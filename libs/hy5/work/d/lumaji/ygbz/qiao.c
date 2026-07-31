// By zjb@ty 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "跃马桥");
        set("long", @LONG  
这里是附近有名的跃马桥,桥中间有六根石柱顶
部给雕成六个俯探桥外的*石龙头*，画龙点睛般为石
桥平添无限生气。
LONG
        ); 
        set("item_desc", ([       
"石龙头" : "你隐见一圈淡淡的圆柱与桥身的接痕，若不是有目标的查察，
必会当是石纹忽略过去,你不禁想顶一顶(ding)圈痕!\n",          
                          ]));
        set("exits", ([
               "south" : "/d/lumaji/pomiao",
                      ]));
        set("no_clean_up", 0);
        setup();
} 
void init()
{
  object me = this_player();
        add_action("do_ding", "ding");
        add_action("do_ba", "ba"); 
        add_action("do_zhuan", "zhuan");
}
void check_longtou()
{
    object me;
    me = this_player();
if(query("longtou")==6)
{
   message_vision(HIC"你突然感觉龙头松了很多,似乎可以拔(ba)起来了!。\n"NOR, this_player());
      me->set_temp("ba_longtou",1);
remove_call_out("on_del");
call_out("on_del", 10);
}
}
int do_ba(string arg)
{
        object me;
        me = this_player(); 
   if( !me->query_temp("ba_longtou")) return 0;   
     if( !arg || arg=="" ) return notify_fail("你要拔什么东西!\n");
            if( arg=="龙头" ) {
             write(HIB"你一把将龙头把了起来。 \n"NOR); 
         write(HIR"龙头似乎可以往左右转动，到底转哪边好呢? \n"NOR); 
             me->delete_temp("ba_longtou");             this_player()->set_temp("zhuan_longtou", 1);
             return 1;
       }
}
 int do_ding(string arg)
{
        object zhu, me=this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="圈痕" )
                             { 
if(query("longtou")<6)
{                                             message_vision(
HIR"$N在龙头下方的圈痕用力往上顶了一下!\n"NOR, this_player());
add("longtou",1);
check_longtou();
return 1;
                }
delete("longtou");
 message_vision(HIG"你顶过头了,龙头又陷了回去!\n"NOR, this_player());
                return 1;
        }
        return 1;
}
int do_zhuan(string arg)
{
        object me; 
    object room;
    string dir;
             me = this_player();
 if (!me->query_temp("zhuan_longtou")) 
return 0;
      if( !arg || arg=="" ) return notify_fail("你要转什么东西!\n");
      if( sscanf(arg, "%s", dir)==1 ) {
    if( dir=="left" ) {
   message_vision(HIC"$N把龙头往左转了一转。\n"NOR, this_player()); 
            add("zhuanmen", 1); 
return 1;
}
 else if( dir=="right") {
         if (query("zhuanmen")) {   
message_vision(HIC"$N把龙头又转了回去。\n"NOR, this_player()); 
  message_vision(HIC"龙柱座落原位，果然与先前丝毫无异。\n"NOR, this_player());
this_player()->delete_temp("zhuan_longtou"); 
        if( room = find_object(__DIR__"yuanzi") ) { 
            room->set("exits/down", __DIR__"jindi");
    message("vision", "龙柱该是连接着钢索轴轮一类的东西，你感到扭动和震荡。\n",me );
    message("vision", "突然你听到井里的水位下降了好多,好象可以走下去了。\n",room ); 
 message("channel:chat", HBRED"【海洋】"+me->query("name")+"成功启动杨公宝库任务了!!\n"NOR,users());
  call_out("on_guanmen", 180);
}
}
return 1;
        }
        else {
            write("你想转向哪个方向?\n");
            return 1;
        }
}
}
void on_guanmen(object room)
{ 
object me;
      if( room = find_object(__DIR__"yuanzi") ) 
            room->delete("exits/down");
delete("longtou");  
me = this_player();  
 message_vision(HIG"突然出现咔咔的响声，水位又上了!\n"NOR, me);
}

void on_del()
{
  object me = this_player();

if (!me) return 0;

if (environment(me)!=this_object())
{
delete("longtou");
remove_call_out("on_del");
return 0;
}
  call_out("on_del", 10);
}
