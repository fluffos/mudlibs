#include <ansi.h>
inherit NPC;
int ask_force2();
int ask_force(string arg);
int ask_me();
int ask_nk();
int ask_zs1();
int ask_zs2();
int ask_zs3();
int ask_zs4();
int ask_zs5();
int ask_zs6();
int ask_hy();
int ask_hy2();
string ask_clear();
string ask_buchang();
string ask_panshi();
string ask_job();
#include "/clone/guard/party.h"
//int ask_gift();
int ask_bing();
int ask_yahuan();
int ask_yahuan2();
mapping pnames=([
"hxsd" : "hxsd",
"lds" : "lds",
"shazi": "shazi",
"lting" : "lting",
"yunlongzi" : "yunlongzi",
"hadis" : "hadisc",
"lxudd" : "lxudd",
"violet" : "violet",
"mist" : "mist",
"spray" : "spray",
"zmkk" : "zmkk",
"yoshare" : "yoshare",
"killman" : "killman",
"sos" : "sos",
"hensen" : "hensen",
"hongyue" : "hongyue",
"whym" : "whym",
"mudw": "mudw",
"green" : "green",
"yellow" : "yellow",
"baixinga" : "baixinga",
"luger" : "luger",
"lyj" : "lyj",
"liandan" : "liandan",
"ccy" : "ccy",
"helpmax" : "helpmax",
"what" : "what",
"paima" : "paima",								
"bhs" : "bhs",	
"savignyy" : "savignyy",	
"dust" : "dust",	
"qzz" : "qzz",	
"jqorzr" : "jqorzr",	
"qazqaz" : "qazqaz",	
"bsx" : "bsx",	
"parry" : "parry",	
"telnet" : "telnet",	
"ajax" : "ajax",	
"bbt" : "bbt",										
"bkl" : "bkl",										
"bry" : "bry",										
"bmr" : "bmr",										
"xianodf" : "xianodf",										
"xianoda" : "xianoda",										
"xianodab" : "xianodab",										
"xianodaa" : "xianodaa",										
"xianodaf" : "xianodaf",										
"wzliu" : "wzliu",																		
"dlc" : "dlc",																		
"game" : "game",																		
"ddbb" : "ddbb",																		
"npc" : "npc",																		
"rains" : "rains",																						
"langaoo" : "langaoo",																						
"lulusee" : "lulusee",																						
"rui" : "rui",																						
"aka" : "aka",																						
"phoenix" : "phoenix",																						
"qier" : "qier",																						
"numen" : "numen",																												
"angel" : "angel",																												
"pepsi" : "pepsi",																												
"zyy" : "zyy",																												
"ranran" : "ranran",																												
"xtm" : "xtm",																												
"kkk" : "kkk",																												
]);

string *jm1=({
"尚未开始",
"夜探商家堡 救人于水火",
"佛山小茶亭 大战袁紫衣",
"北京康王府 解秘掌门会",
"智救苗人凤 战胜田归农",
"义助程灵素 战败毒夫妇",
"战两雄得胜 得宝藏铁盒",
});

string *jm2=({
"尚未开始",
"守护奇铁盒 打败众强盗",
"智入玉笔峰 救出苗若兰",
"解闯王宝藏 败三大高手",
"败大内高手 成民族大义",
});
string *jm3=({
"尚未开始",	
"大败万震山 得连城剑法",
"大闹黑监狱 救出丁典来", 
"败落花流水 见血刀恶僧",
"救美女水笙 杀血刀恶僧",
"破庙败敌人 解连城宝藏",
});
string *jm4=({
"尚未开始",	
"智探无量山 进山洞寻宝",
"败四大恶人 恶战救段誉",
"保护天龙寺 挑战六脉剑",
"苏州探慕容 大败慕容复",
"识康敏奸计 破丐帮大阵",
"解逍遥棋局 打败丁春秋",
"救天山童姥 败七十二洞",
"探西夏皇宫 战胜李秋水",
"勇斗少林寺 败双雄挑战",
"大败辽国兵 败敌接乔锋",
});
string *jm5=({
"尚未开始",	
"义助铁木真 大败梅超风",
"试比武招亲 败叛徒杨康",
"寻访沙窟洞 胜桃花叛徒",
"智做叫花鸡 战败欧阳克",
"桃花岛探密 赢比武招亲",
"陆家庄破敌 大败金兵归",
"解四徒挑战 见一灯大师",
"铁掌山探险 得武穆移书",
"救襄阳危难 退拖雷大军",
"于华山论剑 得武学大成",
});
string *jm6=({
"尚未开始",	
"杀头狼获胜 挑战苏普胜",
"恶战陈达海 力帮李文秀",
"进高昌迷宫 败江南华辉",
"解高昌迷宫 败吕梁三杰",
"识破马家骏 打败计老人",
});

string *jm7=({
"尚未开始",	
"营救矛十八 再救白衣尼",
"救天地会主 见庄家遗孀",
"智杀螯拜回 抱得双儿归",
"进宫探秘密 识破假皇后", 
"智上神龙岛 大败洪教主",
"清凉寺灭敌 再杀吴三桂",
"关外守边疆 西藏灭叛逆",
"得四十二经 解大清宝藏",
});
string *jm8=({
"尚未开始",	
"败青城四兽 相救令狐冲",
"访福威镖局 再救林平之",
"打败田伯光 智救小仪琳",
"智上思过崖 约见风清扬",
"寻找药王庙 败剑宗门人", 
"败敌人追杀 力救向问天",
"秘密访梅庄 智救任我行",
"克少林群雄 救出任盈盈",
"夜探黑木崖 杀东方不败",
"嵩山比武会 败五派掌门",
"力救岳灵姗 败葵花辟邪",
});
string *jm9=({
"尚未开始",	
"华亭败清兵 救文泰骆冰",
"硬闯铁胆庄 破百花错拳",
"力救霍青桐 老云寨夺宝",
"刺杀张召重 抢七族盟书",
"杭州救皇帝 打败陈家洛",
});

string *jm10=({
"尚未开始",	
"过全真大阵 全真败霍都",
"打败李莫愁 力救陆无双",
"闯武林大会 三场定胜败",
"解绝情谷密 救出裘千尺",
"重阳宫抗敌 杀死赵志敬",
"解独孤求败 得玄铁重剑",
"智闯黑龙潭 探绝情谷底",
"救出小郭襄 杀金轮法王",
});
string *jm11=({
"尚未开始",	
"寻丁家两怪 得玄冰碧酒",
"战关东四帮 救大悲老人",
"救出石中玉 大败贝海石",
"硬闯凌霄城 打败白自在",
"接赏罚令牌 打败众岛主",
});
string *jm12=({
"尚未开始",	
"冰火岛解迷 教出张无忌",
"守护武当派 打败五大派", 
"解九阳秘密 打败朱九真",
"闯明教禁地 光明顶显威",
"探秘绿柳庄 得黑玉神药",
"访问灵蛇岛 败波斯三使",
"探险万安塔 败玄冥二老",
"打败三渡僧 杀成昆小人",
});
string *jm13=({
"尚未开始",	
"黑松堡救人 访问夏雪宜",
"拔出金蛇剑 杀敌救温仪",
"五毒教探险 打败何铁手",
"单挑玉真子 打败袁承志",
"打败皇太极 怒杀曹化淳",
});

string *jm14=({
"尚未开始",	
"挑战黑风寨 勇救萧中慧",
"智上常春岛 巧进白云岛",
"杀上蝙蝠岛 恶人谷探险",
"解秘进萧府 打败四高手",
"智得红钥匙 挑战袁冠男",
});


void create()
{
       set_name("无名居士", ({ "noname", "man" }));
        set("title",HIW"一代宗师"NOR);
	set("long", 
              "他就是无名居士，没有人知道他的来历。\n"
              "如果你想收集神书，你可以问问他(book)和(shi).\n"
              );
        set("age", 57);
        set("class", "beggar");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 700);
	set("int", 60);
	set("con", 60);
	set("dex", 700);
	set("per", 60);
	set("kar", 60);
	set("no_kill",1);
	    set("qi",   99999999);
	    set("jing", 99999999);
	set("eff_qi",   99999999);
	set("eff_jing", 99999999);
	set("max_qi",   99999999);
	set("max_jing", 99999999);
	set("neili", 554500);
	set("max_neili", 554500);
	set("jiali", 0);
	set("combat_exp", 285000000);
	set("score", 50000);                
        set_skill("strike",1200);
        set_skill("unarmed",1200);
        set_skill("dodge",1200);
        set_skill("force", 1200);
        set_skill("unarmed", 1200);
        set_skill("sword", 1200);
	set_skill("parry", 1210);
	set_skill("literate", 1200);
	set_skill("canzhi-duanhun",1300);
	set_skill("ai-sword",1300);
        map_skill("unarmed", "canzhi-duanhun");
        map_skill("parry", "canzhi-duanhun");
        map_skill("sword", "ai-sword");


set("inquiry", ([
            "book": "神书共有四十二本，你可以用help tasks获得有关方面知识！",
            "shi": "只有靠"HIR"七"+HIC+"彩"+HIY+"向"+HIM+"导"+HIG+"石"NOR+CYN"才能找到神书，灵石二十两一块！",
	     "mengzhu": (: ask_me :),
//	     "免战": (: ask_nk :),
//	     "nokill": (: ask_nk :),
	     "一转": (: ask_zs1 :),
	     "二转": (: ask_zs2 :),
	     "三转": (: ask_zs6 :),
	     "zhuanshen1": (: ask_zs1 :),
	     "zhuanshen2": (: ask_zs2 :),
	     "zhuanshen3": (: ask_zs6 :),
	     "转身技能": (: ask_zs3 :),
	     "finalskill": (: ask_zs3 :),
	     
	     "maxexp": (: ask_zs4 :),
	     "成长": (: ask_zs4 :), 
	     "双内功": (: ask_force2 :),
	     "force": (: ask_force2 :),
		"随从": (: ask_yahuan :),
		"更换随重": (: ask_yahuan2 :),
		"newguard": (: ask_yahuan2 :),
		"guard": (: ask_yahuan :),
//重要，申请和发礼物，只能开放一个，发礼物时关申请!!申请是关发礼物!!
	     "申请礼物":(: ask_clear :),
	     "yaogift":(: ask_clear :),
//           "gift":(: ask_buchang :),
//	     "节日礼物":(: ask_buchang :),
//	     "礼物":(: ask_buchang :),
//重要，申请和发礼物，只能开放一个，发礼物时关申请!!申请是关发礼物!!
//	     "huiyuan":(: ask_hy :),
//		"会员": (: ask_hy :),
//	     "oldplayer":(: ask_hy2 :),
//		"老玩家": (: ask_hy2 :),
            ]) );
            
set_temp("apply/intelligence", 200);
set_temp("apply/strength",200);
set_temp("apply/dexerity",200);
set_temp("apply/constitution",200);
set_temp("apply/karey", 200);
set_temp("apply/percao", 200);	
set_temp("apply/armor", 5000);
set_temp("apply/defense", 200);
set_temp("apply/attack", 200);
set_temp("apply/damage", 5000);  
            
       	setup();
     carry_object("/clone/weapon/changjian")->wield();
          carry_object("/clone/misc/cloth")->wear();
}
void init()
{
	add_action("do_answer", "answer");
	add_action("ask_force", "yaoforce");
}

int ask_hy()
{
    string week, month, year, day, time,hydata;
    string check;
 	    int i,how=0,what_day=100,neili,exp,pot,mpgx;
 	object me = this_player();
sscanf(ctime(time()), "%s %s %s %s %s", week, month, day, time, year);

    if ( me->query("zhuanshen") && !me->query("ishy"))
{
command("say 你没有会员权限，并已经转生了!");
        return 1;
}

//    write("现在是:");
    //write(year);
    //write(month);
    //write(day);
hydata=year+month+day;
//write(hydata);

    if ( me->query("hydata")==hydata)
{
command("say 你今天已经领过会员礼物了!");
        return 1;
}



//neili=280+random(888);
exp=88000+random(18888);
//pot=18000+random(88888);
pot=exp/2;
neili=50;
mpgx=2;
me->add("max_neili",neili);
me->add("combat_exp",exp);
me->add("potential",pot);
me->add("mpgx",2);

//     ob = new(__DIR__"red");
//     ob->move(me);
     me->set("hydata",hydata);
message_vision("$n的能力加强了!经验增加"+exp+"。潜能增加"+pot+"点。内力增加"+neili+"点。门派贡献增加2点。\n" , this_object(), me );
     //return "你好！\n"+me->query("name")+"的"+HIR"能力加强了许多"NOR+"。内力"+neili+",经验"+exp+",潜能"+pot+",门派贡献二点。\n";
	return 1;
}


int ask_hy2()
{
    string week, month, year, day, time,hydata,arg;
    string check;
 	    int i,how=0,what_day=100,neili,exp,pot,mpgx;
 	object ob;
 	object me = this_player();
sscanf(ctime(time()), "%s %s %s %s %s", week, month, day, time, year);
arg=me->query("id");

   if ( me->query("combat_exp")<=50000)
{
command("say 你先练会武功再来吧,你的经验太少! 需要五万经验!");
        return 1;
}

if (!stringp(pnames[arg])) 
{
command("say 你没有登记!");
        return 1;
}
    if ( me->query("isoldp")==1)
{
command("say 你今天已经领过老玩家礼包了!");
        return 1;
}


     ob = new("/clone/gift/newbiegift");
     ob->move(me);
     me->set("isoldp",1);
log_file("ishy", sprintf("%s 领了老玩家清档包 ON %s.\n", me->query("id"),ctime(time())));
message_vision("$n得到了老玩家清档转站包。并记录到日志系统中.如发现多领,直接所有档.\n" , this_object(), me );
command("say 谢谢您多年对海洋的支持!");
     //return "你好！\n"+me->query("name")+"的"+HIR"能力加强了许多"NOR+"。内力"+neili+",经验"+exp+",潜能"+pot+",门派贡献二点。\n";
	return 1;
}


int accept_object(object me, object ob)
{
object shi; 
if( ob->query("money_id") && ob->value() >= 2000)
{	
	 if (!present("xdshi", me))
	{
	shi = new("/clone/misc/findbook");
	command("say 好吧,"+me->query("name")+"既然给了钱，我就给你一块！\n");
	shi->move(me);
	message_vision("$N将一块"HIR"七"+HIC+"彩"+HIY+"向"+HIM+"导"+HIG+"石"NOR"交给了$n。\n" , this_object(), me );
	} else 
	command("say 你不是有了一块嘛，还想要？钱我没收！\n");
return 1;
}

command("say 谢谢，但我不要这东西！");
return 0;
}
int ask_me()
{
	string info,name,id,file,infoa,infob;
	object me,ob;
	me=this_player();
	ob=me;
	info = read_file("/data/npc/champion.o");


if ((int)ob->query("jinyong/book1",1)!= sizeof(jm1)-1
|| (int)ob->query("jinyong/book2",1)!= sizeof(jm2)-1
|| (int)ob->query("jinyong/book3",1)!= sizeof(jm3)-1
|| (int)ob->query("jinyong/book4",1)!= sizeof(jm4)-1
|| (int)ob->query("jinyong/book5",1)!= sizeof(jm5)-1
|| (int)ob->query("jinyong/book6",1)!= sizeof(jm6)-1
|| (int)ob->query("jinyong/book7",1)!= sizeof(jm7)-1
|| (int)ob->query("jinyong/book8",1)!= sizeof(jm8)-1
|| (int)ob->query("jinyong/book9",1)!= sizeof(jm9)-1
|| (int)ob->query("jinyong/book10",1)!= sizeof(jm10)-1
|| (int)ob->query("jinyong/book11",1)!= sizeof(jm11)-1
|| (int)ob->query("jinyong/book12",1)!= sizeof(jm12)-1
|| (int)ob->query("jinyong/book13",1)!= sizeof(jm13)-1
|| (int)ob->query("jinyong/book14",1)!= sizeof(jm14)-1
) 
{
command("say 你没有完成主线解密(questlists) 无资格挑战!");
        return 1;
}

if (ob->query("jinyong/all",1)==2)
{
command("say 你已经完成了挑战!");
        return 1;
}

	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
{
if (id==this_player()->query("id")) {this_player()->move("/d/biwu/b11");return 1;} 

}	
	
info = read_file("/data/npc/champion1.o");
	if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
{
if (id==this_player()->query("id")) {this_player()->move("/d/biwu/a11");return 1;}
}
if (!ob->query("jinyong/all")) ob->set("jinyong/all",1);	
tell_object(this_player(),"无名居士说道： 好吧，里面危险重重，千万别乱来，否则有生命危险。自己小心吧！\n");
this_player()->move("/d/biwu/hole");

return 1;
}

int ask_nk()
{
if(this_player()->query("PKS",1)> 10 
||this_player()->query_condition("killer")
//||this_player()->query("guard/flag")
||this_player()->query("age") < 18
 )
{
tell_object(this_player(),"无名居士说道：你没有资格，不能启用免战系统！\n");
}
else {
tell_object(this_player(),"无名居士说道： 好吧，你启用了免战系统！\n");
this_player()->set_temp("nokill",1);
}
return 1;
}





void unconcious()
{
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
	say( "无名居士笑着说：动武对我没有用！\n");
	command("hehe");
}

void die()
{
	unconcious();
}

int ask_yahuan2()
{
 	object me = this_player();

	if (!me->query("guard/flag"))
		command("say 凭你现在的条件，还没有资格问我要随从呢！");
	if (!me->query("guard/active"))
		command("say 你现在还没有随从!");
	else {
		command("nod " + me->query("id"));
		command("say 你已经重新可以换一个侍女了！");
		command("say 你会减去十分之一的经验");
	me->delete("guard/active");
  me->add("combat_exp",-(int)me->query("combat_exp")/10);
	}
	return 1;
}


int ask_yahuan()
{
 	object me = this_player();

	if (!me->query("guard/flag"))
		command("say 凭你现在的条件，还没有资格问我要随从呢！");
	else if (me->query("guard/active"))
		command("say 你不是已经有随从了么？");
	else {
		command("nod " + me->query("id"));
		if (me->query("gender") == "男性") {
			command("say 我现在正收了一些义女，她们都是名门弟子，有
\t\t武当派\t\t(wudang)
\t\t华山派\t\t(huashan)
\t\t灵鹫宫\t\t(lingjiu)
\t\t桃花岛\t\t(taohua)
\t\t天地会\t\t(tiandihui)
\t\t明教\t\t(mingjiao)
\t\t古墓派\t\t(gumu)
\t\t丐帮\t\t(gaibang)
\t\t全真教\t\t(quanzhen)
\t\t大理\t\t(dali)
\t\t铁掌帮\t\t(tiezhang)
\t\t慕容世家\t(murong)
\t\t昆仑派\t\t(kunlun)
\t\t凌霄城\t\t(lingxiao)
\t\t五毒教\t\t(wdjiao)
\t\t白驼山\t\t(baituo)
\t\t峨嵋派\t\t(emei)
\t\t逍遥派\t\t(xiaoyao)
\t\t雪山派\t\t(mizong)
\t\t星宿派\t\t(xingxiu)
\t\t御剑流\t\t(feitian)
\t\t神龙教\t\t(shenlong)
\t\t唐门\t\t(tangmen)
\t\t日月教\t\t(riyue)
\t\t少林\t\t(shaolin)
你想要收哪一个做你的丫环？请用answer回答我！");
		} else {
			command("say 我现在正收了一些义子，他们都是名门弟子，有
\t\t武当派\t\t(wudang)
\t\t华山派\t\t(huashan)
\t\t灵鹫宫\t\t(lingjiu)
\t\t桃花岛\t\t(taohua)
\t\t天地会\t\t(tiandihui)
\t\t明教\t\t(mingjiao)
\t\t古墓派\t\t(gumu)
\t\t丐帮\t\t(gaibang)
\t\t全真教\t\t(quanzhen)
\t\t大理\t\t(dali)
\t\t铁掌帮\t\t(tiezhang)
\t\t慕容世家\t(murong)
\t\t昆仑派\t\t(kunlun)
\t\t凌霄城\t\t(lingxiao)
\t\t五毒教\t\t(wdjiao)
\t\t白驼山\t\t(baituo)
\t\t峨嵋派\t\t(emei)
\t\t逍遥派\t\t(xiaoyao)
\t\t雪山派\t\t(mizong)
\t\t星宿派\t\t(xingxiu)
\t\t御剑流\t\t(feitian)
\t\t神龙教\t\t(shenlong)
\t\t唐门\t\t(tangmen)
\t\t日月教\t\t(riyue)
\t\t少林\t\t(shaolin)
你想要收哪一个做你的侍童？请用answer回答我！");
		}
		me->set_temp("guard/answer", 1);
	}
	return 1;
}
int do_answer(string arg)
{
	object me = this_player(), ob;
	int i, flag = 0;
	
	if (!me->query_temp("guard/answer"))
		return 0;
		
	// 要九阴传人需要一定的条件限制！
	for (i = 0; i < sizeof(ps); i++)
		if (arg == ps[i]["party"]) {
			flag = 1;
			break;
		}
	if (!flag) {
		command("kick " + me->query("id"));
		command("say 你想要的随从我可没有！");
		return 1;
	}
	command("ok");
	me->delete_temp("guard/answer");

	me->delete("guard/status");
	me->delete("guard/skills");
	me->delete("guard/gender");
	me->delete("guard/learned");
	me->delete("guard/skill_map");
	me->delete("guard/skill_prepare");
	me->set("guard/flag", 1);
	me->set("guard/active", 1);
	if (me->query("gender") == "男性")
		me->set("guard/gender", "girl");
	else
		me->set("guard/gender", "boy");
	me->set("guard/status", ps[i]["status"]);
	me->set("guard/skills", ps[i]["skills"]);
	me->set("guard/learned", ps[i]["learned"]);
	me->set("guard/skill_map", ps[i]["skill_map"]);
	me->set("guard/skill_prepare", ps[i]["skill_prepare"]);
	me->save();
	
	command("say 从今天起，她就跟着你了，你可以使用(zhaohuan)命令来召唤她！");
		
	return 1;
}

/*string ask_panshi()
{

        mapping quest,item,npc;
        object me=this_player();
if (me->query("npanshi"))
return HIR"“这位"+RANK_D->query_respect(me)+"我已经为你清过叛师记录了。"NOR;
command("say 由于系统调整，就帮你一次吧");
me->set("betrayer",0);
me->set("npanshi",1);
return HIW"“这位"+RANK_D->query_respect(me)+"以后要好好做人。"NOR;
}
*/

string ask_buchang()
{
        mapping quest,item,npc;
        object ob;
        object me=this_player();
if ((int)me->query("combat_exp") < 5000)
return HIR"“这位"+RANK_D->query_respect(me)+"是新手吧。"NOR;
  if(me->query("liwuopen/1")>0)
return HIR"“这位"+RANK_D->query_respect(me)+"已经来拿过了吧。"NOR;
  if(me->query("liwuopen/2")>0)
return HIR"“这位"+RANK_D->query_respect(me)+"已经来拿过了吧。"NOR;

 me->set("liwuopen/2",1);
 ob=new("/clone/gift/biggift");
        ob->set_amount(1);
        ob->move(me);
return HIR"“这位"+RANK_D->query_respect(me)+"节日快乐。祝身体健康!!"NOR;
}
string ask_clear()
{
        mapping quest,item,npc;
        object ob;
        object me=this_player();

 me->delete("liwuopen");

return HIW"“这位"+RANK_D->query_respect(me)+"你已经申请好了。"NOR;
}


int ask_zs1()
{
    int i,temp;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;

obj=this_player();

    if (obj->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");    

     if(obj->is_busy())
        return notify_fail("你现在正忙，没法杀人。\n");

    if ( !userp(obj))
        return notify_fail("这不是玩家啊?\n");

    if ( obj->query("zhuanshen"))
{
command("say 你已经转生过了!");
        return notify_fail("此人已经转生过了!\n");
}
    if (!obj->query("migong/lev3")
    ||!obj->query("migong/lev2")
    ||!obj->query("migong/lev1")
    ||!obj->query("migong/lev4")
    ||!obj->query("migong/lev5")
    ||!obj->query("migong/lev8")
    ||!obj->query("migong/lev6")
    ||!obj->query("migong/lev7")
    ||!obj->query("migong/lev9")
    ||!obj->query("migong/lev10")

    )
{
command("say 你没有资格转生!请至少完成迷宫任务到第10层!");
        return notify_fail("此人没有资格转生\n");
}
    if ( (int)obj->query("combat_exp",1) < 12000000)
{
command("say 你没有资格转生!1转需要12M经验。");
        return notify_fail("此人没有资格转生!1转需要12M经验。\n");
}
    if ( (int)obj->query("max_neili",1) < 5000)
{
command("say 你没有资格转生!你的内力不足!!");
        return notify_fail("此人没有资格转生!\n");
}

    if ( (int)obj->query("mpgx",1) < 50)
{
command("say 你没有资格转生!你的门派贡献不足!!");
        return notify_fail("此人没有资格转生!\n");
}	
		
		
    obj->set("eff_qi",obj->query("max_qi"));
    obj->set("qi",obj->query("max_qi"));
    obj->set("eff_jing",obj->query("max_jing"));
    obj->set("jing",obj->query("max_jing"));
    obj->set("jingli",obj->query("max_jingli"));
    obj->set("neili",obj->query("max_neili"));
    obj->set("food",obj->max_food_capacity());
    obj->set("water",obj->max_water_capacity());
    obj->clear_condition();
if (mapp(skill_status = obj->query_skills()))//判断自己是否有功夫，如有将用这个函数全部删除
{
skill_status = obj->query_skills();
sname = keys(skill_status);//传回所有自己的功夫阵列

temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
obj->delete_skill(sname[i]);//删除自己所有功夫
}
		obj->map_skill("unarmed");
		obj->map_skill("hammer");
		obj->map_skill("blade");
		obj->map_skill("stick");
		obj->map_skill("staff");
		obj->map_skill("club");
		obj->map_skill("throwing");
		obj->map_skill("parry");
		obj->map_skill("dodge");
		obj->map_skill("magic");
		obj->map_skill("spells");
		obj->map_skill("leg");
		obj->map_skill("axe");
		obj->map_skill("array");
		obj->map_skill("whip");	
		obj->map_skill("finger");
		obj->map_skill("hand");	
		obj->map_skill("cuff");	
		obj->map_skill("claw");	
		obj->map_skill("strike");	

		obj->prepare_skill("unarmed");
		obj->prepare_skill("hammer");
		obj->prepare_skill("blade");
		obj->prepare_skill("stick");
		obj->prepare_skill("staff");
		obj->prepare_skill("club");
		obj->prepare_skill("throwing");
		obj->prepare_skill("parry");
		obj->prepare_skill("dodge");
		obj->prepare_skill("magic");
		obj->prepare_skill("spells");
		obj->prepare_skill("leg");
		obj->prepare_skill("axe");
		obj->prepare_skill("array");
		obj->prepare_skill("whip");	
		obj->prepare_skill("finger");
		obj->prepare_skill("hand");	
		obj->prepare_skill("cuff");	
		obj->prepare_skill("claw");	
		obj->prepare_skill("strike");	
                obj->reset_action();

// 1
        if ( obj->query("per",1) < 60)
obj->set("per",obj->query("per")+20);

//2
        if ( obj->query("str",1) < 60)
obj->set("str",obj->query("str")+20);

//3
        if ( obj->query("dex",1) < 60)
 obj->set("dex",obj->query("dex")+20);

//4
        if ( obj->query("int",1) < 60)
 obj->set("int",obj->query("int")+20);

//5
        if ( obj->query("con",1) <60)
 obj->set("con",obj->query("con")+20);


//6
        if ( obj->query("kar",1) <60)
 obj->set("kar",obj->query("kar")+20);

        obj->set("betrayer",0);
        obj->set("title","普通百姓");
        obj->set("class","0");
        obj->set("score",0);
        obj->set("shen",0);
        obj->set("max_neili",0);
        obj->set("max_qi",105);
        obj->set("max_jing",105);
        obj->delete("family");
        obj->delete("party");
obj->delete("blade_get");
obj->delete("work/wakuang");
obj->delete("work/wunon");
obj->delete("work/penlen");
obj->delete("work/zhujian");
obj->delete("work/zhudao");
obj->delete("work/zhubanzi");
obj->delete("work/buyu");
obj->delete("work/dalie");
obj->delete("work/zhaojiu");
obj->delete("work/zhujia");
obj->delete("work");
obj->delete("breakup");
obj->delete("last_getzhen");
obj->delete("dali/fail");
        obj->set("killbyname",0);
        obj->set("MKS",0);
        obj->set("meili",0);
        obj->set("dietimes",0);
        obj->set("normal_die",0);
        obj->set("weiwang",0);
        obj->set("mud_age",400000);
obj->set("combat_exp",0);  
obj->set("mpgx",0);  
obj->set("learned_points",0);
obj->set("potential",obj->query("learned_points"));
                obj->set("mpgx",0);

        //obj->delete("levels");
        obj->save();
obj->set("tforceok",2);
obj->set("guard/flag",1);
obj->set("zhuanshen",1);
obj->delete("jinyong");
obj->delete("blade_get");
obj->delete("szj/failed");
obj->delete("jiuyin/shang-failed");
obj->delete("jiuyin/xia-failed");
obj->delete("zhou/fail");
obj->delete("zhou/jieyi");
obj->delete("jiuyin/gumu-failed");
obj->delete("zhou/failed");
obj->delete("obstacle");
if (obj->query("hyvip"))
{
if (obj->query("hyvip")) obj->add("hymoney",30);
if (obj->query("hyvip")) obj->set("combat_exp",500000);
if (obj->query("hyvip")) obj->add("potential",300000);
}
//obj->set("nbjob",0);
//obj->set("nbtjob32",0);
//obj->set("nbtjob33",0);
    write(HIR"一转成功,请重新登陆!\n"NOR);
tell_object(obj,HIR"一转成功,请重新登陆!\n"NOR);
	log_file("static/ZS",
		sprintf("%s 一转，时间: %s\n", geteuid(obj), ctime(time())) );

        CHANNEL_D->do_channel(this_object(), "rumor", "听说" + obj->name(1) +
                              "一转了。");
    "/cmds/usr/quit"->main(obj);

    return 1;
}

int ask_zs2()
{
    int i,temp;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;

obj=this_player();

    if (obj->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");    

     if(obj->is_busy())
        return notify_fail("你现在正忙，没法杀人。\n");

    if ( !userp(obj))
        return notify_fail("这不是玩家啊?\n");

    if ( !obj->query("zhuanshen"))
{
command("say 你没经过一转!");
        return notify_fail("此人没经过一转!\n");
}

    if (obj->query("zhuanbest")  )
{
command("say 你已经二转过了! ");
        return notify_fail("你已经二转过了!\n");
}


    if (!obj->query("migong/lev11")
    ||!obj->query("migong/lev12")
    ||!obj->query("migong/lev13")
    ||!obj->query("migong/lev14")
    ||!obj->query("migong/lev15")
    )
{
command("say 你没有资格转生!请至少完成迷宫任务到第15层!");
        return notify_fail("此人没有资格转生\n");
}
    if ( (int)obj->query("combat_exp") < 100000000)
{
command("say 你没有资格转生!2转需要100M经验。");
        return notify_fail("此人没有资格转生,2转需要100M经验!\n");
}
    if ( (int)obj->query("max_neili") < 6000)
{                   
command("say 你没有资格转生!你的内力不足!!");
        return notify_fail("此人没有资格转生!\n");
}
    if ( (int)obj->query("mpgx",1) < 100)
{
command("say 你没有资格转生!你的门派贡献不足!!");
        return notify_fail("此人没有资格转生!\n");
}	











    obj->set("eff_qi",obj->query("max_qi"));
    obj->set("qi",obj->query("max_qi"));
    obj->set("eff_jing",obj->query("max_jing"));
    obj->set("jing",obj->query("max_jing"));
    obj->set("jingli",obj->query("max_jingli"));
    obj->set("neili",obj->query("max_neili"));
    obj->set("food",obj->max_food_capacity());
    obj->set("water",obj->max_water_capacity());
    obj->clear_condition();
if (mapp(skill_status = obj->query_skills()))//判断自己是否有功夫，如有将用这个函数全部删除
{
skill_status = obj->query_skills();
sname = keys(skill_status);//传回所有自己的功夫阵列

temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
obj->delete_skill(sname[i]);//删除自己所有功夫
}
		obj->map_skill("unarmed");
		obj->map_skill("hammer");
		obj->map_skill("blade");
		obj->map_skill("stick");
		obj->map_skill("staff");
		obj->map_skill("club");
		obj->map_skill("throwing");
		obj->map_skill("parry");
		obj->map_skill("dodge");
		obj->map_skill("magic");
		obj->map_skill("spells");
		obj->map_skill("leg");
		obj->map_skill("axe");
		obj->map_skill("array");
		obj->map_skill("whip");	
		obj->map_skill("finger");
		obj->map_skill("hand");	
		obj->map_skill("cuff");	
		obj->map_skill("claw");	
		obj->map_skill("strike");	

		obj->prepare_skill("unarmed");
		obj->prepare_skill("hammer");
		obj->prepare_skill("blade");
		obj->prepare_skill("stick");
		obj->prepare_skill("staff");
		obj->prepare_skill("club");
		obj->prepare_skill("throwing");
		obj->prepare_skill("parry");
		obj->prepare_skill("dodge");
		obj->prepare_skill("magic");
		obj->prepare_skill("spells");
		obj->prepare_skill("leg");
		obj->prepare_skill("axe");
		obj->prepare_skill("array");
		obj->prepare_skill("whip");	
		obj->prepare_skill("finger");
		obj->prepare_skill("hand");	
		obj->prepare_skill("cuff");	
		obj->prepare_skill("claw");	
		obj->prepare_skill("strike");	
                obj->reset_action();
        if ( obj->query("per") < 100)
        {
	obj->set("per",obj->query("per")+20);
        }
        if ( obj->query("str") < 100)
        {
	obj->set("str",obj->query("str")+20);
        }
        if ( obj->query("dex")< 100)
        {
	obj->set("dex",obj->query("dex")+20);
        }
        if ( obj->query("int")< 100)
        {
	obj->set("int",obj->query("int")+20);
        }
        if ( obj->query("con")< 100)
        {
	obj->set("con",obj->query("con")+20);
        }
        if ( obj->query("kar")< 100)
        {
	obj->set("kar",obj->query("kar")+20);
        }

        obj->set("betrayer",0);
        obj->set("title","普通百姓");
        obj->set("class","0");
        obj->set("score",0);
        obj->set("shen",0);
        obj->set("max_neili",0);
        obj->set("max_qi",105);
        obj->set("max_jing",105);
        obj->delete("family");
        obj->delete("party");
obj->delete("work/wakuang");
obj->delete("work/wunon");
obj->delete("work/penlen");
obj->delete("work/zhujian");
obj->delete("work/zhudao");
obj->delete("work/zhubanzi");
obj->delete("work/buyu");
obj->delete("work/dalie");
obj->delete("work/zhaojiu");
obj->delete("work/zhujia");
obj->delete("work");
obj->delete("breakup");
obj->delete("last_getzhen");
obj->delete("dali/fail");
        obj->set("killbyname",0);
        obj->set("MKS",0);
        obj->set("zhuanshen",1);
        obj->set("meili",0);
        obj->set("dietimes",0);
        obj->set("normal_die",0);
        obj->set("weiwang",0);
        obj->set("mud_age",400000);
obj->set("zhuanbest",1);
                obj->set("combat_exp",0);
                obj->set("mpgx",0);
obj->set("learned_points",0);
obj->set("potential",obj->query("learned_points"));
obj->delete("blade_get");
obj->delete("szj/failed");
obj->delete("jiuyin/shang-failed");
obj->delete("jiuyin/xia-failed");
obj->delete("zhou/fail");
obj->delete("zhou/jieyi");
obj->delete("jiuyin/gumu-failed");
obj->delete("zhou/failed");
obj->set("guard/flag",1);
obj->set("tforceok",2);

obj->set("zhuanbest",1);
obj->delete("szj/failed");
obj->delete("zhou/failed");
obj->delete("zhou/fail");
obj->delete("zhou/jieyi");
obj->set("jiuyin/full",1);
    write(HIR"获得九阴!\n"NOR);
obj->set("szj/passed",1);
    write(HIR"获得神照!\n"NOR);
obj->set("double_attack",1);
write(HIR"获得互搏!\n"NOR);
if (obj->query("hyvip"))
{
if (obj->query("hyvip")) obj->add("hymoney",30);
if (obj->query("hyvip")) obj->set("combat_exp",500000);
if (obj->query("hyvip")) obj->add("potential",300000);
}
        obj->save();
    write(HIR"二转成功,请重新登陆!\n"NOR);
tell_object(obj,HIR"二转成功,请重新登陆!\n"NOR);
obj->delete("jinyong");
obj->delete("obstacle");
obj->delete("last_alert");
	log_file("static/ZS",
		sprintf("%s 二转，时间: %s\n", geteuid(obj), ctime(time())) );
CHANNEL_D->do_channel(this_object(), "rumor", "听说" + obj->name(1) +"二转了。");
    "/cmds/usr/quit"->main(obj);

    return 1;
}

int ask_force(string arg)
{
    int i,temp,j;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;

obj=this_player();
if (!arg)
return notify_fail("你要要做什么呢？\n");
if (obj->is_busy())
{
command("say 你正忙着呢!");
        return notify_fail("你正忙着呢!\n");
}
    if (obj->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");    

    if ( !userp(obj))
        return notify_fail("这不是玩家啊?\n");

    if ( !obj->query("zhuanshen")
    &&!obj->query("guard/flag")
    &&!obj->query("zhuanbest")
    )
{
command("say 你没有能力使用两种内功!");
        return notify_fail("你没有资格使用两种内功!\n");
}
    if ( !obj->query("tforceok"))
{
command("say 你已经有这种能力了吗!");
        return notify_fail("你没有资格使用两种内功!\n");
}

    if ( (int)obj->query("tforceok")==1)
{
command("say 我不是已经给过你这种能力了吗!");
        return notify_fail("你没有资格使用两种内功!\n");
}

    if ( (int)obj->query("combat_exp") < 800000)
{
command("say 你先练一会武功再来!只有一次机会!!");
        return notify_fail("你先练一会武功再来!\n");
}
    if ( (int)obj->query("combat_exp") < 1000000)
{
command("say 你先练熟一种内功再来吧!只有一次机会!!");
        return notify_fail("你先练一会武功再来!\n");
}
if (mapp(skill_status = obj->query_skills()))//判断自己是否有功夫，如有将用这个函数全部删除
{
j =0;
skill_status = obj->query_skills();
sname = keys(skill_status);//传回所有自己的功夫阵列
temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
if (SKILL_D(sname[i])->exert_function_file() 
&& sname[i]!="force"
&& sname[i]!="taixuan-gong"
&& sname[i]!="jiuyin-zhengong")
{
j=j+1;
}
CHANNEL_D->do_channel(this_object(), "rumor", "听说" + obj->query("name") +"共有" + j +"种内功。");
}
if (j < 1) 
{
command("say 你先学一种内功再来!机会只给一次!!");
        return notify_fail("你先练一会武功再来!\n");
}

if (j > 5) 
{
command("say 你已经有六种内功了!!机会只给一次!!");
        return notify_fail("你先练一会武功再来!\n");
}

if (arg=="wudang")
{
obj->set_skill("taiji-shengong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );
}
else if (arg=="huashan")
{
obj->set_skill("zixia-shengong",105);
obj->set_skill("huashan-neigong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );
}
else if (arg=="lingjiu")
{
obj->set_skill("beiming-shengong",105);
obj->set_skill("bahuang-gong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="mingjiao")
{
obj->set_skill("jiuyang-shengong",105);
obj->set_skill("shenghuo-shengong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="shaolin")
{
obj->set_skill("yijinjing",105);
obj->set_skill("hunyuan-yiqi",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="xueshan")
{
obj->set_skill("longxiang",105);
obj->set_skill("xiaowuxiang",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="xiaoyao")
{
obj->set_skill("beiming-shengong",105);
obj->set_skill("bahuang-gong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="riyue")
{
obj->set_skill("kuihua-xinfa",105);
obj->set_skill("tmdafa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}

else if (arg=="taohua")
{
obj->set_skill("bibo-shengong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="tiandihui")
{
obj->set_skill("yunlong-shengong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="gumu")
{
obj->set_skill("yunv-xinfa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="gaibang")
{
obj->set_skill("huntian-qigong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="quanzhen")
{
obj->set_skill("xiantian-qigong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="dali")
{
obj->set_skill("kurong-changong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="tiezhang")
{
obj->set_skill("guiyuan-tunafa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="murong")
{
obj->set_skill("shenyuan-gong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="kunlun")
{
obj->set_skill("xuantian-wuji",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="lingxiao")
{
obj->set_skill("bingxue-xinfa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="wdjiao")
{
obj->set_skill("wudu-shengong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="emei")
{
obj->set_skill("linji-zhuang",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="xingxiu")
{
obj->set_skill("huagong-dafa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="shenlong")
{
obj->set_skill("shenlong-xinfa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="baituo")
{
obj->set_skill("hamagong",105);
obj->set("tforceok",1);

	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );
}
else if (arg=="tangmen")
{
obj->set_skill("biyun-xinfa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else if (arg=="feitian")
{
obj->set_skill("shayi-xinfa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s 要内功，种类: %s\n", geteuid(obj), arg) );

}
else
command("say 武林中有很多种内功，分别为
\t\t武当派\t\t(wudang)
\t\t华山派\t\t(huashan)
\t\t灵鹫宫\t\t(lingjiu)
\t\t桃花岛\t\t(taohua)
\t\t天地会\t\t(tiandihui)
\t\t明教\t\t(mingjiao)
\t\t古墓派\t\t(gumu)
\t\t丐帮\t\t(gaibang)
\t\t全真教\t\t(quanzhen)
\t\t大理\t\t(dali)
\t\t铁掌帮\t\t(tiezhang)
\t\t慕容世家\t(murong)
\t\t昆仑派\t\t(kunlun)
\t\t凌霄城\t\t(lingxiao)
\t\t五毒教\t\t(wdjiao)
\t\t少林派\t\t(shaolin)
\t\t峨嵋派\t\t(emei)
\t\t星宿派\t\t(xingxiu)
\t\t神龙教\t\t(shenlong)
\t\t白驼山\t\t(baituo)
\t\t唐门\t\t(tangmen)
\t\t飞天御剑流\t(feitian)
\t\t雪山寺\t\t(xueshan)
\t\t逍遥派\t\t(xiaoyao)
\t\t日月神教\t(riyue)
你想要哪一门内功为辅助！");
    "/cmds/usr/save"->main(obj);
if (!wizardp(obj))
obj->start_busy(8);
    return 1;
}

int ask_force2()
{
    int i,temp,j;
    object obj;

obj=this_player();

if (obj->is_busy())
{
command("say 你正忙着呢!");
        return notify_fail("你正忙着呢!\n");
}
    if (obj->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");    

    if ( !userp(obj))
        return notify_fail("这不是玩家啊?\n");


command("say 武林中有很多种内功，分别为
\t\t武当派\t\t(wudang)
\t\t华山派\t\t(huashan)
\t\t灵鹫宫\t\t(lingjiu)
\t\t桃花岛\t\t(taohua)
\t\t天地会\t\t(tiandihui)
\t\t明教\t\t(mingjiao)
\t\t古墓派\t\t(gumu)
\t\t丐帮\t\t(gaibang)
\t\t全真教\t\t(quanzhen)
\t\t大理\t\t(dali)
\t\t铁掌帮\t\t(tiezhang)
\t\t慕容世家\t(murong)
\t\t昆仑派\t\t(kunlun)
\t\t凌霄城\t\t(lingxiao)
\t\t五毒教\t\t(wdjiao)
\t\t少林派\t\t(shaolin)
\t\t峨嵋派\t\t(emei)
\t\t星宿派\t\t(xingxiu)
\t\t神龙教\t\t(shenlong)
\t\t白驼山\t\t(baituo)
\t\t唐门\t\t(tangmen)
\t\t飞天御剑流\t(feitian)
\t\t雪山寺\t\t(xueshan)
\t\t逍遥派\t\t(xiaoyao)
\t\t日月神教\t(riyue)
你想(yaoforce)要哪一门内功为辅助！");
if (!wizardp(obj))
obj->start_busy(8);
    return 1;
}

int ask_zs3()
{
    int i,temp;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;

obj=this_player();

    if (obj->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");    

     if(obj->is_busy())
        return notify_fail("你现在正忙，没法杀人。\n");

    if ( !userp(obj))
        return notify_fail("这不是玩家啊?\n");

    if (!obj->query("4zhuan")
    && !obj->query("5zhuan"))
{
command("say 你没有资格要技能!");
        return notify_fail("此人没有资格要技能\n");
}
    if ( (int)obj->query("combat_exp") < 800000)
{
command("say 你经验高点再来要吧!");
        return notify_fail("你经验高点再来要吧!\n");
}
    if ( (int)obj->query("max_neili") < 1000)
{
command("say 你没有资格转生!你的内力不足!!");
        return notify_fail("此人没有资格转生!\n");
}
if (obj->query("4zhuan",1) || obj->query("5zhuan",1))
{
obj->set_skill("tianrenheyi",205);
write(HIY"获得武功【天人合一】!\n"NOR);
}

if (obj->query("zhuanfinal/7",1)==1 && obj->query("4zhuan",1))
{
obj->set_skill("yinyang-shiertian",205);
write(HIY"获得武功【阴阳十二重天】!\n"NOR);
}
if (obj->query("zhuanfinal/8",1)==1 && obj->query("4zhuan",1))
{
obj->set_skill("never-defeated",205);
write(HIY"获得武功【不败神功】!\n"NOR);
}

    write(HIR"技能获得成功!\n"NOR);
tell_object(obj,HIR"技能获得成功!\n"NOR);
    return 1;
}




int ask_zs5()
{
    int i,temp,maxexp;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;

obj=this_player();
obj->set_temp("xmud",1);
tell_object(obj,HIR"xmud适应成功!\n"NOR);
    return 1;

}        

int ask_zs4()
{
    int i,temp,maxexp;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;

obj=this_player();

    if (obj->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");    

     if(obj->is_busy())
        return notify_fail("你现在正忙着呢。\n");

    if ( !userp(obj))
        return notify_fail("这不是玩家啊?\n");

    if (!obj->query("4zhuan")
    && !obj->query("5zhuan"))
{
command("say 你不需要要获得成长资历!");
        return notify_fail("此人不需要要获得成长资历\n");
}
    if ( (int)obj->query("combat_exp") < 590000)
{
command("say 你经验高点再来要吧!");
        return notify_fail("你经验高点再来要吧!\n");
}
    if ( (int)obj->query("max_neili") < 1000)
{
command("say 你没有资格转生!你的内力不足!!");
        return notify_fail("此人没有资格转生!\n");
}

    if ( (int)obj->query_temp("menpaijob",1) < 12)
{
command("say 你还没有做满12个门派任务呢!!");
        return notify_fail("你还没有做满12个门派任务呢!!\n");
}

maxexp=6000000+(obj->query("expmax",1)*500000);

    if ( (maxexp-(int)obj->query("combat_exp",1)) > 800000)
{
command("say 你没有达到成长瓶颈，不需来!");
        return notify_fail("你没有达到成长瓶颈，不需来!\n");
}


if (obj->query_temp("menpaijob",1) >= 12)
{
if (obj->query("expmax",1) < 1)
{
obj->set("expmax",1);
}
else
{
obj->add("expmax",1);
}
}
obj->set_temp("menpaijob",0);
tell_object(obj,HIR"成长资历获得成功!\n"NOR);
    return 1;
}



int ask_zs6()
{
    int i,temp;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;

obj=this_player();

    if (obj->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");    

     if(obj->is_busy())
        return notify_fail("你现在正忙，没法杀人。\n");

    if ( !userp(obj))
        return notify_fail("这不是玩家啊?\n");

    if ( !obj->query("zhuanshen"))
{
command("say 你没经过一转!");
        return notify_fail("此人没经过一转!\n");
}

    if ( !obj->query("zhuanbest"))
{
command("say 你没经过二转!");
        return notify_fail("此人没经过二转!\n");
}
if (obj->query("4zhuan"))
{
command("say 你已经3转过了 ");
        return notify_fail("你已经3转过了。\n");
}


    if (!obj->query("migong/lev16")
    ||!obj->query("migong/lev17")
    ||!obj->query("migong/lev18")
    ||!obj->query("migong/lev19")
    ||!obj->query("migong/lev20")
    ||!obj->query("migong/lev21")
    )
{
command("say 你没有资格转生!请至少完成迷宫任务到第21层!");
        return notify_fail("此人没有资格转生\n");
}
    if ( (int)obj->query("combat_exp") < 200000000)
{
command("say 你没有资格转生!3转需要200M经验。");
        return notify_fail("此人没有资格转生,3转需要200M经验!\n");
}
    if ( (int)obj->query("max_neili") < 6000)
{                   
command("say 你没有资格转生!你的内力不足!!");
        return notify_fail("此人没有资格转生!\n");
}

    if ( (int)obj->query("mpgx",1) < 100)
{
command("say 你没有资格转生!你的门派贡献不足!!");
        return notify_fail("此人没有资格转生!\n");
}	



if (obj->query("zhuanbest")
&& (int)obj->query("combat_exp") > 200000000 )
{
obj->delete("last_alert");
    write(HIR"3转成功!\n"NOR);

    obj->set("4zhuan",1);


    
if (random(4)==0)
{
obj->set("zhuanfinal/6",1);
write(HIY"获得能力【国士无双】【银仙决】!\n"NOR);
obj->set("zhuanfinal/5",1);
write(HIY"获得能力【破元大法】【动仙决】!\n"NOR);
obj->set("zhuanfinal/1",1);
write(HIY"获得能力【元气无穷】【斩仙决】!\n"NOR);
}
else if (random(4)==1)
{
obj->set("zhuanfinal/2",1);
write(HIY"获得能力【遁影擒踪】【破仙决】!\n"NOR);
obj->set("zhuanfinal/6",1);
write(HIY"获得能力【国士无双】【银仙决】!\n"NOR);
obj->set("zhuanfinal/3",1);
write(HIY"获得能力【神魔金身】【乱仙决】!\n"NOR);
}
else if (random(4)==2)
{
obj->set("zhuanfinal/3",1);
write(HIY"获得能力【神魔金身】【乱仙决】!\n"NOR);
obj->set("zhuanfinal/4",1);
write(HIY"获得能力【缚骨缠身】【妙仙决】!\n"NOR);
obj->set("zhuanfinal/5",1);
write(HIY"获得能力【破元大法】【动仙决】!\n"NOR);

}
else 
{
obj->set("zhuanfinal/4",1);
write(HIY"获得能力【缚骨缠身】【妙仙决】!\n"NOR);
obj->set("zhuanfinal/1",1);
write(HIY"获得能力【元气无穷】【斩仙决】!\n"NOR);
obj->set("zhuanfinal/2",1);
write(HIY"获得能力【遁影擒踪】【破仙决】!\n"NOR);
}

obj->set("zhuanfinal/8",1);
write(HIY"获得武功【不败神功】!\n"NOR);

obj->delete("jinyong");
obj->delete("obstacle");
obj->delete("last_alert");


if (obj->query("hyvip")==4)
{
obj->set("zhuanfinal/7",1);
write(HIY"获得武功【阴阳十二重天】!\n"NOR);

}
    obj->set("eff_qi",obj->query("max_qi"));
    obj->set("qi",obj->query("max_qi"));
    obj->set("eff_jing",obj->query("max_jing"));
    obj->set("jing",obj->query("max_jing"));
    obj->set("jingli",obj->query("max_jingli"));
    obj->set("neili",obj->query("max_neili"));
    obj->set("food",obj->max_food_capacity());
    obj->set("water",obj->max_water_capacity());
    obj->clear_condition();
if (mapp(skill_status = obj->query_skills()))//判断自己是否有功夫，如有将用这个函数全部删除
{
skill_status = obj->query_skills();
sname = keys(skill_status);//传回所有自己的功夫阵列

temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
obj->delete_skill(sname[i]);//删除自己所有功夫
}
		obj->map_skill("unarmed");
		obj->map_skill("hammer");
		obj->map_skill("blade");
		obj->map_skill("stick");
		obj->map_skill("staff");
		obj->map_skill("club");
		obj->map_skill("throwing");
		obj->map_skill("parry");
		obj->map_skill("dodge");
		obj->map_skill("magic");
		obj->map_skill("spells");
		obj->map_skill("leg");
		obj->map_skill("axe");
		obj->map_skill("array");
		obj->map_skill("whip");	
		obj->map_skill("finger");
		obj->map_skill("hand");	
		obj->map_skill("cuff");	
		obj->map_skill("claw");	
		obj->map_skill("strike");	

		obj->prepare_skill("unarmed");
		obj->prepare_skill("hammer");
		obj->prepare_skill("blade");
		obj->prepare_skill("stick");
		obj->prepare_skill("staff");
		obj->prepare_skill("club");
		obj->prepare_skill("throwing");
		obj->prepare_skill("parry");
		obj->prepare_skill("dodge");
		obj->prepare_skill("magic");
		obj->prepare_skill("spells");
		obj->prepare_skill("leg");
		obj->prepare_skill("axe");
		obj->prepare_skill("array");
		obj->prepare_skill("whip");	
		obj->prepare_skill("finger");
		obj->prepare_skill("hand");	
		obj->prepare_skill("cuff");	
		obj->prepare_skill("claw");	
		obj->prepare_skill("strike");	
                obj->reset_action();
        if ( obj->query("per") < 120)
        {
	obj->set("per",obj->query("per")+20);
        }
        if ( obj->query("str") < 120)
        {
	obj->set("str",obj->query("str")+20);
        }
        if ( obj->query("dex")< 120)
        {
	obj->set("dex",obj->query("dex")+20);
        }
        if ( obj->query("int")< 120)
        {
	obj->set("int",obj->query("int")+20);
        }
        if ( obj->query("con")< 120)
        {
	obj->set("con",obj->query("con")+20);
        }
        if ( obj->query("kar")< 120)
        {
	obj->set("kar",obj->query("kar")+20);
        }

        obj->set("betrayer",0);
        obj->set("title","普通百姓");
        obj->set("class","0");
        obj->set("score",0);
        obj->set("shen",0);
        obj->set("max_neili",0);
        obj->set("max_qi",105);
        obj->set("max_jing",105);
        obj->delete("family");
        obj->delete("party");
obj->delete("work/wakuang");
obj->delete("work/wunon");
obj->delete("work/penlen");
obj->delete("work/zhujian");
obj->delete("work/zhudao");
obj->delete("work/zhubanzi");
obj->delete("work/buyu");
obj->delete("work/dalie");
obj->delete("work/zhaojiu");
obj->delete("work/zhujia");
obj->delete("work");
obj->delete("breakup");
obj->delete("last_getzhen");
obj->delete("dali/fail");
        obj->set("killbyname",0);
        obj->set("MKS",0);
        obj->set("zhuanshen",1);
        obj->set("meili",0);
        obj->set("dietimes",0);
        obj->set("normal_die",0);
        obj->set("weiwang",0);
        obj->set("mud_age",400000);
                obj->set("combat_exp",0);
                obj->set("mpgx",0);
obj->set("learned_points",0);
obj->set("potential",obj->query("learned_points"));
obj->delete("blade_get");
obj->delete("szj/failed");
obj->delete("jiuyin/shang-failed");
obj->delete("jiuyin/xia-failed");
obj->delete("zhou/fail");
obj->delete("zhou/jieyi");
obj->delete("jiuyin/gumu-failed");
obj->delete("zhou/failed");
obj->set("guard/flag",1);
obj->set("tforceok",2);
if (obj->query("hyvip"))
{
if (obj->query("hyvip")) obj->add("hymoney",30);
if (obj->query("hyvip")) obj->set("combat_exp",500000);
if (obj->query("hyvip")) obj->add("potential",300000);
}
        obj->save();
    write(HIR"三转成功,请重新登陆!\n"NOR);
tell_object(obj,HIR"三转成功,请重新登陆!\n"NOR);
if (obj->query("zhuanbest"))
{
	obj->delete("jinyong");
	log_file("static/ZS",
		sprintf("%s 三转，时间: %s\n", geteuid(obj), ctime(time())) );
CHANNEL_D->do_channel(this_object(), "rumor", "听说" + obj->name(1) +"三转了。");
}

    "/cmds/usr/quit"->main(obj);

    return 1;
}

}

mixed hit_ob(object me, object ob, int damage_bouns)
{
        int damage;
        
        damage = 3000 + random(3000);
        if (damage < 0) damage = 0;
        ob->receive_wound("qi", damage);
        me->set("neili", me->query("max_neili"));
if (me->is_busy()) me->start_busy(1);
me->clear_condition();

        return HIB "$N" HIB "“嘿”的一声使出无名气功，登时令$n"
               HIB "失去自我，被气功波屡屡击中。\n" NOR;

}

