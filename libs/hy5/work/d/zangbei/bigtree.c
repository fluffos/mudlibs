 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "大树");
        set("long", @LONG
阳光已升起，林子，庭院，美丽如画。乳白色的晨雾渐渐在山林间、泉水上升
起又渐渐一缕缕随风飘靛飘散到远方。一棵大树象天幕一般展开着它铺张的、多节
的枝丫，树干上放着一壶酒，和一个酒杯。
LONG
        );
        set("exits", ([ 
                "north":  __DIR__"bridge",
        ]));
        set("objects", ([
                __DIR__"npc/yexiang":   1,
                __DIR__"obj/trunk":     1,
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
}  
void reset()
{
        object statue,incense;
               
        ::reset();
        statue = present("trunk", this_object());
        if (!statue->is_character())
        if (!present("winepot",statue)) {
                incense=new(__DIR__"obj/winepot");
                incense->move(statue);
        }
}  
void init() {
        add_action("do_get","get");
}   
int do_get(string arg) {
   
        string arg1,arg2;
        int num,gao;
        object ye;
        
        if (!ye=present("yexiang",this_object())) return 0;
        
        if (sscanf(arg,"%s from trunk",arg1)==1) {
                if (arg1=="winepot") gao=1;
                if (sscanf(arg1,"%s %d",arg2,num)==2)
                        if (arg2=="winepot") gao=1;
        }
        
        if (gao) {
                message_vision("$N一伸手挡住了你,苦笑着说：“我就这么点家当了。”\n",ye);
                return 1;
        }
        
        return 0;
        
        
}  
