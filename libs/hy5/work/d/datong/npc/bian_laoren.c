// bian_laoren.c
#include <ansi.h>

inherit NPC;

string ask_me(object who);

void create()
{
        set("nickname", "能工巧匠");
        set_name("手编老人", ({ "shoubian laoren", "laoren" }) );
        set("gender", "男性" );
        set("age", 61);

        set("long",@LONG
这位老人是大同府一家手工艺店的店主。他
的技术老练，据说他还收养了一个女儿并传
授给她编织技巧。如今他似乎正出来干活，
也许是找他帮忙的人太多了吧。
LONG );

        set("combat_exp", 20000);
 
        set("chat_chance", 8);
        set("chat_msg", ({

                (: random_move :)
        }) );

        set("per",20);
        set("str", 30);
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
                tell_object(ob, CYN+this_object()->name()+"说道：草鞋我已经给您编好了，请您来取 (qu) 吧。\n"NOR);
        }
        //else command(sprintf("wanfu %s", ob->query("id"))); 
}

int accept_fight(object me)
{
        command("say 你想对我做什么？我都一把老骨头了！\n");
        return 0;
}
 
int accept_kill(object me)
{
        command("say 连我这老头子都想杀？！\n");
        command(sprintf("say %s别再麻烦我！",RANK_D->query_respect(me)));
                me->set("quest_hlc_hateyy", time()+600+random(600));
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

        tell_object(me, "你觉得"+ob->name()+"的草鞋应该编完了。\n");

        me->delete_temp("quest_hlc_money");
        me->set_temp("quest_hlc_ok", 1);
        ob->stop_busy();
}

int accept_object(object me, object ob)
{
        object npc=this_object();
        object *inv;
        int i, num;

        if (time()<(int)me->query("quest_hlc_hateyy", 1))
        {
                write(CYN+npc->name()+"皱眉说道：刚才还想杀我，这会又找我帮忙？\n"NOR);
                return 0;
        }
        else me->delete("quest_hlc_hateyy");

        if (npc->is_busy())
        {
                write(CYN+npc->name()+"说道：我正在忙，请您先等一会。\n"NOR);
                return 0;
        }

        if (ob->query("money_id"))
        {
                if (!me->query_temp("quest_hlc_money"))
                {
                        if (ob->value()==10)
                        {
                                write(CYN+npc->name()+"说道：好的，请把呼啦草给我吧。\n"NOR);
                                me->set_temp("quest_hlc_money", 1);
                                return 1;
                        }
                        write(CYN+npc->name()+"说道：编草鞋每次十文铜钱。\n"NOR);
                        return 0;
                }
                write(CYN+npc->name()+"说道：啊，您还想再给钱，无功不受禄，我不要。\n"NOR);
                return 0;
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
                        +"怎么把别人的呼啦草拿来了，不太好啊……\n"NOR );
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
                write(CYN+npc->name()+"说道：一把呼啦草只够编个鞋底。\n"NOR);
                return 1;
        }
        else if (num>2)
        {
                command("hehe");
                write(CYN+npc->name()+"说道：您给我这么多干草，让我给您编草帽吗？\n"NOR);
                return 0;
        }

        num++;

        write(CYN+npc->name()+"说道：正好两把草，我就给您编草鞋。\n"NOR);
        message_vision("$N接过$n手中的呼啦草，开始耐心地编草鞋。\n", npc, me);

        call_out("hlc_ok",random(4)+6,me,npc);
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
                        return "娶？您这是哪话说的？我家闺女还不想找婆家……\n";
                }
                return 0;
        }

        if (is_busy()) this_object()->stop_busy();

        who->delete_temp("quest_hlc_ok");
        xie=new(__DIR__"obj/xie");
        xie->set_master(who->query("id"));
        xie->move(who);

        return "给您草鞋，按您说的鞋底有您的名字，呵呵。\n";
}

