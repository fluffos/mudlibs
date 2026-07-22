void init()
{
        object ob;
                
        ::init();
        if (    interactive(ob = this_player() ) 
        &&      !is_fighting() 
        &&      (ob->query("family/family_name") == "丐帮") ) {
                call_out("change_skills",1,ob);
        }
}

void change_skills(object ob)
{
        int a,b,c,d;
        mapping skills_learned;

        a = ob->query_skill("gaibang-steps",1);
	b = ob->query_skill("chansi-shou",1);
	c = ob->query_skill("taizu-gun",1);
	d = ob->query_skill("taizu-changquan",1);
        skills_learned = ob->query_learned();

        if ( !undefinedp(skills_learned["gaibang-steps"]) ) {
                ob->set("combat_exp", ob->query("combat_exp")*3/4);
        }

        if ( a != 0 ) {
                ob->set_skill("wanli-steps",a);
                ob->force_me("enable dodge wanli-steps");
                tell_object(ob,"你的轻功已改为万里独行!\n");
        }

        if ( b != 0 ) {
                ob->set_skill("lianhua-zhang",b);
                ob->force_me("enable unarmed lianhua-zhang");
                tell_object(ob,"你的空手功夫已改为莲花掌!\n");
        }

        if ( c != 0 ) {
                ob->set_skill("feitian-zhang",c);
                tell_object(ob,"你的兵器功夫已改为飞天杖法!\n");
        }

        if ( d != 0 ) {
                ob->set_skill("qimen-blade",d);
                tell_object(ob,"你的兵器功夫已改为奇门刀法!\n");
        }
        
        ob->delete_skill("gaibang-steps");
        ob->delete_skill("chansi-shou");
        ob->delete_skill("taizu-gun");
        ob->delete_skill("taizu-changquan");
        ob->delete_skill("taizu-force");

        return;
}