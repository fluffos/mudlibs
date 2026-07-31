// qiaoshou.c
#include <ansi.h>

inherit NPC;

string ask_me(object who);

void create()
{
        set("nickname", "女红出众");
        set_name("巧手妹妹", ({ "qiaoshou meimei", "meimei" }) );
        set("gender", "女性" );
        set("age", 16);

        set("long",@LONG
巧手妹妹是大同府附近有名的手编艺人。她
自幼父母双亡，被当地一个编织艺人收养，
学到了一手好的手编技术，因此大家都称她
为“巧手妹妹”，以至于她的真实姓名大家
都不记得了。
LONG );

        set("combat_exp", 1000);
 
        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :)
        }) );

        set("per",35);
        set("str", 20);
        set_skill("unarmed",50);
        setup();
 
        set("inquiry", ([
                "编织" : "编草鞋每次十文铜钱。",
                "bian" : "编草鞋每次十文铜钱。",
                                "qu" : (: ask_me :),
                                "取" : (: ask_me :),
]) );

        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if ( interactive(ob = this_player()) )
        {
                remove_call_out("greeting");
                call_out("greeting", 2, ob);
        }
}
 
void greeting(object ob)
{
        if (ob->query_temp("quest_hlc_ok"))
    {
                tell_object(ob, CYN+this_object()->name()+"说道：您的草鞋我已经编好了，请您来取 (qu) 吧。\n"NOR);
        }
        else command(sprintf("wanfu %s", ob->query("id"))); 
}

int accept_fight(object me)
{
        command("say 你想对小女子做什么？小心我到官府去告你！\n");
        return 0;
}
 
int accept_kill(object me)
{
        command("say 你连小女子都想杀？！哼！\n");
        command(sprintf("say 以后请%s别再麻烦小女子！",RANK_D->query_respect(me)));
                me->set("quest_hlc_hatemm", time()+600+random(600));
        return 0;
}

private void hlc_ok(object me,object ob)
{
        object *inv;
        int i;

        inv = all_inventory(ob);
        if( sizeof(inv)-1 >= 1 ) 
        {
                for(i=0; i<sizeof(inv); i++) 
                {
                        if( inv[i]->name() == "呼啦草" && 
                                inv[i]->query_master() == me->query("id") ) 
                                destruct(inv[i]);
                }
        }

        tell_object(me, "你觉得时间差不多，"+ob->name()+"的草鞋好象快编完了。\n");

        me->delete_temp("quest_hlc_money");
        me->set_temp("quest_hlc_ok", 1);
        ob->stop_busy();
}

int accept_object(object me, object ob)
{
        object npc=this_object();
        object *inv;
        int i, num;

        if (time()<(int)me->query("quest_hlc_hatemm", 1))
        {
                write(CYN+npc->name()+"噘嘴说道：刚才还想杀小女子呢，这会又要找我帮忙？\n"NOR);
                return 0;
        }
        else me->delete("quest_hlc_hatemm");

        if (npc->is_busy())
        {
                write(CYN+npc->name()+"说道：我正在编草鞋，请您先等一会。\n"NOR);
                return 0;
        }

        if (ob->query("money_id"))
        {
                if (!me->query_temp("quest_hlc_money"))
                {
                        if (ob->value()==10)
                        {
                                write(CYN+npc->name()+"说道：好的，请把呼啦草给小女子。\n"NOR);
                                me->set_temp("quest_hlc_money", 1);
                                return 1;
                        }
                        write(CYN+npc->name()+"说道：编草鞋每次十文铜钱。\n"NOR);
                        return 0;
                }
                write(CYN+npc->name()+"说道：啊，收了钱您还想再给，小女子笑纳了！\n"NOR);
                return 1;
        }

        if(!me->query_temp("quest_hlc_money"))
        {
                command("shake");
                write(CYN+npc->name()+"说道：编草鞋每次十文铜钱。。\n"NOR);
                return 0;
        }

        if (ob->name()!="呼啦草") return 0;

        if (ob->query_master() != me->query("id"))
        {
                write(CYN+npc->name()+"说道："+RANK_D->query_respect(me)
                        +"怎么把别人的呼啦草拿来了？\n"NOR);
                return 0;
        }

        inv = all_inventory(npc);
        num=0;

        if( sizeof(inv)-1 >= 1 ) 
        {
                for(i=0; i<sizeof(inv); i++) 
                {
                        if( inv[i]->name() == "呼啦草" && 
                                inv[i]->query_master() == me->query("id") ) 
                                num++;
                  }
        }

        if (!num)
        {
                num++;
                write(CYN+npc->name()+"说道：一把呼啦草只够编个鞋面。\n"NOR);
                return 1;
        }
        else if (num>2)
        {
                command("hehe");
                write(CYN+npc->name()+"说道：给我这么多呼啦草，让我给您编凉席吗？\n"NOR);
                return 0;
        }

        num++;

        write(CYN+npc->name()+"说道：小女子这就帮您编草鞋。\n"NOR);
        message_vision("$N接过$n手中的呼啦草，开始细心地编草鞋。\n", npc, me);

        call_out("hlc_ok",random(3)+4,me,npc);
        npc->start_busy(10);
        return 1;
}

string ask_me(object who)
{
        object xie;

        if (!who->query_temp("quest_hlc_ok"))
        {
                if (!random(3) && who->query("gender")=="男性")
                {
                        command("shy");
                        return "取？娶？您是说要娶小女子吗？\n"
                                +"可惜天神说我不能嫁给玩家，唉……我心领了。\n";
                }
                return 0;
        }

        if (is_busy()) this_object()->stop_busy();

        who->delete_temp("quest_hlc_ok");
        xie=new("/d/huashan/obj/xie");
        xie->set_master(who->query("id"));
        xie->move(who);

        return "给你草鞋，我还特意给您在鞋底绣了您的名字，呵呵。\n";
}

