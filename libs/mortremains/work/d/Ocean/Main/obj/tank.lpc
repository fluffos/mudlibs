/*
** File: tank.c
** Purpose: this is used for underwater areas. to breathe.
** Credits: Herself took a flashlight and tweaked it. 8.7.00
** Special Thanx: To Cy for makin the danged thing work ;)
*/

#include <mudlib.h>
inherit OBJECT;

void
create()     
{
    set("author" , "herself");
    set ("short", "@@query_short");
    set ("long", "@@query_long");
    set("id" , ({"tank" , "oxygen" , "oxygen tank" , "valve" , "#REFLEXIVE_SPELL#"}) );
    set("value" , 250);
    set("mass" , 20);
    set ("fuel", 900);  // fuel is measured in seconds
}


void
init()
{
    add_action("open_valve" , "open");
    add_action("close_valve" , "close");
}

int
open_valve(string str)
{
    if(!id(str)) return 0;

    if(!query("fuel"))
    {
	notify_fail("Psssssss. The tank is empty.\n");
	return 0;
    }
    if(query("open"))
    {
	notify_fail("It is already open. \n");
	return 0;
    }
    set("open", 1);
    write("You open the oxygen valve. \n"+
      "You hear a hiss and start to breathe easier. \n");
    call_out("run_out" , query("fuel"));
    return 1;
}

int
close_valve(string str)
{
    if(!id(str)) return 0;
    if(!query("fuel"))
    {
	notify_fail("What's the point, it's cashed.\n");
	return 0;
    }
    write("You close the valve. \n");
    set("open" , 0);
    set("fuel" , remove_call_out("run_out"));
    return 1;
}

void
run_out()
{
    tell_object(environment(this_object()), "The hissing slows and stops.\n");
    set("value", 1);
    set("open", 0);
    set ("fuel", 0);
    set ("light", 0);
}

string
query_short()
{
    if(query("fuel"))
	return "an oxygen tank" + (query("open") ? " (open)" : "");
    return "an empty oxygen tank";
}


string
query_long()
{
    if(query("fuel"))
	return "It is used for breathing underwater.\n" +
	(query("open") ? "The valve is open.\nYou can 'close' it if you like.\n" :
	  "The valve is closed.\nYou can 'open' it if you like.\n");
    return "It used to contain oxygen.\n";
}
int reflex(int damage, string type, object ob) {
    string done;
    if((int)query("open")>0 && type=="suffocation") return 0;
    return damage;
}
