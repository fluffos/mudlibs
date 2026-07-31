// xiaoyao_weng.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("逍遥翁", ({ "xiaoyao weng","weng" }) );
        set("gender", "男性");
        set("age", 75);
        set("long",     "这是一位须发皆白的老人，满面红光，身披鹤氅，一副仙风道骨。\n");
        set("combat_exp", 1000000);
        set("score", 1000);
        set("attitude", "friendly");
	set("per",100);
	set("kar",100);
	set("str",100);
	set("max_force",5000);
	set("force",5000);
	set("force_factor",500);
	set("max_atman",5000);
	set("atman",5000);
	set("max_mana",5000);
	set("mana",5000);
	set("max_kee",5000);
	set("max_gin",5000);
	set("max_sen",5000);
	
	set_skill("unarmed",280);
	set_skill("parry", 280);
	set_skill("dodge", 280);

	set("inquiry",([
	"百草经" : "当年神农氏遍尝百草，倾毕生的时间写得一部《百草经》，
经里记述了很多草药的药性和药的配制方法。老夫潜心研究中草药数
十年也有所心得，如能得到《百草经》，原结合老夫的心得重修此书，
为后世造福，但不知此书现流落何方。\n",
]));
	set("chat_chance",5);
	set("chat_msg",({
	"逍遥翁说道：当年神农氏遍尝百草，写得一部《百草经》。\n",
	"逍遥翁说道：不知《百草经》现在流落何方，是否还存于人世。\n",
}));
        setup();

        carry_object(__DIR__"obj/he_chang")->wear();
}

void init()
{
	add_action("do_answer","answer");
}

int recognize_apprentice(object who)
{
	if( !who->query_temp("xiaoyao_weng/learn")) return 0;
	return 1;
}

int accept_object(object who, object ob)
{
	if(ob->name() == "百草经(上部)")
	{
	if( who->query_temp("xiaoyao_weng/book_two"))
		{
	write("逍遥翁说道：多谢你找齐《百草经》，此举为苍生后世造福不小。老夫潜修一生，
悟得两项技法，为焕容大法(huan-rong)和周易演命(zhouyi) ，愿尽数传授于你，
不过修习这两门技法要抛却世俗间的恩怨与得失，不知你是否能下次决心？
(answer yes/no)\n");
		who->delete_temp("xiaoyao_weng");
		who->set_temp("xiaoyao_weng/one_and_two",1);
		return 1;
		}
	write("逍遥翁说道：这是《百草经》的上部，谢谢你。不知下部在哪里，唉...\n");
	who->set_temp("xiaoyao_weng/book_one",1);
	return 1;
	}

	if(ob->name() == "百草经(下部)")
	{
	if( who->query_temp("xiaoyao_weng/book_one"))
		{
	write("逍遥翁说道：多谢你找齐《百草经》，此举为苍生后世造福不小。老夫潜修一生，
悟得两项技法，为焕容大法(huan-rong)和周易演命(zhouyi) ，愿尽数传授于你，
不过修习这两门技法要抛却世俗间的恩怨与得失，不知你是否能下次决心？
(answer yes/no)\n");
		who->delete_temp("xiaoyao_weng");
		who->set_temp("xiaoyao_weng/one_and_two",1);
		return 1;
		}
	write("逍遥翁说道：这是《百草经》的下部，谢谢你。不知上部在哪里，唉...\n");
	who->set_temp("xiaoyao_weng/book_two",1);
	return 1;
	}

	return 0;
}

int do_answer(string arg)
{
	object obj,me = this_player();
	if(!arg || arg == "") return 0;
	if(arg != "yes" && arg != "no") return 0;
	if(!me->query_temp("xiaoyao_weng/one_and_two")) return 0;
	if(arg == "yes")
	{
	write("逍遥翁说道：好，好！这位"+RANK_D->query_respect(me)+"真是聪颖，慧根独具，定能大彻大悟。\n");
	me->delete_temp("xiaoyao_weng");
	me->set_temp("xiaoyao_weng/learn",1);
	return 1;
	}

	if(arg == "no")
	{
	obj = new(__DIR__"obj/yaopai");
	obj->move(this_object());
	command("give yao pai to "+(string)me->query("id"));
	me->delete_temp("xiaoyao_weng");
	write("逍遥翁说道：看样子这位"+RANK_D->query_respect(me)+"俗缘难断，赠与你一件人间至宝，望好自为之。\n");
	return 1;
	}
}