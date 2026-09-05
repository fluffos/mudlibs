//洛阳，扩展地图
//by kiden
//2006-9-8
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "东大街");
        set("long", @LONG
站在东大街上，你会发现这条街有快慢道之分，街道两旁栽植松柏，
到处是张灯结彩。大街两旁排列着许多店铺。临街店铺里经营着汴绣、字
画、陶瓷、古董、名酒、小吃等，热闹非凡。北边是庙会所在，非常的热
闹，人山人海，人声鼎沸，在里面可以找到你所想要的东西，南边是四海
钱庄的分店『四海金店』，专门寄存顾客的金块。
LONG
        );

        set("exits", ([
               "east" : __DIR__"dongdajie2",
               "west" : __DIR__"center",
               "north" : __DIR__"miaohui",
               "south" : __DIR__"jewelrystore",     
               	"northeast":__DIR__"datiepu",          
        ]));
/*        set("objects", ([
                "/d/city/npc/wujiang1"+random(2) : 1,
                "/d/city/npc/bing" : 2,
        ]));
*/
        set("outdoors", "luoyang");
        setup();
        replace_program(ROOM);
}

