// cyl.c 淳于蓝
// kxkxkx 2004年3月

#include <ansi.h>

inherit NPC;

int cancel_leave();

private nomask void leave();

string ask_me()
{
	object me = this_player();
	
	if ( present("qiyan stone", me)) me->set_temp("askqysd",1);
	
	return "你说的什么宝贝，小老儿我倒没听过。\n";
}

void create()
{
   set_name("淳于蓝", ({"chunyu lan", "chunyu", "lan"}));
   set("title", HIW"江南神匠"NOR);
   set("gender", "男性");
   set("age", 45);
   set("long", "一个不知来自何方的匠师。\n");

   set("attitude", "friendly");
   set("no_bark",1);
   set("per", 30);
   set("str", 20);
   set("int", 20);
   set("con", 20);
   set("dex", 20);

   set("combat_exp", 100000);
   set("shen_type", 1);

   set("max_neili", 100);
   set("neili", 1000);
   set("jiali", 0);
   
   set_skill("force", 100); 
   set_skill("dodge", 100);
   set_skill("parry", 100);
   set_skill("cuff", 100);

   set("inquiry", ([
      "七眼石" : (:ask_me:),
   ]));

   set_temp("apply/attack", 50);
   set_temp("apply/defense", 50);
   set_temp("apply/damage", 15);

   setup();
   if(clonep())
   {
   	carry_object(ARMOR_D("cloth"))->wear();   	
   	call_out("leave", 120);
   	call_out("sure_leave", 300);
   }	
}

int accept_object(object who, object ob, object me)
{
	if( !ob->can_cmds() ) return 0;	
	if( ob->query("cyl", 1) != this_object() && !(wizardp(who) && who->query("env/test"))  ) return 0;	
	if(!who->query_temp("askqysd")) return 0;	
	cancel_leave();	
	who->delete_temp("askqysd");
	call_out("move_back",1,ob,who);	
	return 1;
}

void move_back(object ob,object user)
{
	object cyl;
	
	remove_call_out("move_back");
	cyl = this_object();
	if(!ob || !user) return;	
	ob->move(user);		
	switch(ob->query("max_killers")) {
		case 3:
		ob->set("ok", 1);
		message_vision("$N诡异地一笑：「壮士你可别告诉别人啊。小老儿其实只是个混江湖骗饭吃的，\n哪里知道这些奥妙的东西啊。」\n",cyl);
		message_vision("$n给$N一"+ob->query("unit")+ob->query("name") + "。\n",user,cyl);
		message_vision("$N一眨眼，又不知到哪里去了。\n",cyl);
		destruct(cyl);
		break;
		case 4:
		ob->set("ok", 2);
		cyl->force_me("say 此乃西方七窍玉，化成顽石之态。倒也算个宝贝，\n但毕竟不是什么稀罕物件。居然还有人以此为傲，真是令人不解啊。");
		message_vision("$n给$N一"+ob->query("unit")+ob->query("name") + "。\n",user,cyl);
		message_vision("$N一眨眼，又不知到哪里去了。\n",cyl);
		destruct(cyl);
		break;
		default:
		ob->set("ok", 3);
		message_vision("$N开始细细品鉴着"+ob->name()+ "。\n",cyl);
		user->start_busy(10);
		call_out("give_hook_completion", 10,user,ob);
		break;
	}
}

void give_hook_completion(object user,object ob)
{
	ob->give_hook_completion(user);
}

private nomask void sure_leave()
{
   object self;
         
   self = this_object();
   message_vision("$N好象突然想起什么事，急急忙忙的离开了。\n", self);
   destruct(self);
}


// 试图取消离开，因为这时玩家要把七窍玲珑给淳于蓝
int cancel_leave()
{
   return remove_call_out("leave") != -1;
}

// 120秒后离开的call_out
private nomask void leave()
{
   object self;
   
   self = this_object();
	message_vision("$N好象突然想起什么事，急急忙忙的离开了。\n", self);
	destruct(self);
}

// 避免被打晕，从送信npc处拷贝
void unconcious()
{
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
}

// 避免被打死，从送信npc处拷贝
void die()
{
	unconcious();
}

// 避免跟人打架，从送信npc处拷贝
void kill_ob(object obj)
{
	object me = this_object();

	command("!!!");
	me->remove_enemy(obj);
	obj->remove_killer(me);
	return;
}

// 避免跟人打架，从送信npc处拷贝
void accept_fight(object obj)
{
	command("peace " + obj->query("id"));
	return;
}