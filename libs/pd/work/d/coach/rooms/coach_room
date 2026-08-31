#include <std.h>
#include <coach.h>
inherit ROOM;

string loc;
string *dests;
string *todests;
string largestring;
string coachout;
string nomoney;
int cost;
int departed;

void init() 

{
    ::init();
    add_action("coach", "coach");

}

int coach(string str)
{
    int totalcost;
    int i;
    object mob=present("dwarf");
    object transroom=new(ROOMS"transroom.c");

    if(!str || str == " to" || str == " to " || str == "to" || str == "to ") { 
	write("Coach to where?");
	return 1;
    }
    if(str == "to "+loc)
    {
	mob->force_me("say Aye, you're already here!");
	return 1;
    }
    if(member_array(str,todests) == -1)
    {
	write("Coach to where? The sign will show valid destinations.");
	return 1;
    }
    else
    {
	i = member_array(str,todests);
    }
    if (this_player()->query_level() < 11)
    {
	cost = 0;
    }
    else if (this_player()->query_level() > 10 && this_player()->query_level() < 20)
    {
	cost = 100;
    }
    else if (this_player()->query_level() > 20 && this_player()->query_level() < 50)
    {
	cost = 1000;
    }
    else if (this_player()->query_level() > 50)
    {
	cost = 2000;
    }

    totalcost = cost;

    if (this_player()->query_money("gold") < totalcost)
    {
	mob->force_me("say "+nomoney);
	return 1;
    }
    else
    {
	if (departed != 1)
	{
	    this_player()->add_money("gold", -totalcost);
	    if (this_player()->query_race() == "dragon" || this_player()->query_race() == "ogre" || this_player()->query_race() == "giant" || this_player()->query_race() == "centaur" || this_player()->query_race() == "raknid" || this_player()->query_race() == "minotaur" || this_player()->query_race() == "sauran")
	    {
		mob->force_me("emote "+largestring);
	    }
	    mob->force_me("say All aboard!");
	    this_player()->add_money("gold", -totalcost);
	    this_player()->move(transroom);
	    transroom->start_fmv(dests[i]);
	    departed = 1;
	    call_out("arrive",40);
	    return 1;
	}
	else
	{
	    mob->force_me("emote holds up "+mob->query_possessive()+" hand.");
	    mob->force_me("say "+coachout);
	    return 1;
	}
    }
}

int arrive()

{
    departed = 0;
}
