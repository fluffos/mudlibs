
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIC"大慈恩寺"NOR);
        set("long", @LONG
大慈恩寺是唐高宗为追念他的母亲文德皇后而建，唐玄奘
主持这个著名的寺庙，并在这里创建佛教法相唯识宗，大慈恩
寺是整个长安城内最著名、最宏丽的佛寺。寺内大雁塔和北面
的大明宫遥相呼应。寺院的西南角是远近闻名的杏园，大慈恩
寺的杏园和东南边的曲江芙蓉园都是大家喜欢游玩的景点。
LONG    );
        
        set("exits", ([
                "northwest" : __DIR__"shunjie-1",
                "east" : __DIR__"dayanta",
                "southeast" : __DIR__"qujiangchi",
                "west" : __DIR__"southstreet3",
                
        ]));
        set("objects", ([
		"/d/changan/npc/miaozhu" : 1+random(2),
        ]));
        set("outdoors", "changan");
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
   
}


