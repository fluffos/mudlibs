//pianting1.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"偏厅"NOR);
        set("long", @LONG
房间的四周墙上点满了火把，把整个房间照了个通明。正中的墙上挂着一
幅地图（tu），二弟子周圻正对着地图指指点点，口中咕哝个不停。看见你走
了进来，他马上迎上前来。往南走是一条走廊。
LONG
        );
	set("no_fight",1);
	set("item_desc",([
			"tu" :
HIG"
               星宿派                     京城        
        ∧明   ∧∧∧                    ≌≌≌ 
昆仑派  ∧教                            ≈    ≈
 ∧∧      丝绸之路         ∧∧∧ 少林派       ≈
                     ≈≈≈ 华山派  ∧∧        ≈
                        古墓                      ≈
                       ∧∧∧                     ≈
                              武∧       ±丐帮  ≈
                              当∧ 襄阳      扬州 ≈
                              派   ≌≌      ≌≌ ≈
                峨嵋派                 ≈ ≈≈≈≈≈
                ∧∧∧                        苏州≈
                                      姑苏慕容   ≌≌≈归云庄
                          铁掌帮         ≈≈   ≈ 
                          ∧∧∧                ≈ ≌≌
                                             杭州≌≌        桃花岛 
                    大理≌≌                      宁波≌≌    ≈≈
                                                    福州≌≌"NOR"\n",
		]));	 

        set("exits", ([
               "south" : __DIR__"zoulang5",               
        ]));
        
        set("objects", ([
                __DIR__"npc/dizi2" : 1,
        ]));

        setup();
}
