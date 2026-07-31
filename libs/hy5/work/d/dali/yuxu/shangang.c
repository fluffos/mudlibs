// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "山岗");
	set("long", @LONG
你转过了一道山岗，迎面的是一条笔直大道，道边种有青青杨柳树，随风
飘扬。
LONG
	);
        set("outdoors", "大理");
	set("exits", ([ /* sizeof() == 1 */
	    "northwest" : __DIR__"dadao5",
	    "east" : __DIR__"xiaodao2",
        ]));
        set("objects", ([
              __DIR__"npc/dadao" : 1,
	]));

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
