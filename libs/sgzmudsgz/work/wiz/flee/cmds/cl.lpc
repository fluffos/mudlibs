#include <daemons.h>
#include <edit.h>

inherit CMD;

void main(string str)
{
    mixed tmp;

    if ( !str||!stringp(str) ) return;
	
    tell_user("flee", sprintf("input is %O\n", str));

    tmp = restore_variable(str);

    tell_user("flee", sprintf("result is %O\n", tmp));
}
