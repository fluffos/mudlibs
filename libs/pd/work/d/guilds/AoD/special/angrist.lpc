inherit "/std/weapon";
string *guilds = ({ "AoD", "darksoul" });
//Created by a nutcase
create() {
    ::create();
    set_id( ({ "sai" }) );
    set_name("sai");
    set_short("%^BLACK%^%^BOLD%^S%^WHITE%^ilver %^BLACK%^S%^WHITE%^ai%^RESET%^");
    set("long", "%^BOLD%^%^BLACK%^The cold steel appears to have never let blood, it's surface gleams. You see "
      "%^BOLD%^%^BLACK%^your eyes reflected in the blade but something doesn't seem right. Your eyes "
      "%^BOLD%^%^BLACK%^look foreign...evil even. You begin to have sinister thoughts and a shiver "
      "%^BOLD%^%^BLACK%^runs down your spine.");
    set_weight(15);
    set_curr_value("gold", 100+random(35));
    set_wc(8);
    set_ac(1);
    set_type("knife");
    set_hit((: this_object(), "weapon_hit" :));
    set_wield("%^BOLD%^%^BLACK%^You cry out in %^RED%^R%^BLACK%^A%^RED%^G%^BLACK%^E as %^RESET%^%^RED%^bl%^BOLD%^%^RED%^oo%^RESET%^%^RED%^d%^BOLD%^%^RED%^lu%^RESET%^%^RED%^s%^BOLD%^%^RED%^t%^BLACK%^ surges through your veins%^RED%^!%^RESET%^");
    set_unwield("%^RESET%^%^RED%^You survey the %^BOLD%^%^RED%^c%^RESET%^%^RED%^a%^BOLD%^%^RED%^r%^RESET%^%^RED%^n%^BOLD%^%^RED%^a%^RESET%^%^RED%^g%^BOLD%^%^RED%^e%^RESET%^%^RED%^ left in your wake.");
}
int query_auto_load() { if (this_player()->query_level() > 20) return 1; }

int slap_on_the_wrist(string str) {
    if (!str || present(str, this_player()) != this_object()) return 0;
    if (member_array(this_player()->query_guild(),guilds)!=-1) return 0;
    write("This does not belong to you!");
    say(this_player()->query_cap_name()+" yelps as %^BOLD%^%^BLACK%^Da%^RESET%^%^WHITE%^rk%^BOLD%^%^WHITE%^ne%^BOLD%^%^BLACK%^ss%^RESET%^ burns them!", this_player());
    return 1;
}

void init() {
    ::init();
    add_action("slap_on_the_wrist", "wield");
}
