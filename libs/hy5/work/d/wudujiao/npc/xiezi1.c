// by victori
inherit NPC;
#include <ansi.h>


string *first_name = ({"五毒", "长螯", "双头", "花斑"});
string *name_words = ({"蝎子"});
void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];
        set_name(name,({"xie zi"}));
	set("race", "野兽");
        set("long", "一条半尺来长，鬼头鬼脑的小蝎子。\n");
	set("age", 100);
	set("attitude", "peaceful");

	set("max_jing", 1200);
	set("max_qi", 1300);
	set("jing", 1600);
	set("qi", 1600);
       set_skill("unarmed",180);
       set_skill("parry",180);
       set_skill("dodge",180);
       set_skill("force",180);
	set("str", 20);
	set("con", 50);

	set("limbs", ({ "头部", "身体", "尾巴" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 40);

	set("combat_exp", 10000);
 
        set_weight(5000);
	setup();
}
int init()
{
        object me,who;
        ::init();
        who = this_object();
        if (interactive(me = this_player()))
        {
	if (me->query("id")==who->query_temp("kill_name"))          
              {
	       remove_call_out("kill_ob");
               call_out("kill_ob", 1, me);
		}
        }
       add_action("do_attack","attack");
       add_action("do_stop","stop");
       add_action("do_send","sendto");
       add_action("do_sha","sha");
       add_action("do_guard","guard");
	add_action("do_hit","hit");
	add_action("do_hit","kill");
	add_action("do_hit","touxi");
//	remove_call_out("do_baohu");
//	call_out("do_baohu",5);

}



int do_attack(string arg)
{
  object ob; 
  
  object me=this_player();
  object who=this_object();
 //  if(query("id")=="shuang er")
 //  {say("你无权使用此命令。\n");
 //  return 0;}
 // sscanf(query("id"),"dushe",host_id);
  if(me->query("id")!=(who->query("host_id")))
  return notify_fail(who->query("name")+"连理都不理你！\n");
  if(!arg||!objectp(ob=present(arg,environment(me))))
	return notify_fail(who->query("name")+"傻傻地望着你，不明白你的意思。\n");
  if(ob->query("id")==me->query("id"))
	return notify_fail(who->query("name")+"急忙把头一低，似乎不愿意去干。\n");
  if( ob->query_temp("no_kill") )
       return notify_fail("不能打，打不得啊！\n");
  if((int)ob->query("age") <= 17 && userp(ob) && !ob->query_condition("killer"))
       return notify_fail("为了世界更美好，放过小孩子吧.\n");

  if(!living(ob)) 
	 return notify_fail(who->query("name")+"说:"
              +ob->query("name")+"已经这样啦你还要...??!!\n");
  message_vision(who->query("name")+"吱吱怪叫一声冲了出去.\n",me);
  fight_ob(ob);
  return 1;
}

int do_stop()
{
 object who=this_object();
  
  object me=this_player();
 // if(query("id")=="dushe")
 // return notify_fail("你无权使用此命令。\n");
 //   sscanf(query("id"),"%s's shuang er",host_id);
  if(me->query("id")!=(who->query("host_id")))
  return notify_fail(who->query("name")+"连理都不理你！\n");
 who->set_leader(me);
message_vision("$N对"+who->query("name")+"喝道：别打了，跟我来。\n",me);
// if(!is_fighting())
//	 return notify_fail(who->query("name")+"现在没和人打斗.\n");
 command("halt");
 who->delete_temp("kill_name");
 message_vision(who->query("name")+"乖乖的回到$N身边。\n",me);
 return 1;
}

int do_sha(string arg)
{
  object who=this_object();
  
	object me,ob;

	me = this_player();
  if(me->query("id")!=(who->query("host_id")))
  return notify_fail(who->query("name")+"连理都不理你！\n");
	if(!arg||!objectp(ob=present(arg,environment(me))))
	return notify_fail("你要"+who->query("name")+"杀谁？\n");
  if(ob->query("id")==me->query("id"))
	return notify_fail(who->query("name")+"急忙把头一低，似乎不愿意去干。\n");
  if( ob->query_temp("no_kill") )
       return notify_fail("不能打，打不得啊！\n");
  if((int)ob->query("age") <= 17 && userp(ob) && !ob->query_condition("killer"))
       return notify_fail("为了世界更美好，放过小孩子吧.\n");

	if(!environment(ob)->query("no_fight"))
	{
        message_vision(who->query("name")+"吱吱怪叫一声冲了出去.\n",me);
	command("say 嘿嘿,你认命吧，主人要我杀了你!");
	who->set_leader(ob);
       who->set_temp("kill_name",ob->query("id"));
	remove_call_out("kill_ob");
  	call_out("kill_ob", 0, ob); 
	}
	return 1;
}       
int hit_ob(object me, object ob, int damage)
{
       if ((string)ob->query("family/family_name") != "五毒教") {
	     	ob->apply_condition("xiezi_poison", 20
              +(int)ob->query_condition("xiezi_poison") );
              tell_object(ob, HIG "你觉得被咬中的地方一阵麻木！\n" NOR );
	}
}
void die()
{
       object ob;
       message_vision("$N倒在地上，死了！\n", this_object());
       ob=new(__DIR__"obj/xiezidu.c");
	ob->move(environment(this_object()));
	destruct(this_object());
      
//     return 1;
//	::die();
}
int do_guard(string arg)            //160
{
  object who=this_object();
       int i ;
	object me,ob;
	object* enemy;
	me = this_player();
       if(me->query("id")!=(who->query("host_id")))
            return notify_fail(who->query("name")+"连理都不理你！\n");
	if(!arg)
	ob = this_player();
	if(arg){
        if(!present(arg,environment(me)))
        return 0;
        if(!me)
        return 0;

              if(!userp(present(arg,environment(me))))
	           return notify_fail("你要"+who->query("name")+"保护谁？\n");
              }
	if(arg)
            ob = present(arg,environment(me));
       who->set_temp("guard_ob",ob->query("id"));
 	message("vision",
		 name() + "发出轻微的吱叫声，开始绕着"+ob->name()+"四处游走！\n" NOR,environment(), this_object() );
	enemy = ob->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else enemy[i]->kill_ob(this_object());
		}
	}
//       ob->remove_all_killer();
	who->set_leader(ob);
	return 1;
}       
int do_hit(string arg)
{
	object ob = this_object();
	object me = this_player();

	
	if (!arg )  return 0;
       if (arg != ob->query_temp("guard_ob")) return 0;
	message_vision("$N一声怪叫忽然挡在了"+me->name()+"的面前。\n", this_object());
	remove_call_out("kill_ob");
  	call_out("kill_ob", 0, me); 
	return 1;
}

