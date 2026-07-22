// This is a room made by wsl.
inherit ROOM;
void create()
{
    set("short", "绝崖");
    set("long",@LONG
眼前一片空旷，脚下是一个深不见底的悬崖，稍一迈步，崖边的
碎岩就纷纷落了下去，久久都没听到回音。
LONG
);
        set("outdoors","changan");
    set("exits", ([
        "west" :__DIR__"caodi",
]));
    setup();
}

