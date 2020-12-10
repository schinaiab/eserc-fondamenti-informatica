# Think of a number

import random
computer_num = random.randint(1, 10)

# Create the function is_same()



# Start the game
print("Ciao .\n Ho pensato un numero da  1 and 10.")

# Collect the user's guess as an integer
guess = int(input("Vuoi indovinarlo ? "))

# Use our function

if computer_num == guess:
    result = "Vinto"
elif computer_num > guess:
    result = "Basso"
else:
    result = "Alto"

# gioca finchè vince

while result != "Vinto":
    if result == "Basso":
        guess = int(input("troppo basso ..prova ancora  "))
    else:
        guess = int(input("troppo alto ..prova ancora  "))

    if computer_num == guess:
        result = "Vinto"
    elif computer_num > guess:
        result = "Basso"
    else:
        result = "Alto"
# quando indent cambia ripete la condizione e il blocco

# End the game
input("Giusto!\nbene \n\n\nPremi INVIO per finire .")
