 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "好汉庄");
        set("long", @LONG
好汉庄就是薛家庄，庄主就是当年一百零八招开天辟地盘古神斧横扫过太行山
的薛斌。不过，像它的主人一样，好汉庄已经垂垂老矣。墙上已现出鱼纹，连油漆
都很难掩饰得住，风吹着窗棂时，不停地“格格”发响。
LONG
        );
        set("exits", ([ 
                "northeast" : __DIR__"road1e",
                "south": __DIR__"xuevillage2",
        ]));
        set("objects", ([
                
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}      
