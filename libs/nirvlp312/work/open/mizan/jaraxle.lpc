

/* I took this from Verte - */

/* I added a duration for the armor,
   it will wear out after 131313 hits
   on the call out at a 50% avg for a
   point against that number every 5+R2
   seconds.  This number may change */


#include "/players/vertebraker/define.h"
inherit ARMOUR;

/* mizan change */
#define LIMIT 130000


int countdown;
reset(arg) {
   if(arg) return;
   ::reset();
   set_id("charm");
   set_short(HIR+"Phoenix Charm"+NORM);
   set_alias("phoenix charm");
   set_weight(1);
   set_ac(0);
   set_type("amulet");
   set_value(3000+random(10000)); 
}

wear(string str) {
   while(remove_call_out("regen_sp") != -1);
   if(!id(str) || environment() != this_player() || worn) return 0;
   ::wear(str);
   if(worn) call_out("regen_sp", 5 + random(2));
   return 1; }

remove(string str) {
   if(!id(str) || environment() != this_player() || !worn) return 0;
   ::remove(str);
   while(remove_call_out("regen_sp") != -1);
   return 1; }

long() {
   write("The "+HIR+"Phoenix Charm"+NORM+" is made of short-braided hemp rope.\n"+
      "On the end of the rope is a crystallized "+RED+"Phoenix Tear"+NORM+".\n"+
      "It is said the wearer of this charm is granted powers\n"+
      "of the "+RED+"Phoenix"+NORM+".\n");
   
   /* mizan change */
   write(display_countdown()"\n");
   
}

/* start mizan changes */

add_countdown(arg)
{
    /* for debugging */
    countdown += arg;
}

display_countdown()
{
    if(countdown < 5)
        write("BRAND SPANKING NEW BABY message.");
    else if(countdown < (LIMIT / 10))
        write("1/10 used message.");
    else if(countdown < ((LIMIT / 10) * 2))
        write("2/10 used message.");
    else if(countdown < ((LIMIT / 10) * 3))
        write("3/10 used message.");
    else if(countdown < ((LIMIT / 10) * 4))
        write("4/10 used message.");
    else if(countdown < ((LIMIT / 10) * 5))
        write("5/10 used message.");
    else if(countdown < ((LIMIT / 10) * 6))
        write("6/10 used message.");
    else if(countdown < ((LIMIT / 10) * 7))
        write("7/10 used message.");
    else if(countdown < ((LIMIT / 10) * 8))
        write("8/10 used message.");
    else if(countdown < ((LIMIT / 10) * 9))
        write("9/10 used message.");
    else
        write("Used like Bangkok whore message.");

    return 1;
}
/* end mizan changes */

regen_sp() {
   string msg;
   if(!worn_by) return 0; /* if nobody wearing it, kill call-out*/
                          /*Make sure they need healing -Bp*/
   if(USER && USER->is_player() && worn_by->query_hurt())
      {
      switch(random(3)) {
         case 0: msg = "The tear glows softly.\nYour mental powers seem to recover...\n";
         break;
         case 1: msg = "The tear gives off a faint glow...\n";
         break;
         case 2: msg = "You see an image of a flaming bird appear in your mind.\n";
         break; }
      if(!random(20)) tell_object(USER,msg);
      if(!random(100000)) {
         tell_object(USER,"Suddenly, your chest burns red hot!\n");
         tell_object(USER,RED+"Your flesh is scorched!\n"+NORM);
         USER->hit_player(50 + random(50), "other|fire");
         while(remove_call_out("regen_sp") != -1);
         call_out("regen_sp", 5 + random(2));
         return 1; }
      USER->add_spell_point(2+random(2));
      countdown+=random(2);
      if(countdown > LIMIT){ tell_object(USER,HIR+"The charm has been depleted and turns to ashes.\n"+NORM); 
      command("remove charm", USER);
      destruct(this_object());
         return 1; }
   }
   while(remove_call_out("regen_sp") != -1);
   call_out("regen_sp",5+random(2));
}

query_save_flag() { return 0; }

drop()
{
   while(remove_call_out("regen_sp") != -1);
   ::drop();
}

generic_object() { return 1; } 

restore_thing(str) {
   restore_object(str);
   return 1;
}

save_thing(str) {
   save_object(str);
   return 1;
}

locker_arg() {
   return ""+countdown;
}

locker_init(str) {
   sscanf(str,"%d",countdown);
}
