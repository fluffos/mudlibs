 inherit ROOM;
#include <ansi.h> 
string look_house(); 
void create() 
{
        set("short", "小河畔");
        set("long", @LONG
微风中传来泉水流动的声音，你不知不觉得走过去，在流水旁坐下来。流水也
许会干枯，却永远不会停下来,仿佛永远不知道厌倦，它那种活泼的生机永恒不变。
谈淡的烟雾从河水上升起，看来是那么温柔，那么美丽，如果你纵身一跃跃入雾里，
你的烦恼和痛苦岂非也很快地就会随着这烟雾消失？
LONG
        );
        set("exits", ([ 
                "eastup":  __DIR__"spring",
        ]));
        set("item_desc",([
                "red house":    (: look_house() :),
                "house":        (: look_house() :),
                "小红楼":       (: look_house() :),
                "红楼":         (: look_house() :),
                "river":        "一条弯弯曲曲的小溪，水面上雾气弥漫。\n",
                "流水":         "一条弯弯曲曲的小溪，水面上雾气弥漫。\n",
                "小河":         "一条弯弯曲曲的小溪，水面上雾气弥漫。\n",
                "河水":         "一条弯弯曲曲的小溪，水面上雾气弥漫。\n",
                "stream":       "一条弯弯曲曲的小溪，水面上雾气弥漫。\n",
                "泉水":         "一条弯弯曲曲的小溪，水面上雾气弥漫。\n",
        ]) );
        set("objects", ([
                __DIR__"npc/xiaodie2": 1,
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
}  
void init(){
        add_action("do_walk","walkto");
}  
int walkto(string arg){
        
        object me=this_player();
        object room;
        
        if (!me->query("zangbei/星星楼")) return 0;
        if (arg == "building" || arg == "house" || arg == "小红楼" || arg == "红楼") {
                message_vision("$N向河对岸一跃，身影消失在雾气中。\n",me);
                room=find_object(__DIR__"star_room2");
                if (!objectp(room)) room=load_object(__DIR__"star_room2");
                me->move(room);
                return 1;
        }
        return 0;
}
                
                
                
string look_house(){
        
        object me=this_player();
        if (!me->query("zangbei/星星楼")) return "水雾弥漫，你什么也看不清楚。\n";
        return "水雾中，对岸有一幢小红楼忽隐忽现，你可以试着走过去(walkto house)。\n";
}   
