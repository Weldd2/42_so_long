# Nom de l'exécutable final
NAME = so_long

# Compilateur
CC = cc

# Répertoires
SRCDIR = src
INCDIR = include
OBJDIR = obj
LIB_DIR = lib

# Options de compilation
CFLAGS = -Wall -Wextra -Werror
# CFLAGS = 

# Détection automatique des répertoires d'inclusion
# Inclut le répertoire principal 'include' et tous les 'lib/*/include'
INCLUDE_DIRS = $(INCDIR) $(wildcard $(LIB_DIR)/*/include)
OSI_INCLUDE_FLAGS = $(addprefix -I, $(INCLUDE_DIRS))

# Détection récursive des fichiers sources du projet principal
SRCS = $(shell find $(SRCDIR) -type f -name '*.c')
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

LIBS = MLX42/build/libmlx42.a -lglfw -lm -ldl -lpthread
# LIBS = MLX42/build/libmlx42.a -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw

# Détection automatique des fichiers sources des modules, y compris les sous-dossiers
OSI_MODULE_SRCS = $(shell find $(LIB_DIR)/*/src -type f -name '*.c')

# Transformation des fichiers sources des modules en fichiers objets avec structure
MOD_OBJS = $(patsubst $(LIB_DIR)/%/src/%.c,$(OBJDIR)/modules/%/%.o,$(OSI_MODULE_SRCS))

# Variables pour Valgrind
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --suppressions=valgrind_files/so_long.supp --suppressions=valgrind_files/mlx42.supp
TEST_ARGUMENTS = "map.ber"

# Règle par défaut
all: $(NAME)

install: install_deps mlx_install

# Règle de liaison pour créer l'exécutable
$(NAME): $(OBJS) $(MOD_OBJS)
	$(CC) $(CFLAGS) $(OSI_INCLUDE_FLAGS) $(OBJS) $(MOD_OBJS) $(LIBS) -o $(NAME)

# Règle générique pour compiler les sources du projet principal de manière récursive
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(OSI_INCLUDE_FLAGS) -c $< -o $@

# Règle pour compiler les sources des modules, y compris les sous-dossiers
$(OBJDIR)/modules/%/%.o: $(LIB_DIR)/%/src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(OSI_INCLUDE_FLAGS) -c $< -o $@

# Règle pour installer les dépendances
install_deps:
	@echo "Installation des dépendances..."
	@./.install.osi.sh
	@echo "Dépendances installées."

mlx_install:
	git clone https://github.com/codam-coding-college/MLX42.git
	make mlx_build

mlx_build:
	cd MLX42 && \
	rm -rf build && \
	cmake -B build -DGLFW_DIR=/opt/homebrew/lib/cmake/glfw3 && \
	cmake --build build -j4

# Règle Valgrind
valgrind: CFLAGS += -g
valgrind:
	valgrind $(VALGRIND_FLAGS) ./$(NAME) $(TEST_ARGUMENTS)

gdb: CFLAGS += -g
gdb:
	gdb --args ./$(NAME) $(TEST_ARGUMENTS)

debug: CFLAGS += -g
debug: re

# Règles de nettoyage
clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Déclaration des cibles phony
.PHONY: all clean fclean re install_deps valgrind
