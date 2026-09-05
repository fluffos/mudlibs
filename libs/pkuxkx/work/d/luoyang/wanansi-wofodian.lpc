//万安寺 
//by picewolf
//2009-5-7

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"卧佛殿"NOR);
        set("long", @LONG
殿内横卧着一尊大佛，头西面南，右手曲肱托首，左手平舒放于腿上，
铸造浑朴精致，体态自如。经过了大雄宝殿，到了这里，肃穆之心渐去，超
脱之意渐浓。据说前任万安寺的主持，就是在这里圆寂的。
LONG
			);

        set("exits", ([     
               "south" : __DIR__"wanansi-daxiongbaodian",  
			"north" : __DIR__"wanansi-jiangjingtai",  
			"west" : __DIR__"wanansi-chanfangw",
			"east" : __DIR__"wanansi-chanfange",  
        ]));

		set("outdoors", "luoyang");
		setup();
		replace_program(ROOM);
}