// Room: /d/linzhi/lin25.c

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
  "northeast" : __DIR__"lin24",
  "southwest" : __DIR__"lin26",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/mob" : 1+random(2),
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4800);
	setup();
	replace_program(ROOM);
}
