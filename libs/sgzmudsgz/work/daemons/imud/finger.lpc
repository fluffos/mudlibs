/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** finger.c -- intermud finger
**
** 95-May-15.  Deathblade.  Created.
*/

#include <daemons.h>

inherit CLASS_FINGER;

void send_to_mud(string type, string mudname, mixed * message);
void send_to_user(string type, string mudname, string username,
		  mixed * message);
void return_error(string mudname, string username,
		  string errcode, string errmsg);
string canon_mudname(string mudname);

nomask void do_finger(string mudname, string username)
{
    send_to_mud("finger-req", canon_mudname(mudname), ({ lower_case(username) }));
}

protected nomask void rcv_finger_req(string orig_mud, string orig_user,
				  string targ_user, mixed * message)
{
    class finger info;

    info = FINGER_D->get_finger_data(message[0]);
    if ( !info )
    {
	return_error(orig_mud, orig_user, "unk-user",
		     sprintf("没有「%s」这个玩家", message[0]));
    }
    else
    {
	mixed * packet = ({
	    info->visname,
	    info->title,
	    info->real_name,
	    info->email,
	    info->last_login ? ctime(info->last_login) : 0,
	    info->idle,
	    info->connect_from,
	    info->level,
	    info->plan,
	});
	send_to_user("finger-reply", orig_mud, orig_user, packet);
    }
}

protected nomask void rcv_finger_reply(string orig_mud, string orig_user,
				    string targ_user, mixed * message)
{
    object p;

    p = find_body(targ_user);
    if ( !p )
    {
	return_error(orig_mud, orig_user, "unk-user",
		     sprintf("转回给不知名玩家「%s」",
			     targ_user));
    }
    else
    {
	string s;

	/* NOTE: we're munging the input packet... oh well :-) */
        if (sizeof(message) < 9) message += allocate(9 - sizeof(message));
	if ( message[1] == "" ) message[1] = 0;
	if ( message[2] == "" ) message[2] = 0;
	if ( message[3] == "" ) message[3] = 0;
	if ( message[4] == "" ) message[4] = 0;
	if ( message[5] == "" ) message[5] = 0;
	if ( message[6] == "" ) message[6] = 0;
	if ( message[7] == "" ) message[7] = 0;
	if ( message[8] == "" ) message[8] = 0;

	if ( message[2] )
	    s = sprintf("\n名字:  %-35s真实姓名: %s\n",
			message[0], message[2]);
	else
	    s = sprintf("\n:名字:  %s\n", message[0]);
	if ( message[3] )
	    s += sprintf("%' '42sEmail: %s\n", "", message[3]);
	s += sprintf("等级: %-35s头衔: %s\n",
		     message[7] ? message[7] : "<unknown>",
		     message[1] ? message[1] : "<unknown>");
	if ( message[5] == -1 )
	{
	    if ( message[4] && message[6] )
	    {
		s += sprintf("上次连线时间：%s，来自：%s\n", message[4], message[6]);
	    }
	    else if ( message[4] )
	    {
		s += sprintf("上次连线时间：%s\n", message[4]);
	    }
	    else if ( message[6] )
	    {
		s += sprintf("上次连线来自：%s\n", message[6]);
	    }
	    else
	    {
		s += "不在线上。\n";
	    }
	}
	else
	{
	    string idle;

	    if ( message[5] > 3600 )
		idle = (message[5]/3600) + "h";
	    else if ( message[5] > 60 )
		idle = (message[5]/60) + "m";
	    else if ( message[5] )
		idle = message[5] + "s";
	    if ( idle )
		idle = " (idle " + idle + ")";
    else idle = "";

	    if ( message[4] && message[6] )
		s += sprintf("上线时间：%s%s，来自：%s\n",
			     message[4], idle, message[6]);
	    else if ( message[4] )
		s += sprintf("上线时间：%s%s\n", message[4], idle);
	    else if ( message[6] )
		s += sprintf("来自：%s%s\n", message[6], idle);
	}

	if ( message[8] )
	    s += message[8];

	tell(p, s);
    }
}
