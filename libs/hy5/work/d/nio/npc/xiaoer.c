// waiter.c

inherit NPC;

int ask_key();

void create()
{
	set_name("店小二", ({ "xiao er", "xiao", "xiaoer", "waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位店小二正懒洋洋地坐着，好象几年没发工钱了一样。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	set("inquiry", ([
		"name" : "不敢不敢，小的叫王小二，打从三年前就在这里做跑堂的了。",
		"rumors" : "上次一个红毛鬼子死在这里，就有了闹鬼的传说，只好把门锁了起来！唉，生意也因此冷淡了。",
		"here" : "这里叫做归来客栈。",
		"红毛鬼子": "就死在楼上的西房里。",
		"桃花岛": "传说海上有这么一座小岛，岛上住着一个恶魔。",
		"钥匙": (: ask_key :),
		"key": (: ask_key :),
		"扬州" : "在苏州的西北。",
		"苏州" : "在扬州的东南边，出扬州东门去找。",
		"杭州" : "在苏州的东南边。",
		"少林" : "在河南少室山，从扬州往北可以走到。",
		"少林寺" : "在河南少室山，从扬州往北可以走到。",
		"少林派" : "在河南少室山，从扬州往北可以走到。",
		"武当" : "在湖北境内，出了扬州往南面走吧。",
		"武当山" : "在湖北境内，出了扬州往南面走吧。",
		"武当派" : "在湖北境内，出了扬州往南面走吧。",
		"星宿" : "在天山西边，从扬州往西去找。",
		"星宿海" : "在天山西边，从扬州往西去找。",
		"星宿派" : "在天山西边，从扬州往西去找。",
		"明教" : "在昆仑山东边，从扬州往西走。",
		"光明顶" : "在昆仑山东边，从扬州往西走。",
		"慕容" : "在姑苏燕子圬，去苏州找找看吧。",
		"姑苏慕容" : "在姑苏燕子圬，去苏州找找看吧。",
		"归云庄" : "在太湖边上，从苏州往南走。",
		"丐帮" : "这可是个秘密呀。",
		"昆仑" : "在遥远的西域，一直往西走吧。",
		"昆仑山" : "在遥远的西域，一直往西走吧。",
		"昆仑派" : "在遥远的西域，一直往西走吧。",
		"古墓" : "在终南山，从扬州向北再折向西南吧。",
		"终南山" : "从扬州向北再折向西南吧。",
		"大理" : "在大宋的南边，所以要从扬州往南走。",
		"华山" : "在陕西境内，从扬州城西向北走可以到达。",
	]) );
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
"店小二嚷声说道，“天下第一大门派就是少林。”\n",
"店小二伸出右大姆指, 道，“天下第一帮么, 自然是丐帮了。”\n",
"店小二小声说道，“天下第一教, 是人称魔教的明教。”\n",
"店小二好奇地问，“武当山, 昆仑山, 五岳剑派, 挑哪一个好? ”\n",
"店小二叹息道，“神雕侠侣, 相继亡故, 不知古墓一派可有传人。”\n",
"店小二怒冲冲, 高声叫嚷，“非杀了那帮星宿恶贼不可。”\n",
"店小二笑嘻嘻地说道，“咱前年做生意到大理, 还真碰上了大理国皇帝。”\n",
"店小二神秘一笑, 道，“听说桃花岛岛主黄药师最近云游后, 又回岛了。”\n",
"店小二指了指东南方, 哈哈大笑道，“都什么朝代了, 还要什么大燕国。”\n",
        }) );

}

void init()
{	
	object ob;

	::init();
	if (base_name(environment()) != query("startroom")) return;
	if( interactive(ob = this_player()) && visible(ob) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if (!present(ob, environment())) return;
	say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
		+ "，快进来坐。\n");
}

int accept_object(object who, object ob)
{
	if (ob->query("money_id") && ob->value() >= 400) 
	{
		tell_object(who, "店小二一哈腰，连不迭地说道：多谢您老，客官请上楼歇息。\n");
		who->set_temp("rent_paid",1);
		return 1;
	}
	return 0;
}

void relay_emote(object me,string arg)
{
	command(arg+" "+me->query("id"));
}

int ask_key()
{
	object ob=this_player();

	if (!present("kezhan key",ob)) {
		say("小二高兴地说：客官您喜欢住鬼屋吗？那可太好了。钥匙给您。\n" );
		new("d/nio/obj/key")->move(ob);
	}
	else say("小二撅着嘴说：您怎么又来了，刚才不是您拿走的吗？\n");
	return 1;
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("小二连忙冲$N打揖道：“我可是老实人，客官您就别拿我寻开心了。”\n", ob);
	message_vision("$N看着他的倒霉样，实在下不了手。”\n", ob);
}

void unconcious()
{
	say( "小二大喊一声：“我不行了，快来接班！”\n");
	say( "结果从楼上又走下来一个小二来，说：“没问题，交给我吧。”\n");
	say( "前一个小二快快乐乐地离开了。\n");
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
}

void die()
{
	unconcious();
}

