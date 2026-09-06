
/*********************************************************
 name:    bountyshop.c

 PURPOSE: Give players a chance to do some bounty hunting.

 AUTHOR:  Tron
 *********************************************************/

#include <room.h>
#include "../DEFS.h"
#define SAVE AREA_TRISTEZA "bounty/bounty_save"

mapping wanted; // ([ "player": ({gold, msg}), ... ])

#define MONEY  0
#define CRIMES 1

nomask status
query_prevent_shadow() { return 1; }

nomask void
create_room() {

    set_short("The bounty hunters' job management office");
    set_long("You are standing in a round room with posters on the "+
      "walls. There is a large sign on the wall just above a "+
      "small barred window. There is a fat, dull looking man "+
      "peering at you from behind the bars.");

    add_item("posters", "Those are large black and white posters with "+
      "writing and drawings. \"WANTED\", say the large headlines.");

    add_item("sign", "The sign says: Bounty Hunters' Job Management. "+
      "Check the list for wanted criminals and bring their "+
      "bodies here as a proof of your excellent work for our "+
      "community. You also can bring your gold for bounty. "+
      "('protocol' to view shop protocol).");

    add_item("window", "A small round window with steel bars.");
    add_item("man", "He seems to be somekind of cashier.");
    add_item("hatch", "It's a round metal hatch in the floor.");

    add_exit("west", CITY_DIR+"S4_5");

    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_INDOORS);
    set(IN_CITY);

    wanted = ([]);
    restore_object(SAVE);

    add_command("protocol", "protocol");
    add_command("check", "check");
    add_command("bounty", "bounty");
    add_command("show", "show");
    add_command("crime", "crime");
}

nomask void
init_room()
{
    if(((int)this_player()->query_coder_level() >= 300) &&
      interactive(this_player())) add_action("remove", "bremove");
}

nomask status
protocol() {

    this_player() -> tell_me("PROTOCOL: The Bounty Shop (Ltd.) gets "+
      "10% of the bounty. For this reason we have to confirm, that "+
      "the corpse you bring in, really is the wanted criminal. We "+
      "also want to ensure there is no money laundry done in our "+
      "honest and legal shop. Thus, we can only reward a person "+
      "who killed the wanted criminal. Mr. Bounty.");

    write("\n");
    write("Commands: check list [<#from> <#lines>]\n"+
      "          -Show the list of criminals. The last argument pair is\n"+
      "          -optional. <#from> = line number on the list, <#lines> =\n"+
      "          -amount of lines. (view only part of the list)\n\n"+
      "          check <criminal>\n"+
      "          -Show more information about given criminal.\n\n"+
      "          bounty <criminal> <#gold>\n"+
      "          -Set/add bounty for the criminal ON the list.\n\n"+
      "          crime <criminal> <message>\n"+
      "          -Add message to criminal's record. If given criminal is\n"+
      "          -not on the list, new criminal is added to it.\n\n"+
      "          show corpse\n"+
      "          -Claim your reward.\n");

    return 1;
}

nomask status
remove(string s) {

    if(!interactive(this_player()) || previous_object() != this_player()
      || (int)this_player()->query_coder_level() < 300) return 0;

    if(!s) return 0;

    if(!wanted || !sizeof(wanted)) {
	write("No Criminals to Remove!\n");
	return 1;
    }

    wanted = m_delete(wanted, s);
    save_object(SAVE);

    write("Ok.\n");
    return 1;
}

nomask status
check(string s) {
    int i, a;
    mixed *plr;
    mixed *data;
    mixed onedata;
    int from, amount;
    string arg;

    if(!s) return 0;
    if(sscanf(s, "%s %d %d", arg, from, amount) == 3) s = arg;
    else {
	from = 1;
	if(wanted) amount = (sizeof(wanted));
    } 

    if(from <= 0) from = 1;
    if(amount < 1) amount = from = 1;

    s = lower_case(s);

    if(s == "list" || s == "the list") {
	write("Check list [#ln #lns]:  This list.\n"+
	  "Check <criminal>:       Info about the criminal.\n"+
	  "Crime <criminal> <msg>: Set/add information about crimes.\n"+
	  "                        - Sets new criminal on the list.\n"+
	  "Bounty <criminal> <gc>: Set/add bounty for a person.\n"+
	  "Show corpse:            Claim your reward.\n");
	write("------------------------------------------------------------\n");
	if(!wanted || !(a = sizeof(wanted)))
	    write("No criminals this time, bummer! Come back later.\n");
	else {

	    plr = m_indices(wanted);
	    data = m_values(wanted);

	    if(( from + amount - 1 ) > a) {
		amount = a - from + 1;
		if(amount <= 0) { from = a; amount = 1; }
	    }
	    printf("%-3s) %-15s %s\n\n", "#", "Criminal", "Bounty (gc)");
	    a = from + amount - 1;
	    for(i=from-1; i<a; i++)
		printf("%-3d) %-15s %d\n", i+1, capitalize(plr[i]), 
		  data[i][MONEY]);
	}
    } else {
	if(!wanted || !sizeof(wanted)) {
	    write("There are no criminals on the list.\n");
	    return 1;
	}
	if(onedata = wanted[s]) {

	    write("Name: "+capitalize(s)+"\n"+
	      "Bounty: "+onedata[MONEY]+" gc\n"+
	      "Crime(s): \n\n");
	    this_player()->tell_me(onedata[CRIMES]);

	} else write("No such criminal on the list.\n");
    }

    return 1;
}

nomask status
bounty(string s) {
    int bounty;
    string plr;
    mixed data;

    if(!s) return 0;


    if((int)this_player()->query_coder_level())
	if((int)this_player()->query_coder_level() < 300 || 
	  !interactive(this_player()) ) {
	    write("You are not allowed to do this.\n");
	    return 1;
	}
    if(sscanf(s, "%s %d", plr, bounty)!=2) {
	notify_fail("bounty <player> <money>\n");
	return 0;
    }

    if(!wanted || !sizeof(wanted)) {
	write("No criminals on the list.\n");
	return 1;
    }

    plr = lower_case(plr);

    if(!(data = wanted[plr])) {
	write("No such criminal on the list.\n");
	return 1;
    }

    if(bounty < 1) {
	write("The fat man says: You must be drunk or stupid.\n");
	return 1;
    }


    if((int)this_player()->query_money() >= bounty) {
	data[MONEY] += bounty;
	wanted[plr][MONEY] = data[MONEY];
	this_player()->add_money(-bounty);
	write("You donate your money for a good cause.\n");
	say(this_player()->query_name()+" donates bounty money.\n");
	save_object(SAVE);
    }
    else {
	write("You don't have that kind of money.\n");
	return 1;
    }

    return 1;
}

nomask status
crime(string s) {
    string plr;
    string msg;
    mixed *data;
    mixed *msgs;

    if(!s) return 0;

    if(sscanf(s,"%s %s", plr, msg)!=2) {
	notify_fail("crime <player> <message>\n");
	return 0;
    }

    plr = lower_case(plr);

    if(!wanted || !sizeof(wanted) || !(data = wanted[plr])) {
	if(!("/secure/master_amy"->exists_player(lower_case(plr)))) {
	    write("The fat man says: Never heard of this person, sorry.\n");
	    return 1;
	}
	else {
	    if(!wanted) wanted = ([]);
	    wanted += ([plr : ({0, msg+"\n"}) ]);
	    write("The fat man says: Aaaah, a new criminal.\n");
	}
    }
    else {
	msgs = explode(data[CRIMES], "\n");
	if(sizeof(msgs) > 5) {
	    msgs = ({msg}) + msgs[0..sizeof(msgs)-2];
	    msgs[sizeof(msgs)-1] = "Etc. etc....you name it.";
	}
	else msgs = ({msg}) + msgs;
	wanted[plr][CRIMES] = implode(msgs, "\n");
    }

    write("The fat man says: Ok, I'll put it on the list.\n");
    save_object(SAVE);

    return 1;
}

nomask status
show(string s) {
    object corpse;
    string name;
    object killer;
    mixed  data;
    int money;

    if(!s || s!="corpse") return 0;

    corpse = present("corpse", this_player());
    if(!corpse) {
	write("You have no corpse.\n");
	return 1;
    }

    if(corpse->query_was_player()) {
	name = (string)corpse->query_orig_name();
	name = lower_case(name);
	killer = (object)corpse->query_killer();

	if(wanted && (data=wanted[name])) {
	    if((string)this_player()->query_real_name() == name) {
		write("The fat man says: Haaaahhhaa...is that your "+
		  "twin or something?\n");
		return 1;
	    }

	    write("The fat man says: Great!!!\n");

	    money = (data[MONEY] * 9)/10; // 90%
	    if(!money) money = data[MONEY]; //small money

	    write("The fat man gives you "+money+" gc.\n");

	    this_player()->add_money(money);
	    write("The fat man says: 10% goes for the house.\n");

	    command("drop corpse", this_player());
	    write("You drop the corpse down, happy as a pumpkin.\n");
	    destruct(corpse);
	    say(this_player()->query_name()+" just delivered "+
	      "the body of "+ capitalize(name) +".\n");

	    tell_room(this_object(), "The corpse drops down through the "+
	      "open hatch in the floor. The hatch closes.\n");

	    wanted = m_delete(wanted, name);
	    save_object(SAVE);
	} 
	else {
	    write("The fat man says: Sorry, no bounty for"+
	      " this one...not on the list.\n");
	    return 1;
	}                      
    } 
    else {
	write("The fat man says: Well, it's a fine corpse "+
	  "but not the kind we pay you for.\n");
	return 1;
    }

    return 1;   
}
