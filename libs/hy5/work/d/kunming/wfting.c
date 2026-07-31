// /d/kunming/shilin
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW "望峰亭" NOR);
        set("long", @LONG
这里是石林最高的一座峰，峰上有一小亭，真不知道是如何
建造出来的，放眼看去，只见四面石峰(feng)林立,一时间眼睛都
看花了。
LONG
        );
        set("outdoors", "kunming");
        set("exits", ([
                
                "up"  :__DIR__"lianhua",        
               
        ]));
             
        setup();
        replace_program(ROOM);
}
