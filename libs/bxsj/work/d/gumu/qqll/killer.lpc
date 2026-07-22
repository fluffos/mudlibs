// killer.c 蒙面杀手
// kxkxkx 2004年3月

#include <ansi.h>

inherit FIGHTER;

void create()
{
   set_name("蒙面杀手", ({"mengmian shashou", "shashou", "killer"}));
	set("gender", "男性");
   set("long", "这个拦路的黑衣杀手一脸凶相。\n");
	set("age", random(20) + 25);      

	set("str", 15 + random(5));
   set("int", 20 + random(5));  
   set("con", 20 + random(5));     
   set("dex", 20 + random(5));

	set("no_get", 1);
   set("env/no_guard", 1);
   set("env/no_fight", 1);
   set("no_ansuan", 1);
   
   // ugly hack, 防止蒙面杀手自动yun heal
   set("mute", 1);

   set("combat_exp", 100000);
	set("no_quest", 1);   
   set("shen_type", -1);
   set("attitude", "peaceful");
	set("max_qi",1200);
   set("max_jing",1200);
   set("neili",1000);
   set("max_neili",1000);
	set("score", 100);

   set_skill("force", 100); 
   set_skill("dodge", 100);
   set_skill("parry", 100);
	
   set_temp("no_return",1);

   set("chat_chance_combat", 3);
   set("chat_msg_combat", ({
      "蒙面杀手恶狠狠地说道：乖乖地把东西交出来。\n",
   }));

   setup();
   if(clonep())
   {
   	carry_object(ARMOR_D("cloth"))->wear();
   	add_money("gold", 2 + random(3));
   	call_out("wave",300);
   }
}

void wave()
{
   object self;
   self = this_object();
   message_vision("$N好象突然想起什么事，急急忙忙的离开了。\n", self);
   destruct(self);
}

void kill_ob(object obj)
{
   object qqll, pal;
   
   qqll = query("target", 1);
   pal = qqll->query("pal", 1);
   if(obj != environment(qqll) &&
         obj != qqll->query("pal", 1)) {  // 如果不是team中的，就不相互kill
      remove_enemy(obj);
      obj->remove_killer(this_object());
      return;
   }
   ::kill_ob(obj);
}

void unconcious()
{
   object self, qqll;
   
   qqll = query("target");
   if(qqll)
   {
   	qqll->delete("killer");
   	qqll->add("killers", 1);
	}
   self = this_object();
   command("say 好汉饶命，这些黄金请笑纳。\n");
   //remove_all_killer();    // 停止战斗才好drop gold   
   //add_busy(-query_busy());   // 去掉busy, 才能drop东西
   start_busy(-1);
   interrupt_me();
   command("drop gold");
   tell_room(environment(), HIR + query("name") +
      "转身几个起落就不见了。\n"NOR);
   destruct(self);
}

void die()
{
   unconcious();
}

void no_die_ppl(object ob,object obj)
{
	remove_call_out("no_die_ppl");
	
	if(!ob) return;
			
	if(!living(ob))
	{
		ob->set("qi",100);
		message_vision("$N鼻子里哼了一声：「既然王重阳的遗物到手了，就放过你小子吧。风紧，扯呼……」。\n",this_object());		
		message_vision("$N几个起落，已经消失不见。\n",this_object());		
		if(obj) destruct(obj);
		destruct(this_object());
		return;
	}
	
	call_out("no_die_ppl",1,ob,obj);
}