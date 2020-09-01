###VIDEO EXPLICATIVO: www.youtube.com/watch?v=iliKayKaGtc
################################
###-----------------------------
###Ejemplo: clase con constructor (método __init__) y 2 atributos:
###-----------------------------
class Ejemplo:
    def __init__(self, parámetro1, parámetro2):
        self.atributo1=parámetro1
        self.atributo2=parámetro2

#instanciar un objeto pasando argumentos al constructor
un_ejemplo=Ejemplo("un valor", "otro valor")

#imprimir valor de un atributo
print(un_ejemplo.atributo1)

###-----------------------------
###Ejemplo: implementación de la clase Gato
###-----------------------------

class Gato:

    #atributo de clase
    especie="mamífero"
 
    def __init__(self, nombre, edad):
        self.nombre=nombre
        self.edad=edad
        self.alimentos=[] 
 
    def esAdulto(self):
        if self.edad>1:
            print(self.nombre, "es adulto")
        else:
            print(self.nombre, "es cachorro")

    def esAlimentoFavorito(self,alimento):
        return alimento in self.alimentos

#Instanciar un objeto Gato   
p=Gato("Pelusa",1)

#Imprimir un atributo
print(p.nombre)

#Cambiar un atributo e imprimir
p.nombre="Pelusita"
print(p.nombre)

#Agregar un atributo de forma dinámica e imprimirlo
p.raza="Siamés"
print(p.raza)

#Agregar elementos a una lista que es atributo de un objetoº
p.alimentos.append("pescado")
p.alimentos.append("leche")
print(p.alimentos)

#Modificar la lista que es atributo de un objeto
p.alimentos=["leche", "galletas"]
print(p.alimentos)

#Invocar un método de un objeto
p.verEtapaDeVida()
p.edad=2
p.verEtapaDeVida()

#Instanciar otro objeto de la misma clase
g=Gato("Cleo",3)

#Guardar una lista en un atributo
g.alimentos=["pescado","pan"]

#Invocar al mismo método en distintos objetos
print(p.esAlimentoFavorito("leche"))
print(g.esAlimentoFavorito("leche"))

#Acceder a atributo de clase de un objeto
print(p.especie)

#Acceder a atributo de clase sin instanciar objetos
print(Gato.especie)

###-----------------------------
###Ejemplo: herencia de clases
###-----------------------------

class Empleado:

    def __init__(self, nombre, edad, legajo, sueldo):
        self.nombre=nombre
        self.edad=edad
        self.legajo=legajo
        self.sueldoBase=sueldo
    
    def calcularSueldo(self, descuentos, bonos):
        return self.sueldoBase-descuentos+bonos
    

class AgenteVentas(Empleado):
    #Reimplementación de método __init__ en la subclase
    def __init__(self, mostrador):
        self.numeroMostrador=mostrador

#Instanciar objeto de subclase
pedro=AgenteVentas(4)
print(pedro.numeroMostrador)

#Atributo de superclase no existe
print(pedro.nombre)

#Reimplementación de método __init__ llamando al de la superclase
class AgenteVentas(Empleado):
    def __init__(self, nombre, edad, legajo, sueldo, mostrador):
        self.numeroMostrador=mostrador
        super().__init__(nombre, edad, legajo, sueldo)

#Instanciar objeto de subclase
pedro=AgenteVentas("Pedro Martinez", 32, "A120", 55000, 4)

#Atributo heredado de la superclase
print(pedro.nombre)

#Método heredado de la superclase
print(pedro.calcularSueldo(100, 3000))

#Subclase con método propio
class Tripulante(Empleado):        
    def mostrarRenovacionLicencia():
        if self.edad<50:
            print("Renueva su licencia cada 1 año")
        else:
            print("Renueva su licencia cada 6 meses")

lucas=Tripulante("Lucas Gutierrez", "H618", 60000, 40)
print(lucas.mostrarRenovacionLicencia())

###-----------------------------
###Ejemplo: ocultamiento de la implementación
###-----------------------------

class Carrera:
    def __init__(self, nombre):
        self.nombre=nombre
        self.materias={}
     
    #Ocultar la implementación de una colección implementando un método propio para agregar elementos
    def agregarMateria(self, materia, codigo):
        self.materias[codigo]=materia

class Materia:
    def __init__(self, nombre, profesor):
        self.nombre=nombre
        self.profesor=profesor
    

algebra=Materia("Álgebra", "Ricardo Quinteros")
fisica=Materia("Física", "Margarita Gomez")
quimica=Materia("Química", "Lorena Ríos")
ing=Carrera("Ingeniería")

#Ejemplo donde agregar elemento implica conocer la implementación de la colección
ing.materias[134]=algebra
ing.materias[412]=fisica

#Ejemplo donde se oculta la implementación de la colección
ing.agregarMateria(algebra, 134)
ing.agregarMateria(fisica, 412)

###-----------------------------
###Ejemplo: property y setter para atributos privados
###-----------------------------

class Materia:
    def __init__(self, nombre, profesor, fecha):
        self.nombre=nombre
        self.profesor=profesor
 self.fechaInicioDictado=fecha  #no puede ser anterior a 2006
    
    @property
    def fechaInicioDictado(self):
        print("Se está accediendo mediante property")
        return self._fechaInicioDictado

    @fechaInicioDictado.setter
    def fechaInicioDictado(self, fecha):
        if fecha<2006:
            self._fechaInicioDictado=2006
        else:
            self._fechaInicioDictado=fecha

#Instanciar objetos asignando valores al atributo mediante su setter
algebra=Materia("Álgebra", "Ricardo Quinteros", 2010)
fisica=Materia("Física", "Margarita Gomez", 2015)
quimica=Materia("Química", "Lorena Ríos", 2005)

#Acceder a atributos mediante property
print(algebra.fechaInicioDictado)
print(fisica.fechaInicioDictado)
print(quimica.fechaInicioDictado)

###-----------------------------
###Ejemplo: ocultamiento de atributos
###-----------------------------

#Ejemplo en que se accede a un atributo público y se crea una nueva referencia a él
copia=ing.materias
print(len(ing.materias)

#Mediante la nueva referencia, se modifica la colección contenida en el objeto
copia[999]=quimica
print(len(ing.materias))

class Carrera:
    def __init__(self, nombre):
        self.nombre=nombre
 #Atributo oculto
     self.__materias={}
     
 def agregarMateria(self, materia, codigo):
        self.__materias[codigo]=materia
 
#El atributo es inaccesible mediante su nombre 
copia=ing.__materias

###-----------------------------
###Ejemplos: polimorfismo
###-----------------------------

#Strings, listas y otros contenedores implementan el "iterator protocol"
for elemento in "hola":
    print(elemento)

for elemento in [1,2,3,4]:
    print(elemento)

#El método len es polimórfico porque se aplica a distintos tipos de objetos 
len("hola")
len([1,2,3,4])

#Sobrecarga de operadores
"Hola"+" y adios"
1+2

#Sobrecarga de método con valor por defecto
class Empleado:
    def __init__(self, nombre, legajo, sueldo):
        self.nombre=nombre
        self.legajo=legajo
        self.sueldoBruto=sueldo

    def calcularSueldo(self, descuentos):
        return self.sueldoBruto-descuentos

class Gerente(Empleado):
    def calcularSueldo(self, descuentos, bonificaciones=0):
        return self.sueldoBruto-descuentos+bonificaciones

marcos=Empleado("Marcos Ríos", 221, 30000)
julia=Gerente("Julia Campos", 109, 60000)

print(marcos.calcularSueldo(3000))
print(julia.calcularSueldo(10000, 2000))
