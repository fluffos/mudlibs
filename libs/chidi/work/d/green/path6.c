#pragma save_binary
// Room: /d/green/path6.c

inherit ROOM;

void create()
{
        set("coor",({20,4850,10}));
	set("short", "石板路");
        set("long",
"这是一条平整的石板路,上面隐约可以看见两道很深的车轮,看来\n"
"是用来作运输用途的道路.往西是通往山下的路,往东你可以看到\n"
"一些建筑物,像是村庄之类的.南边看去是一片矮树丛.北边突然\n"
"叉出一条崎岖的山路。\n"
);
        set("exits", ([ /* sizeof() == 2 */
  "north": "/d/goathill/mroad1",
//  "west" : "/d/ny/nroad2",
  "east" : "/d/green/path5",
]));
        set("outdoors", "snow");

        setup();
        replace_program(ROOM);
}
