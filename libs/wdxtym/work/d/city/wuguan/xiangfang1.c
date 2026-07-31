//xiangfang1.c 东厢房

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIY"东厢房"NOR);
        set("long", @LONG
这里是馆主独子万圭和戚芳居住的东厢房，透着一股醉人的芳香，令你心
旷神怡。在房间的一角摆放着一张梳妆台，台上摆着一些女人用的胭脂粉和用
来涂抹嘴唇的香粉，以及一瓶玉露。往里走就是卧室了。
LONG
        );        	

        set("exits", ([
               "east" : __DIR__"xiangfang2",    
	       "west" : __DIR__"zoulang3",
        ]));
	set("no_fight",1);
        set("objects", ([
              __DIR__"npc/dizi3" : 1,
        ]));

        setup();
}
