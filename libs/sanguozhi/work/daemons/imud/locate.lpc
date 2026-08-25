/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** locate.c -- intermud user locating
**
** 95-May-15.  Deathblade.  Created.
*/

void send_to_all(string type, mixed * message);
void send_to_user(string type, string mudname, string username,
		  mixed * message);
void return_error(string mudname, string username,
		  string errcode, string errmsg);

nomask void do_locate(string username)
{
    send_to_all("locate-req", ({ lower_case(username) }));
}

protected nomask void rcv_locate_req(string orig_mud, string orig_user,
				  string targ_user, mixed * message)
{
    object p;

    p = find_body(message[0]);
    if ( p )
    {
	int idle = 0;

	if ( p->query_link() )
	    idle = query_idle(p->query_link());

	send_to_user("locate-reply", orig_mud, orig_user,
		     ({ mud_name(), p->query_name(), idle, 0 }));
    }
}

protected nomask void rcv_locate_reply(string orig_mud, string orig_user,
				    string targ_user, mixed * message)
{
    object p;

    p = find_body(targ_user);
    if ( !p )
    {
	return_error(orig_mud, orig_user, "unk-user",
		     sprintf("转送 locate 回答给不知名玩家「%s」",
			     targ_user));
    }
    else
    {
	string msg;

	msg = sprintf("[locate] 玩家「%s」出现在 %s 上",
		      message[1], message[0]);
	if ( message[3] )
	    msg += sprintf(" (发呆: %s, 状态: %s)",
			   convert_time(message[2], 2), message[3]);
	else
	    msg += sprintf(" (发呆: %s)", convert_time(message[2], 2));
    
	tell(p, msg + "。\n", MSG_INDENT);
    }
}
