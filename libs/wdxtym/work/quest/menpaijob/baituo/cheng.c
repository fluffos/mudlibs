// ding.c 家丁

inherit NPC;
#include <ansi.h>
int accept_object(object who, object ob);
int ask_job();
int ask_fail();
string ask_fangqi();
string ask_job2();
string ask_fangqi2();
void create()
{
        set_name("程管家", ({ "cheng laoban", "cheng", "laoban" }));
        set("age", 25);
        set("gender", "男性");
        set("nickname", HIY"称千金"NOR);
        set("title","白驼山庄管家");
        set("long", "他是一个精明的中年人，眼神中流露的却不仅仅是狡猾，而是歹毒。\n");
        set("attitude", "peaceful");
        set("combat_exp", 5000000);
        set("shen", -5000);
set("no_get",1);
        set("str", 200);
        set("int", 42);
        set("con", 44);
        set("dex", 44);
        set("bac", 40);

        set("qi", 9000);
        set("max_qi", 9000);
        set("jingli", 600);
        set("max_jingli", 6000);
        set("neili", 11500);
        set("max_neili", 11500);

	set("combat_exp", 8500000);
	set("score", 200000);

	set_skill("force", 250);
	set_skill("unarmed", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("strike",170);
	set_skill("hand",170);
	set_skill("training",300);
	set_skill("staff", 250);
	set_skill("hamagong", 300);
	set_skill("chanchu-bufa", 300);
	set_skill("shexing-diaoshou", 300);
	set_skill("lingshe-zhangfa", 300);
	set_skill("hamashengong", 300);
	
	map_skill("strike", "hamashengong");
	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("unarmed", "shexing-diaoshou");
	map_skill("hand", "shexing-diaoshou");
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "reserve" :),
                (: perform_action, "staff.saoluoye" :),
                (: perform_action, "staff.shoot" :),
                (: perform_action, "staff.saoluoye" :),
                (: command("unwield shengzhang") :),
                (: command("unwield shengzhang") :),
                (: command("wield shengzhang") :),
                (: command("wield shengzhang") :),
                (: perform_action, "strike.hama" :),                
                (: perform_action, "strike.hama" :),                
                (: perform_action, "hand.diaoshou" :),                
                (: perform_action, "hand.diaoshou" :),                
        }) );
	create_family("白驼山派",1, "大管家");


        set("inquiry", ([
                "job" : (: ask_job :),
                "fangqi" : (: ask_fangqi :),
		 "work"   : (: ask_job2 :),
		 "牧蛇"   : (: ask_job2 :),
         "fangqi": (: ask_fangqi2 :),
         "放弃"  : (: ask_fangqi2 :),
                "失败" : (: ask_fail() :),
                "fail" : (: ask_fail() :),
        ]) );
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 800);
        set_temp("apply/damage", 850);

        setup();
	carry_object("/d/baituo/obj/shenshezhang")->wield();
	carry_object("/clone/misc/cloth")->wear();

}



int ask_job()
{
        mapping party,quest;
        object me, ob;
int exp,pot;
        me = this_player();
        quest = __DIR__"jyquest"->query_quest();

         if( me->query("family/family_name") != "白驼山派")
            {
                  message_vision("$N对着$n大喝一声：本派弟子才能讨债！\n", this_object(), me);
                return 1;
            }
      if( (int)me->query_skill("hamagong",1) < 50)
            {
                message_vision("$N对着$n大喝一声：你的本门内功不够！\n", this_object(), me);
                return 1;
            }
if ((int)me->query_condition("guojob2_busy"))
           {
                      message_vision("$N对着$n说:现在没有任务,你等会再来吧!\n", this_object(), me);
                      return 1;
            }     
        if ((int)me->query_condition("menpai_busy"))  
            {
                      message_vision("$N对着$n摇了摇头说：现在没你的事,等会再来!\n", this_object(), me);
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
                write("你的修为增加了.\n",);
                write("你的潜能增加了.\n",);
          exp=330+random(350);
          pot=280+random(250);
	   tell_object(me,HIW"你被奖励了：\n" + 
                       chinese_number(exp) + "点实战修为\n" +
                       chinese_number(pot) + "点潜能\n"+
                       NOR);
                me->add("potential", pot);
                me->add("combat_exp", exp);
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
        me->apply_condition("menpai_busy",5);
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
int exp,pot;
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
          exp=250+random(100);
          pot=150+random(100);
	   tell_object(who,HIW"你被奖励了：\n" + 
                       chinese_number(exp) + "点实战修为\n" +
                       chinese_number(pot) + "点潜能\n"+
                       NOR);
                        who->add("potential", pot);
                        who->add("combat_exp", exp);
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
string ask_fangqi()
{
         object me;
         me = this_player();
         if(me->query_temp("qljob")< 1)
         return "你没有领任务,跑这里瞎嚷嚷什麽?";
         me->delete_temp("qljob");
         me->delete_temp("subject");
         me->delete_temp("money");
         me->add("combat_exp",-150);
         me->add("potential",-80);
         me->apply_condition("jyfail",0);
//         return notify_fail("你给我这个干什么?\n");
//         command("没关系,下次继续努力 。");
         return "没关系,下次继续努力 。";
}


string ask_fangqi2()
{
         object me;
         me = this_player();
         if( me->query("family/family_name") != "白驼山派")
       return "你会做这个吗?";
         if( me->is_busy())
       return "你正忙着呢!";
         if( me->is_fighting())
       return "你正忙着呢!";

         if(!me->query_temp("bt2_song"))
         return "我叫你去牧蛇过吗?";
         me->apply_condition("bt2_busy",5);
         me->delete_temp("bt2_song");
         return "没关系,下次继续努力 。";
}

string ask_job2()
{     object wang,ob;
      object *team;
object obj;
          int i=0,count=0,minexp,maxexp;
      string where;
          wang =this_object();
          ob=this_player();
          
         if( ob->query("family/family_name") != "白驼山派")
       return "你会做这个吗?";
         if( ob->is_busy())
       return "你正忙着呢!";
         if( ob->is_fighting())
       return "你正忙着呢!";

  if ( (int)ob->query_condition("bt2_busy")>=1)  
       return "你刚要过任务，等会再来。";

	if( ((int)ob->query_skill("hamagong", 1)) < 10 )
		return "你的本门内功尚未纯熟！";
		          
  if (interactive(ob) && ob->query_temp("bt2_song") )  
       return "上次叫你牧的蛇呢?";
          ob->set_temp("bt2_song","白驼蛇场");
          ob->apply_condition("bt2_busy",3);
          message_vision(HIY"\n$N挥挥手，一个蛇奴抓了一条蛇给你。\n"NOR,this_object());
          command("say 你帮我把这条蛇带出去放牧,并送到白驼蛇场。");
          ob->start_busy(2);
        obj = new(__DIR__"gongzi");
       obj->move(environment(ob));
        obj->set_temp("host",ob->query("id"));
        obj->set_leader(ob);
        message_vision("$N认定了$n。\n",obj,ob);
          return "一定要小心照看我们养的宝蛇。。";   
}

int ask_fail()
{
        object me = this_player();
       
        if (me->query_temp("qljob")) {
                command("sigh");
                command("say 下次不准有失！不然庄法处置!");
                me->apply_condition("menpai_busy",6);
                        me->delete_temp("qljob");
                        me->delete_temp("subject");
                        me->delete_temp("money");

                return 1;
                }
}
