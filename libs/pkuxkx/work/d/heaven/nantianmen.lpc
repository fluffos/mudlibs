
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIY"南天门"NOR);
	set("long", @LONG 
云雾缭绕，仙乐悠扬，这里就是传说中的天界之门。
LONG
	);

	set("exits", ([
		"down" : "/d/death/gate",
		//以后可以增加点地图，目前只是为了放幻镜
		"enter": "/d/city/guangchang"
	]));
	
	set("objects", ([
	    "/clone/misc/huanjing":1
	]));

	setup();
}

void init()
{
    object me = this_player();
    if(!wizardp(me) && me->is_ghost() != 1)
    {
        message_vision("一个宏亮的声音响起：大胆凡人，竟敢私闯天界！\n",me);
        me->move("/d/city/idleroom");                
        me->unconcious();
        message("vision",me->query("name")+"突然从天上掉了下来，摔的不轻。\n",environment(me));
        
    }
}
int valid_leave(object me, string dir)
{
    if(dir == "enter")
    {
        return notify_fail("一个宏亮的声音响起：鬼魂不得入内！\n");
    }
    return 1;
}
