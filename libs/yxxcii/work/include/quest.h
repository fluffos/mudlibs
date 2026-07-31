
#ifndef __QUEST__
#define __QUEST__
string do_quest();
	
string chinese_time(int t)
{
	int d, h, m, s;
	string time;
	s = t % 60;     t /= 60;
	m = t % 60;     t /= 60;
	h = t % 24;     t /= 24;
	d = t;
	if(d) time = chinese_number(d) + "天";
	else time = "";
	if(h) time += chinese_number(h) + "小时";
	if(m) time += chinese_number(m) + "分";
	time += chinese_number(s) + "秒";
	return time;
}

string do_quest()
{
        mapping target=([
        "yue buqun":        "华山派现任掌门「君子剑」岳不群",
        "ping yizhi":       "药铺老板 平一指",
        "xu zhu":           "灵鹫宫掌门人「梦郎」虚竹",
        "xuanku dashi":     "少林派第三十六代弟子「罗汉堂首座」玄苦大师",
        "xuannan dashi":    "少林派第三十六代弟子「般若堂首座」玄难大师",
        "ning zhongze":     "华山派第十三代弟子 宁中则",
        "yu lianzhou":      "武当派第二代弟子「武当二侠」俞莲舟",
        "song yuanqiao":    "武当派第二代弟子「武当首侠」宋远桥",
        "li lishi":         "李力世",
        "guan anji":        "茶馆老板「关夫子」关安基",
        "lazhang huofo":    "活佛 拉章活佛",
        "jia laoliu":       "当铺老板 贾老六",
        "ouyang feng":      "老毒物「西毒」欧阳锋",
        "ding chunqiu":     "星宿派开山祖师「星宿老怪」丁春秋",
        "ben yin":          "天龙寺主持 本因",
        "zhang wuji":       "明教教主 张无忌",
        "wei yixiao":       "明教青翼蝠王 韦一笑",
        "ouye zi":          "玄天派开山祖师「赤心剑胆」欧冶子",
	"pang toutuo":      "神龙教左护法「辽东胖尊者」胖头陀",
	"guo jing":         "「北侠」郭靖",
	"shi song":         "黑龙鞭 史松",
	"maimaiti":         "杂货铺老板 买卖提",
	"chang jinpeng":    "明教朱雀坛坛主 常金鹏",
	"su xinghe":        "逍遥派第二代大弟子「聪辩老人」苏星河",
	"gou du":           "逍遥派“函谷八友”「书呆」苟读",
	"xue muhua":        "逍遥派“函谷八友”「阎王敌薛神医」薛慕华",
	"kang guangling":   "逍遥派“函谷八友”「琴颠」康广陵",
	"jiuyi daoren":     "西夏一品堂高手「雷动于九天之上」九翼道人",
	"zhaixing zi":      "星宿派第二代弟子「星宿派大师兄」摘星子",
	"zhang chengfeng":  "日月神教长老「金猴神魔」张乘风",
	"samu huofo":       "活佛 萨木活佛",
	"jinlun fawang":    "法王 金轮法王",
	"jiumo zhi":        "雪山寺掌门「大轮明王」鸠摩智",
	"ku rong":          "天龙寺第十六代僧人 枯荣大师",
	"sui xi":           "血刀门第六代弟子 随喜",
	"tiansong daoren":  "泰山派第十三代弟子 天松道人",
	"tianyi daoren":    "泰山派第十三代弟子 天乙道人",
	"susu":             "「伺茶丫鬟」素素",
	"wugen daozhang":   "神龙教赤龙使 无根道长",
	"yun sumei":        "神龙教赤龙使座下弟子 云素梅",
	"xu xueting":       "神龙教青龙使「热血神龙」许雪亭",
	"mo da":            "衡山派第十三掌门「潇湘夜雨」莫大",
	"bai guishou":      "明教玄武坛坛主 白龟寿",
	"hu zhanggui":      "杂货铺老板 胡掌柜",
	"zhang songxi":     "武当派第二代弟子「武当四侠」张松溪",
	"qing feng":        "武当派第五代弟子 清风",
	"liu chengfeng":    "「柔云剑」刘承风",
	"wu tiande":        "成都提督 吴天德",
	"huang boliu":      "日月神教风雷堂香主「银髯蛟」黄伯流",
	"lu gaoxuan":       "神龙教军师「神机妙算」陆高轩",
	"he bujing":	    "丐帮七袋弟子 何不净",
	"hong qigong":	    "丐帮第十七代帮主「九指神丐」洪七公",
	"jiang shangyou":   "丐帮五袋弟子 江上游",
	"cheng buyou":      "华山剑宗第十三代弟子 成不忧",
	"cong buqi":        "华山剑宗第十三代弟子 丛不弃",
	"yue wife":         "华山派第十三代弟子「淑女剑」岳夫人",
	"feng buping":      "华山剑宗第十三代弟子「狂风快剑」封不平",
	"yue buqun":        "华山派掌门「君子剑」岳不群",
	]);
	
	int ran, t, time;
	string *str;
	object ob, who, home;
	ob=this_object();

	if(!home = find_object(ob->query("startroom")))
		home = load_object(ob->query("startroom"));
	if (environment(ob)!=home){
		return("我现在正忙着呢！等我回去再说吧！");
	}
		who = this_player();
	if (who->query("family/family_name")=="少林派"){
	return who->name()+"，怎么大师也来赶这趟浑水？\n";
}
	if (who->query("combat_exp")>10000000)
	return("这位"+RANK_D->query_respect(who)+"的大名，江湖上谁人不知，哪个不晓？光临蔽局，深感荣幸！\n");
	if (who->query("combat_exp")<100000 || who->query("age") < 15)
	return("这位"+RANK_D->query_respect(who)+"面生的很，江湖上不知道咋称呼？\n");
        t = time()-who->query("biao_start");
	time = who->query("biao_time");
        if( t <= time )
	return  RANK_D->query_respect(who)+ "似乎还有任务在身吧？\n";
	if( t > time && t < (time + 300) ) {
		if( ob = present("biao yin", who) ) destruct(ob);
		who->set("biao_failed",1);
	}
	if( t >= (time + 300) )
		who->delete("biao_failed");
	if(who->query("biao_failed") ) {
		command("hehe " + who->query("id"));
		return this_player()->name() + "，你印堂发黑，流年失利，我看还是不适宜运镖了。\n";
	}
	t = ( 20 + random(10) ) * 10;
	str=keys(target);
	ran = random(sizeof(str));
	ob = new("/clone/misc/biaoyin");
	ob->set("target", str[ran]);
	who->set("biao_start", time());
	who->set("biao_time", t);
	ob->move(who);
	return ("你来得正好，我有一箱镖银送到" + target[str[ran]] + "的手里。\n"+"你还有" + chinese_time(t)+ "的时间。快快动身吧！\n");
	
}

#endif
