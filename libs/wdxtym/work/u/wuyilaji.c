//抗日任务 (改编自12gong job)
//@txwx by hhm 06/07/01
inherit NPC;
#include <star.h>
void create()
{
        set_name(HIW"五一垃圾"NOR, ({"wuyi laji", "wylj"}));
        set("long", "五一垃圾，清理垃圾人人有责，\n");
        set("gender","男性");
        set("title", HIR"【boss】"NOR);
      set("no_get",1);
        set("age",37);
        set("attitude", "peaceful");
        set("con",1300);
        set("per",312);
        set("str",3250);
        set("int",3305);
        set("combat_exp",23000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "五一垃圾：制造垃圾！\n" 
				"五一垃圾：我在行！\n"
        }));
       set("max_neili", 6000000);
         set("neili", 6000000);
         set("max_jingli",6000000);
         set("jingli",6000000);
         set("jiali",6000000);
         set("max_qi", 6000000);
         set("max_jing", 6000000);
          set_skill("dodge", 550);
          set_skill("force", 550);
          set_skill("parry", 550);
          set_skill("unarmed", 600);
		  set_skill("wuxing-dun", 550+random(300));
		  set_skill("shaolin-shenfa", 600);
		  set_skill("qishang-quan", 600);
        create_family("boss类",1,"五一垃圾");
        set("chat_chance_combat", 1300);
        set("chat_msg_combat", ({
        (: perform_action, "sword.daya" :),
    }) );
        setup();
	carry_object("/d/city/obj/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/misc/mask1");
	add_money("silver", 100);
}
 void init()
{	
	object ob, me;
	mapping skill_status, map_status;
	string *sname, *mname;
	int i;

	me = this_object();
	ob = this_player();

	::init();

	if (me->is_fighting() || wizardp(ob)) return;

	remove_call_out("pretending");
	call_out("pretending", 1, ob);
	
	me->map_skill("unarmed");
	me->map_skill("dodge");
	me->map_skill("parry");

	if ( !(skill_status = ob->query_skills()) ) return;
	sname  = keys(skill_status);

	for(i=0; i<sizeof(skill_status); i++) {
		me->set_skill(sname[i], skill_status[sname[i]]);
	}

	if ( !(map_status = ob->query_skill_map()) ) return;
	mname  = keys(map_status);

	for(i=0; i<sizeof(map_status); i++) {
		me->map_skill(mname[i], map_status[mname[i]]);
	}

	set("neili", 600);
	set("jiali", 30);
	
}

void pretending(object ob)
{

	object me = this_object();
 
	if(!ob || !userp(ob) || environment(ob) != environment()) return;

	switch( random(3) ) {
		case 0:
		       command("grin " + ob->query("id"));
		       command("pretend " + ob->query("id"));
		       command("exert recover");
		       break;
		case 1:
		       command("hi " + ob->query("id"));
		       command("exert heal");
		       command("exert recover");
		       break; 
		case 2:
		       command("stare " + ob->query("id"));
		       me->fight_ob(ob);
		       ob->fight_ob(me);
		       break;
	}
}

 void die()
{
        object nvh,obj1,env;
         object ob =  this_object()->query_last_damage_from();
            object *players;
         int w,x,i;
        ob->start_busy(1); 
		env = environment(this_object());
        if (sizeof(ob->query_team()) > 1)
        {
        players = ob->query_team();
        x = 5000;   
        }
        else
        {
        obj1 = new("/clone/boss/wuyicaifu");
		obj1->set_amount(1);
		obj1->move(env);
		ob->add("potential",12000);
        ob->add("combat_exp", 10000);
        ob->add("jifeng", 100);
        ob->add("experience", 100);
         tell_object(ob,HIR"你赢得了修为10000,潜能12000，100点券，实战体会不告诉你."+w+"\n\n"NOR);   
         players = users();
         x = 1000;
         }
         w = sizeof(players);         
       for(i = 0; i<sizeof(players); i++)
         {
         players[i]->add("potential",x);
        players[i]->add("combat_exp", x/2);
        players[i]->add("experience", x/10);
       tell_object(players[i],HIR"由于"+ob->query("name")+"击败了五一垃圾，你赢得了"+x+"修为,"+x/2+"潜能，"+x/10+"实战体会.\n"NOR); 
       }
            message("channel:chat",HBRED"五一活动挑战"HIR"："+ob->query("name")+"任劳任怨，清理了五一垃圾，当是劳动楷模！\n"NOR,users());
       ::die();
}
