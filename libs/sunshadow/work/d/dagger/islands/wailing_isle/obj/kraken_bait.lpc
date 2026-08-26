// Chernobog & Titania (7/18/22)
// Wailing Isle - Kraken Bait

#include <std.h>
#include "../defs.h"

inherit OBJECT;

void create(){
	::create();
    set_name("sea monster bait");
	set_id(({"glass bottle", "bottle", "glass bottle of foul liquid", "liquid", "foul liquid", "bait"}));
	set_short("%^RESET%^%^CRST%^%^C250%^g%^C253%^la%^C250%^s%^C253%^s %^C250%^b%^C253%^ot%^C250%^t%^C253%^l%^C250%^e %^RESET%^%^C095%^of %^C094%^f%^C088%^o%^C094%^u%^C095%^l l%^C094%^i%^C088%^qu%^C094%^i%^C095%^d%^RESET%^%^CRST%^");
	set_long("%^RESET%^%^CRST%^%^C095%^Sealed within a glass jar, this %^C094%^re%^C088%^d%^C094%^d%^C088%^is%^C094%^h br%^C088%^ow%^C094%^n l%^C088%^i%^C094%^qu%^C088%^id %^RESET%^%^C095%^sloshes around easily with every motion. A lid keeps it from spilling, but you could easily %^C096%^<%^C102%^pour%^C096%^> %^C095%^it out when needed. Whatever it may be, it has a %^C108%^f%^C107%^i%^C106%^s%^C107%^h%^C108%^y %^C107%^r%^C106%^e%^C107%^e%^C108%^k %^RESET%^%^C095%^even from within the sealed container and causes your eyes to water.%^CRST%^");
	set_weight(1);
	set_value(0);
    set_lore("%^RESET%^%^CYAN%^It is said that the predators of the sea have an amazing sense of smell, detecting their prey over leagues with a disturbing precision. This particular concoction seems aimed at attracting one of the most dangerous denizens of the seas... a kraken.%^RESET%^");
    set_property("lore difficulty", 20);
}

void init(){
    ::init();
    add_action("pour_fun", "pour");
}

int pour_fun(string str){
    object player, room;
    int power;
    
    if(!str) return 0;
    if(str != "bottle" && str != "glass bottle" && str != "bait" && str != "liquid") return 0;
    
    player = this_player();
    room = environment(player);
    
    if(!room->is_boat()){
        message("info", "%^RESET%^%^CRST%^%^C059%^You were told you need to be at sea to use this bait.%^CRST%^", player);
        return 1;
    }
    
    message("environment", "%^RESET%^%^CRST%^%^C109%^You hold the %^C250%^b%^C253%^ot%^C250%^t%^C253%^l%^C250%^e %^RESET%^%^C109%^at arm's length, dumping it overboard into the %^C117%^s%^C123%^e%^C117%^a%^RESET%^%^C109%^.%^CRST%^\n", player);
    message("environment", "%^RESET%^%^CRST%^%^C109%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C109%^ holds the %^C250%^b%^C252%^ot%^C250%^t%^C252%^l%^C250%^e %^RESET%^%^C109%^at arm's length, dumping it overboard into the %^C117%^s%^C123%^e%^C117%^a%^RESET%^%^C109%^.%^CRST%^\n", room, player);
    
    power = max(({ player->query_level() / 10, 1 }));
    if(power > 5) power = 5;
    call_out("summon_start", 3, room, power);
    return 1;
}

void summon_start(object room, int power){
    message("environment", "%^RESET%^%^CRST%^%^C095%^The bait %^C103%^clouds %^C095%^the %^C111%^w%^C117%^a%^C123%^t%^C117%^e%^C111%^r%^RESET%^%^C095%^, spreading out slowly and staining the nearby sea a %^C094%^r%^C088%^ud%^C094%^d%^C088%^y %^C094%^h%^C088%^u%^C094%^e%^RESET%^%^C109%^.%^CRST%^\n", room);
    call_out("summon_middle", 3, room, power);
    return;
}

void summon_middle(object room, int power){
    message("environment", "%^RESET%^%^CRST%^%^C109%^The %^C111%^w%^C117%^a%^C123%^t%^C117%^e%^C111%^r %^RESET%^%^C109%^grows unnaturally %^C108%^calm %^C109%^and the air seems to %^C247%^h%^C245%^u%^C243%^s%^C059%^h...%^CRST%^\n", room);
    call_out("summon_end", 6, room, power);
    return;
}

void summon_end(object room, int power){
    object its_coming;
    
    its_coming = new(OBJ"kraken_event");
    its_coming->move(room);
    its_coming->start_event(power);
    this_object()->remove();
    return;
}

