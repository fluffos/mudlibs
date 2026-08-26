//:COMMAND
// specification is: spew file str*
// we will recieve: ({ string, ({ args }) })
// This is pretty much something you can do w/ <
// See also: shell
#include <mudlib.h>

inherit CMD;

// Quick hack by Rust 12-12-93
private void main(mixed* arg)
{
   string buf;
   string* lines;
   int loop;
   int i;
   int startln, numlines;
   string pipe;
   string file;
   string rest;

   if (!wizardp(this_body()))
   {
      out("This command is for wizard use only.\n");
      return;
   }

   file = arg[0];
   rest = implode(arg[1]," ");
   sscanf(rest, "%s %d %d", rest, startln, numlines);

   if (!buf = (numlines ? read_file(file, startln, numlines) : read_file(file, startln)))
   {
      write("Couldn't find your file.\n");
      return;
   }

   pipe = "say";
   lines = explode(buf, "\n");
   i = sizeof(lines);

   for(loop = 0; loop < i; loop++)
   {
      this_user()->force_me(pipe+" "+lines[loop]);
   }

   return;
}

int help()
{
   write("Usage: spew <file> [startline] [# lines] [| command]\n"
      "dumps contents of the file to the screen as a say from the user.\n"
      "if pipe is used, dumps to the command specified.  Ie, \n"
      "spew /cmds/xtra/_spew | wiz\n"
      "would send the contents of this file over the wiz line.\n"
      "\n");
}