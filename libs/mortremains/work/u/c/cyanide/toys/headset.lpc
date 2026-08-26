/*
** FILE: headset.c
** PURPOSE: Chat object for players
** CREDITS:
**    19 May 99  Cyanide wrote the file.
*/

#include <commands.h>
#include <messages.h>
#include "/u/c/cyanide/debug.h"

inherit ARMOR;

#define MAX_CHANNEL 13

int channel, power = 0;   


void create() {
    channel = random(MAX_CHANNEL) + 1;
    seteuid(getuid());

    set("short", "a wireless headset");
    set("long", "@@query_long" );
    set("short", "a wireless headset");
    set("id", ({ "*H_SET*", "headset", "wireless headset" }) );
    set_armor_type("clothing");
}


string query_long() {
    string long = "A simple headset that you can use to "+
    "communicate with your friends. If it is on and worn, "+
    "anything you say will be broadcast. A small label "+
    "on its back reads <hset help>\n";

    if (power) 
	long += "It is currently set to channel "+channel+".";
    else
	long += "It is off.";

    return wrap(long);
}


void init() {
    add_action("broadcast", "say");
    add_action("hset", "hset");
}


int query_power() { 
    if (query("equipped")) 
	return power; 
    else
	return 0;
}


int query_channel() { return channel; }


int broadcast(string str) {
    if (CMD_SAY->cmd_say(str)!=2) return 1;

    if (query_power()) {
	object *usrs=users(), hset;
	int x, sz;

	str = iwrap("]- "+TPN+" broadcasts: "+str);

	sz = sizeof(usrs);
	for (x=0; x<sz; x++) {
	    hset = present("*H_SET*", usrs[x]);
	    if (!hset  
	      || usrs[x]==TP
	      || (channel != hset->query_channel())
	      || !hset->query_power() 
	    )
		continue;

	    message(MSG_SAY, str, ({ usrs[x] }) );
	}
    }

    return 1;
}         

string help() {
    string help = (@EndText
            -=-=-=-=-=-=-=-=-=-
                Fisher Price
              My First Headset
            -=-=-=-=-=-=-=-=-=-

        hset on   -  Turns unit on
        hset off  -  Turns unit off
hset channel <#>  -  Turns unit to channel #

In order to use this item, it must be worn! To broadcast,
simply speak.

Enjoy!
EndText
    );

    return help;
}

int hset (string str) {
    int num;

    if (!str) {
	write("You may want to read the label, first.\n");
	return 1;
    }

    switch( lower_case((explode(str, " "))[0]) ) {  
    case "on" :
	if (power) {
	    write("It is already on.\n");
	} else {
	    power = 1;
	    say(TPN+" turns "+POSS+" headset on.\n");
	    write("You turn your headset on.\n");
	}
	break;

    case "off" :
	if (!power) {
	    write("It is already off.\n");
	} else {
	    power = 0;
	    say(TPN+" turns "+POSS+" headset off.\n");
	    write("You turn your headset off.\n");
	} 
	break;

    case "channel" :
	if (sscanf(str, "%s %d", str, num)!=2) {
	    write("Usage: hset channel [1.."+
	      MAX_CHANNEL+"]\n");
	    return 1;
	}
	if (num<1 || num>MAX_CHANNEL) {
	    write("The channels go from 1 to "+
	      MAX_CHANNEL+".\n");
	    return 1;
	}

	write("You set the channel to "+num+"\n");
	say(TPN+" fiddles with "+POSS+" headset.\n");
	channel = num;
	break;

	case "help":
	write(help());
	break;

	default : write(wrap("That is not an option. Type 'hset "+
	  "help' for more information.") );
    }

    return 1;
}


/* EOF */
