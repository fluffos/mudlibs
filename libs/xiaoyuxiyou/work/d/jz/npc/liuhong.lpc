//Cracked by Roath
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("刘洪", ({"liu hong","liuhong","liu"}));
        set_level(25);
        set("gender", "男性");
        set("age", 38);
        set("title","江州知府");
        set("long","一个看起来让人很不舒服的知府。");
        set("per", 20);
        set_skill("unarmed",250);
        set_skill("parry",250);
        set_skill("sword",250);
        set_skill("pomopima-jian",250);
        set_skill("dodge",250);
	set_skill("changquan",250);
        map_skill("unarmed","changquan");
        map_skill("parry","pomopima-jian");
        map_skill("sword","pomopima-jian");
        set("inquiry", ([
                "陈光蕊": (: kill_ob(this_player()) :),
                "殷温娇": "她是我的结发妻子",
	]));
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
		message("vision","\n"+name()+"恶狠狠的说道：哼，本官乃朝廷钦派。\n"+name()+"见势不妙，丢盔卸甲，抱头鼠窜。\n",environment());
		lose_inventory();
	}	
	destruct(this_object());
}

void unconcious ()
{
	die ();
}