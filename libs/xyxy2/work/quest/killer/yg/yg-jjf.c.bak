inherit __DIR__"yaoguai.c";

void set_skills(int j, int level)
{
	create_family("将军府",4,"");			
        set("title","将军府叛将");
        set_skill("unarmed", j);
        set_skill("dodge", j);
        set_skill("parry", j);
        set_skill("force", j);
        set_skill("spells", j);
        set("chat_chance_combat", 1+2*level);
 	switch(random(3))
 	{
        	case 0 :
        		set_skill("spear", j);
        		set_skill("bawang-qiang", j);
        		map_skill("spear","bawang-qiang");
        		map_skill("parry", "bawang-qiang");
        		carry_object(0,"spear",random(10))->wield();	
        		set("chat_msg_combat", ({
        			(: perform_action,"spear", "bugong" :),
        			(: perform_action,"spear", "huima" :),
        		}));	
			break;
        	case 1 :
        		set_skill("axe",j);
        		set_skill("sanban-axe",j);
        		map_skill("axe","sanban-axe");
        		map_skill("parry", "sanban-axe");
        		carry_object(0,"axe",random(10))->wield();	
        		set("chat_msg_combat", ({
        			(: perform_action,"axe", "kai" :),
        			(: perform_action,"axe", "pidi" :),
        		}));	
			break;
		default :
        		set_skill("bawang-qiang", j);
        		map_skill("parry", "bawang-qiang");
        		carry_object(0,"unarmed",random(10))->wield();	
        		set("chat_msg_combat", ({
        			(: perform_action,"unarmed", "chong" :),
        			(: perform_action,"unarmed", "zhi" :),
        		}));	
			break;
	}		        		
        set_skill("yanxing-steps", j);
        set_skill("changquan", j);
        set_skill("lengquan-force", j);
        set_skill("baguazhou", j);

        map_skill("force", "lengquan-force");
        map_skill("spells", "baguazhou");
        map_skill("dodge", "yanxing-steps");
        map_skill("unarmed", "changquan");
	setup();
	carry_object(0,"armor",random(10))->wear();
	carry_object(0,"cloth",random(10))->wear();
	carry_object(0,"pifeng",random(10))->wear();
	carry_object(0,"kui",random(10))->wear();
	carry_object(0,"shoes",random(10))->wear();
	set("env/wimpy",0);
	set("class","fighter");
}
