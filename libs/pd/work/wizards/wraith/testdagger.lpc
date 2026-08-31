inherit "/std/weapon";
 
create() {
    ::create();
   set_id( ({ "dagger", "a dagger", "a dagger of the Forsaken",
              "dagger of the Forsaken"}) );
   set_name("fkndagger");
   set_short("a Forsaken Dagger");
   set("long", "The dagger is 9 inches long, with Blue "
       "Flame spiraling around the blade.  It fits perfectly "
       "into your hand.\nThere is a small inscription upon the hilt.\n ");
   set_weight(10);
   set_curr_value("gold", 85);
   set_wc(10);
   set_type("knife");
     set_hit((: this_object(), "weapon_hit" :));
   set_wield("You survey the room and think, I see dead people.\n");
   set_unwield("A sense of extreme satisfaction overwhelms you as the Forsaken
Dagger slips into its' sheath.");
}
int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 10) {
        write("Your staff crackles with energy as it drains the life-force of
your opponents soul into
your body, adding to your own.");
        say(""+(string)this_player()->query_cap_name()+"'s staff draws some
life out of "+atk->query_cap_name()+".");
       
result= (random(90)+10);
this_player()->add_hp(result);
;
        return result/2;
    }
}
int query_auto_load() { if (this_player()->query_level() > 35) return 1; }
