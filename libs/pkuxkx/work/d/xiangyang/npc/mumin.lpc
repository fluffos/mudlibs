inherit NPC;
void create()  
{	set_name("蒙古牧民", ({ "mu min","min" }));
	set("gender", "男性");
	set("age", 35);
	set("str", 17);
	set("dex", 16);
	set("long", "他们世世代代在这片土地上放牧为生，脸上带着憨厚朴实的笑容。\n");
	set("combat_exp", 10000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 50);
	
	set("neili", 200); 
	set("max_neili", 200);
        set("chat_chance", 10);
        set("chat_msg", ({
       "牧民打着手势对你说：请到我家里坐一坐吧？.",
       "牧民憨厚地对你笑者。"
                }) );

        setup();
//	carry_object(ne/weapon/fangtianji")->wield();
//	carry_object(__DIR__"obj/yangbian")->wear();

}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

