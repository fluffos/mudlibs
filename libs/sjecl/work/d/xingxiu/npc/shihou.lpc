// shihou.c 狮吼子
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_job();

void create()
{
	set_name("狮吼子", ({ "shihou zi", "shihou", "zi" }));
	set("nickname", "星宿派二师兄");
	set("long", "他双耳上各垂着一只亮晃晃的黄大环，狮鼻阔口，形貌颇为凶狠诡异。\n");
	set("gender", "男性");
	set("age", 43);
	set("attitude", "peaceful");
	set("str", 28);
	set("int", 20);
	set("con", 26);
	set("dex", 23);

	set("max_qi", 1900);
	set("max_jing", 1900);
	set("eff_jingli", 1400);
	set("combat_exp", 600000);
	set("score", -8000);

	set_skill("force", 120);
	set_skill("huagong-dafa", 120);
	set_skill("dodge", 120);
	set_skill("zhaixingshu", 120);
	set_skill("strike", 120);
	set_skill("chousui-zhang", 120);
	set_skill("parry", 120);
	set_skill("staff", 120);
	set_skill("poison", 120);
	set_skill("tianshan-zhang", 120);
	set_skill("literate", 50);
	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixingshu");
	map_skill("strike", "chousui-zhang");
	map_skill("parry", "chousui-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	set("chat_chance_combat", 5);
	set("chat_msg_combat", ({
		(: exert_function, "huagong" :),
		(: perform_action, "strike.yinhuo" :),
		(: perform_action, "strike.biyan" :),
	}));
	create_family("星宿派", 2, "弟子");
	set("inquiry", ([
		"星宿派" : "你想加入，就拜我为师。",
		"星宿海" : "去星宿海干什么？拜我为师就够你学的了。",
		"丁春秋" : "丁春秋是你叫的吗？没大没小的。以后叫老仙！",
		"老仙"  : (: ask_job :),
	]));

	setup();
	UPDATE_D->get_cloth(this_object());
	carry_object("/d/xingxiu/obj/yao");
	carry_object("/d/xingxiu/obj/fire");
}

void attempt_apprentice(object ob)
{
	if(ob->query("family/family_name") != "星宿派"){
		say("狮吼子对"+ob->name()+"理都不理。\n");
		return;
	}
	if(ob->query_skill("huagong-dafa",1) < 45 || ob->query("shen") > -500){
		command("say 你的条件还不够，我才不想收你呢。");
		return;
	}
	command("say 好吧，看来你的化功大法有点基础了，我就收下你吧。");
	command("recruit " + ob->query("id"));
}

string ask_job()
{
	object me, ob;
	mapping fam;
  	int shen, exp;
  	me = this_player();
  	fam = (mapping)me->query("family");
  	shen = me->query("shen");
  	exp=me->query("combat_exp",1);

    	if(!fam) return "看得出你对老仙态度恭敬，何不加入我星宿派呢？";
    	if(fam["family_name"] != "星宿派" && !me->query_temp("ding_flatter"))
       		return "你对老仙的态度看上去不太恭敬啊！";
    	if(exp < 100000)
    		return "哈哈哈，你再加把力练功吧。";
    	if(exp >= 400000)
    		return "老仙最近的情况我不太清楚，你自己去问问他老人家吧。";
    	if(me->query_condition("wait_xx_task"))
    		return "上次搞砸了，这次你就等等吧。";
	if( me->query("job_name") == "老仙分忧")
		return "老仙现在心情还好，不用你来为老仙分忧。";
    	if( me->query_temp("xx_job"))
    		return "你怎么还在这里发呆？";
    	if( me->query_condition("wait_xx_task"))
    		return "老仙现在心情还好，不用你来为他分忧。";
    	ob = new("/d/xingxiu/obj/di");
    	ob->move(me);
    	ob->set("name", MAG "紫玉短笛" NOR);
    	ob->set("long", MAG"这玉笛短得出奇，只不来七寸来长、通体紫红，晶莹可爱。\n" NOR);
    	ob->set("xx_user", getuid(me));
    	if(fam["family_name"] != "星宿派")
      		me->set_temp("title", MAG"星宿派门客"NOR);
    	me->set_temp("xx_job", 1);
    	message_vision("\n$N拿出一只玉制短笛，交给$n。\n", this_object(), me);
    	return "老仙最近心情不佳，你可要多多为他老人家分忧才是！\n";
}
