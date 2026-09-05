              
// 00-2-13
// 文件类型  房间  

inherit ROOM;

void create ()
  {
set("short", "大海边");
set("long", @LONG
转过一处海滨，只觉寒风扑面，你不由打了个冷战，海面
上已没有船只，远近漂浮着许多冰山(iceboat)，难道这就是去
往极北之地的必经之路？

LONG);
set("exits", ([
                "west" :"/d/xiakedao/nanhaibin",        
]));
set("item_desc", ([
        "iceboat" : "这是块冰山，不知会飘向哪里，想试试吗？\n",
    ]));
setup();
   }
void init()
{
    add_action("do_enter", "enter");
}


int do_enter(string arg)
{
    string dir;

    if( !arg || arg!="iceboat" )
    return notify_fail("你要进哪里？\n");

    if( arg=="iceboat" )
    {
     this_player()->move(__DIR__"migong2");
     return 1;
}
}
