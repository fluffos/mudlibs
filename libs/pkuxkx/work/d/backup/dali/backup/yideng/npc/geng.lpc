//耕
//by icer
#include <ansi.h>


inherit NPC;

void create()
{
        set_name("耕夫", ({ "gengfu" }));
        set("long", "这人上身赤膊，腿上泥污及膝。一脸憨厚像，仿佛天生就在这儿耕地一样。\n");
        set("gender", "男性");
        set("rank_info/respect", "大叔");
        set("age", 46);
        set("attitude","heroism");
        set("str", 20);
        set("dex", 35);
        set("con", 20);
        set("int", 30);
        set("shen_type", 5000);

        set_skill("finger", 100);
	set_skill("yiyangzhi",100);
	set_skill("parry",100);
        set_skill("force", 100);
        set_skill("dodge", 100);
	set_skill("xiantian-gong",80);
        map_skill("force", "xiantian-gong");
	map_skill("parry","yiyangzhi");
	map_skill("finger","yiyangzhi");
        set("jiali",50);

        set("combat_exp", 150000);

        set("max_qi", 800);
        set("max_jing", 800);
        set("neili", 800);
        set("max_neili", 800);

        setup();
        carry_object("/d/city/obj/cloth")->wear();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                remove_call_out("seeing");
                call_out("seeing", 1, ob);
        }
	add_action("do_answer","answer");

}
void seeing(object ob)
{
     if ((int)ob->query_temp("marks/耕2",1)) {
		return;
	}

     command("look "+ ob->query("id"));
    say("耕夫立刻警觉起来：你受了伤？来干什么了？(answer)\n");
     ob->set_temp("marks/耕1",1);
}

int do_answer(string arg)
{
	if (!(int)this_player()->query_temp("marks/耕1",1)) {
		return notify_fail("农夫一脸迷茫：你说什么呀？我没问过你什么呀？");
	}
	else
	{
		if (arg == "治伤")
		{
			command("say 又没什么凭证，我为什么要相信你呀？\n");
			this_player()->set_temp("marks/耕2",1);
			return 1;
		}
		else
		{
			return notify_fail("耕夫一脸忿：快走快走！这儿不是你来的地方！\n");
		}                                                                   
	}
}

int accept_object(object me, object ob)
{
        if (ob->query("id")=="ruanwei jia")
	{
		if (me->query_temp("marks/耕2",1))
		{
			write("耕夫将信将疑地接过软猥甲，看了看，说：好吧，就放你过去吧！\n");
			me->set_temp("marks/耕3",1);
                        call_out("destroy",1,ob);
			return 1;
		}
		else
		{
			command("jump");
			command("多谢了，可我可没什么可报答你的啊！\n");
                        call_out("destroy",1,ob);
			return 1;
		}
	}
}
void destroy(object ob)
{
        destruct(ob);
}
