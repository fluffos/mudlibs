// Room: /d/emei/room3.c 峨嵋派 寝室

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "寝室");
        set("long",
"这里是峨嵋弟子们休息的地方。环顾室内，这里昏暗\n"
"而又安静，几个峨嵋弟子睡得正香，也许是由于都是女孩\n"
"的缘故室内东西不多但很整洁。\n"
        );

        set("exits", ([
		"north" : __DIR__"huayuan1",
               ]));  
        set("sleep_room",1); 
        set("no_fight",1);
        setup();
        replace_program(ROOM);
}
