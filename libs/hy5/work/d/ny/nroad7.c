
// Room: /d/snow/eroad3.c

inherit ROOM;

void create()
{
        set("coor",({-150,4800,10}));
	set("short", "山路");
        set("long",
"这是一条说宽不宽，说窄倒也不窄的山路，路面用几块生满青苔的大石铺成，北面是一段坡\n"
"地，从这里可以望见野羊山上有几间房屋错落在林间，南面是一道院墙，里面传来嘈杂的声\n"
"音；山路往东是通往山坳，山路往西衔接一条青石板路。\n"
);
        set("exits", ([ /* sizeof() == 2 */
      "southeast" : __DIR__"mstreet4",
      "southwest" : __DIR__"txgate",
]));
	set("no_clean_up",0);
        set("outdoors", "ny");
//	set("objects",(["/d/snow/npc/txtrainee": 3]));
        setup();
        replace_program(ROOM);
}
