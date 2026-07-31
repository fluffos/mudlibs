 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        object con,item;
        set("short", "黄山剑庐");
        set("long", @LONG
好不容易过险峻的铁索，眼前不觉一亮，峰顶居然有间茅屋，屋上一块正正的
牌匾【黄山剑庐】，屋内陈设简单，一张红木桌上放着几册经卷，笔筒中稀疏地插
着几只狼毫。
LONG
        );
        set("exits", ([ 
          "south" : __DIR__"tiesuo",
        ]));
    set("objects", ([
        __DIR__"npc/mas1" : 1,
        __DIR__"npc/mas2" : 1,
         //       __DIR__"obj/xi" : 1,
    ]) );
    
    set("valid_startroom", 1);
        set("coor/x",-650);
        set("coor/y",-500);
        set("coor/z",40);
        setup();
        
    con = present("西墙",this_object());
/*      item= new(__DIR__"obj/cq2");
    item->move(con);
*/    
//      苍穹 is a very good weapon and has its significance in fy history.
//      However, too many 苍穹 in game will only deflate its value and importance.
//      Therefore I commented it out to keep the number to be 3.
//      in 6666 main site this number has already been reached.
//      in us.fy site, if you are a wizard you can clone one and put it on wall.
//      keep a record of it and try to clone no more than 3 overall.
//                              --- silencer 4/10/2002 
} 
void init()
{
        add_action("climbing", "climb");
} 
void reset()
{
object me,me2;
:: reset();
me2=present("master li",this_object());
me=present("master liu",this_object());
if(me) me->dismiss_team();
if(me2) me2->dismiss_team();
if(me && me2) me->add_team_member(me2);
} 
int climbing(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要爬什么？\n");
                return 1;
        }
        if( arg == "valley" || arg == "down" || arg == "谷壁")
        {
        me = this_player();
        message_vision("$N抓着突出的石角，慢慢的顺着谷壁爬了下去。\n", me);
        me->start_busy(7);
        call_out("fliping",7,me);
        me->stop_busy();
        return 1;
        }
        else
        {
                write("你不可以爬"+arg+"\n");
                return 1;
        }
}
int fliping(object me)
{
        if( !me->is_ghost()) {
        me->move(__DIR__"kuzhu");
        message_vision("$N顺着谷壁爬了下来。\n", me);
        }
        return 1;
}      
