#include <ansi.h>;
inherit NPC;
string part1= HIG"\n请用 " + HIR + "change < xxx >" + HIG + " 来兑换您所需的奖励！\n"NOR;
string part2= HIC"＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊　　\n" +
	"  舍利子(slz)		20	点贡献度	\n" +
	"  菩提子(ptz)		25	点贡献度	\n" +
	"  小袋QQ糖(qqtang)	80	点贡献度	\n" +
	"  大袋QQ糖(qqtang2)	140	点贡献度	\n" +
	"  一点先天容貌(rongmao)	300	点贡献度	\n" +
	"  一点先天福缘(fuyuan)	350	点贡献度	\n" +
	"  一点先天臂力(bili)	800	点贡献度	\n" +
	"  一点先天悟性(wuxing)	800	点贡献度	\n" +
	"  一点先天根骨(gengu)	1000	点贡献度	\n" +
        "  一点先天身法(shenfa) 1000    点贡献度        \n" +
        HIR"  其中天赋只能兑换一次！        \n"HIC +
	"  九阴权限(jiuyin)	1800	点贡献度	\n" +
	"  头衔(title)	change title <新头衔>	\n" +
	"  第一次 500 点贡献度，以后每次翻倍，当换取头衔后如发生	\n" +
	"  改变，可在特使这里用 retitle 来恢复（每次5点贡献度）！	\n" +
	"＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊　　\n"NOR;
string part3= HIG"感谢您长期以来对"HIR"★侠客梦★"HIG"的支持！\n"NOR;
string temp = part1 + part2 + part3;
string ask_change()
{
	return temp;
}
string ansi_convert(string str)
{
	str = replace_string(str, "$BLK$", BLK);
	str = replace_string(str, "$RED$", RED);
	str = replace_string(str, "$GRN$", GRN);
	str = replace_string(str, "$YEL$", YEL);
	str = replace_string(str, "$BLU$", BLU);
	str = replace_string(str, "$MAG$", MAG);
	str = replace_string(str, "$CYN$", CYN);
	str = replace_string(str, "$WHT$", WHT);
	str = replace_string(str, "$HIR$", HIR);
	str = replace_string(str, "$HIG$", HIG);
	str = replace_string(str, "$HIY$", HIY);
	str = replace_string(str, "$HIB$", HIB);
	str = replace_string(str, "$HIM$", HIM);
	str = replace_string(str, "$HIC$", HIC);
	str = replace_string(str, "$HIW$", HIW);
	str = replace_string(str, "$NOR$", NOR);
//	str = replace_string(str, "$BLINK$", BLINK);
        return str+NOR;
}
int set_title(int gxdt)
{
	int sum;
	sum=50000;
	for(int i=1;i<=gxdt;i++)
	{
		sum*=2;
	}
	return sum;
}
void init()
{
	add_action("do_change", "change");
	if(this_player()->query("retitle")==1)
		add_action("do_retitle","retitle");
}
void create()
{
	set_name(HIR"特使" NOR,({"teshi"}));
	set("title",HIG"侠客梦二号"NOR);
	set("gender","男性");
	set("age",15);
	set("attitude", "friendly");
	set("long",HIR"他是梦巫师为了奖励对梦有贡献的玩家而提拔的二号特使，您可以用（ask teshi about change）来得知具体兑换细节！\n"NOR);
	set("shen_type", 2);
	set("combat_exp", 3000000);
	set("attitude", "friendly");
	set("inquiry", ([
		"change" : (: ask_change :),
		"兑换" : (: ask_change :),
		"贡献度" : (: ask_change :),
	]) );
	set("max_qi", 9500);
	set("max_jing", 5000);
	set("max_neili",7500);
	set("neili",7500);
	set("jiali",100);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set_skill("dodge", 300);
	set_skill("force", 300);
	set_skill("literate",300);
	set_skill("liuxing-bu",300);
	set_skill("parry", 300);
	set_skill("strike",300);
	set_skill("sword",300);
	set_skill("taixuan-gong",300);
	set_skill("wuyu-zhangfa", 300);
	set_skill("wugou-jianfa", 300);
	set_skill("zuoyou-hubo",300);

	map_skill("dodge","liuxing-bu");
	map_skill("force","taixuan-gong");
	map_skill("parry","wugou-jianfa");
	map_skill("strike","wuyu-zhangfa");
	map_skill("sword","wugou-jianfa");      

	prepare_skill("strike", "wuyu-zhangfa");
	setup();
	carry_object("/clone/armor/cloth")->wear();
	carry_object("/clone/weapon/gangjian")->wield();
}
int accept_kill(object obj)
{
	int temp;
	command("say 啊！" + obj->name() + "你为什么要杀我呀，小心我告诉你妈妈！");
	if (wizardp(obj))
	{
		temp=obj->query("env/immortal");
		obj->set("env/immortal",0);
		obj->die();
		obj->set("env/immortal",temp);
	}
	else
	{
		obj->die();
	}
}
int temp2()
{
	write(HIR + "你的贡献度不够！\n" + part2 );
	return 1;
}
int temp3()
{
        write(HIR + "你已经兑换过这项属性了！\n"NOR );
	return 1;
}
int do_retitle()
{
	object me=this_player();
	if( me->query("menggxd") < 500 )	return temp2();
	else
	{
		me->add("menggxd",-500);
		me->set("title",me->query("title_bak"));
		write(HIG"你成功的恢复了头衔" + me->query("title_bak") + HIG"，恭喜你，继续努力吧！\n"NOR);
		return 1;
	}
}
int do_change(string arg)
{
	object me=this_player(),obj;
	string str;
	if( !arg )
	 {
		write(temp);
		return 1;
	}
	else if( arg == "舍利子" || arg == "slz" )
	{
		if( me->query("menggxd") < 2000 )
			return temp2();
		else
		{
			me->add("menggxd",-2000);
			me->add("gxdslz",1);
			obj=new(__DIR__"obj/shelizi");
			obj->move(me);
			obj->set("value", 0);
			write(HIG"你成功的兑换了一颗"+obj->name()+HIG"！继续努力吧！\n"NOR);
			return 1;
		} 
	}
	else if( arg == "菩提子" || arg == "ptz" )
	{
		if( me->query("menggxd") < 2500 )
			return temp2();
		else
		{
			me->add("menggxd",-2500);
			me->add("gxdptz",1);
			obj=new(__DIR__"obj/putizi");
			obj->move(me);
			obj->set("value",0);
			write(HIG "你成功的兑换了一颗"+obj->name()+HIG"！继续努力吧！\n"NOR);
			return 1;
		}
	}
	else if( arg == "小袋QQ糖" || arg == "qqtang" )
	{
		if( me->query("menggxd") < 8000 )
			return temp2();
		else
		{
			me->add("menggxd",-8000);
			me->add("gxdqq",1);
			obj=new(__DIR__"obj/qqtang");
			obj->move(me);
			obj->set("value",0);
			write(HIG "你成功的兑换了一小袋"+obj->name()+HIG"！继续努力吧！\n"NOR);
			return 1;
		}
	}
	else if( arg == "大袋QQ糖" || arg == "qqtang2" )
	{
		if( me->query("menggxd") < 14000 )
			return temp2();
		else
		{
			me->add("menggxd",-14000);
			me->add("gxdqq2",1);
			obj=new(__DIR__"obj/qqtang2");
			obj->move(me);
			obj->set("value",0);
			write(HIG "你成功的兑换了一大袋"+obj->name()+HIG"！继续努力吧！\n"NOR);
			return 1;
		}
	}
	else if( arg == "容貌" || arg == "rongmao" )
	{
		if( me->query("gxdper") !=0 )
			return temp3();
		else if( me->query("menggxd") < 30000 )
			return temp2();
		else if( me->query("per") >= 30 )
		{
			me->set("per",30);
			write(HIW"你已经够美了，省下贡献度去换别的吧！\n"NOR);
			return 1;
		}
		else
		{
			me->add("menggxd",-30000);
			me->add("gxdper",1);
			me->add("per",1);
			write(HIG "你成功的兑换了一点先天容貌！继续努力吧！\n"NOR);
			return 1;
		}
	}
	else if( arg == "福缘" || arg == "fuyuan" )
	{
		if( me->query("gxdkar") !=0 )
			return temp3();
		else if( me->query("menggxd") < 35000 )
			return temp2();
		else if( me->query("kar") >= 30 )
		{
			me->set("kar",30);
			write(HIW"你已经够有福气的了，省下贡献度去换别的吧！\n"NOR);
			return 1;
		}
		else
		{
			me->add("menggxd",-35000);
			me->add("gxdkar",1);
			me->add("kar",1);
			write(HIG "你成功的兑换了一点先天福缘！继续努力吧！\n"NOR);
			return 1;
		}
	}
	else if( arg == "臂力" || arg == "bili" )
	{
		if( me->query("gxdstr") !=0 )
			return temp3();
		else if( me->query("menggxd") < 80000 )
			return temp2();
		else
		{
			me->add("menggxd",-80000);
			me->add("gxdstr",1);
			me->add("str",1);
			write(HIG "你成功的兑换了一点先天臂力！继续努力吧！\n"NOR);
			return 1;
		}
	}
	else if( arg == "悟性" || arg == "wuxing" )
	{
		if( me->query("gxdint") !=0 )
			return temp3();
		else if( me->query("menggxd") < 80000 )
			return temp2();
		else
		{
			me->add("menggxd",-80000);
			me->add("gxdint",1);
			me->add("int",1);
			write(HIG "你成功的兑换了一点先天悟性！继续努力吧！\n"NOR);
			return 1;
		}
	}
	else if( arg == "根骨" || arg == "gengu" )
	{
		if( me->query("gxdcon") !=0 )
			return temp3();
		else if( me->query("menggxd") < 100000 )
			return temp2();
		else
		{
			me->add("menggxd",-100000);
			me->add("gxdcon",1);
			me->add("con",1);
			write(HIG "你成功的兑换了一点先天根骨！继续努力吧！\n"NOR);
			return 1;
		}
	}
	else if( arg == "身法" || arg == "shenfa" )
	{
		if( me->query("gxddex") !=0 )
			return temp3();
		else if( me->query("menggxd") < 100000 )
			return temp2();
		else
		{
			me->add("menggxd",-100000);
			me->add("gxddex",1);
			me->add("dex",1);
			write(HIG "你成功的兑换了一点先天身法！继续努力吧！\n"NOR);
			return 1;
		}
	}
	else if( arg == "九阴" || arg == "9yin" || arg == "jiuyin" || arg == "九阴权限" )
	{
		if( me->query("menggxd") < 180000 )
			return temp2();
		else if( me->query("9yin") == "granted" )
		{
			write(HIW"你已经拥有学习九阴真经的权限了，省下贡献度去换别的吧！\n"NOR);
			return 1;
		}
		else
		{
			me->add("menggxd",-180000);
			me->add("gxd9yin",1);
			me->set("9yin","granted");
			write(HIG "你成功的兑换到了学习九阴真经的权限！继续努力吧！\n"NOR);
			return 1;
		}
	}
	else if( sscanf(arg, "title %s", str)==1 || sscanf(arg, "头衔 %s", str)==1 )
	{
		if( me->query("menggxd") < set_title(me->query("gxdtitle") ))
			return temp2();
		else
		{
			str= ansi_convert(str);
			me->add("menggxd", -set_title(me->query("gxdtitle")));
			me->add("gxdtitle",1);
			me->set("retitle",1);
			me->set("title",str);
			me->set("title_bak",str);
			write(HIG"你成功的换取了头衔" + str + HIG"，恭喜你，继续努力吧！\n"NOR);
			return 1;
		}
	}
	else if( arg == "title" || arg == "头衔" )	return temp2();
	else
	{
		write(temp);
		return 1;
	}
}
