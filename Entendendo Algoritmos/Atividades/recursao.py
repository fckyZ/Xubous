def regressiva (i):
    print (i)
    if i <= 0 :  # Caso - Base
        return
    else :
        regressiva (i - 1)  # Caso Recursivo

regressiva (10)