import string
import random
import os 

# Esta es la representación de estas secuencias de caracteres.
numbers=string.digits #'123456789'
characters=string.ascii_lowercase # 'ABCDEFGHIJKLMNÑOPQRSTUVWXYZ'
mayusculas=string.ascii_uppercase # 'ABCDEFGHIJKLMNÑOPQRSTUVWXYZ'
caracteresEspeciales=string.punctuation

#De esta manera podemos obtenes una contraseña que es producto de concatenar distintas secuencias
# de caracteres.
newpassword=random.choices(numbers+characters+caracteresEspeciales+mayusculas,k=20)

array=[1,2,3,4,5,6]




# Hacemos que la contraseña generada tenga buen formato
print(f"Este es el número aleatorio : {"".join(newpassword)}")