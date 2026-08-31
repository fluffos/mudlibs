//      based on stealth.c
//      a dungeonware.net collaboration, stormbringer and asmodeus -00.09.21-
//      from the Carnage/Nightmare mudlib
//      kataan ability


#include <std.h>
int abil();
inherit DAEMON;

int cmd_darkshift(string str) {
    object ob;    
    int stealth, faith, intelligence, dex, stlth;

   if (!abil()) {
      notify_fail("What?\n");
      return 0;
   }
   if(this_player()->query_ghost()) return 0;
   if(this_player()->query_invis()) { 
       notify_fail("You are already walking in darkness.\n");
       return 0;
   }
    stlth = (int)this_player()->query_skill("stealth");
    dex = (int)this_player()->query_stats("dexterity");
    faith = (int)this_player()->query_skill("faith");
    intelligence = (int)this_player()->query_stats("intelligence");
    stealth = ((stlth/3)+(dex)+(intelligence)+(faith/3));

    if(stealth < 15) {
        notify_fail("The demons laugh at you.\n");
        return 0;
    }
   if((int)this_player()->query_sp() < 50) {
        notify_fail("You are too tired.\n");
        return 0;
    }
   if((int)this_player()->query_sp() < 75) {
      notify_fail("You lack the magical energy needed.\n");
      return 0;
    }
   if (!wizardp(this_player())) {
    this_player()->set_invis();
    call_out("take_off", stealth/2+random(this_player()->query_level()), ob);
   } else 
     {
      this_player()->set_invis();
      call_out("take_off", 50, ob);
     }
    this_player()->add_mp(-(random(stealth)+random(this_player()->query_level())));
    this_player()->add_sp(-(random(stealth)));
    write("%^BOLD%^WHITE%^You shift into %^BLACK%^darkness%^WHITE%^ and become completely undetectable!%^RESET%^\n");
    return 1;


}

void take_off(object ob)
{
 if (this_player()->query_invis()) this_player()->set_invis();
}

void help() {
    write("Syntax: <darkshift>\n\n"
      "The caster uses demonic energy to shift into darkness "
      "thereby masking his or her presence. The effects of a "
      "shift are for short amounts of time. Decloak will bring "
      "the shift to an abrupt end.\n"
    );
}

int abil() {
   object o;
   o = this_player();
   if (!o) return 0;
   if (o && o->query_subclass() == "kataan" && o->query_level() >= 20)
   return 1;
}

