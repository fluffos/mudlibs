// Room: /d/xingxiu/yili1.c
// by snowman@SJ
// Modify by Lklv 2001.10.16

#include <ansi.h>
inherit ROOM;

void quarter_pass();

void create()
{
	set("short", "南城门");
	set("long", @LONG
伊犁又名惠远，西通波斯，南到天竺，东与阳关、玉门相连，扼中西交通
的要冲，是横贯东西的丝绸之路上十分重要的地区，汉代这里就属于安西都护
府的辖区。伊犁城在平坦的伊犁河北岸度地而筑，城高一丈四，地势险要。城
墙上满布着炮台、枪眼，戒备森严。
LONG
        );
        set("outdoors", "伊犁");
        set("exits", ([
                "south" : __DIR__"yilihe",
                "north" : __DIR__"yili2",
        ]));

        set("objects", ([
                __DIR__"../npc/bing" : 2,
                __DIR__"../npc/shangren" : 1,
        ]));
	setup();
	quarter_pass();
}

void quarter_pass()
{
        string local;

        local = NATURE_D->query_daytime();

        switch(local){
            case "event_night":
            case "event_midnight":
                  set("long", @LONG
伊犁又名惠远，西通波斯，南到天竺，东与阳关、玉门相连，扼中西交通
的要冲，是横贯东西的丝绸之路上十分重要的地区，汉代这里就属于安西都护
府的辖区。伊犁城在平坦的伊犁河北岸度地而筑，城高一丈四，地势险要。城
墙上满布着炮台、枪眼，戒备森严。现在是夜间，城门已关，只有几个回族士
兵在城门口守夜。
LONG);
        	  delete("exits/north");
                  break;
            default: set("long", @LONG
伊犁又名惠远，西通波斯，南到天竺，东与阳关、玉门相连，扼中西交通
的要冲，是横贯东西的丝绸之路上十分重要的地区，汉代这里就属于安西都护
府的辖区。伊犁城在平坦的伊犁河北岸度地而筑，城高一丈四，地势险要。城
墙上满布着炮台、枪眼，戒备森严。
LONG);
                  set("exits/north", __DIR__"yili2");
        	  break;
        }
        call_out("quarter_pass", 60);
}
