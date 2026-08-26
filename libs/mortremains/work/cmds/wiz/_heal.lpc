/* By Cyanide for himself.  Real quick.  23 May 97 */

inherit DAEMON;

int cmd_heal(string str) {
  this_player()->set("spell_points", 
    (int)this_player()->query("max_sp") );

  this_player()->set ("hit_points", 
    (int)this_player()->query("max_hp") );

  write("Healed.\n");
  say("There is a bright flash of light, and "+
    this_player()->query("cap_name")+" is whole again.\n");
  
  return 1;
}
