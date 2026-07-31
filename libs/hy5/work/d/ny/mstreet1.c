
// Room: /d/snow/mstreet1.c

inherit ROOM;

void create()
{
        set("coor",({-20,4770,10}));
	set("short", "宁远城东街");
        set("long",
"你现在正走在宁远城的街道上，往东边是一条笔直的宁远大街。熙熙攘攘的街道两旁是各式\n"
"各样的店铺，往西南只听得人声鼎沸，那是个五十尺见方的广场，人来人往相当热闹。往北\n"
"可望见一座牌坊，年代久远，上面的字迹早已看不出是什麽字。\n"
);
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"mstreet2",
  "southeast" : __DIR__"square",
]));
        set("objects", ([
                __DIR__"npc/drunk" : 1, ]) );
        set("outdoors", "ny");

        setup();
        replace_program(ROOM);
}
