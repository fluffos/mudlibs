// /d/xingxiu/yili2.c
// Modify by Lklv 2001.10.16

#include <ansi.h>
inherit ROOM;
void quarter_pass();

void create()
{
	set("short", "城中心");
        set("long", @LONG
这里是伊犁城中心，人来人往，十分热闹。只是都是维吾尔族人，他们很
少说汉语，所以你听不懂。大街小巷上商铺林立百货云屯市肆繁华。街西边是
一家大商铺，东面住的则是一个大财主，往北边是城内最大的客栈，南面便是
伊犁城门了。
LONG
        );
        set("outdoors", "伊犁");
        set("exits", ([
        	"west" : __DIR__"store",
        	"east" : __DIR__"house",
        	"northwest" : __DIR__"kezhan",
        	"south" : __DIR__"yili1",
        	"north" : __DIR__"store1",
        ]));
        set("objects", ([
		__DIR__"../npc/woman": 1,
		__DIR__"../npc/hman": 1,
		__DIR__"../npc/wujiang": 1,
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
这里是伊犁城中心，人来人往，十分热闹。只是都是维吾尔族人，他们很
少说汉语，所以你听不懂。大街小巷上商铺林立百货云屯市肆繁华。街西边是
一家大商铺，东面住的则是一个大财主，往北边是城内最大的客栈，南面的伊
犁城门已经掩上了。
LONG);
        	  delete("exits/south");
                  break;
            default: set("long", @LONG
这里是伊犁城中心，人来人往，十分热闹。只是都是维吾尔族人，他们很
少说汉语，所以你听不懂。大街小巷上商铺林立百货云屯市肆繁华。街西边是
一家大商铺，东面住的则是一个大财主，往北边是城内最大的客栈，南面便是
伊犁城门了。
LONG);
                  set("exits/south", __DIR__"yili1");
        	  break;
        }
        call_out("quarter_pass", 60);
}
