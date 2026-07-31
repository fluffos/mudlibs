

#include <liebiao.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mapping sets;
	string msg, *mysets;
	int i, v;

	if ( me->query("xieyi/zmud") || !me->query("env/myhp_show") ) return 1;

	msg = "";
	sets = me->query("env");
	if ( !mapp(sets) ) sets = ([]);
	v = sizeof(sets);
	if ( !v ) return 1;
	mysets = keys(sets);

	for ( i=0 ; i < v; i++ )
	{
		msg += mysets[i]+"="+sets[mysets[i]]+";";
	}

	tell_object(me, SET(msg));
	return 1;
}