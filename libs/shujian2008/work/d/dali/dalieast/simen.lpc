// Modify By River 98/12
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIY"拈花寺"NOR);
	set("long", @LONG
你站在一座小小的古庙前，庙门上檐写着「拈花寺」三字。佛教是大理国
教。大理京城内外，大寺数十，小庙以百计，这座「拈花寺」地处偏僻，无甚
香火，即是世居大理之人，多半也不知晓。
LONG
	);
        set("outdoors", "大理");
	set("exits", ([ 
               "northwest" : __DIR__"road4",   
               "enter" : __DIR__"nianhuasi",   
        ]));

        set("objects", ([
	      __DIR__"npc/shami" : 1,
        ]));

	set("coor/x",-220);
  set("coor/y",-430);
   set("coor/z",0);
   setup();
}
void init()
{
            object me = this_player();
     if(me->query_temp("xuncheng"))
     {
       me->set_temp("dali_xc/nianhuasimen",1);
      }
}