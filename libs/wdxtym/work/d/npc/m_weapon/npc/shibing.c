// npc: shijian.c
// Jay 3/26/96
#include <ansi.h>
inherit NPC;
string ask_met();

void create()
{
	set_name("阿笙", ({ "asheng"}) );
	set("nickname", RED "神兵" NOR );
	set("gender", "女性" );
	set("age", 20);
	set("long", 	
		"他头上包着白布头巾，一袭白袍，没有一丝褶皱。\n");
	set("str", 25);
	set("dex", 20);
	set("con", 17);
	set("int", 30);
	set("shen_type", 0);
	set("max_neli",500);
	set("jiali",50);

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("force",150);
	set_skill("sword",150);
	set_skill("parry",90);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage",50);

	set("combat_exp", 250000);
	set("score",0);
	
	set("attitude", "peaceful");
        
	set("inquiry", ([
		"铸神兵"  : "师傅命我帮助别人铸神兵，但到现在也不见一个人影。谁要铸神兵呢？\n",
		"原料"  : "铸神兵可用寒丝羽竹，海底金母，千年神木。但效果各不一样。\n",
		"修理"  :  (: ask_met() :),
		
	]) );

	setup();

	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	::init();
	add_action("do_zhu","zhu");
}


int accept_object(object who, object ob)
{	
	if((int)(who->query("weapon/make1")) ){
		say("阿笙一脸茫然：您已经有一把自造的神兵了，还来干什么？难到不可手么？\n");
		return 2;
	}
	if((int)(!who->query("feisheng/s1")) ){
		say("阿笙一脸茫然：阁下尚未飞升吧？gjb\n");
		return 2;
	}	
	who->set_temp("m_shenbing",1);
//	switch ((string)ob->query("name") ) 
	switch ((string)ob->query("id") ) 
	{
//		case "千年神木": 
		case "shen mu": 
			who->add_temp("shenmu",1);
			break;
//		case "海底金母":
		case "jin mu":
			who->add_temp("jinmu",1);
			break;
//		case "寒丝羽竹": 
		case "han zhu": 
			who->add_temp("hanzhu",1);
			break;
		default :
			message("vision","这是什么！师傅说这不能用来打造兵器！",who);
			return 0;
	}
	message("vision","阿笙低头检视了一下手中的"+(string)ob->query("name")+
			"点了点头说：\n", who);
	message("vision","。。。好我们现在就开始铸神兵\n", who);
	write("请这位"+RANK_D->query_respect(who)+"给剑起名字吧！(zhu 神兵的名字 英文代号)\n");
	return 2;
}

int do_zhu(string arg)
{
	string o_name,id,w_name;
	object sword,make_time;   //生成的武器句柄
	object me;
	me = this_player();
	if(!(me->query_temp("m_shenbing")) ) 
		return notify_fail("什么?\n");
	me->delete_temp("m_shenbing");
	me->delete_temp("get_orc");
	me->delete_temp("or");

	if((me->query("weapon/make1")) ){
		say("阿笙一脸茫然：您已经有一把自造的神兵了，还来干什么？难到不可手么？\n");
		return 1;
	}
	if( !arg )
		return notify_fail("阿笙认真的说：想好神兵的名称及代号后在对我说。\n");

	sscanf(arg ,"%s %s" ,w_name ,id);
	if(!w_name||!id)
		return notify_fail("什么?(使用zhu 神兵的名字 英文代号\n)");
	if(me->query_temp("shenmu") ) o_name="千年神木";
	if(me->query_temp("jinmu") )   o_name="海底金母";
	if(me->query_temp("hanzhu") )   o_name="寒丝羽竹";
	make_time=NATURE_D->game_time();
	message_vision(me->name()+"沉吟了一会，对阿笙悄声说了几句话。阿笙点了点头。说：好吧！\n",me );
	message_vision("\n阿笙回过身，转向身后的一个巨大的火炉，鼓动真气燃起了熊熊的大火。说：开始！\n",me );
	message_vision(BLU "$N双手握住一个巨大的铁锤，猛的向炉中渐渐红热起来的"+o_name+"挥去！\n" NOR,me);
	message_vision(RED "只听得棚的一声巨响，锤头和"+o_name+"粘在了一起。\n" NOR,me );
	message_vision(YEL "$N只觉得掌心一热，浑身的血液似乎都沸腾了起来！\n" NOR,me);
	message_vision(HIM "一身精血胶合着汩汩的内气，源源不断的向炉中的"+o_name+"涌去！\n" NOR,me );

	message_vision(HIR "只听咯的一声轻响，一柄巨器从炉中倏然跃起。化作一道青电猛的向$N的前胸刺来！！\n" NOR,me );
	say("阿笙见状大叫：神兵初成，人血以祭！！闪开！\n");
	message_vision("$N只觉得眼前一花，一条白影迅捷无比的挡在了$N的身前。\n",me );	
	message_vision("巨剑透胸穿出，阿笙惨号一声，鲜血溅得你满脸都是！\n",me );
	message_vision(RED "阿笙脚下一个不稳，倒在了地上。阿笙已经奄奄一息了。\n" NOR,me);
	this_object()->set("max_qi",10);
	message_vision("巨剑又飞了起来，飞到半空，当的一声落回到地上。\n炉中的火灭了。一室的劲气化于无形，一切又归于沉寂。\n",me );
	
	me->set("qi",10);
	me->set("jing",10);
	me->set("neili",0);

        w_name = replace_string(w_name, "$BLK$", BLK);
        w_name = replace_string(w_name, "$RED$", RED);
        w_name = replace_string(w_name, "$GRN$", GRN);
        w_name = replace_string(w_name, "$YEL$", YEL);
        w_name = replace_string(w_name, "$BLU$", BLU);
        w_name = replace_string(w_name, "$MAG$", MAG);
        w_name = replace_string(w_name, "$CYN$", CYN);
        w_name = replace_string(w_name, "$WHT$", WHT);
        w_name = replace_string(w_name, "$HIR$", HIR);
        w_name = replace_string(w_name, "$HIG$", HIG);
        w_name = replace_string(w_name, "$HIY$", HIY);
        w_name = replace_string(w_name, "$HIB$", HIB);
        w_name = replace_string(w_name, "$HIM$", HIM);
        w_name = replace_string(w_name, "$HIC$", HIC);
        w_name = replace_string(w_name, "$HIW$", HIW);
        w_name = replace_string(w_name, "$NOR$", NOR);

	me->set("weapon/make1",1);		//武器制造后防止再造的标志		
	me->set("shenbing/name",w_name +NOR);	//武器的名称
	me->set("shenbing/id",id);		//武器的代号
	me->set("shenbing/lv",5000000);    	//武器等级
	me->set("shenbing/or",o_name);	//记录制造原料
	me->set("shenbing/value",0);	      	//记录武器升级已有的点数	
	me->set("shenbing/type","神兵");
	me->set("weapon/time",make_time);

	sword=new("/d/npc/m_weapon/weapon/m_shenbing",1);	//生成新剑
	sword->move(this_player());
	message_vision("阿笙摸起地上，带着斑斑血迹还有些烫手的巨剑，说：\n剑。。已。。成。。，阿笙的任务。。。也就完成了。。。。\n",me );
	say("阿笙艰难的说：剑。。您。。收好，我该走了。。。\n");
	message_vision("阿笙说完。倏的便不见了。\n",me);
	                CHANNEL_D->do_channel(find_object(ITEM_D), "rumor",
                              "听说后天灵宝" + sword->name() + HIM +
                              "来到了人间。");
	this_object()->die();
	return 1;
}

string ask_met()
{
	object weapon;
	object gold;
	object *inv;
	int i;
        object me = this_player();
	inv = all_inventory(me);
	for(i=0; i<sizeof(inv); i++) {
        if((int)(inv[i]->query("weapon_prop")&&inv[i]->query("ownmake")))
        return "你身上不是有武器吗？";


        if(me->is_busy())
        return "你上一个动作还没有完成。";

        gold = present("gold_money", this_player());
        if( !gold) return "你身上没有金子。";

        if((int) gold->query_amount() < 101)
        return "你身上没带够一百两金子。";

	if (me->query("shenbing/type")) {

			weapon = new("/d/npc/m_weapon/weapon/m_shenbing");
			weapon->move(me);
        gold->add_amount(-100);
        me->start_busy(5);
			return "修好了,请quit,再重新登陆一次!";
		
          }
else return "你造过武器吗？";
}
}