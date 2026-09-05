// 草地
// edit: by zine Oct 19 2010

inherit __DIR__"xxconfig";
#include <ansi.h>
void create()
{
	set("short", WHT"秘道"NOR);
	set("long", @LONG
这里是一条秘道，从星宿后山通至一个小镇。
LONG
	);
    set("exits", ([ 
		"southeast" : __DIR__"saimachang",
        "northwest" : __DIR__"midao1",
  
    ]));
	setup();
	::create();
}

int valid_leave(object me,string dir)
{  
	if (dir=="southeast") 
    {
        if (!userp(me))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        tell_object(me,HIW"要回星宿后山，在小镇赛马场钻(zuan)进秘道即可。\n"NOR);
		me->remove_listen_to_die(this_object());
		me->delete_temp("revive_room");
		return ::valid_leave(me, dir);
        
    }
	return ::valid_leave(me, dir);
}
