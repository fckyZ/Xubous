def quickSort ( arr ):
    if len ( arr ) < 2 :
        return arr
    else :
        pivo = arr [0]
        menores = [ i for i in arr [1:] if i <= pivo ]
        maiores = [ i for i in arr [1:] if i > pivo ]

        return quickSort ( menores ) + [ pivo ] + quickSort ( maiores )
    

print ( quickSort ( [ 10, 5, 2, 3 ] ) )
