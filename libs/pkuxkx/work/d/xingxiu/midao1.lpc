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
		"west" : __DIR__"yanzhiguan",
        "southeast" : __DIR__"midao2",
  
    ]));
	setup();
	::create();
}

int valid_leave(object me,string dir)
{  
	if (dir=="west") 
    {
        if (!userp(me))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}
