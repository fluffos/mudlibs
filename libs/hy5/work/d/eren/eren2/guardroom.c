#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "石洞");
        set("long",  @LONG
又是石壁上一块凹进的地方，约摸有两丈见方，点着一盏油灯，放着
几个木箱和一张床，地上胡乱丢着几柄长剑，看上去像个哨卡。四壁阴暗
潮湿，长满了青苔。
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"jailroad3",
                "south" : __DIR__"controlroom",
        ]));
        set("objects", ([
                __DIR__"npc/star_monkey" : 1,
        ]) );
        set("item_desc", ([
        "青苔" : "暗色的青苔布满了洞壁。\n",
        "moss" : "暗色的青苔布满了洞壁。\n",
        "木箱" : "几个木箱堆起来，成了一张临时的桌子。\n",
        "box" : "几个木箱堆起来，成了一张临时的桌子。\n",
        "床" : "一张断了一条腿的木床，是守卫轮值休息时用的。\n",
        "bed" : "一张断了一条腿的木床，是守卫轮值休息时用的。\n",
    ])); 
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        
}       
