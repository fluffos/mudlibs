//xiaojing1.c by river

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "小径");
        set("long", @LONG
一条曲曲折折用鹅卵石铺成的小径, 路两旁绿柳成荫, 一处处山石花木点
缀在其中。你走在石地上，脚下啪嗒啪嗒地发出清脆的响声，前方有道小门，
穿过门就能到后花园了。
LONG
        );        
	
	//set("outdoors","武馆");
	set("no_fight",1);
        set("exits", ([
               "north" : __DIR__"houhuayuan",
               "south" : __DIR__"xiaojing2",
        ]));
        
        set("objects", ([
        ]));

        setup();
}
