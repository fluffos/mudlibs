#include <std.h>
inherit WEAPON;

int weapon_hit(object atk);
int can_wield();
int query_auto_load();

void create() {
    ::create();
        set_name("long flail");
        set_short("Long wooden flail");
        set_long("A long wooden flail that seems to have been made by some very sturdy wood.");
        set_weight(12);
        set_id( ({ "flail", "wooden flail", "long flail" }) );
        set_curr_value("gold", 50 + random(15));
        set_wc(8);
        set_type("flail");
        set_hands(1);
        set_decay_rate(5000);
        set_wield("The flail begs to be in battle!");
        set_hit( (: weapon_hit :) );
        set_wield((:can_wield:));
}

int can_wield()
{
    if (this_player()->query_class() != "fighter"  || this_player()->query_skill("flail") < 100)
    {
        write("You barely know how to handle the flail.");
        
    }
    return 1;
}

int weapon_hit(object atk) 
{
        int result;
        int num;
        if (this_player()->query_class() != "fighter" || this_player()->query_skill("flail") < 100)
        {
            write("You fumble the flail and drop it!");
            say((string)this_player()->query_cap_name() + " fumbles their flail and drops it!");
            this_player()->force_me("drop flail");
        }
        num = random(100);
        if(num > 96)
        {
                write("Your flail smacks " + atk->query_cap_name() + " and begins to glow!");
                say((string)this_player()->query_cap_name() + " smacks their flail against " + atk->query_cap_name());
                result = 10 +random(30);
                this_player()->add_sp(result);
                return result;
        }
        return 0;   

}       

int query_auto_load()
{
    if (this_player()->query_level() > 20) return 1;
    return 0;
}
