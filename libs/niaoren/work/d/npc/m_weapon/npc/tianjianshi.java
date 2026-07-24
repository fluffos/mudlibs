// npc: /d/npc/m_weapon/npc/tianjianshi.c
// Jay 3/26/96
#include <ansi.h>
inherit NPC;

int do_weapon();
object creat_weapon();

void create()
{
        set_name("歐冶子", ({ "ouye zi", "zi" }) );
        set("nickname", RED "赤心劍膽" NOR );
	set("gender", "男性" );
        set("age", 60);
        set("long", 	
            "他頭上包著頭巾，三縷\長髯飄洒胸前，面目清瘦但紅暈有光，\n"
            "二目炯炯有神，爍爍閃著竟似是凜凜的劍光，渾身似乎都包圍\n"
	    "在一股劍氣之中。\n");
        set("str", 25);
        set("dex", 20);
        set("con", 17);
        set("int", 30);
        set("shen_type", 0);
	set("max_neli",5000);
	set("jiali",50);

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("claw",200);
        set_skill("jiuyin-baiguzhao",200);
        set_skill("force",150);
        set_skill("sword",150);
        set_skill("bibo-shengong",100);
        set_skill("luoying-shenjian",100);
        set_skill("parry",90);
        set_skill("anying-fuxiang",100);
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage",50);

	create_family("玄天派",1,"弟子");

        set("combat_exp", 250000);
	set("score",0);
	
        map_skill("force","bibo-shengong");
	map_skill("parry","luoying-shenjian");
	map_skill("sword","luoying-shenjian");
	map_skill("claw","jiuyin-baiguzhao");
	map_skill("dodge","anying-fuxiang");

	
	set("attitude", "peaceful");
        
	set("inquiry", ([
            "鑄劍"  : "鑄劍可是件十分艱苦的事，要消耗人的精氣和內力，你有決心和毅力嗎？\n",
	    "原料"  : "鑄劍可用千年玄鐵。。。你找到了我才能幫你鑄劍。\n",
	    "兵器"  :  (: do_weapon() :),
       ]) );

        setup();
        set("chat_chance", 3);
        set("chat_msg", ({
             "歐冶子撫劍而歌：巨闕神兵兮，人鑄就。蓋\世寶劍兮，配英雄！\n",
	     "歐冶子低頭沉吟，似乎在思考什么\。\n"
	     "歐冶子嘆了一口氣：神兵配英雄，可英雄。。。。。。\n"
       }) );
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
        ::init();
        add_action("do_answer","answer");
}


int accept_object(object who, object ob)
{	
	switch ((string)ob->query("name") ) 
	{
		case "菩提子"  :
		case "叫化雞"  :
		case "四十二章經一":
		case "四十二章經七":
		case "四十二章經五":
		case "辟邪劍譜":
		case "白虎堂令牌":
			if( !(who->query_temp("condition")) )	{
				message_vision(HIC "歐冶子一愣：我對你說過我要這樣東西么?\n" NOR, who);
				return 2;
			}
			else {
			who->delete_temp("condition");
			message_vision(HIG "歐冶子微笑著：很好很好！那我就幫你這一次吧!\n" NOR, who);
			who->set_temp("condition_ok",1);
			do_weapon();
			return 2;
			}
	}
	if((who->query("weapon/制造")) ){
		say("歐冶子一臉茫然：您已經有一把自造的武器了，還來干什么\？難到不可手么\？\n");
		return 2;
	}
//	switch ((string)ob->query("name") ) 
	switch ((string)ob->query("id") ) 
	{
//		case "千年神木": 
		case "shen mu": 
			who->set_temp("or",1);
			who->set_temp("get_orc",1);
			break;
//		case "海底金母":
		case "jin mu":
			who->set_temp("or",2);
			who->set_temp("get_orc",1);
			break;
//		case "寒絲羽竹": 
		case "han zhu": 
			who->set_temp("or",3);
			who->set_temp("get_orc",1);
			break;
		default :
			message("vision","這是什么\！這不能用來打造兵器！",who);
			return 2;
	}
	message("vision","歐冶子低頭檢視了一下手中的"+(string)ob->query("name")+
			"點了點頭說：\n",who);
	write("我這兒可以打造以下兵器：\n"+
	      "     劍(jian)\n"+
	      "     刀(dao)\n"+
	      "     棍(gun)\n"+
	      "     杖(staff)\n"+
	      "     鞭(whip)\n");	  	
	say("這位"+RANK_D->query_respect(who)+"要造什么\兵器？決定了告訴我(answer)。\n");
	return 2;

}

int do_answer(string arg)
{
	object me,w_or;
	me = this_player();
	if(!(me->query_temp("get_orc") ) ){
		write("你找到原料了嗎？\n");
		return 0;
	}
	
	if(!arg){
	   write("你要造什么\兵器？\n");
	  return 0;
	}
	message("vision",me->name()+"對歐冶子輕聲說了几句。\n",environment(me), ({me}) );
	switch (arg) {
	  case "jian" :
		me->add_temp("sword",1);
		write("帶著原料去找侍劍吧!\n");
		message("vision","去吧！"+me->name()+"!\n",me);
		break;
	  case "dao" :
		me->add_temp("blade",1);
		write("帶著原料去找侍刀吧!\n");
		message("vision","去吧！"+me->name()+"!\n",me);
		break;
	  case "gun" :
		me->add_temp("club",1);
		write("帶著原料去找侍棍吧!\n");
		message("vision","去吧！"+me->name()+"!\n",me);
		break;
	  case "staff" :
		me->add_temp("staff",1);
		write("帶著原料去找侍杖吧!\n");
		message("vision","去吧！"+me->name()+"!\n",me);
		break;
	  case "whip" :
		me->add_temp("whip",1);
		write("帶著原料去找侍鞭吧!\n");
		message("vision","去吧！"+me->name()+"!\n",me);
		break;
	  default :
		message_vision(HIC "歐冶子一臉狐疑：什么\兵器？\n" NOR,me);
		return notify_fail("歐冶子仔細的說：此事不可兒戲，請慎重!!\n");
	}
	switch ( me->query_temp("or") ) {
	  case 1:
		w_or = new("/d/npc/m_weapon/tan/item/shenmu",1);
		w_or->move(me);
		message_vision(HIC "歐冶子給了$N一塊千年神木\n" NOR, me);
		break;
	  case 2:
		w_or = new("/d/npc/m_weapon/tan/item/jinmu",1);
		w_or->move(me);
		message_vision(HIC "歐冶子給了$N一塊海底金母\n" NOR, me);
		break;
	  case 3:
		w_or = new("/d/npc/m_weapon/tan/item/hanzhu",1);
		w_or->move(me);
		message_vision(HIC "歐冶子給了$N一塊寒絲羽竹\n" NOR, me);
		break;
	}
	return 1;
}

int do_weapon()
{
	object me,weapon,obj;
	string w_id;
	me = this_player();
	w_id = me->query("weapon/代號");

	if( !(me->query("weapon/制造")) )
		return notify_fail("你造過兵器嗎?\n");

	if( objectp(obj = present(w_id, me)) ) {
		say("歐冶子臉色一沉：您的武器不就在你手邊么\？還來干什么\！\n");
		return 1;
	}

	if( !(me->query_temp("condition_ok")) ) {
		message_vision(HIY "這位"+RANK_D->query_respect(me)+"想要從新得到兵器?這不難.不過......\n" NOR, me);
		message_vision(HIY "歐冶子沉吟了一下說:你得找到我要的東西.\n" NOR, me);
		switch( random(5) ) {
			case 0:
				message_vision("拿到菩提子,再來吧!\n",me);
				break;
			case 1:
				message_vision("給我叫化雞,我就幫你!!\n",me);
				break;
			case 2:
				message_vision("嗯...你就拿黑木崖白虎堂令牌來換吧!!\n",me);
				break;
			case 3:
				message_vision("....我想看看有名的手鐲!!\n",me);
				break;
			case 4:
				message_vision("如果你能替我找到辟邪劍譜的話......\n",me);
				break;
			}
		me->set_temp("condition",1);
		}
	else	{
		me->delete_temp("condition_ok");
		weapon = creat_weapon();
		weapon->move( me );
	}
	return 1;
}

object creat_weapon()
{
	object me,weapon;
	string mask;	//the verible that record the type of weapon
	me = this_player();
	mask = me->query("weapon/類型");
	switch(mask)	{
		case "劍":
			weapon = new("/d/npc/m_weapon/weapon/m_sword",1);
			return weapon;
		case "刀":
			weapon = new("/d/npc/m_weapon/weapon/m_blade",1);
			return weapon;
		case "棍":
			weapon = new("/d/npc/m_weapon/weapon/m_club",1);
			return weapon;
		case "杖":
			weapon = new("/d/npc/m_weapon/weapon/m_staff",1);
			return weapon;
		case "鞭":
			weapon = new("/d/npc/m_weapon/weapon/m_whip",1);
			return weapon;
	}
}
