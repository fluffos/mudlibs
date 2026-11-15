// 老婆客串下
// jihaolan.c
// creat by shure@tomud.com 2010-02-18

inherit NPC;
inherit F_DEALER;

string ask_form(string name);
string ask_start();
void create()
{
	set_name("寄好兰", ({"ji haolan"}));
	set("gender", "女性");
	set("nickname", HIB"爱若幽兰"NOR);
	set("age", 21);
	 set("icon", "01394");
	set("long",
		"她是来自宝鸡,很温柔的女孩,是李毅的老婆。\n"
		"她每年都会来到幽兰走上一遭，帮助一些新人熟悉游戏，探索世态民情。\n"
		"你可以问问她关于"HIR"游戏介绍"NOR"的事情\n"
		"或许她可以给于你帮助哦!\n");

	set("startroom", "/d/city/guangchang");
	set("inquiry", ([
		"「帮助指南」"       : (: ask_form ,"newbie" :),
		"「闯荡江湖」"       : (: ask_start :),
	]) );
	set("duihuan",1);  //兑换
	set("vendor_goods", ({
	       "/clone/misc/shi",
	       "/clone/gift/jinkuai",
	       "/clone/gift/cagate",
	       "/clone/gift/ccrystal",
	       "/clone/gift/cdiamond",
	       "/clone/gift/cjade",
	       "/clone/suit/huashan/ling_boots",
	       "/clone/suit/huashan/ling_cloth",
	       "/clone/suit/huashan/ling_pants",
	       "/clone/suit/huashan/ling_sword",
	}));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
	add_action("do_pointlist", "list");
	add_action("do_huan", "huan");
}

//回收套装.
int accept_object(object who, object ob)
{
      int suit_point=0,suit_level=0;
      mapping book=([ ]);
	if(ob->query("skill")) book=ob->query("skill");
	if(ob->query("suit"))
	{
	    suit_level=(int)ob->query("suit_lvl");
	    if(suit_level != 1)
	    {
	       suit_point=random(suit_level*10)+1;
	    }
	    else
	    {
	       suit_point=random(suit_level*2)+1;
	    }	
//	    who->add("suit_point",suit_point);
	    message_vision(HIG"李毅对你点点头,这件套装我收了,< "+HIM+suit_point+HIG+" 兑换点 > 已经给你了。"NOR"\n", who);
	    destruct(ob);
	    return 1;
	}
	if(book["max_skill"])
	{
	    suit_level=(int)ob->query("value")/10000;
	    suit_point=random(suit_level)+1;
//	     who->add("suit_point",suit_point);
	    message_vision(HIG"李毅对你点点头,这本书我收了,< "+HIM+suit_point+HIG+" 兑换点 > 已经给你了。"NOR"\n", who);
	    destruct(ob);
	    return 1;
	}
	    command("say 这不是套装或书籍,我不回收！");
	    return 0;
	
      
}
string ask_form(string name)
{
	object me;
	object ob;

	me = this_player();
	if( me->query("mud_age") > 102000 )
		return "你已经是老手了。";
	if (present(name, this_player()))
	return RANK_D->query_respect(this_player()) + "你身上不是已经有了吗！"; 
	 ob = new("/clone/misc/newbie");
	
	ob->move(me);
	tell_object( me, HIG"兰兰神秘地笑了笑。"NOR"\n" );
	tell_object( me, HIG"兰兰说道：这次我奉命是帮助新手熟悉游戏的。"NOR"\n" );
	command( "say " + "你拿好这份「新手帮助指南」。" );
	return "输入"HIR" read book "NOR + CYN"就可以读指南了。";
}
string ask_start()
{
	object me;
	object ob;

	me = this_player();
if ( me->query("combat_exp", 1) < 10000 ) return "等你稍微有点实战经验再来领取新手奖励吧！";

       if(!me->query("jiangli"))
       {
	ob = new("/clone/misc/sleepbag");
	ob->move(me);     
	ob = new("/clone/money/gold");
	ob->move(me);  
	me->set("jiangli",1);
	write(HIY"\n江湖路难行，送你点必须品。"NOR"\n");
	write(HIG"\n你得到了兰兰的馈赠： <黄金>: 一两   <帐篷>: 一顶，快谢谢她吧 "NOR"\n");
       }
      return HIR+"  一路顺风，谢谢支持[爱若幽兰]"+NOR;
}