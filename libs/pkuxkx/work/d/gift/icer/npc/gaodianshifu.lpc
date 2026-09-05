// gaodianshifu.c 制作月饼的糕点师傅
#include <ansi.h>
inherit NPC;
string ask_fuli();
void create()
{
        set_name("糕点师傅", ({ "gaodian shifu","shifu" }));
        
         set("title",HIY "专业月饼制作" NOR);
        set("long",
                "这是一个专门从事月饼制作的高点师傅，胖乎乎的脸上总是一副和蔼的笑容。你可以问他要免费的福利月饼(ask shifu about 福利月饼)，
                也可以把对诗得来的月饼在他这里重做(chongzou)成味道更丰富的月饼。\n");
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
                "福利月饼" : (: ask_fuli :),
                "重做" : "同一生产日期的两种，每种三块同样名字的月饼可以重做成一个味道更丰富的月饼！比如三块9号普通莲蓉月饼和三块9号普通蛋黄月饼可以重做成一块9号普通莲蓉蛋黄月饼！\n",
        ]) );
        set("chat_chance", 10);
        set("chat_msg", ({
                "糕点师傅说道：你可以打chongzuo让我重做你的月饼，不过必须是对诗得来的，而且得是同一生产日期的两种，每种三块同样名字的月饼！\n",
                "糕点师傅说道：同一生产日期的两种，每种三块同样名字的月饼可以重做成一个味道更丰富的月饼！比如三块9号普通莲蓉月饼和三块9号普通蛋黄月饼可以重做成一块9号普通莲蓉蛋黄月饼！\n",
                "糕点师傅说道：重做月饼的时候必须身上只带同一日期的两种，每种三块同样名字的月饼才行！\n",
                "糕点师傅说道：福利月饼不可重做！\n",
        }) );
        setup();
		carry_object("/d/huashan/npc/obj/baishan")->wear();
}

void init()
{
	add_action("do_chongzuo","chongzuo");
}

string ask_fuli()
{
	int type;
	object me = this_player();
	object yuebing;
	if (me->query_temp("2010zhongqiu/getfuli"))
		return "我不是已经给你一块了么？\n";
	yuebing = new(__DIR__"obj/fuliyuebing");
	type = random(3)+1;
	if (type == 3) type = 4;
	yuebing->set_prop(type,"普通",1);
	me->set_temp("2010zhongqiu/getfuli",1);
	yuebing->move(me);
	message_vision("糕点师傅拍了拍手上的面粉，从身后拿出一块" + yuebing->name() + "给$N。\n",me);
	return "福利月饼只能吃一块，吃了之后就不能吃其他的月饼了哦！\n";
}

int do_chongzuo()
{
	object me = this_player();
	object *ob,*bing,*bing1,*bing2;
	int i,type1,type2,type;
	object newbing;
	
	ob = all_inventory(me);
	bing = ({});
	for (i=0;i<sizeof(ob);i++)
		if (ob[i]->query("id") == "zhongqiu yuebing")
			bing += ({ob[i]});
	if (sizeof(bing) == 0)
		return notify_fail("糕点师傅说道：『你没带可以重做的月饼来，我没有原料啊！只有对诗得来的月饼才可重做。』\n");
	if (sizeof(bing) < 6)
		return notify_fail("糕点师傅数了数你的月饼说道：『你的月饼不够六块，原料不够，没法重做啊！只有对诗得来的月饼才可重做！』\n");
	if (sizeof(bing) > 6)
		return notify_fail("糕点师傅数了数你的月饼说道：『你的月饼多于六块，我怎么知道你要重做哪六块？』\n");
	bing1 = ({});
	bing2 = ({});
	bing1 += ({bing[0]});
	for (i=1;i<6;i++)
		if (bing[i]->query("name") == bing[0]->query("name"))
			bing1 += ({bing[i]});
		else bing2 += ({bing[i]});
	
	if (sizeof(bing1) != 3)
		return notify_fail("糕点师傅仔细看了看你的月饼，说道：『你的月饼不满足重做的要求，必须是同一日期的两种六块月饼，其中每种（莲蓉、蛋黄、蜂蜜、莲蓉蜂蜜等等）各三块。』\n");
	if (bing2[0]->name() != bing2[1]->name() || bing2[1]->name()!= bing2[2]->name())
		return notify_fail("糕点师傅仔细看了看你的月饼，说道：『你的月饼不满足重做的要求，必须是同一日期的两种六块月饼，其中每种（莲蓉、蛋黄、蜂蜜、莲蓉蜂蜜等等）各三块。』\n");
	if (bing1[0]->name() == bing2[0]->name())
		return notify_fail("糕点师傅仔细看了看你的月饼，说道：『你的月饼不满足重做的要求，必须是同一日期的两种六块月饼，其中每种（莲蓉、蛋黄、蜂蜜、莲蓉蜂蜜等等）各三块。』\n");
		
	if (bing1[0]->query("date") != bing2[0]->query("date"))
		return notify_fail("糕点师傅闻了闻你的月饼，说道：『你的这两种月饼不是一天出厂的，重做之后会变味的。』\n");
	if (bing1[0]->query("level") != bing2[0]->query("level"))
		return notify_fail("糕点师傅闻了闻你的月饼，说道：『你的这两种月饼不是一个等级的，别重做了，糟蹋了好月饼。』\n");
	
	type1 = bing1[0]->query("type");
	type2 = bing2[0]->query("type");
	if (type1 == 7||type2 == 7)
		return notify_fail("糕点师傅疑惑地说道：『这其中一种已经是三种味道合一的了，没法再多了。』\n");
		
	type = 0;
	if (type1%2==1 || type2%2==1)
		type = 1;
	type1 = type1 /2;
	type2 = type2 /2;
	if (type1%2==1 || type2%2==1)
		type = type + 2;
	type1 = type1 /2;
	type2 = type2 /2;
	if (type1%2==1 || type2%2==1)
		type = type + 4;
	
	
		if (this_object()->is_busy())
			return notify_fail("糕点师傅说道：『我正忙着，您稍等。』\n");
		this_object()->start_busy(5);
		write("糕点师傅仔细看过你的月饼之后，说道：『您的月饼完全满足要求，我这就给您重做！』\n");
		newbing = new(__DIR__"obj/yuebing");
		newbing->set("savetime","combined" + time());
		newbing->set_prop(type,bing[0]->query("level"),bing[0]->query("date"));
		newbing->move(me);
		write("糕点师傅一通忙活，把六块月饼重做成了一块" + newbing->name() + "递给了你。\n");
		log_file("2010hongbao",me->query("id") + "重做了一块" + newbing->name() + "," + newbing->query("yb_desc") + "。\n");
		destruct(bing[5]);		
		destruct(bing[4]);		
		destruct(bing[3]);		
		destruct(bing[2]);		
		destruct(bing[1]);		
		destruct(bing[0]);		

	return 1;
}