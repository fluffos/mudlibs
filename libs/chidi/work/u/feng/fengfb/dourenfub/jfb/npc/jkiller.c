//edit by jerry
//2008.11.22

#include <ansi.h>
inherit NPC;

#define PRODUCT "/clone/shoufei/product"

void create()
{
	set_name(HIW"亡灵"NOR, ({ "wanlin"}));
	set("gender", "无性");
	set("age",26);
	set("long", "他是一位亡灵，心魔的手下。\n");
        set("attitude", "aggressive");
        set("no_update", 1);
        set("str", 200 + random(60));
        set("int", 200 + random(60));
        set("con", 200 + random(60));
        set("dex", 200 + random(60));
        set("kar", 200 + random(60));
	set("shen_type", -1);
        set("qi", 2000000 + random(300000));
        set("max_qi", 2000000 + random(300000));
        set("jing", 1000000 + random(300000));
        set("max_jing", 1000000 + random(300000));
        set("neili", 500000 + random(300000));
        set("max_neili", 500000 + random(300000));
        set("max_jingli", 500000 + random(300000));
        set("jingli", 200000 + random(300000));
        set("jh_dj/dj",20);
        set("jiali", 500 + random(200));
        set("combat_exp", 500000000 + random(300000000));
        set_skill("force", 1400 + random(300));
        set_skill("dodge", 1400 + random(300));
        set_skill("parry", 1400 + random(300));
        set_skill("sword", 1400 + random(300));
        set_skill("unarmed", 1400 + random(300));
        set_skill("dabei-zhang", 1400 + random(300));
        set_skill("damo-force", 1400 + random(300));
        set_skill("langzi-sword", 1400 + random(300));
        set_skill("piaomiao-shenfa", 1400 + random(300));
        map_skill("unarmed", "dabei-zhang");
        map_skill("force", "damo-force");
        map_skill("dodge", "piaomiao-shenfa");
        map_skill("parry", "dabei-zhang");
        map_skill("sword", "langzi-sword");
        prepare_skill("sword","langzi-sword");

    	set("chat_msg_combat", ({
        (: perform_action, "sword.huitou" :),
        (: perform_action, "sword.xia" :),
         }) );
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();

}

void init()
{
	
	call_out("findPlayer",5); //寻敌
}

void die()
{
	object me,ob,jmem,item;
	mapping team;
	int i,size,level,exp,rand,pot;
	string file;

	ob = this_object();
	me = ob->query_temp("last_damage_from");
	team = me->query_team();
	jmem = (object)me->query_temp("jfb/jfb_jmem");

//tell_object(find_player("jerry"),sprintf("%O %O %O\n",team,jmem,me));
	if(!team || !clonep(jmem) || !team || !me || !userp(me))
	{
		tell_room(environment(ob),HIM"亡灵逃跑了。\n"NOR);
		destruct(ob);
		return;
	}
	
	jmem->add("make_jboss",1);
	tell_room(environment(ob),HIM"轰~~~~！\n亡灵消失了。\n"NOR);

	size = sizeof(team);
	for(i=0;i<size;i++)
	{
		if(!team[i]) continue;
		level = team[i]->query("jh_dj/dj");
		exp = 500*(1+random(level))/size;

		if(exp)
		{
			pot = exp/3;
			tell_object(team[i],sprintf("你获得了%d点经验，%d点潜能。\n",exp,pot));
			team[i]->add("combat_exp",exp);
			team[i]->add("potential",pot);
		}
	}
	//掉宝
	rand = random(500);
//tell_object(find_player("jerry"),sprintf("killer: rand = %d",rand));
	if(rand < 10) file = PRODUCT->get_random_level_product(1+random(15),me->query("jh_dj/dj")-5,me->query("jh_dj/dj"));
	else if(rand < 5) file = PRODUCT->get_random_level_product(1+random(15),me->query("jh_dj/dj"),me->query("jh_dj/dj"));

	if(file)
	{
		item = new(file);
		if(item)
		{
			ob = this_object();  //NPC
			me = ob->query_temp("last_damage_form"); //玩家
			"/adm/item/equip"->init_equip_prop_1(item);  //变更装备品质
			item->move(environment(ob));
		}
	}
        rand = random(1000);
	if(rand > 15)
	{
		item = new("/clone/money/thousand-gold");
		if(item)
		{
			item->set_amount(1+random(1));
			item->move(environment(ob));
		}
	}
        else if(rand > 8)
	{
		item = new("/d/jfb/obj/perwan");
		if(item)
		{
			item->move(environment(ob));
		}
         }
         else if(rand > 6)
	{
		item = new("/d/jfb/obj/karwan");
		if(item)
		{
			item->move(environment(ob));
		}
         }
        else if(rand > 4)
	{
		item = new("/d/jfb/obj/jinglidan");
		if(item)
		{
			item->move(environment(ob));
		}
         }
        else if(rand > 2)
	{
		item = new("/d/jfb/obj/neilidan");
		if(item)
		{
			item->move(environment(ob));
		}
         }
	destruct(ob);
}

//函数：寻敌
void findPlayer()
{
	object map,*players,ob;
	int i,size,rand;
	
	ob = this_object();
	map = environment(ob);
	players = all_inventory(map);
	
	size = sizeof(players);
	rand = random(size);
	if(userp(players[rand])) ob->kill_ob(players[rand]);
	call_out("findPlayer",1+random(5));
}
