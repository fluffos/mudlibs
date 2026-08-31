inherit "/std/weapon";
#include <purgatory.h>
 
create() {
    ::create();
   set_short("Battle Axe");
   set_name("Battle Axe");
   set_id( ({"axe"}) );
   set_long ("This is a large, double-bladed axe, used in one hand. Handed out to the lowest ranking barbarians, it is not so massive as to be unwieldly. ");
   set_weight(45);
   set_curr_value("gold", 200);
   set_wc(6);
   set_ac(1);
   set("skill level", 75);
   set_type("axe");
   set_hit((: this_object(), "weapon_hit" :));

}
int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 10) {
        write("You slam your axe into "+atk->query_cap_name()+" causing blood to fly.");
        say(""+(string)this_player()->query_cap_name()+" slams their axe into "+atk->query_cap_name()+" splattering the room in blood.");
       
result=(random(60)+40)+((this_player()->query_level()));

    }
}
int query_auto_load() { if (this_player()->query_level() > 35) return 1; }

