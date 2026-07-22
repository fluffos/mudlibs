#include <ansi.h>
inherit NPC;

void create()
{
        set_name("护法使者", ({ "shi zhe", "zhe",}));
        set("long", "此人头上罩着黑色头罩，根本看不见相貌。\n"+
        	    "是由教主请手调教出来的高手，负责着教坛的守卫。\n");
        set("title",HIY"日月神教  "HIM"护法"NOR);
        set("gender", "男性");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 22);
        set("int", 25);
        set("con", 21);
        set("dex", 30);
        
        set("max_qi", 3000);
        set("eff_qi", 3000);
        set("qi", 3000);
        set("max_jing", 2000);
        set("jing", 2000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 50);
        set("combat_exp", 1500000);

        set_skill("parry",200);
        set_skill("dodge",200);
        set_skill("force",200);
        set_skill("strike",200);
        set_skill("literate", 120);
        set_skill("blade",200);
        set_skill("tianmo-dao",200);
        set_skill("tianmo-zhang",200);
        set_skill("tianmo-jian",200);
        set_skill("tianmo-dao",200);
        set_skill("ding-dodge",200);
        set_skill("tianmogong",200);

        map_skill("strike", "tianmo-zhang");
        map_skill("sword", "tianmo-jian");
        map_skill("parry", "tianmo-jian");
        map_skill("blade", "tianmo-dao");
        map_skill("dodge", "ding-dodge");
        map_skill("force", "tianmogong");
        prepare_skill("strike", "tianmo-zhang");
        create_family("日月神教",3,"第子");
        setup();

	set("chat_chance", 2);
        set("chat_msg", ({
              "护法使者高声说道：“教主令旨英明，算无遗策。”\n",
              "护法使者说道：“教主千秋万载，一统江湖。”\n",
              "护法使者高叫道：“教主文成武德，仁义英明，中兴圣教，泽被仓生。”\n",
        }));
        if (random(2))
        	carry_object(BINGQI_D("sword"))->wield();
        else
        	carry_object(BINGQI_D("blade"))->wield();
        carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{
	object me, ob;

	::init();

	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight")
	&& !present("heimu ling", ob)){
		if( !ob->query_temp("warned") ) {
			command("say 你是谁？  怎么闯到日月神教里来了？！");
			command("say 快给我速速离开，下次看到决不轻饶！");
			ob->set_temp("warned", 1);
		}
		else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
		else {
			command("say 大胆狂徒，竟敢闯到日月神教里来撒野！！！\n");
			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	}       
}
