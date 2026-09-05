//春明门 /d/jinyang/chunmingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "荐福寺");
        set("long", @LONG
荐福寺相传为唐高宗死后宗族为纪念他而建造，原是唐
太宗之女襄城公主旧宅。寺内的小雁塔远近闻名，清晨小雁
塔的钟声响彻10里，雁塔晨钟是著名的关中八景之一。
LONG);
        set("exits", ([
           "west" : __DIR__"southstreet2",
           "east" : __DIR__"xiaoyanta"
        ]));
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
   
}