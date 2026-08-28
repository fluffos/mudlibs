//	/obj/wed_ring.c
//	from the Nightmare mudlib
//	a wedding ring for the married ones of the mud
//	created by Descartes of Borg august 1992

#include <std.h>

inherit ARMOUR;
void notify_jealous(int);
string me, spouse;
int jealous;

void set_spouse(string str) { spouse = str; }

void set_me(string str) { me = str; }

void init()
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
    set_id( ({ "band", "night_wed_ring", "wedding ring" }) );
    set_name("band");
    set("short", (: call_other, this_object() , "short_fun" :) );
    set_type("ring");
    set_limbs( ({ "left hand" }) );
    set_weight(0);
    set_value(0);
}

int notify_spouse(string str)
{
    if(!find_living(spouse))
    {
        write(capitalize(spouse)+" is not around.\n");
        return 1;
    }
    tell_object(find_living(spouse), "Honey: "+str+"\n");
    write("You tell your spouse: "+str+"\n");
    return 1;
}

int jealous_action0(string str)
{
    if(!str) return 0;
    if(str != spouse) notify_jealous(0);
    return 0;
}

int jealous_action1(string str)
{
    if(!str) return 0;
    if(str != spouse) notify_jealous(1);
    return 0;
}

int jealous_action2(string str)
{
    if(!str) return 0;
    if(str != spouse) notify_jealous(2);
    return 0;
}

void notify_jealous(int arg)
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

void welcome()
{
    notify_spouse("I'm home.");
    set_long("A solid gold band.  There is an inscription on it.\n");
    call_out("wear", 2, "band");
}

int remove_ring(string str)
{
    if(str != "band") return 0;
    write("You may only remove your wedding band through divorce!\n");
    return 1;
}

string
extra_look()
{
    return (capitalize(me)+" is married to "+capitalize(spouse)+".\n");
}

int get()
{
    return 0;
}

int drop()
{
    return 1;
}

void add_jealous(int arg)
{
    jealous = jealous + arg;
    return;
}

int query_jealous()
{
    return jealous;
}

mixed *query_auto_load()
{
    return ({ "/std/obj/wed_ring", ({ me, spouse, jealous }) });
}

void init_arg(mixed *arg)
{

    me = arg[0];
    spouse = arg[1];
    jealous = arg[2];
    welcome();
    set("read", "From "+capitalize(spouse)+" with love.\n");

}

// Following lines added by Darkone 2/20/93
string query_spouse() { return spouse; }
string query_me() { return me; }

string short_fun() { return (capitalize(me)+"'s wedding band"); }
