// Room: /d/changan/ca33.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "函谷关兵营");
	set("long", @LONG
这里就是古函古关。它东起崤山，西接潼津，关设谷中。当年
强秦一隅之地，制关东六国而不敢稍动，最后横扫天下，就是因为
它据此，进可攻，退可守，乃天下形胜之处。老子西出化胡，也是
在此留下两册道德经，千载以下，后人仍研读不尽。
LONG
);
	set("no_clean_up", 0);
	set("outdoors", "changan");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ca32",
//  "east" : "/d/quanzhen/dadao1",
]));
        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 2,
        ]));
	setup();
	replace_program(ROOM);
}
