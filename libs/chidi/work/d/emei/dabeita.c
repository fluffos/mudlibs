// Room: /d/emei/dabeita.c 峨嵋派 大悲塔


#include <room.h>
inherit ROOM;
void create()
{
	set("short", "大悲塔");
	set("long", @LONG
这是一座砖石结构的宝塔，塔分六层，塔身作八角形，飞檐翘翎，檐角上
挂满了一串串小铜铃，随风叮叮作响。塔身墙上镂空雕绘着无数佛像，或慈眉
善目、或怒目圆睁，一个个形态维肖。塔底入口处开了一扇拱形的小木门，门
扇两侧用彩漆涂绘。
LONG
	);

	set("exits", ([
		"east" : __DIR__"gudelin3",
                "enter" : __DIR__"baota1",
	]));
	set("outdoors", "emei");
        set("objects",([
               CLASS_D("emei") + "/jingdao" : 1,
	]));

        setup();
}

int valid_leave(object me, string dir)
{
    mapping myfam, mygen;
    myfam = (mapping)me->query("family");

    if ((!myfam || myfam["family_name"] != "峨嵋派") && dir == "enter") {
        if(objectp(present("jing dao", environment(me))))
            return notify_fail("静道闪身拦住去路，对你说道：这里是佛门圣地，怎能乱闯！\n");
    }

    return ::valid_leave(me, dir);
}


