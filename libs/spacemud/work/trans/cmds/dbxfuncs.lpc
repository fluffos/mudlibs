/* Do not remove the headers from this file! see /USAGE for more info. */

//: COMMAND
// USAGE:
//     ``dbxfuncs <ob> <funcs>``
//
// Finds functions in an objects, e.g.:
//
//  |   ``dbxfuncs /secure/simul_efun arr``
//  |   Matches:
//  |   mixed * clean_array(x)        (defined in /secure/simul_efun/misc)
//  |   mixed array_sum(x)            (defined in /secure/simul_efun/misc)
//  |   mixed flatten_array(x)        (defined in /secure/simul_efun/misc)
//
// .. TAGS: RST

#include <driver/type.h>
#include <mudlib.h>

inherit CMD;

private
void main(string str)
{
   string obname, func;
   string *funcs;
   mixed *result;
   string where;
   object ob;
   string line;

   if (!str || sscanf(str, "%s %s", obname, func) != 2)
   {
      write("dbxfuncs <ob> <funcs>\n");
      return;
   }

   obname = evaluate_path(obname);

   if (!(ob = find_object(obname)))
   {
      write("Can't find object " + obname + "\n");
      return;
   }

   funcs = filter(
       functions(ob, 1), function(mixed * result, string func) { return (sizeof(regexp(({result[0]}), func))); }, func);

   if (!sizeof(funcs))
   {
      write("No matches\n");
      return;
   }

   write("Matches:\n");
   foreach (result in funcs)
   {
      line = result[2] + " ";
      line += (result[0] + "(");
      while (result[1]--)
      {
         line += ("x");
         if (result[1])
            line += (", ");
      }
      line += (")");

      if (where = function_exists(result[0], ob))
         outf("%-30s(defined in %s)\n", line, where);
      else
         outf("%s\n", line);
   }
   return;
}
