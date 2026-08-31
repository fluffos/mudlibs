# include <std.h>
inherit ARMOUR;
int extra_worn();

string *guilds = ({ "AoD", "darksoul" });
void create() {
::create();
  
    set_name("%^BOLD%^%^BLACK%^Ph%^WHITE%^a%^RESET%^%^WHITE%^n%^BOLD%^%^BLACK%^to%^WHITE%^m G%^RESET%^%^WHITE%^l%^BOLD%^%^BLACK%^ov%^WHITE%^e%^RESET%^%^WHITE%^s%^RESET%^");
    
    set_short("%^BOLD%^%^BLACK%^Ph%^WHITE%^a%^RESET%^%^WHITE%^n%^BOLD%^%^BLACK%^to%^WHITE%^m G%^RESET%^%^WHITE%^l%^BOLD%^%^BLACK%^ov%^WHITE%^e%^RESET%^%^WHITE%^s%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^These gloves were created by an ancient lich who instilled the "
"%^BOLD%^%^BLACK%^souls of his "
"%^BOLD%^%^BLACK%^victoms in his inventions.  Every now and then a faint howling can be heard "
"%^BOLD%^%^BLACK%^issuing forth from within them.  They seem %^BOLD%^%^BLUE%^c%^RESET%^%^BLUE%^o%^BOLD%^%^BLUE%^l%^RESET%^%^BLUE%^d%^BOLD%^%^BLACK%^ to the touch and only the most "
"%^BOLD%^%^BLACK%^daring find the courage to wear these gloves.");
    set_id(({"gloves", "glove" , "phantom_gloves"}));
    set_ac(5);            
    set_weight(15);
    set_curr_value("gold", 100+random(30));
    set_type("gloves");
    set_wear( (: extra_worn :) );
    set_limbs(({ "first hand" , "second hand" , "third hand" , "fourth hand"}));
    set_remove("%^BOLD%^%^RED%^Warmth returns and the voices in your head fade away...%^RESET%^"); 
}
int extra_worn() {
    if((int)this_player()->query_level() < 30) {
        write("%^BOLD%^%^WHITE%^Don't be foolish!  Wearing these gloves would surely lead to your demise.%^RESET%^");
        say(this_player()->query_cap_name()+" appears to be knocked back by an invisible force.");
        return notify_fail("You are not powerful enough for this item.");
  
    }
    write("%^BOLD%^%^BLUE%^Y%^RESET%^%^BLUE%^o%^BOLD%^%^BLUE%^u s%^RESET%^%^BLUE%^h%^BOLD%^%^BLUE%^i%^RESET%^%^BLUE%^v%^BOLD%^%^BLUE%^e%^RESET%^%^BLUE%^r v%^BOLD%^%^BLUE%^i%^RESET%^%^BLUE%^o%^BOLD%^%^BLUE%^l%^RESET%^%^BLUE%^e%^BOLD%^%^BLUE%^n%^RESET%^%^BLUE%^t%^BOLD%^%^BLUE%^l%^RESET%^%^BLUE%^y a%^BOLD%^%^BLUE%^s a%^RESET%^%^BLUE%^n i%^BOLD%^%^BLUE%^c%^RESET%^%^BLUE%^y c%^BOLD%^%^BLUE%^h%^RESET%^%^BLUE%^i%^BOLD%^%^BLUE%^l%^RESET%^%^BLUE%^l b%^BOLD%^%^BLUE%^o%^RESET%^%^BLUE%^l%^BOLD%^%^BLUE%^t%^RESET%^%^BLUE%^s t%^BOLD%^%^BLUE%^h%^RESET%^%^BLUE%^r%^BOLD%^%^BLUE%^o%^RESET%^%^BLUE%^u%^BOLD%^%^BLUE%^g%^RESET%^%^BLUE%^h y%^BOLD%^%^BLUE%^o%^RESET%^%^BLUE%^u%^BOLD%^%^BLUE%^r s%^RESET%^%^BLUE%^p%^BOLD%^%^BLUE%^i%^RESET%^%^BLUE%^n%^BOLD%^%^BLUE%^e%^RESET%^%^BLUE%^!%^RESET%^");
    say(this_player()->query_cap_name() + " shivers visibly as the temperature drops drematicly.");
    return 1;
}
 int query_auto_load() { if (this_player()->query_level() > 30) return 1; }



int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (member_array(this_player()->query_guild(),guilds)) return 0;
   write("This does not belong to you!");
   say(this_player()->query_cap_name()+" screams in terror as the gloves fade to mist.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wield");
}

