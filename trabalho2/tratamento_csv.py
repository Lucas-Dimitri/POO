def processa_csv(arquivo):
    with open(arquivo, mode='r', newline='', encoding='utf-8') as file_in:
        conteudo = file_in.read()

    conteudo_processado = ""
    dentro_de_aspas = False
    for caractere in conteudo:
        if caractere == '"':
            dentro_de_aspas = not dentro_de_aspas
        if dentro_de_aspas and caractere == '\n':
            conteudo_processado += ' '
        else:
            conteudo_processado += caractere

    with open(arquivo, mode='w', newline='', encoding='utf-8') as file_out:
        file_out.write(conteudo_processado)

# Exemplo de uso
arquivo = r'c:\Users\lucas\OneDrive\Documents\faculdade\terceiro semestre\POO\trabalho2\dados_entregas.csv'
processa_csv(arquivo)
