#include <mudlib.h>
#include <central.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    set("short", "a street punk");
    set("long", @Endtext
He is a street punk who is looking for someone to mug.  He is
wearing a leather vest with tight leather pants.  His hair is up
in spikes, making his head a weapon of some sort.
Endtext
    );
    set("id", ({ "punk", "street punk" }) );
    set_name ("punk");
    set_living_name("punk");
    enable_commands();
    set("gender", "male");
    set("race", "orc");
    set("damage", ({ 2,4 }) );
    set("weapon_name", "fists");
    set("stat/strength", 15);
    set("stat/dexterity", 15);
    set_verbs( ({ "swipe at" , "swing at", "jab at" }) );
    set_verbs2( ({ "swipes at", "swings at", "jabs at" }) );
    set("chat_chance", 10);
    set("att_chat_output", ({
      "Punk exclaims: Gimme your damn money!\n",
      "Punk says: You gonna die.\n",
    }));
    set("wealth", 10+random(20));
    arm(M_WEAP+"blade", "blade");
    set_level(7);
}
