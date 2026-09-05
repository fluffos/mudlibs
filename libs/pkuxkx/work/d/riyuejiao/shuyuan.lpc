//shuyuan Zine
#include <ansi.h>
#include <room.h>
inherit ROOM;
#include <localtime.h>
void create()
{
        set("short","书院");
        set("long",@LONG 
这是日月神教的书院，教主觉得属下弟子读书太少，就请
了个先生每天来教门下弟子一段时间。如果先生在的话，神教
弟子可以随时请问(qingwen)问题。
LONG
        );

        set("exits", ([
                "west" : __DIR__"baihutang",
        ]));
        setup();
        call_out("gettime",1);
}

int gettime()
{
    object mr;
    mixed* timeinfos;
    int minute;
    timeinfos = localtime(time());
    minute = timeinfos[LT_MIN];
    if (minute>10&&minute<=20)
    {
        mr=new(__DIR__"npc/teacher");
        mr->move(this_object());
        mr->yoar();
        message_vision("$N不紧不慢地过来了。\n",mr);
    }
    call_out("gettime",600);
    return 1;
}







