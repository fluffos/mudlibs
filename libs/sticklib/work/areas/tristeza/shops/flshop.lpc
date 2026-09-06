/* flshop.c */
/* Oletko halunnut olla kukkakauppias? */

#include <room.h>
#include <areas.h>
#include <generic_items.h>
#include <generic_npcs.h>

void
create_room()
{
    set_light_level(LT_LIGHTS);
    set(ROOM_WD, WD_INDOORS);
    set_short("The New Flower Shop");
    set_long(
      "You are in the New Flower Shop. The exit can be seen to\
 northwest.\
 Here you can order a delivery of flowers to any player in game,\
 just type 'deliver <colour> <flower> to <name>', where <colour>\
 is the colour of the flowers, <flower> is the type of flowers\
 and <name> is player to deliver those beautiful flowers to.\
\nExample: 'deliver white roses to Izchak'.\
\n\nCurrently we have: orchids (200 gp), roses (150 gp), tulips (120 gp),\
 lilies (100 gp) and poppies (80 gp).\n\n\
We have at least white-, green-, black-, yellow-, \
violet-, purple- and red-coloured flowers of\
 each type.\n ");
    set_exits(([ "northwest" : AREA_TRISTEZA+"virtual/S8_8" ]));
    set(NO_PK);
    set(IN_CITY);

    add_command("deliver", "deliver");
}

object delman,target,bunch;
string tname,type;
string flnam,flcol,flcard;
int flval,delval;

status
deliver(string str)
{
    string dummy;
    if(!str) return 0;

    if(sscanf(str,"%s %s %s %s",flcol,type,tname,dummy) != 3)
	if(sscanf(str,"%s %s to %s",flcol,type,tname) != 3)
	{
	    this_player()->tell_me("Try 'deliver <colour> <flower> to <name>'.");
	    return 1;
	}

    if(type == "orchid" || type == "orchids") {
	flnam = "orchids"; flval = 125; delval = 200; }
    if(type == "rose" || type == "roses") {
	flnam = "roses"; flval = 75; delval = 150; }
    if(type == "tulips" || type == "tulip") {
	flnam = "tulips"; flval = 55; delval = 120; }
    if(type == "lilies" || type == "lily") {
	flnam = "lilies"; flval = 45; delval = 100; }
    if(type == "poppies" || type == "poppy") {
	flnam = "poppies"; flval = 35; delval = 80; }
    if(delval == 0) {
	this_player()->tell_me("Sorry, but we don't have '" + type + "'.");
	return 1;
    }

    if (member(({ "red", "white", "black",
	  "yellow", "purple", "green",
	  "violet" }), flcol) == -1)
    {
	this_player()->tell_me("Sorry, but "+flcol+"-coloured "+flnam+
	  " are out of stock.");
	return 1;
    }

    target = find_player(tname);
    if(!target) {
	this_player()->tell_me("No one named "+tname+" found.");
	return 1;
    }

    if((string)this_player()->query_real_name() == "guest") {
	this_player()->tell_me("Sorry, but Guests can't deliver flowers. Log in a real "+
	  "character.");
	return 1;
    }

    if(this_player()->query_money() < delval) {
	this_player()->tell_me("Sorry, but you don't have enough money.");
	return 1;
    }
    this_player()->tell_me("Ok.");
    this_player()->tell_me("What do you want to write on the card?" +
      "Type one line of text (just hit CR for a standard card)");
    input_to("deliver2");
    return 1;
}

status
deliver2(string str) {
    tell_here(this_player()->query_name() + " sends flowers to " +
      target->query_name() + ".\n");
    call_other(this_player(), "add_money", - delval);
    bunch = clone_object(GENERIC_FLOWERS);
    if(str == "") {
	bunch->set_cardtext("With love,");
	str = "(Standard message.)";
    }
    else bunch->set_cardtext(str);

    bunch->set_sender(this_player()->query_name());
    bunch->set_flowers(flnam);
    bunch->set_colour(flcol);
    bunch->set_value(flval);
    delman = clone_object(GENERIC_NPC_FLOWER_MAN);
    move_object(delman,this_object());
    delman->set_sender(this_player());
    delman->set_sender_name(this_player()->query_name());
    delman->set_target_name(target->query_name());
    delman->set_who(target);
    delman->set_flowers(bunch);
    move_object(bunch,delman);

    log_file("FLOWER",(string)this_player()->query_real_name()+" sent flowers to "
      +(string)target->query_real_name()+" at "+ctime(time())+"\n");

    return 1;
}
