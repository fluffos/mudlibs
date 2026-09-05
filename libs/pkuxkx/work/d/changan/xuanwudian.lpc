
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "玄武殿");
        set("long", @LONG
唐帝国皇帝尊崇道教为国教，玄武又被尊称为玄元上帝，这是一栋
供奉着玄武的道观，以玄武殿为中心分布着三清殿、玄元皇帝殿、大角
观、大福殿等道教建筑，玄武殿北面就是大明宫的北大门玄武门。
LONG        );
        
        set("exits", ([
                "south" : __DIR__"taiye-4",
                "north" : __DIR__"xuanwumen"
        ]));
        
        set("locate_level",3);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
}