#include <ansi.h>

inherit NPC;
#include "action.h"
#include "party.h"
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
(["id":"zuizui","title":"流动之云","name":"缀缀",]),
(["id":"zhword","title":"永远的漂泊人","name":"新星",]),
(["id":"danyingzi","title":"不灭的旅人","name":"丹辰子",]),
(["id":"fox","title":"岚的冒险者","name":"狐狸",]),
(["id":"cash","title":"雷的探检家","name":"银票",]),
(["id":"fen","title":"无宿渡世","name":"凌云",]),
(["id":"lting","title":"盗贼女僧侣","name":"風動梨花","sex":1,]),
(["id":"shazi","title":"苍瞳之虎","name":"轻狂",]),
(["id":"hotwing","title":"魔法战姬","name":"灼热天使",]),
(["id":"lavender","title":"魔性之美貌","name":"薰衣草","sex":1,]),
(["id":"bakangel","title":"圣之女骑士","name":"黑天使","sex":1,]),
(["id":"rains","title":"风疾黑刃","name":"小小勇士",]),
(["id":"guipu","title":"锐嘴黑鹫","name":"鬼仆",]),
(["id":"flyt","title":"瞳的女剑士","name":"安妮","sex":1,]),
(["id":"qing","title":"丽人之美貌","name":"秋意浓","sex":1,]),
(["id":"sos","title":"勇猛之鹰","name":"飞飞飞飞机",]),
(["id":"dings","title":"光之旋律","name":"鸭蛋",]),
(["id":"damenly","title":"神的闪光","name":"缺德居士",]),
(["id":"Qlbl","title":"绯色绘卷","name":"纨绔公子",]),
(["id":"xbd","title":"魔之探求者","name":"小不懂",]),
(["id":"game","title":"铁之豪腕","name":"游戏",]),
(["id":"amei","title":"美丽之风","name":"千山暮雪","sex":1,]),
(["id":"zbabla","title":"握溃之腕","name":"逍遥快乐",]),
(["id":"lunar","title":"风之女神","name":"雪梅","sex":1,]),
(["id":"yoyo","title":"暗黑魔力之块","name":"悠游",]),
(["id":"snowfly","title":"气力公主","name":"雪花飘","sex":1,]),
(["id":"wto","title":"恶魔的肉壁","name":"大伯流体欧",]),
(["id":"hadis","title":"正义之盾","name":"哈迪斯",]),
(["id":"angel","title":"弱者的守护人","name":"绯村刀心",]),
(["id":"zohu","title":"神秘的光辉","name":"雷骆",]),
(["id":"dfei","title":"神的左脑","name":"大飞",]),
(["id":"bakangel","title":"恶魔的传道女","name":"黑天使","sex":1,]),
(["id":"woodtian","title":"神的左脑","name":"我爱你美女",]),
(["id":"kjhojin","title":"恶魔的新娘","name":"水灵儿","sex":1,]),
(["id":"thill","title":"恶神的使仆","name":"西门子",]),
(["id":"dido","title":"圣瞳","name":"横喇嘛",]),
(["id":"cold","title":"天使恋人","name":"无情",]),
(["id":"scan","title":"将一切献给神","name":"精英六号",]),
(["id":"lubinh","title":"看不见的波","name":"小白兔",]),
(["id":"lightning","title":"恶魔的小偷","name":"渡闪",]),
(["id":"xiaomei","title":"女神的微笑","name":"小美","sex":1,]),
(["id":"dldi","title":"黑色爪刃","name":"大理义工",]),
(["id":"mafan","title":"正义之指","name":"麻烦",]),
(["id":"hailoo","title":"暗黑魔女","name":"蝶舞翩翩","sex":1,]),
(["id":"bingxueer","title":"圣魔女","name":"冰雪儿","sex":1,]),
(["id":"caree","title":"狂乱女神","name":"心语妹妹","sex":1,]),
(["id":"damenl","title":"绯色骑士","name":"想钱想发疯",]),
(["id":"xiaotian","title":"空中飞舞的绵毛","name":"啸天",]),
(["id":"waaas","title":"恶染魔姬","name":"蓉儿","sex":1,]),
(["id":"dbabla","title":"流浪者","name":"地邪",]),
(["id":"lyf","title":"斗影少女","name":"龙吟凤","sex":1,]),
(["id":"loveyqh","title":"圣之魔法师","name":"水手",]),
(["id":"lovefox","title":"剑女神","name":"怜星","sex":1,]),
(["id":"linda","title":"光之女骑士","name":"白晶晶","sex":1,]),
(["id":"lindy","title":"死神之妻","name":"慕容资","sex":1,]),
(["id":"lexy","title":"漂浮的树叶","name":"乐逍遥",]),
(["id":"laiyinhate","title":"流动的云","name":"莱因哈特",]),
(["id":"yzx","title":"永远的旅人","name":"星月浪子",]),
(["id":"xnh","title":"红虎","name":"阿虎",]),
(["id":"xjhjin","title":"白银女狼","name":"茜茜","sex":1,]),
(["id":"xiaoxuan","title":"黑银的微笑","name":"花泽泪",]),
(["id":"xdb","title":"疾风战士","name":"雪代巴",]),
(["id":"wumi","title":"风之刃","name":"呜咪",]),
(["id":"wukong","title":"盗贼战士","name":"齐天大圣",]),
(["id":"wishluck","title":"美丽之眸","name":"小赵敏","sex":1,]),
(["id":"winco","title":"惹人男丽","name":"云峰",]),
(["id":"wanxia","title":"月斩流星","name":"晚霞","sex":1,]),
(["id":"wanghu","title":"炎岚的闪电","name":"公孙大狼",]),
(["id":"waaa","title":"苍蓝旋风","name":"忘命",]),
(["id":"myth","title":"智惠的守门人","name":"慕容布",]),
(["id":"vov","title":"走路的辞典","name":"棒棒",]),
(["id":"tyywl","title":"百伤之男","name":"天野源五郎",]),
(["id":"ttss","title":"美装丽人","name":"冷清秋","sex":1,]),
(["id":"tianjun","title":"寂静之大岩","name":"流云",]),
(["id":"tcl","title":"邪神","name":"王牌",]),
(["id":"taotao","title":"恶魔之化身","name":"OhMyGod",]),
(["id":"sug","title":"纤细的指尖","name":"冷袖风","sex":1,]),
(["id":"sprite","title":"永久魔力","name":"小精灵",]),
(["id":"sony","title":"黑钢肌肉","name":"缘来",]),
(["id":"snq","title":"真实的探求者","name":"小小",]),
(["id":"snow","title":"精神力之源","name":"天下有雪","sex":1,]),
(["id":"smj","title":"不死身之男","name":"阎罗猪",]),
(["id":"smile","title":"死神之□","name":"繁星",]),
(["id":"sjmoxj","title":"神的右脑","name":"吟游诗人",]),
(["id":"siren","title":"邪的使者","name":"贵鬼",]),
(["id":"shuanger","title":"水映之月","name":"独孤霜","sex":1,]),
(["id":"shanc","title":"自由的少女","name":"衫菜","sex":1,]),
(["id":"sgy","title":"神罚使徒","name":"小铁",]),
(["id":"scare","title":"听到天声的人","name":"笑二郎",]),
(["id":"rui","title":"精素之魔操公主","name":"白雪飘零","sex":1,]),
(["id":"quanjia","title":"术少女","name":"泉笳","sex":1,]),
(["id":"qkry","title":"恶盗贼","name":"乾坤日月",]),
(["id":"qiuqiu","title":"速战速决","name":"球球",]),
(["id":"qazqaz","title":"黑骑士","name":"王怜花",]),
(["id":"pxf","title":"死神的保镖","name":"木风",]),
(["id":"pcgame","title":"暗黑之战神","name":"风针",]),
(["id":"papaya","title":"破坏王","name":"阿瓜",]),
(["id":"orange","title":"狂乱女神","name":"桔子","sex":1,]),
(["id":"ooo","title":"光容老将","name":"倾城之恋",]),
(["id":"only","title":"善良的不败斗士","name":"情瘤感菌",]),
(["id":"nvnv","title":"光之骑士","name":"冬冬",]),
(["id":"npc","title":"爱的传导者","name":"小美人","sex":1,]),
(["id":"name","title":"邪战士","name":"直升机",]),
(["id":"mzlm","title":"幸福使者","name":"啦啦",]),
(["id":"marine","title":"听到天声的人","name":"刁钻古怪",]),
(["id":"means","title":"狂气的贤者","name":"意思",]),
(["id":"miean","title":"无光辉的指尖","name":"灭黯",]),
(["id":"mingyang","title":"清魔的使者","name":"名扬",]),
(["id":"mini","title":"白色魔者","name":"本妮",]),
(["id":"mmm","title":"暗黑之鹰","name":"九剑一痴",]),
(["id":"mrf","title":"暗黑街的支配者","name":"慕容峰",]),
(["id":"mryh","title":"寂静的暗杀者","name":"移花",]),
(["id":"myboy","title":"大盗贼","name":"晴天的雨",]),
(["id":"mygirl","title":"黑光蜘蛛","name":"邵四","sex":1,]),
(["id":"lang","title":"恶魔天才","name":"浪翻云",]),
(["id":"langer","title":"狂乱之头脑","name":"本浪",]),
(["id":"legs","title":"魔法女剑士","name":"碧玉纤足","sex":1,]),
(["id":"lbxx","title":"清魔的使者","name":"蜡笔小新",]),
(["id":"lengxin","title":"光之骑士","name":"冷心",]),
(["id":"ling","title":"白色女导师","name":"灵儿","sex":1,]),
(["id":"ljgbook","title":"死亡公主","name":"灵鹫","sex":1,]),
(["id":"lkdd","title":"魅力战士","name":"百变星君",]),
(["id":"kara","title":"幻惑之女魔法师","name":"卡拉","sex":1,]),
(["id":"keeny","title":"男舞者","name":"秋政",]),
(["id":"keyboard","title":"箭之达人","name":"本键",]),
(["id":"kgb","title":"永远的(通缉犯)","name":"江湖小二",]),
(["id":"killman","title":"采花小贼","name":"难免的钱袋",]),
(["id":"jad","title":"灼热盗贼","name":"江东",]),
(["id":"jianxin","title":"深红的牧师","name":"心太",]),
(["id":"jxy","title":"敏捷之贵族","name":"肖岳",]),
(["id":"icefox","title":"愚者的王族","name":"冰狐",]),
(["id":"hadis","title":"亡灵裁判","name":"哈迪斯",]),
(["id":"hechuan","title":"赤色流星","name":"华英雄",]),
(["id":"hehaia","title":"神族使者","name":"任横行",]),
(["id":"himura","title":"亡灵法师","name":"脉剑",]),
(["id":"honda","title":"鸟人剑士","name":"本田",]),
(["id":"huakai","title":"小狼人","name":"花落花开",]),
(["id":"hylijun","title":"狼人王","name":"机器猫",]),
(["id":"hxt","title":"精灵战士","name":"草纸一疤",]),
(["id":"huihui","title":"精灵魔法使","name":"玄慕",]),
(["id":"gameking","title":"精灵箭士","name":"游戏之王",]),
(["id":"gaoc","title":"精灵长老","name":"高昌",]),
(["id":"gmxy","title":"精灵杀手","name":"消魂",]),
(["id":"grape","title":"黑暗精灵","name":"绿豆汤",]),
(["id":"green","title":"杀手公会使者","name":"红叶风",]),
(["id":"fadai","title":"火元素使者","name":"发呆",]),
(["id":"fall","title":"圣城之明珠","name":"冷清秋","sex":1,]),
(["id":"fff","title":"气元素使者","name":"飞龙",]),
(["id":"ffs","title":"土元素使者","name":"地邪",]),
(["id":"fgy","title":"水元素使者","name":"方歌吟",]),
(["id":"flower","title":"爱之女神","name":"蝶恋花","sex":1,]),
(["id":"foryou","title":"精灵女公主","name":"如诗","sex":1,]),
(["id":"foxzzz","title":"黑暗精灵女","name":"雪雁","sex":1,]),
(["id":"frfr","title":"魔族武士","name":"呼噜",]),
(["id":"ftoiloveyou","title":"神之牧师","name":"雪中情圣",]),
(["id":"fury","title":"情色的牧师","name":"清平乐",]),
(["id":"fusheng","title":"破坏神之牧师","name":"本.拉登",]),
(["id":"eddie","title":"纯情之瞳","name":"珞珈混混","sex":1,]),
(["id":"ehuan","title":"魔族女战士","name":"静环","sex":1,]),
(["id":"enjoy","title":"飞天游侠","name":"休闲",]),
(["id":"eric","title":"圣骑士","name":"岳超",]),
(["id":"dairun","title":"魔骑士","name":"代天",]),
(["id":"dali","title":"精灵杀手","name":"难免",]),
(["id":"datank","title":"荣光之骑士","name":"大坦克",]),
(["id":"dhxy","title":"自由骑士","name":"大话西游",]),
(["id":"digu","title":"火之流星","name":"童养媳",]),
(["id":"dldi","title":"武士王","name":"大理义工",]),
(["id":"dodo","title":"骑士统师","name":"没品上人",]),
(["id":"donkey","title":"骑龙剑士","name":"驴子",]),
(["id":"duly","title":"龙骑士","name":"净阿",]),
(["id":"caiyi","title":"吸血鬼女盗贼","name":"彩衣","sex":1,]),
(["id":"camin","title":"无耻黑游侠","name":"笑天",]),
(["id":"chaosheng","title":"圣力之野蛮人","name":"潮生",]),
(["id":"cloud","title":"野蛮人之子","name":"云起",]),
(["id":"com","title":"银狼的野蛮人","name":"虫虫",]),
(["id":"cutlove","title":"野蛮人法师","name":"横刀",]),
(["id":"baggio","title":"野蛮之魔法使","name":"轩辕剑",]),
(["id":"baishi","title":"洞穴巨人之母","name":"冬月辛","sex":1,]),
(["id":"banana","title":"软泥怪物","name":"香蕉",]),
(["id":"baoer","title":"兽人","name":"贾宝玉",]),
(["id":"battlee","title":"食人魔女王","name":"薛婷","sex":1,]),
(["id":"bear","title":"木乃伊","name":"笑狂",]),
(["id":"bee","title":"美女牛头怪","name":"女王蜂","sex":1,]),
(["id":"bihu","title":"蜥蜴人","name":"壁虎",]),
(["id":"biluo","title":"情色之巫妖","name":"爱尔兰咖啡","sex":1,]),
(["id":"bird","title":"傀儡人公主","name":"蓝鸟","sex":1,]),
(["id":"bingxueer","title":"可爱的食尸鬼","name":"冰雪儿","sex":1,]),
(["id":"bmr","title":"娇艳之神怪","name":"雪儿","sex":1,]),
(["id":"budai","title":"元素人","name":"有来有去",]),
(["id":"bullet","title":"魔鬼骑士","name":"小鱼",]),
(["id":"admire","title":"食腐爬行者","name":"雾云",]),
(["id":"aka","title":"黑暗精灵","name":"阿卡",]),
(["id":"akan","title":"魔化兽人","name":"莫柯无量",]),
(["id":"amejio","title":"菜鸟魔法侍女","name":"娟娟","sex":1,]),
(["id":"amy","title":"黑夜之女杀手","name":"阿宝","sex":1,]),
(["id":"ant","title":"美丽之银魔导士","name":"不悔","sex":1,]),
(["id":"anran","title":"魔军司令","name":"我心黯然",]),
(["id":"aoe","title":"魔族长","name":"渡奥",]),
(["id":"axax","title":"魔剑使指挥官","name":"白玉京",])
});
void random_chat();
mixed get_auto_actions(string action);
void change_combat_mode(object me, int mode);


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
	k=random(17);
	sex=npc["sex"];
	set_name(npc["name"]+NOR,({ npc["id"] }));
	set("title",(order[random(13)])+(npc["title"])+NOR);
set("vendetta/authority",1);
	set("age",20+random(30));
        set("per",20+random(30));
if (sex)
set("gender", "女性" );
else set("gender", "男性" );
	set("combat_exp",5000000+random(20000000));
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
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
b=4000+random(4000);
a=6000+random(9000);
d=30+random(60);
set("str",d);
set("dex",d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
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

       i=200+random(500);
        e=200+random(500);
if (random(8)==0)
{
set("nickname",HIY"武功高超"NOR);
        set_skill("spells",650+random(300));
        set_skill("force",650+random(300));
	set_skill("unarmed",650+random(300));
	set_skill("sword",650+random(300));
	set_skill("club",650+random(300));
	set_skill("whip",650+random(300));
	set_skill("throwing",650+random(300));
	set_skill("parry",650+random(300));
        i=400+random(500);
        e=400+random(500);

}
else
if (random(8)==0)
{
set("nickname",HIY"武功超高"NOR);
        set_skill("spells",850+random(300));
        set_skill("force",850+random(300));
	set_skill("unarmed",850+random(300));
	set_skill("sword",850+random(300));
	set_skill("club",850+random(300));
	set_skill("whip",850+random(300));
	set_skill("throwing",850+random(300));
	set_skill("parry",850+random(300));
        i=600+random(500);
        e=600+random(500);

}
else
if (random(8)==0)
{
set("nickname",HIB"经验丰富"NOR);
set("combat_exp",50000000+random(48000000));
       i=300+random(500);
        e=300+random(500);

}
else
if (random(8)==0)
{
set("nickname",HIR"强大不死"NOR);
set("dex",300);
        set("jing",600000);
        set("max_jing",600000);
        set("eff_jing",600000);
        set("qi",600000);
        set("max_qi",600000);
        set("eff_qi",600000);
        set("neili",600000);
        set("max_neili",600000);
	set("combat_exp",10000000);
}
else
if (random(8)==0)
{
set("nickname",HIC"超级加强"NOR);
d=88+random(88);
set("str",d);
set("dex",30+d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
}
else
if (random(10)==0)
{
        i=600+random(500);
        e=600+random(500);

set("dex",300);
        set("jing",100000);
        set("max_jing",100000);
        set("eff_jing",100000);
        set("qi",100000);
        set("max_qi",100000);
        set("eff_qi",100000);
        set("neili",100000);
        set("max_neili",100000);
      set_skill("magic-unarmed", 650+random(300));
      set_skill("magic-sword", 650+random(300));
      set_skill("magic-ice", 650+random(200));
      set_skill("magic-water", 650+random(200));
      set_skill("magic-fire", 650+random(200));
      set_skill("magic-earth", 650+random(200));
      set_skill("magic-light", 650+random(200));
      set_skill("magic-dark", 650+random(200));
        set_skill("spells",650+random(300));
        set_skill("force",650+random(300));
	set_skill("unarmed",650+random(300));
	set_skill("sword",650+random(300));
	set_skill("club",650+random(300));
	set_skill("whip",650+random(300));
	set_skill("throwing",650+random(300));
	set_skill("parry",650+random(300));
set("nickname",HIC"完美无敌"NOR);
d=88+random(88);
set("str",d);
set("dex",30+d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
}
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
        this_object()->change_combat_mode();
set("chat_chance_combat", 100);
set("chat_msg_combat", get_auto_actions("perform"));
change_combat_mode(ob, 1);
        set("chat_chance", 30);
        set("chat_msg", ({
 (: command, "get all" :),
 (: random_move :),
                (: command, "get all" :),
//                (:random_chat:),
        }) );
        
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
		set("chat_chance_combat", 100);
		set("chat_msg_combat", get_auto_actions("perform"));
		set("jiali", 50);
		break;
	case 2:
		set("chat_chance_combat", 100);
		set("chat_msg_combat", get_auto_actions("perform1"));
		set("jiali", (int)query_skill("force") / 2);
		break;
	case 3:
		set("chat_chance_combat", 100);
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
					evaluate(msg[i]);
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



void unconcious()
{
    die();
}
void die()
{
int i,pot,exp;
	object killer,jla;
	exp= random(520)+100;
	pot= exp*2/3;
	if(!objectp(killer = query_temp("last_damage_from")))
	return;
if (userp(killer))
{
	if(objectp(killer = query_temp("last_damage_from")))
        	tell_object(killer,"你被奖励了\n"+chinese_number(exp)+"点实战经验\n"
		+chinese_number(pot)+"点潜能\n");
	killer->add("combat_exp",exp);
	killer->add("potential",pot);
             jla=new("/clone/box/gbox");
jla->move(environment(killer));
message_vision("$N找到了一个宝箱。\n",killer);
}
	::die();

return ;
}