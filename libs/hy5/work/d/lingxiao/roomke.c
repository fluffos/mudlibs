// Room: roomke.c

inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short","居室");
        set("long",@LONG
这里是柯万仞的房间。柯万仞喜欢收集武器，房间四壁都挂
满了形形色色的刀剑，从倭刀到西洋剑，应有尽有。床边还挂了
一柄奇怪的东西，听说是前年从西域来的番人送给他的火枪。据
说老爷子想试试这家伙的威力，结果在床上躺了一个月。
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "south"  : __DIR__"zoulang2", 
        ]));
        set("objects", ([  
                __DIR__"npc/ke" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

