#include <std.h>
#define SIGNS ({"friend", "enemy", "danger", "stop", "run", "mark", "idiot", "rich", "poor", "money", "kill", "mug", "lawman", "snitch"})

inherit DAEMON;

int cmd_make(string str){
    object *users, player;
    int i;

    if(!str) return notify_fail("Make what?\n");
    
    player = this_player();
    if(!player->is_class("thief") && !player->is_class("bard")) return 0;

    users = all_living(ETP);
    if(str == "thief sign"){
        if(player->query_invis()){
            tell_object(player, "%^RESET%^%^CRST%^%^C059%^You sign to the room that you are a thief.%^CRST%^");
            return 1;
        }
        for(i=0;i<sizeof(users);i++){
            if(!users[i]->is_class("thief") && !users[i]->is_class("bard")) continue;
            if(users[i] == player) continue;
            tell_object(users[i], "%^RESET%^%^CRST%^%^C059%^You notice "+player->query_cap_name()+"%^RESET%^%^CRST%^%^C059%^ signing to the room that "+player->query_subjective()+"%^RESET%^%^CRST%^%^C059%^ is a thief.%^CRST%^");
        }
        tell_object(player, "%^RESET%^%^CRST%^%^C059%^You sign to the room that you are a thief.%^CRST%^");
        return 1;
    }
    
    if(member_array(str, SIGNS) == -1){
            tell_object(player, "%^RESET%^%^CRST%^%^C059%^The only signs you can remember are: %^RESET%^%^CRST%^%^C124%^friend, enemy, danger, stop, run, mark, idiot, rich, poor, money, kill, mug, lawman, and snitch.%^CRST%^");
            return 1;
    }
    
    if(player->query_invis()){
            tell_object(player, "%^RESET%^%^CRST%^%^C059%^You make a few indiscrete gestures, signing to the room: %^RESET%^%^CRST%^%^C124%^"+str+"%^RESET%^%^CRST%^%^C059%^.%^CRST%^");
            return 1;
    }
    for(i=0;i<sizeof(users);i++){
        if(!users[i]->is_class("thief") && !users[i]->is_class("bard")) continue;
        if(users[i] == player) continue;
        tell_object(users[i], "%^RESET%^%^CRST%^%^C059%^You notice "+player->query_cap_name()+"%^RESET%^%^CRST%^%^C059%^ make a few indiscrete gestures, signing to the room: %^RESET%^%^CRST%^%^C124%^"+str+"%^RESET%^%^CRST%^%^C059%^.%^CRST%^");
    }
    tell_object(player, "%^RESET%^%^CRST%^%^C059%^You make a few indiscrete gestures, signing to the room: %^RESET%^%^CRST%^%^C124%^"+str+"%^RESET%^%^CRST%^%^C059%^.%^CRST%^");
    return 1;
}

void help(){
    write("Syntax: <make thief sign>\n        <make SIGN>\n\nTells EVERY thief and bard in the room that you are one of their brethren, or communicates a simple word. You never know who's going to be one. If you try to make a sign to the room while hidden, you'll find it doesn't work very well."
    );
}

