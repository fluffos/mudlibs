 inherit ROOM;
void create()
{
        set("short", "云海孤舟");
        set("long", @LONG
云，翻腾在脚下，象海浪，又象流水。你就象乘在一条
孤舟之中在云海中漂荡，分不清是水在流还是船在走。东边，
那日出之颠，就是传说中的“帝王谷”。
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"entrance",
  "eastup" :    __DIR__"palace_gate",
  "westdown" : __DIR__"palace_path3",
]));
        set("outdoors", "palace"); 
        set("coor/x",130);
        set("coor/y",0);
        set("coor/z",20);
        set("coor/x",130);
        set("coor/y",0);
        set("coor/z",20);
        set("coor/x",130);
        set("coor/y",0);
        set("coor/z",20);
        set("coor/x",130);
        set("coor/y",0);
        set("coor/z",20);
        setup();
        replace_program(ROOM);
}   
