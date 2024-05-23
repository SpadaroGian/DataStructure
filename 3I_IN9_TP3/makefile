# Compilateur à utiliser
CC=gcc

# Options de compilation
CFLAGS=-Wall -Wextra -I./headers

# Bibliothèques à inclure
LIBS=-lm 

# Liste des fichiers source à ignorer
IGNORE_FILES = test_unit bench_vector conditional_compilation_demo

# Liste des fichiers source à compiler
SRCS = $(filter-out $(IGNORE_FILES:%=./src/%.c), $(wildcard ./src/*.c))

# Si l'option COVERAGE est définie, ajoute l'option de couverture de code et
# définit les cibles à générer
ifeq ($(COVERAGE), 1)
    CFLAGS += -g --coverage
    TARGETS = test_unit
    SUFFIX = _cov
# Sinon, si l'option DEBUG est définie, ajoute l'option de débogage et
# définit les cibles à générer
else
    TARGETS = test_unit bench_vector conditional_compilation_demo
    ifeq ($(DEBUG), 1)
        CFLAGS += -g
        SUFFIX = _debug
    else
    	CFLAGS += -O2
    endif
endif

# Si l'option VERSION est définie, ajoute l'option de version et modifie
# le suffixe des fichiers objet et exécutables
ifeq ($(VERSION), 2)
    CFLAGS += -DVERSION=2
    SUFFIX := _v2$(SUFFIX)
endif
ifeq ($(VERSION), 3)
    CFLAGS += -DVERSION=3
    SUFFIX := _v3$(SUFFIX)
endif

# Liste des fichiers objet à générer
OBJS = $(SRCS:./src/%.c=./objs/%$(SUFFIX).o)

# Liste des exécutables à générer
TARGETS_BIN = $(TARGETS:%=./bin/%$(SUFFIX))

# Cible par défaut : génère tous les exécutables
all: $(TARGETS_BIN)

# Si l'option COVERAGE est définie, génère la couverture de code après
# avoir exécuté les cibles
ifeq ($(COVERAGE), 1)
	$(TARGETS_BIN)
	lcov -c -d ./objs/ -o ./coverage/index$(SUFFIX).info
	genhtml ./coverage/index$(SUFFIX).info -o ./coverage/html$(SUFFIX) --ignore-errors source
	rm -f ./objs/*.gcda
endif

# Cible pour générer un exécutable : dépend de tous les fichiers objet
$(TARGETS_BIN):./bin/% : ./objs/%.o $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Cible pour compiler un fichier source en fichier objet
./objs/%$(SUFFIX).o: ./src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cible pour nettoyer le projet (supprime les fichiers objet et exécutables)
clean:
	rm -f ./objs/* ./src/~ ./headers/~ ./bin/*
	rm -rf ./coverage/*

# Cible pour afficher la valeur de certaines variables
info:
	@echo "SRCS = $(SRCS)"
	@echo "OBJS = $(OBJS)"
	@echo "TARGETS_BIN = $(TARGETS_BIN)"

