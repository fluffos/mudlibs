// zhao.c
#include <ansi.h>
#include <title.h>
inherit NPC;

void create()
{
	set_name("赵半山", ({"zhao banshan", "zhao", "banshan"}));
	set("title", HIR"红花会"HIG"三当家"NOR);
	set("nickname", HIY "千臂如来" NOR );
	set("gender", "男性");
	set("age", 48);
	set("long", 
"他一张胖胖的脸，笑起来给人一副很慈祥的感觉。他
原是温州王氏太极门掌门大弟子。豪迈豁达，行侠江
湖，一手暗器功夫和太极剑少有能匹敌。屠龙帮风流
云散之后，投入红花会。很得被红花会老当家于万亭
赏识。\n");
	set("attitude", "peaceful");
	set("class", "fighter");
	set("per", 21);
	set("str", 21);
	set("int", 30);
	set("con", 26);
	set("dex", 30);

	set("qi", 2500);
	set("max_qi", 2500);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 2500);
	set("max_neili", 2500);
	set("combat_exp", 20000000);

	set_skill("force", 300);
	set_skill("bingchuan-xinfa", 300);
	set_skill("throwing", 300);
	set_skill("mantian-xingyu", 300);
	set_skill("dodge", 300);
	set_skill("zhuangzi-mengwu", 300);
	set_skill("parry", 300);

	map_skill("force"  , "bingchuan-xinfa");
	map_skill("dodge"  , "zhuangzi-mengwu");
	map_skill("parry"  , "mantian-xingyu");
	map_skill("throwing"  , "mantian-xingyu");
	set("chat_chance_combat", 70);  
	create_family("红花会", 3, "弟子");
	setup();
	
	carry_object("/clone/weapon/changjian")->wield();
	carry_object(__DIR__"obj/jili")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

void attempt_apprentice(object ob)
{
         if ((string)ob->query("family/family_name")!="红花会" )
        {
         command("say 我不收外派弟子。");
         command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜马善均。");
                return;
        }if ((int)ob->query("shen") < 100000) {
                command("say 红花会所作所为都是扶危济困。");
                command("say " + RANK_D->query_respect(ob) + "若能做出" +
                        "几件侠义之事，本座一定收你。");
                return;
        }
        if ((int)ob->query("score")<1500){
            command("sigh"+ob->query("id"));
            command("say 你若为本门立点功劳,本座一定收你");
            return;      
            }
        if ((int)ob->query_skill("bingchuan-xinfa", 1) < 50) {
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
	        ob->set_title(TITLE_RANK, HIR "红花会" NOR + HIY +"堂主" NOR);
        }
        return;
}
void re_rank(object student)
{
        student->set("title",HIR "红花会" NOR + HIY +"堂主" NOR);
//title系统记录玩家title by seagate@pkuxkx
	      student->set_title(TITLE_RANK, HIR "红花会" NOR + HIY +"堂主" NOR);
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

