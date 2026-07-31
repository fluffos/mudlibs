//1997-3-10 by qyz
#include <room.h>

inherit ROOM;


void create()
{
	set("short","象头崖");
	set("long",@LONG
迎面是一块巨大的石崖，形状宛如象头，此地是以得名“象头崖”。前面的
山坡上有一棵松树，形如扫帚，名扫帚松，因枝干繁多又叫千头松，东北方向上
一个巨大圆石，石缝中镶嵌了一株三尺来高的松树，那松树枝干横生，虬枝勃发
，人皆称之探风松。
LONG);
	set("exits",
	([
          "west" : __DIR__"juxian_qiao",
          "northup" : __DIR__"xuanhe_dong",
	]));
	set("outdoors","kongdong");
	set("objects", ([
		__DIR__"npc/kdizi2"  : 3,
		]) );
        setup();
        //place_program(ROOM);
}

int valid_leave(object me,string dir)
{
    if(dir=="northup")
      return notify_fail("北上是陡崖，没法再往上走了。\n");
    return ::valid_leave(me,dir);
}
