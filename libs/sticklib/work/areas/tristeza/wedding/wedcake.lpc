/* This is a wedding cake (coded especially for Dracula & Angora).
	After the wedding cake has been cut by either the bride or
	the groom, guests can then take and enjoy a piece.
					- Minx Sept. 7, 1995
*/

#include <treasure.h>
#include <areas.h>

int short;

void
create_treasure(){

    string *long_descrip, *short_descrip;

    short_descrip=({"a beautiful four tier wedding cake",
      "a beautiful wedding cake cut into several generous pieces"});
    set_short(capitalize(short_descrip[short]));
    set_long("This breath taking four tier wedding cake \
was baked and decorated by Minx. The white fluffy frosting sparkles \
in the light. Tiny pink frosting roses cascade from the top tier to \
the bottom in a swirling blossom waterfall.");

    set_id(({"wedding cake"}));
    set_weight(100000000);
    set_value(0);

}

void
init_treasure(){
    add_action("cut_cmd","cut");
    add_action("get_command","get");
}


cut_cmd(string what){
    object here;
    string who;

    if (what != "cake") {
	this_player()->tell_me("Cut what?");
	return 1;
    }

    who = (string)this_player()->query_real_name();
    if (who == "minx" || who == "minxster"){

	short = 1;
	this_player()->tell_me("You skillfully cut part of \
the cake into several pieces for your guests to enjoy.");

	here=environment(this_object());		
	here->tell_here(
	  capitalize(who)+" cuts part of the cake into \
several pieces and invites you to get a piece to enjoy.",this_player());

    } else {

	this_player()->tell_me("Only Minx can cut \
the wedding cake.");

    }
    return 1;
}


get_command(string what){
    object here, cake;

    if (what != "cake" && what != "piece") return 0;

    if (short == 0){
	this_player()->tell_me("You can't take any cake until \
it has been cut.");
	return 1;
    }

    cake = clone_object(AREA_TRISTEZA "wedding/cake");
    move_object(cake,this_player());
    this_player()->tell_me("You take a huge piece of the \
gorgeous wedding cake.");
    here=environment(this_player());		
    here->tell_here(
      (string)this_player()->query_name()+" takes a huge piece of the gorgeous \
wedding cake.",this_player());

    return 1;
}


