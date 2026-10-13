#include <ansi.h>

#define OBJDIR "/d/obj/books-nonskill/"

#undef BOOK   // globals.h names the generic book; these read the base in this directory
#define BOOK OBJDIR+"book"
