// ma.c
//#include "/quest/quest.h"
#include <ansi.h>
inherit NPC;

string ask_me(object who);

void create()
{
	int jibie;
	jibie = 300;
	set("xyzx_sys/level", jibie*8/10+random(jibie*4/10));	//2016.5.22阿飞调整NPC属性
        set_name("马竟终", ({ "ma jingzhong","ma" }) );
        set("title", "浣花剑派总管");
        set("gender", "男性" );
        set("age", 56);

        set("str", 22);
        set("int", 26);
        set("per", 23);
        set("kar", 25);
        set("con", 23);
        set("dex", 23);
        set("long",
                
"马竟终出道很早，对武林中的大小事务都很熟悉，\n"
"武林中的事可没几件能瞒得过他。\n");

set("combat_exp", 80000000);	
        set("attitude", "friendly");
set("max_qi",50000);
set("max_jing",50000);
        set("env/wimpy", 30);

        set("max_neili", 1000);  
set("neili", 1000000);      
set("jiali", 2000);	

set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.zhenjian" :),
(: perform_action, "sword.snow" :),
                }) );
set_skill("cuff", 500+jibie/3+random(jibie/5));
set_skill("strike",500+jibie/3+random(jibie/5));
set_skill("force", 500+jibie/3+random(jibie/5));
set_skill("dodge", 500+jibie/3+random(jibie/5));
set_skill("parry", 500+jibie/3+random(jibie/5));
set_skill("sword", 500+jibie/3+random(jibie/5));
set_skill("literate",500+jibie/3+random(jibie/5));
set_skill("unarmed",500+jibie/3+random(jibie/5));
set_skill("huanhua-jian",500+jibie/3+random(jibie/5));
set_skill("tiexian-quan",500+jibie/3+random(jibie/5));
set_skill("guiyuan-dafa",500+jibie/3+random(jibie/5));
set_skill("feihua-wuping",500+jibie/3+random(jibie/5));

	 map_skill("force","guiyuan-dafa");
	 map_skill("unarmed","tiexian-quan");
	 map_skill("sword","huanhua-jian");
	 map_skill("dodge","feihua-wuping");
	
/*
	 set("chat_chance",30);
         set("chat_msg",({
         "马竟终自言自语道：江湖上的事。。嘿嘿\n",
         "马竟终大笑道：谁能够瞒得过我的眼睛！\n",
          }));
*/

        create_family("浣花剑派", 3, "弟子");
      
        setup();
        
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();

        add_money("gold", 10);
}

/*
void init()
{
	add_action("do_where", "where");
}

*/
int do_where(string arg)
{
	object ob,me,where;
	mapping fam;
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "浣花剑派")
		{command( "say 你不是本派弟子，我不能告诉你。");return 1;}
		
	if(!arg || arg=="") {
		command("say 你想找谁？");
		return 1;
	}
	me=this_player();
	ob = find_player(arg);
	if( !ob ) ob = find_living(arg);
	if (!ob) {
		command("say 现在没这个人.");
		return 1;
	}
	where = environment(ob);
	if (!where) {
		command("say 这个人不知道在那里耶...");
		return 1;
	}
	printf(CYN"马竟终想了想，说道：%s(%s)现在在%s.\n"NOR,
		(string)ob->name(),
		(string)ob->query("id"),
		(string)where->query("short"));
	return 1;
}

