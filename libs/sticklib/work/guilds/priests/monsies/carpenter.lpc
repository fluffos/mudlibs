#include "priest_monster.h"

#define TH environment()->tell_here
#define TO this_object()
#define TP this_player()

void
create_monster()
{
    set_name("carpenter");
    set_id(({"guild carpenter","old man","man"}));
    set_short("A guild carpenter");
    set_long(
      "He is an old man who makes his living by making staffs for priests. These \
staffs are famous 'Staffs of Boccob'.");
    set_race("human");
    set_gender(G_MALE);
    set_guild(GN_PRIEST);
    set_level(15);
}


void
init_monster()
{
    if(IS_PRIEST(TP))
	add_action("order_cmd","order");
}


status order_cmd(string s)
{
    string a, b;

    notify_fail("Order what?\n");
    if(!s) return 0;
    s = lower_case(s);
    if(sscanf(s, "the %s", a)) s = a;
    if(sscanf(s, "%s from the %s", a, b) == 2) s = a + " from " + b;
    if(sscanf(s, "%s from %s", a, b) == 2)
	if(id(b)) s = a;
    if(s != "staff" && s!= "staff of boccob") return 0;
    TH(({":%<him.capname>% says something to %<me.name>%."}),
      ({LIV_CAN_HEAR}), 0, TP, TO, TP, 0);

    call_out("order2",2,this_player());
    return 1;
}


void order2(object who)
{
    int i;
    string str;

    str = ":";
    if(!who)
	str += "%<me.capname>% looks around looking confused!";
    else if(environment(who) != environment())
	str += "%<me.capname>% is about to answer %<him.name>%, but notices \
that %<him.pronoun>% is gone.";
    else if(STAFF_D -> staff_ordered(who))
	str += "%<me.capname>% says; But you have already ordered the staff, \
%<him.real_name>%!";
    else if(!STAFF_D -> ok_to_order(who))
	str += "%<me.capname>% says: Well, %<cap(him.real_name)>%, you have to \
beseech " + GOD_NAME + " to grant you the staff. Before that, I can't carve \
you a staff!";
    else {
	// Ok to make staff!

	str += "%<me.capname>% says: Very well, %<cap(him.real_name)>%! I will \
carve you the staff.\n";

	if(!(i = (int) STAFF_D -> make_staff(who))) 
	    str += "%<me.capname>% says: Since it's your first staff, it won't \
cost you anything.\n";
	else
	    str += "%<me.capname>% says: It will cost you " + i + " gold pieces.\n";

	str += "%<me.capname>% says: The staff will be ready " + 
	(string)STAFF_D->staff_ready(who) + ". Come then and ask me about it.\n";
    }
    TH(({str}), ({LIV_CAN_HEAR}),0,0,TO,who,0);
}


status catch_ask(object who, string what)
{
    string a, str;
    object x;
    int price;

    str = ":";
    if(what && sscanf(what, "the %s", a)) what = a;
    if(what != "staff" && what != "staff of boccob")
	str += "%<me.capname>% says: Well, I can't say anything about that, \
%<cap(him.real_name)>%... But maybe something about the staff?";
    else
	switch((int) STAFF_D -> staff_status(who)) {
    case 0:
	str += "%<me.capname>% says: You haven't ordered the staff, \
%<cap(him.real_name)>%!";
	break;

    case 1:
	str += "%<me.capname>% says: I haven't finished your staff yet, \
%<cap(him.real_name)>%. It should be ready " +
	(string) STAFF_D->staff_ready(who) + ". Come then, and ask again.";
	break;

    case 2:
	str += "%<me.capname>% says: Your staff is ready, \
%<cap(him.real_name)>%! ";

	if(price = STAFF_D->make_staff(who)) {
	    str += sprintf("It costs %d gold coins.", price);
	    if(who->query_money()<price) {
		str += "\n%<me.capname>% says: Ah, you don't have that much money \
with you. Come back when you do.";
		break;
	    }
	    who->add_money(-price);
	}
	else {
	    str += "Since it's your first one, it's free!";
	}
	STAFF_D->staff_got(who);
	x = (object) STAFF_D -> get_staff(who);
	if(transfer(x, who)) {
	    move_object(x, environment());
	    str += "\n%<me.capname>% gives the staff to %<him.name>%, but \
notices that %<him.name>% can't carry anything more, and leaves it on \
the floor.";
	} else {
	    str += "\n%<me.capname>% gives the staff to %<him.name>%.";
	}
    }
    TH(str,0,0,0,TO,who,0);
    return 1;
}
