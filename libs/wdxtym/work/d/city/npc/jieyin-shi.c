// city/npc/jieyin-shi.c
inherit NPC;
string do_fly() ;
void create()
{
	set_name("门派接引", ({ "jieyin shi"}));	
	set("gender", "女性");
	set("age", 20);
	set("per", 30);
	set("con", 30);
	set("int", 30);
	set("level", 20);
	set("icon","00964");
	set("dex", 30);
	set("str", 30);
	set("long","她是门派的接引使者，帮助新手或门派成员快速往返门派！！！\n");
	set_skill("unarmed", 100);
	set_temp("apply/damage", 50);
	set("inquiry", ([
		"门派接引": (:do_fly:),  
	]) );
	set("combat_exp", 500000);
	set("attitude", "friendly");	
	setup();
	carry_object(__DIR__"cloth/feature")->wear();
}

void init()
{
	add_action("fly","fly");
}

string do_fly()
{
	write(ZJOBLONG"嘿嘿，我可以帮你快速到达各大门派：\n"
		ZJOBACTS2+ZJMENUF(3,3,8,30)+
		"武当松林:fly wudang"ZJSEP
		"峨眉山门:fly emei"ZJSEP
		"少林山脚:fly shaolin"ZJSEP
		"华山入口:fly huashan"ZJSEP
		"天山脚下:fly xingxiu"ZJSEP
		"逍遥树林:fly xiaoyao"ZJSEP
		"古墓草地:fly gumu"ZJSEP
		"终南山上:fly quanzhen"ZJSEP
		"雪山寺前:fly xueshan"ZJSEP
		"血刀门前:fly xuedao"ZJSEP
		"金牛武馆:fly wuguan\n");
		return "哈哈哈。。。";
}
int fly(string arg)
{
	object me=this_player();
	write("嘿嘿，那就让我就送你一程吧！！！\n");
	write(HIY" 门派接引使者拿出了一樽大炮，一把抓住你，塞了进去。。。。。"NOR"\n");
	write(HIG" ~轰~的一声，你大叫着 < 我一定会回来的 > 。。。。"NOR"\n");
	write(HIB"........系统对你默哀了3秒钟........."NOR"\n");
	if (arg=="wudang") me->move("/d/wudang/slxl1");	//武当松林
	else if (arg=="emei") me->move("/d/emei/bgsgate");	//娥眉山门
	else if (arg=="shaolin") me->move("/d/shaolin/shijie1");	//少林山脚
	else if (arg=="huashan") me->move("/d/village/eexit");	//华山入口
	else if (arg=="lingjiu") me->move("/d/xingxiu/shanjiao");	//天山山脚
	else if (arg=="xingxiu") me->move("/d/xingxiu/shanjiao");	//天山山脚
	else if (arg=="xiaoyao") me->move("/d/xiaoyao/shulin1");	//逍遥树林
	else if (arg=="gumu") me->move("/d/gumu/caodi");	  //古墓草地
	else if (arg=="quanzhen") me->move("/d/gumu/zhufeng");	  //终南山主峰
	else if (arg=="xueshan") me->move("/d/xuedao/nroad4");	//雪山寺
	else if (arg=="xuedao") me->move("/d/xuedao/wangyougu");	//血刀门,忘忧古
	else if (arg=="wuguan") me->move("/d/city3/wuguan");	//金牛武馆
	else write(HIR"\n根本就没这个门派，你要去那个门派"NOR"\n");
	return 1;
}
