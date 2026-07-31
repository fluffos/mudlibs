 inherit ROOM;
void create()
{
        set("short", "翠竹庄门");
        set("long", @LONG
这是一座精巧的山庄。庄院依山傍水，似乎聚集着天地间的灵气。
竹门挂着一块木匾，匾上入木三分的写着四个大字“铁雪山庄”，匾左
下角又书：  
             江湖人身在江湖，江湖人莫入翠竹。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"front_yard",
  "south" : __DIR__"small_river",
]));
       set("objects", ([
                __DIR__"npc/guard" : 1,
        ]) ); 
        set("indoors", "resort");
        set("coor/x",-1230);
        set("coor/y",40);
        set("coor/z",-10);
        setup();
}    
