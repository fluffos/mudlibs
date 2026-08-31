//      based on stealth.c
//      a dungeonware.net collaboration, stormbringer and asmodeus -00.09.21-
//      from the Carnage/Nightmare mudlib
//      kataan ability
//      Altered by Daboura 12/11/2005

#include <std.h>
int abil();
inherit DAEMON;

string type() { return "deception"; }

int cmd_darkshift(string str) {
    object ob;    
    int stealth, faith, intelligence, dex, stlth;

   if (!abil()) {
      notify_fail("What?\n");
      return 0;
   }
   if(this_player()->query_ghost()) return 0;
   if(this_player()->query_invis()) 
   { 
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
   if((int)this_player()->query_mp() < 75) {
      notify_fail("You lack the magical energy needed.\n");
      return 0;
    }

    this_player()->set_invis();
    call_out("take_off", ((stlth/2)+dex+random(faith/2)), this_player());

    this_player()->add_mp(-((faith/3)+random(faith/3)));

    write("%^BLUE%^You shift into %^BOLD%^%^BLACK%^darkness%^RESET%^%^BLUE%^ and become completely undetectable!%^RESET%^\n");
    return 1;


}

void take_off(object ob)
{
 if (ob && ob->query_invis()) ob->set_invis();
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
   if (o && o->query_subclass() == "kataan" &&
       o->query_skill("stealth") >= 30*3 &&
       o->query_skill("faith") >= 30*5)
         return 1;
    return 0;
}
