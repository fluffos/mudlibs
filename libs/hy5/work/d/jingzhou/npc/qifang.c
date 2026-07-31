// Room: /d/jingzhou/npc/qifang.c
// Date: 99/06/01 by Byt

#include <ansi.h>
inherit NPC;
int ask_yuan();
int ask_kong();
void create()
{
	set_name("戚芳", ({ "qi fang","qi","fang"}) );
	set("gender", "女性" );
	set("age", 24);
	set("long", "只见她有一对乌黑而光溜溜的眼珠，微微上翘的鼻尖，只是脸色白了些。\n");
	set("shen_type", 1);
	set("combat_exp", 5000);
	set("str", 20);
	set("dex", 18);
	set("con", 19);
	set("int", 20);
        set("per", random(12)+20);
	set("attitude", "friendly");
	set("max_qi", 100);
	set("max_jing", 100);
	set("neili", 100);
	set("max_neili", 100);
	set("score", 1000);

	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 8);
	set_temp("apply/defense", 12);
	set_temp("apply/damage", 11);
	set_temp("apply/armor", 7);
        set("inquiry", ([
            "沅陵" : (: ask_yuan :),
            "空心菜" : (: ask_kong :),
        ]) );	
         set("chat_chance", 10);
         set("chat_msg", ({
		"戚芳带笑的柔和声音说道：“空心菜，你躲到哪儿啦？妈到处找不着。”\n",
		"戚芳带笑着叫道：“空心菜，你还不出来？”\n",		
	}));        
	setup();
	carry_object("/clone/misc/cloth")->wear();
}



int ask_yuan()
{
	object me = this_player();
        command("consider");
        command("say 好熟悉的地方啊，好象在晒谷场上，我还和一个男子比试过武功的。\n");
        command("?");
        me->set_temp("yuan",1);
        return 1;
}

int ask_kong()
{
	object me = this_player();
	object ob;
if (this_object()->query("get") ) return 0;
	{
		message_vision(CYN"戚芳笑道：书已经给别人了!\n"NOR,me);
		return 1;
	}

	if(me->query_temp("yuan")!=1)
	{
		message_vision(CYN"戚芳笑道：你是问我的女儿吗？\n"NOR,me);
		return 1;
	}
	else
	{
		message_vision(CYN"戚芳沉思了一会儿，拿出了一本书递给了$N。\n"NOR,me);	
		ob = new ("/d/jingzhou/obj/tangshixuan");
		ob->move(me);
this_object()->set("get",1);
		me->delete_temp("yuan");
		return 1;
	}
}	