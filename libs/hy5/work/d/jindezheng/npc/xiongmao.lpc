#include <ansi.h>
inherit NPC;

string query_save_file() { return DATA_DIR + "npc/熊猫儿"; }

void create()
{
	set_name("熊猫儿", ({ "xiongmaoer", "xiongmaoer", "xiongmaoer" }) );
	set("gender", "男性" );
	set("age", 22);
      set("combat_exp",1130000+random(1140000));
	set("attitude", "friendly");
	set("no_get", "1");


      set("long","此人身长八尺，沈眉大眼，腰畔斜插着柄无鞘短刀，手
里提着只发亮的酒葫芦，一面高歌，一面痛欢。他蓬
头敞胸，足登麻鞋，衣衫打扮虽然落魄，但龙行虎步，
神情间却另有一股目空四海，旁若无人的涝洒豪迈之气!\n");
      set("chat_chance",5);
      set("chat_msg",({
                HIG+"熊猫儿拿起酒葫芦喝了几口酒，眯起眼睛嘘了口气!\n"+NOR,
                HIG+"熊猫儿叹道：千金挥手美人轻，自古英雄多落魄，且借壶中陈香酒，还我男儿真颜色.\n"+NOR,
                (:random_move:),
              })); 
      set("combat_exp",1130000+random(1140000));
      set("str",40);
      set("per",56);
	set_skill("cuff", 250);
	set_skill("force", 280);
	set_skill("blade", 200);
	set_skill("dodge", 180);
	set_skill("parry", 200);
	set_skill("sword", 350);
	set_skill("strike", 250);
	set_skill("kuangfeng-jian", 320);
	set_skill("zixia-shengong", 300);
	set_skill("poyu-quan", 300);
	set_skill("fanliangyi-dao", 300);
	set_skill("huashan-sword", 300);
	set_skill("hunyuan-zhang", 300);
	set_skill("lonely-sword", 350);
	set_skill("feiyan-huixiang",300);
	set_skill("literate", 200);
        set_skill("zhengqijue",300);
        set_skill("hunyuan-zhang", 350);
        set_skill("poyu-quan", 350);        
        set_skill("huashan-neigong", 350);        
        set("fengset",1);
	map_skill("cuff", "poyu-quan");
	map_skill("force", "zixia-shengong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "lonely-sword");
	map_skill("sword", "lonely-sword");
	map_skill("blade", "fanliangyi-dao");
	map_skill("strike", "hunyuan-zhang");



	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.jiushi" :),
		(: perform_action, "sword.pozhao" :),
		(: perform_action, "sword.poqi" :),
		(: perform_action, "sword.pozhang" :),
		(: perform_action, "sword.pojian" :),
		(: perform_action, "sword.podao" :),
		(: perform_action, "sword.zongjue" :),
	}) );
	if(random(10)>5)
		set("mingwang",-(int)query("mingwang"));
      setup();
      carry_object("/clone/misc/cloth")->wear();
      carry_object(__DIR__"obj/jiuhulu");
      	carry_object("/clone/weapon/changjian")->wield();
      add_money("silver",80);
}

void init()
{
	object ob;
	::init();
	if((int)query("mingwang")<0)
		set("nickname","恶棍");
	else
		set("nickname","游侠");

        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	int my_mw,y_mw;
	string banghui;

	if( !ob || environment(ob) != environment() ) return;
	banghui=(string)ob->query("banghui");
	if(banghui && banghui==(string)query("banghui"))	return;
	my_mw=(int)query("mingwang");
	y_mw=(int)query("mingwang");

	if(my_mw<0 && y_mw>5000)	{
		command("grin "+ob->query("id"));
		kill_ob(ob);
		ob->fight_ob(this_object());
		return;
	}
	if(my_mw>0 && y_mw<-5000)	{
		command("grin "+ob->query("id"));
		kill_ob(ob);
		ob->fight_ob(this_object());
		return;
	}
}
