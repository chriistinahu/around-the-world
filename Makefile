EXE = main
TEST = test 

EXE_OBJ = main.o 
OBJS = main.o loader.o airport.o route.o graph.o bfs.o dijkstra.o landmark.o

OBJS_DIR = .objs 

# specific traversal executables
EXE_BFS = run_bfs
OBJS_BFS = $(OBJS_DIR)/run_bfs.o $(OBJS_DIR)/bfs.o $(OBJS_DIR)/graph.o $(OBJS_DIR)/loader.o $(OBJS_DIR)/route.o $(OBJS_DIR)/airport.o


EXE_DIJ = run_dijkstra
OBJS_DIJ = $(OBJS_DIR)/run_dijkstra.o $(OBJS_DIR)/dijkstra.o $(OBJS_DIR)/graph.o $(OBJS_DIR)/loader.o $(OBJS_DIR)/route.o $(OBJS_DIR)/airport.o

EXE_LANDMARK = run_landmark
OBJS_LANDMARK = $(OBJS_DIR)/run_landmark.o $(OBJS_DIR)/landmark.o $(OBJS_DIR)/graph.o $(OBJS_DIR)/loader.o $(OBJS_DIR)/route.o $(OBJS_DIR)/airport.o

CLEAN_RM = $(EXE_BFS) $(EXE_DIJ) $(EXE_LANDMARK)

include cs225/make/cs225.mk 

$(EXE_BFS): $(OBJS_BFS)
	$(LD) $^ $(LDFLAGS) -o $@

$(EXE_DIJ): $(OBJS_DIJ)
	$(LD) $^ $(LDFLAGS) -o $@

$(EXE_LANDMARK): $(OBJS_LANDMARK)
	$(LD) $^ $(LDFLAGS) -o $@