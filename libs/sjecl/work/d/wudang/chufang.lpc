// chufang.c (kunlun)
// copied from wudang, modify later.
// cck modified on 17/6/97
// Lklv Modify at 2001.10.19

#include <ansi.h>
inherit ROOM;

void init();
int do_tap(string arg);
int do_sit(string arg);
void delete_served(object me);

void create()
{
        set("short", "厨房");
        set("long", @LONG
这里是武当派弟子用餐的地方。屋里布置很简单, 只摆着几张桌椅, 几位
武当弟子一声不响地吃着。大凡入道之人生活简朴, 只见碗中仅是粗茶淡饭。
LONG
        );

        set("exits", ([
                "west" : __DIR__"donglang2",
        ]));

        set("objects",([
                __DIR__"npc/daotong" : 1,
                FOOD_D("rice") : 2,
                FOOD_D("cha") : 2,
                FOOD_D("doufu") : 2,
                FOOD_D("dawancha") : 2,
        ]));
        set("no_fight", 1);
        setup();
}

int valid_leave(object me, string dir)
{
        object *ob = deep_inventory(me);
        int i = sizeof(ob);
        if((dir == "west")){
        while (i--)
        if(ob[i]->id("xiang cha")
         ||ob[i]->id("mi fan")
         ||ob[i]->id("doufu")
         ||ob[i]->id("da wan"))
           return notify_fail(CYN"道童拦住你道：武当山的规矩, 饮食不得带出厨房。\n"NOR);
        }
        return ::valid_leave(me, dir);
}
