#include <std.h>
inherit WEAPON;
string *guilds = ({ "AoD", "darksoul" });
create() {
    ::create();
    set_id(({"staff", "Voided Staff"}));
    set_name("%^BOLD%^%^WHITE%^V%^BLACK%^o%^BLACK%^i%^WHITE%^d%^BLACK%^e%^WHITE%^d S%^BLACK%^t%^WHITE%^a%^BLACK%^f%^WHITE%^f%^RESET%^");
    set_short("%^BOLD%^%^WHITE%^V%^BLACK%^o%^BLACK%^i%^WHITE%^d%^BLACK%^e%^WHITE%^d S%^BLACK%^t%^WHITE%^a%^BLACK%^f%^WHITE%^f%^RESET%^");
    set_long( "%^BOLD%^%^BLACK%^A staff of infinite death and destruction if there every was one. Black oak turned to perfection, with obsidian runes carved and set deep within the wood.\n"
    );
    set_mass(80+random(10));
    set_curr_value("gold",240+random(40));
    set_wc(11);
    set_ac(1);
    set_type("blunt");
    set_wield("%^BOLD%^%^BLACK%^The staff quivers in your hands as if alive.");
    set_unwield("%^BOLD%^%^WHITE%^You gasp as you release the staff.");
    set_hit((:this_object(), "weapon_hit":));
}
int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 10) {
        write("%^BOLD%^%^BLACK%^Your staff crackles with energy as it drains the life-force of your opponents soul into your body, adding to your own.");
        say("%^BOLD%^%^BLACK%^"+(string)this_player()->query_cap_name()+"'s staff draws some life out of "+atk->query_cap_name()+".");
       
result= (random(90)+10);
this_player()->add_hp(result);
;
        return result/2;
    }
}
int query_auto_load() {
if(member_array(this_player()->query_guild(),guilds)==-1) return 0;
if(this_player()->query_level() < 40) return 0;

 return 1; 
}

int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (member_array(this_player()->query_guild(),guilds)) return 0;
   write("%^BOLD%^%^RED%^YOU ARE NOT A DARKSOUL!!!!!!!!!!");
   say(this_player()->query_cap_name()+" prances around like a little girly person.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wield");
}

