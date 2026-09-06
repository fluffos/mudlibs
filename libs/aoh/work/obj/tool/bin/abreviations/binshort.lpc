/*
** Shortcuts for the bincommands themselves
** Softbyte 29sep1998
*/

#include "../bincmd.h"
#include <properties.h>
#include <msgclass.h>

inherit BASICCMD;

#define PO previous_object()


string *QueryAbrev() {
return ({"li","pend","inf","inst","upd","uninst"}); }
string *QueryCommands() {
return ({"list","pending","info","install","update","uninstall" }); }

string QueryListHelp()
{return "Subsitute for binpackage list <xxx>\n";}
string QueryPendingHelp()
{return "Substitute for binpending.\n";}
string QueryInfoHelp()
{return "Substitue for binpackage info <xxx>\n";}
string QueryInstallHelp()
{return "Substitute for binpackage install <xxx>\n";}
string QueryUpdateHelp()
{return "Substitute for binpackage update <xxx>\n";}
string QueryUninstallHelp()
{return "Substitute for binpackage uninstall <xxx>\n";}
string QueryHelp()
{
  string s;

  s="This module defines shortcuts for various bincommands:\n"+
  implode(QueryCommands(),", ")+"\n";

  return s;
}


string QueryAuthor() {return "Softbyte, Sep1998";}
string QueryVersion() {return "V1.0";}
string QueryUsage() {return "See Help.\n";}
string QueryShort() {return "Shortcuts for various bincommands.\n";}
string QueryInfo() {return QueryHelp();}

int QueryEUIDRequired() {return 1;}

int cmd_uninstall(string str )
{
  return QueryDispatcher()->cmd_binpackage("remove "+str);
}
int cmd_update(string str )
{
  return QueryDispatcher()->cmd_binpackage("update"+" "+str);
}
int cmd_install(string str )
{
  return QueryDispatcher()->cmd_binpackage("install"+" "+str);
}
int cmd_info(string str )
{
  return QueryDispatcher()->cmd_binpackage("info"+" "+str);
}
int cmd_pending(string str )
{
  return QueryDispatcher()->cmd_binpending(str);
}
int cmd_list(string str )
{
  if (str=="available" || str=="avail" || str=="-a")
    return QueryDispatcher()->cmd_binpackage("la");
  if (str=="installed" || str=="instal" || str=="-i")
    return QueryDispatcher()->cmd_binpackage("li");
  return (int)notify_fail("List what?\n"),0;
}


