#################LISTAS####################
###########################################
personajes_op = ['Luffy', 'Zoro','Namy','Ussop','Sanji','Chopper']  #nombre de personajes
#input()
print(personajes_op)        #imprime lista
print(type(personajes_op))  #imprime tipo de lista
print(personajes_op[2])     #imprime el numero 2 en la lista

print("personajes_op size: ", len(personajes_op))  #imprime cuntos el numero de objetos en la lista
print(personajes_op[0:2])
print(personajes_op[:2])

personajes_op.append('Robin')  #añade al final de la lista
print(personajes_op) 
      
personajes_op.insert(3,'Franky')  #añade en la posicion 3
print(personajes_op)

personajes_op.extend(['Brook','Jimbei']) #agrega varios elementos
print(personajes_op)

print(personajes_op.index('Zoro')) #busca la posicion

personajes_op.remove('Brook')  #elimina ese elemento
print(personajes_op)

personajes_op.insert(8,'Brook') #añade en posicion 8
print(personajes_op)

print(personajes_op.pop()) #elimina el ultimo elemento
size = len(personajes_op)
print("size = ", size)

personajes_op_3 = personajes_op*3 #multiplica la lista por 3
print("personajes_op_3: ",personajes_op_3)

print("sort: ")
print()
personajes_opSort = personajes_op.sort() #ordena la lista original
print(personajes_opSort)

Numpersonajes_op =[10,9,8,7,6,5,4,3,2,1] #lista numerica
print("Ordering my_NumList: ")
Numpersonajes_op.sort() #se ordena la lista
print(Numpersonajes_op)

Numpersonajes_op.sort(reverse = True)    #ordena la lista de mayor a menor
print("de menor a mayor: ",Numpersonajes_op)

#################TUPLAS####################
###########################################

print("###########################")
print("###########################")
print("###########################")
print("############TUPLAS#########")  #solo texto

tupla_personajes_op = tuple(personajes_op)  #convierte en tupla una lista
print() #linea vacia
print()
print("tupla_personajes_op: ",tupla_personajes_op)

print(tupla_personajes_op[0]) #acceso igual que las listas
print(tupla_personajes_op[2])

print('Luffy' in tupla_personajes_op) #verifica si existe
print(tupla_personajes_op.count('Luffy'))  #cuantas veces aparece

tupla_personajes_op_unitaria = ('Robin')
print(tupla_personajes_op_unitaria)

tupla_personajes_op = 'Marlon', 26, 4, 1999 #tupla sin parentesis
print(tupla_personajes_op)

nombre,dia,mes,año = tupla_personajes_op
print(nombre)
print(dia)
print(mes)
print(año)

print("Nombre: ", nombre, "- Dia:",dia," - Mes: ",mes," - Año : ",año)

personajes_op2 = list(tupla_personajes_op)
print(personajes_op2)
