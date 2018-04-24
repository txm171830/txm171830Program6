#Tasnim Mahmud 
#CS 3377.501
#txm171830@utdallas.edu
CXX = g++
CXXFLAGS = -Wall
CPPFLAGS = 

LDFLAGS =

LIBRARIES = -l cdk -lcurses

INCLUDE_PATH = /scratch/perkins/include/

LIBRARY_PATH = /scratch/perkins/lib/

PROJECTNAME = Program6

SRCS = program6.cc 

EXEC = Executable

#
# You normally don't need to change anything below here.
# ======================================================
#
all: $(EXEC)

clean:
	rm -f $(OBJS) *.d *~ \#* $(EXEC)

#  This is a rule to link the files.  Pretty standard
$(EXEC): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(LDFLAGS) $(SRCS) -I $(INCLUDE_PATH) -L $(LIBRARY_PATH) $(LIBRARIES)


# Backup Target
backup:	clean
	@mkdir -p ~/backups; chmod 700 ~/backups
	@$(eval CURDIRNAME := ~/Program5/*)
	@$(eval MKBKUPNAME := ~/backups/$(PROJECTNAME).tar.gz)
	@echo
	@echo Writing Backup file to: $(MKBKUPNAME)
	@echo
	@-tar zcfv $(MKBKUPNAME) $(CURDIRNAME)
	@chmod 600 $(MKBKUPNAME)
	@echo
	@echo Done!
