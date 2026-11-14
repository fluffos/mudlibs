/*
** Push a directory on the stack
** Softbyte 23sep1998
*/

#include "../bincmd.h"
#include <properties.h>
#include <msgclass.h>

inherit BASICCMD;

#define PO previous_object()


string *QueryAbrev() { return ({"pushd"}); }
string *QueryCommands() { return ({"pushd"}); }

string QueryPushdHelp() 
{
  return
  "Usage:    pushd [<directory>]\n"
  "          Pushed a directory on the stack\n"
  "See also: popd\n";
}


string QueryAuthor() {return "Softbyte, Sep1998";}
string QueryVersion() {return "V1.0";}

public int QueryEUIDRequired() {return 1;}

Query( string arg ) { if ( arg == "IsTool" ) return 1; else return 0; }

int cmd_pushd(string str )
{
string *p;
  if (CheckHelp(str)) return 1;


  if (!str) str=this_player()->QueryCurrentDir();
  else str="/secure/master"->make_path_absolute(str);

  p=QueryDispatcher()->QueryPermData("pushd_path")||({});
  p+=({str});
  QueryDispatcher()->SetPermData("pushd_path",p);

  write("Pushed: "+str+"\n");
  
  return 1;
}

