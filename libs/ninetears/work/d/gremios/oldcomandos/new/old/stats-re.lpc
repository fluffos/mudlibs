/* Hamlet September 1995 
   New "rearrange" code.  Actual useful code is in /obj/misc/roller.
   Since you only do this once in your lifetime, there's no need to keep
   it in the player.c.  So /obj/misc/roller gets cloned when it's actually
   needed and stays away otherwise.
*/
object roller;

int do_rearrange() 
  {
  roller = clone_object("/obj/misc/roller");
  roller->intro();
  this_player()->remove_known_commands("rearrange");

  return 1;
}
