// Room: /u/xdd/gumu/gmqiant.c
// Motify by river 98/08/29
#include <ansi.h>;
#include <room.h>;
inherit ROOM;

void create()
{
     set("short", HIC"前厅"NOR);
     set("long", @LONG
这是入墓的第一间石室，四壁俱是坚硬的岩石，古墓内光线十分阴暗，寒
气更为逼人，和室外有天壤之别，让你瑟瑟发抖，正前方的石壁上刻着不少文
字(zi)，乃拜师必读。北面通往领悟室，往南则是切磋室。
LONG        );

     set("exits", ([
         "north" : __DIR__"gmlw",
         "south" : __DIR__"gmqc",
         "east" : __DIR__"gmzt", 
         "out" : __DIR__"rukou",   
     ]));    

     set("item_desc", ([
         "zi" : HIR"\t\t本派弟子不得乱杀无辜。\n"NOR
                HIR"\t\t拜师后不得轻易离开古墓。\n"NOR
                HIR"\t\t要修炼本门上乘武功，须夫妇同门。\n"NOR
     ]));
     
     setup();
}
