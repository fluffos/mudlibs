// Chernobog & Titania (4/5/22)
// Wailing Isle - Voodoo Compass

#include <std.h>

inherit OBJECT;

string owner;
int DELAY = 43200;

void create(){
	::create();
    set_name("voodoo compass");
	set_id(({"compass", "voodoo compass"}));
	set_short("%^RESET%^%^CRST%^%^C101%^small %^C172%^b%^C178%^r%^C184%^a%^C172%^s%^C178%^s %^RESET%^%^C101%^comp%^C059%^a%^C196%^s%^C101%^s%^CRST%^");
	set_long("%^RESET%^%^CRST%^%^C101%^Small and circular, this compass fits easily in the palm of one's hand. Wrapped in %^C172%^d%^C178%^e%^C184%^n%^C172%^t%^C178%^e%^C184%^d %^RESET%^%^C172%^b%^C178%^r%^C184%^a%^C172%^s%^C178%^s%^RESET%^%^C101%^, the glass cover has been broken to expose the sharp %^C059%^ma%^C244%^gn%^C196%^et%^C124%^ic %^C245%^needle%^C101%^, the tip coated in dried %^C058%^brown flakes%^C101%^. Where one might expect to see markings denoting the cardinal directions, it has been defaced with a series of %^RESET%^%^C118%^s%^C112%^o%^C106%^ft%^C118%^l%^C112%^y %^C106%^gl%^C118%^o%^C112%^w%^C106%^in%^C118%^g %^RESET%^%^C118%^s%^C112%^i%^C106%^gi%^C118%^l%^C112%^s %^C101%^that seem to writhe and twist when you look away.%^CRST%^");
	set_weight(1);
	set_value(0);
    set_lore("%^RESET%^%^CYAN%^Crafted by Kietta, the strange herbalist of the Wailing Isle, a compass like this has been enchanted with a strong magic to return a traveler safely to the isle by %^BOLD%^touch%^RESET%^%^CYAN%^ing the %^BOLD%^needle%^RESET%^%^CYAN%^... at the price of a measure of the user's strength. The creation of these artifacts is quite draining, and not something that she would undertake lightly.%^RESET%^");
    set_property("lore difficulty", 50);
    set_property("no alter", 1);
}

void init(){
    ::init();
    add_action("teleport_me", "touch");
}

int teleport_me(string str){
    object compass, player, room;
    int reputation, tpward, sacrifice, current_hp;
    
    compass = this_object();
    player = environment(compass);
    room = environment(player);
    reputation = player->query("reputation wailing isle");
    
    if(!str) return 0;
    if(str != "needle" && str != "the needle") return 0;
    if(!userp(player)) return 0;
    if(player->query_bound() || player->query_unconscious() || player->query_paralyzed()){
        tell_object(player, "%^RESET%^%^CRST%^%^C059%^You are unable to move to do that.%^CRST%^");
        return 1;
    }
    if(player->query_name() != owner){
        tell_object(player, "%^RESET%^%^CRST%^%^C059%^The compass fails to respond to your touch.%^CRST%^");
        tell_room(room,"%^RESET%^%^CRST%^%^C059%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C059%^ taps against the needle of their compass.%^CRST%^", player);
        return 1;
    }
    if(reputation < 50){
        tell_object(player, "%^RESET%^%^CRST%^%^C059%^The compass fails to respond to your touch.%^CRST%^");
        tell_room(room,"%^RESET%^%^CRST%^%^C059%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C059%^ taps against the needle of their compass.%^CRST%^", player);
        return 1;
    }
    if(player->cooldown("voodoo compass")){
        tell_object(player, "%^RESET%^%^CRST%^%^C059%^You don't feel ready to make the sacrifice yet.%^CRST%^");
        return 1;
    }
    if(room->query_property("no teleport")){
        tell_object(player, "%^RESET%^%^CRST%^%^C059%^The compass fails to respond to your touch.%^CRST%^");
        tell_room(room,"%^RESET%^%^CRST%^%^C059%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C059%^ taps against the needle of their compass.%^CRST%^", player);	 	  
        return 1;
    }
    tpward = room->query_property("teleport proof");
    if(tpward > (player->query_base_character_level() + roll_dice(1, 10))){
        tell_object(player, "%^RESET%^%^CRST%^%^C059%^The compass fails to respond to your touch.%^CRST%^");
        tell_room(room,"%^RESET%^%^CRST%^%^C059%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C059%^ taps against the needle of their compass.%^CRST%^", player);	 	  
        return 1;
    }
    
    tell_object(player, "%^RESET%^%^CRST%^%^C101%^You press your finger to the %^C172%^c%^C178%^o%^C184%^m%^C172%^p%^C178%^a%^C184%^s%^C172%^s %^C059%^ne%^C245%^e%^C196%^dl%^C124%^e %^RESET%^%^C101%^and feel it pierce the skin. Drops of blood flow down, soaking into the wood and brass as it begins to %^C118%^e%^C112%^e%^C106%^ri%^C118%^l%^C112%^y %^C106%^gl%^C118%^o%^C112%^w%^RESET%^%^C101%^... and you feel yourself falling backwards.%^CRST%^");
    tell_room(room, "%^RESET%^%^CRST%^%^C101%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C101%^ presses their finger to the %^C172%^c%^C178%^o%^C184%^m%^C172%^p%^C178%^a%^C184%^s%^C172%^s %^C059%^ne%^C245%^e%^C196%^dl%^C124%^e%^RESET%^%^C101%^. Drops of blood flow down, soaking into the wood and brass as it begins to %^C118%^e%^C112%^e%^C106%^ri%^C118%^l%^C112%^y %^C106%^gl%^C118%^o%^C112%^w%^RESET%^%^C101%^... and then they vanish, falling backwards into a %^C059%^pool %^C245%^of %^C244%^s%^C243%^h%^C059%^ad%^C243%^o%^C244%^w%^RESET%^%^C101%^.%^CRST%^", player);
    
    player->move_player("/d/dagger/islands/wailing_isle/room/beach3");
    sacrifice = player->query_max_hp() / 2;
    current_hp = player->query_hp();
    if(sacrifice > current_hp) player->set_hp(1);
    else player->set_hp(current_hp - sacrifice);
    player->add_cooldown("voodoo compass", DELAY);
    
    room = environment(player);
    tell_object(player, "%^RESET%^%^CRST%^%^C101%^The world twists and you feel disoriented for a moment before everything straightens out.%^CRST%^");
    tell_room(room, "%^RESET%^%^CRST%^%^C101%^A %^C059%^pool %^C245%^of %^C244%^s%^C243%^h%^C059%^ad%^C243%^o%^C244%^w %^RESET%^%^C101%^appears on the ground, and "+player->query_cap_name()+"%^RESET%^%^CRST%^%^C101%^ appears to be propelled upwards out of it, landing shakily on their feet.%^CRST%^", player);
    return 1;
}

void set_owner(string str){
    owner = str;
    return;
}

int isMagic(){ return 2; }