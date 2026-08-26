//updated by Circe 7/11/04 with new desc, etc.
// Chernobog (10/13/22)
// cleaned up and removed unused code, converted to new colors

#include <std.h>
#include <move.h>

inherit OBJECT;

#define WOODS ({ "%^C144%^o%^C229%^a%^C144%^k", "%^C100%^pine", "%^C253%^b%^C249%^i%^C253%^rc%^C249%^h", "%^C144%^ash", "%^C130%^walnut", "%^C228%^cypress", "%^C136%^chestnut", "%^C124%^c%^C160%^her%^C124%^r%^C160%^y", "%^C144%^h%^C228%^i%^C144%^ck%^C228%^or%^C144%^y", "%^YELLOW%^maple", "%^RESET%^%^RED%^teak", "%^C101%^p%^C144%^o%^C101%^p%^C144%^la%^C101%^r", "%^C160%^r%^C124%^o%^C160%^s%^C124%^e%^C160%^w%^C124%^oo%^C160%^d", "%^C101%^e%^C144%^l%^C101%^m", "%^C130%^cedar", "%^C160%^r%^C124%^e%^C160%^dw%^C124%^oo%^C160%^d" })

string *mymsgs, *yourmsgs;
int lit, packed, hasmsgs, intox, tracker;

void create(){
    int i;
    ::create();
    i = random(sizeof(WOODS));
    set_name("wooden pipe");
    set_id(({ "wooden pipe", "pipe", "carved "+WOODS[i]+" pipe", ""+WOODS[i]+" pipe" }));
    set_short("%^RESET%^%^CRST%^%^C130%^a carved "+WOODS[i]+"%^RESET%^%^CRST%^%^C130%^ pipe%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C130%^This hand-carved creation is made of seasoned "+WOODS[i]+" %^RESET%^%^C130%^fashioned into a slender pipe and fitted with a %^C059%^black mouthpiece%^C130%^. The bowl of the pipe is deep and decorated with %^C058%^b%^C100%^u%^C101%^r%^C144%^n%^C058%^e%^C100%^d %^C101%^s%^C144%^c%^C058%^r%^C100%^o%^C101%^l%^C144%^l%^C058%^w%^C100%^o%^C100%^r%^C144%^k %^RESET%^%^C130%^that gives it an elegant appearance. You can %^C144%^pack %^C130%^it with tobacco or other herbs if you wish to %^C144%^smoke%^C130%^. When finished, you can %^C144%^douse %^C130%^it and %^C144%^empty %^C130%^it.%^CRST%^");
    set_weight(1);
    set_value(1500);
    set_property("repairtype", ({ "woodwork" }));
    
    packed = 0;
    lit = 0;
    hasmsgs = 0;
    tracker = 0;
    mymsgs = ({});
    yourmsgs = ({});
    intox = 0;
}

void init(){
    ::init();
    add_action("extinguish", "douse");
    add_action("smoke", "smoke");
    add_action("pack_pipe", "pack");
    add_action("pack_pipe", "fill");
    add_action("empty", "empty");
}

int smoke(string str){
    object pipe, player;
    pipe = this_object();
    player = environment(pipe);
    
    if(!id(str)){
        tell_object(player, "%^RESET%^%^CRST%^%^C100%^What do you want to smoke?%^CRST%^");
        return 0;
    }
    if(!packed){
        tell_object(player, "%^RESET%^%^CRST%^%^C100%^There is nothing in the pipe to smoke.%^CRST%^");
        return 0;
    }
    if(lit){
        tell_object(player, "%^RESET%^%^CRST%^%^C100%^It is already lit.%^CRST%^");
        return 0;
    }
    
    tell_object(player, "%^RESET%^%^CRST%^%^C100%^You light your pipe and begin %^C243%^s%^C245%^m%^C247%^o%^C249%^k%^C251%^i%^C253%^n%^C255%^g%^C100%^.%^CRST%^");
    tell_room(environment(player), "%^RESET%^%^CRST%^%^C100%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C100%^ lights their pipe and begins %^C243%^s%^C245%^m%^C247%^o%^C249%^k%^C251%^i%^C253%^n%^C255%^g%^C100%^.%^CRST%^", player);
    pipe->remove_property_value("added short", ({ " %^RESET%^%^CRST%^%^C076%^(%^C064%^packed%^C076%^)%^CRST%^" }));
    pipe->remove_property("added short");
    pipe->set_property("added short", ({ " %^RESET%^%^CRST%^%^C214%^(%^C202%^l%^C196%^i%^C202%^t%^C214%^)%^CRST%^" }));
    call_out("take_drag", 5);
    set_property("lit pipe", 1);
    lit = 1;
    return 1;
}

int extinguish(string str){
    object pipe, player;
    pipe = this_object();
    player = environment(pipe);
    
    if(!id(str)){
        tell_object(player, "%^RESET%^%^CRST%^%^C100%^What do you want to douse?%^CRST%^");
        return 0;
    }
    if(!lit){
        tell_object(player, "%^RESET%^%^CRST%^%^C100%^The pipe is not lit.%^CRST%^");
        return 0;
    }
    
    tell_object(player, "%^RESET%^%^CRST%^%^C100%^You douse your pipe.%^CRST%^");
    tell_room(environment(player), "%^RESET%^%^CRST%^%^C100%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C100%^ douses a pipe.%^CRST%^", player);
    remove_call_out("take_drag");
    pipe->remove_property("lit pipe");
    lit = 0;
    pipe->remove_property_value("added short", ({ " %^RESET%^%^CRST%^%^C214%^(%^C202%^l%^C196%^i%^C202%^t%^C214%^)%^CRST%^" }));
    pipe->set_property("added short", ({ " %^RESET%^%^CRST%^%^C076%^(%^C064%^packed%^C076%^)%^CRST%^" }));
    return 1;
}

int empty(string str){
    object pipe, player;
    pipe = this_object();
    player = environment(pipe);
    
    if(!id(str)){
        tell_object(player, "%^RESET%^%^CRST%^%^C100%^What do you want to empty?%^CRST%^");
        return 0;
    }
    if(lit == 1){
        tell_object(player, "%^RESET%^%^CRST%^%^C100%^You must douse your pipe before emptying it!%^CRST%^");
        return 0;
    }
    
    tell_object(player, "%^RESET%^%^CRST%^%^C100%^You empty your pipe.%^CRST%^");
    tell_room(environment(player), "%^RESET%^%^CRST%^%^C100%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C100%^ empties a pipe.%^CRST%^", player);
    lit = 0;
    packed = 0;
    intox = 0;
    hasmsgs = 0;
    pipe->remove_property_value("added short", ({ " %^RESET%^%^CRST%^%^C076%^(%^C064%^packed%^C076%^)%^CRST%^" }));
    pipe->remove_property("added short");
    return 1;
}

void take_drag(){
    object player, room;
    int i;
    
    player = environment(this_object());
    room = environment(player);
    
    if(!living(player)){
        call_out("go_out", 0);
        return;
    }
    if(tracker > 30 + random(4)){
        call_out("go_out", 0);
        return;
    }
    
    tell_object(player, "%^RESET%^%^CRST%^%^C100%^You take a long, gentle puff from your pipe.%^CRST%^");
    tell_room(room, "%^RESET%^%^CRST%^%^C100%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C100%^ takes a long, gentle puff from a pipe.%^CRST%^", player);
    if(intox){
        player->add_intox(intox);
        tell_object(player, "%^RESET%^%^CRST%^%^C144%^You start to feel %^C076%^s%^C070%^t%^C064%^r%^C076%^a%^C070%^n%^C064%^g%^C076%^e%^C144%^, and your mind wanders...%^CRST%^");
    }
    if(hasmsgs){
        i = random(sizeof(mymsgs));
        tell_object(player, mymsgs[i]);
        tell_room(room, yourmsgs[i], player);
    }
    tracker++;
    call_out("take_drag", random(30) + 60);
}

void go_out(){
    object pipe, player, room;
    pipe = this_object();
    player = environment(pipe);
    room = environment(player);
    
    tell_room(room, "%^RESET%^%^CRST%^%^C059%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C100%^'s pipe goes out.%^CRST%^", player);
    tell_object(player, "%^RESET%^%^CRST%^%^C059%^Your pipe goes out.%^CRST%^");
    pipe->remove_property("lit pipe");
    remove_call_out("take_drag");
    
    lit = 0;
    packed = 0;
    intox = 0;
    hasmsgs = 0;
    tracker = 0;
    
    pipe->remove_property_value("added short", ({ " %^RESET%^%^CRST%^%^C214%^(%^C202%^l%^C196%^i%^C202%^t%^C214%^)%^CRST%^" }));
    pipe->remove_property("added short");
}

int pack_pipe(string str){
    object ob, player = this_player();
    string pipe, tobacco_type;

    if(!str) return 0;
    if((sscanf(str, "%s with %s", pipe, tobacco_type)) != 2) return 0;
    if(pipe != "pipe") return 0;
    if(packed){
        tell_object(player, "%^RESET%^%^CRST%^%^C100%^The pipe is already packed.%^CRST%^");
        return 0;
    }
    if(!(ob = present(tobacco_type, player))){
        tell_object(player, "%^RESET%^%^CRST%^%^C100%^You don't see that here.%^CRST%^");
        return 1;
    }
    if(!(ob->is_tobacco())){
        tell_object(player, "%^RESET%^%^CRST%^%^C100%^You can't pack your pipe with that.%^CRST%^");
        return 1;
    }
    
    tell_object(player, "%^RESET%^%^CRST%^%^C100%^You pack your pipe with "+tobacco_type+".%^CRST%^");
    tell_room(environment(player), "%^RESET%^%^CRST%^%^C100%^"+player->query_cap_name()+"%^RESET%^%^CRST%^%^C100%^ packs their pipe with some "+tobacco_type+".%^CRST%^", player);
    packed = 1;
    ob->use_load();
    intox = (int)ob->query_intox();
    if(ob->query_has_messages()){
        hasmsgs = 1;
        mymsgs = ({});
        mymsgs = (string)ob->query_my_messages();
        yourmsgs = ({});
        yourmsgs = (string)ob->query_your_messages();
    }
    this_object()->remove_property_value("added short", ({ " %^RESET%^%^CRST%^%^C076%^(%^C064%^packed%^C076%^)%^CRST%^" }));
    this_object()->set_property("added short", ({ " %^RESET%^%^CRST%^%^C076%^(%^C064%^packed%^C076%^)%^CRST%^" }));
    return 1;
}

remove(){
    if(lit) call_out("go out", 2);
    if(packed) call_out("empty", 2);
    
    return ::remove();
}

int is_carving(){
    return 1;
}

