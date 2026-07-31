 inherit ROOM;
void create()
{
        set("short", "绿洲");
        set("long", @LONG
你脚下的流沙突然不见，一阵凉爽的微风拂面出来，只见一个小小的湖泊呈现
在你的眼前。湖里的水虽然只有二指厚，却很清澈，湖边绿树成荫绿草芬芳。在酷
热的沙漠中，湖水仍是那么的清凉。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"desert9",
  "north" : "/d/loulan/sandlin",
  "east" : __DIR__"desert7",
]));
        set("objects", ([
                __DIR__"npc/thinlama" : 1,
        ]));
        set("resource/water",1);
        set("liquid", (["container": "湖"]));
        set("outdoors", "quicksand"); 
        set("coor/x",-1085);
        set("coor/y",-10);
        set("coor/z",0);
        setup();
}
// took out this by xxder because it caused some bug in guanwai Mache
/*
void init()
{
    object ob;
    string outexit;
    if( interactive( ob = this_player()))
    {
        if(query("exits/east")) delete("exits/east");
        outexit = __DIR__"desert"+(string)( random(3)+6)+ ".c";
        set("exits/east", outexit);
    }
}
*/     
