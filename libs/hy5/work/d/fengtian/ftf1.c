// Room: /d/fengtian/ftf1.c

inherit ROOM;

void create()
{
	set("short", "盛京府衙门口");
	set("long", @LONG
这里是盛京府的政府所在地，门口有两个衙役手持烧火棍笔
直的站在那里，衙役两旁是两个镇门的石狮子，大门口还有一面
大鼓，如果你有冤在身可以在这里击鼓鸣冤。 
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xm2",
]));

        set("objects",([
        	__DIR__"npc/bing" :5,        
        	__DIR__"npc/wujiang" :1,        	
        ]));

        set("outdoors", "fengtian");
	set("cannot_build_home",1);

	setup();
	replace_program(ROOM);
}
