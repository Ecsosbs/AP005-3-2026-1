while true:
a= input("porfavor ingrese un valor: ")
print(a)

mod= int(a)%2
print(mod)
if (mod==0):
    print("Par")
else:
    print("Impar")

b=input("ingrese 1 para continuar, 0 para finalizar")
print(b)
    if(b==0):
    break: