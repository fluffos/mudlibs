#include <room.h>
inherit ROOM;

void create()
{
        set("short", "铸剑室");
        set("long", @LONG
这里是铸剑室，室中到处都是断兵刃，地上隐约还能看见斑斑的血迹，墙
上挂着少古剑。室正中放着一个巨大的炉子，冒着蓬蓬的蓝炎，激烈的罡气震
得你一阵晕眩，原来这里正在以内家真气炼剑。炉前聚精会神的在着一位道长，
他就是「长真子」谭处端。据江湖传闻，他的铸剑之术不在当年的欧冶子之下。  
LONG
        );
        
        set("exits", ([
                "up" : __DIR__"baguating",
                
        ]));
        set("objects", ([
                __DIR__"npc/tanchuduan" : 1, 
   ]));

        setup();
        replace_program(ROOM);
}


