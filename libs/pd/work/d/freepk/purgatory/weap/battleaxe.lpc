#include <std.h>
#include <purgatory.h>
inherit WEAPON;

int weapon_hit(object atk);

create() {
    ::create();
   set_short("Battle Axe");
   set_name("Battle Axe");
   set_id( ({"axe"}) );
   set_long ("This is a large, double-bladed axe, used in one hand. Handed out to the lowest ranking barbarians, it is not so massive as to be unwieldly. ");
   set_weight(15);
   set_curr_value("gold", 190);
   set_wc(9);
   set_ac(1);
   set("skill level", 75);
   set_type("axe");
   set_hit((: weapon_hit :));
   set_decay_rate(1000);
}
int weapon_hit(object atk)
{
    int result;
    if(random(100) < 10) {
        write("You slam your axe into "+atk->query_cap_name()+" causing blood to fly.");
        say(""+(string)this_player()->query_cap_name()+" slams their axe into "+atk->query_cap_name()+" splattering the room in blood.");
       
result=(random(60))+((this_player()->query_level()));

    }
}
int query_auto_load() { if (this_player()->query_level() > 35) return 1; }

