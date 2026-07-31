// write by dfbb@hero
// 1/25/96
#include <ansi.h>
inherit NPC;
inherit F_QUEST;

void create()
{
	set_name("杨莲亭", ({ "yang lian ting", "yang" }));
	set("title",HIR "日"+HIB"月"+HIY "神教" NOR +"总管");	
	set("long", 
		"一个满脸于思的大汉,又高又壮,衣服华丽\n");
	set("gender", "男性");
	set("age", 21);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_kee", 500);
	set("max_gin", 500);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 10);
	set("combat_exp", 15000);
	set("score", 6000);

	set_skill("force", 10);
	set_skill("tianmo-dafa", 10);
	set_skill("dodge", 10);
	set_skill("mo-shan-jue", 10);
	set_skill("strike", 10);
	set_skill("mo-zhang-jue", 10);
	set_skill("parry", 10);
	set_skill("halberd", 10);
	set_skill("literate", 50);

	map_skill("force", "tianmo-dafa");
	map_skill("dodge", "mo-shan-jue");
	map_skill("strike", "mo-zhang-jue");
	map_skill("halberd", "mo-ji-jue");
	map_skill("parry", "mo-ji-jue");

	prepare_skill("strike", "mo-zhang-jue");

	create_family("日月神教", 15, "总管");

	setup();
	carry_object("/obj/cloth")->wear();
	
}

int accept_fight(object me)
{
        command("say 想找死啊!!");
        command("grin");
        return 0;
}

int accept_kill(object killer)
{

        int i;
        object *ob,me;
        me=this_object();
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
                if( ob[i]->query("family/family_name")!="日月神教")continue;
                if( ob[i]->query("id")==killer->query("id")) continue;
                if( userp(ob[i]) ) ob[i]->kill_ob(killer);
                else if( !ob[i]->is_killing(killer) )
		ob[i]->kill_ob(killer);
                ob[i]->set_leader(killer);
                write(ob[i]->query("name")+ "吼道:"+HIY 
                "好小子, 居然敢杀我们日月神教的人,死去吧你!\n" NOR);
        }
        return 1;
}

void init()
{
        add_action("do_gogo", "go");
        add_action("do_none", "north");
	add_action("give_quest","quest");
        ::init();
}

int do_gogo(string arg)
{
        object me;
        me = this_player();
        if( (arg == "north" )&&(!query("is_here")))
        {
         write("这个方向的路被杨莲亭挡住了 。\n");
	 command("say 本教重地,你不能进去");
         return 1;
        }
        return 0;
}
 
        
int do_none()
{
        return 1;
}
               
