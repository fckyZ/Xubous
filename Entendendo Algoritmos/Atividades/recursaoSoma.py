def recursaoSomaArray ( arr ):
    if not arr : 
        return 0
    else :
        return arr [0] + recursaoSomaArray ( arr [ 1: ] );

def resursaoContadorArray ( arr ):
    count = 0
    if not arr:
        return 0
    else :
        return 1 + resursaoContadorArray ( arr [ 1: ] );

def valorMaiorArray ( arr ):
    maior = arr [0];
    if not arr :
        return 0
    else :
        if maior < valorMaiorArray ( arr [ 1: ] ) :
            maior = valorMaiorArray ( arr [ 1: ] )
            return maior

# A Variavel Baixo e Alta

