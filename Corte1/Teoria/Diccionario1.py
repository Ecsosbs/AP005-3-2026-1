# tripulacion =  {"Sunny": 21, "Going Merry": 23, "Thousand Sunny": 20, "Baratie": 22}
# marines = {"Marineford": 6,  "Enies Lobby": 2, "Impel Down": 1}

# print(tripulacion)
# print(marines)

# frutas_del_diablo = {"Gomu Gomu": "Luffy", "Mera Mera": "Ace", "Ope Ope": "Law", "Hito Hito": "Chopper" }
# print(frutas_del_diablo)

## Verifying an error:
#  ERROR ORIGINAL: listas como claves
# poderes = {[1, 2, 4, 8, 16]: "Luffy", [1, 3, 9, 27, 81]: "Zoro"}

# CORREGIDO: usar tuplas
# poderes = {(1, 2, 4, 8, 16): "Luffy", (1, 3, 9, 27, 81): "Zoro"}
# print(poderes)

# tripulaciones = {"Sombrero de Paja": ["Luffy", "Zoro", "Nami"], "Barbanegra": ["Teach", "Shiryu", "Burgess"]}
# print(tripulaciones)

# diccionario_vacio = {}
# print(diccionario_vacio)

# menu_barco = {"carne": 3, "sake": 6, "jugo": 5, "pan": 2}
# print("Before: ", menu_barco)
# menu_barco["pastel"] = 8
# print("After", menu_barco)

# animales_isla = {"dinosaurios": 0}
# animales_isla = {"dinosaurios": 0}
# animales_isla = {"caballos": 2}
# print(animales_isla)


## Add multiple keys
# sensores_barco = {"cubierta": 21, "cocina": 23, "habitacion": 20}
# print("Before", sensores_barco)

# sensores_barco.update({"almacen": 22, "cuarto invitados": 25, "patio": 34})
# print("After", sensores_barco)

###
# recompensas = {"Luffy": 3000000000, "Zoro": 1110000000}
# print(recompensas)
# recompensas.update({"Sanji": 1032000000, "Nami": 366000000})
# print(recompensas)

## Overwrite Values ##
# menu_barco["banana"] = 3

# menu_barco = {"carne": 3, "sake": 6, "jugo": 5, "pan": 2}
# print("Before: ", menu_barco)
# menu_barco["carne"] = 5
# print("After", menu_barco)

# premios = {"Mejor Pirata": "Luffy", "Mejor Espadachin": "Zoro", "Mejor Navegante": "Nami", "Mejor Doctor": "Chopper"}
# print("Before", premios)
# print()
# premios.update({"Mejor Cocinero": "Sanji"})
# print("After1", premios)
# print()
# premios["Mejor Pirata"] = "Shanks"
# print("After2", premios)


### Dict Comprehensions

nombres = ['Luffy', 'Zoro', 'Sanji', 'Nami']
recompensas_lista = [3000, 1110, 1032, 366]

# zipPiratas = zip(nombres, recompensas_lista)
# print("zipPiratas: ", zipPiratas)

# piratas = {key:value for key, value in zip(nombres, recompensas_lista)}
# print(piratas)

# bebidas = ["sake", "te", "agua", "ron"]
# energia = [64, 40, 0, 120]

# bebidas_energia = zip(bebidas, energia)
# print(bebidas_energia)

# mapa_bebidas = {key:value for key, value in bebidas_energia}
# print(mapa_bebidas)

canciones = ["Binks no Sake", "We Are", "Over the Top", "Hope", "Share the World", "Bon Voyage"]
reproducciones = [78, 29, 44, 21, 89, 5]

plays = {key:value for key, value in zip(canciones, reproducciones)}
print(plays)

plays.update({"New World": 1})
plays.update({"Hope": 94})

print("After: ", plays)

biblioteca = {"Mejores Canciones": plays, "Canciones Tristes": {}}
print(biblioteca)
