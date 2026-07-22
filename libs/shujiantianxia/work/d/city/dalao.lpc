//Xiaoyao 3/24/99
// Modified by snowman 21/05/2000

#include <room.h>
inherit ROOM;

string look_sign();
void create()
{
        set("short", "监狱");
        set("long", @LONG
这里是监狱，约莫两丈见方的一间大石室，墙壁和顶板都是大石所砌。墙
角里放着一只粪桶，鼻中闻到的尽是臭气和霉气，不由使你捂住了鼻子。在西
面墙上开着一扇小窗(window)。
LONG);

        set("cost", 0);
        set("no_fight", 1);
	set("item_desc",([
        	"window" : (: look_sign :),
        ]));
        setup();
}


string look_sign()
{
        object env, me = this_player();

	if ( me->is_busy() )
		return "你正忙着呢！\n";
		
        if(!( env = find_object("/d/city/bingying")) )
        env = load_object("/d/city/bingying");

        tell_room(env, "你发现有一双眼睛在窗子背後张望。\n");
        me->add_busy(3);
        return "/cmds/std/look"->look_room(me, env);
}
