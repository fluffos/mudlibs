#include <npc.h>
#include <city_name.h>
#include <generic_items.h>

string *route;
object drink;

void load_travel();

void
reset_monster()
{
    if (!present("newspaper",this_object()))
	move_object(clone_object(GENERIC_NEWSPAPER), this_object());
}

void
create_monster()
{
    set_name("mayor");
    set_short("The mayor");
    set_id(({ sprintf("mayor of %s", LCASE_CITY_NAME), "man" }));
    set_living_name("village_mayor");
    set_alignment(AL_GOOD);
    set_gender(G_MALE);
    set_level(19);
    set_wc(35);
    set_ac(20);
    set_hp(500);
    set_long(sprintf("He is the mayor of %s.", CITY_NAME));
    load_travel();
    set_spell_mess1("The mayor files some red tape.\nThere is a LOUD sigh from above.\n\
There is a big clap of thunder and a lightning almost strikes you from the sky.");
    set_spell_mess2("The mayor files some red tape.\nThere is a LOUD sigh from above.\n\
There is a big clap of thunder and a lightning hits you from the sky.");
    set_spell_dam(100);
    set_spell_chance(5);
    set_money(1000);
    call_out("start_travel",2);
}

void
start_travel()
{
    remove_call_out("start_travel");
    if (environment())
	if (strstr(object_name(environment()), "mayors_off") >= 0)
	    call_out("travel",1,0);
    return;
}

int
travel(int nr)
{
    string message,action,func;
    int time_to_next;
    //	remove_call_out("travel");
    sscanf(route[nr],"%d#%s#%s#%s",time_to_next, action, message, func);
    if (message && message!="")
	environment() -> tell_here(message + ".", this_object());
    if (action)
	init_command(action);
    if (func)
	call_other(this_object(), func);
    if (time_to_next)
	call_out("travel", time_to_next, nr + 1);
    else return 1;
}

void
load_travel()
{
    route = ({
      "3##The mayor folds the paper and puts it on the table#paper",
      "3#s##",
      "4###pinch",
      "6#e##","6#s##","6#s##","6#s##","6#s##",	// pub
      "1##Mayor looks thirsty#",
      "10###pub",
      "10#drink firebreather#",
      "3#ne##",
      "2###harry",
      "5#throw coin#Mayor makes a wish#",
      "6#ne##","6#e##",				// guild
      "10##Mayor studies the board#",
      "6#w##","6#w##","6#w##","6#nw##",		// post
      "7##Mayor reads his mail#",
      "6#se##","6#w##",				// shop
      "6#sell bottle##",
      "4#read plank##", 
      "6#e##","6#n##","6#w##","3#n##",		// mayor's office
      "0###get_paper"
    });
}

void
paper()
{
    object ob;
    if (ob = present("newspaper"))
	move_object(ob, environment());
    return;
}

void
get_paper()
{
    object ob;
    if (ob = present("newspaper",environment(this_object()))) {
	move_object(ob, this_object());
	environment() -> tell_here("Mayor picks up the newspaper.", this_object());
    }
    return;
}

void
pinch()
{
    if (present("secretary")) {
	environment() -> tell_here("The mayor pinches the secretary.\n\
Secretary giggles inanely.", this_object());
    }
    return;
}

void
pub()
{
    if (object_name(environment(this_object())) == "room/pub2") {
	init_command("buy firebreather");
	call_out("leave_pub", 4);
    }
    return;
}

void
leave_pub()
{
    remove_call_out("leave_pub");
    init_command("north");
    return;
}

void
harry()
{
    if (present("harry",environment())) 
	init_command("say Hi harry, nice to see you!");
}
