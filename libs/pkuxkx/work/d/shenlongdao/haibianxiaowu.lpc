//小屋，给方怡和沐剑屏住的
#include <ansi.h>
inherit ROOM; 
 
void create() 
{ 
        set("short", HIG"海边小屋"NOR);
        set("long", @LONG
    这是神龙岛海边的一个小屋，里面布置得很温馨。一位姑娘在窗口眺望大海，另外一位姑娘在
梳妆台前发呆。看到你走了近来，窗口的那位姑娘眼皮都没有眨一下。
LONG
        );
        set("no_sleep_room", 1);
        set("exits", ([ /* sizeof() == 3 */
  
  "southeast" : __DIR__"haitan",
  
]));
          set("objects",
          ([__DIR__"npc/fang":1,
      __DIR__"npc/mu":1,
                                
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
