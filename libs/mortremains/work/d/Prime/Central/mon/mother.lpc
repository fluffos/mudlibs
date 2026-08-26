#include <mudlib.h>
#include <path.h>

inherit MONSTER ;
object ob1, ob2;

void create () {
    ::create();
    seteuid(getuid());
    set("short", "a young woman");
    set("long", @Endtext
She is a young woman who has made a home here in Vieillere for herself
and her daughter.  Her boyfriend deserted her after finding out about
her pregnancy and ever since then, she has been living here and making
the best out of life by working as a teacher.
Endtext
    );
    set("id", ({ "woman", "young woman", "mother" }) );
    set_name ("woman");
    set_living_name("woman");
    enable_commands();
    set("gender", "female");
    set("race", "human");
    set("damage", ({ 1,3 }) );
    set("weapon_name", "fists");
    set("stat/strength", 13);
    set("stat/dexterity", 13);
    set_skill ("attack", 12, "strength");
    set_skill ("defense", 12, "dexterity");
    set_verbs( ({ "swipe at" , "swing at", "jab at" }) );
    set_verbs2( ({ "swipes at", "swings at", "jabs at" }) );
    set("chat_chance", 10);
    set("chat_output", ({
      "Woman says: Please, make yourself at home.\n",
      "Woman says: If you want, you can <taste> my soup.\n"
    }));
    set("att_chat_output", ({
      "Woman screams for help!\n",
      "Woman frantically tries to get away from you.\n",
    }));
    arm(OBJS+"spoon", "spoon");
    wear(OBJS+"dress", "dress");
    set_level(2);
}
