// Room: /d/snow/sroad1.c

inherit ROOM;

void create()
{
        set("short", "宁远城街道");
        set("long",
"这里是宁远城的街道，往北是一个热闹的广场，南边是条小路通往一座道观，东边则有一条\n"
"小径沿著山腰通往山上，往西是一条比较窄的街道，参差不齐的瓦屋之间传来几声犬吠。\n"
);
        set("exits", ([ /* sizeof() == 4 */
]));
        set("outdoors", "ny");

        setup();
        replace_program(ROOM);
}
