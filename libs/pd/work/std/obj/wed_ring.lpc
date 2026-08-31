//      /obj/wed_ring.c
//      from the Nightmare mudlib
//      a wedding ring for the married ones of the mud
//      created by Descartes of Borg august 1992

#include <std.h>
#include <daemons.h>

inherit ARMOUR;

string short_fun();
string extra_look();

string me, spouse;
int jealous;
int notify_jealous(int arg);
int set_spouse(string str) { spouse = str; }

int set_me(string str) { me = str; }

int init()
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
    set_id( ({ "ring", "wedding ring", "band", "wedding band" }) );
    set_name("ring");
    set_short( (: short_fun() :) );
    set_long( (: extra_look() :) );
    set_ac(1);
    set_type("ring");
    set_limbs( ({ "left hand" }) );
    set_weight(1);
    set_value(10000);
    if(query_verb() != "marry" && this_player()->query_current_marriage()) {
	set_spouse(this_player()->query_current_marriage()[0]);
	set_me(this_player()->query_name());
    }
    set_heart_beat(1);
}

int notify_spouse(string str)
{
    if(!find_living(spouse))
    {
	write(capitalize(spouse)+" is not around.");
	return 1;
    }

    if(!str) {
	tell_object(find_living(spouse) , "%^BOLD%^%^RED%^<"+capitalize(this_player()->query_name())+" is thinking about you>%^RESET%^");
	tell_object(this_player(), "%^BOLD%^%^RED%^<You let your spouse know you're thinking about them>%^RESET%^");
	return 1;
    }

    message("info", "%^BOLD%^%^RED%^"+this_player()->query_cap_name()+" <honey> %^RESET%^"+str, ({this_player(), find_living(spouse)}) );
    LAST_D->add_honeyline((string)this_player()->query_name(), this_player()->query_cap_name()+" <honey> "+str);
    LAST_D->add_honeyline(find_living(spouse)->query_name(), this_player()->query_cap_name()+" <honey> "+str);


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

int notify_jealous(int arg)
{
    object zip;

    if(!find_living(spouse)) return 0;
    if(!arg) tell_object(find_living(spouse), "You are feeling a little jealous.");
    else if(arg == 1) tell_object(find_living(spouse), "You feel jealous.");
    else tell_object(find_living(spouse), "You feel very jealous.");
    if(zip = present("night_wed_ring", find_player(spouse)))
	zip->add_jealous(arg);
    return 0;
}

int welcome()
{
    notify_spouse("I'm home.");
    set_long("A solid gold ring.  There is an inscription on it.");
    call_out("wear", 2, "ring");
}

int remove_ring(string str)
{
    if(str != "ring") return 0;
    write("You may only remove your wedding ring through divorce!");
    return 1;
}

string
extra_look()
{
    return (capitalize(me)+" is married to "+capitalize(spouse)+".
");
}
/*
get()
{
    return 0;
}
*/
int drop()
{
    return 1;
}

int add_jealous(int arg)
{
    jealous = jealous + arg;
    return 0;
}

int query_jealous()
{
    return jealous;
}

int query_auto_load()
{
    return 1;
}

int init_arg(mixed *arg)
{

    //    me = arg[0];
    //    spouse = arg[1];
    //    jealous = arg[2];
    welcome();
    set("read", "From "+capitalize(spouse)+" with love.");

}


// Following lines added by Darkone 2/20/93
string query_spouse() { return spouse; }
string query_me() { return me; }

string short_fun() { return (capitalize(me)+"'s wedding ring"); }
//      /obj/wed_ring.c
//      from the Nightmare mudlib
//      a wedding ring for the married ones of the mud
//      created by Descartes of Borg august 1992

void heart_beat()
{
    if (!spouse) {
	this_object()->remove();
    }
}
