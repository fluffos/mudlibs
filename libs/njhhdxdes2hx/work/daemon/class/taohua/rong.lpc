// huang-rong.c -黄蓉

#include <ansi.h>

inherit NPC;

int ask_ji();

void create()
{
        set_name("黄蓉", ({ "huang rong", "huang", "rong" }));
        set("long",
	"她长的及其美丽，让人看了以为天仙一般。\n"
	"她是当今大侠郭靖的夫人，和郭大侠一起镇守襄阳城已有多年。\n"
	"郭夫人曾是丐帮帮主，武功自然也很了得。\n");

	set("nickname", GRN "赛诸葛" NOR);
	set("title", YEL "郭夫人" NOR);
        set("gender", "女性");
        set("age", 36);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 20);
        set("int", 30);
        set("con", 24);
        set("dex", 28);
	set("per", 30);

        set("max_kee", 800);
        set("max_gin", 600);
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 20);
	set("combat_exp", 100000);
        set("score", 5000);
        set("chat_chance",10);  
            
        set("chat_msg", ({
            "黄容说到:“蒙古大汉蒙哥就要帅重兵来攻打襄阳城了。”\n"
           }));
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "staff.chan" :)
        }) );

	set_skill("literate", 200);
	set_skill("qimen-bagua", 200);
        set_skill("force", 80);
	set_skill("taohua-force", 80);
        set_skill("dodge", 90);
        set_skill("parry", 90);
        set_skill("sword", 80);
        set_skill("yuxiao-jian", 60);
	set_skill("staff", 120);
	set_skill("dagou-bang", 120);
        set_skill("baguabu", 90);
        set_skill("hand", 90);
        set_skill("lanhua-shou", 80);
        set_skill("strike", 80);
        set_skill("luoying-zhang", 80);

	map_skill("force", "taohua-force");
        map_skill("parry", "lanhua-shou");
        map_skill("sword", "yuxiao-jian");
        map_skill("dodge", "baguabu");
        map_skill("strike", "luoying-zhang");
        map_skill("hand", "lanhua-shou");
	map_skill("staff", "dagou-bang");

        prepare_skill("strike", "luoying-zhang");
 	prepare_skill("hand", "lanhua-shou");

        create_family("桃花岛", 2, "弟子");

        set("inquiry", ([
                "叫化鸡" : (: ask_ji :),
        ]));

        setup();
	
	carry_object("/kungfu/class/gaibang/zhuzhang");

}

int ask_ji()
{
	command("say 叫化鸡我是会做，可现在我正在守城，"+ RANK_D->query_respect(this_player())+ "若能立一大功，我就可以给你做鸡。");
	this_player()->set_temp("ask-ji", 1);
	return 1;
}

int accept_object(object ob, object obj)
{
	object obj1,obj2;
	object me=this_object();   
        if (obj->query("id")=="jun ling") 
          {                            
            if (!ob->query_temp("havesword"))
            {command("say 想不到这位英雄如此神勇，竟在万军之中去上将首级!");
            command("say 我无以回报，就把这把刚铸好的倚天剑赠给英雄。");
            obj2=new("/d/new_taohua/obj/skysword"); 
            obj2->move(ob);               
            ob->set_temp("havesword",1);
	    write("黄容给你一把倚天剑。\n");   
            remove_call_out("destroying");
            call_out("destroying", 1, ob, obj);
            return 1;
            }
            else
            {command("say 我已经没有可以给这位英雄的了。");
             } 
            return 1;
           }
        if (obj->query("id")!="rentou" || obj->query("name")!="蒙古千夫长的人头")
	{
		command("say 这东西给我可没什么用。");
		return 0;
	}

	if (ob->query_temp("ask-ji"))
	{
		command("say 既然" + RANK_D->query_respect(ob) + "杀了蒙古武士，那我就给你做鸡吧！");
                obj1=new("/kungfu/class/gaibang/jiaohuaji");
                obj1->move(ob);
		write("黄蓉给你一只叫化鸡。\n");
		ob->delete_temp("ask-ji");
	}
	else
	{
		command("say 想不到" + RANK_D->query_respect(ob) + "也是如此侠肝义胆！\n");
		ob->set("shen", ob->query("shen") + 100);
	}

	remove_call_out("destroying");
	call_out("destroying", 1, me, obj);
        return 1;
}


void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

int accept_fight(object ob)
{
	command("say 好吧，那我们点到为止！");
	command("wield zhuzhang");
	return 1;
}

