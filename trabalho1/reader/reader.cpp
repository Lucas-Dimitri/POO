#include "reader.h"

std::vector<std::string> Reader::read_line(std::string line, bool& string_aberta){
    std::vector<std::string> incomplete_line;
    std::string pedaco;

    for (char c : line) {
        if (c == '"') {
            string_aberta = !string_aberta;
        } else if (c == ',' && !string_aberta) {
            incomplete_line.push_back(pedaco);
            pedaco.clear();
        } else {
            pedaco += c;
        }
    }

    if (!pedaco.empty() && !string_aberta) {
        incomplete_line.push_back(pedaco);
    }

    return incomplete_line;
}

// Função para ler um arquivo CSV e retornar um vetor de vetores de strings
std::vector<std::string> Reader::read_csv(const std::string& filename) {
    // Criando arquivo
    std::fstream file; 

    // Abrindo arquivo
    file.open(filename, std::ios::in); 

    // Verificando se houve erro na abertura do arquivo
    if (!file.is_open())
        throw std::runtime_error("Arquivo não pôde ser aberto");

    // Declarando variáveis necessárias
    std::vector<std::string> data;
    std::string line; 
    bool string_aberta = false;

    // Pegando cabeçalhos da tabela
    std::getline(file, line);
    std::vector<std::string> cabecalhos = Reader::read_line(line, string_aberta);

    // Pegando células de todas as linhas
    std::vector<std::string> partes;
    while (std::getline(file, line)) {

        // Lendo linha e armazenando em um vetor
        partes = Reader::read_line(line, string_aberta);

        // Inserindo células na lista de dados
        for (std::string parte : partes){
            data.push_back(parte);
        }
    }

    // Fechando arquivo
    file.close();

    return data;
}
