// yangzhou 's 老鼠

inherit NPC;

void create()
{
	set_name("老鼠", ({ "laoshu","hao zi","mouse" }) );
	set("race", "野兽");
	set("age", 3);
	set("long", "一只灰老鼠。\n");
	
	set("str", 20);
	set("con", 10);

	set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("chat_chance", 30);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"老鼠“支”“支”叫了几声。\n",
		"老鼠警惕的望着你。\n",
                         }));		
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 100);
        set("env/wimpy",80);
       set("no_clean",1);
	setup();
        add_money("coin", 10);
}




int accept_object(object who, object ob)
{
	if( ob->id("huashenmi") ) {
		set_leader(who);
                this_object()->set("title",who->query("name")+"养的");
		message("vision", name() + "在你脚下转了一圈。\n", environment());
		return 1;
	}

return 0;

}
