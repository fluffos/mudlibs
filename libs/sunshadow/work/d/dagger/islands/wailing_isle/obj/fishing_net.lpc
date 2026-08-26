// Chernobog & Titania (2/21/22)
// Fishing Net

#include <std.h>
#include "../defs.h"

inherit OBJECT;

int uses;

void create(){
    ::create();
    set_name("fishing net");
    set_id(({"net","fishing net"}));
	set_short("%^RESET%^%^CRST%^%^C130%^fi%^C136%^s%^C130%^hin%^C136%^g %^C130%^n%^C136%^e%^C130%^t%^CRST%^");
	set_long("%^RESET%^%^CRST%^%^C058%^Woven with skill, this %^C130%^n%^C136%^e%^C130%^t %^RESET%^%^C058%^is fairly light and yet seems quite durable. You can %^C226%^<%^C220%^cast the net%^C226%^> %^RESET%^%^C058%^into nearby waters.%^CRST%^");
	set_weight(5);
	set_value(1000);
    uses = random(5) + 6;
}

void init(){
    ::init();
    add_action("cast_fun", "cast");
}

void set_uses(int new_total){
    uses = new_total;
    return;
}

int cast_fun(string str){
    object player, room, net;
    
    if((str != "net") && (str != "the net")) return 0;
    
    player = this_player();
    room = environment(player);
    
    if(present("cast fishing net", room)){
        tell_object(this_player(), "%^RESET%^%^CRST%^%^C059%^Someone is already fishing here.%^CRST%^");
        return 1;
    }
    if(!room->is_dock() && (!room->is_boat())){
        tell_object(player, "%^RESET%^%^CRST%^%^C059%^You don't see a way to fish here.%^CRST%^");
        return 1;
    }
    
    tell_object(player, "%^RESET%^%^CRST%^%^C058%^You cast the fishing net and attach the line nearby.%^CRST%^");
    tell_room(room, "%^RESET%^%^CRST%^%^C058%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C058%^ casts a fishing net and attaches the line nearby.%^CRST%^", player);
    net = new(OBJ"fishing_net_cast");
    if(room->is_boat()) net->set_short("%^RESET%^%^CRST%^%^C058%^a %^C130%^fi%^C136%^s%^C130%^hin%^C136%^g %^C130%^l%^C136%^i%^C130%^ne%^RESET%^%^C058%^ bound to the side of the boat%^CRST%^");
    net->move(room);
    net->set_uses(uses);
    net->start_fishing();
    this_object()->move("/d/shadowgate/void");
    //this_object()->remove();
    return 1;
}

