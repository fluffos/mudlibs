inherit NPC;
void create()  
{	set_name("蒙古妇女", ({ "fu nu","nu" }));
	set("gender", "女性");
	set("age", 35);
	set("str", 17);
	set("dex", 16);
	set("long", "她们成年辛勤地工作着，大漠的风沙使她们的脸上过早地出现了皱纹。\n");
	set("combat_exp", 1000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set_skill("unarmed", 20);
	
	set("neili", 100); 
	set("max_neili", 100);
        set("chat_chance", 10);
        set("chat_msg", ({
       "妇女打着手势对你说：你是从哪来的呀？.",
       "妇女冲着你愉快地微笑着。",
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

