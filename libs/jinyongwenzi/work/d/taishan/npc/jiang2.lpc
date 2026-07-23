// jiang 江百胜
// by pishou 97/6

#include <ansi.h>

inherit NPC;

void create()
{
	seteuid(getuid());

	set_name("江百胜", ({ "jiang baisheng", "jiang", "baisheng" }) );
	set("gender", "男性" );
	set("age", 30);
        set("long", "当今武林盟主江百胜, 号称百战百胜, 攻无不克。\n");
	set("attitude", "heroism");
	set("generation",0);
	set("winner","none");

	set("str", 25);
	set("con", 25);
	set("int", 25);
	set("dex", 25);

	set("max_qi", 1000);
	set("eff_qi", 1000);
	set("qi", 1000);
	set("max_jing", 500);
	set("jing", 500);
        set("jingli", 500);
        set("max_jingli", 500);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 60);
	set("shen_type", 0);

	set("no_clean_up",1);
	set("combat_exp", 150000);

	set_skill("force", 120); 
	set_skill("unarmed", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);

	set("fight_times", 0);	

	setup();
        
}

int checking(object me, object ob)
{
	object obj;
	int my_max_qi, his_max_qi;

	if ( !present(ob, environment()) ) return 1; 

	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if( me->is_fighting() ) 
	{
		if (( (int)me->query("qi")*100 / my_max_qi) <= 80 ) 
		{
            say(GRN "\n江百胜说道： 老子闯荡江湖几十载, 可算是攻无不克，克无不胜！ 怎么能今天败在你手里?！\n" NOR);
            message_vision(HIY "\n江百胜说完，全身不知打哪里冒出来的一股力气，不但功力尽复，拳力也威猛好多倍！\n" NOR, ob);

			me->set("eff_qi", me->query("max_qi"));
			me->set("qi",     me->query("max_qi"));
			me->set("jing",   me->query("max_jing"));
                        me->set("jingli",   me->query("max_jingli"));
			me->set("neili",  me->query("max_neili"));
		}
		else if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
		{
            say(GRN "\n江百胜说道： 看来你小子跟我还差着一大截呢，来争什么盟主, 回去练上十年再来吧！\n");
			return 1;
		}

		if ( present(ob, environment()) ) call_out("checking", 1, me, ob);
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

	if ( !present(ob, environment()) ) return 0;

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
                me->set("eff_qi",    hp_status["eff_qi"]);
                me->set("qi",        hp_status["qi"]);
                me->set("max_jing",  hp_status["max_jing"]);
                me->set("eff_jing",  hp_status["eff_jing"]);
                me->set("jing",      hp_status["jing"]);
                me->set("max_neili", hp_status["max_neili"]);
                me->set("neili",     hp_status["neili"]);
                me->set("jiali",     hp_status["jiali"]);
                me->set("combat_exp",hp_status["combat_exp"]);

	if ( me->query("fight_times") >= 10 )
		return notify_fail("江百胜已经全身脱力，趴在地上大口地喘着粗气！\n");	

	me->add("fight_times", 1);

	remove_call_out("checking");
	call_out("checking", 1, me, ob);
	
	return 1;
}



