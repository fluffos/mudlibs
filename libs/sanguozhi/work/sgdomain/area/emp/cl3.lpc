#include <ansi.h>
inherit INDOOR_ROOM;
void setup()
{
   set_light(50);
   set_brief(""+YEL+"长廊"+NOR+"");
   set_long("
    这里的北面就是皇上批阅公文的御书房，周围有大批神色凝重的
御前侍卫在巡逻，足见这里的戒备森严。御书房的门口站着一个小太
监，正无精打采地垂手站在门前。门边有一道醒目的告示，上面写着：
              %^H_RED%^御书房重地，非请勿入，擅入者死！%^RESET%^

");
   set_exits( ([
             "north" : __DIR__+"ysf",
	     "south" : __DIR__+"cl2",
        ]) );
	set_objects( ([ __DIR__+"xtj" : 1, ]));	}
