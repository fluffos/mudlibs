inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
	set("short", "正厅");
	set("long", @LONG
这里是大理皇宫的正厅。只见正中有一块横匾，写着「邦国柱石」四个大
字，下首署着「丁卯御笔」四个小字，楹柱中堂悬满了字画。厅中站着一人，
气宇轩昂，看上去有帝王之像。厅的东边是书房，西边是御膳房。北边有一扇
门，似乎是通往后宫的走廊。
LONG);

	set("exits", ([
		"south" : __DIR__"zoulang1",
		"north" : __DIR__"zoulang2",
		"east" : __DIR__"shufang",
		"west" : __DIR__"chufang",
	]));
	 set("objects", ([
            __DIR__"npc/duanzm" : 1
	]) );


	set("coor/x",-310);
  set("coor/y",-420);
   set("coor/z",-20);
   setup();
}

int valid_leave(object me, string dir)
{
    if((dir=="north")
     &&(!me->query_temp("enter"))){
	return notify_fail("里面是后宫，若没有要紧的事不要乱闯。\n");
        }	
      return ::valid_leave(me, dir);
}
