#include <ansi.h> 
 
inherit ITEM; 
 
void create() 
{ 
        set_name(HIC"波音767客机"NOR, ({"boeing 767","plane"})); 
         set("long", HIC"这是一架波音767飞机，你可以劫持(rob)它。\n"NOR)
;
        set("weight",1000000000); 
        set("no_drop", 0); /*"这么危险的东西怎么能随便丢弃呢？\n"); */
        set("no_get",1);
        set("value",0); 
        set("unit", "架"); 
 
        setup(); 
} 
 
void init() 
{ 
        add_action("do_rob","rob"); 
        add_action("do_aim","aim"); 
} 
 
int do_rob(string arg) 
{ 
        if (!arg || (arg != "plane" && arg != "boeing 767"))
        {
                tell_object(this_player(),"你要劫持什么？\n");
                return 1;
        }
        if (this_object()->query_temp("robbed"))
                return notify_fail("这架飞机已经被劫持了！\n");
        message("vision",HIR"◎据传一架波音767被"+this_player()->query("name")+"劫持了！\n" NOR, users());  
        tell_object(this_player(),"你要让这架飞机飞到哪(aim)？\n");
        this_object()->set_temp("robbed",1);
        return 1;        
} 
 
int do_aim(string arg) 
{ 
        object me, ob; 
 
        me= this_player();
        if (!arg || arg != "wtc") return notify_fail("你要瞄准哪个目标？\n"); 
        ob=this_object(); 
        if ( !ob->query_temp("robbed") ) return notify_fail("这架飞机又不是你的！\n");
        if (this_object()->query_temp("aimed"))
                return notify_fail("这架飞机已经有目标了！\n");
        this_object()->set_temp("aimed",1); 
        message("vision",HIR "◎据传被"+me->name()+"劫持的波音767正在向纽约飞去！”\n" NOR, users());  
        tell_object(me,"你开始驾驶飞机飞向世界贸易中心......\n");
        call_out("do_shoot",5,me);
        return 1;        
} 
 
int do_shoot(object me) 
{ 
        object room;  
        int i;

        message("vision",BNK + HIR"◎被"+me->query("name")+"劫持的波音767撞到了世界贸易中心大楼上！\n" NOR, users());  
        this_object()->set_temp("shoot", 2);
        room = find_object("/u/icer/wtc");
        
        if ( ! i= room->query_temp("zhadiao") )
                room->set_temp("zhadiao",1);
        else room->set_temp("zhadiao",i+1);
        tell_room(room, HIR "一架飞机冲着"+room->query("short")+"飞了过来。\n" NOR); 
        tell_room(room,"飞机正撞在"+room->query("short")+"楼身上！\n");  
        room->set("short",HIR"被撞出"+chinese_number(room->query_temp("zhadiao"))+"个洞的"HIC"世界贸易中心"NOR);
        if (room->query_temp("zhadiao") >= 5)
        {
                room->set("short",HIR"被撞成废墟的"+HIC+"世界贸易中心"NOR);
                message("vision",BNK + HIG"\n\n\n世界贸易中心塌掉了！！！\n" NOR, users());  
        }
        me->move(room);
        destruct(this_object());        
        return 1; 
 
} 


