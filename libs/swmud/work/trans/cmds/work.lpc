/* Do not remove the headers from this file! see /USAGE for more info. */

// gesslar@thresholdrpg.com
// 2022-10-26

//: COMMAND
//$$ see: cd
// USAGE: work  or  work <obj>
//
// This command will change your pwd to the directory of your environment if
// no arguments are supplied or the directory of the object if one is specified.

inherit CMD;

private
void main(string arg)
{
   object caller = this_body();
   object target;
   string file, path;

   if (!arg)
   {
      target = environment(caller);
   }
   else
   {
      if (!(target = get_object(arg)))
      {
         outf("No such target: %s\n", arg);
         return;
      }
   }

   file = file_name(target);
   path = base_path(file);

   if (!is_directory(path))
   {
      outf("No such path: %s\n", path);
      return;
   }

   this_user()->query_shell_ob()->set_pwd(path);
   outf("new cwd: %s\n", path);
}
