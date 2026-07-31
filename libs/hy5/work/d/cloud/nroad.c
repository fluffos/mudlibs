
// Room: /u/cloud/dragonhill/nroad.c

inherit ROOM;

void create()
{
        set("coor",({0,4550,10}));
	set("short", "黄土路");
        set("long",
"这里是宁远城通往绮云镇的必经之北边就是宁远城，南面通往卧龙岗。早先官府想在此修条\n"
"大路连接两镇，无奈地势所限，加上卧龙岗上常有强人出没，只得做罢。虽说是土路，可过\n"
"往的人很多，路面已被踩得很平了。\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "north" : "/d/ny/nroad6",
  "northeast" : "/d/xueting/sgate",
  "southeast" : __DIR__"nhillfoot",
]));
        set("outdoors", "cloud");

        setup();
        replace_program(ROOM);
}
