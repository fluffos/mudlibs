/* Do not remove the headers from this file! see /USAGE for more info. */

//: COMMAND
// USAGE:  ``mkdir <directory>``
//
// This command will create directories.
//
// ``mkdir /wiz/zifnab/obj``
//
// will create a directory named obj in */wiz/zifnab*
//
// ``mkdir obj npc``
//
// will try to create a directory named *obj* and one called *npc* in my current directory.
//
// .. TAGS: RST

inherit CMD;

private
void main(string *arg)
{
   foreach (string d in arg[0])
   {
      if (mkdir(d))
         outf("Ok.\n");
      else
         outf("Failed to make directory: %s\n", d);
   }
}
