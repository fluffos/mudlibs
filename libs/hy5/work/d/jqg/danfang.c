// danfang.c 丹房
// Modify By River 99.5.25
inherit ROOM;

#include <ansi.h>
void create()
{
           set("short",HIG"丹房"NOR);
           set("long",@LONG
你打量室中，只见桌上，柜中满列药瓶，壁上一丛丛的挂著无数乾草药，
西首并列三座丹炉(lu)，这间石室自便是所谓丹房了。
LONG
           );
			
	   set("exits",([
               "south": __DIR__"lang2",
           ]));
	   set("item_desc",([
              "lu": "这是公孙谷主炼丹的丹炉，看起来极为普通，但是似乎又有些看上去不对劲。\n",
           ]));
            
	   setup();
}

void init()
{
         add_action("do_tui","tui");
}

int do_tui(string arg)
{   
          object me = this_player();
          if( !arg || arg==" " ) return notify_fail ("你要推什么啊？\n");
          if (arg =="lu")
               return notify_fail("你要推哪边的丹炉啊？\n");
          if (me->query_skill("force", 1) < 120 ) 
               return notify_fail("你深深的吸了口气，用力地推丹炉，无奈内力不够，丹炉丝毫不动！\n");
          if (me->query_str() < 30 ) 
               return notify_fail("你深深的吸了口气，用力地推丹炉，无奈膂力不够，丹炉丝毫不动！\n");
          if( arg=="zhonglu" || arg=="middlelu"){
           if (me->query_temp("jqg/tui"))
                 return notify_fail("你已经把丹炉推好了。还想再推什么？\n");  
               me->set_temp("jqg/tui", 1);
               tell_object(me,"你先将中间的丹炉推开。\n");
               message("vision",me->name() +"中间的丹炉推开。\n"NOR,environment(me), me);
               return 1;
               }
          if (!me->query_temp("jqg/tui")) return 0;
          if( arg == "donglu" || arg == "eastlu" 
           || arg == "westlu" || arg == "xilu" )
               return notify_fail("你要把丹炉推向哪里啊？\n");
          if( arg =="donglu middle" || arg =="eastlu middle" 
           || arg =="donglu zhong" || arg =="eastlu zhong"){
           if (me->query_temp("jqg/tuidong"))
                 return notify_fail("你已经把丹炉推好了。还想再推什么？\n");  
               tell_object(me,"你再将东首的一座丹炉推到中间。\n");
               message("vision",me->name() +"东首的一座丹炉推到中间。\n"NOR,environment(me), me);
               me->start_busy(1);
               me->set_temp("jqg/tuidong", 1);
               return 1;
	       }
 	  if( arg =="xilu east" || arg =="westlu east" 
           || arg =="xilu dong" || arg =="westlu dong"){
           if (! me->query_temp("jqg/tuidong")) return 0;
           if ( me->query_temp("jqg/tuixi"))
                 return notify_fail("你已经把丹炉推好了。还想再推什么？\n");
               tell_object(me,"接着你将西首的一座丹炉推到东首。\n");
               message("vision",me->name() +"将西首的一座丹炉推到东首。\n"NOR,environment(me), me);
               me->start_busy(1);
               me->set_temp("jqg/tuixi", 1);
               return 1;
               }
          if(arg =="zhonglu west" || arg =="middlelu west" 
            || arg =="zhonglu xi" || arg ==" middlelu xi"){
           if (! me->query_temp("jqg/tuixi")) return 0;
               tell_object(me,"然后你将中间的一座丹炉推到西首。\n");
               message("vision",me->name() +"将中间的一座丹炉推到西首。\n"NOR,environment(me), me);
               me->start_busy(1);
               tell_object(me,HIR"\n你的足下一软，却似踏了个空。登时笔直堕下，但觉足底空虚，竟似直堕了数十丈尚未著地。\n\n"NOR);
               message("vision",me->name() +"的足下一软，登时笔直堕下。\n"NOR,environment(me), me);
               me->delete_temp("jqg");
               me->move(__DIR__"eytan");
               tell_object(me,HIR"\n你眼前一片黑暗，扑通一声，已摔入水中，往下急沉，原来丹房之下竟是个深渊。\n\n"NOR);
               message("vision", me->name() +"眼前一片黑暗，扑通一声，已摔入水中。\n",environment(me), me);
             if( me->query_skill("dodge", 1) < 120){
                 me->receive_damage("qi", 200);
                 me->receive_wound("qi", 200);
                 me->unconcious();
                 return 1;
                 }
               return 1; 
               }               
}
