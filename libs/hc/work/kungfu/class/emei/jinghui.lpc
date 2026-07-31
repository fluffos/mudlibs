// jinghui.c 静慧
// create by host dec,11
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("静慧", ({ "jing hui", "jing", "hui"}));
        set("long",
           "她是峨嵋派四师姐，只见她两眼烁烁有神，不停的扫视着四周。。\n");
        set("gender", "女性");
        set("age", 38);
        set("attitude", "peaceful");
        set("nickname", HIY "四师姐" NOR);
        set("shen_type", 1);
        set("str", 27);
        set("int", 24);
        set("con", 27);
        set("dex", 24);

        set("qi", 1500);
        set("max_qi", 1500);
        set("jing", 800);
        set("max_jing", 800);
        set("neili", 1200);
        set("max_neili", 1200);
        set("jiali", 40);

        set("combat_exp", 3080000);
        set("score", 100000);

        set_skill("force", 210);
        set_skill("dodge", 200);
        set_skill("parry", 210);
        set_skill("blade",220);
        set_skill("linji-zhuang",200);
        set_skill("zhutian-bu",200);
        set_skill("yanxing-dao",220);
        set_skill("literate", 180);
        map_skill("dodge","zhutian-bu");
        map_skill("parry", "yanxing-dao");
        map_skill("blade", "yanxing-dao");
        map_skill("force","linji-zhuang");

        create_family("峨嵋派", 4,"弟子");
        set("class","bonze");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangdao")->wield();
  }
void attempt_apprentice(object ob)
 {
     
     object me;
     me = this_player();

     if ((string)ob->query("gender") != "女性" )
      {
        command("say 我怎么能够收男子为徒呢？");
       return;
      }
     if ((int)ob->query("shen") < 0)
        {
        command("say 我峨嵋乃是堂堂名门正派，对弟子要求极严。");
        command("say 在德行方面，" + RANK_D->query_respect(ob) +
                 "是否还做得不够？");
                return;
        }
    if ((int)ob->query("str") < 25 && (int)ob->query("con") < 25 ) 
        {
		command("say " + RANK_D->query_respect(ob) + 
			"根骨太差，先练好本门功夫再来吧。");
		return;
  	}       
    if( (string)me->query("class")=="bonze" )
       {
             command("nod");
             command("recruit " + ob->query("id"));
       }
     
      else {

                command("say 阿弥陀佛！善哉！善哉！施主若真心皈依我佛，可去静心那里受戒。\n");
		return ;
            }

 

  }
