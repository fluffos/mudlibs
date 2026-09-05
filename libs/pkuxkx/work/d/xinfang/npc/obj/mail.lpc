//mail
//Made By jason@mudnow.com
//2000-5.-6
#include <ansi.h>

inherit ITEM;
int start_decay(int time);
int decay(object);

void create()
{
        set_name("信",({"xin jian","mail","xin"}));
        set("long","一封加急信件。\n");
        set("unit","封");
        setup();
}

int give_mail(object target,object ppl)
{
        object me=this_object();
        if(!target||!ppl) return 0;
        if(target->query("id")!=me->query("songxin/target_id")||
        target->query("name")!=me->query("songxin/target_name")||
        target->query("id")!=ppl->query("songxin/target_id")||
        target->query("name")!=ppl->query("songxin/target_name"))
                return 0;
        else
        {
                if(target->query("start_room")!=base_name(environment(target)))
                        return 0;
                if((time()-me->query("songxin/start_time"))<me->query("songxin/all_time"))
                {
                         int ereward,breward,preward;
                        message_vision("$N笑呵呵的迎上来：总算来了，谢谢这位"+RANK_D->query_respect(ppl)+"\n",
                        target);
                        ereward=(10+random(10))*(ppl->query("songxin/base_v"));
                         preward=(10+random(8))*(ppl->query("songxin/base_v"));
                        breward=(300+random(200))*(ppl->query("songxin/base_v"));
                        ppl->add("combat_exp",ereward);
                         ppl->add("potential",preward);
                        ppl->add("balance",breward);
                        message("vision",HIY"你得到了"+chinese_number(ereward)+"点经验的奖励。\n"
                         "你得到了"+chinese_number(preward)+"点潜能的奖励。\n"
                        "你得到了"+chinese_number(breward/100)+"两银子的奖励。\n"NOR,ppl);
                        ppl->set("songxin/ok",1);
                        destruct(me);
                        return 1;
                }
                else
                {
                        int ereward,breward;
                        message_vision("$N皱了皱眉头：你是爬过来的么！？\n",target);
                        command("heng");
                        ereward=6+random(10)*(ppl->query("songxin/base_v"));
                        breward=250+random(100)*(ppl->query("songxin/base_v"));
                        ppl->add("combat_exp",ereward);
                        ppl->add("balance",breward);
                        message("vision",HIR"你得到了"+chinese_number(ereward)+"点经验的奖励。\n"
                        "你得到了"+chinese_number(breward/100)+"两银子的奖励。\n"NOR,ppl);
                        ppl->set("songxin/ok",2);
                        destruct(me);
                        return 1;
                }
        }
        
}

int start_decay(int time)
{
        remove_call_out("decay");
        call_out("decay",time,this_object());
        return 1;
}

int decay(object ob)
{
        message_vision("$N在风吹雨打下破损的不成样子了。\n",ob);
        destruct(ob);
        return 1;
}
