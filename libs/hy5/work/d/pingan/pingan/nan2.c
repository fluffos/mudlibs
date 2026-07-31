
inherit ROOM;

void create()
{
	set("short", "平安城南街");
	set("long", @LONG
这是平安城南街，宽敞的街道看的人不竟心情一畅。街对面好象
有一家娱乐中心。可进出的人你看着总觉得有点不对劲。东面有
一家棋馆，你可以找人进去杀几把。
LONG
	);
set("outdoors","/d/pingan");
        set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
	set("no_clean_up", 0);
//	set("objects", ([ /* sizeof() == 2 */
//  __DIR__"npc/man2" : 1,
//]));
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"qiyuan/qiyuan1",
  "north" : __DIR__"nan1",
  "west" : __DIR__"duchang/club",
  "south" : __DIR__"nan3",
]));
	set("outdoors", "pingan");

	setup();
	replace_program(ROOM);
}
