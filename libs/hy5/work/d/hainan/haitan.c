// Room: /d/hainan/haitan
inherit ROOM;

void create()
{
  set ("short", "海滩");
  set ("long", @LONG
海浪拍打着岸边的岩石,洁白的沙滩上几只海蟹正努力地向大海爬去.
远处海面上飞鱼越水而出,在海面上滑翔.远远的,你能看到在海中有一片淡
淡的影子,那就是海南岛.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"tohaitan",
]));
	set("objects",([
		__DIR__"npc/man6":1,
			__DIR__"npc/yuwen2":1,
	]));
  set("outdoors", "/d/hainan");
  setup();
  replace_program(ROOM);
}
