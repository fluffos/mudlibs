//	/obj/wed_ring.c
//	from the Nightmare mudlib
//	a wedding ring for the married ones of the mud
//	created by Descartes of Borg august 1992
//	slight changes by Drakken 13.Nov.1994

#include <std.h>

inherit ARMOUR;

string short_fun();

string me, spouse;
int jealous;

set_spouse(str) { spouse = str; }

set_me(str) { me = str; }

init() {
    ::init();
    add_action("remove_ring","remove");
    add_action("notify_spouse","honey");
    add_action("jealous_action0","kiss");
    add_action("jealous_action2","french");
    add_action("jealous_action2","snuggle");
    add_action("jealous_action0","wink");
    add_action("jealous_action1","nibble");
    add_action("jealous_action2","love");
    add_action("jealous_action2","lick");
    add_action("jealous_action2","grope");
    add_action("jealous_action2","fondle");
    add_action("jealous_action1","cuddle");
}

void create() {
    ::create();
    set_id( ({ "band", "night_wed_ring", "wedding ring" }) );
    set_name("band");
    set_short( (: short_fun :) );
    set_long("A solid %^YELLOW%^gold%^RESET%^ band.  There is an inscription on it.\n");
    set_ac(1);
    set_type("ring");
    set_limbs( ({ "left hand" }) );
    set_mass(0);
    set_prevent_get("You cannot get that!");
    set_prevent_drop("You cannot drop that!");
    set_prevent_put("You cannot put that in there!");
    set_value(0);
}

notify_spouse(str) {
    if(!spouse) return;
    if(!find_player(spouse)) {
        message("my_action", sprintf("%s is not around.", capitalize(spouse)), this_player());
        return 1;
    }
    message("my_action", sprintf("%%^RED%%^%%^BOLD%%^Honey: %%^RESET%%^%s", str), find_player(spouse));
    message("my_action", sprintf("You tell your spouse: %s", str), this_player());
    return 1;
}

jealous_action0(str) {
    string who,rest;
    object ob;

    if(!str) return 0;
    sscanf(str, "%s %s",who ,rest);
    if(!rest) who = str;
    if(!find_player(who)) return 0;
    ob = present(who, environment(this_player()));
    if(!ob) return 0;
    if(spouse != who) notify_jealous(0);
    return 0;
}

jealous_action1(str) {
    string who,rest;
    object ob;

    if(!str) return 0;
    sscanf(str, "%s %s",who ,rest);
    if(!rest) who = str;
    if(!find_player(who)) return 0;
    ob = present(who, environment(this_player()));
    if(!ob) return 0;
    if(spouse != who) notify_jealous(1);
    return 0;
}

jealous_action2(str) {
    string who,rest;
    object ob;

    if(!str) return 0;
    sscanf(str, "%s %s",who ,rest);
    if(!rest) who = str;
    if(!find_player(who)) return 0;
    ob = present(who, environment(this_player()));
    if(!ob) return 0;
    if(spouse != who) notify_jealous(2);
    return 0;
}

notify_jealous(arg) {
    object zip;

    if(!find_player(spouse)) return;
    if(!arg) message("info","You are feeling a little jealous.",find_player(spouse));
    else if(arg == 1) message("info","You feel jealous.",find_player(spouse));
    else message("info","You feel very jealous.",find_player(spouse));
    if(zip = present("night_wed_ring", find_player(spouse)))
      zip->add_jealous(arg);
}

welcome() {
    notify_spouse("I'm home.");
    call_out("wear", 2, "band");
}

remove_ring(str) {
    if(str != "band") return 0;
    message("my_action","You may only remove your wedding band through divorce!",this_player());
    return 1;
}

string extra_look() {
    return (capitalize(me)+" is married to "+capitalize(spouse)+".\n");
}

add_jealous(arg) {
    jealous = jealous + arg;
    return;
}

query_jealous() {
    return jealous;
}

mixed *query_auto_load() {
    return ({ "/std/obj/wed_ring", ({ me, spouse, jealous }) });
}

void init_arg(mixed *arg) {
    me = arg[0];
    spouse = arg[1];
    jealous = arg[2];
    welcome();
    set_read("%^MAGENTA%^From "+capitalize(spouse)+" with love%^RESET%^.\n");
}

// Following lines added by Darkone 2/20/93
string query_spouse() { return spouse; }
string query_me() { return me; }

string short_fun() { return (capitalize(me)+"'s wedding band"); }
