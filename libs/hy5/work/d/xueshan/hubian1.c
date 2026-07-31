//      hubian1.c 湖边小路
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","湖边小路");
        set("long",@LONG
这是圣湖边的小路。路侧的湖水极为清澈。阳光下映
着白顶雪山显出一片蓝幽幽的宁静。
LONG );
        set("outdoors","xueshan");
        set("exits",([
                "east" : __DIR__"hubian2",
                "west" : __DIR__"shenghu",
        ]));
	set("objects", ([
		"quest/skills2/wunon/yu/yutan" : 2,
	])); 

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
