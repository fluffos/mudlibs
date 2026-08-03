// /u/beyond/obj/chahua3.c
// this is made by beyond
// update 1997.6.30
#include <ansi.h>                     
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIW"落第秀才"NOR,({ "flower", "hua" }) );
         set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "朵");
                set("value", 0);
                set("material", "plant");
                set("long", "这是一朵落第秀才。\n");
                set("wear_msg", "");
                set("no_get",1);
                set("unequip_msg", "$N摘下胸前的$n。\n");
                set("armor_prop/armor", 0);
        }
           
        setup();
}

void init()
{
        add_action("do_jiao", "jiaoshui");
        add_action("do_chu",  "chucao");
}

int wear()
{
        object me = environment();
        int ret;

        message_vision("$N拿出一朵" + this_object()->query("name") + "，戴在胸前。", me);
        if (ret=::wear()) {
                if (me->query("gender") == "男性")
                        message_vision("好一个风流少年郎！\n", me);
                else if (me->query("gender") == "女性")
                        message_vision("好一个美丽俏佳娃！\n", me);
                else
                        message_vision("好一个不三不四的家伙！\n", me);
        }
        return ret;
}

int do_jiao()
{
        object me = this_player();
        object weapon;
        object haoke;
        object piao;
        
        if (me->is_busy()) return notify_fail("你现在正忙着呢！\n");
        if (me->query_temp("mark/ok")) return notify_fail("你已经干完了，还在这里干吗？想把花浇死呀？\n");
        if (me->is_fighting()) return notify_fail("你正在战斗中，无法专心干活！\n");
        if (me->query_temp("yanpopo")!= 2) return notify_fail("你还没有去要工具，怎么干活呀？\n");
        
        if (!objectp(weapon = me->query_temp("weapon")) || weapon->query("id")!= "piao")
                return notify_fail("你想用什么来浇花，用手吗？\n");
        if((int)me->query("combat_exp")  > 30000 )
        {
                if(!me->query_temp("killke"))
                {
                        if((int)me->query_temp("mark/次") > (5 + random(5)) )
                        {
                            haoke = new("/d/mr/npc/haoke");
                            if(!haoke)
                                return notify_fail("系统出错，请通知巫师。\n");
                            haoke->set_temp("target",me->query("id"));
                            haoke->move(environment(me));
                            
                            tell_object(me,"你正在用心浇花，忽然一个江湖豪客闯了进来，一把抢过你的水瓢，恶狠狠的问道：慕容家的人呢？出来受死！\n");
                            piao = present("piao", me);
                            piao->move(haoke);
                            haoke->kill_ob(me);
                            me->kill_ob(haoke);
                            me->set_temp("killke",1);                   
                        }
                }
        }
        if((int)me->query_temp("mark/次") > (10 + random(10)) )
        {
	    message_vision(RED"$N觉得水已经浇的差不多了，可以回去复命了。\n"NOR, me);
            me->delete_temp("mark/次");
            me->delete_temp("yanpopo");     
            me->set_temp("mark/ok",1);
            return 1;
        }
        else
        {
            me->start_busy(1);
            me->receive_damage("jingli",random(5)+2);
            me->receive_damage("qi",random(5)+2);       
            me->add_temp("mark/次",1);
            message_vision("$N从水缸中舀了瓢水，小心翼翼的把水浇在「落地秀才」上。\n", me);
        }
        
        return 1;
}
