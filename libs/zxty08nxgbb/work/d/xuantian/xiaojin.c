// xuantian  by:pipip
inherit ROOM; 
int do_ba(string arg) ;void create()
{
        set("short", "小径");
        set("long", @LONG
你终于走出了地底来到了一条小径，高兴的你
用力吸了一口气，忽然你看到一块巨大的圆石，奇怪
的是石头上竟然插着把生锈的短刀。
LONG
        );
        set("exits", ([
              "out" : "d/xuantian/dadao",
              "enter" : "d/xuantian/pomiao",
        ]));

        setup();
}
void init()
{
            add_action("do_ba","ba");
}
void reset()
{
        ::reset();
        set("get_available" , 1);
}
int do_ba(string arg)
{
       object me,obj;
       me = this_player();
       if( !arg || arg!="刀柄" )
              return notify_fail("你要拔什么?\n");
       if ( query("get_available") )  {
       obj = new ("d/xuantian/obj/xblade");
       obj->move(me);
       add("get_available", -1);
message("vision",HIC"〖"HIR"江湖奇闻"HIC"〗"HIC+":"+HIC" 听说"HIM+me->name()+NOR HIG"在玄天派迷宫里弄到了玄天派宝刀！！\n"NOR,users());

       }
       else
       return notify_fail("你伸手一拔，结果拔了个空，原来刀已经被人取走了。\n");
       return 1;
}

