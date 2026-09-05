// Room: /shenlongjiao/yishidating.c
// kiden 06/08/25
#include <ansi.h>;
#include <room.h>;
inherit ROOM;

void create()
{
        set("short", CYN"议事大厅"NOR);
        set("long", @LONG
过了一条长廊，眼前突然出现一座大厅。这厅硕大无比，足可容纳千人之众，一见之下，不由得让人肃然生敬。
一群群少年男女衣分五色，分站五个方位。青、白、黑、黄四色的都是少年，穿红的则是少女，
背上名负长剑，每一队约有百人。大厅彼端居中并排放着两张竹椅，铺了锦缎垫子。
两旁站着数十人，有男有女，年纪轻的三十来岁，老的已有六七十岁，身上均不带兵刃。
大厅中聚集着五六百人，竟无半点声息，连咳嗽也没一声。
LONG
        );
//        set("outdoors", "shenlongdao");
        set("exits", ([
                "out" : __DIR__"changlang2",  
                "west" : __DIR__"qingshibanlu",  
                "north" : __DIR__"neitang",      
//                "west" : __DIR__"xixiangfang",                                
//                "east" : __DIR__"dongxiangfang",                        
        ]));

   set("objects", ([
              __DIR__"npc/dizi" : 4,
//        __DIR__"npc/rascal":1,
       ]));
        setup();
        replace_program(ROOM);
}

