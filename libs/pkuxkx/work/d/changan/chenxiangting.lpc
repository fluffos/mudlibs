//春明门 /d/jinyang/chunmingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "沉香亭");
        set("long", @LONG
这是龙池湖畔的沉香亭，每当牡丹花盛开的时候，这里都是
欣赏兴庆宫牡丹花的最好场所，亭中歌舞相伴，亭外牡丹与湖光
相映，难怪让人流连忘返。
LONG);
        set("exits", ([
           "southwest" : __DIR__"longchi-1",
        ]));
        
        set("locate_level",2);

        set("outdoors", "changan");
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();
   
}