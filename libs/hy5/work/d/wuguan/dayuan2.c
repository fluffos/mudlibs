//cool 98.4.18
inherit ROOM;

void create()
{
	set("short", "武馆大院");
	set("long", @LONG
这是个大院子，东西两边都是练武场，不少人在这里习武强身，这里
很吵，乱烘烘的，你看见不时有扛着东西的，挑着水的匆匆而过，北面上
了台阶就是武馆大厅.。
LONG);
	set("exits", ([
		"south" : __DIR__"dayuan",
       	        "northup" : __DIR__"dating",
        ]));
        set("objects", ([
           __DIR__"npc/zhangfeng" : 1,
                   ]));
           set("no_fight",1);
set("roomif","$botten#武馆任务:ask zhang about job$#");     
	setup();
        replace_program(ROOM);
}


