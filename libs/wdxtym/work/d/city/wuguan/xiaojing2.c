//xiaojing2.c by river

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "石径");
        set("long", @LONG
一条曲曲折折用鹅卵石铺成的小径, 路两旁绿柳成荫, 一处处山石花木点
缀在其中。你走在石地上，脚下啪嗒啪嗒地发出清脆的响声。西边连接着回廊，
往北面去是这条小径的延伸，东面就是文霞亭了。
LONG
        );
        
        //set("outdoors","武馆");
	  set("no_fight",1);
        set("exits", ([
               "north" : __DIR__"xiaojing1",
	       "east"  : __DIR__"wxting",
	       "west"  : __DIR__"huilang",
        ]));
        
        set("objects", ([
        ]));

        setup();
}
