              
// 00-2-13
// 文件类型  房间  

inherit ROOM;

void create ()
  {
set("short", "冰火岛海滩");
set("long", @LONG
冰山(iceboat)又飘了一日一夜，终于到了火山脚下，但见那火柱周围一
片青绿，竟是一个极大的岛屿。该处虽然地近北极，但因火山万年不灭，岛
上气候便和长白山、黑龙江一带相似，高山处玄冰白雪。岛东却是一片望不
到尽头的平野，乃火山灰逐年倾入海中而成。

LONG);
set("exits", ([
                "north" : __DIR__"shulin",        
]));
set("item_desc", ([
        "iceboat" : "这是块冰山，虽然回归中土希望极渺，但可一试。\n",
    ]));
set("outdoors","bhdao");
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
     this_player()->move(__DIR__"migong1");
     return 1;
}
}
