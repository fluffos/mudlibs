 // Room: /d/shaolin/muwu.c
inherit ROOM; 
void create()
{
        set("short", "小木屋");
        set("long", @LONG
这是一间简陋的小木屋，屋内靠边放着一张木板床，中间是
一张木桌，桌上放着笔墨纸砚和几本诗集，一看主人就是一位读
书人，屋外是一片翠绿的竹林。
LONG
        );
        set("no_clean_up", 0); 
        set("exits",([
        "east" : __DIR__"zhulin/exit",
])); 
        setup();
        replace_program(ROOM);
}  
