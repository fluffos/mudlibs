// zjb /2002/3/16/ 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIY"长廊尽头"NOR);
        set("long", @LONG 
尽端还是道钢门，没有钢环，只有个圆形的掣钮,
边缘满布格数，共四十九格，钮的上方还有个红色的圆
点刻在门壁(wall)上。门外两侧各嵌着六颗青光闪亮的
明珠(zhu)，光度虽不强，已足可令两人视物如白昼。 

LONG
        ); 
        set("item_desc", ([ 
          "wall" : "你可以试着蹲(dun)下来仔细看看掣钮!\n",                   
  "zhu" : "夜明珠似乎可以拿(pick)出来!\n", 
                    ]));
        set("exits", ([
                "south" : __DIR__"changlang6",
                      ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
  object me = this_player();
// 1秒后如果没在本ROOM自动取消身上和ROOM里的所有定义 by zjb
call_out("on_quxiao", 1);
        add_action("do_pick", "pick");
    add_action("do_xuan", "xuan"); 
       add_action("do_dun", "dun");
  add_action("do_an", "an");
}
void check_mingzhu()
{
    object me;
    me = this_player();
if(query("mingzhu")==6)
{
// message("channel:chat", HBRED HIB"【海洋】"+me->query_temp("name")+"因为太贪心,拿光了夜明珠，被机关踢出宝库了!\n"NOR,users());
  message_vision(HIC"突然$N的脚底下出现一个洞，$N掉了下去。\n"NOR, this_player());
  this_player()->unconcious();
      me->move("/d/lumaji/pomiao");
}
}
void check_tian()
{
    object room; 
 object me;
      me = this_player();
if (query("tian")!=21)
{
me->delete_temp("tian");
}
if (!query("tian") || query("tian")<0)
{
me->delete_temp("zjbtian");
}    if( (int)query("tian")==21
            &&  !query("exits/enter") ) {
    message("vision", HIR"当刻数二十一经过红点，竟发出轻微异响,,"+ me->name() +"不由想按下去试试。\n",
            this_object() ); 
me->set_temp("tian",1);
                }
} 
void check_di()
{
    object room; 
 object me;
   me = this_player();
if (query("di")!=47)
{
me->delete_temp("di");
}
if (!query("di")||query("di")<0)
{
me->delete_temp("zjbdi");
} 
if (query("di")==47&&me->query_temp("di2"))
{
me->set_temp("zjbok",1);
    message("vision", HIW"当刻数四十七经过红点，竟发出轻微异响,"+ me->name() +"不由想按下去试试。\n",      this_object() ); 
}
 if (query("di")==47&&me->query_temp("di2"))  return 0;
if( (int)query("di")==47
            &&  !query("exits/enter") ) {
        message("vision", HIB"当刻数四十七经过红点，竟发出轻微异响,"+ me->name() +"不由想按下去试试。\n",
            this_object() ); 
me->set_temp("di",1);         
          } 
}

int do_dun()
{
       object me;
        me = this_player();
if (!query("xuanid"))
{
 message_vision(HIR"$N蹲在了掣钮旁边，准备旋掣钮!\n"NOR, this_player()); 
set("xuanid",me->query("id")); 
return 1;
}
if (query("xuanid")==me->query("id"))
return notify_fail("老大，你已经蹲着了!\n");
            write("已经又人蹲着在旋了，你要抢位置呀，先PK他!\n");
return 1;
}
int do_an(string arg)
{
        object me;
        me = this_player();
      if( !arg || arg=="" ) return notify_fail("你要按什么东西!\n");
            if( arg=="掣钮" ) { 
if (me->query_temp("tian")){
me->set_temp("tian2",1);
me->delete_temp("tian"); 
 me->delete_temp("zjbtian");  
me->delete_temp("di2"); 
delete("tian");
delete("di");
  message_vision(HIW"$N用力按下，发出「的」一声脆响。\n"NOR, this_player()); 
return 1;
}
if (me->query_temp("di")){
me->set_temp("di2",1);
me->delete_temp("di");     
delete("tian");
delete("di");
me->delete_temp("zjbdi");message_vision(HIB"$N用力按下，发出「的」一声脆响。\n"NOR, this_player()); 
return 1;
} 
if (me->query_temp("zjbok")){ 
message_vision(BLINK MAG"$N用力按下，发出「喀嚓」一声脆响。\n"NOR, this_player()); 
  call_out("on_zjbok", 1);
return 1;

}
}
}
 int do_pick(string arg)
{
        object zhu, me=this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="zhu" )
                             { 
if(query("mingzhu")<6)
{                                           
  message_vision(
HIR"$N拿下了一颗夜明珠。\n"NOR, this_player());
                        zhu = new(__DIR__"obj/zhu");
                        zhu->move(me);  
add("mingzhu",1);
// message("channel:chat", HBRED HIB"【海洋】"+me->query_temp("name")+"在杨公宝库里偷拿了一颗夜明珠!\n"NOR,users());
  check_mingzhu();
return 1;
                }
                message_vision(
"$N想去拿夜明珠结果发现已经给人拿光了\n", this_player());
                return 1;
        }
        return 0;
}
int do_xuan(string arg)
{
        object me; 
    object room;
    string dir;
             me = this_player();
       if( !arg || arg=="" ) return notify_fail("你要转什么东西!\n"); 
if (query("xuanid") != me->query("id"))
return notify_fail("你没蹲下怎么旋呀!\n");
      if( sscanf(arg, "%s", dir)==1 ) {
    if( dir=="left" ) {    
if (me->query_temp("tian"))
{
me->delete_temp("tian");
}if (me->query_temp("zjbdi"))
{
{
add("di",-1);
 check_di();
 message_vision(HIC"$N缓缓扭动掣钮往左旋,旋回到了第"+ query("di") +"点刻数。\n"NOR, this_player()); 
}
return 1;
}
me->set_temp("zjbtian",1); 
me->delete_temp("zjbdi");
add("tian", 1);
   message_vision(HIC"$N缓缓扭动掣钮往左旋,旋到了第"+ query("tian") +"点刻数。\n"NOR, this_player()); 
                      check_tian();
return 1; 
}

 else if( dir=="right" ) {   
if (me->query_temp("di"))
{
me->delete_temp("di");
}  
if (me->query_temp("zjbtian"))
{
add("tian",-1);
 check_tian();
message_vision(HIC"$N缓缓扭动掣钮往右旋,旋回到了第"+ query("tian") +"点刻数。\n"NOR, this_player());
return 1;
}
if (!me->query_temp("tian2"))
{  
            message_vision(HIR"$N想把掣钮往右旋。\n"NOR, this_player()); 
     message_vision(HIR"突然$N的脚底下出现一个洞，$N掉了下去。\n"NOR, this_player());
me->delete_temp("tian");me->move("/d/lumaji/pomiao");
this_player()->unconcious();
   call_out("on_quxiao", 1);
return 1;
 } 
me->set_temp("zjbdi",1);
me->delete_temp("zjbtian");
add("di", 1);
 message_vision(HIC"$N缓缓扭动掣钮往右旋,旋到了第"+ query("di") +"点刻数。\n"NOR, this_player()); 
       check_di();
        
        return 1;
        }
        else {
            write("你想旋向哪个方向?\n");
            return 1;
        }
}
}
void on_zjbok(object me)
{
    me = this_player();
delete("tian");
delete("di");
delete("xuanid");
me->delete_temp("tian");
me->delete_temp("tian2");
me->delete_temp("di");
me->delete_temp("di2");
me->delete_temp("zjbok");
me->delete_temp("zjbtian");
me->delete_temp("zjbdi");
set("exits/enter", __DIR__"jiguan"); 
        message("vision", HIR"门传来「咔咔」的一声，清脆响亮,门慢慢的打开了。\n",
            this_object() ); 
  call_out("on_guanmen", 10); 
}
void on_guanmen(object room)
{
      message_vision(HIG"突然出现咔咔的响声，钢门又合上了!\n"NOR, this_player());
delete("exits/enter");
}

// 取消所有身上和room的定义 by zjb
void on_quxiao(object me)
{
me = this_player();
 if(!me) 
return 0;

if (this_object()!=environment(me))
{
delete("tian");
delete("di");
delete("xuanid");
me->delete_temp("tian");
me->delete_temp("tian");
me->delete_temp("tian2");
me->delete_temp("di");
me->delete_temp("di2");
me->delete_temp("zjbdi");
me->delete_temp("zjbtian");
me->delete_temp("zjbok");
return 0;
}
call_out("on_quxiao", 1);
}
