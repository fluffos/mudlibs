// Room: /d/jingzhou/npc/diyun.c
// Date: 99/06/01 by Byt

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("少年狄云", ({ "di yun", "di" }));
        set("gender", "男性");
        set("age", 23);
        set("str", 40);
        set("dex", 20);
        set("long", "只见他长脸黝黑，颧骨微高，粗手大脚，那是湘西乡下常见的庄稼青年汉子。\n");
        set("combat_exp", 30000);
        set("shen_type", 0);
        set("attitude", "heroism");

  	set("combat_exp", 3500000);
	set("attitude", "heroism");

	set_skill("unarmed", 230);
	set_skill("dodge", 230);
	set_skill("parry", 260);
	set_skill("force", 260);
	set_skill("sword", 260);
       set("max_neili",20000);
        set("neili",20000);
        set("max_qi",9800);
        set("qi",9800);
	set_skill("liancheng-jian", 380);
	map_skill("sword", "liancheng-jian");
map_skill("parry", "liancheng-jian");	
        set_temp("apply/attack", 120);
        set_temp("apply/defense", 120);
        set_temp("apply/armor", 120);
        set_temp("apply/damage", 320);

	set("chat_chance", 40);
	set("chat_msg", ({
		(: random_move :),
	}));
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.ci" :),
                (: perform_action, "sword.erguang" :),
                (: perform_action, "sword.gan" :),
                (: perform_action, "sword.qian" :),
                (: perform_action, "sword.qu" :),
                (: perform_action, "sword.zhai" :),                	                	                	
                (: perform_action, "sword.zhu" :),                	                	                	
		            (: random_move :),
        }) );

        setup();
        carry_object(__DIR__"obj/gangjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}



int accept_object(object who, object ob)
{
	object obj,ob1;
	obj=this_object();
if (obj->query("get") ) return 0;
//	if(who->query_temp("task")!=1) return 0;
        if((ob->query("id") == "tangshi xuanzhu"))
        {
                command("sish");
		remove_call_out("destrory");
		call_out("destrory",1,ob);
		ob1 = new("/d/jingzhou/obj/jianpu");
		ob1->move(who);
		ob1 = new("/d/jingzhou/obj/wucanyi");
		ob1->move(who);
this_object()->set("get",1);
	}
	return 1;
}

   
void destrory(object ob)
{
        destruct(ob);
}
       
 


