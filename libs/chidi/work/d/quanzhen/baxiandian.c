// baxiandian.c 八仙殿

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "八仙殿");
        set("long", @LONG
这里是八仙殿，殿内八具塑像栩栩如生。殿中供奉着的正是民间
广为流传的李铁拐、钟离权、张果老、吕洞宾、何仙姑、蓝采和、韩
湘子、曹国舅八仙。殿中放了红木大香案，香案上供品齐备，香火十
分旺盛。 
LONG
        );  
        
        set("exits", ([
                "northwest" : __DIR__"xilang2",
                "south": __DIR__"xilang1",
        ]));
        set("objects", ([
                __DIR__"npc/qizhicheng" : 1, 
   ]));
        setup();
        replace_program(ROOM);
}

