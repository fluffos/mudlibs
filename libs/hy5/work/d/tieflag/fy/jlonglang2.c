 inherit ROOM;
void create()
{
        set("short", "浸龙走廊");
        set("long", @LONG
一人多高，只容两人并行的檀香木走廊，廊中的两侧陈列着一些奇花异草。滚
滚热气从走廊的一头冒出，将檀木地板打得又湿又滑，你几乎要扶着栏杆才不会滑
倒。
LONG
        );
        set("exits", ([
                "south" : __DIR__"jlonglang1",
                "west" : __DIR__"jlonglang3",
        ]));
        set("no_magic",1);
        set("coor/x",-20);
        set("coor/y",40);
        set("coor/z",0);
        setup();
}
void init()
{ 
        add_action("do_search","search");
} 
int do_search()
{ 
        object me,obj;
        me=this_player();
        if(me->query_temp("marks/sword_almost2") && !query("gotit")){
        tell_object(me,"你在湿湿的水汽中摸了又摸，终于发现了一件东西。。。\n");
        obj = new(__DIR__"obj/shangfang");
        obj->move(this_object());
        set("gotit",1);
        me->set_temp("marks/sword_gotit",1);
        }else
        tell_object(me,"你在湿湿的水汽中摸了又摸，但什么也没有摸到。\n");
        return 1;
} 
void reset()
{ 
::reset();
if(query("gotit") && random(4)) set("gotit",1);
        else set("gotit",0);
        
}   
int valid_leave(object me, string dir)
{
    if(  dir == "west" && (string)me->query("gender") != "男性")
        return notify_fail("这是男人浴室，你冲进去作什么？\n");
    return 1;
}  
