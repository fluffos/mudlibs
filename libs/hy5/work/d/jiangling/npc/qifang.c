//Edited by fandog, 02/13/2000
#include <ansi.h>
inherit NPC;
int ask_yuan();
int ask_kong();
void create ()
{
	set_name("戚芳", ({"qi fang","qi"}));
	set("long", "一位容色秀丽的少妇，圆圆的脸蛋，一双大眼黑溜溜的，脸上不施脂粉，容色颇为憔悴。\n");
	set("gender", "女性");
	set("age", 20);
	set("combat_exp", 1000000);
	set("str", 20);
	set("int", 28);
	set("dex", 23);
	set("con", 26);
	set("per", 26);
	set("kar", 26);
	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("sword", 60);
	set_skill("parry", 60);
	set_skill("feixian-steps", 60);
	set_skill("liancheng-jian", 360);
	map_skill("dodge", "feixian-steps");
	map_skill("parry", "liancheng-jian");
	map_skill("sword", "liancheng-jian");
          
          	set_temp("apply/attack", 118);
	set_temp("apply/defense", 112);
	set_temp("apply/damage", 711);
	set_temp("apply/armor", 777);
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
	carry_object("/clone/cloth/female1-cloth")->wear();
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