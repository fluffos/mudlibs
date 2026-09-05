// Room: /u/cuer/emei/shendeng.c

inherit ROOM;

void create()
{
	set("short", "神灯阁");
	set("long", @LONG
这里是千佛庵的神灯阁，是师太们和香客们休息的地
方。一群香客正坐在那聊天，这儿有免费的茶水。往北就
出了神灯阁，进入一个大院子。				
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"dian4",
  "north" : __DIR__"houyuan",
  "west" : __DIR__"beilang3",
  "east" : __DIR__"beilang1",
  "up" : __DIR__"shendeng2"
]));
	set("resource/water", 1);

	setup();
	replace_program(ROOM);
}
