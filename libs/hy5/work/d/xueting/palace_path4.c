
inherit ROOM;

void create()
{
        set("short", "云海孤舟");
        set("long", @LONG
云，翻腾在脚下，象海浪，又象流水。你就象乘在一条孤舟之
中在云海中漂荡，分不清是水在流还是船在走。东边，那日出之颠，
耸立着“日朝园”。
LONG
        );
        set("exits", ([ 
  "eastup" : __DIR__"palace_gate",
  "westdown" : __DIR__"palace_path3",
]));
        set("outdoors","xueting");

        setup();
        replace_program(ROOM);
}

