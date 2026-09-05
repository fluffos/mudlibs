inherit NPC;


void create()
{
	set_name("贴身丫鬟", ({ "ya huan", "ya","huan" }));
	set("gender", "女性");
	set("age", random(15) + 10);
	set("str", 10);
	set("dex", 10);
	set("long", "她是一名都府里的丫鬟，内府的打扫由她负责。\n");
	set("combat_exp", 6000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("is_yahuan",1);
	set_skill("unarmed", 10);
	set_skill("force", 10);
	set_skill("dodge", 10);
	set_skill("parry", 10);
	set("chat_chance", 2);
	set("chat_msg", ({
				(: random_move :),
                this_object()->name()+"害羞地想着心事。\n",
				this_object()->name()+"轻轻拂去灰尘。\n",
				this_object()->name()+"开心地笑了笑。\n",
                //(:askforhelp:),
        }) );
	setup();
	carry_object(__DIR__"obj/cloth_yahuan")->wear();
}
