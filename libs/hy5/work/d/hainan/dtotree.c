// Room: /d/hainan/dtotree.c

inherit ROOM;

void create()
{
	set("short", "小山路");
	set("long", @LONG
一条小小的山路,已经快被路边的野草遮住了,看来很久以来就没人走
过了,不过只要翻开草叶,你还是能发现这条小路居然是用纯白的云母铺成
的,当初所化的人力物力定是不少.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/hainan");
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"outcave",
  "northeast" : __DIR__"outtree",
]));

	setup();
	replace_program(ROOM);
}
