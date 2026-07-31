// 水浒传之108将。

#include <ansi.h>

inherit NPC;

int ask_zhou();
int ask_back();
int inheritman(object newob,object ob,int manskills,string*manmsg,int newsequence);
string* msg = ({
"0,老魔星,天下第一,老魔",	
"1,天魁星,呼保义,宋江",
"2,天罡星,玉麒麟,卢俊义",
"3,天机星,智多星,吴用",
"4,天闲星,入云龙,公孙胜",
"5,天勇星,大刀,关胜",
"6,天雄星,豹子头,林冲",
"7,天猛星,霹雳火,秦明",
"8,天威星,双鞭,呼延灼",
"9,天英星,小李广,花荣",
"10,天贵星,小旋风,柴进",
"11,天富星,扑天雕,李应",
"12,天満星,美髯公,朱仝",
"13,天孤星,花和尚,鲁智深",
"14,天伤星,行者,武松",
"15,天立星,双枪将,董平",
"16,天捷星,没羽箭,张清",
"17,天暗星,青面獣,杨志",
"18,天佑星,金枪手,徐宁",
"19,天空星,急先锋,索超",
"20,天速星,神行太保,戴宗",
"21,天异星,赤髪鬼,刘唐",
"22,天杀星,黒旋风,李逵",
"23,天微星,九纹龙,史进",
"24,天究星,没遮拦,穆弘",
"25,天退星,挿翅虎,雷横",
"26,天寿星,混江龙,李俊",
"27,天剑星,立地太歳,阮小二",
"28,天平星,船火児,张横",
"29,天罪星,短命二郎,阮小五",
"30,天损星,浪里白跳,张顺",
"31,天败星,活阎罗,阮小七",
"32,天牢星,病关索,杨雄",
"33,天慧星,拚命三郎,石秀",
"34,天暴星,两头蛇,解珍",
"35,天哭星,双尾蝎,解宝",
"36,天巧星,浪子,燕青",
"37,地魁星,神机军师,朱武",
"38,地煞星,镇三山,黄信",
"39,地勇星,病尉遅,孙立",
"40,地杰星,丑郡马,宣赞",
"41,地雄星,井木犴,郝思文",
"42,地威星,百胜将,韩滔",
"43,地英星,天目将,彭玘",
"44,地奇星,圣水将,单廷圭",
"45,地猛星,神火将,魏定国",
"46,地文星,圣手书生,萧让",
"47,地正星,鉄面孔目,裴宣",
"48,地辟星,摩云金翅,欧鹏",
"49,地阖星,火眼狻猊,邓飞",
"50,地强星,锦毛虎,燕顺",
"51,地暗星,锦豹子,杨林",
"52,地辅星,轰天雷,凌振",
"53,地会星,神算子,蒋敬",
"54,地佐星,小温侯,吕方",
"55,地佑星,赛仁贵,郭盛",
"56,地霊星,神医,安道全",
"57,地獣星,紫髯伯,皇甫端",
"58,地微星,矮脚虎,王英",
"59,地慧星,一丈青,扈三娘",
"60,地暴星,丧门神,鲍旭",
"61,地黙星,混世魔王,樊瑞",
"62,地猖星,毛头星,孔明",
"63,地狂星,独火星,孔亮",
"64,地飞星,八臂哪吒,项充",
"65,地走星,飞天大圣,李衮",
"66,地巧星,玉臂匠,金大坚",
"67,地明星,鉄笛仙,马麟",
"68,地进星,出洞蛟,童威",
"69,地退星,翻江蜃,童猛",
"70,地満星,玉幡竿,孟康",
"71,地遂星,通臂猿,侯健",
"72,地周星,跳涧虎,陈达",
"73,地隠星,白花蛇,杨春",
"74,地异星,白面郎君,郑天寿",
"75,地理星,九尾亀,陶宗旺",
"76,地俊星,鉄扇子,宋清",
"77,地楽星,鉄叫子,乐和",
"78,地捷星,花项虎,龚旺",
"79,地速星,中箭虎,丁得孙",
"80,地镇星,小遮拦,穆春",
"81,地羁星,操刀鬼,曹正",
"82,地魔星,云里金刚,宋万",
"83,地妖星,摸着天,杜迁",
"84,地幽星,病大虫,薛永",
"85,地僻星,打虎将,李忠",
"86,地空星,小霸王,周通",
"87,地孤星,金銭豹子,汤隆",
"88,地全星,鬼睑児,杜兴",
"89,地短星,出林龙,邹渊",
"90,地角星,独角龙,邹润",
"91,地囚星,旱地忽律,朱贵",
"92,地蔵星,笑面虎,朱富",
"93,地伏星,金眼彪,施恩",
"94,地平星,鉄臂膊,蔡福",
"95,地损星,一枝花,蔡庆",
"96,地奴星,催命判官,李立",
"97,地察星,青眼虎,李云",
"98,地悪星,没面目,焦挺",
"99,地丑星,石将军,石勇",
"100,地数星,小尉遅,孙新",
"101,地阴星,母大虫,顾大嫂",
"102,地刑星,菜园子,张青",
"103,地壮星,母夜叉,孙二娘",
"104,地劣星,活闪婆,王定六",
"105,地健星,険道神,郁保四",
"106,地耗星,白日鼠,白胜",
"107,地贼星,鼓上蚤,时迁",
"108,地狗星,金毛犬,段景住",});

void create()
{
	set_name("梁山门将", ({ "xingxiu man", "liangshan" }));
	set("title", HIY "金毛犬" NOR);
	set("gender", "无性");
	set("age", 20);
	set("long","这是个看起来三十来岁的汉子，面眉全黑，脸傍消瘦，着一袭战袍，昂然挺立。\n");

	set("int", 30);
	set("str", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 6000);
	set("sequence", 108);
	set("max_qi", 5000);
	set("jing", 20000);
	set("max_jing", 20000);
	set("neili", 15000);
	set("max_neili", 15000);
	set("jiali", 250);
	set("combat_exp", 5000000);
	set("score", 20000000);

	set_skill("force", 100);
	set_skill("taixuan-gong", 100);
	set_skill("dodge", 100);
	set_skill("taixuan-gong", 100);
	set_skill("unarmed", 100);
	set_skill("taixuan-gong", 100);
	set_skill("parry", 100);

	map_skill("force", "taixuan-gong");
	map_skill("dodge", "taixuan-gong");
	map_skill("unarmed", "taixuan-gong");
	map_skill("parry", "taixuan-gong");
	
		prepare_skill("unarmed", "taixuan-gong");

	set("chat_chance_combat", 200);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: perform_action, "xuan" :),
	(: perform_action, "jing" :),
	}) );

	set("chat_chance", 5);
	set("inquiry", ([
		"108星宿" :  "水浒传听说过吗？。",
	]));

	create_family("梁山", 0, "好汉");
	setup();

	carry_object("/clone/misc/cloth")->wear();
}


void die()
{
        object me = this_object()->query_last_damage_from();
        object newob,ob,jl,jl2,jl1,wuliang,dan;
		string *manmsg;
        int newsequence,manskills,i,j;
        ob = this_object();
		newsequence = ob->query("sequence")-1;
		manmsg = explode(msg[newsequence],",");
		newob = new("d/fuben/108man/npc/1");
		jl = new("clone/jifeng/putao");
			jl1 = new("clone/jifeng/dan_congmai2");
				jl2 = new("clone/jifeng/dan_congmai3");
				wuliang = new("clone/jifeng/book_wuliang");
				dan = new("clone/jifeng/dan_congmai4");
				
				
		manskills = ob->query_skill("force",1)+10;

 if (ob->query("sequence") > 72)
	  {
	    if (random(2) == 1)
   	  {
     	  tell_object(me,HIR"恭喜你获得了一个葡萄和无量经书！\n"NOR);
	    jl->move(me);
		wuliang->move(me);
   	  }
   	  if (random(10) == 1)
  	  {
   	  me->add("jifeng",10);
  	  tell_object(me,HIR"恭喜你获得了10点点券！\n"NOR);
   	  }
	}
	  else
	    if (ob->query("sequence") > 32)
	  {
     	  if (random(2) == 1)
    	  {
	  tell_object(me,"恭喜你获得了一个中品冲脉丹！\n");
	  jl1->move(me);
     	  }
	       if (random(10) == 1)
    	  {
	  me->add("jifeng",10);
	  tell_object(me,"恭喜你获得了10点点券！\n");
	       }
	  }
	  else
	 if (ob->query("sequence") < 32)
{
	  if (random(2) == 1)
	  {
	  tell_object(me,HIW"恭喜你获得了一个上品冲脉丹！\n"NOR);
	 jl2->move(me);
	  }
	  if (random(10) == 1)
	  {
	  dan->move(me);
	  tell_object(me,HIR"恭喜你获得了极品冲脉丹！\n"NOR);
	  }
	 }
	    if (ob->query("sequence") == 1)
	  {
		  me->move("d/city/kedian");
		  ::die();
	  }
	  inheritman(newob,ob,manskills,manmsg,newsequence);
	  newob->set("long","这是梁山好汉中排名第"+manmsg[0]+"的"+ manmsg[2]+manmsg[3]+"，拥有很高的武艺。"); 
	  environment(me)->set("short",manmsg[1]);
	  newob->move(environment(me));  
	 tell_object(me,ZJFORCECMD("look"));//执行look指令，以便玩家看到当地环境名称的变化!
	  ::die();
}

int inheritman(object newob,object ob,int manskills,string*manmsg,int newsequence)
{
 newob->set("qi", ob->query("max_qi")+8000);
	newob->set("max_qi",ob->query("max_qi")+8000);
	newob->set("eff_qi",ob->query("max_qi")+8000);
	newob->set("jing", ob->query("max_jing")+8000);
	newob->set("max_jing", ob->query("max_jing")+8000);
	newob->set("neili", ob->query("max_neili")+8000);
	newob->set("max_neili", ob->query("max_neili")+8000);	  
	newob->set("sequence",newsequence);	 
	 newob->set("name",manmsg[3]);
	 newob->set("title",manmsg[2]);
	newob-> set_skill("force", manskills);
	newob->set_skill("taixuan-gong", manskills);
	newob->set_skill("dodge", manskills);
	newob->set_skill("taixuan-gong", manskills);
	newob->set_skill("unarmed", manskills);
	newob->set_skill("taixuan-gong", manskills);
	newob->set_skill("parry",manskills);
	return 1;
}