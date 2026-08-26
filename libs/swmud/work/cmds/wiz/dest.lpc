/* Do not remove the headers from this file! see /USAGE for more info. */

// Davmar/Nevyn

//: COMMAND
//$$ see: clone, clean, scan
// USAGE:  dest <object>
//
// This command destroys an object in your inventory or in your environment.

inherit CMD;

private
void main(mixed *arg)
{
   object ob;

   ob = arg[0];

   //Give objects a chance before dested.
   ob->do_remove();

   //Message about the dest.
   if (ob->short())
   {
      this_body()->do_player_message("destruct", ob);
   }
   else
   {
      write("Destructing: " + file_name(ob) + "\n");
   }
   if (member_array(ob, bodies()) != -1)
      ob = ob->query_link();
   destruct(ob);
   return;
}
