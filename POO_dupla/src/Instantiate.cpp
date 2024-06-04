#include "../include/Instantiate.hpp"
#include "../include/Order.hpp"
#include "../include/Client.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>

struct Coordenadas
{
    double latitude;
    double longitude;
};

Coordenadas *get_lat_lon(std::string endereco)
{
    Coordenadas *coords = new Coordenadas();
    std::string endereco = endereco; // Endereço de exemplo
    std::string url = "https://nominatim.openstreetmap.org/search?q=" + endereco + "&format=jsonlea";

    CURL *curl;
    CURLcode res;
    std::string buffer;

    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,
                         [](void *ptr, size_t size, size_t nmemb, std::string *data)
                         {
                             data->append((char *)ptr, size * nmemb);
                             return size * nmemb;
                         });
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res == CURLE_OK)
        {
            Json::Value root;
            Json::Reader reader;
            if (reader.parse(buffer, root))
            {
                if (!root.empty())
                {
                    coords->latitude= root[0]["lat"].asDouble();
                    coords->longitude = root[0]["lon"].asDouble();
                }
                else
                    std::cerr << "Endereço não encontrado." << std::endl;
            }
            else
                std::cerr << "Erro ao analisar JSON." << std::endl;
        }
        else
            std::cerr << "Erro na requisição: " << curl_easy_strerror(res) << std::endl;
    }
    return coords;
}

void clean_csv(std::string csvFile, std::string newCSVFile)
{
    std::ifstream arquivo(csvFile);
    std::ofstream novoArquivo(newCSVFile);

    if (!arquivo.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo de leitura!" << std::endl;
        return;
    }

    if (!novoArquivo.is_open())
    {
        std::cerr << "Erro ao criar o arquivo de escrita!" << std::endl;
        return;
    }

    int countBreak = 6;

    char caractere;
    while (arquivo.get(caractere))
    {

        if (caractere == '\n')
        {
            countBreak++;
            if (countBreak % 7 == 0)
                novoArquivo.put('\n');
        }
        else
            novoArquivo.put(caractere);
    }
    arquivo.close();

}

void create_order(std::string csv)
{
    std::ifstream file(csv);
    std::string line;
    std::vector<std::string> row;
    std::string currentItem;

    while (std::getline(file, line))
    {
        row.clear();
        currentItem.clear();
        int enable = 0;

        for (char c : line)
        {
            if (c == '"')
            {
                if (enable == 1) enable = 0;
                else enable = 1;
            }

            if (c == ',' && enable == 0)
            {
                row.push_back(currentItem);
                currentItem.clear();
            }
            else currentItem += c;
        }

        std::list<Client*>& allClients = Client::get_instances();
        for (Client* client : allClients)
        {
            Coordenadas *coords1 = get_lat_lon(row[5]);
            Coordenadas *coords2 = get_lat_lon(row[6]);

            if (row[1] == client->get_cpf())
            {
                Order *newObject = new Order(client->get_id(), Coordinates(coords1->latitude, coords1->longitude), Coordinates(coords2->latitude, coords2->longitude), std::stof(row[7]), std::stof(row[8]), row[9]);
            }
        }
    }
}

void registerFile(std::string csvFile, std::string newCSVFile)
{
    clean_csv(csvFile, newCSVFile);
    create_order(newCSVFile);
}