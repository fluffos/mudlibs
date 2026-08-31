#include <std.h>
inherit WEAPON;

int weapon_hit(object atk);
int can_wield();
int query_auto_load();

void create() {
    ::create();
        set_name("sharp axe");
        set_short("Sharp Axe");
        set_long("This axe has a very short handle, the blade of the axe looks razor sharp.");
        set_weight(12);
        set_id( ({ "axe", "sharp axe" }) );
        set_curr_value("gold", 50 + random(15));
        set_wc(8);
        set_type("axe");
        set_hands(1);
        set_decay_rate(5000);
        set_wield("The axe demands blood!");
        set_hit( (: weapon_hit :) );
        set_wield((:can_wield:));
}

int can_wield()
{
    if (this_player()->query_class() != "fighter"  || this_player()->query_skill("axe") < 100)
    {
        write("You barely know which end of the axe to grab.");
        
    }
    return 1;
}

int weapon_hit(object atk) 
{
        int result;
        int num;
        if (this_player()->query_class() != "fighter" || this_player()->query_skill("axe") < 100)
        {
            write("You fumble the axe and drop it!");
            say((string)this_player()->query_cap_name() + " fumbles their axe and drops it!");
            this_player()->force_me("drop axe");
        }
        num = random(100);
        if (num > 96)
        {
                write("Your axe glows a bright red from inside your opponet!");
                say((string)this_player()->query_cap_name()+" buries their axe inside of you!");
                result = 10 +random(30);
                this_player()->add_sp(result);
                return result;
        }
        return 0;   

}       

int query_auto_load()
{
    if (this_player()->query_level() > 18) return 1;
    return 0;
}
