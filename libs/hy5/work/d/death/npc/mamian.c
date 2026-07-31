#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW "马面" NOR, ({ "mamian" }) );
        set("gender", "男性" );
        set("age", 25);
	set("title", HIW "枷铐" NOR);
        set("str", 36);
        set("cor", 24);
        set("cps", 11);
        set("per", 27);
        set("int", 27);
	set("agi", 30);
        set_temp("apply/astral_vision",1);
        set("intellgent",1);
        set("attitude", "peaceful");
        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
        }) );

        set("max_force", 3000);
        set("force", 3000);

        set("long",     "马面人身，全身青紫的鬼怪\n");

        set("combat_exp", 9999);

        set_skill("hammer", 120);
	set_skill("dodge", 100);
        setup();
        carry_object(__DIR__"obj/hammer")->wield();
}
int accept_object(object who, object ob)
{
		message_vision("$N对$n怪叫一声：在阳间做亏心事了吧！\n",this_object(),who);
		return 1;
}
