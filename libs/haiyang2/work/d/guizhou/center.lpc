inherit ROOM;

void create()
{
	set("short", "贵阳十字街头");
	set("long", @LONG
这是贵阳城内南北和东西的交汇点。形形色色的叫卖声在耳边此起
彼伏，连绵不绝。路上车水马龙，各色行人摩肩接踵，热闹非凡。大道
两旁高立了两座楼牌，南首是军队的驻地，东西两面则是民居。
LONG );

	set("exits", ([
                          "north"      : __DIR__"beishi",
                         "south"      : __DIR__"chengmen",
                         "west"      : __DIR__"xidajie",
                         "east"      : __DIR__"dongdajie",
		
	]));
set("objects",([
__DIR__"npc/chefu":1,
"/clone/npc/man":2,	
     "/clone/misc/dache":1,
]));

 	set("outdoors", "guizhou");
	setup();
	replace_program(ROOM);
}



