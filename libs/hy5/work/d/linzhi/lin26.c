// Room: /d/linzhi/lin26.c

inherit ROOM;

void create()
{
	set("short", "则玛拉山路");
	set("long", @LONG
你来到则玛拉山的北侧，这里平均海拔在4500米左右。山路
此起彼伏，走着十分吃力。不时有风呼呼吹过，像是要阻止你前
进的步伐。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"lin25",
  "westdown" : __DIR__"lin27",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4200);
	setup();
	replace_program(ROOM);
}
