// by victori
inherit NPC;
#include <ansi.h>

string *first_name = ({ "花皮", "青竹", "四脚", "眼镜王"});
string *name_words = ({ "蛇"});
void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];
        set_name(name,({"du she"}));
	set("race", "野兽");
        set("long", "一条一尺多长，鬼头鬼脑的小蛇。\n");
	set("age", 100);
	set("attitude", "peaceful");

	set("max_jing", 3200);
	set("max_qi", 3200);
	set("jing", 3200);
	set("qi", 3200);
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

	set("combat_exp", 10000);
 
        set_weight(500000);
	setup();
}
void init()
{
        object me,ob;
//       ::init();
        add_action("do_xun", "xun");
//       object me,ob;
//        ::init();
        if (interactive(me = this_player()))
        {
	if (!(ob = present("xionghuang", this_player())))          
               {
      	       remove_call_out("kill_ob");
              call_out("kill_ob", 1, me);
		}
        }
        ::init();
}
int do_xun(string arg)
{
	object me,who;
	me =this_object();
	who=this_player();
	if (!arg || (arg != "du she"))
		return notify_fail("你要驯服什么？\n");
	if(me->is_fighting())
		return notify_fail("这只蛇正在战斗。\n");
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
	ob=new(__DIR__"she1.c");
	ob->move(environment(owner_ob));
	ob->set_leader(owner_ob);
       ob->set("host_id",owner_ob->query("id"));
       name=this_object()->query("name");
       ob->set_name(name,({"du she"}));

	destruct(this_object());
       
	return;
	}
       else {
            message_vision("$N倒在地上，死了！\n", this_object());
            ob=new(__DIR__"obj/shedu.c");
	      ob->move(environment(this_object()));
	      destruct(this_object());
       }
//     return 1;
//	::die();
}

int hit_ob(object me, object ob, int damage)
{
       if ((string)ob->query("family/family_name") != "五毒教") {
	     	ob->apply_condition("snake_poison", 20
              +(int)ob->query_condition("snake_poison") );
              tell_object(ob, HIG "你觉得被咬中的地方一阵麻木！\n" NOR );
	}
}

