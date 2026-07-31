// zjb /2002/3/15/
#include <ansi.h>
inherit ROOM;
int do_pick(string arg);
int do_la(string arg); 
int do_zhuan(string arg);
void create()
{
        set("short", "廊道尽端");
        set("long", @LONG 
尽端是道钢门(men)，还有个钢环，门外两侧各嵌着
六颗青光闪亮的明珠(zhu)，光度虽不强，已足可令两人
视物如白昼,门侧左壁光滑的花岗石壁(wall)似乎被人以
匕首一类的东西硬刻出一行字。 

LONG
        ); 
        set("item_desc", ([ 
          "men" : "这扇钢门的钢环似乎可以拉出来!\n",                     "zhu" : "夜明珠似乎可以拿(pick)出来!\n", 
          "wall" : HIB"「高丽罗刹女曾到此地」!\n"NOR,        ]));
        set("exits", ([
                "south" : __DIR__"langdao",
                      ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
  object me = this_player();
        add_action("do_pick", "pick");
        add_action("do_la", "la"); 
        add_action("do_zhuan", "zhuan");
}
void check_mingzhu()
{
    object me;
    me = this_player();
if(query("mingzhu")==6)
{
  message("channel:chat", HBRED HIW"【海洋】"+me->query("name")+"因为太贪心,拿光了夜明珠，被机关踢出宝库了!\n"NOR,users());
  message_vision(HIC"突然$N的脚底下出现一个洞，$N掉了下去。\n"NOR, this_player());
  this_player()->unconcious();
      me->move("/d/lumaji/pomiao");
}
}
void check_zhuanmen()
{
    object room;
    if( (int)query("zhuanmen")==3
            &&  !query("exits/enter") ) {
        message("vision", HIR"门传来「的」的一声，清脆响亮,门慢慢的打开了。\n",
            this_object() );
        set("exits/enter", __DIR__"langdao2");
             delete("zhuanmen");
this_player()->delete_temp("lamen");
  call_out("on_guanmen", 5);
    }
}
int do_la(string arg)
{
        object me;
        me = this_player();
      if( !arg || arg=="" ) return notify_fail("你要拉什么东西!\n");
            if( arg=="钢环" ) {
             write(HIB"你一把将门环拉後，露出连着钢环的钢索。 \n"NOR); 
         write(HIC"门环似乎可以往左右转动，到底转哪边好呢? \n"NOR);
             this_player()->set_temp("lamen", 1);
             return 1;
       }
}
 int do_pick(string arg)
{
        object zhu, me=this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="zhu" )
                             { 
if(query("mingzhu")<6)
{                                             message_vision(
HIR"$N拿下了一颗夜明珠。\n"NOR, this_player());
                        zhu = new(__DIR__"obj/zhu");
                        zhu->move(me);  
add("mingzhu",1);
//message("channel:chat", HBRED HIB"【海洋】"+me->query("name")+"在杨公宝库里偷拿了一颗夜明珠!\n"NOR,users());
  check_mingzhu();
return 1;
                }
                message_vision(
"$N想去拿夜明珠结果发现已经给人拿光了\n", this_player());
                return 1;
        }
        return 0;
}
int do_zhuan(string arg)
{
        object me; 
    object room;
    string dir;
             me = this_player();
 if (!me->query_temp("lamen")) 
return 0;
      if( !arg || arg=="" ) return notify_fail("你要转什么东西!\n");
      if( sscanf(arg, "%s", dir)==1 ) {
    if( dir=="left" ) {
if (query("zhuanmen")>3) {
      message_vision(HIC"$N把门环往左转了一转。\n"NOR, this_player()); 
  message_vision(HIC"突然$N的脚底下出现一个洞，$N掉了下去。\n"NOR, this_player());
 this_player()->delete_temp("lamen");
  this_player()->move("/d/lumaji/pomiao");
 this_player()->unconcious();
delete("zhuanmen");
}
   message_vision(HIC"$N把门环往左转了一转。\n"NOR, this_player()); 
            add("zhuanmen", 1); 
            check_zhuanmen();
return 1;
}
 else if( dir=="right" ) {
                     
            message_vision(HIC"$N把门环往右转了一转。\n"NOR, this_player()); 
     message_vision(HIC"突然$N的脚底下出现一个洞，$N掉了下去。\n"NOR, this_player());
this_player()->delete_temp("lamen");
       this_player()->move("/d/lumaji/pomiao");
this_player()->unconcious();
 
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
      message_vision(HIG"突然出现咔咔的响声，钢门又合上了!\n"NOR, this_player());
delete("exits/enter");
}


