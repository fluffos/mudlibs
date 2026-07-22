// qiaobi.c 
// By River 98.08.28
int get_object(object ob);
inherit ROOM;
#include <ansi.h>
void create()
{
       set("short", HIY"峭壁"NOR);
       set("long", @LONG
那峭壁便如一座极大的屏风，冲天而起，峭壁中部离地约二十馀丈处，生
著一块三四丈见方的大石，便似一个平台，石上隐隐刻得有字。极目上望，瞧
清楚是「剑冢」两个大字。
LONG
        );

       set("exits", ([ 
           "southdown"  : __DIR__"shanlu8",
       ]));
   
       set("outdoors", "襄阳");

       setup();
}

void init()
{
        add_action("do_look", "kan");
        add_action("do_look", "look");
        add_action("do_mo", "mo");
        add_action("do_cuan", "cuan");              
}

int do_look(string arg)
{
        object me;
        me = this_player();
 
        if(!arg) return 0;
        if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着哪！\n");
        if ( me->query_temp("shibi1") >= 1)
        return notify_fail("你还没有看够？\n");
        if(arg == "shibi"){
        if( me->query_temp("shibi") >= 10)
           {
            write(HIY"\n你凝神瞧了一阵，突见峭壁上每隔数尺便生著一丛青苔，数十丛笔直排列而上。\n"NOR);            
            me->add_temp("shibi1",1);
            me->start_busy(2);
            return 1;
            }
            message_vision("$N正盯着石壁仔细地研究着。\n", me);                    
            write(HIG"但见石壁草木不生，光秃秃的实无可容手足之处，不知当年那人如何攀援上去。\n"NOR);
            me->add_temp("shibi", 1);
            return 1;
        }             
}         

int do_mo(string arg)
{         
         object me;
         me = this_player();
         
         if (!arg && arg != "qingtai")
             return 0;
         if (me->is_busy() || me->is_fighting())
             return notify_fail("你正忙着哪！\n");
         if (me->query_temp("shibi1"))
          write(HIG"你心念一动，手到最底一丛青苔中摸去，抓出一把黑泥，果然是个小小洞穴。\n"NOR);
          me->delete_temp("shibi");
          me->delete_temp("shibi1");
          me->set_temp("shibi2", 1);
          return 1;
}   

int get_object(object ob)
{
        if(userp(ob))
        return 1;
        return 0;
}

int do_cuan(string arg)
{
          object me= this_player();
          object *inv = deep_inventory(me);
	object *obj;

          if ( !arg ) return 0;
          if (me->is_busy() || me->is_fighting())
                return notify_fail("你正忙着哪！\n");
          if (me->query_temp("shibi2")){
          if ( arg =="up"){
          if (me->query_skill("dodge", 1) < 120 
           && me->query("neili") < 1500)
           return notify_fail(HIM"你紧一紧腰带，提了一口气，窜高数尺，左足踏在第一个小洞之中，跟著窜起，\n"+
                                 "右足对准第二丛青苔踢了进去，软泥迸出，但是只窜上十来丈，已然力气不加，\n"+
                                 "当即轻轻溜了下来。\n"NOR);
          obj = filter_array(inv,(:get_object:));
          if(sizeof(obj)){
          write(HIR"你紧一紧腰带，提了一口气，窜高数尺，左足踏在第一个小洞之中，跟著窜起，\n"+
                   "右足对准第二丛青苔踢了进去，软泥迸出，但是只窜上十来丈，突然发现负重\n"+
                   "过高，已然累的气喘吁吁，砰然一声从高处摔下。\n"NOR);     
          me->unconcious();
          me->move(__DIR__"qiaobi");
          return 1;
          }
          write(HIG"你紧一紧腰带，提了一口气，窜高数尺，左足踏在第一个小洞之中，跟著窜起，\n"+
                   "右足对准第二丛青苔踢了进去，辗转腾挪之际，一口气窜上了平台。\n"NOR); 
          tell_room(environment(me),HIG + me->name() + "在峭壁下运功调息，养足力气，辗转腾挪之际，一口气窜上了平台。\n"NOR, ({ me }));
          me->delete_temp("shibi2"); 
          me->move(__DIR__"pingtai");
          me->receive_damage("jingli", 300);
	  me->receive_damage("qi", 300); 
          me->start_busy(2);  
          tell_room(environment(me), me->name() + "从峭壁下窜了上来。\n", ({ me }));  
          return 1; 
         }
      }
}
