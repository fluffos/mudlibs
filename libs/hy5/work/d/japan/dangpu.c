// Room: /d/japan/dangpu.c

inherit ROOM;

void create()
{
	set("short", "当铺");
	set("long", @LONG
不要奇怪,日本早就有当铺了.当然,屋中的摆设有点不同,有许多看
来很值钱的古董摆在屋子四周.老板一般要仔细估价之后才会扔给你几个
小钱.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jiedaoe1",
]));
  set("no_beg", 1);
  set("no_fight", 1);
  set("no_steal", 1);

        set("objects", ([ /* sizeof() == 2 */
               __DIR__"npc/zuozuomu" : 1,
            ]));

	setup();
	replace_program(ROOM);
}
