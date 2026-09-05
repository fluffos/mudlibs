// Room: /d/beijing/shiweitian.c
//食为天
//by vast 2003.2

#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIC"食为天"NOR);
set("long",
CYN"这里是京城有名的饭馆，生意非常兴隆，伙计们都忙得团团转。
门口站着一位漂亮的老板娘在招呼来往的客人。里面坐着一个秃头
大汉。饭馆的门口挂着一幅对联，写的是："HIR"闻香下马，知味停车。\n"NOR
 );
	set("exits",  ([
		       "west" : __DIR__"fuchengdajie_s",
        ]));
	set("objects",  ([
		       __DIR__"npc/saixishi": 1,
//                       __DIR__"npc/jialao6": 1,
        ]));

        setup();
        replace_program(ROOM);
}
