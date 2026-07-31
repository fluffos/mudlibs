 inherit ROOM;
#include <ansi.h>
void create() 
{
        set("short", "小桥流水");
        set("long", @LONG
乳白色的晨雾渐渐在山林间、泉水上升起又渐渐一缕缕随风飘靛飘散到远方。
小桥旁的屋子里正有几个人走出来手揽着身旁少女的腰，边打着呵欠，边讨论着方
才的战局。在这里你不但可以买得到最醇的酒最好的女人，还可以买到连你自己都
认为永远无法实现的梦想。只要你够慷慨，在这里你甚至可以买别人的命。
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"bigtree",
                "west":  __DIR__"happywood",
                "east":  __DIR__"happyroom",
        ]));
        set("objects", ([
                __DIR__"npc/huhua": 1,
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
}  
