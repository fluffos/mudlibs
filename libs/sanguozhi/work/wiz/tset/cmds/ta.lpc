/* Do not remove the headers from this file! see /USAGE for more info. */
// Created by Tset on May 24, 1999

#include <mudlib.h>
inherit CMD;
inherit M_GETOPT;

private string * dirs;
private string fname;
private int curpos;
private void main(string arg)
{
  string file = "";
  int start = 0;
  int length = 8000;
  mixed* args;

  if (!arg) {
    arg = fname;
    start = curpos;
  }
  if (!arg) arg = this_body()->query_shell_ob()->get_variable("cwf");
  if (!arg) arg = file_name(environment(this_body()));
  if (!arg) return;
  args = argument_explode(arg);
  if (sizeof(args) < 1)
  {
    file = this_body()->query_shell_ob()->get_variable("cwf");
    if (!file) return;
  }
  file = args[0][0];
  if (sizeof(args[0]) > 1) start = to_int(args[0][1]);
  if (sizeof(args[0]) > 2) length = to_int(args[0][2]);
  file = evaluate_path(file);
  fname = file;
  curpos = start+length;
  out(read_bytes(file, start, length));
  out("FILE: "+file+" ["+start+"-"+(start+length)+"] ("+length+")\n");
}
