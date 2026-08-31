/* Do not remove the headers from this file! see /USAGE for more info. */

// Davmar/Nevyn

//: COMMAND
// USAGE:  ``quiet <object>``
//
// This command silences an NPC in the room you are in if they use M_ACTIONS for
// all their chatter.
//
// .. TAGS: RST

inherit CMD;

private
void main(mixed *arg)
{
   object ob;

   ob = arg[0];
   
   //Doesn't work on people
   if (ob->is_body())
   {
      outf("Making %s quiet is beyond your powers.", ob->short());
      return;
   }

   //May not have actions.
   if (!arrayp(ob->query_actions()))
   {
      outf("%s is already quiet.", ob->short());
      return;

   }
   ob->stop_actions();
   ob->set_actions(100, 0);
   outf("%s has been quieted.", ob->short());

   return;
}
