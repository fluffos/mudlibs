// Kyra - LoKi - 2021


#include <std.h>
#include <daemons.h>
#include "../serakii.h"
inherit NPC;


void create(){
   object ob;
   ::create();
   set_name("Kyra Rall");
   set_id(({ "Kyra","kyra","rall",
   "kyra rall","oracle"}));
   set_short("%^C062%^Kyra Rall, "+
   "%^C043%^Serith's %^C110%^oracle%^CRST%^");
set_long("%^CRST%^Dressed in a "+
"%^C015%^simple white dress%^CRST%^ "+
"and %^C143%^plain shoes%^CRST%^ you "+
"would be forgiven in thinking this "+
"young girl was nothing more than "+
"that. However as you look at her "+
"closer you realize her skin is "+
"almost too perfect, her %^C110%^blue "+
"eyes%^CRST%^ %^C231%^shine %^CRST%^with "+
"a little too much %^C228%^light %^CRST%^"+
"and as she moves the whole church seems "+
"to %^C248%^hush %^CRST%^around her.\n");
   set_race("human");
   set_stats("intelligence",20);
   set_stats("wisdom",18);
   set_stats("strength",16);
   set_stats("charisma",16);
   set_stats("dexterity",12);
   set_stats("constitution",14);
   set_class("oracle");
   set_mlevel("oracle",30);
   set_guild_level("oracle",30);
   set_alignment(5);
   set_gender("female");
   set_size(2);
   set_exp(0);
   set_overall_ac(-10);
   set_hd(35,15);
   set_max_hp(400);
   set_hp(query_max_hp());
   set("aggressive",0);
   set_emotes(3, ({
"%^C246%^You swear you just saw a %^C231%^small white rabbit%^C246%^ peer out from behind the %^C241%^altar.%^CRST%^\n",
"%^C061%^Out of the corner of your eyes, the %^C056%^runes %^C061%^on the altar reform and you can %^C110%^understand them%^C061%^! But when you look again they are obscure again.%^CRST%^\n",
"%^C208%^You see a flash of %^C226%^golden wings%^C208%^ through the temple windows.. Or no.. that's not possible.. %^CRST%^\n",
"%^C088%^The temple is awash suddenly in the rich %^C196%^scent of roses%^C088%^, but as you turn, it's gone...%^CRST%^\n",
"%^C247%^The %^C241%^shadows %^C247%^seem to grow, encroaching on everything in the room, but when they get close to the young girl they %^C059%^recoil %^C247%^and return to normal.%^CRST%^\n",
}), 0);
   set_property("no bows",1);
   set_spoken("wizish");
   command("speech %^C060%^speak in a %^C044%^soft %^C060%^voice%^CRST%^");
   
   command ("pose %^C044%^standing near the altar%^CRST%^");
}

