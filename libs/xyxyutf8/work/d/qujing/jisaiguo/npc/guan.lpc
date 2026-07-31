inherit NPC;

void create()
{
       set_name("黄门官", ({"huangmen guan", "guan"}));
       set("gender", "男性");
       set_level(39);
       set("age", 30);
        set("long", "一个身高胸阔的殿前武士，正走来走去巡视着。\n");
       set("attitude", "heroism");
       set("shen_type", 1);
        set_skill("unarmed",390);
        set_skill("dodge",390);
        set_skill("blade",390);
        set_skill("parry",390);
	set_skill("force",390);
        set("force_factor", 10);
	set_weight(300000);
	setup();
	carry_object("/d/obj/armor/tongjia")->wear();
        carry_object("/d/qujing/baoxiang/obj/wandao")->wield();
}

void die()
{
	object ob;
        if( environment() && base_name(environment())=="/d/qujing/jisaiguo/yunqi" )
        {
        	message("sound", "\n黄门官大叫：有刺客，快来保护皇上！\n", environment());
        	if( !objectp(ob=present("guan 2", environment()))
        	  || userp(ob) )
		{
			if( ob=new("/d/qujing/jisaiguo/npc/guan"))
				message("sound", "\n几个黄门官从台下跑了上来。\n", environment());
			ob->move(environment());	
        	}
	}
	::die();
}

