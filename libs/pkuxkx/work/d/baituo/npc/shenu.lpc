//Cracked by Roath
// shenu.c 蛇奴
// maco

/***************************************************************

breed		: 现在可学poison的极限
new_breed	: 最新一次培养怪蛇成功後，可学poison的极限
new_breed_time	: 最新一次开始培养怪蛇的时间
checked_snake	: 是否检查过这次的怪蛇？
snake_amount    : 目前培养的怪蛇数量
guaishe         : 是否取走了怪蛇（每次只能取一条）
***************************************************************/
#include <ansi.h>

inherit NPC;

int ask_snake();
int ask_guaishe();
string ask_shezhang();
string ask_qushe();
int do_order(string);

void create()
{
	set_name("蛇奴", ({ "she nu" ,"nu"}));
	set("long", "他是负责看管白驼山庄蛇场的蛇奴，担当替庄主、少主养育怪蛇的事务。\n");
	set("gender", "男性");
	set("title", "白驼山庄");
	set("age", 35);

	set_skill("hand", 30);
	set_skill("shexing-diaoshou", 30);
	set_skill("dodge", 20);
	set_skill("parry", 30);
	set_skill("force", 20);
	map_skill("hand","shexing-diaoshou");
	map_skill("dodge","chanchubu");
	prepare_skill("hand","shexing-diaoshou");

	set("str", 28);
	set("int", 21);
	set("con", 27);
	set("dex", 21);

         set("no_get", 1);
	set("max_neili", 200);
	set("jiali", 10);
	set("combat_exp", 10000);

	set("attitude", "peaceful");
	set("shen_type", -1);
	set("inquiry", ([
		"蛇" : (: ask_snake :),
		"snake" : (: ask_snake :),		
		"怪蛇" : (: ask_guaishe :),
		"怪蛇杖" : (: ask_shezhang :),
		"guaishe" : (: ask_guaishe :),
		"取蛇" : (: ask_qushe :),
	]));
	set("count",2);

	setup();
	carry_object("/d/xingxiu/obj/wcloth")->wear();
}

void init()
{
	::init();
	add_action("do_order", "order");
}

int ask_snake()
{
	object me, snake;
	int time, poison, breed, new_breed;


	me = this_player();

	poison = (int)me->query_skill("poison",1);
	breed = me->query("baituo/breed");
	new_breed = me->query("baituo/new_breed");

	if( me->query("family/family_name") != "白驼山" ) {
		command("say "+RANK_D->query_rude(me)+"想打听咱们的蛇儿，莫非动着什麽歪脑筋？");
		return 1;
	}

/*
  if (me->query("combat_exp") >= 30000000) {
          command("say 少主已经是江湖中赫赫有名的人物了，别老是在白驼山屈着，出去闯荡闯荡吧。");
          return 1;
  }
*/
	if (me->query("family/master_name") != "欧阳锋") {
		command("say 场子里的蛇都是庄主和少主所饲养的。");
		return 1;
	}

	if( !me->query("baituo/new_breed_time") && !me->query("baituo/checked_snake")) {
		command("say 场子里没有少主养的蛇，您是也想养些麽？");
		return 1;
	}

	if( me->query("baituo/checked_snake") ) {
		command("say 少主上次培育的蛇种已有结果，是否要再捉新的品种来改良？");
		return 1;
	}

	time = time() - me->query("baituo/new_breed_time");

	if(time < 300) {
		command("say 少主前次捉回来的蛇群，小的日日夜夜都用心看顾，就等它们繁殖了。");
		return 1;
	}

	if(time < 600) {
		command("say 少主前次捉回来的蛇已经下蛋了，想必近日便会孵化。");
		return 1;
	}

	command("say 小蛇已经出生了，小的这就去把它带来。");
	message_vision("\n蛇奴匆匆忙忙地退了下去。\n", me);
	
	this_object()->move("/d/baituo/temproom");

        remove_call_out("bring_snake");
        call_out("bring_snake", 3, me);
        return 1;
}

void bring_snake(object me)
{
	object snake;
	int poison, breed, new_breed;
	int exp1,pot1,exp2,pot2,exp3,pot3;	
	string result;

	poison = (int)me->query_skill("poison",1);
	breed = me->query("baituo/breed");
	new_breed = me->query("baituo/new_breed");

//	if( new_breed > poison+10 )  new_breed = poison + 10; 
//	if( new_breed > 400 ) new_breed = 400;

	this_object()->move("/d/baituo/shechang");


	if( new_breed > poison ) {
		me->set("baituo/guaishe",1);
		snake = new("/d/baituo/npc/new_snake");
		snake->set_name(HIW"小怪蛇"NOR, ({ "guai she", "she", "snake" }) );
		snake->set("long", 
		"一条银鳞闪闪的小蛇，形状怪异，是白驼山少主"+me->name()+"第"
		+chinese_number(me->query("baituo/manage"))+"次培养出的蛇种。\n"
		);
		if( breed >= 400 )
		result = HIW"这条怪蛇的毒性猛恶一如以往，可见你对蛇毒的掌握，已然纯熟如意。\n"NOR;
		else if( new_breed > breed ) 
		result = HIY"你成功地培养出了毒性更胜原种的怪蛇！\n"NOR
		+ "如今，你对掌握毒物的法门领会更多，你的毒技和驭兽术都有了大幅度的提高。\n";
		else result = "虽然你培养出了怪蛇，但是神态不如以前的品种狰狞，想必毒性有所不及。\n";
	}
	else if( new_breed >= 240 ) {
		me->set("baituo/guaishe",1);
		snake = new("/d/baituo/npc/new_snake");
		snake->set_name(HIW"小怪蛇"NOR, ({ "guai she", "she", "snake" }) );
		snake->set("long", 
		"一条银鳞闪闪的小蛇，形状怪异，是白驼山少主"+me->name()+"第"
		+chinese_number(me->query("baituo/manage"))+"次培养出的蛇种。\n"
		);
		result = "虽然你培养出了怪蛇，但是以你的使毒本领而言，这等毒性的怪蛇称不上突破，仅是增生怪蛇数量而已。\n";
	}
	else {
		snake = new("/d/baituo/npc/new_snake");
		snake->set_name("小毒蛇", ({ "snake", "she"}) );
		snake->set("long", 
		"一条三角尖头的小蛇，是白驼山少主"+me->name()+"第"
		+chinese_number(me->query("baituo/manage"))+"次培养出的蛇种。\n"
		);
		if( !breed || breed == 0 )
		result = "这条毒蛇并无特异之处，看来这次培养的蛇种不甚成功。\n";
		else if( new_breed > breed ) 
		result = "你仔细检视，觉得这条蛇的毒性虽然胜过上回培养的品种，然而依旧不够理想。\n";
		else result = "你仔细端详，却见这条毒蛇毫无特异之处，看来毒性反而比从前弱了。\n";
	}

	message_vision("\n过了一会儿，蛇奴走了出来。\n", me);
	command("say 这是最近养育的小蛇中毒性最强的一条，请少主过目。");
	message_vision("一条"+snake->name()+"蜿蜒地游了过来。\n", me);

        snake->move(me);
	snake->set_owner(me);
	snake->set("who_breed", me->query("id"));
	snake->set("snake_poison", new_breed);
	//蛇的毒性，可能用在咬人后让对方中毒的程度，变为蛇杖后，蛇杖的毒性等（暂时未使用）

	write(result);

        log_file("breed_snake",
		sprintf("%s(%s) 第%d次培养结果：%s(毒性%d) on %s \n", 
		me->name(), me->query("id"), me->query("baituo/manage"), snake->name(), new_breed, ctime(time())));

	exp1 = new_breed*(10 + random(15));
	pot1 = new_breed;
	exp2 = new_breed*(20 + random(30));
	pot2 = new_breed*2 + 1;
	exp3 = new_breed*(5 + random(10));
	pot3 = new_breed/5 + 1;
			
	if(new_breed > 400 && new_breed < breed) {
		me->add("baituo/success_breed", 1);
//		if( me->query_skill("training") < 400 )
			me->improve_skill("training", new_breed*(5+random(10)) );
//		if( me->query_skill("poison") < 400 )
			me->improve_skill("poison", new_breed*(5+random(10)) );
		me->add("combat_exp", exp1);
		me->add("potential", pot1);
                me->add("score", random(10)+10);
		tell_object(me,"你的经验增加了"+chinese_number(exp1)+"点。\n");
		tell_object(me,"你的潜能增加了"+chinese_number(pot1)+"点。\n");
                tell_object(me,"你的忠诚度增加了。\n");
	}
	else if( new_breed > breed ) 
	{
		me->set("baituo/breed", new_breed);
		me->add("baituo/success_breed", 1);
			me->improve_skill("training", new_breed*(10+random(10)) );
			me->improve_skill("poison", new_breed*(10+random(10)) );
		me->add("combat_exp", exp2);
		me->add("potential", pot2);
                me->add("score", random(20)+10);
		tell_object(me,"你的经验增加了"+chinese_number(exp2)+"点。\n");
		tell_object(me,"你的潜能增加了"+chinese_number(pot2)+"点。\n");
                tell_object(me,"你的忠诚度增加了。\n");
	}
	else
	{
		me->improve_skill("training", new_breed*(5+random(5)) );
		me->improve_skill("poison", new_breed*(5+random(5)) );
		me->add("combat_exp", exp3);
		me->add("potential", pot3);

		tell_object(me,"你的经验增加了"+chinese_number(exp3)+"点。\n");
		tell_object(me,"你的潜能增加了"+chinese_number(pot3)+"点。\n");
		tell_object(me,"要继续努力啊。\n");
	}
	me->set("baituo/checked_snake", 1);
	me->delete("baituo/new_breed");
	me->delete("baituo/new_breed_time");

	return;
}

int ask_guaishe()
{
	object me;
	int num;
	me = this_player();
	num = me->query("baituo/snake_amount");

	if( me->query("family/family_name") != "白驼山" ) {
		command("say "+RANK_D->query_rude(me)+"想打听咱们白驼山的怪蛇，莫非动着什麽歪脑筋？");
		return 1;
	}

	if( me->query("family/master_name") != "欧阳锋" ) {
		command("say 庄主和少主费尽心思，以数种最毒之蛇相互杂交，才产下这些毒中之毒的怪蛇。");
		return 1;
	}
	if ( num < 1)
		command("say 现下场子里没有少主养的怪蛇。");
	else command("say 少主养在场子里的怪蛇，一共有"+chinese_number(num)+"条。如果少主现在需要可以向我打听“取蛇”。");

	if ( num > 10 )
	command("admire "+me->query("id"));
	return 1;
}

string ask_qushe()
{
	object me,she;
    int time;
	me = this_player();
	time = time() - me->query("baituo/guaishe_time");

	if (me->query("baituo/snake_amount") < 1)
                return ("少主目前还未培养出怪蛇。");
	if (time<1200)
		return ("目前小怪蛇还未长大。");
	if (me->query("baituo/guaishe"))
                return ("少主不是已经取走了一条怪蛇么？");

    she = new(CLASS_D("btshan")+"/obj/guaishe2");
	she ->move(environment(me));
    she -> set_owner(me);
	she -> set("who_breed", me->query("id"));
	she -> set("snake_poison", me->query("baituo/new_breed"));
    tell_object(me,"蛇奴交给你毒性最强的一条"+she->query("name")+"。\n");
	me -> set("baituo/guaishe",1);
	me->add("baituo/snake_amount", -1);
	me->delete("baituo/guaishe_time");

        return "少主可要小心照顾此蛇啊！";
}

string ask_shezhang()
{
	object me,she;
	me = this_player();
    if (query("count")<1)
                return ("我这里的怪蛇杖已经被拿完了。");
	if (me->query("baituo/guaishe"))
    {
		she = new(CLASS_D("btshan")+"/obj/gshezhan");
		she -> move(me);
		add("count",-1);
		tell_object(me,"蛇奴交给你一把"+she->query("name")+"。\n");
		she->set("master_id",me->query("id"));
                return "少主可要小心保管此杖啊！";
	}
        return "怪蛇杖暂时不能给你。";
}
int do_order(string arg)
{
	object me, room;
	int flag;
	me = this_player();
	
	if( me->query("family/family_name") != "白驼山" ) return 0;

	room = load_object("/d/baituo/shegu1");

	if( room->query("defense") ) flag = 1;
	
	if ( arg == "defense") {

		if( flag ) return notify_fail("蛇谷入口已经由毒气封住了。\n");

		if( me->query("family/master_name") != "欧阳锋" ) {
			message_vision(CYN"$N向蛇奴下令：放出密窖中的蛇毒，封住蛇谷的入口！\n"NOR, me);
			command("bored "+me->query("id"));
			command("say 哼，要不要封谷，你我都做不了主！");
			return 1;
		}

		message_vision(CYN"$N向蛇奴下令：放出密窖中的蛇毒，封住蛇谷的入口！\n"NOR, me);
		if (time() - room->query("open_time") < 300)
		{
			message_vision("蛇奴恭恭敬敬地说道：『少主，现在距上次关毒气还不足五炷香的时辰，须得等足了时辰才能再放毒气。』\n", me);
			return 1;
		}
		message_vision("蛇奴恭恭敬敬地答应，退到蛇场一角，启动了释放密窖毒气的机关。\n", me);
		message_vision(HIR"\n你听到蛇场外传来一阵嘶嘶轻响……\n"NOR, me);
		
		message("vision", HIR"你突然听到一阵嘶嘶轻响，一片血红色的雾气缓缓从土地下喷出，渐渐布满了整个谷口……\n\n"NOR,room );
		room->set("defense", 1);
		command("say 少主，办妥了！");
	}

	else if( arg == "remove" ) {
		if( !flag ) return notify_fail("蛇谷入口现在本就没有毒气。\n");


		if( me->query("family/master_name") != "欧阳锋" ) {
			message_vision(CYN"$N向蛇奴下令：停止从密窖释放毒气，开放蛇谷的入口！\n"NOR, me);
			command("kick "+me->query("id"));
			command("say 你想害死我不成？没有庄主下令，谁敢擅开蛇谷？");
			return 1;
		}
		message_vision(CYN"$N向蛇奴下令：停止从密窖释放毒气，开放蛇谷的入口！\n"NOR, me);
		message_vision(CYN"$N嘿嘿冷笑，说道："+RANK_D->query_self_rude(me)+"要让那些自居名门正派的人物，送上谷来给咱们蛇儿果腹！\n"NOR, me);

		command("fear "+me->query("id"));
		message_vision("蛇奴面有难色，但是被$N斜眼一瞪，还是战战兢兢地退开，解除了机关。\n", me);
		message_vision(WHT"\n你听到蛇场外传来一阵嘶嘶轻响，接着很快又安静下来。\n"NOR, me);
		message("vision", WHT"你突然听到一阵嘶嘶轻响，封锁在蛇谷前的红雾慢慢消散，土里也没有雾气再冒出来。\n不一会儿，烟消云散，蛇谷的入口完全呈现在眼前。\n\n"NOR,room );
		room->delete("defense");
		room->set("open_time",time());

		command("say 少主，小的依您吩咐，关了毒气，下次再放毒气需要五炷香的时辰以后，但庄主要问起来，您可得担待住……");
	}

	else return notify_fail("你要对蛇奴下什麽命令？ (defense or remove) \n");

	return 1;
}
