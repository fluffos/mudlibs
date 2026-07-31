// Room: /d/new_taohua/houting.c

inherit ROOM;

void create()
{
	set("short", "后厅");
	set("long", @LONG
此间屋偏小，陈设皆无，一边通向客房，一边通向饭厅。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
  "north": __DIR__"yonglu1",
  "south" : __DIR__"dating",
  "east" : __DIR__"yushimen",
  "west" : __DIR__"shitang",
]));
    set("objects", ([
       __DIR__"npc/di-zi3" : 3,
     ]));
	

	setup();
	replace_program(ROOM);
}
