// Room: /d/yandang/shanlu8.c

inherit ROOM;

void create()
{
	set("short", "倒灵峰");
	set("long", @LONG
传说元代至正元年,山崩地裂,原灵峰寺中的无恶不作的主持静空等
恶僧统统葬在岩底下,只有一个好心肠的伙夫僧由神犬引出洞外保全了性
命,北面就是哪个传说中的山洞了.
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/nuhai.c" : 1,
  __DIR__"npc/nanhai.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"shanlu7",
  	"westdown" : __DIR__"to_yandang3",
  "enter" : __DIR__"shandong1",
]));
	set("outdoors", "/d/yandang");

	setup();
	replace_program(ROOM);
}
