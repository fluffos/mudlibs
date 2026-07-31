inherit ROOM;

void create ()
{
        set ("short", "女弟子卧室");
        set ("long", @LONG

卧房里面陈设相当干净，地上铺垫这几张皮绒编织的睡垫，看上去非常舒服。
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
