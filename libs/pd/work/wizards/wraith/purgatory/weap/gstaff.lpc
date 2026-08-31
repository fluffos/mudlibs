inherit "/std/weapon";
#include <purgatory.h>
 
create() {
    ::create();
   set_id( ({"staff"}) );
   set_name("%^ORANGE%^A gnarled old staff%^RESET%^");
   set_short("%^ORANGE%^A gnarled old staff%^RESET%^");
   set_long ("%^ORANGE%^This staff looks like it was cut from a crossgrained tree"
             "%^ORANGE%^ by a blind woodsman who had WAY too much to drink"
             "%^ORANGE%^ in the middle of the night with a dull hunk of iron.");
   set_weight(20);
   set_curr_value("gold", 111);
   set_wc(12);
   set_ac(2);
   set("skill level", 350);
   set_type("blunt");
   set_hit((: this_object(), "weapon_hit" :));

   set_wield("%^ORANGE%^You try to find a spot for your hands to grip.");
   set_unwield("Frustrated, you throw the staff down.");
}
int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 10) {
        write("%^BOLD%^%^RED%^Your hands fumble as you crack "+atk->query_cap_name()+" on the head.");
        say(""+(string)this_player()->query_cap_name()+"'s staff slips and smacks "+atk->query_cap_name()+" upside the head.");
       
result= (random(390)+45);
       if(random(100)> 5) { 
          query_wielded()->query_current_attacker()->set_paralyzed(6);}

    }
}
int query_auto_load() { if (this_player()->query_level() > 60) return 1; }
