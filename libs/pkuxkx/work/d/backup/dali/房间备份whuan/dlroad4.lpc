// /d/dali/dlroad4.c

inherit ROOM;

void create()
{
	set("short", "大道");
	set("long", @LONG
你来到了大理国边境,北边则通往天下闻名的平西王府.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 4 */
		  "northeast" : __DIR__"dlroad2",
		  "south" : __DIR__"guandao6",
               "southwest" : __DIR__"foothill",
		  "north" : "/d/pingxiwangfu/pxroad1",
		]));
        setup();
        replace_program(ROOM);
}
