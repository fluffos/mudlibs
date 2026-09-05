//万安寺 
//by picewolf
//2009-5-7

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"天王殿"NOR);
        set("long", @LONG
这里正中供奉着弥勒佛，正笑嘻嘻地望着你。两侧矗立着四大天王，
威武强壮。正有虔诚的香客给弥勒佛上香，大概是在祈子求福吧。
LONG
			);

        set("exits", ([     
               "south" : __DIR__"wanansi-guangchang",   
			"north" : __DIR__"wanansi-daxiongbaodian", 
			"east" : __DIR__"wanansi-gulou",
			"west" : __DIR__"wanansi-zhonglou",
        ]));

		set("outdoors", "luoyang");
		setup();
		replace_program(ROOM);
}