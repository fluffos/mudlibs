// cunzhangjia.c 村长家
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "村长家");
        set("long", @LONG
这里是村长的家，堂屋里堆放着一些锄头、镰刀之类的农耕用
具，有一些是村中村民家里坏了，来央求村长给修的。屋檐前吊着
数十串鲜红的辣椒，还有一些风干的野味。
LONG
        );
        set("exits", ([
                "south" : __DIR__"guchang",
        ]));
        set("objects", ([
                __DIR__"npc/dibao" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
