/*
** pops a directory from the stack
** Softbyte 23sep1998
*/

#include "../bincmd.h"
#include <properties.h>
#include <msgclass.h>
#include <string.h>

inherit BASICCMD;

#define PO previous_object()


string *QueryAbrev() { return ({"popd"}); }
string *QueryCommands() { return ({"popd"}); }

string QueryPopdHelp() 
{
  return
  "Usage:    popd [show|clear|<level>]\n"
  "          Pops a directory from the stack. Or loads it from level.\n"
  "See also: pushd\n";
}


string QueryAuthor() {return "Softbyte, Sep1998";}
string QueryVersion() {return "V1.0";}

public int QueryEUIDRequired() {return 1;}

//Query( string arg ) { if ( arg == "IsTool" ) return 1; else return 0; }

int cmd_popd(string str )
{
string *p;
int i;
string s;

  if (CheckHelp(str)) return 1;

  p=QueryDispatcher()->QueryPermData("pushd_path")||({});
  if (str=="show")
  {
    s="Directory stack:\n";
    for (i=sizeof(p)-1;i>=0;i--)
    {
      s+=sprintf("%2d: %s\n",i+1,p[i]);
    }
    L_STR->SMore(s);
  }
  else if (str=="clear")
  {
    p=({});
    QueryDispatcher()->SetPermData("pushd_path",p);
    write("Directory stack cleared.\n");
  }
  else if (str && to_int(str)>0)
  {
    i=to_int(str)-1;
    if (i<0 || i>=sizeof(p))
      write("Not that many directories on the stack.\n");
    else
    {
      s=p[i];
      if (s) this_player()->cd(s);
    }

  }
  else if (!str)
  {
    if (!sizeof(p))
      write("No directories on the stack.\n");
    else
    {
      s=p[sizeof(p)-1];
      if (s) this_player()->cd(s);
      p=p[0..<2];
      QueryDispatcher()->SetPermData("pushd_path",p);
    }
  } 
  else
  {
    write(QueryPopdHelp());
  }
  return 1;
}

