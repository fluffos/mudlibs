 inherit ROOM;
void create()
{
        set("short", "竹林");
        set("long", @LONG
这里是一片竹林。四周密不透光。空中响着一种奇怪的声音，让你心神不宁。
走着走着，你已经看不到来时的方向了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "south" : __DIR__"bomboo2",
        "east"  : __DIR__"bomboo2",
        "north" : __DIR__"bomboo2",
        "west"  : __DIR__"bomboo2",
]));
        set("item_desc", ([
                "bamboo": "一片竹林似乎可以推开（push）。\n",
                "竹林": "一片竹林似乎可以推开（push）。\n",
      ]));
        set("outdoors", "fengyun");
        set("coor/x",-20);
        set("coor/y",220);
        set("coor/z",0); 
        setup();
}
void init()
{
        add_action("do_push","push");
  } 
int do_push(string arg)
{
    object me;
    if(!arg || arg==""){
        write("你要推什么？\n");
        return 1;
    }
    if( arg == "bamboo" || arg == "竹林"){
            me = this_player();
             
            me->start_busy(1);
       if(me->query("marks/梅山民") && !query("exits/northeast")) {
                message_vision("$N立定身形向四周察看了一番，用力的推开竹子。\n", me);
                set("exits/northeast", __DIR__"meilin");
                call_out("close_path", 5);
            } else if( !query("exits/southwest") ) {
                    message_vision("$N不辨方向胡乱用力的推开竹子。\n", me);
                    set("exits/southwest", __DIR__"bomboo");
                    call_out("close_path", 10);
        }
        return 1;
    } else {
        write("你不可以推"+arg+"\n");
        return 1;
    }
}
void close_path()
{
    if( query("exits/southwest") ) {
            message("vision", "竹子弹了回来，挡住了去路\n", this_object() );
        delete("exits/southwest");
        } else if( query("exits/northeast") ) {
                message("vision", "竹子弹了回来，挡住了去路\n", this_object() );
                delete("exits/northeast");
        }
}      
