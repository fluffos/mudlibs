// feng.c 风清扬
inherit NPC;
#include <ansi.h>
#include <title.h>
inherit F_MASTER;
void consider();
void heal();
void create()
{
        set_name("风清扬",({"feng qingyang","feng"}));
                set("long",
                "华山高人，\n"
                "他今年六十多岁。\n");
        set("nickname", RED "剑魔" NOR);
        set("title",GRN "华山派" NOR + YEL "隐侠" NOR);
        set("gender", "男性");
        set("age", 65);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 46);
        set("int", 40);
        set("con", 46);
        set("dex", 48);
        set("per", 260);
        set("max_qi", 15800);
        set("qi", 15800);
        set("max_jing", 10800);
        set("neili", 16000);
        set("feilong", 1);
           set_weight(2000000);
        set("max_neili", 16000);
        set("jiali", 350);
        set("combat_exp", 15000000);
        set("score", 100000);
         set_skill("force",350);
         set_skill("huashan-neigong", 380);
        set_skill("dodge", 400);
        set_skill("huashan-shenfa", 380);
	set_skill("cuff", 400);
	set_skill("poyu-quan", 350);
	set_skill("huashan-jianfa", 350);
	set_skill("strike", 350);
	set_skill("hunyuan-zhang", 350);
//      set_skill("taiji-quan", 150);
        set_skill("parry", 380);
        set_skill("sword", 420);
        set_skill("dugu-jiujian",400);
//      set_skill("taoism", 150);
        set_skill("literate", 300);
        map_skill("force", "huashan-neigong");
        map_skill("dodge", "huashan-shenfa");
//      map_skill("unarmed", "taiji-quan");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "dugu-jiujian");
	map_skill("cuff", "poyu-quan");
	map_skill("strike", "hunyuan-zhang");

	prepare_skill("cuff", "poyu-quan");
	prepare_skill("strike", "hunyuan-zhang");
    set_temp("apply/armor", 400);
    set_temp("apply/damage", 550);
        set("chat_chance", 100);
        set("chat_msg", ({
	        (: heal :),
        }));
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: consider :),
        }) );

        create_family("华山派",17,"弟子");
        setup();
        carry_object("/clone/weapon/changjian");
        carry_object("/d/huashan/obj/huishan")->wear();
}
void attempt_apprentice(object ob)
{
	string title1;
        if ((string)ob->query("family/family_name")!="华山派")
        {
                command("say 你非我派弟子，我不能收你。");
                return ;
        }

        if((int)ob->query("betrayer"))
        {
                command("say "+RANK_D->query_respect(ob)+"你多次判师，背信弃义。我怎会收你。\n");
                return;
        }
	      
	      if((string)ob->query("gender")!="无性")
        {
                if ((int)this_player()->query_int() < 30 )
                {
                       command("say 学习独孤剑主要要有好的悟性，"+RANK_D->query_respect(ob)+"资质不够。");
                       return;
                }
		            
		            if ((int)ob->query("shen") < 30000) 
		            {
                       command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
                       command("say 在德行方面，" + RANK_D->query_respect(ob) + "是否还做得不够？");
                       return;
                }
                
                if ((int)ob->query("score") < 1500)
                {
                   command("pat " + ob->query("id"));
                   command("say 我只收本门忠心耿耿的弟子，你还达不到我的要求，还是回去吧!");
                   return; 
                }
                
                command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
                command("say 你今后可要惩恶扬善，旷扶正义！绝不可为非作歹，否则为师绝不会饶你的！\n");
	              title1=ob->query("title");
                command("recruit "+ob->query("id"));
                ob->set("title", RED"剑  魔  "HIW"传  人"NOR);
//title系统记录玩家title by seagate@pkuxkx
	              ob->set_title(TITLE_RANK, ob->query("title"));
        }
}
void re_rank(object student)
{
	student->set("title", RED"剑  魔  "HIW"传  人"NOR);
//title系统记录玩家title by seagate@pkuxkx
	student->set_title(TITLE_RANK, student->query("title"));
	return;
}
void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
         switch( random(2) )
        {
            case 0:
            command("wield jian");
            command("perform parry.feilong " + target->query("id"));
            command("unwield jian");
             break;
            case 1:
            command("wield jian");
            command("perform sword.po " +target->query("id"));
            command("unwield jian");
             break;
             }
}
void heal()
{
	object ob=this_object();
	
	if (ob->query("eff_qi") < ob->query("max_qi"))
	{
		command("exert heal");
		command("enforce 100");
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

#include "/kungfu/class/masterdie.h"