// Room: /d/huashan/laojun.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
	set("short", "老君沟");
	set("long", @LONG
爬过两个要命的悬崖，你已经十分疲倦，可在这里稍作歇息。老君沟是一
条半里多长的山沟，相传为太上老君所开，故名老君沟。
LONG
	);
	set("exits", ([
		"westdown" : __DIR__"baichi",
		"southup" : __DIR__"husun",
	]));

	set("objects", ([ 
		__DIR__"npc/monkey" : 1,
	]));

	set("no_clean_up", 0);
	set("outdoors", "华山" );

	set("coor/x",70);
  set("coor/y",70);
   set("coor/z",40);
   setup();
}
