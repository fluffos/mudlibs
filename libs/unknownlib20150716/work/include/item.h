// item.h

#include <armor.h>
#include <weapon.h>

#ifndef __ITEM__
#define __ITEM__

/*****************
   外部接口函数：
*****************/
// 创造一个物品，根据等级，出现武器的百分比
public varargs object create_obj(int level, int percent);
// 创造一个物品，根据任务和等级
public object create_task_obj(string task, int level);
// 创造一个物品，根据类型和等级
public object create_type_obj(string type, int level);
// 创造一个武器，根据类型和等级
public object create_weapon(string type, int level);
// 创造一个防具，根据类型和等级
public object create_armor(string type, int level);


/*****************
    内部函数：
*****************/
//赋予武器名字
private void set_weapon_name(object ob, string type, int level);
//赋予防具名字
private void set_armor_name(object ob, string type, int level);
//赋予武器属性
private void set_weapon_stats(object ob, int level);
//赋予防具属性
private void set_armor_stats(object ob, int level);
//检查type和level合法性 woa->武器还是防具
//type错误返回1 level错误返回2
private int do_legal(string type, int level, string woa);
//增加一个数量级别的属性
private void set_one_stats(string woa);
//增加属性到全局记录
private void save_to_stats(string type, int val);
//增加技能到全局记录
private void save_to_skill_stats(string type, int val);

//原型文件
mapping armor_dir = ([
	"CLOTH"		:	ARCHETYEP_DIR"armor/cloth",		//衣服
	"SKIRT"		:	ARCHETYEP_DIR"armor/skirt",		//长裙
	"HEAD"		:	ARCHETYEP_DIR"armor/head",		//头盔
	"NECK"		:	ARCHETYEP_DIR"armor/neck",		//项链
	"ARMOR"		:	ARCHETYEP_DIR"armor/armor",		//护甲
	"SURCOAT"	:	ARCHETYEP_DIR"armor/surcoat",		//披风
	"WAIST"		:	ARCHETYEP_DIR"armor/waist",		//护腰
	"WRISTS"	:	ARCHETYEP_DIR"armor/wrists",		//护腕
	"SHIELD"	:	ARCHETYEP_DIR"armor/shield",		//盾牌
	"FINGER"	:	ARCHETYEP_DIR"armor/finger",		//戒指
	"HANDS"		:	ARCHETYEP_DIR"armor/hands",		//手套
	"BOOTS"		:	ARCHETYEP_DIR"armor/boots",		//鞋子
]);
mapping weapon_dir = ([
	"AXE"		:	ARCHETYEP_DIR"weapon/axe",		//斧类
	"BLADE"		:	ARCHETYEP_DIR"weapon/blade",		//刀类
	"FORK"		:	ARCHETYEP_DIR"weapon/fork",		//叉类
	"HAMMER"	:	ARCHETYEP_DIR"weapon/hammer",		//锤类
	"MACE"		:	ARCHETYEP_DIR"weapon/mace",		//锏类
	"RAKE"		:	ARCHETYEP_DIR"weapon/rake",		//耙类
	"SWORD"		:	ARCHETYEP_DIR"weapon/sword",		//剑类
	"STAFF"		:	ARCHETYEP_DIR"weapon/staff",		//杖类
	"STICK"		:	ARCHETYEP_DIR"weapon/stick",		//棍类
	"WHIP"		:	ARCHETYEP_DIR"weapon/whip",		//鞭类
	"SPEAR"		:	ARCHETYEP_DIR"weapon/spear",		//枪类
]);
//基础防御
mapping armor_df_bas = ([
	"CLOTH"		:	PROP_CLOTH,		//衣服
	"SKIRT"		:	PROP_SKIRT,		//长裙
	"HEAD"		:	PROP_HEAD,		//头盔
	"NECK"		:	PROP_NECK,		//项链
	"ARMOR"		:	PROP_ARMOR,		//护甲
	"SURCOAT"	:	PROP_SURCOAT,		//披风
	"WAIST"		:	PROP_WAIST,		//护腰
	"WRISTS"	:	PROP_WRISTS,		//护腕
	"SHIELD"	:	PROP_SHIELD,		//盾牌
	"FINGER"	:	PROP_FINGER,		//戒指
	"HANDS"		:	PROP_HANDS,		//手套
	"BOOTS"		:	PROP_BOOTS,		//鞋子
]);
//基础伤害
mapping weapon_dam_bas = ([
	"AXE"		:	DEFAULT_DAMAGE,		//斧类
	"BLADE"		:	DEFAULT_DAMAGE,		//刀类
	"FORK"		:	DEFAULT_DAMAGE,		//叉类
	"HAMMER"	:	DEFAULT_DAMAGE,		//锤类
	"MACE"		:	DEFAULT_DAMAGE,		//锏类
	"RAKE"		:	DEFAULT_DAMAGE,		//耙类
	"SWORD"		:	DEFAULT_DAMAGE,		//剑类
	"STAFF"		:	DEFAULT_DAMAGE,		//杖类
	"STICK"		:	DEFAULT_DAMAGE,		//棍类
	"WHIP"		:	DEFAULT_DAMAGE,		//鞭类
	"SPEAR"		:	DEFAULT_DAMAGE,		//枪类
]);
//武器按类型的简略ID
mapping short_id_weapon = ([
	"AXE"		:	"fu",		//斧类
	"BLADE"		:	"dao",		//刀类
	"FORK"		:	"cha",		//叉类
	"HAMMER"	:	"chui",		//锤类
	"MACE"		:	"jian",		//锏类
	"RAKE"		:	"pa",		//耙类
	"SWORD"		:	"jian",		//剑类
	"STAFF"		:	"zhang",	//杖类
	"STICK"		:	"gun",		//棍类
	"WHIP"		:	"bian",		//鞭类
	"SPEAR"		:	"qiang",	//枪类
]);
//防具按类型的简略ID
mapping short_id_armor = ([
	"CLOTH"		:	"yi",		//衣服
	"SKIRT"		:	"qun",		//长裙
	"HEAD"		:	"kui",		//头盔
	"NECK"		:	"xiangliang",	//项链
	"ARMOR"		:	"jia",		//护甲
	"SURCOAT"	:	"pifeng",	//披风
	"WAIST"		:	"yaodai",	//护腰
	"WRISTS"	:	"huwan",	//护腕
	"SHIELD"	:	"dun",		//盾牌
	"FINGER"	:	"ring",		//戒指
	"HANDS"		:	"glove",	//手套
	"BOOTS"		:	"xue",		//鞋子
]);

//公共属性代号列表
string *public_stats_list = ({
	"str", 
	"dex", 
	"con", 
	"spi", 
	"int", 
	"cor", 
	"per", 
	"kar", 
	"attack", 
	"force", 
	"spells", 
	"dodge", 
	"RLC_force", 
	"RLC_mana", 
	"RLC_kee", 
	"RLC_sen", 
	"DF_force", 
	"DF_spells", 
	"RE_force", 
	"RE_spells", 
});
//武器属性代号列表
string *weapon_stats_list = ({
	"damage", 
	"min_damage", 
});
//防具属性代号列表
string *armor_stats_list = ({
	"armor",
});
//全部属性代号对应装备每提高一个等级所能增加的属性
mapping stats_list = ([
	"damage"	:	4,
	"min_damage"	:	1, 
	"armor"		:	1,
	"str"		:	1, 
	"dex"		:	1, 
	"con"		:	1, 
	"spi"		:	1, 
	"int"		:	1, 
	"cor"		:	1, 
	"per"		:	1, 
	"kar"		:	1, 
	"attack"	:	1, 
	"force"		:	1, 
	"spells"	:	1, 
	"dodge"		:	1, 
	"RLC_force"	:	1, 
	"RLC_mana"	:	1, 
	"RLC_kee"	:	1, 
	"RLC_sen"	:	1, 
	"DF_force"	:	1, 
	"DF_spells"	:	1, 
	"RE_force"	:	1, 
	"RE_spells"	:	1, 
]);
//技能代号列表
string *skill_list = ({
	"force", 
	"dodge", 
	"parry", 
	"spells", 
	"sword",
});
//装备名字
mapping name_list = ([
	"AXE"		:	
		([
			"车轮板斧"	:	"chelun axe",
			"金雀开山斧"	:	"jinque axe",
			"宣化板斧"	:	"xuanhua axe",
			"月牙斧"	:	"yueya axe",
			"八卦宣化斧"	:	"bagua axe",
			"凤头斧"	:	"fengtou axe",
			"金蘸斧"	:	"jinzhan axe",
			"加钢板斧"	:	"jiagang axe",
			"月牙开山斧"	:	"yueyakaishan axe",
			"青铜斧"	:	"qingtong axe",
			"宝花板斧"	:	"baohua axe",
			"渗金斧"	:	"shenjin axe",
			"日月加钢斧"	:	"riyu axe",
			"二龙宣化斧"	:	"erlong axe",
			"八卦开天斧"	:	"kaitian axe",
			"凤头金攥斧"	:	"fengtou axe",
			"短把青铜斧"	:	"duanba axe",
			"短把镔铁斧"	:	"bingtie axe",
		]),
	"BLADE"		:	
		([
			"金背大砍刀"	:	"jinbei blade", 
			"门扇大刀"	:	"menshan blade", 
			"齐凤朝阳刀"	:	"chaoyang blade",  
			"象鼻古月刀"	:	"guyue blade",  
			"砍山刀"	:	"kanshan blade",  
			"三尖两刃刀"	:	"sanjian blade",  
			"合扇板门刀"	:	"heshan blade", 
			"金背砍山刀"	:	"kanshan blade",  
			"雁翎刀"	:	"yanling blade",  
			"青铜刀"	:	"qingtong blade",  
			"丹凤刀"	:	"danfeng blade",  
			"板门红缨刀"	:	"hongying blade",  
			"锈绒刀"	:	"xiurong blade",  
			"七星摺花刀"	:	"qixing blade",  
			"虎牙刀"	:	"huya blade", 
			"九耳八环刀"	:	"bahuan blade",  
			"鱼鳞紫金刀"	:	"yulin blade",  
			"三叉鬼头刀"	:	"guitou blade",  
			"亮银刀"	:	"liangyin blade",  
			"电光刀"	:	"dianguang blade",  
			"七宝措金刀"	:	"cuojin blade",  
			"赤铜刀"	:	"chitong blade",  
			"劈水刀"	:	"pishui blade",  
			"青钢刀"	:	"qinggang blade", 
		]),
	"FORK"		:	
		([
			"五股烈焰叉"	:	"lieyan fork",  
			"九股托天叉"	:	"tuotian fork",   
			"三股亮银叉"	:	"liangyin fork",   
			"三股托天叉"	:	"tuotian fork",   
			"五股钢叉"	:	"gang fork",   
			"五股托天叉"	:	"tuotian fork",   
			"三股钢叉"	:	"gang fork",   
			"五股烈焰叉"	:	"lieyan fork",   
			"三股烈焰叉"	:	"lieyan fork",   
			"三股烈焰叉"	:	"lieyan fork",   
			"青铜叉"	:	"qingtong fork",   
			"九股烈焰叉"	:	"lieyan fork",   
			"五钩神飞叉"	:	"shenfei fork",   
			"五股青铜叉"	:	"qingtong fork",   
		]),
	"HAMMER"	:	
		([
			"八楞紫金锤"	:	"zijin hammer",   
			"八楞黄金锤"	:	"huangjin hammer",    
			"八卦生铜锤"	:	"shengtong hammer",    
			"八楞亮银锤"	:	"liangyin hammer",    
			"镔铁轧油锤"	:	"bingtie hammer",    
			"八卦亮银锤"	:	"bagua hammer",    
			"擂鼓瓮金锤"	:	"leigu hammer",    
			"龙头链子锤"	:	"longtou hammer",   
			"八楞生铁锤"	:	"baleng hammer",    
			"八卦镔铁锤"	:	"bagua hammer",    
			"黑虎铜锤"	:	"heihu hammer",    
			"乌金锤"	:	"wujin hammer",    
			"压把懒龙锤"	:	"lanlong hammer",    
			"人面赤铜锤"	:	"chitong hammer",    
			"瓜梭锤"	:	"guasuo hammer",    
			"八宝电光锤"	:	"dianguang hammer",    
			"青铜链子锤"	:	"lianzi hammer",    
			"电光紫金锤"	:	"zijin hammer",    
			"八棱铜锤"	:	"baleng hammer",    
			"浑圆锤"	:	"hunyuan hammer",    
			"青铜窝瓜锤"	:	"wogua hammer",   
			"子母鸳鸯锤"	:	"zimu hammer",    
			"亮银链子锤"	:	"lianzi hammer",    
			"八角紫金锤"	:	"bajiao hammer",    
			"红铜锤"	:	"hongtong hammer",    
			"八宝亮银锤"	:	"babao hammer",    
		]),
	"MACE"		:	
		([
			"凹面金装锏"	:	"wamian mace",   
			"四棱镔铁锏"	:	"bingtie mace", 
			"凹面八楞锏"	:	"baleng mace", 
			"四棱锏"	:	"sileng mace", 
			"熟铜锏"	:	"shutong mace", 
			"金装锏"	:	"jinzhuang mace", 
			"蟠龙银锏"	:	"pantong mace", 
			"四方镔铁锏"	:	"bingtie mace", 
			"青铜凹面锏"	:	"qingtong mace", 
			"银装锏"	:	"yinzhuang mace",
		]),
	"RAKE"		:	
		([
			"短把镔铁耙"	:	"duanba rake",   
			"画杆描金耙"	:	"huagan rake",   
			"三叉耙"	:	"sancha rake",   
			"银龙耙"	:	"yinlong rake",   
			"豹尾耙"	:	"baowei rake",   
			"黄幡耙"	:	"huangpo rake",   
			"描金耙"	:	"miaojin rake",   
			"双耳亮银耙"	:	"shuanger rake",  
			"青铜耙"	:	"qingtong rake",  
		]),
	"SWORD"		:	
		([
			"松纹古定剑"	:	"guding sword",   
			"七星鎏虹剑"	:	"liuhong sword",    
			"烈焰青锋剑"	:	"qingfeng sword",    
			"透龙剑"	:	"toulong sword",    
			"丧门宝剑"	:	"sanmeng sword",    
			"紫电青霜剑"	:	"zidian sword",    
			"紫霜剑"	:	"zishuang sword",    
			"碧灵剑"	:	"biling sword",    
			"盘蛇宝剑"	:	"panshe sword",    
			"盘龙宝剑"	:	"panlong sword",    
			"天狼剑"	:	"tianlang sword",    
			"乌钩剑"	:	"wugou sword",    
			"青钢剑"	:	"qinggang sword",    
			"鸳鸯剑"	:	"yanyang sword",    
			"青萍剑"	:	"qingping sword",    
			"太合剑"	:	"taihe sword",    
			"日月火龙剑"	:	"huolong sword",    
			"青龙剑"	:	"qinglong sword",    
			"诛龙剑"	:	"zhulong sword",    
			"困龙剑"	:	"kunlong sword",    
			"寒光剑"	:	"hanguang sword",    
			"柳叶剑"	:	"liuye sword",    
			"分天剑"	:	"fentian sword",    
			"落叶青锋剑"	:	"luoye sword",   
			"二刃青钢剑"	:	"qinggang sword",    
			"长虹剑"	:	"changhong sword",   
			"斩仙剑"	:	"zhanxian sword",    
			"乌龙剑"	:	"wulong sword",    
			"青云剑"	:	"qingyun sword",    
			"梨花宝剑"	:	"lihua sword",    
			"白光剑"	:	"baiguang sword",    
			"裁云宝剑"	:	"caiyun sword",    
		]),
	"STAFF"		:	
		([
			"阴阳杖"	:	"yinyang staff",   
			"骕濑杖"	:	"lilai staff",  
			"墨角杖"	:	"mojiao staff",  
			"牛角杖"	:	"niujiao staff",  
			"独龙杖"	:	"dulong staff",  
			"七星卧鱼杖"	:	"woyu staff",  
			"镔铁丁字杖"	:	"dingzi staff",  
			"镔铁怀抱杖"	:	"huaibao staff",  
			"龙头杖"	:	"longtou staff",  
			"虎头杖"	:	"hutou staff", 
			"七星杖"	:	"qixing staff",  
			"护手双铁杖"	:	"hushou staff",  
			"鸳鸯杖"	:	"yanyang staff",  
			"单刀卧鱼杖"	:	"woyu staff",  
			"沉香杖"	:	"chenxiang staff",  
			"勾搂虎头杖"	:	"goulou staff",  
			"镔铁鸳鸯杖"	:	"yanyang staff", 
		]),
	"STICK"		:	
		([
			"水火囚龙棒"	:	"qiulong stick",   
			"开山棒"	:	"kaishan stick", 
			"钉钉狼牙棒"	:	"dingding stick", 
			"渗金蒺藜棒"	:	"shenjin stick", 
			"紫金虬龙棒"	:	"zijin stick", 
			"乌油棒"	:	"wuyou stick", 
			"八棱棒"	:	"baleng stick", 
			"龙头软棒"	:	"longtou stick", 
			"浑铁棒"	:	"huntie stick", 
			"天罡棒"	:	"tiangang stick", 
			"独龙渗金棒"	:	"dulong stick", 
			"行者棒"	:	"xingzhe stick", 
			"亮银狼牙棒"	:	"langya stick", 
			"青铜蒺藜棒"	:	"qingtong stick", 
			"镔铁螺丝棒"	:	"luosi stick", 
			"金丝藤蛇棒"	:	"tengshe stick", 
			"金光狼牙棒"	:	"jinguang stick", 
			"百钉狼牙棒"	:	"baiding stick", 
			"紫藤软棒"	:	"ziteng stick", 
			"青铜棒槌"	:	"qingtong stick", 
			"金丝棒槌"	:	"jinsi stick",
		]),
	"WHIP"		:	
		([
			"亮银鞭"	:	"liangyin whip",
			"竹节钢鞭"	:	"zhujie whip",
			"豹尾鞭"	:	"baowei whip", 
			"打将鞭"	:	"dajiang whip", 
			"驼骨阴风鞭"	:	"tuogu whip", 
			"金龙鞭"	:	"jinlong whip", 
			"虎尾钢鞭"	:	"huwei whip", 
			"镔铁鞭"	:	"bingtie whip", 
			"龙头凤尾鞭"	:	"longtou whip", 
			"虎眼钢鞭"	:	"huyan whip", 
			"金丝软鞭"	:	"jinsi whip", 
			"葫芦鞭"	:	"hulu whip", 
			"龟骨鞭"	:	"guigu whip", 
			"鱼尾鞭"	:	"yugu whip", 
			"蛇骨鞭"	:	"shegu whip", 
			"银丝软鞭"	:	"yinsi whip", 
			"遮云扫龙鞭"	:	"zheyun whip", 
		]),
	"SPEAR"		:	
		([
			"如意金枪"	:	"ruyi spear",   
			"镔铁点钢枪"	:	"diangang spear",    
			"梅花亮银枪"	:	"meihua spear",    
			"盘竹枪"	:	"panzhu spear",    
			"素缨枪"	:	"suying spear",    
			"五钩神飞枪"	:	"shenfei spear",    
			"吸水提卢枪"	:	"tilu spear",    
			"钩镰枪"	:	"goulian spear",    
			"蛇镰枪"	:	"shelian spear",    
			"虎牙枪"	:	"huya spear",    
			"乌金枪"	:	"wujin spear",    
			"浑铁枪"	:	"huntie spear",    
			"虎头钻金枪"	:	"zuanjin spear",    
			"麒麟双枪"	:	"qilin spear",    
			"鹿筋软藤枪"	:	"ruanteng spear",    
			"点钢枪"	:	"diangang spear",    
			"丈八蛇矛枪"	:	"shemao spear",    
			"六合枪"	:	"liuhe spear",    
			"蟠龙金枪"	:	"panlong spear",    
			"金锋枪"	:	"jinfeng spear",   
			"梨花枪"	:	"lihua spear",    
			"丈八滚云枪"	:	"gunyun spear",    
			"提卢枪"	:	"tilu spear",    
			"火尖枪"	:	"huojian spear",   
		]),
	"CLOTH"		:	
		([
			"麻布衣"	:	"mabu cloth",
			"棉布衣"	:	"mianbu cloth",
			"绸布衣"	:	"choubu cloth",
			"飞雪衣"	:	"feixue cloth",
			"夜魔衣"	:	"yemo cloth",
			"青丝衣"	:	"qingsi cloth",
			"九天袍"	:	"jiutian cloth",
			"虚无袍"	:	"xuwu cloth",
			"青冥袍"	:	"qingming cloth",
			"云罗衣"	:	"yunluo cloth",
			"丝绸长袍"	:	"silk cloth",
		]),
	"SKIRT"		:	
		([
			"千褶裙"	:	"qianze skirt",
			"金丝八宝裙"	:	"babao skirt",
			"朝阳五凤裙"	:	"wufeng skirt",
			"豆绿宫裙"	:	"gong skirt",
			"双鱼比目裙"	:	"bimu skirt",
			"缕金裙"	:	"lvjin skirt",
			"百蝶裙"	:	"baidie skirt",
			"穿花裙"	:	"chuanhua skirt",
			"五彩绉裙"	:	"wucai skirt",
			"翡翠绉裙"	:	"feicui skirt",
			"撒花绉裙"	:	"sahua skirt",
		]),
	"HEAD"		:	
		([
			"闹龙垂头"	:	"naolong kui",
			"夜明盔"	:	"yeming kui",
			"凤翅金盔"	:	"fengchi kui",
			"铜荷叶盔"	:	"heye kui",
			"黄金帅字盔"	:	"huangjin kui", 
			"银练盔"	:	"yinlian kui",
			"分水盔"	:	"fenshui kui",
			"五凤朝阳盔"	:	"chaoyang kui", 
			"凤翅月明盔"	:	"fengchi kui", 
			"狼牙盔"	:	"langya kui", 
			"五凤花盔"	:	"wufeng kui", 
			"太岁盔"	:	"taisui kui", 
			"钻天盔"	:	"zuantian kui",
			"亮银虎头盔"	:	"hutou kui", 
			"豹子盔"	:	"baozi kui", 
			"蝴蝶金盔"	:	"hudie kui", 
			"双凤冠"	:	"shuangfeng guan", 
			"金凤冠"	:	"jinfeng guan",  
			"赤金冠"	:	"chijin guan",  
			"金霞冠"	:	"jinxia guan", 
			"紫金冠"	:	"zijin guan",  
			"束发金冠"	:	"shufa guan",  
			"九云烈焰冠"	:	"lieyan guan", 
		]),
	"NECK"		:	
		([
			"黑狐颈链"	:	"heihu necklace",
			"女神颈链"	:	"nvshen necklace",
			"银项链"	:	"yin necklace",
			"铜项链"	:	"tong necklace",
			"金项链"	:	"jin necklace",
			"蓝玉项链"	:	"lanyu necklace",
			"黄水晶项链"	:	"shuijing necklace",
			"青铜项链"	:	"qingtong necklace",
			"葱头项链"	:	"congtou necklace",
			"骷髅项链"	:	"kulou necklace",
			"古树项链"	:	"gushu necklace",
			"翡翠项链"	:	"feicui necklace",
			"冰鳞项链"	:	"binglin necklace",
		]),
	"ARMOR"		:
		([
			"柳叶绵竹铠"	:	"liuye armor",
			"大叶鱼鳞甲"	:	"yulin armor",
			"大叶龙鳞甲"	:	"longlin armor",
			"镔铁甲"	:	"bingtie armor", 
			"赤金铠甲"	:	"chijin armor", 
			"黄金甲"	:	"huangjin armor",
			"龟背甲"	:	"guibei armor",
			"墨鱼甲"	:	"moyu armor",
			"赤铜大叶甲"	:	"chitong armor",
			"银装甲"	:	"yinzhuang armor", 
			"连环镔铁铠"	:	"lianhuan armor",
			"月落红云甲"	:	"yueluo armor",
			"金丝软甲"	:	"jinsi armor",
			"紫藤甲"	:	"ziteng armor",
			"紫金护心甲"	:	"huxin armor", 
			"荷叶连环甲"	:	"heye armor", 
		]),
	"SURCOAT"	:	
		([
			"夜光披风"	:	"yeguang pifeng",
			"黄金披风"	:	"huangjin pifeng",
			"绵布斗篷"	:	"mianbu pifeng",
			"羊皮斗篷"	:	"yangpi pifeng",
			"绸缎斗篷"	:	"chouduan pifeng",
			"赤红斗篷"	:	"chihong pifeng",
			"灵角披风"	:	"lingjiao pifeng",
			"战月披风"	:	"zhanyue pifeng",
			"异兽披风"	:	"yishou pifeng",
		]),
	"WAIST"		:	
		([
			"帆布腰带"	:	"fanbu waist",
			"真皮腰带"	:	"zhenpi waist",
			"编织腰带"	:	"bianzhi waist",
			"粗布腰带"	:	"cubu waist",
			"生铁腰带"	:	"shengtie waist",
			"琥珀腰带"	:	"hupo waist",
			"冰鳞腰带"	:	"binglin waist",
			"白银腰带"	:	"baiying waist",
			"翡翠腰带"	:	"feicui waist",
		]),
	"WRISTS"	:	
		([
			"粗布护腕"	:	"cubu wrists",
			"紫竹护腕"	:	"zizhu wrists",
			"古木护腕"	:	"gumu wrists",
			"青铜护腕"	:	"qingtong wrists",
			"精铁护腕"	:	"jingtie wrists",
			"翡翠护腕"	:	"feicui wrists",
			"黄金护腕"	:	"huangjin wrists",
			"冰鳞护腕"	:	"bingling wrists",
		]),
	"SHIELD"	:	
		([
			"环形圆盾"	:	"yuan shield",
			"陶瓷盾"	:	"ci shield",
			"火龙之盾"	:	"huolong shield",
			"狮子盾"	:	"shizi shield",
			"虎头蘸金盾"	:	"hutou shield",
			"虎皮云片盾"	:	"hupi shield",
			"藤木盾"	:	"tengmu shield",
			"精钢盾牌"	:	"jinggang shield",
		]),
	"FINGER"	:
		([
			"永恒戒指"	:	"yongheng ring",
			"花戒指"	:	"hua ring",
			"银戒指"	:	"yin ring",
			"威严戒指"	:	"weiyan ring",
			"首领戒指"	:	"shouling ring",
			"古树戒指"	:	"gushu ring",
			"隐士戒指"	:	"yinshi ring",
			"十字骨戒"	:	"shizi ring",
			"水晶戒指"	:	"shuijing ring",
			"冰鳞戒指"	:	"bingling ring",
			"翡翠戒指"	:	"feicui ring",
			"飞雪戒指"	:	"feixue ring",
			"紫竹戒指"	:	"zizhu ring",
			"兽骨戒指"	:	"shougu ring",
		]),
	"HANDS"		:	
		([
			"流云手套"	:	"liuyun glove",
			"赤炼手套"	:	"chilian glove",
			"虚无手套"	:	"xuwu glove",
			"镏金手套"	:	"liujin glove",
			"镔铁手套"	:	"bingtie glove",
		]),
	"BOOTS"		:	
		([
			"流云靴"	:	"liuyun shoes",
			"赤炼靴"	:	"chilian shoes",
			"虚无靴"	:	"xuwu shoes",
			"镏金靴"	:	"liujin shoes",
			"火龙靴"	:	"huolong shoes",
			"兽皮靴"	:	"shoupi shoes",
			"铜牙靴"	:	"tongya shoes",
			"精铁靴"	:	"jingtie shoes",
			"乘风靴"	:	"chengfeng shoes",
			"虎纹靴"	:	"huwen shoes",
			"破浪靴"	:	"polang shoes",
		]),
]);



#endif
