#include "reader.h"

std::vector<std::string> Reader::split(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    bool inside_quotes = false;
    std::istringstream tokenStream(s);
    char ch;
    while (tokenStream.get(ch)) {
        if (ch == '"') {
            inside_quotes = !inside_quotes; 
        } else if (ch == delimiter && !inside_quotes) {
            tokens.push_back(token);
            token.clear();
        } else {
            token += ch;
        }
    }
    tokens.push_back(token);

    return tokens;
}

// Função para ler um arquivo CSV e retornar um vetor de vetores de strings
std::vector<std::vector<std::string>> Reader::read_csv(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::vector<std::string>> lines;

    if (!file.is_open()) {
        std::cerr << "Erro ao ler o arquivo " << filename << std::endl;
        return lines; // Retorna um vetor vazio se houver erro ao abrir o arquivo
    }

    std::string line;
    bool inside_quotes = false;
    std::string complete_line;

    std::getline(file, line);

    while (std::getline(file, line)) {
        if (inside_quotes) {
            complete_line += "\n" + line;
            if (line.back() == '"') {
                inside_quotes = false;
                std::vector<std::string> fields = split(complete_line, ',');
                lines.push_back(fields);
            }
        } else {
            if (line.front() == '"' && line.back() != '"') {
                inside_quotes = true;
                complete_line = line;
            } else {
                std::vector<std::string> fields = split(line, ',');
                lines.push_back(fields);
            }
        }
    }

    
    file.close();

    return lines;
}