//Cracked by Roath

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("李彪", ({"li biao","libiao","li"}));
        set("gender", "男性");
        set_level(20);
        set("age", 38);
        set("title","江州知爷");
        set("long","一个身强力壮的男人，怎么看也不象知爷。");
        set("attitude", "friendly");
        set("per", 10);
        set_skill("unarmed",200);
        set_skill("parry",200);
        set_skill("sword",200);
        set_skill("pomopima-jian",200);
        set_skill("dodge",200);
	set_skill("changquan",200);
        map_skill("unarmed","changquan");
        map_skill("parry","pomopima-jian");
        map_skill("sword","pomopima-jian");
        setup();
        carry_object(0,"sword",random(2))->wield();
        carry_object(0,"cloth",random(2))->wear();
        carry_object(0,"kui",random(2))->wear();
        carry_object(0,"shoes",random(2))->wear();
        
}
void die ()
{
	if( environment() )
	{
		EMOTE_D->do_emote(this_object(), "pei",0,CYN,0,0,0);
		message("vision","\n"+name()+"见势不妙，丢盔卸甲，抱头鼠窜。\n",environment());
		lose_inventory();
	}	
	destruct(this_object());
}

void unconcious ()
{
	die ();
}