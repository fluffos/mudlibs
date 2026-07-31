// by victori
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("三足金蟾",({"chan chu"}));
	set("race", "野兽");
        set("long", "一只拳头大小通身金黄的小蟾蜍，据说只有月宫才有。\n");
	set("age", 10000);
	set("attitude", "peaceful");

	set("max_jing", 9500);
	set("max_qi", 9500);
	set("jing", 9600);
	set("qi", 9600);
       set_skill("unarmed",180);
       set_skill("parry",180);
       set_skill("dodge",180);
       set_skill("force",180);
	set("str", 40);
	set("con", 50);

	set("limbs", ({ "头部", "身体", "尾巴" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 200);
       set_skill("unarmed",180);
       set_skill("parry",180);
       set_skill("dodge",180);
       set_skill("force",180);
	set("combat_exp", 500000);
 
        set_weight(500000);
	setup();
}
void init()
{
        object me;
        add_action("do_xun", "xun");
//       object me,ob;
//        ::init();
        if (interactive(me = this_player()))
        {
      	       remove_call_out("kill_ob");
              call_out("kill_ob", 1, me);
        }
        ::init();
}
int do_xun(string arg)
{
	object me,who;
	me =this_object();
	who=this_player();
	if (!arg || (arg != "chan chu"))
		return notify_fail("你要驯服什么？\n");
	if(me->is_fighting())
		return notify_fail("这只蟾蜍正在战斗。\n");
	if((string)who->query("family/family_name")!="五毒教")
		return notify_fail("什么？\n");
	
	message_vision("$N对$n一阵怪啸：大胆，还不驯服更待何时？\n\n", who,me);
	message_vision("$N勃然大怒道：咱们谁驯谁还不一定哪。\n
冲上来和$n扭打到一起。\n",me,who);
	me->kill_ob(who);
	who->kill_ob(me);
        COMBAT_D->do_attack(me, who, query_temp("weapon"));
	me->set("owner",who->query("id"));
	return 1;
}

void die()
{
	string owner,name;
	object owner_ob;            
       object ob;
	owner = query("owner");
	if(owner) owner_ob= find_player(owner);
	if(owner_ob &&  (object)query_temp("last_damage_from") == owner_ob ) {
		message_vision("$N趴在地上，一动也不敢动了。\n",this_object());	
	ob=new(__DIR__"chanchu3.c");
	ob->move(environment(owner_ob));
	ob->set_leader(owner_ob);
       ob->set("host_id",owner_ob->query("id"));
       name=this_object()->query("name");
       ob->set_name(name,({"chan chu"}));
	destruct(this_object());

		return;
	}
       else {
            message_vision("$N倒在地上，死了！\n", this_object());
            ob=new(__DIR__"obj/chanchudu.c");
	      ob->move(environment(this_object()));
	      destruct(this_object());
       }
//     return 1;
//	::die();
}

int hit_ob(object me, object ob, int damage)
{
       if ((string)ob->query("family/family_name") != "五毒教") {
	     	ob->apply_condition("chanchu_poison", 20
              +(int)ob->query_condition("chanchu_poison") );
              tell_object(ob, HIG "你觉得被咬中的地方一阵麻木！\n" NOR );
	}
}

