// xingge.c 星哥
// By Lgg,1998.10
// modified by wind

#include <ansi.h>
inherit BHNPC;
int peiqian(object me);
int do_ya(string arg);

//全程变量
int thecash;

void create()
{
	set_name("星哥", ({ "xing ge", "xing" }));
	set("gender", "男性");
	set("long",
		"这是号称‘赌圣’的周星弛－－星哥。\n"
	);
	set("age", 32);
	set("title",HIW"亚洲赌王"NOR);
	set("nickname",CYN"赌圣"NOR);

	set("immortal",1);

	set("inquiry", ([
		"刘德华"   : "哦，你是问华崽啊，他是我的师兄，人称‘赌侠’。\n",  
		"发崽" : "我师父的名字也是你乱喊得的？\n",
	]) );	

	set("book_count",1);

	setup();

	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_ya","ya");
}

int accept_object(object who, object ob)
{
//object obj;
	object me=this_player();

	if (query("book_count")) {
    	if (ob->query("money_id")) {
		if (ob->query_temp("tmark/宝")) {
			message_vision(HIG"星哥诧异地看着$N说：你已经下过注了呀！\n"NOR,who);
		}
	if (ob->value()<100) {
			message_vision(HIR"星哥不屑一顾地看着$N，说道：要下注至少一两银子！\n"NOR,who);
			return 0;
			}
	if (ob->value()>2000000) {
			message_vision(HIR"星哥摇了摇头，对$N说道：这里不欢迎孤注一掷，最多下注200两黄金！\n"NOR,who);
			return 0;
         }
		add("book_count",-1);
		thecash = ob->value();
		who->set_temp("tmark/宝",1);

		message_vision(HIY"星哥吆喝道：下注完成，现在押大押小就看$N一句话了。\n"NOR,who);
		message_vision(HIY"请type ya da(xiao)完成这次押注。\n"NOR,who);

	        remove_call_out("destroying");
        	call_out("destroying", 0, me, ob);
		return 1;
	}
	} // if (query("book_count"))
	else {
		message("vision",HIY"已经有人在星哥对赌了，看来$N得等下波儿了。\n"NOR,who);
		return 0;
	}
}

int do_ya(string arg)
{
	object me=this_player();
	int l1,l2,l3,sum;

	if(!arg || (arg!="da" && arg!="xiao"))
		return notify_fail("你到底要押什么？\n");

	if (!me->query_temp("tmark/宝")) {
		message_vision(MAG"星哥不耐烦地推了$N一把：去去去，钱还没给就想押大小！\n"NOR,me);
		return 1;
	}

	l1=1+random(6);
	l2=1+random(6);
	l3=1+random(6);
	sum=l1+l2+l3;

	message("vision",HIG"只见三粒色子不停转动，终于停了下来，是"+l1+" "+l2+" "+l3+"。\n"NOR,me);
	if (l1==l2 && l2==l3) {
		message_vision(HIG"星哥高声叫道：开了！"+l1+" "+l2+" "+l3+" "+"，全一色通杀！\n"NOR,me);
	}
	else {
	if(sum>10)
		message_vision(HIG"星哥高声叫道：开了！"+l1+" "+l2+" "+l3+" "+"，"+sum+"点大，吃小赔大！\n"NOR,me);
	else
		message_vision(HIG"星哥高声叫道：开了！"+l1+" "+l2+" "+l3+" "+"，"+sum+"点小，吃大赔小！\n"NOR,me);
	if(sum>10) {
		if(arg=="da") {
			message("vision",HIW"星哥一副不敢相信的表情，噫，你怎么会押中的？\n"NOR,me);
			peiqian(me);
		}
		else {
			message("vision",HIR"星哥贼贼一笑：你又输了，不好意思。\n"NOR,me);
		}
	}
	else {
		if(arg=="xiao") {
			message("vision",HIW"星哥一副不敢相信的表情，噫，你怎么会押中的？\n"NOR,me);
			peiqian(me);
		}
		else {
			message("vision",HIR"星哥贼贼一笑：你又输了，不好意思。\n"NOR,me);
		}
	}
	} // end of else

	me->set_temp("tmark/宝",0);
	set("book_count",1);
	return 1;
}

int peiqian(object me)
{
	object ob,ob1;

	if(thecash<10000) {
	ob = new("/clone/money/silver");
	ob->set_amount(thecash/100*2);
	ob->move(me);	
	}
	else {
	ob = new("/clone/money/gold");
	ob->set_amount(thecash/10000*2);
	ob->move(me);
	if((thecash % 10000)!=0) {
		ob1 = new("/clone/money/silver");
		ob1->set_amount((thecash-((thecash/10000*10000)))/100*2);
		ob1->move(me);
	}
	}
	me->set_temp("tmark/宝",0);
	return 1;	
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

