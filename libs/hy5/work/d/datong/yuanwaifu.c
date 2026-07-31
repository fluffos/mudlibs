// Room: /open/dt/yuanwaifu.c

inherit ROOM;

void create()
{
	set("short", "员外府");
	set("long", @LONG
梁员外修的何园是扬州城中数一数二的好园林，就是传到江南也颇
有些名声，园内假山水池错落有致，一草一木，别具匠心，往往细微之
处却又有曲径通幽之感。满目芳华，扑鼻芬香，令人陶醉。

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"hongchanglu6",
]));
        set("objects",([
       __DIR__"npc/cui" :1,

]));
	setup();
	replace_program(ROOM);
}
