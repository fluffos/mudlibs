// Chernobog (11/15/21)
// Deep Caverns Demiplane Effect

#include <std.h>
#include <stdprops.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("grue orb");
    set_id(({ "darkness", "orb", "orb of darkness" }));
    set_short("%^RESET%^%^CRST%^%^C024%^floating %^C030%^orb %^C024%^of %^C059%^darkness%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C024%^The %^C030%^orb %^C024%^hovers just above the ground, rolling slowly about the area. Light seems to dim and wane in its proximity, though peering intently you can see some %^C030%^wisp of energy %^C024%^in the core of the %^C059%^darkness%^C024%^. You could probably %^C037%^snuff the orb %^C024%^with a bit of effort.%^CRST%^");
    set_weight(100000);
    set("value", 0);
}

void init(){
    ::init();
    add_action("snuff_fun","snuff");
}

varargs int move(mixed dest){
    int x;

    if(objectp(ETO)) environment(this_object())->set_property("light", 2);
    x = ::move(dest);
    if(objectp(ETO)) environment(this_object())->set_property("light", -2);
    return x;
}

remove(){
    if(objectp(ETO)) ETO->set_property("light", 2);
    tell_room(environment(TO),"%^RESET%^%^CRST%^%^C023%^The dar%^C024%^kness %^C030%^rece%^C037%^des...%^CRST%^");
    return ::remove();
}

int snuff_fun(string str){
    if(!str){
        tell_object(TP, "%^RESET%^%^CRST%^%^C023%^You could try to %^C030%^snuff the orb%^C023%^.%^CRST%^");
        return 0;
    }
    if((str != "orb") && (str != "the orb")){
        tell_object(TP, "%^RESET%^%^CRST%^%^C023%^You could try to %^C030%^snuff the orb%^C023%^.%^CRST%^");
        return 0;
    }
    if(TP->query_paralyzed()){
        tell_object(TP, "%^RESET%^%^CRST%^%^C125%^You're too busy to do that!%^CRST%^");
        return 1;
    }
    
    remove();
    return 1;
}

