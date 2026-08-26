// By Rust
#include <mudlib.h>

inherit CMD;

private void main(mixed *arg, mapping flags, string stdin)
{
   string file;
   int i;
   mixed chunk;

   if (!wizardp(this_body()))
   {
      out("Meow!  This command is for wizard use only.\n");
      return;
   }

   if (arg[0])
   {
      foreach(file in arg[0])
      {
         i = 0;

         if (!is_file(file))
         {
            printf("Warning: cat of %s failed.\n", file);
         }
         else
         {
            int place = 0;

            while(((chunk = read_file(file, place, 100))) != 0 && (chunk != ""))
            {
               place += 101;
               out(chunk);
            }
         }
      }
   }
   else
   {
      out(stdin);
   }
}