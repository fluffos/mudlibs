// /clone/npc/robber.c
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("劫镖强盗", ({ "biao robber", "robber" }) );
        set("long","这些强盗啸聚山林，专以打劫镖银为生。\n");

        set("attitude", "heroism");

        set("str", 20+random(11) );
        set("con", 20+random(11) );
        set("dex", 20+random(11) );
        set("int", 20+random(11) );
        set("ker", -1 );
        set("per", -1 );
        set("spi", 20+random(11) );
        set("cps", 20+random(11) );

        set("combat_exp", 500);
        set("shen",-10);

         set_skill("force", 280);
         set_skill("hunyuan-yiqi", 280);
         set_skill("dodge", 380);
         set_skill("shaolin-shenfa", 280);
         set_skill("cuff", 280);
         set_skill("jingang-quan", 210);
         set_skill("parry", 270);
         set_skill("literate", 250);
        set_skill("xue-dao", 250);



        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "jingang-quan");
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set_temp("apply/armor", 20);
        set_temp("apply/damage", 50);
	set("chat_chance_combat", 50);  
	set("chat_msg_combat", ({
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "cuff.jingang" :),
	}) );
 	prepare_skill("cuff", "jingang-quan");
 
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "劫镖强盗喝道：快快放下镖银，留你一条生路！\n",
                "劫镖强盗喝道：呔！此路是我开，此树是我栽，要想从此过，留下镖银来！\n",
                  "劫镖强盗喝道：老子看你是要钱还是要命！\n"
        }) );

        setup(); 
        carry_object("/clone/weapon/gangdao")->wield(); 
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold", 1);
}
void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("checking");
                call_out("checking", 0, ob);
        }
}

void checking(object ob)
{
        object me = this_object();
	mapping hp_status, skill_status, map_status, prepare_status;
	string *sname, *mname, *pname;
	int i, temp;

        if( !ob || !present(ob, environment(this_object())) || !present("biao yin", ob) ) {
                if(ob == query_leader() )       set_leader(0);
                return;
        }

        command("say "+ob->name()+"，把镖银留下，放你走路！！\n");
        set_leader(ob);

        kill_ob(ob);
        ob->fight_ob(me);
//        command("kill "+ob->query("id") );


/* delete and copy skills */

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
	
/* delete and copy skill maps */

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
	
/* delete and copy skill prepares */

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
		me->set("eff_qi",    hp_status["max_qi"]);
		me->set("qi",        hp_status["max_qi"]);
		me->set("max_jing",  hp_status["max_jing"]);
		me->set("eff_jing",  hp_status["max_jing"]);
		me->set("jing",      hp_status["max_jing"]);
		me->set("max_neili", hp_status["max_neili"]);
		me->set("neili",     hp_status["max_neili"]);
		me->set("jiali",     hp_status["jiali"]);
		me->set("combat_exp",hp_status["combat_exp"]);

        kill_ob(ob);
        ob->fight_ob(me);

}

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        message("vision",HIB+name()+"急急忙忙地走开了。\n" NOR, 
                environment(), this_object() );
        destruct(this_object());
}
