// wuchen.c
#include <ansi.h>
#include <title.h>
inherit NPC;

void create()
{
	set_name("无尘道长", ({"wuchen daozhang", "wuchen", "daozhang"}));
	set("title", HIR"红花会"HIG"二当家"NOR);
	set("nickname", HIC "追魂夺命剑" NOR );
	set("gender", "男性");
	set("age", 52);
	set("long", 
"他就是无尘道人。少年时混迹绿林，劫富济贫，做下了无数巨案，武
功高强，手下兄弟又众，官府奈何他不得。有一次他见到一位官家小
姐，竟然死心塌地的爱上了她。那位小姐却对无尘并没真心，受了父
亲教唆，一天夜里无尘偷偷来见她之时，那小姐说：“你对我全是假
意，没半点诚心。”无尘当然赌誓罚咒。那小姐道：“你们男人啊，
这样的话个个会说。你隔这么久来瞧我一次，我可不够。你要是真心
爱我，就把你一条手膀砍来给我。有你这条臂膀陪着，也免得我寂寞
孤单。”无尘一语不发，真的拔剑将自己的左臂砍了下来。小姐楼上
早埋伏了许多官差，一见都涌了出来。无尘已痛晕在地，哪里还能抵
抗？无尘手下的兄弟们大会群豪，打破城池，将他救出，又把小姐全
家都捉了来听他发落。众人以为无尘不是把他们都杀了，就是要了这
小姐做妻子。哪知他看见小姐，心肠一软，叫众人把她和家人都放了，
自己当夜悄悄离开了那地方，心灰意懒，就此出家做了道人。人虽然
出了家，可是本性难移，仍是豪迈豁达，行侠江湖，被红花会老当家
于万亭请出来做了副手。\n");
	set("attitude", "peaceful");
	set("class", "taoist");
	set("per", 21);
	set("str", 21);
	set("int", 30);
	set("con", 26);
	set("dex", 30);

	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 2000);
	set("max_jing", 2000);
	set("neili", 2500);
	set("max_neili", 2500);
	set("combat_exp", 20000000);
	set("score", 0);

	set_skill("force", 200);
	set_skill("bingchuan-xinfa", 200);
	set_skill("sword", 200);
	set_skill("zhuihun-jian", 200);
	set_skill("luohua-jian", 200);
	set_skill("dodge", 200);
	set_skill("zhuangzi-mengwu", 200);
	set_skill("parry", 200);

	map_skill("force"  , "bingchuan-xinfa");
	map_skill("dodge"  , "zhuangzi-mengwu");
	map_skill("parry"  , "zhuihun-jian");
	map_skill("sword"  , "zhuihun-jian");
  set("chat_chance_combat", 10);
  set("chat_msg_combat", ({
                (: perform_action, "sword.zhuihun" :),
                (: perform_action, "sword.duoming" :),                	
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );
  create_family("红花会", 3, "弟子");
	set("shen_type",1);set("score",5000);setup();
	
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
    
}

void attempt_apprentice(object ob)
{
         if ((string)ob->query("family/family_name")!="红花会" )
        {
         command("say 我不收外派弟子。");
         command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜马善均。");
                return;
        }
        if ((int)ob->query("shen") < 100000) 
        {
                command("say 红花会所作所为都是扶危济困。");
                command("say " + RANK_D->query_respect(ob) + "若能做出" +
                        "几件侠义之事，本座一定收你。");
                return;
        }
        if ((int)ob->query("score")<800)
        {
            command("sigh"+ob->query("id"));
            command("say 你若为本门立点功劳,本座一定收你");
            return;      
        }
        if ((int)ob->query_skill("bingchuan-xinfa", 1) < 50) 
        {
          command("say 你的冰川心法太低了，无法修习我的功夫。");
          command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在冰川心法上多下点功夫？");
                return;
        }
        if((int)ob->query("betrayer")>=1)
        {
                command("say "+RANK_D->query_respect(ob)+"多次背信弃义，我怎可收你。");
                return;
        }
      command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
      command("recruit "+ob->query("id"));
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        {
          ob->set("title",HIR "红花会" NOR + HIY +"堂主" NOR);
//title系统记录玩家title by seagate@pkuxkx
	        ob->set_title(TITLE_RANK, ob->query("title"));
	      }
        return;
}
void re_rank(object student)
{
        student->set("title",HIR "红花会" NOR + HIY +"堂主" NOR);
//title系统记录玩家title by seagate@pkuxkx
	      student->set_title(TITLE_RANK, student->query("title"));
        return;
}
void heal()
{
        object ob=this_object();
        if (ob->query("eff_qi") < ob->query("max_qi"))
        {
                command("exert heal");
                command("enforce 50");
                return;
        }
        if (ob->query("qi") < ob->query("eff_qi"))
        {
                command("exert recover");
                return;
        }
        if (ob->query("jing") < ob->query("eff_jing"))
                command("exert regenerate");
        return;
}

