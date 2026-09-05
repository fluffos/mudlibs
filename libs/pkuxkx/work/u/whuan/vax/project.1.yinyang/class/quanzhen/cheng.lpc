//made by hacky
//date 97,11,24

#include <ansi.h>
inherit NPC;
inherit F_AQUESTMASTER;
void do_answer(string);

void create()
{
    set_name("程遥伽",({"cheng yaojia","cheng"}));
    set("title",HIB"全真派"NOR+GRN"女道长"NOR);
    set("age",21);
    set("gender","女性");
   
    set("str",20);
    set("int",25);
    set("con",21);
    set("attitude","friendly");

    set("max_qi",500);
    set("max_jing",500);
    set("max_neili",500);
    set("neili",500);
    set("jiali",20);
    
    set("combat_exp",50000);
    set("score",1000);

    set_skill("parry",60);
    set_skill("dodge",60);
    set_skill("sword",60);
    set_skill("quanzhen-jian",50);
    set_skill("cuff",50);
    set_skill("daoxue-xinfa",60);
    set_skill("fx-step",40);
    set_skill("xiantian-gong",40);
    set_skill("qixing-xinfa",50);
    set_skill("force",60);
    set_skill("literate",50);
    set_skill("yangxin-quan",40);


    map_skill("sword","quanzhen-jian");
    map_skill("force","xiantian-gong");
    map_skill("dodge","fx-step");
    map_skill("parry","quanzhen-jian");
    map_skill("cuff","yangxin-quan");

    setup();

    create_family("全真派",3,"弟子");

    carry_object(__DIR__"obj/whiterobe")->wear();
    carry_object(__DIR__"obj/gangjian")->wield();

}
void init()
{
	add_action("do_answer","answer");
        add_action("give_wsquest","quest");
}


void attempt_apprentice (object ob)
{
    if ( (string)ob->query("gender")!="女性")
     {
         command("say 我只收女徒");
      }
     else {
	if ((string)ob->query("family/family_name") == "灵鹫宫" 
		&& ob->query("lingjiu/xiulian"))
	{
       		command("say "+RANK_D->query_respect(ob)+"，你现在拜我似乎会有很大损失，你能拿定主意吗？(answer)");
	return;		
	}	
          command("smile");
          command("say 全真教就是少女伴,你肯来真是太好了");
          command("recruit " + ob->query("id") );
          
      ob->set("title",HIB"全真派"NOR+YEL"女道童"NOR);
    }
 } 
void do_answer(string arg)
{
	object me=this_player();
	if (!arg || (arg != "是" && arg != "能" && arg != "yes"))
        	command("say 你说的什么乱七八糟的，看来你是没有诚心，算了！");
	else
	{
   	        command("smile");
          	command("say 全真教就是少女伴,你肯来真是太好了");
		me->set("mud_age",me->query("lingjiu/mud_age"));
		me->set("age",14+me->query("mud_age")/3600/24);
		me->delete("lingjiu/skill_status");
		me->delete("lingjiu/qi");
		me->delete("lingjiu/eff_qi");
		me->delete("lingjiu/max_qi");
		me->delete("lingjiu/jing");
		me->delete("lingjiu/eff_jing");
		me->delete("lingjiu/max_jing");
		me->delete("lingjiu/jingli");
		me->delete("lingjiu/neili");
		me->delete("lingjiu/max_jingli");
		me->delete("lingjiu/max_neili");
		me->delete("lingjiu/combat_exp");
		me->delete("lingjiu/need_xiulian");
		me->delete("lingjiu/mud_age");
		me->delete("lingjiu/xiulian");
		me->delete("lingjiu/last_xiulian_time");
	        command("recruit "+me->query("id"));
	        me->set("title",HIB"全真派"NOR+YEL"女道童"NOR);

	}
return;
}
