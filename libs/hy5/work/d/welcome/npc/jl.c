
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("武师", ({ "jiao tou" }) );
 set("title", HIR "武馆教练" NOR);
	set("gender", "男性" );
	//set_temp("no_kill", 1);
	set("age", 76);
	set("per", 100);
        set("long", "
这是古村的武馆教练，你可以拜他为师（duilian jiao tou）练习武功。
\n");
	set("shen_type",1);
	set("combat_exp", 2000000);
	set("attitude", "peaceful");
        set("apply/attack", 350);
	set("apply/defense", 350);
        set_skill("literate", 150);
        set_skill("dodge", 150);
        set_skill("force", 150);
        set_skill("parry", 150);
        set_skill("claw", 150);
        set_skill("hand", 150);
        set_skill("strike", 150);
        set_skill("finger", 150);
        set_skill("feixian-sword", 250);
        set_skill("softsword", 250);
        set_skill("cuff", 150);
        set_skill("blade", 150);
        set_skill("stick", 150);
        set_skill("club", 150);
        set_skill("staff", 150);
        set_skill("sword", 150);
        set_skill("throwing", 150);
        set_skill("bat-blade",250);
        set_skill("changquan",250);
        set_skill("jingyiforce",250);
set("skill_public", 1);
set("pubmaster", 1);
set("pubduilian", 1);
	//create_family("古村", 1, "教练");
        set_temp("apply/attack", 250);
        set_temp("apply/defense", 250);
        set_temp("apply/damage", 250);



	setup();
	carry_object("clone/cloth/cloth")->wear();
}
