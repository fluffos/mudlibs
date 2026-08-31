/* Do not remove the headers from this file! see /USAGE for more info. */

//: COMMAND
// USAGE:
//     ``dbxvars <ob> <var>``
//
// Finds functions in an objects, e.g.:
//
//  |   ``dbxvars /std/body name``
//  |   Matches:
//  |   proper_name         : 0
//  |   old_fnames          : ({ /* sizeof() == 2 */
//  |   "/obj/shells/wish",
//  |   "/obj/pshell"
//  |   })
//  |   name                : 0
//  |   corpse_filename     : "/std/corpse"
//  |   invis_name          : 0
//  |   nickname            : 0
//
// .. TAGS: RST

#include <mudlib.h>
inherit CMD;

private
void main(string str)
{
   string obname;
   string var;
   string *vars;
   object ob;
   function f;

   if (!str || sscanf(str, "%s %s", obname, var) != 2)
   {
      out("dbxvars <ob> <var>\n");
      return;
   }

   obname = evaluate_path(obname);

   if (!(ob = find_object(obname)))
   {
      out("Can't find object " + obname + "\n");
      return;
   }

   vars = regexp(variables(ob), var);

   if (!sizeof(vars))
   {
      out("No matches\n");
      return;
   }

   /*
   ** NOTE: this may fail if the command user does not have enuf privs
   */
   f = bind(( : fetch_variable:), ob);

   out("Matches:\n");
   foreach (var in vars)
   {
      outf("%-20s: %O\n", var, evaluate(f, var));
   }
   return;
}
