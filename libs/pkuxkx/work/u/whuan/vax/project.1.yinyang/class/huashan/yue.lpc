 // que.c 岳不群
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("岳不群",({"yue buqun","yue"}));
	set("nickname", RED "君子" NOR + "剑");
        set("title", YEL "华山派" NOR + GRN "第十八代" NOR + YEL "掌门" NOR);
        set("long",
                "华山掌门岳不群，\n"
                "他今年四十多岁，人称君子剑，素以温文尔雅著称。\n");
        set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 26);
        set("int", 30);
        set("con", 26);
        set("dex", 28);
        set("max_qi", 1200);
        set("max_jing", 800);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 50);
        set("combat_exp", 3000000);
        set("score", 50000);

        set_skill("force",250);
        set_skill("zixia-shengong", 350);
        set_skill("huashan-xinfa", 250);
	set_skill("cuff", 250);
	set_skill("poyu-quan", 250);
	set_skill("strike", 250);
	set_skill("hunyuan-zhang", 250);
        set_skill("dodge", 250);
        set_skill("huashan-shenfa", 250);
//      set_skill("taiji-quan", 150);
        set_skill("parry", 250);
        set_skill("sword", 250);
        set_skill("huashan-jianfa",250);
        set_skill("literate", 150);

	map_skill("cuff", "poyu-quan");
	map_skill("strike", "hunyuan-zhang");
        map_skill("force", "zixia-shengong");
        map_skill("dodge", "huashan-shenfa");
//      map_skill("unarmed", "taiji-quan");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");

	prepare_skill("cuff", "poyu-quan");
	prepare_skill("strike", "hunyuan-zhang");

        create_family("华山派",18,"掌门");
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/baishan")->wear();
}
void attempt_apprentice(object ob)
{
        if ((string)ob->query("family/family_name")!="华山派")
{
                command("say 你非我派弟子，我不能收你。");
                return ;
}
        if((string)ob->query("gender")!="男性")
          {
           command("say 我不受女弟子。姑娘，你还是拜我的内子吧！");
           return;
          }
        if((string)ob->query("gender")=="男性")
          {
               if ((int)ob->query("max_neili") <200) {
                       command("say 我华山派原有剑宗、气宗之争。最终气宗为首。")
;
                       command("say " + RANK_D->query_respect(ob) +
                               "是否还应该多练练内力？");
                       return;
               }
               if ((int)ob->query("score") < 500)
                  {
                   command("sigh "+ob->query("id"));
                   command("say 你对本门的贡献太少了，我不能传授你更高深的功夫了!");
                   return;
                  }
               if ((int)ob->query("shen") < 1000) {
                       command("say 学武之人，德义为先，功夫的高低倒还在其次，未
练武，要先学做人。");
                       command("say 在德行方面，" + RANK_D->query_respect(ob) +
                               "是否还做得不够？");
                       return;
               }
           command("say 好吧，小兄弟！我就收下你了！\n");
           command("say 你今后可要惩恶扬善，旷扶正义！绝不可为非作歹，否则为师绝
不会放过你的！\n");
           command("recruit "+ob->query("id"));

           }
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
	        if (this_player()->query("shen")<10000)
        	{
                	ob->set("title",GRN "华山派" NOR + YEL +"剑客" NOR);
			return;
                }
        	else 
		{
        	        ob->set("title",GRN "华山派" NOR + YEL +"剑侠" NOR);
			return;
        	}

}

void re_rank(object student)
{
	        if (this_player()->query("shen")<10000)
        	{
                	student->set("title",GRN "华山派" NOR + YEL +"剑客" NOR);
			return;
                }
        	else 
		{
        	        student->set("title",GRN "华山派" NOR + YEL +"剑侠" NOR);
			return;
        	}
}

int accept_object(object me,object ob)
{
	object jian;
	if (ob->query("id") == "heimuya tu")
		{
			command("say 多谢这位" + RANK_D->query_respect(me) + "把这幅图带了回来，这把碧水剑本来是准备给小女作生日礼物的，就送给你作个纪念吧！\n");
			tell_object(me,HIG "你的道德上升了！\n" NOR);
			me->add("shen",5000);
			jian = new("/d/riyuejiao/obj/bishuijian");
			jian->move(me);
			message_vision("岳不群给了$N一把" + HIG "碧水剑" NOR + "。\n",me);
                          this_object()->start_busy(3);
                          call_out("destroying",1,ob);
                          return 1;
		}
	return 0;
}

int destroying(object ob)
{
        destruct(ob);
        return 1;
}
