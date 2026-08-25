#include <ansi.h>
inherit INDOOR_ROOM;
void setup()
{
   set_light(50);
   set_brief(""+YEL+"长廊"+NOR+"");
   set_long("
    这里北面是一座炼丹房，周围有不少的御前侍卫在巡逻。炼丹房
的门外站着一个小道士，手执拂尘，木无表情地站在那里。门上有一
道告示，上书：%^H_RED%^炼丹房重地，擅入者死！%^RESET%^你不由自主地倒吸了一口凉
气，退后了两步。
\n");
   set_exits( ([
             "north" : __DIR__+"ldf",
	     "south" : __DIR__+"cl5",
        ]) );
	set_objects( ([ __DIR__+"xds" : 1, ]));	}
