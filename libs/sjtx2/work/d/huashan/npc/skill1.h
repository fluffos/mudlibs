int do_clone(object me, object ob)
{
        object weapon;
        int number,number_t,k_qi,k_neili,k_jing, j, k;

        number = (int)ob->query("max_pot");
        number = number - 100;
        k_qi = (int)ob->query("max_qi") + random((int)ob->query("max_qi") / 10 + 1000);
        k_jing = (int)ob->query("max_jing");
        k_neili = (int)ob->query("max_neili") + random((int)ob->query("max_qi") / 10 + 1000);
        j = (int)ob->query("dex");
        k = (int)ob->query("str");


// skills LVL
        number = number - random(10);
        number_t = number + random(15);
        if (number > 300) number_t = 300;

//add by river
        if( ob->query("hmy_job") > 200 || number > 300) {
        	me->set_temp("apply/parry",  number / 5 + random(number / 4));
        	me->set_temp("apply/attack",  number / 5 + random(number / 4));
        }
//set killer's skill
        me->set_skill("force",number_t);
        me->set_skill("dodge",number_t);
        me->set_skill("zixia-gong",number_t);
        me->set_skill("huashan-shenfa",number_t);
        me->set_skill("hunyuan-zhang",number_t);
        me->set_skill("poyu-quan",number_t);
        me->set_skill("cuff",number_t);
        me->set_skill("strike",number_t);
	switch(random(2)) {
		case 0 :
			me->set_skill("huashan-jianfa",number_t);
			me->set_skill("sword",number_t);
			me->map_skill("parry","huashan-jianfa");
			me->map_skill("sword","huashan-jianfa");
			me->set("chat_chance_combat", 60);
			me->set("chat_msg_combat", ({
               			(: perform_action, "sword.lianhuan" :),
               			(: perform_action, "sword.feijian" :),
               			(: perform_action, "sword.jianzhang" :),
              		}) );
                    	if (!(weapon = present("chang jian",me)))
			        carry_object(BINGQI_D("changjian"))->wield();
                    	weapon->wield();
                    	break;
              	case 1 :
			me->set_skill("fanliangyi-dao",number_t);
			me->set_skill("blade",number_t);
			me->map_skill("parry","fanliangyi-dao");
			me->map_skill("blade","fanliangyi-dao");
			me->set("chat_chance_combat", 60);
			me->set("chat_msg_combat", ({
               			(: perform_action, "blade.sanshenfeng" :),
              		}) );
            		if ((weapon = me->query_temp("weapon"))
			 && weapon->query("skill_type") == "sword")
				weapon->unequip();
            		if (weapon = present("blade",me))
                		weapon->wield();
            		else
            			carry_object(BINGQI_D("blade"))->wield();
            		break;
	}
// set killer's  skill maps
        me->map_skill("force","zixia-gong");
        me->map_skill("dodge","huashan-shenfa");
        me->map_skill("strike","hunyuan-zhang");
//        me->map_skill("cuff","poyu-quan");
// set killer's skill prepares
//        me->prepare_skill("cuff","poyu-quan");
        me->prepare_skill("strike","hunyuan-zhang");
// copy entire dbase values
        me->set("max_qi",k_qi);
        me->set("eff_qi",k_qi);
        me->set("qi",k_qi);
        me->set("max_jing",k_jing);
        me->set("eff_jing",k_jing);
        me->set("jing",k_jing);
        me->set("max_neili",k_neili);
        me->set("neili",k_neili);
        me->set("jiali", k_neili / 40);
        me->set("combat_exp",ob->query("combat_exp")* 12/10);


//add log here
        log_file("job/heimuya",sprintf("%8s%-10s FIGHT LING，LING等级是%3d，本人等级是%3d。\n",
		ob->name(1),"("+ob->query("id")+")",number_t,(int)ob->query("max_pot")-100),ob);

        me->set_temp("skillset",1);
        command("say 来吧，我们来切磋切磋！");
	return 1;
}
