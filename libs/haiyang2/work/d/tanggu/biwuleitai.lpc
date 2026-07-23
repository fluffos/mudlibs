
#include <ansi.h>

//文件目录

inherit ROOM;

void create()
{
        set("short", HIG"招亲擂台"NOR);
        set("long", "这里是比武招亲的擂台。斗大的旗帜迎风飘扬。擂台四周挤满了围观的人群。有
吆喝助威的，有嬉笑起哄的，更多是无聊的闲人。擂台一角挂着一个牌子（paizi）。\n");
        set("no_death", 1);
        set("no_get_from", 1); 
        set("no_sleep_room", 1);
        set("exits", ([ 
			             "out" : __DIR__"kongchangdi",
        ])); 


	set("objects", ([
  //              __DIR__"npc/mu-nianci" : 1,
      	]));

        set("item_desc", ([            
			"paizi" : "\n这里规则与擂台相似，在双方都准备好( ok )了以后开始比武。\n",      
        ]));
        setup(); 
}

