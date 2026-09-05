//春明门 /d/jinyang/chunmingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "西市");
        set("long", @LONG
这是喧嚣的长安西市，两边的商店鳞次栉比，市场街道
上挤满了来自长安各地的居民，来自异国他乡的商人，好一
个热闹景象。街道两边是长安有名的古董店和胭脂铺。
LONG);

        set("exits", ([
                "west" : __DIR__"gudongdian",
                "north" : __DIR__"weststreet-2",
                "south" : __DIR__"westmarket-2",
                "east" : __DIR__"yanzhipu",                
        ]));

        set("outdoors", "changan");
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
   
}