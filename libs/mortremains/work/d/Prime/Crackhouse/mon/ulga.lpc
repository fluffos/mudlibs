// QC Passed - Cyanide

#include <mudlib.h>
#include "where.h"

inherit MONSTER ;
object nails, dress;

void create () {
    ::create();
    seteuid(getuid());
    set("author","cattt");
    set("short", "Ulga, resident prostitute");
    set("long", @Endtext
She is wearing the ugliest red dress and so much makeup you wonder
what would make anyone want her services.  She is kinda frumpy and
undernourished. She is offering herself in exchange for credits or
some crack. 
Endtext
    );
    set("id", ({ "orc", "prostitute", "ulga" , "Ulga" }) );
    set_name ("Ulga");
    enable_commands();
    set("gender", "female");
    set("race", "orc");
    set("damage", ({ 1,3 }) );
    set("weapon_name", "fists");
    set("stat/strength", 12);
    set("stat/dexterity", 12);
    set_verbs( ({ "scratch at" , "claw at", "flail at" }) );
    set_verbs2( ({ "scratches at", "claws at", "flails at" }) );
    set("chat_chance", 10);
    set("chat_output", ({
      "Ulga asks: Got any crack man? \n",
      "The prostitute rubs her breast while motioning to you.\n",
      iwrap("Ulga stumbles up to you and says: I can make "+
	"you feel -real- good for a few credits."),
    }));
    set("att_chat_output", ({
      "The prostitute begs for you to leave her alone.\n",
      "Ulga tries to steal your wallet while you swing at her.\n",
    }));

    arm(M_WEAP+"nails","nails");
    wear(M_ARM+"dress","dress");

    set("prevent_summon", 1);
    set_size(6);
    set_level(7);
}
