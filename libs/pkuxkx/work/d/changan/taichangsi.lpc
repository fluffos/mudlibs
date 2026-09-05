
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "太常寺");
        set("long", @LONG
这里是太常寺，太常寺是五寺之一，负责掌管礼乐、郊庙、社稷、坛壝、
陵寝等职责，设有郊社、太乐、鼓吹、太医、太卜、廪牺六个署，南面的太
乐署下辖内教坊，常有艺人排演各种演艺节目，太常寺的东面是巍峨高耸的
太庙。
LONG        );
        
        set("exits", ([
                "east" : __DIR__"taimiao",
                "south" : __DIR__"neijiaofang",
                "west" : __DIR__"chengtianstreet-9"
        ]));
        
        set("locate_level",1);
        set("changan", 2); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}
