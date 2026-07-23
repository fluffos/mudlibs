// Modified by snowman@SJ 12/06/2000

#define DROP_CMD		"/cmds/std/drop"

object ob;
int timer = 0;

// add by snowman@SJ 12/06/2000, 防止player flood hitting this npc.
int is_corpse(){ return 1; }
void move_to_court(object ob);
void test_robot(object obj);
void question();

void create()
{
	set_name("银翼杀手", ({ "blade runner", "runner" }));

	set("gender", "机器");
	set("age", 20);
	set("no_quest", 1);
	set("no_drop", 1);
	set("no_get", 1);
	set_temp("apply/long",
		({ "这是一个专门追缉机器人的机器探员。\n"
		"如果利用机器自动回答问题，档案将被无条件删除。\n"})
	);
	set_skill("dodge", 1000);
	set("max_qi", 10000);
	set("qi", 10000);
	set("max_jing", 10000);
	set("jing", 10000);

	set("combat_exp", 5000000);

	set("inquiry", ([
		"name": "你还有这闲功夫啊？专心回答问题吧！",
		"rumors": "听说有机器人混入本MUD，嘿嘿，我可是火眼金睛呀。",
	]) );
	set("attitude", "friendly");
	set("env/invisibility", 1);

	setup();
	set_weight(0);
}

void init()
{
	if (environment() == ob) {
		question();
		add_action("do_answer", ({ "answer" }));
		add_action("wait", ({
			"quit", "learn", "chat", "rumor", "tell", "reply", "whisper", "post", "ask",
			"say", "party", "study", "sleep", "practice", "exercise", "respirate", "to",
			"mm", "party*", "chat*", "rumor*", "emote", "lingwu", "teach", "beep", "team" })
		);
	}
}

int wait()
{
	write("对不起，请先回答问题。\n");
	return 1;
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("$N沮丧地发现银翼杀手根本不理会作战请求。\n", ob);
}

void unconcious()
{
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
	say("银翼杀手狞笑着说：我是无敌不死版！\n");
	command("hehe");
}

void die()
{
	unconcious();
}

// 防止player利用bug带出带入物品。 by snowman@SJ 12/06/2000
//改成在法庭发呆一段时间,才drop all,免得答错丢失东西  by tiantian@sj 7/8/2000
void move_to_court(object ob)
{
	string room;
	int times;

	ob->apply_condition("robot", 15);
	message_vision("$N把$n带去了法庭。\n", this_object(), ob);
	if( !stringp(room = base_name(environment(ob))) ){
		if (ob->query("enter_wuguan"))
			room = "/d/wuguan/dayuan";
		else    room = "/d/city/chmiao";
	}
	if ( ob->query("robot") < 2 ) {
		ob->set("catch_robot_place", room);
		ob->move("/d/wizard/robot_court");
		tell_object(ob,"你已经累积被银翼杀手抓送机器人法庭"+chinese_number(ob->add("robot",1))+"次了。\n");
	} else{
		ob->delete("robot");
		times = ob->add("rules",1);
		ob->set("relax_timeout_room",room);
		ob->apply_condition("relax", times*30);
		tell_object(ob,"您因为「机器人」，违反书剑游戏规则共计" + chinese_number(times) +
			"次，决定给予关禁闭于桃花源"+chinese_number(times*10)+"分钟的处罚。\n");

		shout(HIW "\n【纪律】"+ob->query("name")+"("+capitalize(ob->query("id"))
			+")因为「机器人」，违反书剑游戏规则共计"
			+chinese_number(times)+ "次，决定给予关禁闭"+chinese_number(times*10)+"分钟的处罚。\n\n" NOR);

		tell_object(ob, "银翼杀手把你直接抓到了桃花源。\n");
		ob->move("/d/wizard/relax");
		log_file("nosave/ROBOT", sprintf("%s %s(%s)共计违规 %d 次。\n",
			ctime(time())[0..15],  ob->query("name"), ob->query("id"), times));
	}
}

void test1()
{
	object me = this_object();

	if (ob) {
		timer -= 10;
		if (timer > 0) {
			message("channel", "银翼杀手警告你：你还有" + chinese_number(timer) + "秒钟的考虑时间。\n", ob);
			me->move(ob, 1);
			call_out("test1", 10);
		} else {
			if (!interactive(ob) || query_idle(ob) >= 180) {
				"/cmds/usr/quit"->main(ob);
				if (me) destruct(me);
			} else {
				// 防止player故意晕倒等bug. snowman@SJ 12/06/2000.
				if (!living(ob)) ob->revive();
				message_vision(
					query("name")+"叹了口气道：$N一点反应都没有，又是一个机器人嫌犯！\n", ob
				);
				move_to_court(ob);
				destruct(me);
			}
		}
	}
	else destruct(me);
}

void test_player(string player)
{
	object ob = find_player(player);

	if (ob) test_robot(ob);
}
