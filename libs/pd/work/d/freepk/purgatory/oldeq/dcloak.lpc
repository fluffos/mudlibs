# include <std.h>
inherit ARMOUR;
int extra_worn();
void create() {
    ::create();

    set_name("%^BOLD%^%^BLACK%^T%^RESET%^%^RED%^h%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^ R%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^p%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^r%^RESET%^%^RED%^s %^BOLD%^%^BLACK%^C%^RESET%^%^RED%^l%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^k%^RESET%^");

    set_short("%^BOLD%^%^BLACK%^T%^RESET%^%^RED%^h%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^ R%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^p%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^r%^RESET%^%^RED%^s %^BOLD%^%^BLACK%^C%^RESET%^%^RED%^l%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^k%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Hundreds of reaped and tortured souls inhabit this cloak, "
      "%^BOLD%^%^BLACK%^apparently made by %^BOLD%^%^BLACK%^T%^RESET%^%^RED%^h%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^ R%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^p%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^r himself. Shrieks and wails waft out "
      "%^BOLD%^%^BLACK%^of this forbidden piece of clothing. Evil seems to ebb and swell from the fringes...");
    set_id(({"cloak", "robe", "death"}));
    set_ac(5);            
    set_mass(225);
    set_type("body armour");      
    set_wear( (: extra_worn :) );
    set_remove("%^BOLD%^%^BLACK%^The souls feel that you have settled your sins with them and set you free.");
    set_limbs(({"head", "torso", "right arm", "tail", "left arm", "right leg", "left leg", "right foot", "left foot"}));
}

int extra_worn() {
    if((int)this_player()->query_level() < 89) {
	write("%^BOLD%^%^RED%^YOU FOOL!!!! You have brought Death and Destruction apon us all by stealing %^BOLD%^%^BLACK%^T%^RESET%^%^RED%^h%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^ R%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^p%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^r%^RESET%^%^RED%^s %^BOLD%^%^BLACK%^C%^RESET%^%^RED%^l%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^k%^RESET%^!!");
	say(this_player()->query_cap_name()+"%^BOLD%^%^RED%^ is an IDIOT!! Trying to wear %^BOLD%^%^BLACK%^T%^RESET%^%^RED%^h%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^ R%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^p%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^r%^RESET%^%^RED%^s %^BOLD%^%^BLACK%^C%^RESET%^%^RED%^l%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^k%^RESET%^%^BOLD%^%^RED%^ indeed! All of you around this person shall suffer!");
	notify_fail("%^BOLD%^%^RED%^YOU FOOL!!!! You have brought Death and Destruction apon us all by stealing %^BOLD%^%^BLACK%^T%^RESET%^%^RED%^h%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^ R%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^p%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^r%^RESET%^%^RED%^s %^BOLD%^%^BLACK%^C%^RESET%^%^RED%^l%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^k%^RESET%^");
	return 0;

    }
    write("%^BOLD%^%^BLACK%^Evil wells up from within the cloak as hands reach out to pull you into the cloak.");
    say(this_player()->query_cap_name() + " %^BOLD%^%^BLACK%^is CONSUMED by "+this_player()->query_possessive()+" evil deeds and now must wear the reapers cloak!");
    return 1;


}
int query_auto_load() { if (this_player()->query_level() > 90) return 1; }
