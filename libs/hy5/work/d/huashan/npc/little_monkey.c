// little_monkey.c
#include <ansi.h>

inherit NPC;
#include "/quest/givegift.c"
int do_work(string arg);
void create()
{
	set_name("小猴",({ "little monkey", "monkey"}) );
	set("gender", "雄性");
	set("race", "野兽");
	set("age", 2);
	set("long", "这是一只调皮的小猴子，虽是畜牲，却喜欢模仿人样。\n"
	    "陆大有整天调教得它无比伶俐，你似乎可以抓它(zhua 他)\n");
	set("limbs", ({ "头部", "身体", "腿部", "尾巴",}) );
	set("verbs", ({ "bite" }) );
	set("shen", 0);
	set("str", 20);
	set("dex", 20);
	set("con", 20);
	set("int", 20);
        set("attitude", "peaceful");

	set("no_get", "1");
	set("max_qi", 1600);
	set("qi", 1600);
	set("max_jing", 1600);
	set("jing", 1600);
	set("neili", 1600);
	set("max_neili", 1600);
	set("jiali", 10);
	set("combat_exp", 150000);

	set_skill("force", 30); 
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 130);
	set("fight_times", 0);	
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	set("chat_chance", 15);
	set("chat_msg", ({
		"小猴伸出小抓挠挠头，冲你扮个鬼脸。\n",
		"小猴伸抓捉住了身上的虱子，看了两眼，使劲就是一捏! \n",
        "小猴冲着你大扮鬼脸，叽叽歪歪一阵乱叫......!\n",
        "小猴忽然跳了过来，一个倒勾，前爪一伸摘了你的草帽!\n",
        "小猴轰的一声一起从这株树跳到那株树，把你吓了一大跳!\n",
                (: random_move :),
	}));
	setup();
        
}
void init()
{
        add_action("do_work", "zhua");
}


int do_work(string arg)
{
        object me, ob, weapon;
int exp,pot;
        me=this_player();
 	ob=this_object();
 	if (!arg)
	return notify_fail("你要抓什么啊？\n");

 	if (!id(arg))
	return notify_fail("你要抓什么啊？\n");

        if( strsrch(file_name(environment(me)), "/d/huashan") == -1 )
                return notify_fail("这里不是华山了，抓什么抓啊。\n");
        if (me->query("family/family_name")!="华山派")
                return notify_fail("小猴一看你，似乎认生，逃开了！\n");
	if( !living(ob) )
		return notify_fail(ob->name() + "已经昏过去了。\n"); 
        if (!environment(me)->query("outdoors"))
                return notify_fail("不在户外，抓什么抓！\n");
       if (!environment(me)->query("exits"))
                return notify_fail("这里没有出口,抓什么抓！\n");
        if (me->query("jing")< 30)
                return notify_fail("你的精不够。\n");

        if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

         tell_object(me, HIY"你偷偷的跑到小猴的身边，一把向小猴抓去！\n"NOR);
	ob->set("max_qi", 1600);
	ob->set("qi", 1600);
	ob->set("max_jing", 1600);
	ob->set("jing", 1600);
	ob->set("neili", 1600);
	ob->set("max_neili", 1600);

                        message_vision(HIM"一看到$N, 忽然跳了起来，一个倒勾跑开了......。\n"NOR, me);
                        message_vision(HIM"$N累的满头是汗......。\n"NOR, me);
                        me->add("jing",-10);
                        me->add_temp("hs_times",1);
                        me->start_busy(1);

                if (me->query_temp("hs_times")>(random(10)+8))
                {
                        message_vision(HIC"$N一把抓住了小猴。小猴叽叽歪歪一阵乱叫,$N一松手把小猴放了.\n"NOR, me);
                        message_vision(HIC"$N的经验和潜能增加了!\n"NOR, me);
                        me->delete_temp("hs_times");
exp=random(20)+40;
pot=random(30)+18;
exp=exp/2+6;
addnl(me,"exp",exp);

                        me->add("combat_exp", exp);
                        me->add("potential", pot);

                }
                else
if (ob) ob->random_move();
if (random(10)==0)
{
command("go north");
command("go east");
command("go west");
command("go south");
command("go northeast");
command("go northwest");
command("go southeast");
command("go southwest");
}
                return 1;
}

int accept_fight(object ob)
{
	object me;
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp;

	me = this_object();

	if (is_fighting()) return 0;

	if (me->query("damaged"))
		return notify_fail("这个小猴已经被打伤了！\n");	

	if (random(me->query("fight_times")) >= 5) {
		me->set("damaged", 1);
		return notify_fail("这个小猴已经被打怕了！\n");	
	}

	if (me->query("last_fighter") == ob->query("id"))
		return notify_fail("这个小猴已经不想和你玩了！\n");	

	me->set("last_fighter", ob->query("id"));
	me->add("fight_times", 1);

	remove_call_out("renewing");	
	call_out("renewing", 1000 + random(300), me);	


	if ( mapp(skill_status = me->query_skills()) ) {
		skill_status = me->query_skills();
		sname  = keys(skill_status);

		temp = sizeof(skill_status);
		for(i=0; i<temp; i++) {
			me->delete_skill(sname[i]);
		}
	}

	if ( mapp(skill_status = ob->query_skills()) ) {
		skill_status = ob->query_skills();
		sname  = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			me->set_skill(sname[i], skill_status[sname[i]]);
		}
	}
	

	if ( mapp(map_status = me->query_skill_map()) ) {
		mname  = keys(map_status);

		temp = sizeof(map_status);
		for(i=0; i<temp; i++) {
			me->map_skill(mname[i]);
		}
	}

	if ( mapp(map_status = ob->query_skill_map()) ) {
		mname  = keys(map_status);

		for(i=0; i<sizeof(map_status); i++) {
			me->map_skill(mname[i], map_status[mname[i]]);
		}
	}
	

	if ( mapp(prepare_status = me->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		temp = sizeof(prepare_status);
		for(i=0; i<temp; i++) {
			me->prepare_skill(pname[i]);
		}
	}

	if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
		pname  = keys(prepare_status);

		for(i=0; i<sizeof(prepare_status); i++) {
			me->prepare_skill(pname[i], prepare_status[pname[i]]);
		}
	}
	
	hp_status = ob->query_entire_dbase();

		me->set("str", hp_status["str"]);
		me->set("int", hp_status["int"]);
		me->set("con", hp_status["con"]);
		me->set("dex", hp_status["dex"]);

		me->set("max_qi",    hp_status["max_qi"]);
		me->set("eff_qi",    hp_status["eff_qi"]);
		me->set("qi",        hp_status["qi"]);
		me->set("max_jing",  hp_status["max_jing"]);
		me->set("eff_jing",  hp_status["eff_jing"]);
		me->set("jing",      hp_status["jing"]);
		me->set("max_neili", hp_status["max_neili"]);
		me->set("neili",     hp_status["neili"]);
		me->set("jiali",     hp_status["jiali"]);
		me->set("combat_exp",hp_status["combat_exp"]);

	return 1;
}

void renewing(object me)
{
	me->delete("last_fighter");
}
