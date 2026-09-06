/*
** Imports the Xtool aliases
** Softbyte 30sep1998
*/

#include "../bincmd.h"
#include <properties.h>
#include <msgclass.h>
#include <string.h>
#include <config.h>

inherit BASICCMD;

#define PO previous_object()


string *QueryAbrev() { return ({"ximp"}); }
string *QueryCommands() { return ({"ximport"}); }

string QueryXimportHelp() 
{
  return
  "Usage:    ximport [<filename>]\n"
  "          Imports your xaliases into the bintool or the aliase from\n"
  "          the given file.\n";
}

mixed *aliases;

string QueryAuthor() {return "Softbyte, Sep1998";}
string QueryVersion() {return "V1.0";}

public int QueryEUIDRequired() {return 1;}

int cmd_ximport(string arg )
{
string *a1,*a2;
int i;
string s;

  if (CheckHelp(arg)) return 1;
  if (!arg) arg= WPATH+getuid(QueryCloner())+"/.xtoolrc";
  arg = "/secure/master"->make_path_absolute( arg );
  if ( file_size( arg+".o" ) > 0 )
  {
    restore_object( arg );
    if (!aliases)
    {
      write("No aliases found in that file.\n");
    }
    else if (2!=sizeof(aliases))
    {
      write("Unknown file format for alias import.\n");
    }
    else
    {
      a1=aliases[0];
      a2=aliases[1];
      write("Importing aliases...\n");
      for (i=0;i<sizeof(a1);i++)
      {
        QueryDispatcher()->cmd_alias(a1[i]+" "+a2[i]);
      }
      write("Done...\n");

    }
  }
  else
  {
     write("The file '"+arg+"' can't be read.\n");
  }
  return 1;
}

