/*
** Improved cd
** Softbyte 29sep1998
*/

#include "../bincmd.h"
#include <properties.h>
#include <msgclass.h>

inherit BASICCMD;

#define PO previous_object()


string *QueryAbrev() { return ({"cd"}); }
string *QueryCommands() { return ({"cd"}); }

string QueryCdHelp() 
{
  return
  "Usage:    cd [<directory>]\n"
  "          Changes current directory. Accepts abreviations.\n";
}


string QueryAuthor() {return "Softbyte, Sep1998";}
string QueryVersion() {return "V1.0";}

public int QueryEUIDRequired() {return 1;}

int is_dir(string dir,string path)
{
  if (-2==file_size(path+"/"+dir)) return 1;
  return 0;
}

int cmd_cd(string str )
{
string *p;
string s;
int i;
string *dirs;

  if (CheckHelp(str)) return 1;


  if (str)
  {
    str="/secure/master"->make_path_absolute(str);
    if (-2!=file_size(str))
    {
      p=explode(str,"/")||({});
      s="";
      for (i=0;i<sizeof(p)-1;i++)
      {
        if (p[i][<1]=='*')
        {
        dirs=get_dir(s+"/"+p[i])||({});
        dirs=filter(dirs,#'is_dir,s);
        if (dirs && sizeof(dirs)) s+="/"+dirs[0];
        else s+="/"+p[i];
        }
        else s+="/"+p[i];
      if (s && s[0..1]=="//") s=s[1..<1];
      }
      p=get_dir(s+"/"+p[<1]+"*")||({});
      p=filter(p,#'is_dir,s);
      if (p && sizeof(p)>0) str=s+"/"+p[0];
    }
  }
  return this_player()->cd(str);
}

