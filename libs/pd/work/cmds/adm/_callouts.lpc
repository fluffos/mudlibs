//    /bin/adm/_callouts.c
//    From the Nightmare mudlib
//    Coded by Valodin on Feb 4, 1993

#include <str_fmt.h>
#include <std.h>
inherit DAEMON;

int cmd_callouts(string str)
{
  mixed *crap;
  mixed *element;
  object ob;
  string func, filename, trash, spaces;
  int i, j, delay;
  mixed args;
  string printing_crap;

  crap = call_out_info();

  if(!sizeof(crap))
  {
    write("There are no call_outs right now.\n");
    return 1;
  }

  write("Object                               Function  Delay\n" +
        "------                               --------  -----");

  for(i = 0; i < sizeof(crap); i++)
  {
    element = crap[i];
    if(sizeof(element) != 3)
    {

/*      write("Size problem " + sizeof(element) + " " + (string)element + "\n");
*/
    write("Size problem " + sizeof(element) + "\n");
      continue;
    }
/*
 * 0:   The object.
 * 1:   The function (string).
 * 2:   The delay.
*/
    ob = (object)element[0];
    func = (string)element[1];
    delay = (int)element[2];
 //   args  = element[3];
    filename = file_name(ob);
    if(strlen(filename) > 35)
    {
      while(strlen(filename) > 34)
        sscanf(filename, "%s/%s", trash, filename);
      filename = "~" + filename;
    }
    spaces = "  ";
    for(j = strlen(filename); j < 35; j++)
      spaces += " ";
    printing_crap = filename + spaces + func + "  "  + delay;
    write(printing_crap);
  }
  return 1;
}

int help()
{
  write("Command: callouts\n\n" +
        "This command lists all the call_outs on the mud.\n" +
        "See man: call_out_info\n"+
        "See also: cache, mstatus, netstat, fdinfo, opcprof, dumpallobj\n"+
        "" );
  return 1;
}
