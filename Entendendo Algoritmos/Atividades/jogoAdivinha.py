import random

def apresentação ():
    print ("Jogo Do Adivinhe !!!")
    print ("Adivinhe o Número Entre 1 e 100")
    print ("")

def sortearNumero ():
    return random.randint (1, 100)

def definirPersonagemInfo ():
    life = 7
    name = input ("Digite Seu Nome: ")
    print ("")
    return name, life

def mostrarPersonagemInfo (name, life):
    print (f"Nome: {name}")
    print (f"Vidas: {life}")

def selecionarPersonagem (name, life):
    print ("Aperte Enter Para Selecionar O Personagem ...")
    print ("")
    mostrarPersonagemInfo (name, life)
    input ()

def jogarPartida (name, life):
    numero_sorteado = sortearNumero ()
    while life > 0:
        try:
            palpite = int (input("Adivinhe o número (entre 1 e 100): "))
            if palpite < 1 or palpite > 100:
                print ("Por favor, insira um número entre 1 e 100.")
                continue
        except ValueError:
            print ("Por favor, insira um número válido.")
            continue

        if palpite == numero_sorteado:
            print ("Parabéns! Você acertou!")
            print ("")
            break
        elif palpite < numero_sorteado:
            print ("O número é maior.")
            print ("")
        else:
            print ("O número é menor.")
            print ("")
        
        life -= 1
        print (f"Você tem {life} vidas restantes.")

    if life == 0:
        print (f"Você perdeu todas as suas vidas! O número era {numero_sorteado}")

    return input ("Deseja jogar novamente? (s/n): ").lower() == 's'

def jogoAdivinhar ():
    while True:
        apresentação ()
        name, life = definirPersonagemInfo ()
        selecionarPersonagem (name, life)
        if not jogarPartida (name, life):
            print ("Obrigado por jogar! Até a próxima!")
            break

jogoAdivinhar ()
