// /d/taiyuan/huanggong.c
// Room in 太原
// rich 99/05/05
inherit ROOM;
void create()	
{
	set("short", "皇宫");
	set("long", @LONG
这里原来是隋炀帝在太原的行宫，因为建造的时间短，所以建造的
并不豪华，当李渊起兵，攻占长安后，这个皇宫也就只有看守的军兵了。
LONG
	);
set("outdoors", "taiyuan");
set("exits", ([
                "south" : __DIR__"dongdajie1", 
	]));
            set("objects", ([
                __DIR__"npc/shiwei": 2,
        ]));
       setup();
	replace_program(ROOM);
}	
