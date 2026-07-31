// mg-room2.c 迷宫房舍
#include <ansi.h>
#include <command.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", CYN "迷宫房舍" NOR);                      
        set("long", "这一座殿堂中供的是汉人塑像，匾上写的是「"HIY"大成至圣先师孔子位"NOR"」，中
间是一个老人，左右各有数十人，分别写著「颜回」、「子路」、「子贡」、
「子夏」、「子张」等名字。你悄声悄气地走了进来。\n");

        set("no_sleep_room", 1);
        set("exits", ([
              "south" : __DIR__"mg-room1",                     
        ]));

        setup(); 
        set("tie_count", 1);
}

void init()
{
       this_player()->set_temp("ketou_times", 50);
       add_action("do_ketou", "ketou");
}

int do_ketou()
{
       int i;
       object me, ob, *inv;
       me = this_player();
       if(!userp(me) || me->is_busy() || me->is_fighting()) return notify_fail("你正忙着呢！\n");               
       if(random(me->query_temp("ketou_times")) == 0 ) {
         me->set_temp("ketou_times", 50);
         message_vision(BLU"突然一团白色物事从黑暗中迅速异常的冲来，冲到离$N约莫一丈之处，猛地\n"+
                           "直立不动，看上去依稀是个人形，火光映照下，只见这鬼怪身披白色罩袍，\n"+
                           "满脸都是鲜血，白袍上也是血迹淋漓，身形高大之极，至少比常人高了五尺。\n"+
                           "静夜看来，恐怖无比。那鬼怪陡然间双手前伸，十根指甲比手指还长，满手\n"+
                           "也都是鲜血。\n"NOR, me);
         message_vision(HIB"那鬼怪桀桀怪笑，尖声道：「我在迷宫里已住了一千年，不许谁来打扰，\n"+
                           "谁叫你们这样大胆？」那鬼怪慢慢转身，双手对着$N，叫道：「给我死！」\n"NOR, me);
         me->start_busy(2);
         if(random(20)>18){
            tell_object(me, HIR "你感觉四肢一麻，不好！\n" NOR );
            tell_room(environment(me), HIR +"只见"+me->name()+"双膝跪倒，然后口吐白漠，翻身不动了！\n" NOR, ({ me }));    
              inv = all_inventory(me);
            for (i = 0; i < sizeof(inv); i++)
               DROP_CMD->do_drop(me, inv[i]);
            me->unconcious();
            message_vision("接着这鬼怪回过身来，抓起$N疾驰而去，片刻间走得无影无踪！\n", me);            
            me->move(__DIR__"shulin1");
            return 1;
         }
         tell_object(me, HIR"你心念一动，马上向后跃出丈远！\n" NOR );
         message_vision(CYN"接着这鬼怪回过身来，疾驰而去，片刻间走得无影无踪！\n"NOR, me);            
       }
       me->add_temp("ketou_times", -1);        
       message_vision("$N跪下来，在孔子像前磕了一个头。\n", me);
       if(random(160-(int)me->query_temp("ketou_times")) == 30 
        && !present("kuaixueshiqing tie", me)
        && query("tie_count") >= 1){
          add("tie_count", -1);
          ob = unew(__DIR__"obj/tie");
          if (!clonep(ob)){
             ob = new("/clone/money/coin")->move(environment(me));
             message_vision("\n突然啪地一声掉下一枚铜钱，落在$N的面前！\n\n", me);
             return 1;
          }
          if( clonep(ob) && ob->violate_unique()){
             destruct(ob);
             ob = new("/clone/money/coin")->move(environment(me));
             message_vision("\n突然啪地一声掉下一枚铜钱，落在$N的面前！\n\n", me);
             return 1;
          }           
          ob->move(environment(me));
          message_vision("\n突然啪地一声掉下一束纸卷，落在$N的面前！\n\n", me);
       }       
       return 1;
}

int valid_leave(object me, string dir)
{
      me->delete_temp("ketou_times");
      return ::valid_leave( me,dir);
} 

int clean_up()
{
        return 0;
}

int count = 40;
void reset()
{
    if (--count == 0) {count = 40; set("tie_count", 1); ::reset();}
}
