// xiaohong.c 小虹
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void do_answer(string);
void create()
{
   set_name("小玲", ({ "xiao ling","ling" }));
        
         set("title",GRN "古墓派" NOR + YEL +"女使" NOR);
        set("long",
                "她是神雕大侠收养的孤儿\n"
                "她看起来十多岁，容貌秀丽，别有一番可人之处。\
n");
        set("gender", "女性");
        set("age", 16);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 18);
        set("int", 28);
        set("con", 20);
        set("dex", 24);
        set("per", 25);
        set("max_qi", 600);
        set("max_jing", 300);
        set("neili", 600);
        set("max_neili", 600);
        set("jiali", 50);
        set("combat_exp", 50000);
        set("score", 5000);
/*set("inquiry", ([
                "冰魄杖" : (: ask_me :),
                "name"   : "我就是阿紫呀！！",
        ]) );
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: consider :)
        }) );
  */   
	 set_skill("force", 60);
        set_skill("changhen-xinfa", 60);
	set_skill("cuff", 70);
	set_skill("meinu-quan", 70);
        set_skill("dodge", 80);
        set_skill("xianyun", 80);
        set_skill("parry", 70);
        set_skill("whip", 70);
        set_skill("changhen-bian", 70);
	set_skill("throwing",70);
	set_skill("qianmie-shou",70);
        set_skill("literate", 50);

       

        map_skill("force", "changhen-xinfa");
	map_skill("cuff", "meinu-quan");
        map_skill("dodge", "xianyun");
//      map_skill("unarmed", "taiji-quan");
        map_skill("parry", "changhen-bian");
        map_skill("whip", "changhen-bian");

	prepare_skill("cuff", "meinu-quan");

       

        create_family("古墓派" , 5, "弟子");
        setup();
        carry_object("/d/shaolin/obj/changbian")->wield();
         carry_object("/d/gumu/npc/obj/white")->wear();
}
void init()
{
	add_action("do_answer","answer");
}

void attempt_apprentice(object ob)
{
         if((int)ob->query("betrayer")>=5)
        {
        command("say 你多次背信弃义，我怎可信你!\n");
        command("say"+RANK_D->query_respect(ob)+"你多次残害黎民百姓，我怎可容你.\n");
        return;
        }
        if((string)ob->query("gender")=="无性")
        {
        
        command ("say 你不男不女的，我怎可收你.\n");
        command("say"+RANK_D->query_respect(ob)+"你不男不女的，我怎可收你.\n");
        return;
	}
	if ( this_player()->query("class")=="bonze")
	 {
                command("say 我派不收佛门弟子，" + RANK_D->query_respect(ob) + "请现还俗了在来。");
                return;
        }
	if ((string)ob->query("family/family_name") == "灵鹫宫" 
		&& ob->query("lingjiu/xiulian"))
	{
       		command("say "+RANK_D->query_respect(ob)+"，你现在拜我似乎会有很大损失，你能拿定主意吗？(answer)");
	return;		
	}	

        command("say 好吧，"+RANK_D->query_respect(ob)+"，我就收下你了！");
        command("recruit "+ob->query("id"));
 if (this_player()->query("age")<16)
        {
        if((string)this_player()->query("gender")!="女性")
                this_player()->set("title",RED "古墓派" NOR + GRN +"男童" NOR);
        else

                this_player()->set("title",RED "古墓派" NOR + GRN +"女童" NOR);
        }
        else {
        if((string)this_player()->query("gender")!="女性")
                this_player()->set("title",RED "古墓派" NOR + GRN +"使者" NOR);
        else
                this_player()->set("title",RED "古墓派" NOR + GRN +"使女" NOR);
        }
        
}
void do_answer(string arg)
{
	object me=this_player();
	if (!arg || (arg != "是" && arg != "能" && arg != "yes"))
        	command("say 你说的什么乱七八糟的，看来你是没有诚心，算了！");
	else
	{
        	command("say 好吧，"+RANK_D->query_respect(me)+"，我就收下你了！");
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
                me->set("title",RED "古墓派" NOR + GRN +"使女" NOR);

	}
return;
}
