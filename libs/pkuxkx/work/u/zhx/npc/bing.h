int do_copy(object me,int maxpot)
{
        int i,j;
        object ob;
        mapping skill_all;
                string *skill;
                ob = this_object();
        i=maxpot;
                if( i < 100) i = 100;
        ob->set("combat_exp", (me->query("combat_exp")+random(me->query("combat_exp")))*3/4);
        skill_all=ob->query_skills();
                skill = keys(skill_all);
                j = sizeof(skill_all);
                for(i=0; i<j; i++)
                        { ob->set_skill(skill[i],maxpot);
                        }
        ob->set("max_qi",     me->query("max_qi")*2/3);
        ob->set("eff_jing", me->query("eff_jing")*2/3);
        ob->set("max_neili",  me->query("max_neili"));
        ob->reincarnate();
        ob->set("eff_qi",ob->query("max_qi"));
                ob->set("qi",ob->query("max_qi"));
        ob->set("neili",ob->query("max_neili"));
                call_out("do_back", 350,  ob);
        //ob->set("attitude", "aggressive");
        return 1;
        //add_money("silver", random(100));
}
