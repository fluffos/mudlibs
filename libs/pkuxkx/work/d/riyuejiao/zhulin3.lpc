//竹林

#include <ansi.h>
inherit ROOM;
#include "bamboo.h"
void create()
{
	set("short",HIG"竹林"NOR);
	set("long",@LONG 
这里是一大片竹林，竹林间偶尔有小动物穿行。
LONG
	);

	set("exits", ([
		"north" : __DIR__"zhulin",
		
	]));
	
	set("outdoors", "riyuejiao");
	setup();

}
void init()
{
    object me=this_player();
    int i,count=0;
    object chai;
    object *all=all_inventory(this_object());
    add_action("do_get","get");
    add_action("do_pi", ({ "pi","chop" }));
    for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query("is_chai"))
        {
            count=1;
        }
    }
    if (userp(me)&&me->query("rynewbiejob/zhulou/start")&&count<1)
    {
        chai=new(__DIR__"obj/kandao");
        chai->move(this_object());
    }
}

int do_get(string arg)
{
    object me=this_player();
    if (arg=="all")
    {
        tell_object(me,"这里只能一件一件拿东西。\n");
        return 1;
    }
    if (arg=="kan dao")
    {
        if (!me->query("rynewbiejob/zhulou/start"))
        {
            tell_object(me,"一把砍刀也偷，真是辱没你在江湖的威名啊。\n");
            return 1;
        }
        if (present("kan dao",me))
        {
            tell_object(me,"你身上不是有一把砍刀了吗？\n");
            return 1;
        }
    }
}




