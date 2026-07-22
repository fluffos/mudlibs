inherit ROOM;
void create()
{
        set("short","胡同");
        set("long", @LONG
这是一条黑暗、肮脏的小巷，空气中仿佛飘扬着一股罪恶的气息，东北
边通向小巷深处，正人君子是不会往那边走去的。往东走就会回到城中大路
了。西面是一条小巷，名为“生死巷”。
LONG
);
        set("exits", ([ 
	    "south" : __DIR__"dongdajie3",
//     "west" : __DIR__"leitai",
        "northeast" : __DIR__"hutong1",

]));
        set("objects", ([
               __DIR__"npc/liumang"    : 2,
        ]) );

	set("coor/x",120);
  set("coor/y",-210);
   set("coor/z",0);
   set("incity",1);
	setup();
}

