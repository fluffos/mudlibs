// Room: /u/cuer/emei/chfang10.c

inherit ROOM;

void create()
{
	set("short", "禅房");
	set("long", @LONG
这里是文善的禅房。简单而整齐的摆放着一张床
和一张小桌，桌上放着几本佛经，文善正端坐在床上
，一边敲着木鱼一边念经。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"dlang2",
]));
	set("objects",([
          __DIR__"npc/wenshan" : 1,
               ]));

	setup();
	replace_program(ROOM);
}
