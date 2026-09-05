// huangniu.c 倒月饼的黄牛党
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("月饼贩子", ({ "yuebing fanzi","fanzi" }));
        
         set("title",HIY "专业月饼兑换" NOR);
        set("long",
                "这是一个专门从事月饼兑换生意的月饼贩子，长得贼眉鼠眼。你可以从他这里兑换(duihuan)高等级的月饼。\n");
        set("gender", "男性");
        set("age", 26);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 18);
        set("int", 28);
        set("con", 20);
        set("dex", 24);
        set("per", 20);
        set("max_qi", 400);
        set("max_jing", 300);
        set("neili", 400);
        set("max_neili", 400);
        set("jiali", 10);
    set("combat_exp", 5000);
	set("inquiry", ([
                "月饼" : "你有月饼要兑换吗？可以打duihuan试试！\n",
                "月饼兑换"   : "三块同样名字的月饼换一块更高等级的月饼！比如三块9号普通莲蓉月饼换一块9号精选莲蓉月饼！\n",
                "兑换" : "三块同样名字的月饼换一块更高等级的月饼！比如三块9号普通莲蓉月饼换一块9号精选莲蓉月饼！\n",
        ]) );
        set("chat_chance", 10);
        set("chat_msg", ({
                "月饼贩子说道：月饼兑换喽～～\n",
                "月饼贩子说道：你可以打duihuan跟我兑换月饼！\n",
                "月饼贩子说道：三块同样名字的月饼换一块更高等级的月饼！比如三块9号普通莲蓉月饼换一块9号精选莲蓉月饼！\n",
                "月饼贩子说道：兑换月饼的时候必须身上只带三块同样名字的月饼才行！\n",
                "月饼贩子说道：福利月饼不可兑换！\n",
        }) );
        setup();
		carry_object("/d/huashan/npc/obj/huishan")->wear();
}

void init()
{
	add_action("do_duihuan","duihuan");
}

int do_duihuan()
{
	object me = this_player();
	object *ob,*bing;
	int i;
	object newbing;
	
	ob = all_inventory(me);
	bing = ({});
	for (i=0;i<sizeof(ob);i++)
		if (ob[i]->query("id") == "zhongqiu yuebing")
			bing += ({ob[i]});
	if (sizeof(bing) == 0)
		return notify_fail("月饼贩子白了你一眼：『你又没带可以兑换的月饼，换什么呀！只有对诗得来的月饼才可兑换！』\n");
	if (sizeof(bing) < 3)
		return notify_fail("月饼贩子看了一眼你的月饼说道：『你的月饼不够三块，不能兑换！只有对诗得来的月饼才可兑换！』\n");
	if (sizeof(bing) > 3)
		return notify_fail("月饼贩子看了一眼你的月饼说道：『你的月饼多于三块，我怎么知道你要兑换哪三块？』\n");
	if (bing[0]->name() == bing[1]->name() && bing[1]->name()== bing[2]->name())
	{
		if (this_object()->is_busy())
			return notify_fail("月饼贩子说道：『我正忙着，您稍等。』\n");
		this_object()->start_busy(5);
		write("月饼贩子一看你的月饼，大喜道：『生意上门了！』\n");
		newbing = new(__DIR__"obj/yuebing");
		newbing->set("savetime","combined" + time());
		if (bing[0]->query("level") == "普通")
			newbing->set_prop(bing[0]->query("type"),"精选",bing[0]->query("date"));
		if (bing[0]->query("level") == "精选")
			newbing->set_prop(bing[0]->query("type"),"极品",bing[0]->query("date"));
		if (bing[0]->query("level") == "极品")
		{
			write("月饼贩子再仔细一看，大失所望道：『您这已经是极品月饼了，我可没有更高等级的月饼跟您兑换了。』\n");
			return 1;
		}
		newbing->move(me);
		write("月饼贩子一把抓起你的三块" + bing[0]->name() + "，然后偷偷塞给你一块" + newbing->name() + "。\n");
		log_file("2010hongbao",me->query("id") + "兑换了一块" + newbing->name() + "," + newbing->query("yb_desc") + "。\n");
		destruct(bing[2]);		
		destruct(bing[1]);		
		destruct(bing[0]);		
	}
	else
		return notify_fail("月饼贩子对你说道：『你这三块月饼的名字不一样，没法兑换！只有对诗得来的月饼才可兑换！』\n");
	return 1;
}