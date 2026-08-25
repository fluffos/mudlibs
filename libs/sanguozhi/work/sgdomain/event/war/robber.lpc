// robber.c
// need to handle robber for auto_war
// by fire on Sep 20, 1998
string auto_start_point(string p_area,string p_side);
string robber_name(string p_inp)
{
        switch (p_inp)
        {
                case "aut bandit": return "强盗";
                case "aut brigand": return "土匪";
                case "aut yellow": return "黄巾余党";
                default: return "山贼";
        }
}
int robber_attack_prepare(int w_id)
{
        int p_sum;  // number of troops
        int i;
	mixed * att_party=({});
		string p_baseroom;
        string att_area,def_area,rob_id,rob_nam;
		int *att_army;
        att_area=TASK_D->get_task(w_id,"att_area");
        def_area=TASK_D->get_task(w_id,"def_area");
        rob_id=def_area+" "+att_area[4..<1];
        rob_nam=robber_name(att_area);
        p_sum=2+random(4);
		p_baseroom=AREA_D->get_area(def_area,"path")+"warroom/";
	att_army=({});
        for(i=0;i<p_sum;++i)
        {       string l_id;
                object o_troop;
                int troop_id;
                l_id=rob_id+i;
		att_party+=({l_id});
                CHAR_D->add_char(l_id);
                if(i==0)
                {
                        CHAR_D->set_char(l_id,"name",rob_nam+"头子");
                        TASK_D->set_task(w_id,"att_leader",l_id);
		}
                else
                        CHAR_D->set_char(l_id,"name",rob_nam);
				TASK_D->add_char(w_id,l_id,0);
		CHAR_D->set_char(l_id,"is_tmp",1);
                          CHAR_D->set_char(l_id,"is_robber",1);
				TASK_D->add_char(w_id,l_id,0);
                o_troop=TROOP_D->new_troop(rob_nam,({l_id}),0
     ,p_baseroom+auto_start_point( def_area,"a"));
                troop_id=o_troop->get_id();
   TROOP_D->set_troops(troop_id,"task_id",w_id);
		att_army+=({troop_id});
                if(i==0)
                {
                        TROOP_D->add_soldier(troop_id,"infantry",
							100,80,80,0);
                        TROOP_D->add_soldier(troop_id,"cavalry",
							100,80,80,0);
                        TROOP_D->add_soldier(troop_id,"bowman",
							100,80,80,0);
				}
				else
				{
					string soldier_type;
					switch(random(3))
					{
					case 0: soldier_type="infantry";break;
					case 1: soldier_type="cavalry";break;
					case 2: soldier_type="bowman";break;
                    }
                       TROOP_D->add_soldier(troop_id,soldier_type,
                                      100,70,70,0);
				}
		TROOP_D->set_troops(troop_id,"side","a");
        }
      TASK_D->set_task(w_id,"att_army",att_army);
      TASK_D->set_task(w_id,"att_party",att_party);
      call_out("attack_enter",1,w_id);
        TASK_D->set_task(w_id,"timaim",2); // 10 sec check
        TASK_D->set_task(w_id,"stage",1); // begin war
        return 1;
}
