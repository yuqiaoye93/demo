TARGET = $(notdir $(PWD))
CC = g++
LD = -lpthread 
CFLAGS = -g -std=c++17
HD =
OBJECT_DIR = object
BIN_DIR = bin
DIRS := $(shell find $(SOURCE_DIR) $(PROJECT_DIR) -maxdepth 3 -type d)

SOURCES = $(foreach dir,$(DIRS),$(wildcard $(dir)/*.cpp))
OBJ_FILES = $(notdir $(patsubst %.cpp, %.o, $(SOURCES)))
DEP_FILES_ND = $(patsubst %.o, %.d, $(OBJ_FILES))
DEP_FILES = $(addprefix object/,$(DEP_FILES_ND)) 

CSOURCES = $(foreach dir,$(DIRS),$(wildcard $(dir)/*.c))
COBJ_FILES = $(notdir $(patsubst %.c, %.o, $(CSOURCES)))
CDEP_FILES_ND = $(patsubst %.o, %.d, $(COBJ_FILES))
CDEP_FILES = $(addprefix object/,$(CDEP_FILES_ND)) 
HD += $(addprefix -I,$(DIRS)) 
VPATH += $(DIRS)

ALL:TARGET

TARGET:PRE COMPILE $(TARGET) 
	
COMPILE:$(OBJ_FILES) $(COBJ_FILES)
$(OBJ_FILES):%.o:%.cpp %.d
	@echo compiling  $(<F)...
	@$(CC) -c $< -o $(OBJECT_DIR)/$@ $(HD) $(CFLAGS)
$(COBJ_FILES):%.o:%.c %.d
	@echo compiling  $(<F)...
	@$(CC) -c $< -o $(OBJECT_DIR)/$@ $(HD) $(CFLAGS)
$(TARGET):$(OBJ_FILES) $(COBJ_FILES)
	@$(CC)  -o $(TARGET) $(addprefix $(OBJECT_DIR)/,$(OBJ_FILES)) $(addprefix $(OBJECT_DIR)/,$(COBJ_FILES)) $(LD) 
	@echo build successfully TARGET = $(TARGET)!

-include $(DEP_FILES)
-include $(CDEP_FILES)
.PHONY:clean
clean:
	rm -f $(OBJECT_DIR)/*.o
	rm -f $(OBJECT_DIR)/*.d
	rm -f $(TARGET)
	rm -f $(BIN_DIR)/*
%.d:%.cpp
	@set -e; rm -f $@; $(CC) $(CFLAGS)  $(HD) -MM $< $(INCLUDEFLAGS) > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > object/$@; \
	rm -f $@.$$$$

%.d:%.c
	@set -e; rm -f $@; $(CC) $(CFLAGS)  $(HD) -MM $< $(INCLUDEFLAGS) > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > object/$@; \
	rm -f $@.$$$$

.PHONY:PRE
PRE:
ifneq  ($(OBJECT_DIR), $(wildcard $(OBJECT_DIR)))
	@mkdir -p $(OBJECT_DIR)
endif
ifneq  ($(BIN_DIR), $(wildcard $(BIN_DIR)))
	@mkdir -p $(BIN_DIR)
endif
.PHONY:build
build:TARGET

