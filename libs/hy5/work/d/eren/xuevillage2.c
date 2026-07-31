 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "好汉庄大厅");
        set("long", @LONG
大厅中很宽阔，正中是张枣木桌，桌上有酒，还有一卷纸。阳光从窗外照进来，
正照在架上的铁斧上，一柄六十三斤的大铁斧。三十年前，这柄铁斧陪着庄主薛斌
入过龙潭，闯过虎穴，横扫过大行山。现在这柄铁斧还是和三十年前一样，看来还
是那么刚健，还是在闪闪的发着光。----- 可是铁斧的主人呢？
LONG
        );
        set("exits", ([ 
                "north": __DIR__"xuevillage",
        ]));
        set("objects", ([
                __DIR__"npc/xuebin": 1,
                __DIR__"npc/jiaren":    1,
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
