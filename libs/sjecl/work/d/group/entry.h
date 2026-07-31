// entry.h
// by augx@sj  4/2/2002
#include <wanted.h>

int valid_leave(object me, string dir)
{
	string str;
	if( !mapp(query("exits")) || !(str=query("exits/"+dir)) ) return 1;
	if( strlen(str)<=9 || str[0..8]!="/d/group/" ) return 1;
	if( sscanf(str,"/d/group/%s/",str) < 1 ) return 1;
	if( !GROUP_D->site_now(str) ) return notify_fail( GROUP_D->get_last_error() );
	if( is_wanted(me)) return 0;
	if( !userp(me) && me->query("no_quest") && !me->query("group/id") ) return 0;
	return 1;
}

void init()
{
	object me = this_player(), room;

	if( userp(me) || !mapp(me->query("group")) || !me->query("startroom") ) return;
	if( !(room=find_object(me->query("startroom"))) ) {
		if( !(room=load_object(me->query("startroom"))) ) {
			destruct(me);
			return;
		}
	}

	tell_room(this_object(),CYN+me->name()+CYN"急匆匆的走了回去。\n"NOR);
	me->move(room);
	tell_room(room,CYN+me->name()+CYN"急匆匆的走了过来。\n"NOR);
}
