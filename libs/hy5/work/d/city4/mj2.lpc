/*  <SecCrypt CPL V3R05>  */
 
//  Room:  /d/city/club3
inherit  ROOM;

void  create  ()
{
    set  ("short",  "麻将馆");
    set  ("long",  @LONG
这是一间宽敞明亮的大厅，厅的正中间是一根圆形的柱子。柱
子上，屋子正中放着一个麻将台，有几个牌友坐在那里打牌。
LONG);

    set("light_up",  1);
    set("no_magic",  1);
    set("no_fight",  1);
    set("exits",  ([  /*  sizeof()  ==  2  */
        "north":  __DIR__"mj1",
    ]));
       set("objects",  ([  //sizeof()  ==  1
                __DIR__"mj/south"  :  1,
                __DIR__"mj/west"  :  1,
                __DIR__"mj/east"  :  1,
                __DIR__"mj/1mj"  :  1,
       ]));
    set("no_clean_up", 0);
    setup();
    replace_program(ROOM);
}
