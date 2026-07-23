 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "河滩");
        set("long", @LONG
边城南面是一条湍急的小河，两岸的泥土为深褐色，当地人称之为赤土河，上
游是著名的贡嘎银河，也就是传说中的神河，所以赤土河也沾上了神气，每到节日
就有许多虔诚的信徒来转山。不过平时就只有几个妇人在浆洗衣裳。河的南岸有许
多堆的整整齐齐的石头，一条小路通向山林深处。
LONG
        );
        set("exits", ([ 
                "northwest":  __DIR__"zhihuo",
                "north":  "/d/qingzh/kunlun18",	
        ]));
        set("item_desc", ([
                "river":        "水流湍急，但是不深，你可以试着涉过去(wade)。\n",
                "赤土河":       "水流湍急，但是不深，你可以试着涉过去(wade)。\n",
//	          "river":        "水流湍急，但是不深。\n",
//                 "赤土河":       "水流湍急，但是不深。\n",
        ]) );
        set("objects", ([
        
                __DIR__"npc/woman":     1,
                __DIR__"npc/girl":      1,
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",-1100);
        set("coor/y",130);
        set("coor/z",0);
        setup(); 
}  
