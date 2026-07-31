inherit ROOM; 
 
#include <ansi.h>
void create() 
{ 
        set("short", "精灵界");
        set("long",HIG @LONG
这里是一个异世界，来到这里，已经远离了你的江湖。这里没
有恩怨，没有纷争。有的只是动听的音乐，优美的风景。十四根玉
石柱子参天而立，看不到尽头。玉柱间白云缭绕，透过白云，隐约
能看到雕栏画栋，听到丝竹笙歌，光彩流动，奇丽不可名状。这里
没有昼夜之分，只有空气中不时传来缕缕清香，令人感到平静安宁。
LONG
       );
        set("exits", ([ 
  "north" : __DIR__"spirit2",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

