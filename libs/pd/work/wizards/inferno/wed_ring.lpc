//	/obj/wed_ring.c
//	from the Nightmare mudlib
//	a wedding ring for the married ones of the mud
//	created by Descartes of Borg august 1992

#include <std.h>

inherit ARMOUR;

string short_fun();
string extra_look();

string me, spouse;
int jealous;

set_spouse(string str) { spouse = str; }

set_me(string str) { me = str; }

init()
{
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
    set_id( ({ "ring", "wedding ring" }) );
    set_name("ring");
    set_short( (: short_fun() :) );
    set_long( (: extra_look() :) );
    set_ac(1);
    set_type("ring");
    set_limbs( ({ "left hand" }) );
    set_weight(1);
    set_value(10000);
    set_spouse(this_player()->query_current_marriage()[0]);
    set_me(this_player()->query_name());
}

notify_spouse(string str)
{
    if(!find_living(spouse))
    {
        write(capitalize(spouse)+" is not around.\n");
        return 1;
    }
    tell_object(find_living(spouse) , "<"+this_player()->query_name()+"> Honey: "+str+"\n");
    tell_object(this_player(), "<"+this_player()->query_name()+"> Honey: "+str+"\n");
    return 1;
}

jealous_action0(str)
{
    if(!str) return 0;
    if(str != spouse) notify_jealous(0);
    return 0;
}

jealous_action1(str)
{
    if(!str) return 0;
    if(str != spouse) notify_jealous(1);
    return 0;
}

jealous_action2(str)
{
    if(!str) return 0;
    if(str != spouse) notify_jealous(2);
    return 0;
}

notify_jealous(arg)
{
    object zip;

    if(!find_living(spouse)) return;
    if(!arg) tell_object(find_living(spouse), "You are feeling a little jealous.\n");
    else if(arg == 1) tell_object(find_living(spouse), "You feel jealous.\n");
    else tell_object(find_living(spouse), "You feel very jealous.\n");
    if(zip = present("night_wed_ring", find_player(spouse)))
      zip->add_jealous(arg);
    return;
}

welcome()
{
    notify_spouse("I'm home.");
    set_long("A solid gold ring.  There is an inscription on it.\n");
    call_out("wear", 2, "ring");
}

remove_ring(str)
{
    if(str != "ring") return 0;
    write("You may only remove your wedding ring through divorce!\n");
    return 1;
}

string
extra_look()
{
     return (capitalize(me)+" is married to "+capitalize(spouse)+".\n");
}
/*
get()
{
    return 0;
}
*/
drop()
{
    return 1;
}

add_jealous(arg)
{
    jealous = jealous + arg;
    return;
}

query_jealous()
{
    return jealous;
}

int query_auto_load()
{
    return 1;
}

void init_arg(mixed *arg)
{

//    me = arg[0];
//    spouse = arg[1];
//    jealous = arg[2];
    welcome();
    set("read", "From "+capitalize(spouse)+" with love.\n");

}

// Following lines added by Darkone 2/20/93
string query_spouse() { return spouse; }
string query_me() { return me; }

string short_fun() { return (capitalize(me)+"'s wedding ring"); }
