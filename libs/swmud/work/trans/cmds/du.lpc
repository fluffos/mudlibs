// du - Disk Usage
// shows usage (in K) in all directories below a specified point
// without args, the default is the current dir
// Written by: Gunn @ TMI (01/22/92)
// Rust ported it to lima.  Didn't do too much to it, tho.
#include <mudlib.h>

inherit CMD;

#define MAX_RECURSE 10

int disk_usage(string path, int level);
private void main(string path);

int disk_usage(string path, int level)
{
   int i, total, num;
   string *dir;

   if (level > MAX_RECURSE) { return 0; }

   total = file_size(path);

   if (total == -1)
   {
      out("Cannot access: " + path + "\n");
      return 0;
   }

   if (total == -2)
   {
      total = 0;

      if (path == "/") { path = ""; }

      dir = get_dir(path + "/*") - ({ ".", ".." });

      if (dir)
      {
         num = sizeof(dir);

         for (i = 0; i < num; i++)
         {
            total += disk_usage(path + "/" + dir[i], level + 1);
         }
      }

      outf("%-10d%-s\n", (1 + total / 1024), path);
   }

   return total;
}

private void main(mixed* arg)
{
   if (!wizardp(this_body()))
   {
      out("This command is for wizard use only.\n");
      return;
   }

   if (!arg[0])
   {
      arg[0] = get_user_variable("pwd");
   }

   disk_usage(arg[0], 0);
}