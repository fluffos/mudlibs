 inherit ROOM;
void create()
{
        set("short", "吐鲁番");
        set("long", @LONG
这盆地中部，气候变化无常，＂早穿棉，午穿纱，抱着火炉吃
西瓜＂指的就是这里。横亘在吐鲁番盆地中部，就是呈橘红色色的
火焰山。神话小说《西游记》中所描写的孙悟空过火焰山，斗铁扇
公主的故事，就发生在那儿。
LONG
        );
        set("exits", ([ 
  "westup" : __DIR__"sichou3",
  "southwest" : __DIR__"aiding",
  "eastup" : __DIR__"emin",
]));
        set("objects", ([
        __DIR__"npc/girl" : 2,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
        set("coor/x",-1060);
        set("coor/y",2030);
        set("coor/z",-10);
        setup();
        replace_program(ROOM);
}     
