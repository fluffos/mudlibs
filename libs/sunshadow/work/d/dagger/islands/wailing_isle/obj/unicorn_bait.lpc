// Chernobog & Titania (3/3/22)
// Wailing Isle - Unicorn Bait

#include <std.h>

inherit OBJECT;

void create(){
	::create();
    set_name("unicorn bait");
	set_id(({"vial", "blood", "runed vial", "runed vial of blood", "unicorn_bait"}));
	set_short("%^RESET%^%^CRST%^%^C118%^r%^C112%^un%^C106%^e%^C118%^d %^RESET%^%^C059%^vial of %^C196%^bl%^C124%^o%^C196%^o%^C124%^d%^CRST%^");
	set_long("%^RESET%^%^CRST%^%^C059%^This small vial is filled with a vibrant crimson fluid that moves with the viscous consistency of %^C196%^bl%^C124%^o%^C196%^o%^C124%^d%^RESET%^%^C059%^. Strange symbols have been painted along the glass in a %^C118%^f%^C112%^ou%^C106%^l %^C118%^i%^C112%^ch%^C106%^o%^C118%^r%^RESET%^%^C059%^, glowing faintly but seeming to preserve the contents. The lid can be removed so that one can <sprinkle blood> about an area, when needed.%^CRST%^");
	set_weight(1);
	set_value(0);
    set_lore("%^RESET%^%^CYAN%^One of the more common legends regarding unicorns are their affinity for virginal innocence, often drawn to maidens and only allowing such to ever ride them. This vial seems to emanate and enhance such an aura, but the price for its creation is the sacrifice of a woman still possessing her maidenhead and filling a prepared vial with her heart's blood.%^RESET%^");
    set_property("lore difficulty", 30);
}

void init()
{
	::init();
    add_action("sprinkle_fun", "sprinkle");
}

int sprinkle_fun(string str){
    object player, room, blood, unicorn;
    int power;
    player = environment(this_object());
    if(!userp(player)) return 0;
    room = environment(player);
    power = max(({ player->query_level() / 10, 1 }));
    
    if(!str) return 0;
    if(str != "blood"){
        tell_object(player, "You could try to <sprinkle blood>.");
        return 0;
    }
    if(!objectp(blood = present("unicorn_bait", player))){
        tell_object(player, "You don't have the proper bait.");
        return 0;
    }
    if(!room->can_bait_unicorn()){
        tell_object(player, "This doesn't appear to be the right place. Kietta mentioned a willow tree... in the vale?");
        return 1;
    }
    
    tell_object(player, "%^RESET%^%^CRST%^%^C059%^As you open the vial and sprinkle the %^C196%^bl%^C124%^o%^C196%^o%^C124%^d %^RESET%^%^C059%^about the base of the %^C108%^willow%^C059%^, a breeze picks up and sends all the %^C130%^bra%^C136%^nc%^C130%^h%^C136%^e%^C130%^s %^RESET%^%^C059%^and %^C040%^le%^C046%^av%^C040%^e%^C046%^s %^RESET%^%^C059%^fluttering...%^CRST%^");
    tell_room(room, "%^RESET%^%^CRST%^%^C059%^As "+player->query_cap_name()+"%^RESET%^%^CRST%^%^C059%^ opens the vial and sprinkles the %^C196%^bl%^C124%^o%^C196%^o%^C124%^d %^RESET%^%^C059%^about the base of the %^C108%^willow%^C059%^, a breeze picks up and sends all the %^C130%^bra%^C136%^nc%^C130%^h%^C136%^e%^C130%^s %^RESET%^%^C059%^and %^C040%^le%^C046%^av%^C040%^e%^C046%^s %^RESET%^%^C059%^fluttering...%^CRST%^", player);
    call_out("summon_fun", 3, room, power, blood);
    return 1;
}

void summon_fun(object room, int power, object blood){
    object unicorn;
    
    tell_room(room, "\n%^RESET%^%^CRST%^%^C255%^With a %^C196%^th%^C124%^un%^C196%^de%^C124%^ri%^C196%^ng %^RESET%^%^C255%^of %^C059%^hooves%^C255%^, a %^RESET%^%^C214%^u%^C220%^n%^C226%^ico%^C220%^r%^C214%^n %^RESET%^%^C255%^comes charging into view!%^CRST%^");
    unicorn = new("/d/dagger/islands/wailing_isle/mon/unicorn");
    unicorn->move(room);
    unicorn->set_powerlevel(5);
    blood->remove();
    return;
}

