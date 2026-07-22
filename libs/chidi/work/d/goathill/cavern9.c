#pragma save_binary
// Room: /d/goathill/cavern8.c

inherit ROOM;

void create()
{
	set("short", "岩穴");
	set("long",
"这里一片黑漆漆，你必须全靠摸索才能不至于撞到岩壁，你听到\n"
"东边传来阵阵滴水的声音，可是伸手一摸却仍是冷冰冰、又乾又\n"
"硬的岩石，地上布满了许多又黏又稠的不知名东西，使你每一步\n"
"都走得异常艰辛。\n"
);
	set("exits", ([ /* sizeof() == 1 */
         "southup" : __DIR__"cavern8",
         ]));
	set("objects", ([
          __DIR__"npc/red_dragon": 8,
	]) );

	setup();
	replace_program(ROOM);
}
