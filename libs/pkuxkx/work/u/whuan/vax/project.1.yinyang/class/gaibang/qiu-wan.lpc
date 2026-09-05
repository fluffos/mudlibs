// gaibang npc code

#include <ansi.h>
#include "gaibang-master.h"

inherit NPC;
inherit F_MASTER;
void do_answer(string);
void get_class(string arg,object ob);

void create()
{
        set_name("裘万家", ({"qiu wanjia", "qiu", "wanjia"}));
        set("title",MAG "丐帮" NOR + YEL "二袋" NOR+ MAG "弟子" NOR);
        set("gender", "男性");
        set("age", 27);
        set("long",
                "这是位衣著邋塌，蓬头垢面的丐帮二袋弟子。\n");
        set("attitude", "heroism");
        set("str", 28);
        set("int", 18);
        set("con", 24);
        set("dex", 20);
        set("chat_chance", 20);
        set("chat_msg", ({
              (: heal :),
        }));

        set("max_qi", 600);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 50);
        set("dai",2);

        set("combat_exp", 10000);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: exert_function , "powerup" :),
                (: combat_heal :),
        }) );

        set_skill("force", 45);
        set_skill("huntian-qigong", 45);
        set_skill("jiaohua-xinfa", 45);
        set_skill("blade", 45);
        set_skill("liuhe-dao", 45);
        set_skill("hand", 45);
        set_skill("shexing-shou", 45);
        set_skill("dodge", 50);
        set_skill("xiaoyaoyou", 45);
        set_skill("parry", 43);
        set_skill("begging", 50);
        set_skill("stealing", 40);

        map_skill("force", "huntian-qigong");
        map_skill("hand", "shexing-shou");
        map_skill("blade", "liuhe-dao");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "liuhe-dao");

        prepare_skill("hand", "shexing-shou");

        create_family("丐帮", 25, "弟子");
        setup();
}

void init()
{
	add_action("do_answer","answer");
}


void attempt_apprentice(object ob)
{
        mapping fam;
        object obj;
        if( ob->query("combat_exp") < 2000 && !(ob->query("is_beggar2")) && !(ob->query("is_beggar")))
        {
	if ((string)ob->query("family/family_name") == "灵鹫宫" 
		&& ob->query("lingjiu/xiulian"))
		{
       		command("say "+RANK_D->query_respect(ob)+"，你现在拜我似乎会有很大损失，你能拿定主意吗？(answer)");
		return;		
		}
                command("say 本帮弟子分为「污衣派」和「净衣派」，不知" + 			RANK_D->query_respect(ob) + "愿意加入哪一派呢？\n");
                input_to("get_class",ob);
                return;
        }
        command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜小叫化呢？");
        return;


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
                command("say 本帮弟子分为「污衣派」和「净衣派」，不知" + 						RANK_D->query_respect(me) + "愿意加入哪一派呢？\n");
                input_to("get_class",me);	
	}
return;
}
void get_class(string arg,object ob)
{
        if (arg == "污衣派")
        {
                ob->set_temp("bai_qiu/污衣派",1);
                call_out("recruit_id",1,ob);
        }
        else    if (arg == "净衣派")
                {
                        ob->set_temp("bai_qiu/净衣派",1);
                        call_out("recruit_id",1,ob);
                }
                else
                {
                        write("请选择 污衣派 或者 净衣派\n");
                        input_to("get_class",ob);
                }
        return;
}

void recruit_id(object ob)
{
        object obj;
        
        if (ob->query_temp("bai_qiu/净衣派"))
        {
                command("say 好，既然" + RANK_D->query_respect(ob) + "愿意拜我为师，我就收下你作「净衣派」弟子了。");
                ob->set("dai", 1);
                ob->set("is_beggar2", 1);
                command("recruit " + ob->query("id"));
                this_player()->set("title",MAG "丐帮" NOR + HIC + "净衣派" + YEL +"一袋" NOR + MAG "弟子" NOR);
        }
        else
        {
                command("say 好，既然" + RANK_D->query_respect(ob) + "愿意拜我为师，我就收下你作「污衣派」弟子了。");
                ob->set("dai", 1);
                ob->set("is_beggar", 1);
                if (ob->query("class")!="bonze")
                ob->set("class", "beggar");
                command("recruit " + ob->query("id"));
                if(!present("budai", this_player()))
                {
                      obj=new("/d/gaibang/obj/gaibang-bag");
                      obj->move(ob);
                }
                this_player()->set("title",MAG "丐帮" NOR + BLK + "污衣派" + YEL +"一袋" NOR + MAG "弟子" NOR);
        }
        return;
}       
