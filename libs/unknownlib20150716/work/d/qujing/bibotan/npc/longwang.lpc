inherit NPC;

void create()
{
        set_name("万圣龙王", ({"wansheng longwang", "longwang", "long"}));
        set("long", "他是乱石山碧波潭的老龙王。\n");
        set_level(85);
        set("age", 68);
        set("attitude", "peaceful");
        set("gender", "男性");
	set("class", "dragon");
        set("force_factor", 40);
        set("mana_factor", 40);
        set_skill("unarmed",850);
        set_skill("parry",850);
	set_skill("force",850);
	set_skill("spells",850);
        set_skill("dodge",850);
        set_skill("dragonfight",850);
        set_skill("dragonstep",850);
        map_skill("unarmed", "dragonfight");
        map_skill("dodge", "dragonstep");
        setup();
        carry_object("/d/sea/obj/longpao")->wear();

}

void die()
{
 	object me,obj;
	if(environment() ) 
	{
        	message("sound", "\n\n万圣龙王怒道：你竟敢欺人太甚！\n\n", environment());
        	message("sound", "\n万圣龙王半空中一转，现了真身！竟是一条五爪金龙！\n\n", environment());
        	
		if( objectp(me= query_temp("last_damage_from")) 
		 && present(me,environment()) )
		{
			obj=new("/d/qujing/bibotan/npc/dragon");
			if(this_object()->query_temp("longjin_kill"))
				obj->set_temp("longjin_kill",this_object()->query_temp("longjin_kill"));
			obj->move(environment(me));
			obj->kill_ob(me);
			me->fight_ob(obj);
        	}
        }	
	destruct(this_object());
}


void unconcious()
{
        die();
}
