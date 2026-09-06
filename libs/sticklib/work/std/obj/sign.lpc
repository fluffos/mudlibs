// New standard sign object. Can't be taken; can be read.
// Clone this and set up with calls to functions
// "set_name", "set_short", "set_read_msg" and possibly
// "set_id", "set_long" and "set_no_get_msg".
//
// Version 1.0 19-apr-95 by Doomdark

inherit "/basic/id";

string read_msg;		// Text of the sign.
string no_get_msg;		// Msg player gets if he/she tries to take this.
void
create()
{
    set_long("It seems to have some writing on it. Maybe you should read it?");
    this_object()->create_sign();
}

status
get(status x)
{
    if (!x && no_get_msg)
	this_player()->tell_me(no_get_msg);
    return 0;
}

status
read_cmd(string s)
{
    if (read_msg) {
	this_player()->tell_me(read_msg);
	environment(this_player()) -> tell_here((string)
	  this_player()->query_name() + " reads the "+query_name()+".", this_player());
	return 1;
    }
    return 0;
}

void
set_read_msg(string s)
{
    read_msg = s;
}

void
set_no_get_msg(string s)
{
    no_get_msg = s;
}
