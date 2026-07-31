// Room: /d/canyon/canyon7.c

inherit ROOM;

void create()
{
	set("coor",({-300,4100,0}));
	set("short", "雁门关谷地");
	set("long",
"雁门关两边是悬崖，中间是谷地，形状很象骆驼的双峰，由此得名。这里地势险峻，南下通\n"
"往京师，北上就是异族的领地了，历来是兵家必争之地。\n"
);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"shance",
  		"north" : __DIR__"canyon6",
]));

        set("outdoors","yanmen");
	setup();
	replace_program(ROOM);
}
