#include <std.h>

inherit WEAPON;
string *guilds = ({ "forsaken"});

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
    set_wc(1);
    set_ac(1);
    set_hands(1);
    set("skill level", 150);
    set_wield("%^BOLD%^%^YELLOW%^You're astounded that the Tetsubo weighs so much!%^RESET%^");
    set_unwield("%^BOLD%^%^YELLOW%^You drop the Tetsubo with haste. Your wrists sting.%^RESET%^");
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
