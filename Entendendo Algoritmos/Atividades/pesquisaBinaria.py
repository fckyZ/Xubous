def pesquisaBinaria (lista, item):
    baixo = 0
    alto = len (lista) - 1
    while baixo <= alto:
        meio = (baixo + alto) // 2
        chute = lista[meio]
        if chute == item:
            return meio
        if chute > item:
            alto = meio - 1
        else:
            baixo = meio + 1
    
    return None

minhaLista = [1, 3, 5, 7, 9]
print (pesquisaBinaria (minhaLista, 3))

# lista com 128 homens, qual seria o numero maximo de etapas para achar o numero
# log 128 base 2 = 7
# log 256 base 2 = 8