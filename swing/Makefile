# Makefile para compilar y ejecutar el programa Java

# Nombre del programa
PROG = ClientWindow

# Fuentes
SOURCES = $(PROG).java

# Objetos
OBJ = $(SOURCES:.java=.class)

# Comandos
JAVAC = javac
JAVA = java

# Opciones de compilación
JAVACFLAGS = -g

# Reglas
all: $(PROG)

$(PROG): $(OBJ)
	$(JAVA) $(PROG)

run: $(PROG)
	$(JAVA) $(PROG)

clean:
	rm -f $(OBJ)

.SUFFIXES: .java .class

.java.class:
	$(JAVAC) $(JAVACFLAGS) $<
