// Created by waiwai@2001/03/23
// 为了简化而整合

#include <ansi.h>
string day_event(){return NATURE_D->outdoor_room_event();}

// 帮会地盘灾害
string *bad_weather=({
	"所属$N地盘受干旱的影响，亏空",
	"所属$N地盘由于暴雨袭击，收成跌了",
	"所属$N地盘遭到了抢匪的袭击,被劫",
	"所属$N地盘被官府加重征税，$N亏空",
	"所属$N地盘疾病肆虐受损严重,亏损",
	"所属$N地盘受龙卷风袭击，结果损失",
	"所属$N地盘突发地震，人员伤亡惨重,损失",
	"所属$N地盘帮内内讧元气大伤,亏损",
});

string *bad_M=({
	HIG"受干旱的影响，$N地盘所属帮会亏空"NOR,
	HIG"由于暴雨袭击，$N地盘所属帮会收成跌了"NOR,
	HIG"$N地盘遭到了抢匪的袭击,所属帮会损失"NOR,
	HIG"官府加重对$N地盘的征税，$N所属帮会亏空"NOR,
	HIG"疾病在$N地盘肆虐，受损严重,所属帮会亏损"NOR,
	HIG"龙卷风袭卷了$N地盘，结果造成所属帮会损失"NOR,
	HIG"$N地盘突发地震，人员伤亡惨重,所属帮会损失"NOR,
	HIG"$N地盘帮内内讧，元气大伤,所属帮会亏损"NOR,
});

// 天降奇缘物件
// Added by waiwai@2002/07/20
string *stone = ({
//        "/obj/self/yuhua-stone",	//雨花石(343种随机组合)
        "/obj/self/yuhua-stone2",	//雨花石之二
        "/obj/self/stone-hib",	//蓝色神石
        "/obj/self/stone-hig",	//绿色神石
        "/obj/self/stone-hiy",	//金色神石
        "/obj/self/stone-hiw",	//银色神石
        "/obj/self/stone-him",	//紫色神石
        "/obj/self/stone-hic",	//青色神石
        "/obj/self/stone-hir",	//红色神石
        "/obj/self/agate",		//玛瑙
//        "/obj/self/magate",		//神之玛瑙
        "/obj/self/fagate",		//稀世玛瑙
        "/obj/self/cagate",		//玛瑙残片
        "/obj/self/crystal",	//水晶
//        "/obj/self/mcrystal",	//神之水晶
        "/obj/self/fcrystal",	//稀世水晶
        "/obj/self/ccrystal",	//水晶残片
        "/obj/self/diamond",	//钻石
//        "/obj/self/mdiamond",	//神之钻石
        "/obj/self/fdiamond",	//精美钻石
        "/obj/self/cdiamond",	//钻石碎粒
        "/obj/self/jade",		//翡翠
//        "/obj/self/mjade",		//神之翡翠
        "/obj/self/fjade",		//稀世翡翠
        "/obj/self/cjade",		//翡翠残片
        "/obj/self/jinkuai",	//金块
        "/obj/self/star",		//星星
});

// 天降奇缘路径(目前38个)
// Added by waiwai@2002/07/20
string *path=({
	"/d/city/",
	"/d/gao/",
	"/d/westway/",
	"/d/eastway/",
	"/d/changan/",
	"/d/kaifeng/",
	"/d/qujing/baotou/",
	"/d/qujing/baoxiang/",
	"/d/qujing/bibotan/",
	"/d/qujing/biqiu/",
	"/d/qujing/chechi/",
	"/d/qujing/dudi/",
	"/d/qujing/fengxian/",
	"/d/qujing/heifeng/",
	"/d/qujing/huangfeng/",
	"/d/qujing/jilei/",
	"/d/qujing/jindou/",
	"/d/qujing/jingjiling/",
	"/d/qujing/jinping/",
	"/d/qujing/jisaiguo/",
	"/d/qujing/liusha/",
	"/d/qujing/maoying/",
	"/d/qujing/nuerguo/",
	"/d/qujing/pansi/",
	"/d/qujing/pingding/",
	"/d/qujing/qilin/",
	"/d/qujing/qinfa/",
	"/d/qujing/qinglong/",
	"/d/qujing/shuangcha/",
	"/d/qujing/tianzhu/",
	"/d/qujing/tongtian/",
	"/d/qujing/wuji/",
	"/d/qujing/xiaoxitian/",
	"/d/qujing/yinwu/",
	"/d/qujing/yuhua/",
	"/d/qujing/zhujie/",
	"/d/qujing/zhuzi/",
});

// 天降奇缘路径对应区域(目前38个)
// Added by waiwai@2002/07/20
string *name=({
        HIW U"长安城内"NOR,
        HIW U"高老庄附近"NOR,
        HIW U"长安城以西"NOR,
        HIW U"长安城以东"NOR,
        HIW U"长安城以南"NOR,
        HIW U"开封城附近"NOR,
        HIW U"豹头山附近"NOR,
        HIW U"宝象国附近"NOR,
        HIW U"碧波潭附近"NOR,
        HIW U"比丘国附近"NOR,
        HIW U"车迟国附近"NOR,
        HIW U"毒敌山附近"NOR,
        HIW U"凤仙郡附近"NOR,
        HIW U"黑风山附近"NOR,
        HIW U"黄风岭附近"NOR,
        HIW U"积雷山附近"NOR,
        HIW U"金兜山附近"NOR,
        HIW U"荆棘岭附近"NOR,
        HIW U"金平府附近"NOR,
        HIW U"祭赛国附近"NOR,
        HIW U"流沙河附近"NOR,
        HIW U"毛颖山附近"NOR,
        HIW U"女儿国附近"NOR,
        HIW U"盘丝岭附近"NOR,
        HIW U"平顶山附近"NOR,
        HIW U"麒麟山附近"NOR,
        HIW U"钦法国附近"NOR,
        HIW U"青龙山附近"NOR,
        HIW U"双叉岭附近"NOR,
        HIW U"天竺国附近"NOR,
        HIW U"通天河附近"NOR,
        HIW U"乌鸡国附近"NOR,
        HIW U"小西天附近"NOR,
        HIW U"隐雾山附近"NOR,
        HIW U"玉华县附近"NOR,
        HIW U"竹节山附近"NOR,
        HIW U"朱紫国附近"NOR,
});

// 风霜雨雪区域信息显示
string *nameW=({
        HIY"大唐长安城"NOR,
        HIY"大唐高老庄"NOR,
        HIY"长安城西"NOR,
        HIY"长安城东"NOR,
        HIY"长安城南"NOR,
        HIY"大唐开封城"NOR,
        HIY"西域豹头山"NOR,
        HIY"西域宝象国"NOR,
        HIY"西域碧波潭"NOR,
        HIY"西域比丘国"NOR,
        HIY"西域车迟国"NOR,
        HIY"西域毒敌山"NOR,
        HIY"西域凤仙郡"NOR,
        HIY"西域黑风山"NOR,
        HIY"西域黄风岭"NOR,
        HIY"西域积雷山"NOR,
        HIY"西域金兜山"NOR,
        HIY"西域荆棘岭"NOR,
        HIY"西域金平府"NOR,
        HIY"西域祭赛国"NOR,
        HIY"西域流沙河"NOR,
        HIY"西域毛颖山"NOR,
        HIY"西域女儿国"NOR,
        HIY"西域盘丝岭"NOR,
        HIY"西域平顶山"NOR,
        HIY"西域麒麟山"NOR,
        HIY"西域钦法国"NOR,
        HIY"西域青龙山"NOR,
        HIY"西域双叉岭"NOR,
        HIY"西域天竺国"NOR,
        HIY"西域通天河"NOR,
        HIY"西域乌鸡国"NOR,
        HIY"西域小西天"NOR,
        HIY"西域隐雾山"NOR,
        HIY"西域玉华县"NOR,
        HIY"西域竹节山"NOR,
        HIY"西域朱紫国"NOR,
});
