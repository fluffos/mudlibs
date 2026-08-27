/*
 * This is an example of leftovers code . Please read the file
 * /doc/man/objects/leftovers for further explanations.
 */
inherit "/std/leftover";

#define BS(message)	break_string(message, 75)
#define TP 		this_player()
#define TO 		this_object()

void
create_leftover()
{
    set_name(({"heart", "bugbear heart"}));
    set_long("A grisly example of the influence of late-night movies.\n");
    set_decay_time(30);
    set_amount(1500);
}

void
init()
{
    add_action("cpr_it", "cpr");
    ::init();
}

int
cpr_it(string str)
{
    if (str != query_organ())
	return 0;

    write(BS("Pushing all reason and sense overboard you engage in an energetic display of the correct procedure of cardio-pulmonery resuscitation. Less the body, but... you can't have everthing, can you?\n"));

    call_out("beat", 3, 10);

    return 1;
}

void
beat(int time)
{
    if (time--)
	call_out("beat", 1, time);

    write("The heart beats!\n");
    say("Ba-dum\n");
}
