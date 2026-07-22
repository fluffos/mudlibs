#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "空地");
        set("long", @LONG
这是一片堂屋前的空地，旁边放了些兵器架、沙袋以及几个木桩。地
上铺满了飘落的树叶和干草。旁边有一口水井、一把水瓢，井水清澈，散
发着阵阵凉气。西面是几大间储藏室。
LONG);
        set("resource/water", 1);
        set("exits", ([
              "southdown" : __DIR__"shanmen",
              "west" : __DIR__"chucang",
              "northup" : __DIR__"tangwu",
        ]));
        set("drink_msg", "$N用水瓢舀了一口清清的井水喝。\n");
        set("outdoors", "白陀山");
        setup(); 
}

