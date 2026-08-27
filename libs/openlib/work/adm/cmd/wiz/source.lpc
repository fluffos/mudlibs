/*  -*- LPC -*-  */
// source.c:  command for reading command scripts
//
// Created 9 Sept 1996 by Tim@Dysfunctional Mud
//
#include <command.h>

#define BRANCH_NONE 0
#define BRANCH_IF   1
#define BRANCH_ELSE 2

int
main(string arg)
{
  string* cmds;
  int branch, cond;

  if( !arg )
    return notify_fail("usage: source <script file>\n");

  arg = RESOLVE_PATH(arg);
  
  if( file_size(arg) < 0 )
  {
    if( query_notify_fail() )
      return 0;
    else
      return notify_fail("No such file.\n");
  }

  // Parse script file
  arg = replace_string(replace_string(read_file(arg), "\n", ";"), "#", ";#");
  cmds = explode(arg, ";");
  cmds = filter(cmds, (: $1[0] != '#' :));
  
  for(int i = 0; i < sizeof(cmds); i++)
  {
    string cmd;
    
    // strip leading spaces
    while(cmds[i][0] == ' ')
      cmds[i] = cmds[i][1..];

    // strip trailing spaces
    while(sizeof(cmds[i]) && cmds[i][<1] == ' ')
      cmds[i] = cmds[i][0..<2];

    // skip null commands
    if( !sizeof(cmds[i]) )
      continue;

    switch( cmds[i] )
    {
    case "fi":
      branch = BRANCH_NONE;
      continue;
    case "else":
      branch = BRANCH_ELSE;
      continue;
    }
    
    if( sscanf(cmds[i], "if %s", cmd) == 1 )
    {
      branch = BRANCH_IF;
      cond = this_player()->force_me(cmd);
      continue;
    }

    if( branch == BRANCH_NONE ||
        branch == BRANCH_IF && cond || branch == BRANCH_ELSE && !cond )
      this_player()->force_me(cmds[i]);
  }
  
  
  return 1;
}

string
help_desc()
{
  return "read and execute command script files";
}

string
help()
{
  return @ENDHELP
  A script file contains several commands separated by newlines or semicolons,
which are treated just like a newline.  Blank lines are ignored; everything
following a # until the next newline or semicolon is considered a comment.

Source will interpret conditional statements in the form of:
if <command>
  cmdX
  ...
  cmdN
[else
  cmdY
  ...
  cmdM]
fi
(Brackets not included - text in square brackets is optional)
The first block is evaluated if the command succeeds, the second if it fails.
Conditional statements may _not_ be nested.
ENDHELP;
}
