caderno = dict ()
caderno [ "maçã" ] = 0.68
caderno [ "leite" ] = 1.58
caderno [ "abacate" ] = 2.45

print ( caderno [ "abacate" ] )


listaTelefonica = dict ()
listaTelefonica [ "jenny" ] = 8675309
listaTelefonica [ "emergency" ] = 911


voted = {}

def verificarEleitor ( nome ) :
    if voted.get ( nome ) :
        print ( "Mande Embora!" )
    else :
        voted [ nome ] = True
        print ( "Deixe Votar" )

verificarEleitor ( "tom" )
verificarEleitor ( "gabriel" )
verificarEleitor ( "gabriel" )


cache = {}

def pegaDados ( url ) :
    return f"Dados da URL {url}"

def caching ( url ) :
    if cache.get ( url ) :
        return cache [ url ]
    else :
        dados = pegaDados ( url)
        cache [ url ] = dados
        return dados