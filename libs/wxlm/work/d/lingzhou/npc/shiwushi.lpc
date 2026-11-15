// shiwushi.c

inherit NPC;


void create()
{
	set_name("石人武士", ({ "wu shi", "shi" }));
	set("gender", "男性");
	set("age", random(10) + 20);
	set("str", 25);
	set("dex", 16);
	set("long", "这是守护西夏王陵的石人武士，虽然笨拙，但是却十分强大。\n");
	set("combat_exp", 3000000);
	set("shen_type", 1);
	set("attitude", "aggressive");

	set_skill("unarmed", 380);
	set_skill("force", 380);
	set_skill("club", 380);
	set_skill("zhongping-qiang", 380);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	map_skill("club", "zhongping-qiang");
	set_temp("apply/attack", 300);
	set_temp("apply/armor", 350);
	set_temp("apply/damage", 150);

	set("neili", 10000); 
	set("max_neili", 10000);
	set("max_qi", 50000);
	set("max_jing", 50000);
	set("jiali", 30);

	setup();
	carry_object("/d/city/npc/obj/tiejia")->wear();
	carry_object("/clone/weapon/changqiang")->wield();
}

void die()
{
	object ob;
	int num,exp, pot, ww, sc;

	exp = random(400) + 200;
	pot = random(300) + 150;
	ww = random(30) + 30;
	sc = random(40) + 40;

	if ( objectp(ob = query_last_damage_from()) )
	{
		ob->add("combat_exp", exp);
		ob->add("potential", pot);
		ob->add("score", sc);
		ob->add("weiwang", ww);
		tell_object(ob,"石人武士轰的一声倒在地上碎成了一堆乱石块儿！\n");
		num = time() - environment()->query("start_time");
		num = (900 - num)*2;
		if(num<0) num = 0;
		num += 1000;
		num -= 500*(ob->query("max_qi")-ob->query("qi"))/ob->query("max_qi");
		if(num>0&&mapp(ob->query("banghui")))
		{
			WARS_D->set_data("wangling/"+ob->query("banghui/name")+"/pot",WARS_D->query_data("wangling/"+ob->query("banghui/name")+"/pot")+num);
			tell_object(ob,"你在今天的王陵争霸赛中为本帮做出了"+num+"点贡献！\n");
		}
		tell_object(ob, HIC "你获得了" + exp +"点经验、" + pot + "点潜能、"+sc+"点江湖阅历以及" + ww + "点江湖威望。"NOR"\n");
	}
	destruct(this_object());
}
