 inherit ROOM;
void create()
{
        set("short", "乌拉泊北城门");
        set("long", @LONG
乌拉泊自唐元以来就是这里最热闹的城镇，这里的巴札，以其历史悠久
而闻名于世，迄今已有过千年的历史。这里真可谓“十里长街，万商云集”。
往南就是大巴札，再往北有一座若隐若现的宝塔。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"tulu",
  "south" : __DIR__"wuming",
]));
        set("objects", ([
        __DIR__"npc/wall_solider" : 2,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
        set("coor/x",-1120);
        set("coor/y",2110);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    
