#include <std.h>
#include <marsh.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("cloak");
    set_id( ({ "black cloak", "cloak"}) );
    set_short( "a cloak" );
    set_long( "A common black cloak." );
    set_mass(1);
    set_value(0);
    set_type("cloak");
        set_limbs(({"torso" , "right arm", "left arm"}));
    set_ac(1);
    set_wear("The tattered shirt reaks from an ogre!\n");
    set_remove("You are happy about the smell being gone!\n");
}


void init()
{
 ::init();
 add_action("func_get", "get");
}

int func_get(string str)
{
 object ob;

 if (!str || str == "") return 0;
 if (present(str, environment(this_player()))!=this_object()) return 0;
 write("You attempt to pick up the cloak but it picks itself up.");
 message("info", this_player()->query_cap_name()+" attempts to pick up the"+
                 "cloak but it picks itself up!", environment(this_player()), 
                 ({ this_player() }));
 ob = new(MOB"fcloaker");
 ob->move(environment(this_player()));
 ob->force_me("kill "+this_player()->query_cap_name());
 this_object()->remove();
 return 1;
}
