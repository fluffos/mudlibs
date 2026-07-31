 //Created by justdoit at May 2001
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "碧海蓝天");
        set("long", @LONG
放眼望去，海天相接，一片空蒙，在这里，你已分不清天上人间。沙滩洁白柔
细，海水湛蓝如碧，浪涛带着新鲜美丽的白沫轻拍着海岸。潮涨潮落时，竟然会有
些零碎的物件飘来。方圆百里似乎人烟皆无，往北是一大片平野，而尽头处却是起
伏环绕的群山碧水，一间破陋的小屋在海风中摇摇晃晃。
LONG
           );
        set("exits", 
           ([ 
       "north" : __DIR__"xiaowu",
       "west" : __DIR__"shatan",
       "east" : __DIR__"shatan",
        ]));
    set("objects", 
       ([ 
//           __DIR__"obj/sand" : 1, 
        ]));
        set("outdoors", "baiyun");
        set("coor/x",10);
    set("coor/y",-1680);
    set("coor/z",0);
    setup();
    replace_program(ROOM);
}    
