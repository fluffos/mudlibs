//万安寺 
//by picewolf
//2009-5-7

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"大雄宝殿"NOR);
        set("long", @LONG
这里供奉着释迦牟尼佛、药师佛、阿弥陀佛三尊大佛，均为精铜所铸，
世间罕见。中央的大红香案上五供齐全，香炉内香烟缭绕，两厢分列十八
罗汉，姿态不一，神情各异。站在里，你不由得肃然正容，缓缓下跪，默
默地祈祷着，忏悔自己今生的孽业。

LONG
			);

        set("exits", ([     
               "south" : __DIR__"wanansi-tianwangdian",  
			"north" : __DIR__"wanansi-wofodian",  
			"west" : __DIR__"wanansi-guanyintang",
			"east" : __DIR__"wanansi-jialandian",  
        ]));

		set("outdoors", "luoyang");
		setup();
		replace_program(ROOM);
}