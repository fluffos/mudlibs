// hswz.c 黑石围子
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "黑石围子");
        set("long", @LONG
这个叫做黑石围子的地方其实是个山前的小湖泊。这里非常的奇怪，
他四周两面是大沙漠，一面过去是西域白驼山，往西却是大草原。周围
乱七八糟的有几百个灰褐色的巨石(stone)，象是自然形成的又象是有人
搬来的。
LONG);
        set("resource/water", 1);
        set("exits", ([
            "southeast" : "/d/xingxiu/shamo4",
            "south" : "/d/xingxiu/shamo4",
            "north" : __DIR__"gebi2",
            "southwest" : __DIR__"caoyuan10",
        ]));                 
        set("item_desc", ([
                "stone" : "这里有一块特别大的石头，它后面还有块石碑，
但被这块大石挡了，看不见上面有些什么东西。\n",
        ]));
        set("outdoors", "gaochang");
        setup();
}

void init()
{
        add_action("do_tui", "tui");
        add_action("do_tui", "push");
        add_action("do_kan", "read");
        add_action("do_kan", "look");
}

int do_tui(string arg)
{      
        object me, room;        
        me = this_player();
        room = this_object();       
        if( !arg ) return 0;              
        if( (int)room->query_temp("stone_pushed") ) 
                return notify_fail("你怎么这么喜欢没事推石头？\n");         
        if (arg == "stone" ){        
         if (me->query_skill_mapped("force") != "hamashengong" ){
               me->add("neili", -1500);
               message_vision(HIR "$N运气猛力向巨石一击，结果不但没推开它，反而震伤了自己。\n" NOR, me);
               me->unconcious();
               return 1;
               }
         if (me->query("neili") < 1000 || me->query_str() < 25 ){
               message_vision("$N运起蛤蟆功使劲推了推巨石，无赖力量不够，只好做罢。\n", me);
               me->add("neili", -200);
               return 1;
               }        
      else{
             me->add("neili", -500);
               message_vision(HIG "$N体内蛤蟆功来回运转，口中一叫，双掌推出。\n
只听轰的一声，巨石竟然被$N推开了，露出了后面的石碑。\n" NOR, me);
       if(me->query_skill("hamashengong", 1) < 100)
               me->improve_skill("hamashengong", me->query("int"));
               room->set_temp("stone_pushed", 1);
               call_out("stone_push", 10);
            }                    
       }
        return 1;
}

int do_kan(string arg)
{      
        object me, room;        
        me = this_player();
	room = this_object();      
        if( !arg ) return 0;               
        if( !(int)room->query_temp("stone_pushed") ) 
                return notify_fail("隔着块石头怎么看得见？\n");                 
        if ( me->query_skill_mapped("force") != "hamashengong" )
                return notify_fail("你看了半天，还是不明白那上面写了些什么东西。\n");              
        tell_object(me, HIB "\n 。。。。。。
此处乃入白陀山庄之秘道，尔既然可以推开巨石，
当已有我蛤蟆功功底，可算白陀山转之人。可按
如此走法进入山庄。。。\n    
            白陀山庄庄主西毒欧阳锋\n\n" NOR);  
        message_vision("$N盯着石碑看了半天，脸上露出欣慰的表情，跟着$N脚步转了几转，走进乱石堆里不见了。\n", me);
        me->move("/d/baituo/midao");
        tell_object(me, "你兜兜转转走了半天，发现自己已经身在山洞中。\n");
        return 1;
}

int stone_push()
{
       object room = this_object();
       if(objectp(room)){
		message("vision", "轰的一声，巨石又滚回来挡住了石碑。\n", this_object());
		room->delete_temp("stone_pushed");
         }
}
int valid_leave(object me, string dir)
{
       if( dir != "northwest" && !userp(me) && !me->query_temp("go"))
            return notify_fail("...\n");        
       return ::valid_leave(me,dir);
}
