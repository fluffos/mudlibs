inherit ROOM; 
#include <ansi.h> 
void create()
{
        set("short", "渡船");
        set("long", HIG @LONG 
一叶小舟，最多也就能载七个人。一名精灵族的老艄公，手持长
竹篙，正在船尾吃力地撑着船。
LONG );
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

