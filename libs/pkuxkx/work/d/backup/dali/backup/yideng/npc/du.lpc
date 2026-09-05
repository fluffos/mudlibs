//读
//by icer
#include <ansi.h>


inherit NPC;

int ask_dayi();

void create()
{
        set_name("书生", ({ "shusheng" }));
        set("long", "那书生摇头晃脑，读得津津有味，根本不在乎挡没挡路。再听他所读之书原来是\n
一部最平常不过的“论语”。\n");
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
        set_skill("force", 100);
        set_skill("dodge", 100);
	set_skill("parry",100);
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
        set("inquiry", ([
	    "微言大义" : (: ask_dayi :),
       ]) );


        setup();
        carry_object("/d/city/obj/cloth")->wear();
}

int ask_dayi()
{
	if (this_player()->query_skill("literate",1)<150)
	return notify_fail("书生哈哈大笑：你这点墨水还想来指点我？赶快回去再学几年吧！\n");
	write("书生愕然止读：这位"+ RANK_D->query_self_respect(this_player())+"自称懂得孟子微言大义，我倒要请教。\n");
	command("say 我这里有个谜语，你猜猜看？\n");
	command("say \n
六经蕴籍胸中久，	一剑十年磨在手。\n
杏花头上一枝横，	恐泄天机莫露口。\n
一点累累大如斗，	却掩半床无所有。\n
完名直待挂冠归，	本来面目君知否？(answer)\n");
	this_player()->set_temp("marks/读1",1);
	return 1;
}

void init()
{
        object ob;
        ::init();
	add_action("do_answer","answer");

}

int do_answer(string arg)
{
	if ((int)this_player()->query_temp("marks/读2")) 
	{
			if ( arg == "魑魅魍魉，四小鬼各自肚肠" )
			{
				command("wa "+ this_player()->query("id"));
				command("admire "+ this_player()->query("id"));
				command("say 在下拜服！");
				write("那书生站了起来，让开了地方，你可以跳(jump)过去了。\n");
				return 1;
			}
			else
			{
				command("laugh "+ this_player()->query("id"));
				command("say 什么呀？对不出来你就趁早回去吧！\n");
				return notify_fail("你羞得满脸通红。\n");
			}
	}
	else 
	{
		if ((int)this_player()->query_temp("marks/读1")) 
		{
		if ( arg == "辛未状元" )
		{
			command("wa "+ this_player()->query("id"));
			command("say 我还有一幅上联，你来对一下:\n
琴瑟琵琶，八大王一般头面 (answer)\n");
			this_player()->set_temp("marks/读2",1);
			return 1;
		}
		else
		{
			command("laugh "+ this_player()->query("id"));
			command("say 什么呀？猜不出来你就趁早回去吧！\n");
			return notify_fail("你羞得满脸通红。\n");
		}
		}
	}
}

