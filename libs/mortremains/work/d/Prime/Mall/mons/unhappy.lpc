
// A generic monster.
// Ilz coded 28 Jan 98

#include <mudlib.h>
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("prevent_summon", 1);
    set("author" , "herself");
    set("short" , "an unhappy customer");
    set("long", "This customer is unhappy with her purchase. \n"+
      "She is trying to get a refund, but is having a hard\n"+
      "time. \n");
    set("id" , ({"customer" , "unhappy" , "unhappy customer" }) );
    set_size(8);
    set_name ("unhappy customer");
    set ("gender", "female") ;
    set("race", "human");
    set_align("le");
    enable_commands() ;
    set("speed" , 5);
    set("wealth" , 520);
    set ("base_ac", 2);
    set ("armor_class", 2);
    set("chat_chance", 10);
    set("chat_output", ({
      "customer says: Hey I just want my money back!\n",
      "Customer asks: Isn't the customer always right? \n",
    }) );
    set("att_chat_output", ({
    }) );
    set("damage" , ({2,4}) );
    set("weapon_name" , "clothes hanger");
    set_verbs( ({"swing at" , "strike" , "slash at" }) );
    set_verbs2( ({"swings at" , "strikes" , "slashes at" }) );
    set_level(8);
}

