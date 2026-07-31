
// Room: /u/cloud/dragonhill/hummock.c

inherit ROOM;

void create()
{
        set("coor",({1000,4450,20}));
	set("short", "卧龙岗");
        set("long",
"这是位于雪亭和绮云两镇间的一道山梁。据说山上时常有强盗拦路抢劫。\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "northdown" : __DIR__"nhillfoot",
  "southdown" : __DIR__"shillfoot",
]));

        set("objects", ([
                __DIR__"npc/gangster" : 5
]) );

        set("outdoors", "cloud");

        setup();
}
