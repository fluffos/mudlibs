/*
** Testtool
** Softbyte 21sep1998
*/

#include "bincmd.h"
#include <properties.h>
#include <msgclass.h>

inherit BASICXCMD;

#define PO previous_object()


string *QueryAbrev() { return ({"bt1","bt2","xwh"}); }
string *QueryCommands() { return ({"bt111","bt2","xwher"}); }

string QueryBt111Help() {return "Bt1 help\n";}
string QueryBt2Help() {return "Bt2 help\n";}
string QueryXwherHelp() {return "Xwher help\n";}
string QueryTestHelp() {return "btest help\n";}
string QueryHelp() {return "help\n";}


string QueryAuthor() {return "Softbyte, Sep1998";}
string QueryVersion() {return "V1.0";}

Query( string arg ) { if ( arg == "IsTool" ) return 1; else return 0; }

int main(string str )
{
  write("main\n");
  return 1;
}
int cmd_bt111(string str )
{
  write("bt111\n");
  return 1;
}
int cmd_bt2(string str )
{
  write("bt2\n");
  QueryDispatcher()->cmd_binpackage("info"+" "+str);
  return 1;
}
int cmd_xwher(string str )
{
  write("xwher\n");
  return 0;
}





