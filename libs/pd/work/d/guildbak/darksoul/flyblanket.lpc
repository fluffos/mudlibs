# include <std.h>
inherit ARMOUR;
int extra_worn();
void create() {
::create();
  
    set_name("%^ORANGE%^f%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^y%^BOLD%^%^BLACK%^-%^RESET%^%^ORANGE%^b%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^k%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^t%^RESET%^");
    
    set_short("%^ORANGE%^f%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^y%^BOLD%^%^BLACK%^-%^RESET%^%^ORANGE%^b%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^k%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^t%^RESET%^");
    set_long("A bunch of nasty %^ORANGE%^f%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^s%^RESET%^");
    set_id(({"fly-blanket", "armour", "flies", "blanket"}));
set_curr_value("gold",800+random(40));
    set_ac(2);            
    set_mass(25);
    set_type("body armour");
    set_wear( (: extra_worn :) );
    set_limbs(({ "abdomen", 
}));
}

int extra_worn() {
    if((int)this_player()->query_level() < 35) {
        write("You are not big enough to gather %^ORANGE%^f%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^s%^RESET%^!");
        say(this_player()->query_cap_name()+" waves their hands around the room like an idiot.");
        notify_fail("You are not big enough to gather %^ORANGE%^f%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^s%^RESET%^!");
  
    }
    write("%^ORANGE%^f%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^s%^RESET%^ gather around your abdomen as a protective shield.");
    say(this_player()->query_cap_name() + " summons hordes of %^ORANGE%^f%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^s%^RESET%^ into the room that almost block out the sun.");
    return 1;

}
 int query_auto_load() { if (this_player()->query_level() > 35) return 1; }
