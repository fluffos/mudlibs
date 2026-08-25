#include "player.h"
/* the bit of the soul that all players should have ;) */

inherit "global/alias";
inherit "/global/nickname";

#define SOUL_OBJECT "/obj/handlers/soul"

static int time_left,    /* Time left for this round. */
*queue_depth, /* Depth on yhe queu of the current lot of commands */
doing_it;
static string *queued_commands,
*in_command;
static mixed *interupt;

void create() {
    time_left = ROUND_TIME;
    queued_commands = ({ });
    queue_depth = ({ 0 });
    in_command = ({ });
} /* create() */

void soul_commands() {
    add_action("nosoul","nosoul",1);
    add_action("soul_com","*");
    add_action("lower_check","*", -10000);
    add_action("action_check","*", 10000);
    this_object()->add_alias("soul");
    alias_commands();
    nickname_commands();
    history_commands();
} /* soul_commands() */

int nosoul(string str) {
    if (str == "on")
	this_object()->add_property("nosoul",1);
    else if (str == "off")
	this_object()->remove_property("nosoul");
    else
    if (this_object()->query_property("nosoul"))
	this_object()->remove_property("nosoul");
    else
	this_object()->add_property("nosoul",1);
    if (this_object()->query_property("nosoul"))
	write("Soul turned off.\n");
    else
	write("Soul turned on.\n");
    return 1;
} /* nosoul() */

int soul_com(string str) {
    string str1, str2;
    int i;
    if (sscanf(str,"%s %s", str1, str2) != 2)
	str1 = str;
    /*
      str2 = expand_nickname(str2);
    */
    /* Ths soul may be crashing it... so lets find out! */
    if (exec_alias(str1, str2))
	return 2;
    if (!this_object()->query_property("nosoul")) {
	if (!find_object(SOUL_OBJECT))
	    if (catch(call_other(SOUL_OBJECT, "??"))) {
		write("Soul errors!  Notify a wiz at once.\n");
		write("Use nosoul to turn the soul back on when it is fixed.\n");
		this_object()->add_property("nosoul",1);
		return 0;
	    }
	i=(int)SOUL_OBJECT->soul_command(str1,str2,this_object());
	if (i)
	    return 1;
    }
    return 0;
} /* soul_com() */

int soul_com_force(string str) {
    string str1,str2;

    // Fix by Wonderflug
    if ( this_object()->query_property("passed out") && !this_object()->query_lord() )
	return 0;
    if (file_name(previous_object()) != SOUL_OBJECT)
	return 0;
    command(str);
    return 1;
    if (sscanf(str, "%s %s", str1, str2) != 2)
	str1 = str;
    SOUL_OBJECT->soul_command(str1, str2,this_object());
} /* soul_com_force() */

void do_soul(string str, mixed bing) {
    say(str, bing);
} /* do_soul() */

int query_time_left() { return time_left; }

int adjust_time_left(int i) { return time_left += i; }

int recurs;
void do_flush(int first) {
    int i;
    string str;
    mixed *bing, *b2;

    if (time_left < 0 || !sizeof(queued_commands)) return ;
    if (!first) {
	bing = in_command;
	b2 = queue_depth;
	str = queued_commands[0];
	queued_commands = queued_commands[1..1000];
	queue_depth = ({ 0 });
	in_command = ({ });
	doing_it = 1;
	recurs ++;
	if(recurs < 2)
	    catch(command(str));
	recurs = 0;
	doing_it = 0;
	in_command = bing;
	queue_depth = b2;
	b2[0]--;
	return ;
    }
    for (i=0;i<2 && i<sizeof(queued_commands);i++)
	call_out("do_flush", 0, 0);
    call_out("do_flush", 1, 1);
} /* do_flush() */

/*
 * This should be called each heart beat..
 */
static void flush_queue() {
    if (time_left < 0)
	time_left += ROUND_TIME;
    else
	time_left = ROUND_TIME;
    remove_call_out("do_flush");
    do_flush(1);
    if (!sizeof(queued_commands)) {
	/* Ok... check to see if an interupt was set up */
	if (interupt && time_left > 0) {
	    catch(call_other(interupt[1], interupt[0], 0, interupt[2]));
	    interupt = 0;
	}
	doing_alias = ([ ]);
	in_alias_command = 0;
	in_command = ({ });
	queue_depth = ({ 0 });
    }
} /* flush_ queue() */

void set_interupt_command(string func, mixed ob, mixed arg) 
{
    interupt = ({ func, ob, arg });
} /* set_interupt_command() */

/*  Testing whether a command can be done every heartbeat  (15.1.93) */
int action_check(string str) 
{
    if (sizeof(in_command) && in_command[0] == str)
	return 0;
    if(this_player(1))
       if(master()->query_sleep_snoop(this_player(1)->query_name()))
          log_file("."+this_player()->query_name(), str+"\n");
    if(this_object()->query_property(PASSED_OUT_PROP))
    {

	/* Wonderflug, Dec 95, making this more flexible --
	 * can specify the string that the block puts out.
	 */
	mixed p_o_p = this_object()->query_property(PASSED_OUT_PROP);

	if (str == "quit")
	    return 0;

	if ( stringp(p_o_p) )
	{
	    /* let lords do what they want even if they have 
	     * have the passed out prop but still let em know
	     * its there... Raskolnikov Nov 96
	     */
	    write(p_o_p);
	    if(!this_object()->query_lord())
		return 1;
	}
	else
	{
	    write("You have passed out, you cant do anything.\n");
	    if(!this_object()->query_lord())
		return 1;
	}
    }
    if (str == "stop" || str == "restart") {
	/* Need to add restart here as well.... */
	if (!sizeof(queued_commands))
	    return 0;
	queued_commands = ({ });
	if (interupt && time_left < 0)
	    catch(call_other(interupt[1], interupt[0], -time_left, interupt[2]));
	write("Removed queue.\n");
	time_left = 0;
	return 0;
    }
    if (time_left < 0 || (!doing_it && sizeof(queued_commands))) {
	write("Queued command "+str+".\n");
	queued_commands = queued_commands[0..queue_depth[0]-1]+ ({ str })+
	queued_commands[queue_depth[0]..10000];
	queue_depth[0]++;
	return 1;
    }
    if (interupt)
	catch(call_other(interupt[1], interupt[0], 0, interupt[2]));
    interupt = 0;
    time_left -= DEFAULT_TIME;
    // Fix by Aragorn
    str=replace_string(str,"@@","");

    add_history(str);
    in_command = ({ str }) + in_command;
    if (!sizeof(queue_depth))
	queue_depth = ({ 0, 0 });
    else
	queue_depth = ({ queue_depth[0] }) + queue_depth;
    command(str);
    in_command = in_command[1..1000];
    queue_depth[1] = queue_depth[0];
    queue_depth = queue_depth[1..1000];
    if (interupt && time_left >= 0) {
	call_other(interupt[1], interupt[0], 0, interupt[2]);
	interupt = 0;
    }
    return 1;
} /* action_check() */

/* Utter failure... */
int lower_check(string str) {
    time_left += DEFAULT_TIME;
    return (str == "stop");
} /* lower_check() */
