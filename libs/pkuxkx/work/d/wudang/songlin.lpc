// songlin.c 松林
// by llin
// by arnzh 97/1/23

inherit ROOM;

void create()
{
	set("short", "松林");
	set("long", 
"一片郁郁葱葱的松树林，林间飘着一股淡淡的松香气味。\n"
"耳中只听到几声鸟叫和时断时续的砍柴声，显的十分幽静。一\n"
"条草径曲曲折折，通往树林深处。远处依稀可以看到灵霄宫的\n"
"飞檐斗拱。\n"

	);
        set("outdoors", "wudang");

	set("exits", ([
		"south" : __DIR__"fuzhen",
	]));
        set("objects", ([
                CLASS_D("wudang") + "/famu" : 1,
                __DIR__"npc/monkey" : 1]));

       	setup();
	replace_program(ROOM);
}

