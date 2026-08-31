#include <std.h>
inherit WEAPON;

int weapon_hit();
int can_wield();
int query_auto_load();

void create() {
    ::create();
        set_name("wizards wand");
        set_short("Wizards wand");
        set_long("A short wooden wand.");
        set_weight(5);
        set_id( ({ "wand", "wizards wand" }) );
        set_curr_value("gold", 5 + random(15));
        set_ac(1);
        set_wc(1);
        set_type("blunt");
        set_hands(1);
        set_decay_rate(5000);
        set_wield("The wand tingles.");
        set_hit( (: this_object(), "weapon_hit" :) );
        set("skill level", 10);
        set_wield((:can_wield:));
}

int can_wield()
{
    if (this_player()->query_subclass() != "wizard"  || this_player()->query_skill("wizardry") < 25)
    {
        write("The wand seems to resist you.");
        
    }
    return 1;
}

int weapon_hit() 
{
        int result;
        object atk;
        int num;
        if (this_player()->query_subclass() != "wizard" || this_player()->query_skill("wizardry") < 25)
        {
            write("You fumble the wand and drop it!");
            say((string)this_player()->query_cap_name() + " fumbles their wand and drops it!");
            this_player()->force_me("drop wand");
        }

}       

int query_auto_load()
{
    if (this_player()->query_level() > 10) return 1;
    return 0;
}
