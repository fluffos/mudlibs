

inherit ROOM;

void create()
{
 set("coor",({50,4700,10}));
	set("short", "马场");
	set("long",
"这是宁远城的马场,是专门卖马的地方，只见院子里到处都是马匹，千里马，赤兔马，应有\n"
"尽有。只不过这里的马尿味道很浓，简直要把人熏死!\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"sroad1",
]));
set("objects",([
 __DIR__"npc/mafanzi":1,]));
               /* "east" : "/d/snow/bank",*/

	setup();
	replace_program(ROOM);
}
