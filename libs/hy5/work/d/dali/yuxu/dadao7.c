// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "大道");
	set("long", @LONG
你在大道上，两边都是杨柳树，这条路上来往的人并不多。北面就到四川
境内了。
LONG
	);
        set("outdoors", "大理");
	set("exits", ([ 
            "west" : "/d/qingcheng/qcroad3",
	    "south" : __DIR__"dadao6",
        ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
