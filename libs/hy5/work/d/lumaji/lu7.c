// Room: /d/lumaji/lu7.c

inherit ROOM;

void create()
{
	set("short", "碎石小径");
	set("long", @LONG
由于这里离长昆明不远，又有一个唯一的马市，所以路上的行
人很多，但大多都不是本地人。路的西面是一家客栈。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"kezhan",
  "south" : __DIR__"lu8",
  "north" : __DIR__"lu6",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
