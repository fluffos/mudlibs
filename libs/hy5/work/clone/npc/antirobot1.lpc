//  antirobot1.c
//  By Jpei  Aug 1997

inherit NPC;

void create()
{
	set_name("#TICK!!!", ({ "anti robot" }));
	set("shen_type", 0);

	set("gender", "机器");
	set("age", 20);
	set("long", "这是一个专门破坏机器人的机器人。\n");
	set("nickname", "反呆组密探 -- 机器人克星");

	set("max_qi", 10000);
	set("qi", 10000);
	set("max_jing", 10000);
	set("jing", 10000);
	set("attitude", "friendly");

        set("chat_chance", 40);
        set("chat_msg", ({
                (: random_move :)
        }) );
	
	setup();
}

void init()
{
	say("档案储存完毕。\n");
	say("你吐纳完毕，睁开双眼，站了起来。\n");
	say("你运功完毕，站了起来。\n");
	say("你一觉醒来，觉得精力充沛，该活动一下了。\n");
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("$N沮丧地发现机器人克星根本不理会作战请求。\n", ob);
}

void unconcious()
{
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
	say( "机器人克星狞笑着说：我是无敌不死版！\n");
	command("hehe");
}

void die()
{
	unconcious();
}

