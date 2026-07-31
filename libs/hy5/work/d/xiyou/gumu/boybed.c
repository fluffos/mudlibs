inherit ROOM;

void create ()
{
        set ("short", "男弟子卧室");
        set ("long", @LONG

这里是男弟子卧房。地面非常干净，好像刚刚被打扫过，地上整齐的摆放着几张紫藤席。
LONG);

       set("exits", 
        ([ //sizeof() == 4
                  "out" : __DIR__"houting",
        ]));
        
        set("objects", 
        ([ //sizeof() == 1
  
        ]));

        set("sleep_room",1);
        set("if_bed",1);


        setup();
}
