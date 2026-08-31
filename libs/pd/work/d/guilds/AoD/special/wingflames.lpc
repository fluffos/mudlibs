# include <std.h>
inherit ARMOUR;
int extra_worn();
int extra_removed();
void create() {
::create();
set_name("Wing Flames");
    
    set_short("%^BOLD%^%^BLUE%^Wi%^WHITE%^n%^YELLOW%^g F%^RED%^l%^YELLOW%^a%^WHITE%^m%^BLUE%^es%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^Only the holy seraphim may adorn their wings with these %^BLUE%^bl%^CYAN%^ue fla%^BLUE%^mes%^RESET%^. "
"Blessed by the One who sits in his great halls in the sky, they serve to protect "
"the vulnerable wings of the majestic angels.  Those with evil in their hearts covet "
"these flames, yet dare not touch them for they sense evil and attack at will.");
    set_id(({"wing_flames", "flames"}));
    set_ac(4);            
    set_weight(8);
    set_curr_value("gold", 130);
    set_type("wing armour");  
    set_wear( (: extra_worn :) );
    set_remove( (: extra_removed :) );
    set_limbs(({ "right wing" , "left wing" }));
}
int extra_worn() {
    write("%^BOLD%^%^BLUE%^The blue flames envelope your wings creates a brilliant glow about you!%^RESET%^");
    say(this_player()->query_cap_name() + " unfurls his mighty wings as flames dance upon them%^RESET%^!");
    this_player()->set_paralyzed(2,"You are still struggling with your wing armour.");
    return 1;
}
int extra_removed() {
    write("%^BOLD%^%^BLUE%^The blue flames go out as you struggle to remove your armour!%^RESET%^");
    say(this_player()->query_cap_name() + " struggles to remove some wing armour%^RESET%^.");
    this_player()->set_paralyzed(2,"You are still struggling with your wing armour.");
    return 1;
}
 int query_auto_load() { if (this_player()->query_level() > 34) return 1; }
