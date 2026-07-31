// Room: /d/city/yunhe1
// Date:  inca netkill  98/08/18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY "京杭运河" NOR);
    set("long", HIY @LONG
你现在正坐船航行在京杭运河上。江面上许多船只来来往往。
这里离扬州不远，所以河上还有不少画舫，河上不时传来阵阵的
歌舞声和游客的嘻笑声，不知不觉中你的情绪仿佛也被感染了，
不由想起了“腰缠十万贯，骑鹤下扬州”这句话。
LONG NOR
    );


    set("outdoors", "city");
    setup();
}


   

void init()

{	

	 	 add_action("do_look", "look");
	 
        }


int do_look()
{  
        return notify_fail("小船\n\t一叶小舟，最多也就能载两三个人。一名年轻的艄公手持\n长竹篙，缓缓的驾着船。\n");
    
}

