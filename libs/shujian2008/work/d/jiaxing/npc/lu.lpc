// lu.c 陆无双
// By River@SJ 
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("陆无双", ({ "lu wushuang", "lu", "wushuang" }));
	set("long", "只见她一张瓜子脸，颇为俏丽，皮色虽然不甚白皙，但容貌秀丽。\n");
	set("gender", "女性");
	set("age", 17);
	set("attitude","firendly");
	set("str", 22);
	set("dex", 23);
	set("con", 20);
	set("int", 24);
	set("per", 25);
	set("shen_type", 1);

	set_skill("parry", 120);
	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("sword", 120);
	set_skill("throwing",100);
	set_skill("meinu-quanfa", 120);
	set_skill("cuff", 120);
	set_skill("meinu-quanfa", 120);       
	set_skill("yunu-shenfa", 120);
	set_skill("yunu-jianfa", 120);
	set_skill("yunu-xinjing", 120);
	map_skill("force", "yunu-xinjing");
	map_skill("dodge", "yunu-shenfa");
	map_skill("cuff", "meinu-quanfa");
	map_skill("sword", "yunu-jianfa");
	prepare_skill("cuff", "meinu-quanfa");

	set("combat_exp", 700000);

	set("max_qi", 1700);
	set("max_jing", 1200);
	set("eff_jingli", 1200);
	set("neili", 2500);
	set("max_neili", 2500);
	set("jiali",30);

	set("chat_chance", 60);
	set("chat_msg", ({ (: random_move :) }) );

	setup();
	carry_object("/d/gumu/obj/qun1")->wear();
	carry_object(BINGQI_D("changjian"))->wield();
	call_out("dest", 1500, this_object());
}

void dest(object ob)
{
	if(!ob) return;
	destruct(ob);
}

void unconcious()
{
	object me, book;
	me = query_temp("last_damage_from");
	
	if(!objectp(me)){
		tell_room(environment(this_object()),CYN"\n陆无双娇哼一声：原来是巫师大人啊。。。那我乖了。。我回家去。\n\n"NOR);
		destruct(this_object());
		return;
	}
        
	if (me->query_temp("limochou/ask")){
		book = new(__DIR__"obj/wudu");
		book->set("owner", me->query("id"));
		book->move(me);
		message_vision(CYN"\n陆无双娇哼一声：还不就是本臭书么，我不要了。\n\n"NOR,me);
		message_vision("言毕，陆无双将一本书丢了过来，顺势往后跃开数步，$N接过书后，当下，也不再追赶。\n\n",me);
		destruct(this_object());
		return;
	}
	else{
		message_vision(CYN"\n陆无双说道：小女子可不奉陪了。\n\n"NOR,me);
		message_vision("话音未落，陆无双一个转身已然远去。\n\n",me);
		destruct(this_object());
		return;
	}
}

void die()
{
	unconcious();
}
