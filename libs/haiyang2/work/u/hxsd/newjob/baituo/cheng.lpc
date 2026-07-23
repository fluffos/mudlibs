// ding.c 家丁

inherit NPC;
#include <ansi.h>
int accept_object(object who, object ob);
int ask_job();

void create()
{
        set_name("程管家", ({ "cheng laoban", "cheng", "laoban" }));
        set("age", 25);
        set("gender", "男性");
        set("nickname", HIY"称千金"NOR);
        set("title","白驼山庄管家");
        set("long", "他是一个精明的中年人，眼神中流露的却不仅仅是狡猾，而是歹毒。\n");
        set("attitude", "peaceful");
        set("combat_exp", 20000);
        set("shen", -5000);

        set("str", 20);
        set("int", 12);
        set("con", 24);
        set("dex", 24);
        set("bac", 20);

        set("qi", 900);
        set("max_qi", 900);
        set("jingli", 600);
        set("max_jingli", 600);
        set("neili", 500);
        set("max_neili", 500);
        set("rank", "帮众");

        set_skill("force", 60);
        set_skill("parry", 60);
        set_skill("dodge", 60); 
        set_skill("parry", 60); 
	set_skill("literate", 90); 

//	        create_party("权力帮","帮众",1);

//      carry_object("/clone/misc/cloth")->wear();
//      carry_object(__DIR__"obj/tiecheng")->wield();

        set("inquiry", ([
                "job" : (: ask_job :),
        ]) );

        setup();
}


int ask_job()
{
        mapping party,quest;
        object me, ob;

        me = this_player();
        quest = __DIR__"jyquest"->query_quest();

         if( me->query("family/family_name") != "白驼山派")
            {
                  message_vision("$N对着$n大喝一声：本派弟子才能讨债！\n", this_object(), me);
                return 1;
            }
     
        if (me->query_temp("qljob") && me->query_temp("qljob") == 1)
        {
                command("hmm");
                command("say 是不是对给你的工作不满意？哼！");
                return 1;
        }

        else if (me->query_temp("qljob") && me->query_temp("qljob") == 4)
        {
                command("jump");
                command("say 干的好，长了我们山庄的威风，下去歇歇吧！");
                write("你的经验增加了.\n",);
                write("你的潜能增加了.\n",);
                me->add("potential", 80+random(180));
                me->add("combat_exp", 100+random(300));
                me->add("party/tasks", 2);
                me->delete_temp("qljob");
                me->delete_temp("subject");
                me->delete_temp("money");
                return 1;
        }

        else if ( me->query_condition("jyfail") )
        {
                command("say 让你要个帐都要不来，又不敢杀人，我还怎么让你做事！");
                command("say 你还下去吧，省得我们白驼山庄的脸都被你丢光了！");
                me->delete_temp("qljob");
                me->delete_temp("subject");
                me->delete_temp("money");
                return 1;
        }
        else if ( me->query_temp("qljob"))
        {
                command("say 收完帐不交钱，是不是想吞了呀？");
                return 1;
        }

        command("say " + quest["quest_1"] + "欠我们白驼山庄" + chinese_number(quest["quest_2"]) + "两银子，你去要回来吧。");
        command("say 这张欠单带好，到那甭废话，直接收帐(shouzhang)。");
        command("say 如果" + quest["quest_1"] + "赖着不还，就杀了他，显显我们白驼山庄的威风。");

        me->set_temp("qljob", 1);
        me->set_temp("subject", quest["quest_1"]);
        me->set_temp("money", quest["quest_2"]);
        ob = new(__DIR__"qiandan");
        ob->set("long", "
        欠单
" + quest["quest_1"] + "欠白驼山庄" + chinese_number(quest["quest_2"]) + "两纹银，
口说无凭，立此为证。

        黑老汉、白驼山庄\n");
        ob->move(me);
        return 1;
}

int accept_object(object who, object ob)
{
        mapping myfam;

        if (ob->query("money_id")) 
        {
                if (who->query_temp("qljob") && (who->query_temp("qljob") == 1))
                {
                        command("say 这点钱我就收下了，可是你的活却没有做完！");
                        command("say 还不快去做！");
//                        destruct(ob);
                        return 1;
                }
                else if (who->query_temp("qljob") && (who->query_temp("qljob") == 2 ||who->query_temp("qljob") == 5))
                {
                        command("say 自己收不到帐还想瞒我？你当我是谁？");
                        command("say 这点钱就算你孝敬我的，我有事做再叫你。");
//                        destruct(ob);
                        who->delete_temp("qljob");
                        who->delete_temp("subject");
                        who->delete_temp("money");
                        return 1;
                }
                else if (who->query_temp("qljob") && who->query_temp("qljob") == 3 && ob->value() >= (100 * who->query_temp("money")))
                {
                        command("say 不错不错，干的确实不错，下去休息吧。");
                        message_vision("程管家在帐单上记上一笔，然后把钱放进了钱柜。\n", who);
                        message_vision("你的经验增加了.\n", who);
                        message_vision("你的潜能增加了.\n", who);
                        who->add("potential", 60+random(60));
                        who->add("combat_exp", 80+random(80));
                        who->delete_temp("qljob");
                        who->delete_temp("subject");
                        who->delete_temp("money");
//                        destruct(ob);
                        return 1;
                }
                else if (who->query_temp("qljob") && who->query_temp("qljob") == 3 && ob->value() < (100 * who->query_temp("money")))
                {
                        command("say 就收了这么一点钱，恐怕是你把钱扣下了吧！");
                        command("say 看来你是活的不耐烦了。");
                        return 1;
                }
                else return notify_fail("出现了巫师没有想到的情况，快通知巫师吧。\n");
        }
        else
        {
                return notify_fail("你给我这个干什么?\n");
        }
}
