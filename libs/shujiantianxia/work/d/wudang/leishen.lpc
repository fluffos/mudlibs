// /area/jiangbei/wudang/leishen.c 雷神洞
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIR"雷神洞"NOR);
        set("long", @LONG
雷神洞位于紫宵宫展旗峰南端的半山腰，它的全称是“南岩焱火雷君沧水
圣洞”。这里是武当山道人修练清微雷法和祈雨的场所。据说，这儿祈雨是非
常灵验的。雷神洞的石殿里供奉的是背生双翅，鹰嘴鹞眼的雷神，他身边立着
的两个侍从，一个叫司查，一个叫击恶。也就是说，一个是管调查人间善恶，
而另一个则专门对行恶之人进行惩罚。
LONG
        );

        set("exits", ([
             "northeast" : __DIR__"gsdao3",
        ]));

        set("no_clean_up", 0);

        set("objects",([
               __DIR__"npc/jxk" : random(2)+1,
        ]));

        set("outdoors", "武当");

        setup();
}
