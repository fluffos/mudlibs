 /* Copyright (C) 1998 Apstone, Inc. */
inherit ROOM;
void create()
{
        set("short", "柴容堡湖");
        set("long", @LONG
水平如镜，清可鉴人，盛产鱼蟹。有些地方的湖水并不深，
可以看到湖底的石头和在石缝中穿梭的小鱼，偶尔还有几个气
冒出水面，发出＂咕噜＂一声。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"tulu3",
  "south" : __DIR__"baiyang",
]));
        set("objects", ([
        __DIR__"npc/fish" : 2,
        __DIR__"npc/shrimp" : 2,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
        set("resource/water",1);
        set("liquid/name","清凉的湖水");
        set("liquid/type", "water");
        set("liquid/container","柴容堡湖");
        set("coor/x",-1110);
        set("coor/y",2030);
        set("coor/z",0);
        setup();
} 

void init()
{
        add_action("do_fillwater", "fillwater");
}
int do_fillwater(string arg)
{
        object *list, ob;
        int i, can_fillwater;
        string dir; 
        if( !arg || arg=="" ) return 0; 
        if( arg=="skin" || arg=="wineskin" ) {
                list = all_inventory(this_player());
                i = sizeof(list);
                can_fillwater = 0;
                while (i--) {
                  if (((string)list[i]->query("liquid/type") == "alcohol")
 || ((string)list[i]->query("liquid/type") == "water")         ) {
                        ob = list[i];
                        can_fillwater = 1;
                        ob->set("liquid", ([
                                "type": "water",
                                "name": "清凉的湖水",
                                "remaining": 5,
                                "drunk_apply": 0,
                        ]) );
                        write("你从里装满了清凉的湖水！\n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("你没有装水的东西啊....\n");
                        return 1;
                }
        }
        else {
                write("你要往什么东西里灌水？\n");
        }
        return 1;
}
     
