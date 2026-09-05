// d/diaoyudao/npc/yunv.c 渔家少女
// hongdou 98.10.01

#include <ansi.h>

inherit NPC;

int accept_object(object who, object ob);

void init()
{
//	object ob;

//	::init();
//	if (interactive(ob = this_player())
	add_action("do_kissher", "kissher");
	add_action("do_touchher","touchher");
}


void create()
{
	set_name(GRN"渔家少女"NOR, ({
		"shao nv",	 
		"luonv",
		"nv",
	}));
	set("long",
"她是一个十七八岁美丽的渔家少女，已经被东瀛武士撕光了衣服，
身上没有任何东西遮挡，只有双臂紧抱在胸前蜷缩在帐篷的角落里。
你看到这么美丽的少女以及诱人的胴体，不禁有些冲动，想去亲亲
她(kissher)，摸摸她(touchher)。\n"
	);
	set("gender", "女性");
	set("attitude", "friendly");
	set("age", 18);
	set("shen_type",1);
	set("str", 13);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 50);
	set("max_qi", 300);
	set("max_jing", 100);
	set("combat_exp", 800);
	set_skill("dodge", 20);
	set_skill("parry", 20); 
	set_skill("cuff", 40);
	
	setup();

}

int do_kissher()
{
	object me = this_player();
	object npc= this_object();
	object huan,ch;
	huan = new("d/diaoyudao/npc/obj/erhuan");
	if (me->query("gender")=="女性" ) 
	{
		message_vision(HIY "$N走上前去，轻轻吻了一下少女的脸颊......\n" NOR,me);
		message_vision("\n$N大惊失色，颤声道：「这位姐姐，你要...要做什么？\n"
			"奴家死也不受你的侮辱，爷爷，恕孙女不孝了......」\n",npc);
	}
	else
	{
		message_vision(HIY "$N扑上前去，疯狂地在少女头上、身上狂吻起来......\n" NOR,me);
		message_vision("\n$N大惊失色，颤声道：「你这个大色狼，奴家死也不受你的侮辱，\n"
			"爷爷，恕孙女不孝了......」\n",npc);
	}
	message_vision(HIR"\n$N说完一头撞在桌子角上，立刻香消玉殒!!! \n"NOR,npc);
	tell_object(me,"你从她的玉体上找到了一副耳环。\n");

	remove_call_out("si");
	call_out("si",2,me);
	me->set_temp("marks/死",1);
	me->add("shen",-500);
	huan->move(me);
	npc->die();
	return 1;
}

int do_touchher()
{
	object me = this_player();
	object npc= this_object();
	object huan,ch;
	huan=new("d/diaoyudao/npc/obj/erhuan");
	if (me->query("gender")=="女性" ) 
	{
		message_vision(HIY "$N走上前去，抚摩少女的裸露的肩臂，轻轻地安慰她......\n" NOR,me);
		message_vision("\n$N哭泣着投入$n的怀抱，哽咽道：「这位姐姐，多谢你救了我！」\n",npc,me);
		return 1;
	}
	else
	{
		message_vision(HIY "$N淫笑着扑上前去，伸出魔爪在少女的身上到处乱摸起来......\n" NOR,me);
		message_vision(HIY"\n$N大惊失色，冲$n怒骂道：「你这个大色狼，奴家死也不受你的侮辱，\n"
			"爷爷，恕孙女不孝了......」\n"NOR,npc,me);
		message_vision(HIR"\n$N说完一头撞在桌子角上，立刻香消玉殒!!! \n"NOR,npc);
		tell_object(me,"你从她的玉体上找到了一副耳环。\n");
		me->set_temp("marks/死",1);
		me->add("shen",-(random(5)+1));
		huan->move(me);
		npc->die();
		return 1;
	  }
}

int accept_object(object who, object ob)
{
	object obj,me,huan,npc;
	npc=this_object();
	me = this_player();
	
	if ((string)ob->query("name")=="东瀛和服") 
	{
		message_vision("\n$N"+HIC+"悲凄地对$n道：「奴家死也不穿东瀛狗的衣服！」\n"
			"随后少女又悲悲戚戚地哭了起来......\n\n" NOR,npc,me);
		return 0;
	}
	if ((string)ob->query("name")==HIM"女儿装"NOR && (string)ob->query("id")=="nver zhuang") 
	{
		if (me->query_temp("marks/救")) 
		{	
		message_vision("\n$N"+HIC+"对$n道：「我已经穿着衣服，不再需要它了！」\n\n"NOR,npc,me); 
		return 0;
		}
		message_vision(HIY"\n$N走过去将一件衣服遮住了她雪白的胴体......\n" NOR,me);
		message_vision(HIY
"\n少女止住哭泣，站起身来向$N盈盈一拜，道：「多谢恩公救命之恩，这是奴家的
贴身之物，麻烦恩公交给我爷爷，让他到海边来找我。」说完匆匆离去。\n" NOR,me);
		tell_object(me,"\n渔家少女给了你一副耳环。\n");
		huan= new(__DIR__"obj/erhuan");
		huan->move(me);
		call_out("destroy",1,npc);
		me->add("shen",(random(5)+1));
		me->set_temp("marks/救",1);
		return 1;
	}
	message_vision("\n$N"HIC+"凄然地对$n道：「恩公救了奴家，奴家怎么能要恩公的东西呢！」\n\n"
		"少女又悲悲泣泣地哭了起来：「奴家好命苦啊……」\n\n"NOR,npc,me);
	return 0;
}

void destroy(object ob)
{
	destruct(ob);
	return;
}
