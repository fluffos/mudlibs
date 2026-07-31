 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "卧室");
        set("long", @LONG
卧室里的陈设及其简单，西墙有张床，在关外长大的人都习惯睡硬炕，老伯也
不例外，所以这是张很硬的木板床，也是张很普通的木板床。正中是把宽大而舒服
的藤椅，老伯喜欢坐在这把藤椅上接见他的朋友的属下，听他们的意见和消息，然
后再下决定。有很多改变了无数人命运的大事都是老伯坐在这藤椅上决定的。
LONG
        );
        set("exits", ([ 
                "south":        __DIR__"groom1",
        ]));
        set("objects", ([
                __DIR__"npc/laobo":     1,
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}       
