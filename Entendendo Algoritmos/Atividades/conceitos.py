# DEFINIÇÃO DE VARIÁVEIS
a = 10                     # Inteiro
b = 10.00                  # Float
c = "Hello World"          # String
d = 'a'                    # String de um único caractere
e = True                   # Booleano
e2 = False                 # Booleano

# VARIÁVEIS COMPOSTAS
listaInteiro = [1, 2, 3, 4, 5]        # Lista de inteiros
listaFloat = [1.1, 2.2, 3.3, 4.4, 5.5]  # Lista de floats
listaComposta = ["gabriel", "joao", 1, 2, 3, 'a', 'b', 12.12, 10.10]  # Lista mista
matriz = [                        
    [1, 2, 3],
    [4, 5, 6],              # Matriz 3x3
    [7, 8, 9]
]

# ESTRUTURAS DE REPETIÇÃO
# Estrutura de Repetição: For
print ("Usando o loop for:")
for i in range (5):          # Loop de 0 a 4
    print (i)

# Estrutura de Repetição: While
print ("Usando o loop while:")
i = 0                        # Inicializando a variável
while i < 5:                # Loop enquanto i for menor que 5
    print (i)
    i += 1                  # Incrementando i

# ESTRUTURAS CONDICIONAIS
print ("Estruturas condicionais:")
x = 10
if x > 0:
    print ("x é positivo")
elif x < 0:
    print ("x é negativo")
else:
    print ("x é zero")

# FUNÇÕES
def saudacao(nome):
    return f"Olá, {nome}!"

# Chamando a função
print (saudacao("Gabriel"))

# DICIONÁRIOS
print ("Exemplo de dicionário:")
dicionario = {
    "nome": "Gabriel",
    "idade": 30,
    "cidade": "São Paulo"
}
print (dicionario["nome"])  # Acessando um valor pelo nome da chave

# CONJUNTOS
print ("Exemplo de conjunto:")
conjunto = {1, 2, 3, 4, 5}
conjunto.add(6)            # Adicionando um elemento
print (conjunto)

# TUPLAS
print ("Exemplo de tupla:")
tupla = (1, 2, 3)
print (tupla[0])            # Acessando um elemento da tupla

# TRATAMENTO DE EXCEÇÕES
print ("Tratamento de exceções:")
try:
    resultado = 10 / 0  # Isso gerará um erro
except ZeroDivisionError:
    print ("Erro: Divisão por zero!")
finally:
    print ("Executando bloco finally.")

# LIST COMPREHENSIONS
print ("Usando list comprehension:")
quadrados = [x**2 for x in range (10)]  # Criando uma lista de quadrados
print (quadrados)
