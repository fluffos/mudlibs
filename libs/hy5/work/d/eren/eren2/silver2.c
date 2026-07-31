#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"银屋"NOR);
        set("long", @LONG
这屋子布置得竟像是女子闺房，对旁的梳妆台上，居然还放着整套的
梳妆用具，床后面还有个马桶。掀开帐子，床上直直的躺着具骷髅，发髻、
环佩，还都完整的留在枕头上，自然是个女子。 
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"silver",
                        ]));
        set("objects", ([
                __DIR__"npc/maskman_s" : 1,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}     
