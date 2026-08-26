// Chernobog & Titania (3/7/22)
// Wailing Isle - Cargo

#include <std.h>

inherit OBJECT;

int destroyed;

void create(){
	::create();
    set_name("pile of cargo");
	set_id(({"crates", "boxes", "cargo"}));
	set_short("%^RESET%^%^CRST%^%^C058%^a large pile of %^C136%^boxes %^C058%^and %^C136%^crates%^CRST%^");
    set_long((:this_object(), "long_fun":));
	set_weight(1000000);
	set_value(0);
	set_property("no animate",1);
    destroyed = 0;
}

void init(){
    ::init();
    add_action("ignite_fun", "ignite");
}

string long_fun(){
    string longdesc;
    object player;
    
    player = this_player();
    
    if(destroyed){
        longdesc = "%^RESET%^%^CRST%^%^C243%^Only the charred remains of broken crates and boxes have been left on the docks, with faint trails of smoke leading off into the sea breeze.%^CRST%^";
        return longdesc;
    }
    longdesc = "%^RESET%^%^CRST%^%^C058%^Wooden %^C136%^boxes %^C058%^and %^C136%^crates %^C058%^have been stacked here in preparation for loading onto one of the merchant vessels laying in wait along the docks.%^CRST%^\n";
    if(player->query("wailing isle quest") == 7) longdesc += "%^RESET%^%^CRST%^%^C124%^This appears to be the cargo to which Mister Brookes was referring. It does, indeed, seem like one could easily %^C196%^ignite %^C124%^it.%^CRST%^\n";
    return longdesc;
}

int ignite_fun(string str){
    object cargo, player, room, guard;
    
    if(!str) return 0;
    if(str != "crates" && str != "boxes" && str != "cargo") return 0;
    
    cargo = this_object();
    player = this_player();
    room = environment(cargo);
    
    tell_object(player, "%^RESET%^%^CRST%^%^C125%^It isn't hard to get an %^C124%^e%^C196%^m%^C124%^b%^C196%^e%^C124%^r %^RESET%^%^C125%^started, and it is quick to spread across the %^C058%^wooden crates %^C125%^and %^C058%^boxes%^C125%^. Before long there is a proper %^C202%^b%^C196%^o%^C202%^n%^C208%^f%^C202%^i%^C196%^r%^C202%^e %^RESET%^%^C125%^on the docks, though it has caught the attention of one of the local guards!%^CRST%^");
    tell_room(room, "%^RESET%^%^CRST%^%^C125%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C125%^ ignites the pile of cargo, the %^C202%^f%^C196%^i%^C202%^r%^C208%^e %^C125%^quickly spreading across the %^C058%^wooden crates %^C125%^and %^C058%^boxes%^RESET%^%^C125%^. Before long there is a proper %^C202%^b%^C196%^o%^C202%^n%^C208%^f%^C202%^i%^C196%^r%^C202%^e %^RESET%^%^C125%^on the docks, though it has caught the attention of one of the local guards!%^CRST%^", player);
    destroyed = 1;
    set_short("%^RESET%^%^CRST%^%^C058%^a %^C124%^sm%^C196%^o%^C124%^lde%^C196%^ri%^C124%^ng %^RESET%^%^C058%^pile of broken %^C136%^crates %^C058%^and %^C136%^boxes%^CRST%^");
    if(player->query("wailing isle quest") == 7) player->set("wailing isle quest", 8);
    guard = new("/d/shadow/city/mon/city_guard");
    guard->move(room);
    guard->force_me("kill "+player->query_name()+"");
    guard->force_me("say You there, you're under arrest!");
    
    call_out("reinforcements_1", 5, player, room);
    return 1;
}

void reinforcements_1(object player, object room){
    if(!present(player, room)) return;
    
    tell_room(room, "%^RESET%^%^CRST%^%^C226%^You can hear the rushed footsteps of guards approaching!%^CRST%^");
    call_out("reinforcements_2", 10, player, room);
    return;
}

void reinforcements_2(object player, object room){
    object guard;
    
    if(!present(player, room)) return;
    
    tell_room(room, "%^RESET%^%^CRST%^%^C226%^A pair of guards rush into the room, drawing their weapons!%^CRST%^");
    guard = new("/d/shadow/city/mon/city_guard");
    guard->move(room);
    guard->force_me("kill "+player->query_name()+"");
    guard = new("/d/shadow/city/mon/city_guard");
    guard->move(room);
    guard->force_me("kill "+player->query_name()+"");
    guard->force_me("say Halt, in the name of the law!");
    
    return;
}

void refresh_cargo(){
    destroyed = 0;
    set_short("%^RESET%^%^CRST%^%^C058%^a large pile of %^C136%^crates %^C058%^and %^C136%^boxes%^CRST%^");
    return;
}

