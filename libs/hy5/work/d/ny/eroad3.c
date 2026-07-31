
// Room: /d/snow/eroad3.c

inherit ROOM;

void create()
{
        set("coor",({1400,4900,10}));
	set("short", "山路");
        set("long",
"这是一条说宽不宽，说窄倒也不窄的山路，路面用几块生满青苔的大石铺成，西面是一段坡\n"
"地，从这里可以望见西边有几间房屋错落在林木间，东面则是山壁，山路往西南衔接一条黄\n"
"土小径,南面有一片松林。\n"
);
        set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"eroad2",
]));
        set("outdoors", "ny");

        setup();
        replace_program(ROOM);
}
