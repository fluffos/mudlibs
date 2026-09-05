inherit "obj/weapon";
#if 0 /* Changed to just use ansi.h - don't use personal ansi files anymore
         -- Rumplemintz
       */
#include "/players/grimm/esc.h";
#include "/players/fred/ansi.h";
#else
#include <ansi.h>
#endif
#define tp this_player()
#define tpn tp->query_name()

int i;
reset(arg) {
   ::reset(arg);
   if(arg) return;
     set_alias("staff");
	  set_name("Death's Scythe");
        set_short(""+BLUE+"Staff"+NORM+" of "+BLINK+RED+"Madness"+OFF+"");
       long_desc =
		" apparently u can read this staff.\n",
        set_params("other|evil",15,0);
		set_type("exotic");
		set_params("other|dark",15,0);
	    set_class(17);
        set_weight(3);
        set_value(7200);

      set_hit_func(this_object());
}
weapon_hit(attacker) {
  i=random(10);
  if (i>5) {

        say(this_player()->query_name()+"'s Staff glows with a "+HIR+"red"+NORM+" fury!\n");
        write("You summon "+HIR+"HELL"+NORM+" upon your FOE!!!.\n");
  return 1;
    }
   return 0;
}
	
init() {
  ::init();
  add_action("emotes","flag");
  add_action("emotes","elem");
  add_action("emotes","shin");
  add_action("emotes","bang");
  add_action("read_staff","read");
  }
  read_staff() {
  write("**********~~~~~~~~~Staff powers~~~~~~~~~~~~~~~**********\n");
  write("EMOTES:\n"+
        "  flag   elem   shin   bang\n");
  write("**********~~~~~~~~~Staff powers~~~~~~~~~~~~~~~~**********\n");
return 1; }

  emotes() {
string msg,msg2;
msg = msg2 = 0;
  if(query_verb() == "elem") { 
    msg = "You bleep obscenities about the elementalists.";
    msg2 = tpn+" goes through the book, screaming obscenities about the elementalists.";
  }
  if(query_verb() == "flag") {
    msg = "You run around the room waving a white flag.";
    msg2 = tpn+" runs around the room waving a huge white flag.";
  }
  if(query_verb() == "shin") {
    msg = "You wonder if shinshi will make a emote from you.";
    msg2 = tpn+" wonders if "+tp->query_possessive()+" emote will be made next, by shinshi.";

  }
  if(query_verb() == "bang") {
    msg = "You scream :BANG BANG! BANG BANG! You run around the room like a nut.";
    msg2 = tpn+" screams: BANG BANG BANG BANG! as "+tp->query_objective()+" runs around the room.";
  }
  write(msg+"\n");
  say(msg2+"\n");
return 1; }
