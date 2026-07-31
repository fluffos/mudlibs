// qingsonglin14.c 青松林

inherit ROOM;

void create()
{
	set("short", "青松林");
	set("long", @LONG
青松林中一片黑暗，黑暗中充满了各式各样的危险，每一种都可以
至命。若是在林中迷失了方向，饥渴就足以至命。你感觉自己被困
在了阵法之中，只要走错一步，就有生命的危险，心中充满了恐惧。
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"south" : __DIR__"qingsonglin"+(random(10)+2),
		"north" : __DIR__"yadi",
              "west" :__DIR__"qingsonglin"+(random(10)+2),
		"east" : __DIR__"qingsonglin8",
         ]));
	
	set("no_acc_drop",1);
	setup();
	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{

	if (dir == "north" ) me->add_temp("bamboo/count", 1);
	else 			 me->add_temp("bamboo/count", -1);

	return ::valid_leave(me, dir);
}
