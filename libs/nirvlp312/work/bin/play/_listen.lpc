inherit "/obj/user/sensory";

int cmd_listen(string str)
{
 if(!this_player()->query_invis())
  say((string)this_player()->query_name()+" perks up "+
   possessive(this_player())+" ears.\n");

 return do_sense(str, "sound", "hear");
}
