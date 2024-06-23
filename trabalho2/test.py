import re

# Definindo o padrão da regex para validar CPF
pattern = r'^\d{3}\.\d{3}\.\d{3}-\d{2}$|^\d{11}$'
regex = re.compile(pattern)

# Função para validar o CPF e padronizar
def validar_cpf(cpf):
    # Remover todos os caracteres não numéricos
    numeros = re.sub(r'\D', '', cpf)

    # Verificar se a string inteira corresponde ao padrão da regex
    if regex.fullmatch(cpf):
        return True, numeros
    else:
        return False, None
