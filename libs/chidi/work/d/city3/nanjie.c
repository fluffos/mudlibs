// Room: /chengdu/nanjie.c
// oooc: 1998/06/20 

inherit ROOM;

void create()
{
        set("short", "南大街");
	set("long", @LONG
你走在南大街的最南端，道路两旁栽种着枝粗叶茂的梧桐，
路面被打扫得干干净净。来来往往的都是些兵勇和官员，偶而走
过来几个平民百姓。东面有个制作精致的石拱桥。
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "north" : __DIR__"nanjie2",
                "south" : __DIR__"southchengmen",
                "east" : __DIR__"gongqiao",
                "southwest" : __DIR__"cai",

	]));
        set("objects", ([
            __DIR__"npc/qigai" : 2,
        ]));

	setup();
	replace_program(ROOM);
}

