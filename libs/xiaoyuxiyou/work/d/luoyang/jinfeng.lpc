//changan city
// Cracked by 凌惊雪 1-3-2003

inherit ROOM;

void create ()
{
        set ("short", "金风玉露楼");
        set ("long", @LONG
此楼处于京都，但却是中原最有名的青楼。这里有最贵的酒，
也是最好的酒；这里有最贵的女人，也是最有味儿的女人；这里
有最贵的服务，也是最好的服务。朱红大门上牌一块，又高悬一
块木匾：|春色无边|

LONG);

        set("exits", 
        ([ //sizeof() == 4
                "east" : __DIR__"chengyun",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/gongsun3" : 1,
        ]));
        set("outdoors", "luoyang");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


