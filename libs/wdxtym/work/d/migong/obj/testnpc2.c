#include <ansi.h>

inherit NPC;
#include "action2.h"
#include "party2.h"
mapping *menpai=({
(["mp":"wudang",]),
(["mp":"lingjiu",]),
(["mp":"taohua",]),
(["mp":"tiandihui",]),
(["mp":"mingjiao",]),
(["mp":"gumu",]),
(["mp":"huashan",]),
(["mp":"gaibang",]),
(["mp":"quanzhen",]),
(["mp":"dali",]),
(["mp":"tiezhang",]),
(["mp":"murong",]),
(["mp":"kunlun",]),
(["mp":"lingxiao",]),
(["mp":"wdjiao",]),
(["mp":"baituo",]),
(["mp":"emei",]),
(["mp":"xiaoyao",]),		
(["mp":"mizong",]),
(["mp":"xingxiu",]),
(["mp":"feitian",]),
(["mp":"shenlong",]),
(["mp":"tangmen",]),		
(["mp":"riyue",]),
(["mp":"mizong1",]),
(["mp":"shaolin",]),
(["mp":"riyue1",]),
(["mp":"jiuyin",]),
(["mp":"noname",])
});
string *ns = ({	"force",
		"dodge",
		"parry",
		"unarmed",
		"strike",
		"cuff",
		"finger",
		"claw",
		"hand",
		"leg",
		"sword",
		"blade",
		"whip",
		"hammer",
		"staff",
		"axe",
		"literate",
		"shenzhao-jing",
});
string *cmds = ({"wield", "unwield", "wear", "remove", "enable", "jifa", "prepare", "bei", "exert",
"yun", "perform", "yong", "enforce", "jiali"});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *data=({
(["id":"zuizui","title":"丐帮九袋长老","name":"缀缀 ",]),
(["id":"zhword","title":"三大门派掌门","name":"新星 ",]),
(["id":"danyingzi","title":"大理BUG","name":"丹辰子 ",]),
(["id":"fox","title":"老银狐","name":"狐狸 ",]),
(["id":"cash","title":"海洋最初第一","name":"银票 ",]),
(["id":"fen","title":"海洋黑暗左使","name":"凌云 ",]),
(["id":"lting","title":"翠蕊梨花阁梨花仙子","name":"風動梨花","sex":1,]),
(["id":"shazi","title":"风哥是我老大","name":"轻狂 ",]),
(["id":"hotwing","title":"大理镇南王府武将","name":"灼热天使 ",]),
(["id":"lavender","title":"都是真的","name":"薰衣草","sex":1,]),
(["id":"bakangel","title":"唐门第七代弟子","name":"黑天使","sex":1,]),
(["id":"rains","title":"华山派第十三代弟子","name":"小小勇士 ",]),
(["id":"guipu","title":"我是流氓我怕谁！！！","name":"鬼仆 ",]),
(["id":"flyt","title":"别欺负我老公啊","name":"安妮","sex":1,]),
(["id":"qing","title":"终南第一女侠","name":"秋意浓","sex":1,]),
(["id":"sos","title":"海洋总统","name":"飞飞飞飞机 ",]),
(["id":"dings","title":"只发呆不做事","name":"鸭蛋 ",]),
(["id":"damenly","title":"我就是最近杀飞机的一毛不拔","name":"缺德居士 ",]),
(["id":"Qlbl","title":"五毒教长老","name":"纨绔公子 ",]),
(["id":"xbd","title":"海洋第一","name":"小不懂 ",]),
(["id":"game","title":"莫思身外无穷事且尽生前有限杯","name":"游戏 ",]),
(["id":"amei","title":"五毒教长老","name":"千山暮雪","sex":1,]),
(["id":"zbabla","title":"我爱虫宝宝","name":"逍遥快乐 ",]),
(["id":"lunar","title":"桃花岛第二代弟子","name":"雪梅","sex":1,]),
(["id":"yoyo","title":"桃花岛第二代弟子","name":"悠游 ",]),
(["id":"snowfly","title":"我要我们在一起","name":"雪花飘","sex":1,]),
(["id":"wto","title":"铁掌帮第十五代弟子","name":"大伯流体欧 ",]),
(["id":"hadis","title":"铁掌帮第十五代弟子","name":"哈迪斯 ",]),
(["id":"angel","title":"【飞天御剑流】第三十七代掌门人","name":"绯村刀心 ",]),
(["id":"zohu","title":"听说雷骆被雷打中了","name":"雷骆 ",]),
(["id":"dfei","title":"逍遥派护法使者","name":"大飞 ",]),
(["id":"bakangel","title":"唐门第七代弟子","name":"黑天使","sex":1,]),
(["id":"woodtian","title":"我的帅惊动了十六大和党中央","name":"我爱你美女 ",]),
(["id":"kjhojin","title":"唐门第七代弟子","name":"水灵儿","sex":1,]),
(["id":"thill","title":"念密宗不动明王真言","name":"西门子 ",]),
(["id":"dido","title":"幻影旅团ヒソカ","name":"横喇嘛 ",]),
(["id":"cold","title":"宝箱里发出一阵金光","name":"无情 ",]),
(["id":"scan","title":"海洋头号丹神","name":"精英六号 ",]),
(["id":"lubinh","title":"一百年前，没有你，也没有我","name":"小白兔 ",]),
(["id":"lightning","title":"少林派第三十五代弟子","name":"渡闪 ",]),
(["id":"xiaomei","title":"武当派第二代弟子","name":"小美","sex":1,]),
(["id":"dldi","title":"大理镇南王府武将","name":"大理义工 ",]),
(["id":"mafan","title":"逍遥派护法使者","name":"麻烦 ",]),
(["id":"hailoo","title":"全真教第二代弟子","name":"蝶舞翩翩","sex":1,]),
(["id":"bingxueer","title":"将无聊进行到底","name":"冰雪儿","sex":1,]),
(["id":"caree","title":"云龙门第三代弟子","name":"心语妹妹","sex":1,]),
(["id":"damenl","title":"这年头","name":"想钱想发疯 ",]),
(["id":"xiaotian","title":"通缉犯许郝被啸天就地正法了","name":"啸天 ",]),
(["id":"waaas","title":"海洋新一代丹神","name":"蓉儿","sex":1,]),
(["id":"dbabla","title":"五毒老妖","name":"地邪 ",]),
(["id":"lyf","title":"天堂有路你不走呀","name":"龙吟凤","sex":1,]),
(["id":"loveyqh","title":"华山派第十四代弟子","name":"水手 ",]),
(["id":"lovefox","title":"轻紫阁","name":"怜星","sex":1,]),
(["id":"linda","title":"穿好，觉得自己还挺美的...","name":"白晶晶","sex":1,]),
(["id":"lindy","title":"天之羽","name":"慕容资","sex":1,]),
(["id":"lexy","title":"华山派第十四代弟子","name":"乐逍遥 ",]),
(["id":"laiyinhate","title":"幻影旅团团长","name":"莱因哈特 ",]),
(["id":"yzx","title":"那一剑的风情","name":"星月浪子 ",]),
(["id":"xnh","title":"雪山寺掌门大弟子","name":"阿虎 ",]),
(["id":"xjhjin","title":"逍遥派弟子","name":"茜茜","sex":1,]),
(["id":"xiaoxuan","title":"你的「sk」进步了！","name":"花泽泪 ",]),
(["id":"xdb","title":"华山弟子","name":"雪代巴 ",]),
(["id":"wumi","title":"漂亮的回旋踢","name":"呜咪 ",]),
(["id":"wukong","title":"姑苏慕容","name":"齐天大圣 ",]),
(["id":"wishluck","title":"中华圣朝外交部长","name":"小赵敏","sex":1,]),
(["id":"winco","title":"花开花落两不知箫声袅袅绕桃花","name":"云峰 ",]),
(["id":"wanxia","title":"清风明月本无价近水远山皆有情","name":"晚霞","sex":1,]),
(["id":"wanghu","title":"今有佳人公孙氏一舞剑器动四方","name":"公孙大狼 ",]),
(["id":"waaa","title":"问世间情为何物","name":"忘命 ",]),
(["id":"myth","title":"姑苏慕容第二代弟子","name":"慕容布 ",]),
(["id":"vov","title":"玫瑰天使^_^","name":"棒棒 ",]),
(["id":"tyywl","title":"白驼山派第二代弟子","name":"天野源五郎 ",]),
(["id":"ttss","title":"正牌无敌唐伯虎","name":"冷清秋","sex":1,]),
(["id":"tianjun","title":"不上高山不临深溪！","name":"流云 ",]),
(["id":"tcl","title":"雪山派俗家弟子","name":"王牌 ",]),
(["id":"taotao","title":"白驼山派第二代弟子","name":"OhMyGod ",]),
(["id":"sug","title":"青裙缟袂谁家女","name":"冷袖风","sex":1,]),
(["id":"sprite","title":"古墓派第四代弟子","name":"小精灵 ",]),
(["id":"sony","title":"武当派第二代弟子","name":"缘来 ",]),
(["id":"snq","title":"凌霄城城主","name":"小小 ",]),
(["id":"snow","title":"乞讨为生","name":"天下有雪","sex":1,]),
(["id":"smj","title":"要 exp","name":"阎罗猪 ",]),
(["id":"smile","title":"饿了我","name":"繁星 ",]),
(["id":"sjmoxj","title":"活佛","name":"吟游诗人 ",]),
(["id":"siren","title":"正大光明","name":"贵鬼 ",]),
(["id":"shuanger","title":"飞天小龙女","name":"独孤霜","sex":1,]),
(["id":"shanc","title":"灵鹫宫第二代弟子","name":"衫菜","sex":1,]),
(["id":"sgy","title":"法王","name":"小铁 ",]),
(["id":"scare","title":"我爱 陈超","name":"笑二郎 ",]),
(["id":"rui","title":"Amy的军团 －将军","name":"白雪飘零","sex":1,]),
(["id":"quanjia","title":"橘子香水","name":"泉笳","sex":1,]),
(["id":"qkry","title":"日月神教任教主亲传弟子","name":"乾坤日月 ",]),
(["id":"qiuqiu","title":"丐帮第十九代弟子","name":"球球 ",]),
(["id":"qazqaz","title":"将堕落进行到底","name":"王怜花 ",]),
(["id":"pxf","title":"~_______~","name":"木风 ",]),
(["id":"pcgame","title":"逍遥派护法使者","name":"风针 ",]),
(["id":"papaya","title":"海洋菜园帮帮主 ","name":"阿瓜 ",]),
(["id":"orange","title":"判师了","name":"桔子","sex":1,]),
(["id":"ooo","title":"现任HY流氓老大","name":"倾城之恋 ",]),
(["id":"only","title":"虫儿乖乖","name":"情瘤感菌 ",]),
(["id":"nvnv","title":"新一代路盲","name":"冬冬 ",]),
(["id":"npc","title":"全真教第二代弟子","name":"小美人","sex":1,]),
(["id":"name","title":"极品丑男","name":"直升机 ",]),
(["id":"mzlm","title":"嘛弥嘛弥哄","name":"啦啦 ",]),
(["id":"marine","title":"幻影旅团☆シズク","name":"刁钻古怪 ",]),
(["id":"means","title":"铁掌帮上官帮主弟子","name":"意思 ",]),
(["id":"miean","title":"无奈的我没有为海洋重开出钱","name":"灭黯 ",]),
(["id":"mingyang","title":"桃花快剑","name":"名扬 ",]),
(["id":"mini","title":"大理段家第十七代弟子","name":"本妮 ",]),
(["id":"mmm","title":"机器人中请不要和me说话","name":"九剑一痴 ",]),
(["id":"mrf","title":"姑苏慕容第三代弟子","name":"慕容峰 ",]),
(["id":"mryh","title":"活佛","name":"移花 ",]),
(["id":"myboy","title":"★烧★☆菜★Ω收钱","name":"晴天的雨 ",]),
(["id":"mygirl","title":"小月姑娘","name":"邵四","sex":1,]),
(["id":"lang","title":"对酒当歌，人生几何","name":"浪翻云 ",]),
(["id":"langer","title":"大理镇南王府皇卿","name":"本浪 ",]),
(["id":"legs","title":"选你所爱 爱你所选","name":"碧玉纤足","sex":1,]),
(["id":"lbxx","title":"雪山派俗家弟子","name":"蜡笔小新 ",]),
(["id":"lengxin","title":"五行引导师","name":"冷心 ",]),
(["id":"ling","title":"全真教第二代弟子","name":"灵儿","sex":1,]),
(["id":"ljgbook","title":" 你伤心问道：「这是为什么啊？」","name":"灵鹫","sex":1,]),
(["id":"lkdd","title":"你生得呲牙咧嘴黑如锅底奇丑无比","name":"百变星君 ",]),
(["id":"kara","title":"与往事干杯","name":"卡拉","sex":1,]),
(["id":"keeny","title":"慢慢来，不要急！练了也白练！","name":"秋政 ",]),
(["id":"keyboard","title":"★机器人★★中★","name":"本键 ",]),
(["id":"kgb","title":"永远的(通缉犯)","name":"江湖小二 ",]),
(["id":"killman","title":"采花小贼","name":"难免的钱袋 ",]),
(["id":"jad","title":"海洋麻雀楼之大当家","name":"江东 ",]),
(["id":"jianxin","title":"心太的道馆","name":"心太 ",]),
(["id":"jxy","title":"华山派第十三代弟子","name":"肖岳 ",]),
(["id":"icefox","title":"好久没上了","name":"冰狐 ",]),
(["id":"hadis","title":"铁掌帮第十五代弟子","name":"哈迪斯 ",]),
(["id":"hechuan","title":"丐帮九袋长老","name":"华英雄 ",]),
(["id":"hehaia","title":"明教使者","name":"任横行 ",]),
(["id":"himura","title":"大理段家第十七代弟子","name":"脉剑 ",]),
(["id":"honda","title":"欢迎光临www.fivekids.com","name":"本田 ",]),
(["id":"huakai","title":"凌霄城第七代弟子","name":"花落花开 ",]),
(["id":"hylijun","title":"华山派第十三代弟子","name":"机器猫 ",]),
(["id":"hxt","title":"圣火加油站","name":"草纸一疤 ",]),
(["id":"huihui","title":"少林派第三十六代弟","name":"玄慕 ",]),
(["id":"gameking","title":"无忧仙境　第二代弟子","name":"游戏之王 ",]),
(["id":"gaoc","title":"高昌迷宫主人","name":"高昌 ",]),
(["id":"gmxy","title":"法王","name":"消魂 ",]),
(["id":"grape","title":"钦赐一等鹿鼎公","name":"绿豆汤 ",]),
(["id":"green","title":"多情自古空余恨","name":"红叶风 ",]),
(["id":"fadai","title":"一个人的追逐","name":"发呆 ",]),
(["id":"fall","title":"钦赐一等鹿鼎公","name":"冷清秋","sex":1,]),
(["id":"fff","title":"苦命的孩子","name":"飞龙 ",]),
(["id":"ffs","title":"法王","name":"地邪 ",]),
(["id":"fgy","title":"连城剑","name":"方歌吟 ",]),
(["id":"flower","title":"大理镇南王府家奴","name":"蝶恋花","sex":1,]),
(["id":"foryou","title":"为君而狂","name":"如诗","sex":1,]),
(["id":"foxzzz","title":"钦赐一等鹿鼎公","name":"雪雁","sex":1,]),
(["id":"frfr","title":"丐帮九袋长老","name":"呼噜 ",]),
(["id":"ftoiloveyou","title":"wait me xue yitiantulong","name":"雪中情圣 ",]),
(["id":"fury","title":"一道闪电从天而降砸到你头上","name":"清平乐 ",]),
(["id":"fusheng","title":"看黄沙卷起千层浪一笑不能忘","name":"本.拉登 ",]),
(["id":"eddie","title":"Amy的大米军团三团团长","name":"珞珈混混","sex":1,]),
(["id":"ehuan","title":"负神 no look","name":"静环","sex":1,]),
(["id":"enjoy","title":"色佛","name":"休闲 ",]),
(["id":"eric","title":"逍遥派第四代弟子","name":"岳超 ",]),
(["id":"dairun","title":"钦赐一等鹿鼎公","name":"代天 ",]),
(["id":"dali","title":"萝卜青菜猪","name":"难免 ",]),
(["id":"datank","title":"昆仑派第六代弟子","name":"大坦克 ",]),
(["id":"dhxy","title":"【上次死因】被上官巡捕杀死","name":"大话西游 ",]),
(["id":"digu","title":"终于过上好日子，用上宽带了","name":"童养媳 ",]),
(["id":"dldi","title":"大理镇南王府武将","name":"大理义工 ",]),
(["id":"dodo","title":"孤魂野鬼","name":"没品上人 ",]),
(["id":"donkey","title":"唐门第七代弟子","name":"驴子 ",]),
(["id":"duly","title":"采花小贼","name":"净阿 ",]),
(["id":"caiyi","title":"逍遥派护法使者","name":"彩衣","sex":1,]),
(["id":"camin","title":"采花小贼","name":"笑天 ",]),
(["id":"chaosheng","title":"Diablo12 www.love214.com","name":"潮生 ",]),
(["id":"cloud","title":"华山派第十三代弟子","name":"云起 ",]),
(["id":"com","title":"千里思君莫相忘","name":"虫虫 ",]),
(["id":"cutlove","title":"白驼山派第二代弟子","name":"横刀 ",]),
(["id":"baggio","title":"百里潜龙","name":"轩辕剑 ",]),
(["id":"baishi","title":"mely的专职秘书","name":"冬月辛","sex":1,]),
(["id":"banana","title":"星宿派第三代弟子","name":"香蕉 ",]),
(["id":"baoer","title":"华山派第十三代弟子","name":"贾宝玉 ",]),
(["id":"battlee","title":"【神古活心流】代师傅","name":"薛婷","sex":1,]),
(["id":"bear","title":"挂挂机聊聊天","name":"笑狂 ",]),
(["id":"bee","title":"游戏人生","name":"女王蜂","sex":1,]),
(["id":"bihu","title":"小恐龙","name":"壁虎 ",]),
(["id":"biluo","title":"右丞相","name":"爱尔兰咖啡","sex":1,]),
(["id":"bird","title":"明教使者","name":"蓝鸟","sex":1,]),
(["id":"bingxueer","title":"将无聊进行到底","name":"冰雪儿","sex":1,]),
(["id":"bmr","title":"姑苏","name":"雪儿","sex":1,]),
(["id":"budai","title":"姑苏慕容第四代弟子","name":"有来有去 ",]),
(["id":"bullet","title":"我要! 我要嘛 ～～～～","name":"小鱼 ",]),
(["id":"admire","title":"雾中云中难寻我踪","name":"雾云 ",]),
(["id":"aka","title":"九阴狂中","name":"阿卡 ",]),
(["id":"akan","title":"小善人","name":"莫柯无量 ",]),
(["id":"amejio","title":"桃花岛第二代弟子","name":"娟娟","sex":1,]),
(["id":"amy","title":"幼年天下第一","name":"阿宝","sex":1,]),
(["id":"ant","title":"是谁在耳边说爱你永不变","name":"不悔","sex":1,]),
(["id":"anran","title":"古墓之风云乍起","name":"我心黯然 ",]),
(["id":"aoe","title":"放下屠刀 立地成佛","name":"渡奥 ",]),
(["id":"axax","title":"愿随夫子天坛上 闲与仙人扫落花","name":"白玉京",])
});
void random_chat();
mixed get_auto_actions(string action);
void change_combat_mode(object me, int mode);
int ask_job();
int ask_job2();
void create()
{
	mapping npc,mp,j;
	mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;
	string sex;
	object ob, weapon;
	int i,k,a,b,c,d,e,f,temp;
	npc=data[random(sizeof(data))];
	mp=menpai[random(sizeof(menpai))];
	j=ps[random(sizeof(ps))];
ob=this_object();
	k=random(29);
	//k=11;
	sex=npc["sex"];
	set_name(npc["name"]+NOR,({ npc["id"] }));
	set("title",(order[random(13)])+(npc["title"])+NOR);
set("nick","测试员");
set("vendetta/authority",1);
	set("age",20+random(30));
        set("per",20+random(30));
if (sex)
set("gender", "女性" );
else set("gender", "男性" );
	set("combat_exp",3000000+random(20000000));
set("skill_public",1);
set("pubmaster",1);
	set_temp("apply/attack",50);
	set_temp("apply/defense",100);
	set_temp("apply/armor",550);
	set_temp("apply/damage",50);
	set("max_force",2000);
	set_skill("unarmed",200);
	set_skill("sword",200);
	set_skill("club",200);
	set_skill("whip",200);
	set_skill("throwing",200);
	set_skill("parry",200);
	set_skill("dodge",200);
set("no_get",1);
        set("szj/passed",1);
        set("double_attack",1);
        set("breakup", 1);
        set("szj/over200", 1);
        set("jiuyin/full", 1);
        set("jiuyin/shang", 1);
        set("jiuyin/xia", 1);
b=2000+random(4000);
a=3000+random(9000);
d=20+random(60);
set("str",d);
set("dex",100);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
        set("inquiry", ([
            "qixue" : (: ask_job() :),
            "气血" : (: ask_job() :),
            "参考" : (: ask_job2() :),
            "skill" : (: ask_job2() :),
        ]) );
        set("jing",b);
        set("max_jing",b);
set("eff_jing",b);
        set("neili",a);
        set("max_neili",a);
	this_object()->set("party",ps[k]["party"]);
	this_object()->set_skills(ps[k]["skills"]);
	this_object()->set_skill_map(ps[k]["skill_map"]);
	this_object()->set_skill_prepare(ps[k]["skill_prepare"]);
        i=200+random(500);
        e=200+random(500);
	for (k = 0; k < sizeof(ns); k++)
		this_object()->set_skill(ns[k], i);

		this_object()->set_skill("literate",i);
        this_object()->set_skill("shenzhao-jing",e);
if (mapp(skill_status = this_object()->query_skills()))//判断自己是否有功夫，如有将用这个函数全部删除
{
skill_status = this_object()->query_skills();
sname = keys(skill_status);//传回所有自己的功夫阵列

temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
this_object()->set_skill(sname[i],e);//删除自己所有功夫
}
set_skill("force", e);
        this_object()->change_combat_mode();
set("chat_chance_combat", 80);
set("chat_msg_combat", get_auto_actions("perform"));
change_combat_mode(ob, 1);
        
f=1+random(8);        
	setup();

	if (ob->query("gender")=="女性")
	{
	carry_object("/clone/cloth/female"+f+"-cloth")->wear();
	carry_object("/clone/cloth/female-shoe")->wear();
	}
else {
	carry_object("/clone/cloth/male"+f+"-cloth")->wear();
	carry_object("/clone/cloth/male-shoe")->wear();
}        
        if (stringp(ob->query_skill_mapped("sword"))) 
	carry_object(__DIR__"weapon/sword")->wield();
	if (stringp(ob->query_skill_mapped("blade"))) 
	carry_object(__DIR__"weapon/dao")->wield();
	if (stringp(ob->query_skill_mapped("whip"))) 
	carry_object(__DIR__"weapon/bian")->wield();
	if (stringp(ob->query_skill_mapped("hammer"))) 
	carry_object(__DIR__"weapon/hammer")->wield();
	if (stringp(ob->query_skill_mapped("staff"))) 
	carry_object(__DIR__"weapon/ban")->wield();
	if (stringp(ob->query_skill_mapped("axe"))) 
	carry_object(__DIR__"weapon/axe")->wield();
	if (stringp(ob->query_skill_mapped("throwing"))) 
	carry_object(__DIR__"weapon/throwing")->wield();

	add_money("silver",50+random(50));
}
       

mixed get_auto_actions(string action)
{
	int i, flag = 0;

	for (i = 0; i < sizeof(pfm); i++)
		if (pfm[i]["party"] == query("party")) {
			flag = 1;
			break;
		}
	if (!flag)
		return ({ });
	if (arrayp(pfm[i][action]))
		return pfm[i][action];
	else
		return ({ });
}

void change_combat_mode(object me, int mode)
{
	switch (mode) {
	case 0:
		delete("chat_chance_combat");
		delete("chat_msg_combat");
		set("jiali", 1);
		break;
	case 1:
		set("chat_chance_combat", 80);
		set("chat_msg_combat", get_auto_actions("perform"));
		set("jiali", 50);
		break;
	case 2:
		set("chat_chance_combat", 80);
		set("chat_msg_combat", get_auto_actions("perform1"));
		set("jiali", (int)query_skill("force") / 2);
		break;
	case 3:
		set("chat_chance_combat", 80);
		set("chat_msg_combat", get_auto_actions("perform2"));
		set("jiali", 1);
		break;
	default:
		set("chat_chance_combat", 80);
		set("chat_msg_combat", get_auto_actions("perform"));
		set("jiali", 50);
		return;
	}
	set("combat_mode", mode);
//	me->set("guard/status/combat_mode", mode);
}

void random_chat()
{
  string *e,str="";
   int i;
   object npc,*inv;
if (!environment(this_object()))
   return;
   inv=all_inventory(environment(this_object()));
	if(!sizeof(inv))	return;
 
   e = sort_array(EMOTE_D->query_all_emote(), 1);
   str=e[random(sizeof(e))];
   command(str+" "+inv[random(sizeof(inv))]->query("id"));
   set("answer",str);  
   return;
}

int chat()
{
	int i, ratio, chance, rnd, flag = 0;
	string *msg, *emotes, cmd;
	object *inv, *killer;

	if (!is_busy() 
	&& living(this_object())
	&& environment(this_object()) )
	{
		if (arrayp(msg = get_auto_actions("powerup")))
			for (i = 0; i < sizeof(msg); i++)
				if (functionp(msg[i]))
if (msg[i]) evaluate(msg[i]);
	}


	if (query("neili") > 100 && query("max_neili") > 200 && !is_busy()
	&& living(this_object())
	&& environment(this_object()) 
	) {
		if (query("eff_jing") && query("jing") * 100 / query("eff_jing") <= 80)
			command("exert regenerate");

		if (query("eff_qi") && query("qi") >= 0 && query("qi") * 100 / query("eff_qi") <= 80)
			command("exert recover");

		if (query("eff_qi") && query("qi") >= 0
		&& query("max_qi") && !is_fighting() && !query("mute")
		&& query_skill_mapped("force")
		&& query("eff_qi") < query("max_qi")
		&& query("eff_qi") >= query("max_qi") / 3)
			command("exert heal");

		if (query("max_neili")
		&& query("neili") * 100 / query("max_neili") <= 80
		&& !is_fighting()
		&& query_skill_mapped("force")) {
			i = 1 + (int)query_skill("force") / 15 * (1 + (int)query_skill("force") / 100);
			command(sprintf("dazuo %d", i));
		}

	}

	if( !chance = (int)query(is_fighting()? "chat_chance_combat": "chat_chance") )
		return 0;

	if( arrayp(msg = query(is_fighting()? "chat_msg_combat": "chat_msg"))) {
		if( query_temp("is_unconcious") ) return 0;
		if(!living(this_object()) ) return 0;
		if(!environment(this_object())  ) return 0;

		if( random(100) < chance ) {
			rnd = random(sizeof(msg));
			if( stringp(msg[rnd]) )
				say(msg[rnd]);
			else if( functionp(msg[rnd]) )
				return evaluate(msg[rnd]);
		}
		return 1;
	}

	return 1;
}


int do_copy(object me,int maxpot,int type)
{
        int j;
	mapping npc,mp;
	mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;
	string sex;
	object ob, weapon;
	int i,k,a,b,c,d,e,f,temp;
	npc=data[random(sizeof(data))];
	mp=menpai[random(sizeof(menpai))];


        ob = this_object();
if (!me->query_skill("force"))
i=10;
else      i=me->query_skill("force",1);
//        if(type==1)
//		i = i - random(20);
//		else  
//	    i = i +10+ random(10);
//        if( i < 100) i = 100;
        
        ob->set("combat_exp", (me->query("combat_exp")*3/4));
        
        ob->set_skill("force", i*3/4);
        ob->set_skill("sword", i*3/4);
        ob->set_skill("unarmed", i*3/4);
        ob->set_skill("cuff",  i*3/4);
	ob->set_skill("blade", i*3/4);
        ob->set_skill("dodge", i*3/4);
        ob->set_skill("parry", i*3/4);
        ob->set_skill("taiji-shengong", i);       
        ob->set_skill("wuxing-dun", i); 
//        ob->set_skill("shiren-jianfa", i); 
//        ob->set_skill("shiren-quanfa", i);         
        set_skill("taiji-shengong",i*1/2);
ob->set("jing",me->query("max_jing"));
ob->set("eff_jing",me->query("max_jing"));
ob->set("max_jing",me->query("max_jing"));
ob->set("qi",me->query("max_qi"));
ob->set("eff_qi",me->query("max_qi"));
ob->set("max_qi",me->query("max_qi"));
//ob->map_skill("unarmed", "shiren-quanfa");
//ob->map_skill("parry", "shiren-quanfa");
if (random(10)>8)
{
        ob->set_skill("force", i*3/4);
        ob->set_skill("sword", i*3/4);
        ob->set_skill("unarmed", i*3/4);
        ob->set_skill("cuff",  i*3/4);
	ob->set_skill("blade", i*3/4);
        ob->set_skill("dodge", i*3/4);
        ob->set_skill("parry", i*3/4);
//        ob->set_skill("shiren-jianfa", i); 
//        ob->set_skill("shiren-quanfa", i);         
}
        ob->set("eff_jingli", me->query("eff_jingli")*1/2); 
        ob->set("jiali", i/6);
	ob->set("max_qi",  me->query("qi")*2/3); 
        ob->set("eff_jingli", me->query("eff_jingli")*2/3); 
        ob->set("max_neili", me->query("max_neili")*2/3); 
        ob->set("jiali", i/10);
        if(type==3)
		{ob->set("max_qi",     me->query("qi")*2/3);
		 ob->set("max_neili",  me->query("max_neili")*2/3); 
		}
		if(type==2)
        ob->set("max_qi",     me->query("qi")*2/3); 
		ob->reincarnate(); 
        ob->set("qi",ob->query("max_qi")*2/3);
        ob->set("neili",ob->query("max_neili")*2/3);
        ob->set("qi",me->query("max_qi"));
        ob->set("eff_qi",me->query("max_qi"));
        ob->set("max_qi",me->query("max_qi"));        
        ob->set("neili",me->query("max_neili"));
        ob->set("max_neili",me->query("max_neili"));
        ob->set("jing",me->query("max_jing"));
        ob->set("eff_jing",me->query("max_jing"));
        ob->set("max_jing",me->query("max_jing"));
ob->set("str",me->query("str"));
ob->set("dex",me->query("dex")*2);
ob->set("con",me->query("str"));
	this_object()->set("party",ps[k]["party"]);
	this_object()->set_skills(ps[k]["skills"]);
	this_object()->set_skill_map(ps[k]["skill_map"]);
	this_object()->set_skill_prepare(ps[k]["skill_prepare"]);
        i=me->query_skill("force",1)*2/3;
        e=me->query_skill("force",1)*2/3;
	for (k = 0; k < sizeof(ns); k++)
		this_object()->set_skill(ns[k], i);

		this_object()->set_skill("literate",i);
        this_object()->set_skill("shenzhao-jing",e);
if (mapp(skill_status = this_object()->query_skills()))//判断自己是否有功夫，如有将用这个函数全部删除
{
skill_status = this_object()->query_skills();
sname = keys(skill_status);//传回所有自己的功夫阵列

temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
this_object()->set_skill(sname[i],e);//删除自己所有功夫
}
//        ob->set_skill("shiren-jianfa", i); 
//        ob->set_skill("shiren-quanfa", i);         
//ob->map_skill("unarmed", "shiren-quanfa");
//ob->map_skill("parry", "shiren-quanfa");

}
void unconcious()
{
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
        this_object()->clear_condition();
	command("hehe");
}

void die()
{
	unconcious();
}

int ask_job()
{

        object ob = this_player();
        object me = this_object();
me->clear_condition();
                command("say 气现在是" + me->query("qi") + "。气上限是 " + me->query("eff_qi") + "。");
//                command("nod" + me->query("id"));
                command("say 精现在是" + me->query("jing") + "。精上限是 " + me->query("eff_jing") + "。");
                return 1;
}
int ask_job2()
{
int maxpot;
        object ob = this_object();
        object me = this_player();
if (me->is_busy())
return 0;
maxpot=me->query_temp("maxpot")+10;
    command("say 参考" + me->query("name") + "武功!");
ob->do_copy(me,maxpot,2);
ob->clear_condition();
me->start_busy(12);
return 1;
}