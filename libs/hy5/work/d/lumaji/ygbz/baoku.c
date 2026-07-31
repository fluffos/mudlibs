// zjb /2002/3/15/
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "小宝库");
        set("long", @LONG  
这是一个宽阔的密封地室，室顶四角均有通气口，两边 
平排放置共十多个该是装载奇珍异宝的箱子(xiang)，贴
墙有几十个兵器架，放满各种，兵器，但都只是普通货色
，且全部都生锈发霉，拿去送人也没有人要。
LONG
        ); 
        
set("objects", ([
		__DIR__"obj/corpse" : 2,
	]));        
        set("item_desc", ([ 
          "xiang" : "箱子里有很多珍珠财宝，你要拿(na)出来吗?\n",      
                          ]));
        set("exits", ([
                "out" : __DIR__"langdao6",
                      ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
  object me = this_player(); 
call_out("on_jinbaoku", 1);
    add_action("do_na", "na"); 
        add_action("do_fan", "fan"); 
     }
void check_tishi()
{
    object room;
            message("vision", HIR"你在拿金票的时候突然发现箱底的板似乎可以翻!。\n",
            this_object() );
}
int do_na(string arg)
{
        object tg, me=this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="箱子")
                             {  
if(query_temp("natg")){ 
   message_vision("$N想去拿金票结果发现已经给人拿光了\n", this_player());
     return 1;
 }
                                message_vision(
HIY"$N在箱子里拿了一叠金票放到怀里!\n"NOR, this_player());
                    tg = new(__DIR__"obj/tg");
                        tg->move(me);   
set_temp("natg",1);
//message("channel:chat", HBRED HIW"【海洋】"+me->query("name")+"在杨公宝库里偷拿了一叠金票!\n"NOR,users()); 
if (random(10)<3)
{
  check_tishi();  
}
return 1;
                }
        return 0;
}
int do_fan(string arg)
{
        object me; 
    object room;
    string dir;
             me = this_player();
       if( !arg || arg=="" ) return notify_fail("你要翻什么东西!\n");
      if( sscanf(arg, "%s", dir)==1 ) {
    if( dir=="箱子" ) {
   message_vision(HIY"$N箱底的盖子一翻，发现箱子下面另有一番天地!。\n"NOR, this_player());  
        set("exits/down", __DIR__"baoku2");
call_out("on_guan", 5);
              return 1;
}
         else {
            write("你想翻什么东西?\n");
            return 1;
        }
}
} 
void on_guan(object room)
{
      message_vision(HIG"突然出现咔咔的响声，箱底又合上了!\n"NOR, this_player());
delete("exits/down");
}

void on_jinbaoku(object room)
 {
  object me = this_player(); 
me->set_temp("jinbaoku",1); 
 message_vision(HIC"$N眨眼一看，呆了一呆，难道闻名天下的杨公宝藏只有这么点吗?\n"NOR, this_player()); 
}
