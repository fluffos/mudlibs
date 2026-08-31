#include <std.h>

inherit WEAPON;
string *guilds = ({ "forsaken"});


int special1(object atk);
int special2(object atk);


void create() {
    ::create();
    set_id( ({ "tetsubo", "blunt" }) );
    set_name("tetsubo");
    set_short("%^BOLD%^%^RED%^Te%^CYAN%^ts%^RED%^ub%^CYAN%^o%^RESET%^");
    set_long("%^BOLD%^An Ancient Tetsubo from the Quing Dynasty. It has been modified "
"%^BOLD%^with %^YELLOW%^golden-tipped spikes%^RESET%^%^BOLD%^ on the upper half, with the insignia of %^RED%^Forsaken"
"%^RESET%^%^BOLD%^ burned into the handle.%^RESET%^");
    set_mass(12);
set_curr_value("gold",1000);
    set_type("blunt");
    set_wc(11);
    set_ac(1);
    set_hands(1);
    set("skill level", 150);
    set_wield("%^BOLD%^%^YELLOW%^You're astounded that the Tetsubo weighs so much!%^RESET%^");
    set_unwield("%^BOLD%^%^YELLOW%^You drop the Tetsubo with haste. Your wrists sting.%^RESET%^");
    set_hit((:this_object(),"weapon_hit":));  
}

int weapon_hit() {
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    switch(random(2)) {
    case(0) : return special1(atk);
        break;
    case(1) : return special2(atk);
        break;
    }
    return result;
}

int special1(object atk) {
    int result;
    if(random(100) > 80) {
    write("%^BOLD%^%^YELLOW%^The spikes on the Tetsubo sinks into "+atk->query_cap_name()+"'s back!%^RESET%^");
    say("%^BOLD%^%^YELLOW%^"+(string)this_player()->query_cap_name()+"'s Tetsubo sinks deeply into "+atk->query_cap_name()+" ");

result=(random(110)+((this_player()->query_level())+1));
        result=random(result)+10;
        return result;
    }
}
int special2(object atk) {
    int result;
    if(random(100) > 95) {
    write("%^BOLD%^%^YELLOW%^A horrible Cracking noise is heard!%^RESET%^");
    say("%^BOLD%^%^YELLOW%^"+(string)this_player()->query_cap_name()+" roars as the spikes on "
"his Tetsubo punctures "+atk->query_cap_name()+"'s back down to the spine!%^RESET%^");

result = (random(2) )
;

    atk->set_paralyzed(result, "You can't move your spine has been injured!", "You can move your body again.");
        return result;
    }
}
int query_auto_load() {
if(this_player()->query_level() < 37) return 0;
    if(member_array(this_player()->query_guild(), guilds)==-1) return 0;

    return 1;
}

int slap_on_the_wrist(string str) {
if (!str || present(str, this_player()) != this_object()) return 0;
   if (member_array(this_player()->query_guild(),guilds)!=-1) return 0;
    write("%^BOLD%^%^YELLOW%^You must be of the Forsaken to wield this weapon!%^RESET%^");
    say(this_player()->query_cap_name()+" tries to wield a %^BOLD%^%^YELLOW%^Tetsubo%^RESET%^ but can not because they are to weak!", this_player());
    return 1;
}

void init() {
  ::init();
    add_action("slap_on_the_wrist", "wield");
}



