// Room: /d/emei/chanfang8.c 峨嵋派 禅房

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "禅房");
        set("long",
"这里是静照师太的禅房。简单而整齐的摆放着一张床\n"
"和一张小桌，桌上放着几本佛经，静照师太正端坐在床上\n"
"，一边敲着木鱼一边念经。\n"
        );

        set("exits", ([
		"west" : __DIR__"xilang4",
               ]));   
        set("objects",([
           __DIR__"npc/jingzhao" : 1,
            ]));

        setup();
        replace_program(ROOM);
}
