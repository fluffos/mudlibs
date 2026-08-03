inherit __DIR__"yaoguai.c";

void set_skills(int j, int level)
{
	create_family("将军府",4,"");			
        set_skill("unarmed", j);
        set_skill("dodge", j);
        set_skill("parry", j);
        set_skill("force", j);
        set_skill("spells", j);

	set_skill("spear", j);
        set_skill("bawang-qiang", j);
        map_skill("spear","bawang-qiang");
        map_skill("parry", "bawang-qiang");
        set_skill("yanxing-steps", j);
        set_skill("changquan", j);
        set_skill("lengquan-force", j);
        set_skill("baguazhou", j);

        map_skill("force", "lengquan-force");
        map_skill("spells", "baguazhou");
        map_skill("dodge", "yanxing-steps");
        map_skill("unarmed", "changquan");
        set("env/test","HIB");
	setup();
	carry_object(0,"armor",1)->wear();
	carry_object(0,"cloth",1)->wear();
	carry_object(0,"pifeng",1)->wear();
	carry_object(0,"kui",1)->wear();
	carry_object(0,"shoes",1)->wear();
        carry_object(0,"spear",1)->wield();		
	set("env/wimpy",0);
	set("class","fighter");
	powerup(1,1);
}
