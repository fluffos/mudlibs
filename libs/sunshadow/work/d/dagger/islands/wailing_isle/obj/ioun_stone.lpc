// Chernobog (8/22/22)
// Wailing Isle - Ioun Stone

#include <std.h>
inherit ARMOUR;

#define COLORS ({ "crimson sphere", "deep red sphere", "incandescent blue sphere", "onyx rhomboid", "pale blue rhomboid", "pink and green sphere" })

string stone_color;

void create() {
    ::create();
    set_name("ioun stone");
    set_id(({ "ioun", "stone", "ioun stone", "ioun_slot_stone" }));
    set_obvious_short("%^RESET%^%^CRST%^%^C116%^small gray stone%^CRST%^");
    set_short("%^RESET%^%^CRST%^%^C116%^basic ioun stone%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C116%^This small gray stone is smooth to the touch. There seems to be some feeling of inherent potential.%^CRST%^");
    set_lore("%^RESET%^%^CYAN%^These stones are enchanted by powerful artificers, each type granting benefits to its bearer based on the gemstones or materials used. They are lightweight, sometimes even managing to float off of their own volition, but will maintain a regular orbit once placed nearby one's head.%^RESET%^");
    set_property("lore difficulty", 30);
    set_weight(1);
    set_value(0);
    set_type("ring");
    set_limbs( ({ "head" }) );
    set_ac(0);
    
    set_property("enchantment", 4);
    set_property("no alter", 1);
    set_wear((:this_object(), "wear_fun":));
    set_remove((:this_object(), "remove_fun":));
    
    stone_color = "%^RESET%^%^CRST%^%^C245%^gray%^CRST%^";
}

int wear_fun(){
    object player = environment(this_object());
    
    if(player->query_property("ioun")){
        message("info", "%^RESET%^%^CRST%^%^C116%^You already have an ioun stone in place.%^CRST%^", player);
        return 0;
    }
    
    message("environment", "%^RESET%^%^CRST%^%^C116%^You carefully place the "+stone_color+"%^RESET%^%^CRST%^%^C116%^ stone near your head... and it pulls free of your fingers, orbiting your head %^C158%^faster %^C116%^and %^C158%^faster %^RESET%^%^C116%^until it appears as a %^RESET%^%^C099%^f%^C105%^a%^C111%^d%^C117%^ed h%^C111%^a%^C105%^l%^C099%^o%^RESET%^%^C116%^.%^CRST%^", player);
    message("environment", "%^RESET%^%^CRST%^%^C116%^"+player->query_cap_name()+" carefully places the "+stone_color+"%^RESET%^%^CRST%^%^C116%^ stone near "+player->query_possessive()+"%^RESET%^%^CRST%^%^C116%^ head and it quickly begins to orbit, moving %^C158%^faster %^C116%^and %^C158%^faster %^RESET%^%^C116%^until it appears as a %^RESET%^%^C099%^f%^C105%^a%^C111%^d%^C117%^ed h%^C111%^a%^C105%^l%^C099%^o%^RESET%^%^C116%^.%^CRST%^", environment(player), player);
    player->set_property("ioun", 1);
    set_obvious_short("%^RESET%^%^CRST%^%^C116%^small "+stone_color+"%^RESET%^%^CRST%^%^C116%^ stone %^C099%^(o%^C105%^rb%^C111%^it%^C117%^ing th%^C111%^e h%^C105%^ea%^C099%^d)%^RESET%^%^CRST%^");
    set_short("%^RESET%^%^CRST%^%^C116%^"+stone_color+"%^RESET%^%^CRST%^%^C116%^ ioun stone %^C099%^(o%^C105%^rb%^C111%^it%^C117%^ing th%^C111%^e h%^C105%^ea%^C099%^d)%^RESET%^%^CRST%^");
    return 1;
}

int remove_fun(){
    object player = environment(this_object());
    
    message("environment", "%^RESET%^%^CRST%^%^C116%^You pluck the "+stone_color+"%^RESET%^%^CRST%^%^C116%^ stone from around your head and the aura quickly fades away.%^CRST%^", player);
    message("environment", "%^RESET%^%^CRST%^%^C116%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C116%^ plucks the "+stone_color+"%^RESET%^%^CRST%^%^C116%^ stone from around "+player->query_possessive()+"%^RESET%^%^CRST%^%^C116%^ head and the aura quickly fades away.%^CRST%^", environment(player), player);
    player->remove_property("ioun");
    set_obvious_short("%^RESET%^%^CRST%^%^C116%^small "+stone_color+"%^RESET%^%^CRST%^%^C116%^ stone%^CRST%^");
    set_short("%^RESET%^%^CRST%^%^C116%^"+stone_color+"%^RESET%^%^CRST%^%^C116%^ ioun stone%^CRST%^");
    return 1;
}

void choose_stone(string str){
    if(!str) str = "random";
    if(str == "random") str = COLORS[random(sizeof(COLORS))];
    
    switch(str){
        case "crimson sphere":
            stone_color = "%^RESET%^%^CRST%^%^C089%^c%^C088%^ri%^C052%^m%^C088%^so%^C089%^n s%^RESET%^%^C088%^p%^C052%^he%^C088%^r%^C089%^e%^CRST%^";
            set_item_bonus("intelligence", 3);
            set_value(24000);
            break;
        case "deep red sphere":
            stone_color = "%^RESET%^%^CRST%^%^C088%^d%^C052%^ee%^C088%^p r%^C052%^e%^RESET%^%^C088%^d sp%^C052%^he%^C088%^re%^CRST%^";
            set_item_bonus("dexterity", 3);
            set_value(8000);
            break;
        case "incandescent blue sphere":
            stone_color = "%^RESET%^%^CRST%^%^C019%^in%^C020%^ca%^C021%^nd%^C027%^es%^C026%^ce%^C025%^nt %^C019%^b%^C020%^l%^C021%^u%^C027%^e %^RESET%^%^C019%^s%^C020%^p%^C021%^h%^C027%^e%^C026%^r%^C025%^e%^CRST%^";
            set_item_bonus("wisdom", 3);
            set_value(8000);
            break;
        case "onyx rhomboid":
            stone_color = "%^RESET%^%^CRST%^%^C059%^on%^C243%^y%^C059%^x rho%^C243%^mb%^C059%^oid%^CRST%^";
            set_item_bonus("constitution", 3);
            set_value(24000);
            break;
        case "pale blue rhomboid":
            stone_color = "%^RESET%^%^CRST%^%^C075%^p%^C081%^a%^C075%^le bl%^C081%^u%^C075%^e %^C075%^rh%^C081%^o%^C075%^mb%^C081%^o%^C075%^id%^CRST%^";
            set_item_bonus("strength", 3);
            set_value(8000);
            break;
        case "pink and green sphere":
            stone_color = "%^RESET%^%^CRST%^%^C201%^p%^C206%^i%^C211%^n%^C216%^k %^C221%^a%^C226%^n%^C118%^d %^C046%^g%^C047%^r%^C048%^e%^C120%^e%^C119%^n %^C118%^s%^C221%^p%^C216%^h%^C211%^e%^C206%^r%^C201%^e%^CRST%^";
            set_item_bonus("charisma", 3);
            set_value(8000);
            break;
        default:
            stone_color = "%^RESET%^%^CRST%^%^C116%^broken";
    }
    add_id(stone_color);
    set_obvious_short("%^RESET%^%^CRST%^%^C116%^small "+stone_color+"%^RESET%^%^CRST%^%^C116%^ stone%^CRST%^");
    set_short("%^RESET%^%^CRST%^%^C116%^"+stone_color+"%^RESET%^%^CRST%^%^C116%^ ioun stone%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C116%^This is a small "+stone_color+"%^RESET%^%^CRST%^%^C116%^, easily held in the palm of your hand. It feels light, as if it could float away at any moment.%^CRST%^");
    return;
}

void query_stone_color(){
    return stone_color;
}

