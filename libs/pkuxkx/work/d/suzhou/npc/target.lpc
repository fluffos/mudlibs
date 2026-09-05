// 朱三太子的线人
// created by Zine 30 Sep 2010

inherit NPC;
#include <ansi.h>
#include <random_name.h>


int ask_secret();
int ask_secret2();
void consider();

void create()
{
	set_name(get_rndname(), ({get_rndid(), }));
	set("gender", "男性" );
	set("long", "一个一脸菜色的家伙，目光毫无神采。\n");
	set("str", 20);
	set("int", 20);
	set("dex", 20);
	set("kar", 20);       
	set("qi", 100);
	set("max_qi", 100);
	set("jing", 100);
	set("max_jing", 100);
	set("eff_jingli", 10);
	set("neili", 10);
	set("max_neili", 10);
	set("jiali", 1);
	set("shen_type", 1);
    set("env/wimpy", 1);
	set("uni_target",1);
	set("combat_exp", 10000);
	set("inquiry", ([
		"情报" : (: ask_secret :),
        "密探" : (: ask_secret2 :),
         	

	]));
	set("chat_chance", 50);
	set("chat_msg", ({
		(: random_move :),
		(: random_move :),
		(: random_move :),
	}) );
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	call_out("dest",300);
}

int dest()
{
	if (this_object()->set("come"))
	{
		call_out("dest",60);
	}
	else
	{
		message_vision(this_object()->query("name")+"说道：“看来没人来接应我了，我就自己接应自己吧。”\n",this_object());
		destruct(this_object());
	}
}

int ask_secret2()
{
	object ob=this_object();
	object me=this_player();
	message_vision(ob->query("name")+"说道：“作为一个密探，最重要的是眼观六路，耳听八方。”\n",ob);
	message_vision(ob->query("name")+"说道：“但同时，我们的感情是丰富的。”\n",ob);
	command("laugh");
	command("hate");
	command("sob");
	command("cry");
	return 1;
}


int ask_secret()
{
	object me=this_player();
	if (me->query("id")!=this_object()->query("zhusan"))
	{
		command("knife " + me->query("id"));
		if((int)me->query("qi")<200)
		{
			me->unconcious();
		}
		else
		{
			me->add("qi",-200);
		}
		return 1;
	}
	else
	{
		command("yi " + me->query("id"));
		command("welcome " + me->query("id"));
		command("say 你的信物带来了吗？如果你带了，为什么不给我呢？如果没带的话，我怎么知道你是真的呢？");
		me->set_temp("zhusan/spy",1);
		this_object()->set("come",1);
		return 1;
	}
}

int accept_object(object me, object xw)
{
	object paper;
	if (me->query("id")!=this_object()->query("zhusan"))
	{
		return notify_fail(this_object()->query("name")+"你认错人了吧？虽然我们好像在哪见过，毫无疑问你是个可耻的NPC！\n");
	}
	if (!me->query_temp("zhusan/spy"))
	{
		return notify_fail(this_object()->query("name")+"素不相识，你给我东西干嘛？当我是垃圾桶啊？\n");
	}
	if( xw->query("id") != "xin wu")
	{
		return notify_fail(this_object()->query("name")+"怒道，你这个人到底啥意思？老乱给我东西。\n");
	}
	if (xw->query("owner")!=me->query("id"))
	{
		return notify_fail(this_object()->query("name")+"道：你从哪捡来的破玩意，敢来忽悠我？\n");
	}
	else
	{
		if (random(10)>8||me->query("family/family_name")=="朝廷")
		{
			message_vision(this_object()->query("name")+"说道：“好吧，既然你不是水货，我就把这份情报交给你，你送给老夫子去吧”。\n",me);
			tell_object(me,this_object()->query("name")+"交给你一摞资料。\n");
			paper=new(__DIR__"obj/paper");
			paper->set("owner",me->query("id"));
			paper->move(me);
			return 1;
		}
		else
		{
			message_vision(this_object()->query("name")+"脸色一变：不好，有敌情，你带情报撤退，我掩护。\n",me);
			tell_object(me,this_object()->query("name")+"交给你一摞资料。\n");
			tell_object(me,this_object()->query("name")+"不由你分说，把你塞上备好的马匹，还在马屁股上狠狠一刺。\n");
			paper=new(__DIR__"obj/paper");
			paper->set("owner",me->query("id"));
			paper->move(me);
			if (me->query("skfxiang")>25)
			{
				tell_object(me,"你眼中一亮，恶从胆边生，准备把这些情报送给睿亲王多尔衮。\n");
			}
			call_out("escape",1,me);
			return 1;
		}
	}
}


void random_move(object me)
{
	mapping exits=environment()->query("exits");
	string *dirs;
	object luanru;
	string dir;
	object ob=new(__DIR__"attacker");
	if(!environment()) return 0;
    if(sizeof(environment()->query("exits")) == 0) return 0;
    if( !mapp(exits = environment()->query("exits")) ) return 0;
    if (!me) return 0;
	dirs = keys(exits);
	dir = dirs[random(sizeof(dirs))];
	luanru = exits[dir];
	if (me)  
	me->move(luanru);
	ob->set("attack",me->query("id"));
	ob->move(luanru);
	
}

void random_move2(object me)
{
	mapping exits=environment()->query("exits");
	string *dirs;
	object luanru;
	string dir;
	if(!environment()) return 0;
    if(sizeof(environment()->query("exits")) == 0) return 0;
    if( !mapp(exits = environment()->query("exits")) ) return 0;
    if (!me) return 0;
	dirs = keys(exits);
	dir = dirs[random(sizeof(dirs))];
	luanru = exits[dir];
	if (me)  
	me->move(luanru);
	tell_object(me,HIB"你终于摆脱了投靠清廷的武林败类的追杀。\n"NOR);
	
}

int escape(object me)
{	
	if (random(200)>50)
	{
		tell_object(me,"马儿吃痛狂奔开去，转眼把所有敌兵抛在身后。\n");  
		random_move(me);
	}
	else
	{
		tell_object(me,"你觉得屁股一痛，不由想破口大骂：你扎马啊！扎我干嘛。\n");
		tell_object(me,"你痛得几乎要昏了过去，赶紧抱紧马脖子，远远逃去。\n");
		me->add_busy(1);
		random_move(me);
	}
	call_out("esp1",1,me);
	return 1;
}

int esp1(object me)
{
	tell_object(me,"马儿吃痛狂奔开去，转眼把所有敌兵抛在身后。\n");  
	me->add_busy(1);
	random_move(me);
	call_out("esp2",1,me);
	return 1;
}

int esp2(object me)
{
	tell_object(me,"马儿吃痛狂奔开去，转眼把所有敌兵抛在身后。\n");  
	me->add_busy(1);
	random_move(me);
	call_out("esp3",1,me);
	return 1;

}

int esp3(object me)
{
	tell_object(me,"马儿吃痛狂奔开去，转眼把所有敌兵抛在身后。\n");  
	me->add_busy(1);
	random_move(me);
	call_out("esp4",1,me);
	return 1;
}

int esp4(object me)
{
	tell_object(me,"马儿吃痛狂奔开去，转眼把所有敌兵抛在身后。\n");  
	me->add_busy(1);
	random_move2(me);
	destruct(this_object());
	return 1;
}