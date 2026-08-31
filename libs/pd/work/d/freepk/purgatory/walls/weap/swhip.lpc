inherit "/std/weapon";
#include <castlewall.h>
int weapon_hit(object atk);
 
create() {
    ::create();
   set_name("Spiked Leather Whip");
   set_short("%^BOLD%^%^WHITE%^Sp%^BLACK%^ik%^WHITE%^ed %^RESET%^%^RED%^Le%^ORANGE%^ath%^RED%^er%^RESET%^ Whip");
   set_id( ({"whip", "leather whip", "spiked leather whip"}) );
   set_long ("This whip has sharp metal spikes interwoven into the leather. It looks like it could tear anything apart if used properly.");
   set_weight(28);
   set_curr_value("gold", 50+random(50));
   set_wc(8);
   set_ac(2);
   set("skill level", 200);
   set_type("flail");
   set_hit((: weapon_hit :));

   set_wield("%^BOLD%^%^BLACK%^A sadistic grin crosses your face as you wield the whip.");
   set_unwield("%^BOLD%^%^WHITE%^A sense of loss is felt as the whip leaves your palm.");
}
int weapon_hit(object atk)
{
    int result;
    if(random(100) > 90) {
       write("%^BOLD%^%^WHITE%^The spikes on your whip rend the flesh of "+atk->query_cap_name()+".%^RESET%^");
        say("%^BOLD%^%^WHITE%^"+(string)this_player()->query_cap_name()+" rips strips of flesh from "+atk->query_cap_name()+"'s body with their whip.");
result=(random(20))+((this_player()->query_level()/2));

    }
}
int query_auto_load() { if (this_player()->query_level() > 83) return 1; }

int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_level() > 83) return 0;
   write("You cut yourself, you are too inexperienced to play with this.");
   say(this_player()->query_cap_name()+" gibbers like an idiot.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wield");
}
