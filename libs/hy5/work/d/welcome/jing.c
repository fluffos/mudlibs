#include <ansi.h>
inherit NPC;

string ask_liwu();
string ask_liwu1();
string ask_liwu2();
string ask_liwu3();
string ask_liwu4();
string ask_liwu5();
string ask_liwu6();
string ask_liwu7();
string ask_liwu8();
string ask_liwu9();
string ask_liwu10();
string ask_liwu11();
string ask_liwu12();
string ask_liwu13();
string ask_liwu14();
string ask_liwu15();
string ask_liwu16();
#include "/quest/givegift.c"
void create()
{
        set_name("老村长", ({ "lao cunzhang","lao" }) );
  set("title", HIM "导师「人见人爱」" NOR);
	set("gender", "男性" );
	set_temp("no_kill", 1);
	set("age", 76);
	set("per", 100);
        set("long", "这是一个瘦小的老者，看起来有一百多岁，他是北戏子北丑和
南贤的师傅，也是这个新手村的村长，如果你有什么问题不妨
找他帮忙，输入指令 ask lao about here 可得到帮助信息。\n");
	set("shen_type",1);
	set("combat_exp", 2000000);
	set("attitude", "peaceful");
        set("apply/attack", 350);
	set("apply/defense", 350);

	set_skill("unarmed", 1500);
	set_skill("blade", 1500);
	set_skill("parry", 1500);
	set_skill("dodge", 1500);
	set("inquiry" , ([
             "here" : (: ask_liwu :),
             "帮助" : (: ask_liwu :),
             "out" : (: ask_liwu14 :),
             "出村" : (: ask_liwu14 :),
"任务" : (: ask_liwu15 :),
"job" : (: ask_liwu15 :),
"ok" : (: ask_liwu16 :),
"结束" : (: ask_liwu16 :),
	     "1" : (: ask_liwu1 :),
	     "2" : (: ask_liwu2 :),
	     "3" : (: ask_liwu3 :),
	     "4" : (: ask_liwu4 :),
	     "5" : (: ask_liwu5 :),
	     "6" : (: ask_liwu6 :),
	     "7" : (: ask_liwu7 :),
	     "8" : (: ask_liwu8 :),
	     "9" : (: ask_liwu9 :),
	     "10" : (: ask_liwu10 :),
	     "11" : (: ask_liwu11 :),
	     "12" : (: ask_liwu12 :),
	     "13" : (: ask_liwu13 :),
	]));

	setup();
	carry_object("clone/cloth/cloth")->wear();
}

void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() ) {

			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		
	}


}


void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

			say( HIG"老村长对你说道：这位" + RANK_D->query_respect(ob)+ "，如果需要帮助请输入指令 "+HIR+"ask lao about here\n"NOR);


}


string ask_liwu()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;

me->add_temp("nbjob1",1);
if (me->query_temp("nbjob1",1)>2) me->set_temp("nbjob1",2);
msg=HIY"\n编号         信    息
 1        什么是文字MUD游戏
 2        简单介绍一下这个游戏的玩法
 3        我在游戏里能做些什么
 4        我自己是谁
 5        我在哪里
 6        如何移动
 7        如何跟其他朋友交流
 8        我可以扮演哪些角色
 9        如何生存
10        如何练功和使用兵器
11        如何战斗
12        如何得到更多帮助
13        如何离开这里到外面的世界去
要了解的信息可以输入指令 "HIR"ask lao about <编号>"NOR"
如要了解 <如何移动> 的信息，则输入 "HIR"ask lao about 6"NOR"
如果你是位新玩家，你可以"HIR"ask lao about job"NOR"，开始你的新手教程。
如果你是位老玩家，你也可以直接"HIR"ask lao about 出村"NOR"，去闯荡江湖，当然这样的话你可能会错失了某种机缘。"NOR;
  return msg;
}

string ask_liwu1()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;

me->start_more( read_file(__DIR__"1") );
  return "海洋IV 欢迎您";
}

string ask_liwu2()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;

me->start_more( read_file(__DIR__"2") );
  return "海洋IV 欢迎您";
}
string ask_liwu3()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;

me->start_more( read_file(__DIR__"3") );
  return "海洋IV 欢迎您";
}
string ask_liwu4()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;

me->start_more( read_file(__DIR__"4") );
  return "海洋IV 欢迎您";
}
string ask_liwu5()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;

me->start_more( read_file(__DIR__"5") );
  return "海洋IV 欢迎您";
}
string ask_liwu6()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;

me->start_more( read_file(__DIR__"6") );
  return "海洋IV 欢迎您";
}
string ask_liwu7()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;

me->start_more( read_file(__DIR__"7") );
  return "海洋IV 欢迎您";
}
string ask_liwu8()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;

me->start_more( read_file(__DIR__"8") );
  return "海洋IV 欢迎您";
}
string ask_liwu9()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;

me->start_more( read_file(__DIR__"9") );
  return "海洋IV 欢迎您";
}
string ask_liwu10()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;

me->start_more( read_file(__DIR__"10") );
  return "海洋IV 欢迎您";
}
string ask_liwu11()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;

me->start_more( read_file(__DIR__"11") );
  return "海洋IV 欢迎您";
}
string ask_liwu12()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;

me->start_more( read_file(__DIR__"12") );
  return "海洋IV 欢迎您";
}

string ask_liwu13()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;


msg=HIY"等你在这里历练合格（输入指令 "HIR"ask lao about 出村"HIY"）后，\n可到『古村』村口去找花伯（输入指令 "HIR"ask hua about 出村"NOR"）。"NOR;



  return msg;

}

string ask_liwu14()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili;
  int exp,pot;

if (me->query("nbjob",1)==19)
{
  exp=18888;
  addnl(me,"exp",exp);	
me->set("nbjob",20);
}
me->set_temp("isout",1);

if (me->query("nbjob",1)!=20 || !me->query("nbjob",1))
{
me->set_temp("isout",1);
  return "你可以出去闯荡江湖了！但你没有完成新手任务(ask lao about job) 新手奖励将会损失。请注意！去西边(west)找花伯吧! ";
}

  return "不错，不错，看来你已经可以出去闯荡江湖了！去西边(west)找花伯吧!";
}             


string ask_liwu15()
{
  string msg;
  object ob1;
  object me=this_player();
  int exp_bound,qn_bound,neili;
if ((int)me->query("combat_exp",1)==0) me->set("nbjob",0);

msg="看来你已经可以出去闯荡江湖了！ ask lao about 出村";
if (!me->query("nbjob"))
msg=HIY"老村长说道：\n第一个任务
  查看新手帮助 请输入
  ask lao about here 
  help newbie
  完成后 ask lao about ok"NOR;

if (me->query("nbjob",1)==1)
{
msg=HIY"老村长说道：\n第二个任务
  我教了你一些读书写字和剑法，查看你的状态 请输入
  hp,score,skills,verify feixian-sword
  完成后 ask lao about ok"NOR;
if (!me->query_skill("literate"))
{
me->set_skill("literate",10);
}
if (!me->query_skill("feixian-sword"))
{
me->set_skill("feixian-sword",5);
}
}


if (me->query("nbjob",1)==2)
msg=HIY"老村长说道：\n第三个任务
  走路到练武场休息室 请输入
  e,e,s,sleep
  完成后 ask lao about ok"NOR;

if (me->query("nbjob",1)==3)
msg=HIY"老村长说道：\n第四个任务
  去要馒头和水。然后试着吃了它们。请输入
  east,north,yao
  如果需要吃它们，请用eat mantou,drink water
  完成后 ask lao about ok"NOR;
  
if (me->query("nbjob",1)==4)
msg=HIY"老村长说道：\n第五个任务
  拜师学武功 请找到武术教练 武伯(Wu bo)
  查看师傅技能请使用 skills 师傅ID skills wu bo 
  然后bai wu bo 
  完成后 ask lao about ok "NOR;
  
if (me->query("nbjob",1)==5)
msg=HIY"老村长说道：\n第六个任务
  学习武伯的10级基本剑法(sword)和10级天外飞仙（feixian-sword）并使用(enable sword feixian-sword)
  请找到武术教练 武伯(Wu bo) 
  然后用learn|xue <某人> <技能> <次数>
  精力不够学习吗 可以再s处睡觉(sleep) 
  已经学习特殊内功特殊内功 请（jifa force 特殊内功） 并使用 （yun regenerate） 帮助恢复精力
  完成后 ask lao about ok"NOR;
  
if (me->query("nbjob",1)==6)
msg=HIY"老村长说道：\n第七个任务
  去找一把剑。并装备 (wield sword)
  可以到杂货铺去买(buy)，或去武器库找一把(qu)
  小提示：在武伯的 n 方向有武器库  
  世界之树 e s 方向的杂货铺可以购买(list 查看)
  完成后 ask lao about ok"NOR;

if (me->query("nbjob",1)==7)
msg=HIY"老村长说道：\n第八个任务
  用绝招 天外飞仙 杀一支野兔
  找到野兔 然后kill 
  使用绝招perform feixian
  使用绝招需要内功(force) 和内力，请学基本内功和一门内功，打坐(dazuo) 获得5点内力。
  小提示 武伯处可以学习基本内功(force)和特殊内功(jingyiforce) 学习到10级(jifa force 特殊内功) 
  用当前气(hp 查看) 持续打坐到5点最大内力(dazuo 当前气)
  完成后 ask lao about ok"NOR;

if (me->query("nbjob",1)==8)
msg=HIY"老村长说道：\n第九个任务 
  完成一次洗盘子任务
  找到本村的客店 查看地图请使用map指令 使用set showmap 1 可以看到当前地图
  提示:e,e,e,n,ask xiao er about job 然后west,ask guan shi about panzi
  east,north,xi zangpanzi多次 看到提示后,south,give panzi to xiao er
  完成后 ask lao about ok"NOR;            
   

if (me->query("nbjob",1)==9)
msg=HIY"老村长说道：\n第十个任务 
  武伯教了你不少武功，你找钱伯(Qian bo) 买只烧鸡(Meat) 送他（give meat to wu bo)吧。
  找到本村的杂货铺 查看地图请使用map指令 使用set showmap 1 可以看到当前地图
  提示:buy meat 然后give meat to wu bo
  完成后 ask lao about ok"NOR;       

if (me->query("nbjob",1)==10)
{
msg=HIY"老村长说道：\n第十一个任务 
  乱坟岗那有个原始森林 我指定你两手武功，你去打猎一下，搞点战利品吧。
  查看地图请使用map指令 使用set showmap 1 可以看到当前地图
  那边有危险，如果发生危险，或迷路了，请用recall命令回到出生地。
  完成后 ask lao about ok"NOR;  
if (me->query("max_qi",1)< 800) me->set("max_qi",800);
if (me->query("eff_qi",1)< 800) me->set("eff_qi",800);
if (me->query("qi",1)< 800) me->set("qi",800);
if (me->query("max_neili",1)< 200) me->set("max_neili",200);
if (me->query("neili",1)< 200) me->set("neili",200);
if (me->query_skill("force",1)< 100) me->set_skill("force",100);
if (me->query_skill("dodge",1)< 100) me->set_skill("dodge",100);
if (me->query_skill("unarmed",1)< 100) me->set_skill("unarmed",100);
if (me->query_skill("parry",1)< 100) me->set_skill("parry",100);
if (me->query_skill("sword",1)< 100) me->set_skill("sword",100);
if (me->query_skill("feixian-sword",1)< 100) me->set_skill("feixian-sword",100);
if (me->query_skill("jingyiforce",1)< 100) me->set_skill("jingyiforce",100);
if (me->query_skill("softsword",1)< 100) me->set_skill("softsword",100);
}
if (me->query("nbjob",1)==11)
msg=HIY"老村长说道：\n第十二个任务 
  检查你打猎的成果吧，把打猎得到的成果，去卖了换钱吧。
  查看地图请使用map指令 使用set showmap 1 可以看到当前地图
  找到当铺 试试sell <物品id>
  完成后 ask lao about ok"NOR;  

if (me->query("nbjob",1)==12)
{
msg=HIY"老村长说道：\n第十三个任务 
  刚才给你了一本三字经 并教了你点读书写字，你试着把它存到当铺内室中去吧。
  查看地图请使用map指令 使用set showmap 1 可以看到当前地图
  找到当铺 试试pawn <物品id>
  完成后 ask lao about ok"NOR;  
if (me->query_skill("literate",1)<=80)
{
me->set_skill("literate",80);
}

}
if (me->query("nbjob",1)==13)
msg=HIY"老村长说道：\n第十四个任务 
  你现在身上应该有点钱了吧 你试着把它存到钱庄中去吧。
  查看地图请使用map指令 使用set showmap 1 可以看到当前地图
  找到钱庄 试试deposit <钱id>
  完成后 ask lao about ok"NOR;  

if (me->query("nbjob",1)==14)
{
msg=HIY"老村长说道：\n第十五个任务 
  你现在应该有点基本内功了吧，记得enable force <特殊内功>。
  如果受了伤，你试试exert cureheal或exert recover吧。
  详细内容查询 help force
  完成后 ask lao about ok"NOR;  
me->set("qi",me->query("max_qi",1)/2);
}
if (me->query("nbjob",1)==15)
msg=HIY"老村长说道：\n第十六个任务 
  江湖中，朋友互相帮助很重要。
  你试试用chat <内容> 来说一句话。（如:chat 我是新人 请各位老玩家多多帮助）
  此功能可以和在线的玩家语言互动或寻求帮助
  完成后 ask lao about ok"NOR;  

if (me->query("nbjob",1)==16)
msg=HIY"老村长说道：\n第十七个任务 
  江湖中，指令是可以简化的。
  你试试用alias k kill $*。把kill <id>简化为k <id>
  alias 也可以查询 你设定了多少简介命令
  小提示: 你忘了前面武功特殊招式的的指令了吗 同样可以设定
  查询武功情况命令verify|chkskill <武功id>
        如 (alias vv verify $*)
  完成后 ask lao about ok"NOR;  

if (me->query("nbjob",1)==17)
msg=HIY"老村长说道：\n第十八个任务 
  江湖中，对新手来说新手背包是很重要的。
  你试试用look newbie beg 然后xiuxi newbie beg
  完成后 ask lao about ok
  小提示:按 i 可以看自己身上的物品id 可以查询自己身上的物 品简称 
  同样xiuxi newbie beg 也可以变成 xiuxi beg
  完成后 ask lao about ok"NOR;  
  
if (me->query("nbjob",1)==18)
{
msg=HIY"老村长说道：\n第十九个任务 
  江湖中，特殊装备对新手来说很重要 我送你一件新手披风和新手之剑
  你试试用bangding 1 newbie armor 然后bweapon 1
  你试试用bangding 2 newbie sword 然后bweapon 2
  相关资料help dazao,help bangding,help bweapon
  试试wield,unwield,wear,remove指令吧。
  完成后 ask lao about ok
  小提示: 如果命令记不住 别忘了设定 alias 简化命令 方便  以后查看哦.
  完成后 ask lao about ok"NOR;  
if (!present("newbie armor",me))
{
                  ob1=new("/p/item/newbie");
                  ob1->move(me); 
}

if (!present("newbie sword",me))
{
                  ob1=new("/p/item/newbiesword");
                  ob1->move(me); 
}

}

if (me->query("nbjob",1)==19)
msg=HIY"老村长说道：\n最后一个任务 出村
老村长说道：你的新手生涯就要到此就要结束了.短短的时间内,
你学到不少东西吧.别忘了你在我这里学到的东西，它将你在江
湖里创造一个属于你个人的天地。再见了（ask lao about 出村)"NOR;  


message("vision", msg+"\n", me);  
  return me->query("name")+"你快去完成这件事吧。";
}             


string ask_liwu16()
{
  string msg;
  object me=this_player();
  int exp_bound,qn_bound,neili,exp,pot;
  object ob1;
  object weapon;
weapon = me->query_temp("weapon");
if (!me->query("nbjob") && me->query_temp("nbjob1",1)>=2)
{
exp=1888;
addnl(me,"exp",exp);
me->set("nbjob",1);	
return "不错，不错，请继续努力 ask lao about job";
}	

if (me->query("nbjob",1)==1 && me->query_temp("nbjob2",1)>=3)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",2);	
return "不错，不错，请继续努力 ask lao about job";
}	

if (me->query("nbjob",1)==2 && me->query_temp("nbjob3",1)==1)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",3);	
return "不错，不错，请继续努力 ask lao about job";
}

if (me->query("nbjob",1)==3 && me->query_temp("nbjob4",1)==1)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",4);	
return "不错，不错，请继续努力 ask lao about job";
}

if (me->query("nbjob",1)==4 && me->query_temp("nbjob5",1)==1)
{
exp=1888;
addnl(me,"exp",exp);
me->set("nbjob",5);		
return "不错，不错，请继续努力 ask lao about job";
}

if (me->query("nbjob",1)==5 && me->query_skill("sword",1)>9 && me->query_skill("feixian-sword",1)>9 
&& (string) me->query_skill_mapped("sword") == "feixian-sword")
{
exp=1888;

                  ob1=new("/clone/money/silver");
                  ob1->move(me); 
                  ob1=new("/clone/money/silver");
                  ob1->move(me); 
                  ob1=new("/clone/money/silver");
                  ob1->move(me); 
addnl(me,"exp",exp);	
me->set("nbjob",6);	
return "不错，不错，请继续努力 ask lao about job";
}

if (me->query("nbjob",1)==6 && weapon)
{
if ((string)weapon->query("skill_type") == "sword")
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",7);	
return "不错，不错，请继续努力 ask lao about job";
}
}

if (me->query("nbjob",1)==7 &&  me->query_temp("nbjob8",1)==1)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",8);	
return "不错，不错，请继续努力 ask lao about job";
}

if (me->query("nbjob",1)==8 && me->query_temp("nbjob9",1)==1)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",9);	
                  ob1=new("/clone/money/silver");
                  ob1->move(me); 
                  ob1=new("/clone/money/silver");
                  ob1->move(me); 
                  ob1=new("/clone/money/silver");
                  ob1->move(me); 
return "不错，不错，请继续努力 ask lao about job";
//return "不错，不错，看来你已经可以出去闯荡江湖了！ ask lao about 出村";
}

if (me->query("nbjob",1)==9 && me->query_temp("nbjob10",1)==1)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",10);	
return "不错，不错，请继续努力 ask lao about job";
}

if (me->query("nbjob",1)==10 && me->query_temp("isdalinb",1)==1)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",11);	
return "不错，不错，请继续努力 ask lao about job";
}

if (me->query("nbjob",1)==11 && me->query_temp("isdangpu",1)==1)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",12);	
                  ob1=new("/d/welcome/npc/lbook1");
                  ob1->move(me); 
return "不错，不错，送你一本三字经，请继续努力 ask lao about job";
}

if (me->query("nbjob",1)==12 && me->query_temp("isdangpu2",1)==1)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",13);
                  ob1=new("/clone/money/silver");
                  ob1->move(me); 
                  ob1=new("/clone/money/silver");
                  ob1->move(me); 	
return "不错，不错，请继续努力 ask lao about job";
}

if (me->query("nbjob",1)==13 && me->query_temp("isbank",1)==1)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",14);
return "不错，不错，请继续努力 ask lao about job";
}

if (me->query("nbjob",1)==14 && me->query_temp("ishealnb",1)==1)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",15);
return "不错，不错，请继续努力 ask lao about job";
}

if (me->query("nbjob",1)==15 && me->query_temp("ischatnb",1)==1)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",16);
return "不错，不错，请继续努力 ask lao about job";
}

if (me->query("nbjob",1)==16 && me->query_temp("isaliasnb",1)==1)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",17);
return "不错，不错，请继续努力 ask lao about job";
}

if (me->query("nbjob",1)==17 && me->query_temp("isnbbg",1)==1)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",18);
return "不错，不错，请继续努力 ask lao about job";
}

if (me->query("nbjob",1)==18 && me->query_temp("isnbwp",1)==1)
{
exp=1888;
addnl(me,"exp",exp);	
me->set("nbjob",19);
return "不错，不错，请继续努力 ask lao about job";
}

  return "不错，不错！有空多看看帮助信息吧(help) 查看任务的情况请 ask lao about job";
}