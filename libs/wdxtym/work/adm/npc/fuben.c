inherit NPC;
string do_fly() ;
void create()
{
	set_name(HIW"老魔"NOR, ({ "xiaobai"}));
	set("gender", "女性");
	set("age", 20);
	set("per", 30);
	set("con", 30);
	set("int", 30);
	set("level", 20);
	set("icon","00964");
	set("dex", 30);
	set("str", 30);
	set("long",HIW"她是巫师老魔的分身，掌管空间。\n"NOR);
	set_skill("unarmed", 100);
	set_temp("apply/damage", 50);
	set("inquiry", ([
		"传送": (:do_fly:),
	]) );
	set("combat_exp", 500000);
	set("attitude", "friendly");
	setup();
	carry_object("/d/city/npc/cloth/feature")->wear();
}

void init()
{
	add_action("fly","fly");
}


string do_fly()
{
	write(ZJOBLONG"传送副本：\n"
		ZJOBACTS2+ZJMENUF(3,3,8,30)+
	//	"杀日寇:fly yz"ZJSEP
	//	"挖矿场:fly lvliu"ZJSEP
	//	"奇异空间:fly qiyi"ZJSEP	
		"华山论剑:fly lunjian"ZJSEP
		"龙族秘境:fly longzhu"ZJSEP
		"屠人大赛:fly turen"ZJSEP
		"武馆试炼:fly shilian\n");
		return "老魔随手挥出一道空间裂缝，一脚把你踢了进去。";
}
int fly(string arg)
{
	object me=this_player();
	write("嘿嘿，小心别挂了！！！\n");
	if (arg=="shilian") me->move("/d/city/wuguan/qianting");
	else if (arg=="turen") me->move("/d/pk/enter");
	else if (arg=="longzhu") me->move("/fuben/longzhu/longzhu");
	else if (arg=="lunjian") me->move("/d/lunjian/enter");
	//else if (arg=="daojian") me->move("/maze/daojian/fightroom");	
///	else if (arg=="jiangshi") me->move("/maze/jiangshi/fightroom");
//	else if (arg=="shenlin") me->move("/maze/forestnew/enter");
//	else write(HIR"\n根本就没这个副本"NOR"\n");
	return 1;
}
