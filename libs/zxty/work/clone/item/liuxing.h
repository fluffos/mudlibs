#include <ansi.h>

void init()
{
                object me = this_player();
                add_action("block_cmd","beg",1);
                add_action("block_cmd","steal",1);
                add_action("block_cmd","sleep",1);
                
                add_action("do_go","go");
                add_action("do_dig","digging",1);
                
                //this_player()->set_temp("marks/守卫", 1);

}



int block_cmd()
{
                object ob = this_object();
                if ( ob->query("定做/liuxing") ){
                write("由于刚出现过流星，附近有不少村民围观，你还是收敛点吧！\n");
    return 1;
        }
}

int do_dig()
{
                object obj,ob = this_object(),me = this_player();
                
                if ( !ob->query("定做/liuxing") )
                return 0;       

    if ( !(present("tie qiao", me)) && !(present("tie chan", me)))
        return notify_fail(YEL"\n没有工具你挖得动吗？！\n"NOR);

    if( me->is_busy() || me->is_fighting() ) 
        return notify_fail("你正忙着呢！\n");     
        
                if ( me->query("jing") < 15 )
                return notify_fail("你实在太累了，歇歇吧！\n"); 
                
                if ( me->query("jing") < 20 && random(2)==1 )
                return notify_fail("你实在太累了，歇歇吧！\n");
                        
                message_vision("$N抡起铁锹，开始一阵猛敲乱砸。\n", me);      
                if ( random(5000)==1 && me->query_int() > 300 && !ob->query("hanzhu") )//获得陨铁

                {
                                obj=new("/clone/item/hanzhu");
                                obj->move(me);
                                ob->set("hanzhu",1);
                                message_vision(HIC"$N正挖间忽然碰到一个柔韧无比的翠绿色竹体，刨出来一看，赫然是"+obj->query("name")+"！\n"NOR, me);
                                write(HIG"你竟然发现了极其难得一见的寒丝羽竹，简直欣喜若狂，兴奋无比！\n"NOR);          
                                return 1;
                }   
                                
                if ( random(20)==1 && me->query_int() > 250 && !ob->query("yuntie") )//获得陨铁

                {
                                obj=new("/clone/item/ironstone");
                                obj->move(me);
                                ob->set("yuntie",1);
                                message_vision(HIC"$N正挖间忽然碰到一个异常坚硬的物体，刨出来一看，赫然是一大块"+obj->query("name")+"！\n"NOR, me);
                                write(HIG"你竟然发现了极其难得一见的外星陨铁，简直欣喜若狂，兴奋无比！\n"NOR);          
                                return 1;
                }
                
                if ( random(10)==1 && me->query_int() > 200 )//获得玄铁
                {
                                obj=new("/clone/item/xuantie");
                                obj->move(me);
                                message_vision("$N的榔头忽然被一物碰出点点火星，刨出来一看，竟然是块"+obj->query("name")+"！\n", me);
                                return 1;
                }
                
                                if ( random(888)>885 && me->query_int() > 100 )//获得玄铁
                {
                                obj=new("/clone/item/zizhu");
                                obj->move(me);
                                message_vision("$N的榔头忽然被一物碰出点点火星，刨出来一看，竟然是根"+obj->query("name")+"！\n", me);
                                return 1;
                }
                
                if ( random(199)>170 )//获得普通矿石
                {       
                                if (random(2)==1)
                                obj=new("/clone/item/iron-ore");
                                else obj=new("/clone/item/copper-ore");
                                obj->move(me);
                                message_vision("$N似乎挖到了什么东西，刨出来一看，竟然是块"+obj->query("name")+"！\n", me);
                                return 1;
                }
                
                me->receive_damage("jing", 15 + random(10) );
                me->start_busy(1);
                return 1;
}

