/*
.H file for	workerd.c

Created	by snowman@SJ 21/04/2001
Modified by augx@SJ 9/6/2001
Modified by Ciwei@SJ

Copyright 1997-2001 ShuJian MUD Wizard Group.
All rights reserved.

*/

#include "armor.h"

#define	USER_WEAPON	BINGQI_D("user_weapon")

#define	DEFAULT_SETTINGS  ([ \
	"wield_maxneili":	500,\
	"wield_neili":		50,\
	"wield_str":		18,\
	"long":			"",\
	"long2":		"",\
	"maker":		"",\
	"material":		"steel",\
	"wield_msg":		"$N将$n握在手中。\n",\
	"unwield_msg":		"$N将手中的$n放下。\n",\
	"utime":		0,\
	"no_sell":		1,\
	"imbued":		1,\
	"dur":			3000,\
])

nosave mapping MDESC_WEAPON = ([
  "hantie": HIC "万年寒冰铁" NOR,
  "xuantie": WHT "玄铁" NOR,
  "shentie": RED "万年神铁" NOR,
  "jintie": HIY "金铁" NOR,
  "ruanying": HIW "软银" NOR,
  "liuhuashi": RED "流花石" NOR,
  "lushi": HIG "绿石" NOR,
  "ruantie": YEL "软铁" NOR,
  "shengtie": YEL "生铁" NOR,
  "qingtong": GRN "青铜" NOR,
  "default": "精钢",
]);

nosave mapping MDESC_ARMOR = ([
  "longcansi": HIY "龙茧蚕丝" NOR,
  "tiancansi": WHT "天蚕丝" NOR,
  "bingcansi": HIW "冰蚕丝" NOR,
  "yucansi": GRN "玉蚕丝" NOR,
  "mumianhua": HIY "木棉花" NOR,
  "cansi": HIW "蚕丝" NOR,
  "zhuma": HIY "苎麻" NOR,
  "dama": YEL "大麻" NOR,
  "yama": YEL "亚麻" NOR,
  "mianhua": HIW "棉花" NOR,
  "default": "布料",
]);

nosave mapping SPECIAL_B = ([
  "imbued": 5,
  "material": "xuantie",
  "wield_maxneili": 6500,
  "wield_neili": 1500,
  "wield_str": 50,
  "wield_msg": HIG "\n$N将手在风中一挥，无数的火星从四方飞来，渐渐聚在一起～～～一柄$n" HIG "已经出现在$P手中！\n" NOR,
  "unwield_msg": HIG "\n$N将$n" HIG "随手一扔，只见$n" HIG "突然变得火红，化做无数的火星四散飘走了！\n" NOR,
  "dur": 5000,
]);
nosave mapping SUPER_B = ([
  "imbued": 4,
  "material": "supersteel",
  "sharpness": 3,
  "rigidity": 3,
  "wield_maxneili": 4200,
  "wield_neili": 1200,
  "wield_str": 39,
  "wield_msg": HIW "\n$N将手一挥，一柄$n" HIW "从身后飞出，电光一闪，已经握在了$P手中。\n" NOR,
  "unwield_msg": HIW "\n$N将手中的$n" HIW "一弹，电光闪耀中，已不见了$n" HIW "的踪迹。\n" NOR,
  "dur": 4500,
]);
nosave mapping GREAT_B = ([
  "imbued": 3,
  "material": "greatsteel",
  "sharpness": 2,
  "rigidity": 2,
  "wield_maxneili": 3300,
  "wield_neili": 600,
  "wield_str": 32,
  "wield_msg": "\n$N将一柄$n抽出握在了手中。\n",
  "unwield_msg": "\n$N将手中的$n放回了武器囊。\n",
  "dur": 3800,
]);
nosave mapping GOOD_B = ([
  "imbued": 2,
  "material": "steel",
  "sharpness": 1,
  "rigidity": 1,
  "wield_maxneili": 1500,
  "wield_neili": 150,
  "wield_str": 25,
  "dur": 3350,
]);

nosave mapping WEAPON_MAP = ([
  "sword": ([
    "name": "剑",
    "basic_name": "长",
    "b_id": "jian",
    "skill_type": "sword",
    "verbs": ({ "slash", "hack", "slice", "thrust" }),
    "unit": "把",
    "weight": 12000,
    "flag": 4, ]),
  "xiao": ([
    "name": "箫",
    "basic_name": "铁",
    "b_id": "xiao",
    "skill_type": "sword",
    "verbs": ({ "slash", "hack", "slice", "thrust" }),
    "unit": "只",
    "weight": 5000,
    "flag": 8, ]),
  "axe": ([
    "name": "斧",
    "basic_name": "手",
    "b_id": "fu",
    "skill_type": "axe",
    "verbs": ({ "chop", "slice", "hack" }),
    "unit": "柄",
    "weight": 17500,
    "flag": 4, ]),
  "blade": ([
    "name": "刀",
    "basic_name": "单",
    "b_id": "dao",
    "skill_type": "blade",
    "verbs": ({ "slash", "slice", "hack" }),
    "unit": "把",
    "weight": 15000,
    "flag": 4, ]),
  "brush": ([
    "name": "笔",
    "basic_name": "铁",
    "b_id": "bi",
    "skill_type": "brush",
    "verbs": ({ "pierce", "slice", "thrust" }),
    "unit": "支",
    "weight": 6000,
    "flag": 8, ]),
  "club": ([
    "name": "棍",
    "basic_name": "铁",
    "b_id": "gun",
    "skill_type": "club",
    "rigidity": 1,
    "verbs": ({ "bash", "crush", "slam" }),
    "unit": "根",
    "weight": 17500,
    "flag": 16, ]),
  "dagger": ([
    "name": "匕",
    "basic_name": "短",
    "b_id": "bishou",
    "skill_type": "dagger",
    "dagger_count": 5,
    "verbs": ({ "slice", "pierce", "thrust" }),
    "unit": "把",
    "weight": 2000,
    "flag": 4, ]),
  "fork": ([
    "name": "叉",
    "basic_name": "鱼",
    "skill_type": "fork",
    "b_id": "cha",
    "verbs": ({ "thrust", "pierce", "impale" }),
    "unit": "根",
    "weight": 15000,
    "flag": 8, ]),
  "hammer": ([
    "name": "锤",
    "basic_name": "钉头",
    "b_id": "chui",
    "skill_type": "hammer",
    "rigidity": 1,
    "hammer_count": 5,
    "verbs": ({ "bash", "crush", "slam" }),
    "unit": "柄",
    "weight": 26000,
    "flag": 1, ]),
  "hook": ([
    "name": "钩",
    "basic_name": "单手",
    "skill_type": "hook",
    "b_id": "gou",
    "verbs": ({ "impale", "slash", "hack", }),
    "unit": "把",
    "weight": 15000,
    "flag": 4, ]),
  "spear": ([
    "name": "枪",
    "basic_name": "长",
    "b_id": "qiang",
    "skill_type": "spear",
    "verbs": ({ "thrust", "pierce", "impale" }),
    "unit": "根",
    "weight": 16000,
    "flag": 8, ]),
  "staff": ([
    "name": "杖",
    "basic_name": "拐",
    "b_id": "zhang",
    "skill_type": "staff",
    "rigidity": 1,
    "verbs": ({ "bash", "crush", "slam" }),
    "unit": "根",
    "weight": 22000,
    "flag": 16, ]),
  "stick": ([
    "name": "棒",
    "basic_name": "钢",
    "b_id": "bang",
    "skill_type": "stick",
    "rigidity": 1,
    "verbs": ({ "bash", "crush", "slam" }),
    "unit": "根",
    "weight": 16000,
    "flag": 16, ]),
  "whip": ([
    "name": "鞭",
    "basic_name": "铁",
    "b_id": "bian",
    "skill_type": "whip",
    "verbs": ({ "whip" }),
    "unit": "根",
    "weight": 8000,
    "flag": 0, ]),
]);


nosave mapping Special_Class = ([
  RED "干将": ([ "id": "ganjiang",
    "long2": RED "干将威力无比，能开天辟地，荡妖除魔！\n" NOR,
    "weapon_prop": ([ "damage": 70 ]),  //180
    "sharpness": 10,
    "rigidity": 9,
  ]),
  RED "莫邪": ([ "id": "moye",
    "long2": RED "莫邪锋利无比，能开天辟地，荡妖除魔！\n" NOR,
    "weapon_prop": ([ "damage": 70 ]),  //130
    "sharpness": 15,
    "rigidity": 9,
  ]),
  RED "鱼肠": ([ "id": "yuchang",
    "long2": RED "鱼肠轻巧无比，能开天辟地，荡妖除魔！\n" NOR,
    "weapon_prop": ([ "damage": 70, "attack": 150 ]),  //100
    "sharpness": 8,
    "rigidity": 7,
  ]),
  RED "太阿": ([ "id": "taie",
    "long2": RED "太阿帝王之兵，持之能号令天下，莫有不从！\n" NOR,
    "weapon_prop": ([ "damage": 70, "qi": 2000, "jing": 1000 ]),  //100
    "sharpness": 7,
    "rigidity": 9,
  ]),
  RED "巨阙": ([ "id": "juque",
    "long2": RED "巨阙坚硬无比，能开天辟地，荡妖除魔！\n" NOR,
    "weapon_prop": ([ "damage": 70 ]),  //120
    "sharpness": 7,
    "rigidity": 20,
  ]),
  RED "纯钩": ([ "id": "chungou",
    "long2": RED "纯钩将帅之兵，持之能挥军百万，克敌制胜！\n" NOR,
    "weapon_prop": ([ "damage": 70, "jingli": 1000, "neili": 2000 ]),  //120
    "sharpness": 7,
    "rigidity": 8,
  ]),
  RED "湛卢": ([ "id": "zhanlu",
    "long2": RED "湛卢威力、锋利、坚硬都冠绝当世，乃千古神兵！\n" NOR,
    "weapon_prop": ([ "damage": 70 ]),  //160
    "sharpness": 12,
    "rigidity": 12,
  ]),
  RED "工布": ([ "id": "gongbu",
    "long2": RED "工布天生怪异，功能参商！\n" NOR,
    "weapon_prop": ([ "damage": 70, "attack": 100, "parry": 75, "dodge": 75 ]),  //70
    "sharpness": 10,
    "rigidity": 9,
  ]),
  RED "胜邪": ([ "id": "shengxie",
    "long2": RED "胜邪威力巨大而无任何要求！\n" NOR,
    "weapon_prop": ([ "damage": 70 ]),  //70
    "sharpness": 8,
    "rigidity": 9,
    "wield_maxneili": 0,
    "wield_neili": 0,
    "wield_str": 0,
  ]),
  RED "龙泉": ([ "id": "longquan",
    "long2": RED "龙泉人间极品，武林至宝！\n" NOR,
    "weapon_prop": ([
      "damage": 100,
      "dexerity": 5,
      "strength": 5,
      "constitution": 5,
      "intelligence": 5
    ]),
    "sharpness": 9,
    "rigidity": 7,
  ]),
]);

nosave mapping Super_Class = ([
  HIM "轩辕": ([ "id": "xuanyuan",
    "long2": HIM "昔日黄帝持此物立于指南车上，驱迷雾，扫阴霾，率应龙旱魃，御百兽而战蚩尤！\n" NOR,
  ]),
  HIR "神通": ([ "id": "shentong",
    "long2": HIR "天兵神通，走势要平善，气要随行，两眼顾尖，气沉两足稳，
身法需自然，身行如飞燕，身落如停风，收如花絮，刺如钢钉！\n" NOR,
  ]),
  HIG "无极": ([ "id": "wuji",
    "long2": HIG "此物已达出神入化，登峰造极，神乎其神之境界！俗说万物归宗，便是这“无极”！\n" NOR,
  ]),
  HIW "八卦": ([ "id": "bagua",
    "long2": HIW "八卦有“休”“生”“伤”“杜”“死”“景”“惊”“开”之别，创自诸葛武候，集天下万变于一身！\n" NOR,
  ]),
  HIB "乔依乌斯": ([ "id": "joeywus",
    "long2": HIB "在西方查理曼统治的时代，最简朴的剑也能值三头母牛的价钱。而查理大帝自己的那把传奇式
的神兵“乔依乌斯”据说是半人半神的“韦兰铁匠”所造，乃当世界神兵！\n" NOR,
  ]),
  HIW "太白": ([ "id": "taibai",
    "long2": HIW "
		赵客缦胡缨  吴钩霜雪明		银鞍照白马  飒沓如流星
		十步杀一人  千里不留行		事了拂衣去  深藏身与名
		闲过信陵饮  脱剑膝前横		将炙□朱亥  持觞劝侯嬴
		三杯吐然诺  五狱倒为轻		眼花耳热後  意气素霓生
		救赵挥金槌  邯郸先震惊		千秋二壮士  喧赫大梁城
		纵死侠骨香  不惭世上英		谁能书阁下  白首太玄经\n" NOR,
  ]),
  HIY "乾坤": ([ "id": "qiankun",
    "long2": HIY "此物左右两边分别以黑白两种奇铁溶铸而成，一黑一白，切合乾坤，包含阴阳之气，好一柄宝物！\n" NOR,
  ]),
  HIY "太极": ([ "id": "taiji",
    "long2": HIY "太极者，无极而生，阴阳之母也。动之则分，静之则合。无过不及，随曲就伸。
人刚我柔谓之走，我顺人背谓之粘。动急则急应，动缓则缓随。虽变化万端，而
理为一贯！\n" NOR,
  ]),
  HIC "天地": ([ "id": "tiandi",
    "long2": HIC "天地之初，女娲补天所留下的天地间至尊之物之一经千秋万载所制，功能开天劈地！\n" NOR,
  ]),
  HIM "风云": ([ "id": "fengyun",
    "long2": HIM "所谓风云际会，天地变色！仗此行千里，老魔小丑，岂堪一击！\n" NOR,
  ]),
  HIG "浩气": ([ "id": "haoqi",
    "long2": HIG "天地浩气之神兵，扫魔除妖，为国为民，侠之大者！\n" NOR,
  ]),
  HIR "炼狱": ([ "id": "lianyu",
    "long2": HIR "三十三天下有地，地下有城，城名鬼城，大小妖魔，人神畜生都在此轮回往返，谓之“炼狱”！\n" NOR,
  ]),
  HIC "三清": ([ "id": "sanqing",
    "long2": HIC "大道无名，聚气成形，功参造化，一是三清！这便是“老子一罡化三清。”\n" NOR,
  ]),
  HIC "昆仑": ([ "id": "kunlun",
    "long2": HIC "	笑江湖浪迹十年游，空负少年头。
	对铜陀巷泊，吟情渺渺，心事悠悠！
	酒令诗残梦断，南国正清愁。
	把剑凄然望，无处招归舟。

	明月天涯路远，问谁留楚佩，弄影中洲？
	数英雄儿女，俯仰古今愁。
	难消受灯昏罗帐，伥昙花一现恨难休！
	飘零惯，金戈铁马，拼葬荒丘！ \n" NOR,
  ]),
]);

nosave mapping Great_Class = ([
  CYN "帝王": "diwang", CYN "王者": "wangzhe",
  CYN "天后": "tianhou", CYN "霸王": "bawang",
  CYN "天圣": "tiansheng", CYN "神王": "shenwang",
  CYN "妖后": "yaohou", BLU "公侯": "gonghou",
  BLU "魔王": "mowang", BLU "七星": "qixing",
  BLU "恶鬼": "egui", GRN "玉龙": "yulong",
  GRN "玉凤": "yufeng", GRN "松鹤": "songhe",
  GRN "天龙": "tianlong", GRN "地龙": "dilong",
  GRN "天凤": "tianfeng", GRN "地凤": "difeng",
  GRN "龙翔": "longxiang", GRN "凤舞": "fengwu",
  HIG "无影": "wuying", HIG "破甲": "pojia",
  HIG "飞龙": "feilong", HIG "武翼": "wuyi",
  HIG "鸟翔": "niaoxiang", HIG "婉盘": "wanpan",
  HIG "青萍": "qingping", YEL "黄龙": "huanglong",
  WHT "云梯": "yunti", WHT "太渊": "taiyuan",
  WHT "太风": "taifeng", WHT "虚灵": "xuling",
  WHT "霹雳": "pili", WHT "雷电": "leidian",
  WHT "风雷": "fenglei", WHT "震电": "zhendian",
  WHT "白玉": "baiyu", WHT "青玉": "qingyu",
  WHT "紫玉": "ziyu", WHT "蓝玉": "lanyu",
  WHT "绿玉": "luyu", WHT "黄玉": "huangyu",
  WHT "赤玉": "chiyu", WHT "红玉": "hongyu",
  CYN "青虹": "qinghong", CYN "白虹": "baihong",
  CYN "紫虹": "zihong", CYN "蓝虹": "lanhong",
  CYN "绿虹": "luhong", CYN "赤虹": "chihong",
  CYN "幻影": "huanying", CYN "凝霜": "ningshuang",
  CYN "青索": "qingsuo", MAG "天龙": "tianlong",
  MAG "紫电": "zidian", MAG "凤凰": "fenghuang",
  MAG "天枢": "tianqu", MAG "天璇": "tianxuan",
  MAG "天玑": "tianji", MAG "天权": "tianquan",
  MAG "玉衡": "yuheng", MAG "开阳": "kaiyang",
  MAG "摇光": "yaoguang", MAG "北斗": "beidou",
  HIR "天火": "tianhuo", HIR "麒麟": "qilin",
  HIR "辟邪": "pixie", YEL "鸿钧": "hongjun",
  YEL "广成": "guangcheng", YEL "金光": "jinguang",
  YEL "修罗": "xiuluo", YEL "夜叉": "yecha",
  YEL "瑶池": "yaochi", YEL "泪痕": "leiheng",
  HIR "火龙": "huolong", HIC "冰龙": "binglong",
  HIB "黑龙": "heilong", HIR "炎龙": "yanlong",
  HIC "青龙": "qinglong", HIR "朱雀": "zhuque",
  HIW "白虎": "baihu", HIB "玄武": "xuanwu",
  GRN "玄机": "xuanji", HIG "九天": "jiutian",
  HIG "九幽": "jiuyou", MAG "九龙": "jiulong",
  MAG "五龙": "wulong", MAG "三龙": "sanlong",
  WHT "生死": "shengsi",
]);

nosave string *G_3_class = ({
  "春雨", "夏雨", "秋雨", "冬雨", "春兰", "夏荷", "秋菊", "冬梅",
  "玉泉", "羽泉", "风泉", "虎泉", "怒涛", "江河", "漩流", "清水",
  "巨", "大", "小", "怪", "阖", "阔", "宾", "叠",
  "青锋", "双锋", "锐气", "必胜", "吴钩", "桃花", "无敌", "双手",
  "吉祥", "天女", "花纹", "暗光", "松纹", "蟠钢", "龟文", "盘古",
  "缦理", "流水", "芙蓉", "深渊", "高山", "大川", "流波", "冰释",
  "鱼鳞", "兽皮", "开山", "倒海", "复体", "锯齿", "沧海", "天门",
  "地门", "雁翎", "飞燕", "燕尾", "慑魂", "夺魂", "弦月", "连衡",
  "鬼号", "厉鬼", "鬼头", "鬼王", "牛头", "拘魂", "魂魄", "寒光",
  "阴蛇", "照海", "地狱", "龙头", "猛虎", "曙光", "泼水", "暗光",
  "晦光", "明光", "天光", "神光", "鬼气", "仙品", "天水", "地水",
  "天锋", "地锋", "天雨", "神雨", "鬼雨", "地雨", "仙雨", "魔雨",
  "神水", "仙水", "魔水", "毒蛇", "五步", "竹叶", "柳叶", "天竹",
  "地竹", "神竹", "魔竹", "伤痕", "飞武", "猛虎", "猛狮", "啸天",
  "幻风", "望月", "明月", "赶月", "弯月", "豹枭", "虎枭", "狮枭",
  "野狼", "狂狼", "狂龙", "神狼", "神狮", "神虎", "神豹", "神鹰",
  "天羽", "地羽", "泪痕", "浪云", "乌发", "蝉鬓", "云髻", "雾鬟",
  "娥眉", "青黛", "明眸", "流盼", "朱唇", "皓齿", "玉指", "素臂",
  "晓翠", "春江", "夜月", "啼莺", "慈云", "浮云", "青云", "朝云",
  "夜云", "飞云", "卷云", "白云", "蓝云", "紫云", "红云", "赤云",
  "鸿门", "蛟龙", "雷霆", "狮吼", "卧虎", "青羊", "老君", "斗母",
  "贺兰", "日月", "玉门", "阡陌", "纵横", "承天", "延永", "玉皇",
  "松柏", "须弥", "秀骨", "清相", "洛神", "璎络", "圣母", "文昌",
  "武圣", "南天", "北天", "西天", "东天", "飞雪", "飘雪", "落雪",
  "白雪", "梦雪", "雪花", "烟雨", "霞蔚", "赤霞", "潇湘", "瀚海",
  "牡丹", "百合", "白荷", "龙菊", "幽兰", "翡翠", "寒梅", "青竹",
  "相思", "云竹", "海棠", "芍药", "杜鹃", "玫瑰", "月季", "四季",
  "芙蓉", "蔷薇", "苍岩", "天师", "洗心", "常青", "翻天", "降魔",
  "风铃", "风信", "紫阳", "丹阳", "紫薇", "木樨", "富贵", "太阳",
  "火鹤", "青鹤", "白鹤", "紫鹤", "白薇", "蓝薇", "青薇", "火薇",
  "冰薇", "青阳", "白阳", "火阳", "冰阳", "天秤", "巨蟹", "金牛",
  "扣骨", "渡心", "含翠", "蝙蝠", "月形", "黑云", "铁鲨", "撼山",
  "断玉", "摘星", "探星", "飞星", "黑魅", "绿影", "玉魔", "银铃",
  "金铃", "千仞", "晶电", "千芒", "阴霾", "魔袱", "戈壁",
  "蚁峻", "矗页", "睚眦", "螭吻", "蒲牢", "饕餮", "蜍夏", "椒图",
  "血斩", "天威", "旋风", "紫芒", "削岩", "万丈", "星龙", "月龙",
  "巨威", "影残", "璨星", "裂心", "双星", "望霞", "翠屏", "朝云",
  "松峦", "集仙", "聚鹤", "净坛", "上升", "起云", "飞凤", "登龙",
  "聚泉",
});

/////////////////////////////// functions ////////////////////////
string s_good(int i) {
  switch (i) {
    case 10..20: return "无比";
    case 9: return "无比";
    case 8: return "极其";
    case 7: return "绝对";
    case 6: return "极为";
    case 5: return "相当";
    case 4: return "十分";
    case 3: return "非常";
    case 2: return "比较";
    case 1: return "还算";
    case -1: return "不怎么";
    case -2: return "很不";
    case -3: return "极不";
    default: return "一般";
  }
}

string s_power(int i) {
  if (i >= 300) return HIW "毁天灭地" NOR;
  if (i >= 280) return HIW "开元创世" NOR;
  if (i >= 250) return HIY "天下无双" NOR;
  if (i >= 220) return HIY "绝世罕见" NOR;
  if (i >= 200) return HIM "举世无匹" NOR;
  if (i >= 180) return HIM "开天劈地" NOR;
  if (i >= 160) return HIR "倚天屠龙" NOR;
  if (i >= 140) return HIC "斩妖伏魔" NOR;
  if (i >= 120) return HIG "无与伦比" NOR;
  if (i >= 100) return HIB "极其可怕" NOR;
  if (i >= 80) return WHT "很高" NOR;
  if (i >= 60) return YEL "水准以上" NOR;
  if (i >= 40) return MAG "不错" NOR;
  if (i > 20) return RED "不小" NOR;
  if (i <= 0) return GRN "极差" NOR;
  if (i <= -20) return BLU "低劣" NOR;
  return CYN "一般" NOR;
}

// Important mapping for user_weapon.
nosave mapping mp;
nosave string *special_st = ({});
nosave string *name_st = ({});
/////////////////////////// armors //////////////////////////////
#define	USER_ARMOR	ARMOR_D("user_armor")

#define	ARMOR_DEFAULT_SETTINGS  ([ \
	"long":			"",\
	"long2":		"",\
	"maker":		"",\
	"material":		"mianbu",\
	"no_sell":		1,\
	"utime":		0,\
	"imbued":		1,\
	"wear_maxneili":	500,\
	"wear_con":		18,\
	"wear_str":		18,\
	"poisoned":		"",\
	"poison_number":	0,\
	"times":		100,\
	"max_dur":		2000,\
	"dur":			2000,\
])

nosave mapping ARMOR_SPECIAL_B = ([
  "imbued": 5,
  "wear_maxneili": 6500,
  "wear_con": 50,
  "wear_str": 50,
  "max_dur": 3000,
  "times": 450,
]);
nosave mapping ARMOR_SUPER_B = ([
  "imbued": 4,
  "wear_maxneili": 5000,
  "wear_con": 39,
  "wear_str": 39,
  "max_dur": 2800,
  "times": 350,
]);
nosave mapping ARMOR_GREAT_B = ([
  "imbued": 3,
  "wear_maxneili": 3500,
  "wear_con": 32,
  "wear_str": 32,
  "times": 250,
  "max_dur": 2500,
]);
nosave mapping ARMOR_GOOD_B = ([
  "imbued": 2,
  "wear_maxneili": 1500,
  "wear_con": 26,
  "wear_str": 26,
  "times": 175,
  "max_dur": 2250,
]);

nosave mapping ARMOR_MAP = ([
  "cap": ([
    "name": "头盔",
    "armor_type": TYPE_HEAD,
    "basic_name": "",
    "unit": "顶",
    "armor_prop": ([ "armor": 1 ]),
    "weight": 3500, ]),
  "glove": ([
    "name": "手套",
    "armor_type": TYPE_HANDS,
    "basic_name": "",
    "unit": "副",
    "armor_prop": ([ "armor": 1 ]),
    "weight": 1500, ]),
  "coat": ([
    "name": "彩衣",
    "armor_type": TYPE_COAT,
    "basic_name": "",
    "unit": "件",
    "armor_prop": ([ "armor": 1 ]),
    "weight": 6000, ]),
  "armor": ([
    "name": "甲胄",
    "armor_type": TYPE_ARMOR,
    "basic_name": "",
    "unit": "件",
    "armor_prop": ([ "armor": 1 ]),
    "weight": 22000, ]),
  "belt": ([
    "name": "腰带",
    "armor_type": TYPE_WAIST,
    "basic_name": "",
    "unit": "条",
    "armor_prop": ([ "armor": 1 ]),
    "weight": 2500, ]),
  "boot": ([
    "name": "靴",
    "armor_type": TYPE_BOOTS,
    "basic_name": "皮",
    "unit": "双",
    "armor_prop": ([ "dodge": 1 ]),
    "weight": 5000, ]),
  "mantle": ([
    "name": "披风",
    "armor_type": TYPE_SURCOAT,
    "basic_name": "",
    "unit": "件",
    "armor_prop": ([ "dodge": 1 ]),
    "weight": 10000, ]),
]);

nosave mapping Armor_Special_Class = ([
  "cap": ([
    YEL "青龙头盔" NOR: ([
      "id": "qinglong toukui",
      "long2": YEL "飞龙在天之宝器。\n" NOR,
      "armor_prop": ([ "armor": 30, "dexerity": 2 ]),
    ]),
    HIW "白虎头盔" NOR: ([
      "id": "qinglong toukui",
      "long2": HIW "坚固无比之上古宝器。\n" NOR,
      "armor_prop": ([ "armor": 50 ]),
    ]),
    RED "莫邪头盔" NOR: ([
      "id": "moye toukui",
      "long2": RED "莫邪开天辟地，百毒不侵，为古代辟邪之物！\n" NOR,
      "armor_prop": ([ "armor": 30, "antipoison": 25 ]),
    ]),
    RED "龙泉头盔" NOR: ([
      "id": "longquan toukui",
      "long2": RED "龙泉人间极品，武林至宝！\n" NOR,
      "armor_prop": ([
        "armor": 25,
        "dexerity": 1,
        "strength": 1,
        "constitution": 1,
        "intelligence": 1
      ]),
    ]),
  ]),
  "glove": ([
    HIB "飞叶手套" NOR: ([
      "id": "feiye shoutao",
      "long2": HIB "飞叶伤人之宝器。\n" NOR,
      "armor_prop": ([ "armor": 30, "dexerity": 2 ]),
    ]),
    HIW "顽石手套": ([
      "id": "wanshi shoutao",
      "long2": HIW "坚固无比之上古宝器。\n" NOR,
      "armor_prop": ([ "armor": 50 ]),
    ]),
    HIR "摘花手套": ([
      "id": "zhaihua shoutao",
      "long2": HIR "温柔摘花之宝物。\n" NOR,
      "armor_prop": ([ "armor": 30, "constitution": 3 ]),
    ]),
    RED "龙泉手套": ([
      "id": "longquan toukui",
      "long2": RED "龙泉人间极品，武林至宝！\n" NOR,
      "armor_prop": ([
        "armor": 25,
        "dexerity": 1,
        "strength": 1,
        "constitution": 1,
        "intelligence": 1
      ]),
    ]),
  ]),
  "boot": ([
    HIW "飞云靴" NOR: ([
      "id": "feiyun xue",
      "long2": HIW "飞龙在天，纵横天下之宝靴！\n" NOR,
      "armor_prop": ([ "armor": 25, "dexerity": 3 ]),
    ]),
    HIY "天龙靴" NOR: ([
      "id": "tianlong xue",
      "long2": HIY "坚固无比之上古宝器。\n" NOR,
      "armor_prop": ([ "armor": 40 ]),
    ]),
    HIR "工布靴" NOR: ([
      "id": "gongbu xue",
      "long2": RED "工布天生怪异，功能参商！\n" NOR,
      "armor_prop": ([ "armor": 25, "dodge": 20, "parry": 20 ]),
    ]),
    RED "胜邪靴" NOR: ([
      "id": "shengxie xue",
      "long2": RED "胜邪坚固无比而无任何要求！\n" NOR,
      "armor_prop": ([ "armor": 30 ]),
      "wear_maxneili": 0,
      "wear_dex": 0,
      "wear_str": 0,
    ]),
  ]),
  "belt": ([
    HIW "飞天腰带" NOR: ([
      "id": "feitian yaodai",
      "long2": HIW "飞翔于九天之外之宝器！\n" NOR,
      "armor_prop": ([ "armor": 25, "dexerity": 2 ]),
    ]),
    HIB "辟邪腰带" NOR: ([
      "id": "pixie yaodai",
      "long2": HIB "辟邪除魔之震妖宝器！\n" NOR,
      "armor_prop": ([ "armor": 25, "constitution": 2 ]),
    ]),
    RED "湛卢腰带" NOR: ([
      "id": "zhanlu yaodai",
      "long2": RED "湛卢坚固无比，乃千古神器！\n" NOR,
      "armor_prop": ([ "armor": 40 ]),
    ]),
    RED "胜邪腰带" NOR: ([
      "id": "shengxie xue",
      "long2": RED "胜邪坚固无比而无任何要求！\n" NOR,
      "armor_prop": ([ "armor": 30 ]),
      "wear_maxneili": 0,
      "wear_dex": 0,
      "wear_str": 0,
    ]),
  ]),
  "coat": ([
    RED "莫邪彩衣" NOR: ([
      "id": "moye caiyi",
      "long2": RED "莫邪开天辟地，百毒不侵，为古代辟邪之物！\n" NOR,
      "armor_prop": ([ "armor": 90, "antipoison": 60 ]),
    ]),
    RED "太阿彩衣" NOR: ([
      "id": "taie caiyi",
      "long2": RED "太阿帝王之器，持之能号令天下，莫有不从！\n" NOR,
      "armor_prop": ([ "armor": 90, "qi": 1000, "jing": 500 ]),
    ]),
    RED "湛卢彩衣" NOR: ([
      "id": "zhanlu caiyi",
      "long2": RED "湛卢坚固无比，乃千古神兵！\n" NOR,
      "armor_prop": ([ "armor": 120 ]),
    ]),
    RED "工布彩衣" NOR: ([
      "id": "gongbu caiyi",
      "long2": RED "工布天生怪异，功能参商！\n" NOR,
      "armor_prop": ([ "armor": 90, "parry": 35, "dodge": 35 ]),
    ]),
    RED "胜邪彩衣" NOR: ([
      "id": "shengxie caiyi",
      "long2": RED "胜邪无比坚固巨大而无任何要求！\n" NOR,
      "armor_prop": ([ "armor": 90 ]),
      "wear_maxneili": 0,
      "wear_dex": 0,
      "wear_str": 0,
    ]),
    RED "龙泉彩衣" NOR: ([
      "id": "longquan caiyi",
      "long2": RED "龙泉人间极品，武林至宝！\n" NOR,
      "armor_prop": ([
        "armor": 80,
        "dexerity": 1,
        "strength": 1,
        "constitution": 1,
        "intelligence": 1
      ]),
    ]),
  ]),
  "armor": ([
    RED "莫邪甲胄" NOR: ([
      "id": "moye jiazhou",
      "long2": RED "莫邪开天辟地，百毒不侵，为古代辟邪之物！\n" NOR,
      "armor_prop": ([ "armor": 108, "antipoison": 50 ]),
    ]),
    RED "太阿甲胄" NOR: ([
      "id": "taie jiazhou",
      "long2": RED "太阿帝王之器，持之能号令天下，莫有不从！\n" NOR,
      "armor_prop": ([ "armor": 108, "qi": 600, "jing": 300 ]),
    ]),
    RED "湛卢甲胄" NOR: ([
      "id": "zhanlu jiazhou",
      "long2": RED "湛卢坚固无比，乃千古神兵！\n" NOR,
      "armor_prop": ([ "armor": 135 ]),
    ]),
    RED "工布甲胄" NOR: ([
      "id": "gongbu jiazhou",
      "long2": RED "工布天生怪异，功能参商！\n" NOR,
      "armor_prop": ([ "armor": 108, "parry": 30, "dodge": 30 ]),
    ]),
    RED "胜邪甲胄" NOR: ([
      "id": "shengxie jiazhou",
      "long2": RED "胜邪无比坚固巨大而无任何要求！\n" NOR,
      "armor_prop": ([ "armor": 108 ]),
      "wear_maxneili": 0,
      "wear_dex": 0,
      "wear_str": 0,
    ]),
    RED "龙泉甲胄" NOR: ([
      "id": "longquan jiazhou",
      "long2": RED "龙泉人间极品，武林至宝！\n" NOR,
      "armor_prop": ([
        "armor": 100,
        "dexerity": 1,
        "strength": 1,
        "constitution": 1,
        "intelligence": 1
      ]),
    ]),
  ]),
  "mantle": ([
    RED "莫邪披风" NOR: ([
      "id": "moye pifeng",
      "long2": RED "莫邪开天辟地，百毒不侵，为古代辟邪之物！\n" NOR,
      "armor_prop": ([ "armor": 70, "antipoison": 75 ]),
    ]),
    RED "太阿披风" NOR: ([
      "id": "taie pifeng",
      "long2": RED "太阿帝王之器，持之能号令天下，莫有不从！\n" NOR,
      "armor_prop": ([ "armor": 70, "qi": 400, "jing": 150 ]),
    ]),
    RED "湛卢披风" NOR: ([
      "id": "zhanlu pifeng",
      "long2": RED "湛卢坚固无比，乃千古神兵！\n" NOR,
      "armor_prop": ([ "armor": 85 ]),
    ]),
    RED "工布披风" NOR: ([
      "id": "gongbu pifeng",
      "long2": RED "工布天生怪异，功能参商！\n" NOR,
      "armor_prop": ([ "armor": 70, "parry": 20, "dodge": 20 ]),
    ]),
    RED "胜邪披风" NOR: ([
      "id": "shengxie pifeng",
      "long2": RED "胜邪无比坚固巨大而无任何要求！\n" NOR,
      "armor_prop": ([ "armor": 70 ]),
      "wear_maxneili": 0,
      "wear_dex": 0,
      "wear_str": 0,
    ]),
    RED "龙泉披风" NOR: ([
      "id": "longquan pifeng",
      "long2": RED "龙泉人间极品，武林至宝！\n" NOR,
      "armor_prop": ([
        "armor": 60,
        "dexerity": 1,
        "strength": 1,
        "constitution": 1,
        "intelligence": 1
      ]),
    ]),
  ]),
]);

nosave mapping Armor_Super_Class = ([
  HIM "轩辕": ([ "id": "xuanyuan",
    "long2": HIM "昔日黄帝持此物立于指南车上，驱迷雾，扫阴霾，率应龙旱魃，御百兽而战蚩尤！\n" NOR,
  ]),
  HIR "神通": ([ "id": "shentong",
    "long2": HIR "天器神通，走势要平善，气要随行，两眼顾尖，气沉两足稳，
身法需自然，身行如飞燕，身落如停风，收如花絮，刺如钢钉！\n" NOR,
  ]),
  HIG "无极": ([ "id": "wuji",
    "long2": HIG "此物已达出神入化，登峰造极，神乎其神之境界！俗说万物归宗，便是这“无极”！\n" NOR,
  ]),
  HIW "八卦": ([ "id": "bagua",
    "long2": HIW "八卦有“休”“生”“伤”“杜”“死”“景”“惊”“开”之别，创自诸葛武候，集天下万变于一身！\n" NOR,
  ]),
  HIW "太白": ([ "id": "taibai",
    "long2": HIW "
		赵客缦胡缨  吴钩霜雪明		银鞍照白马  飒沓如流星
		十步杀一人  千里不留行		事了拂衣去  深藏身与名
		闲过信陵饮  脱剑膝前横		将炙□朱亥  持觞劝侯嬴
		三杯吐然诺  五狱倒为轻		眼花耳热後  意气素霓生
		救赵挥金槌  邯郸先震惊		千秋二壮士  喧赫大梁城
		纵死侠骨香  不惭世上英		谁能书阁下  白首太玄经\n" NOR,
  ]),
  HIY "乾坤": ([ "id": "qiankun",
    "long2": HIY "此物左右两边分别以黑白两种物质融会而成，一黑一白，切合乾坤，包含阴阳之气，好一见宝物！\n" NOR,
  ]),
  HIY "太极": ([ "id": "taiji",
    "long2": HIY "太极者，无极而生，阴阳之母也。动之则分，静之则合。无过不及，随曲就伸。
人刚我柔谓之走，我顺人背谓之粘。动急则急应，动缓则缓随。虽变化万端，而
理为一贯！\n" NOR,
  ]),
  HIC "天地": ([ "id": "tiandi",
    "long2": HIC "天地之初，女娲补天所留下的天地间至尊之物之一经千秋万载所制，功能开天劈地！\n" NOR,
  ]),
  HIM "风云": ([ "id": "fengyun",
    "long2": HIM "所谓风云际会，天地变色！仗此行千里，老魔小丑，岂堪一击！\n" NOR,
  ]),
  HIG "浩气": ([ "id": "haoqi",
    "long2": HIG "天地浩气之神兵，扫魔除妖，为国为民，侠之大者！\n" NOR,
  ]),
  HIR "炼狱": ([ "id": "lianyu",
    "long2": HIR "三十三天下有地，地下有城，城名鬼城，大小妖魔，人神畜生都在此轮回往返，谓之“炼狱”！\n" NOR,
  ]),
  HIC "三清": ([ "id": "sanqing",
    "long2": HIC "大道无名，聚气成形，功参造化，一是三清！这便是“老子一罡化三清。”\n" NOR,
  ]),
  HIC "昆仑": ([ "id": "kunlun",
    "long2": HIC "	笑江湖浪迹十年游，空负少年头。
	对铜陀巷泊，吟情渺渺，心事悠悠！
	酒令诗残梦断，南国正清愁。
	把剑凄然望，无处招归舟。

	明月天涯路远，问谁留楚佩，弄影中洲？
	数英雄儿女，俯仰古今愁。
	难消受灯昏罗帐，伥昙花一现恨难休！
	飘零惯，金戈铁马，拼葬荒丘！ \n" NOR,
  ]),
]);

nosave mapping Armor_Great_Class = ([
  CYN "帝王": "diwang", CYN "王者": "wangzhe",
  CYN "天后": "tianhou", CYN "霸王": "bawang",
  CYN "天圣": "tiansheng", CYN "神王": "shenwang",
  CYN "妖后": "yaohou", BLU "公侯": "gonghou",
  BLU "魔王": "mowang", BLU "七星": "qixing",
  BLU "恶鬼": "egui", GRN "玉龙": "yulong",
  GRN "玉凤": "yufeng", GRN "松鹤": "songhe",
  GRN "天龙": "tianlong", GRN "地龙": "dilong",
  GRN "天凤": "tianfeng", GRN "地凤": "difeng",
  GRN "龙翔": "longxiang", GRN "凤舞": "fengwu",
  HIG "无影": "wuying", HIG "破甲": "pojia",
  HIG "飞龙": "feilong", HIG "武翼": "wuyi",
  HIG "鸟翔": "niaoxiang", HIG "婉盘": "wanpan",
  HIG "青萍": "qingping", YEL "黄龙": "huanglong",
  WHT "云梯": "yunti", WHT "太渊": "taiyuan",
  WHT "太风": "taifeng", WHT "虚灵": "xuling",
  WHT "霹雳": "pili", WHT "雷电": "leidian",
  WHT "风雷": "fenglei", WHT "震电": "zhendian",
  WHT "白玉": "baiyu", WHT "青玉": "qingyu",
  WHT "紫玉": "ziyu", WHT "蓝玉": "lanyu",
  WHT "绿玉": "luyu", WHT "黄玉": "huangyu",
  WHT "赤玉": "chiyu", WHT "红玉": "hongyu",
  CYN "青虹": "qinghong", CYN "白虹": "baihong",
  CYN "紫虹": "zihong", CYN "蓝虹": "lanhong",
  CYN "绿虹": "luhong", CYN "赤虹": "chihong",
  CYN "幻影": "huanying", CYN "凝霜": "ningshuang",
  CYN "青索": "qingsuo", MAG "天龙": "tianlong",
  MAG "紫电": "zidian", MAG "凤凰": "fenghuang",
  MAG "天枢": "tianqu", MAG "天璇": "tianxuan",
  MAG "天玑": "tianji", MAG "天权": "tianquan",
  MAG "玉衡": "yuheng", MAG "开阳": "kaiyang",
  MAG "摇光": "yaoguang", MAG "北斗": "beidou",
  HIR "天火": "tianhuo", HIR "麒麟": "qilin",
  HIR "辟邪": "pixie", YEL "鸿钧": "hongjun",
  YEL "广成": "guangcheng", YEL "金光": "jinguang",
  YEL "修罗": "xiuluo", YEL "夜叉": "yecha",
  YEL "瑶池": "yaochi", YEL "泪痕": "leiheng",
  HIR "火龙": "huolong", HIC "冰龙": "binglong",
  HIB "黑龙": "heilong", HIR "炎龙": "yanlong",
  HIC "青龙": "qinglong", HIR "朱雀": "zhuque",
  HIW "白虎": "baihu", HIB "玄武": "xuanwu",
  GRN "玄机": "xuanji", HIG "九天": "jiutian",
  HIG "九幽": "jiuyou", MAG "九龙": "jiulong",
  MAG "五龙": "wulong", MAG "三龙": "sanlong",
  WHT "生死": "shengsi",
]);

nosave string *Armor_G_3_class = ({
  "春雨", "夏雨", "秋雨", "冬雨", "春兰", "夏荷", "秋菊", "冬梅",
  "玉泉", "羽泉", "风泉", "虎泉", "怒涛", "江河", "漩流", "清水",
  "巨", "大", "小", "怪", "阖", "阔", "宾", "叠",
  "青锋", "双锋", "锐气", "必胜", "吴钩", "桃花", "无敌", "双手",
  "吉祥", "天女", "花纹", "暗光", "松纹", "蟠钢", "龟文", "盘古",
  "缦理", "流水", "芙蓉", "深渊", "高山", "大川", "流波", "冰释",
  "鱼鳞", "兽皮", "开山", "倒海", "复体", "锯齿", "沧海", "天门",
  "地门", "雁翎", "飞燕", "燕尾", "慑魂", "夺魂", "弦月", "连衡",
  "鬼号", "厉鬼", "鬼头", "鬼王", "牛头", "拘魂", "魂魄", "寒光",
  "阴蛇", "照海", "地狱", "龙头", "猛虎", "曙光", "泼水", "暗光",
  "晦光", "明光", "天光", "神光", "鬼气", "仙品", "天水", "地水",
  "天锋", "地锋", "天雨", "神雨", "鬼雨", "地雨", "仙雨", "魔雨",
  "神水", "仙水", "魔水", "毒蛇", "五步", "竹叶", "柳叶", "天竹",
  "地竹", "神竹", "魔竹", "伤痕", "飞武", "猛虎", "猛狮", "啸天",
  "幻风", "望月", "明月", "赶月", "弯月", "豹枭", "虎枭", "狮枭",
  "野狼", "狂狼", "狂龙", "神狼", "神狮", "神虎", "神豹", "神鹰",
  "天羽", "地羽", "泪痕", "浪云", "乌发", "蝉鬓", "云髻", "雾鬟",
  "娥眉", "青黛", "明眸", "流盼", "朱唇", "皓齿", "玉指", "素臂",
  "晓翠", "春江", "夜月", "啼莺", "慈云", "浮云", "青云", "朝云",
  "夜云", "飞云", "卷云", "白云", "蓝云", "紫云", "红云", "赤云",
  "鸿门", "蛟龙", "雷霆", "狮吼", "卧虎", "青羊", "老君", "斗母",
  "贺兰", "日月", "玉门", "阡陌", "纵横", "承天", "延永", "玉皇",
  "松柏", "须弥", "秀骨", "清相", "洛神", "璎络", "圣母", "文昌",
  "武圣", "南天", "北天", "西天", "东天", "飞雪", "飘雪", "落雪",
  "白雪", "梦雪", "雪花", "烟雨", "霞蔚", "赤霞", "潇湘", "瀚海",
  "牡丹", "百合", "白荷", "龙菊", "幽兰", "翡翠", "寒梅", "青竹",
  "相思", "云竹", "海棠", "芍药", "杜鹃", "玫瑰", "月季", "四季",
  "芙蓉", "蔷薇", "苍岩", "天师", "洗心", "常青", "翻天", "降魔",
  "风铃", "风信", "紫阳", "丹阳", "紫薇", "木樨", "富贵", "太阳",
  "火鹤", "青鹤", "白鹤", "紫鹤", "白薇", "蓝薇", "青薇", "火薇",
  "冰薇", "青阳", "白阳", "火阳", "冰阳", "天秤", "巨蟹", "金牛",
  "扣骨", "渡心", "含翠", "蝙蝠", "月形", "黑云", "铁鲨", "撼山",
  "断玉", "摘星", "探星", "飞星", "黑魅", "绿影", "玉魔", "银铃",
  "金铃", "千仞", "晶电", "千芒", "阴霾", "魔袱", "戈壁",
  "蚁峻", "矗页", "睚眦", "螭吻", "蒲牢", "饕餮", "蜍夏", "椒图",
  "血斩", "天威", "旋风", "紫芒", "削岩", "万丈", "星龙", "月龙",
  "巨威", "影残", "璨星", "裂心", "双星", "望霞", "翠屏", "朝云",
  "松峦", "集仙", "聚鹤", "净坛", "上升", "起云", "飞凤", "登龙",
  "聚泉",
});

nosave mapping armor_modify = ([
  "cap": 17,
  "glove": 20,
  "coat": 6,
  "armor": 5,
  "belt": 25,
  "boot": 20,
  "mantle": 20,
  /*
	"cap":0.4,25
	"glove":0.3,33
	"coat":0.9,11
	"armor":1.0,10
	"belt":0.2,50
	"boot":0.5,20
	"mantle":0.4,25
	////////////	
	cap      0.6  17
	glove    0.5   20
	coat     1.6   6
	armor    1.8   5
	belt     0.4   25
	boot     0.5   20
	mantle   0.5   20
	
	cap      0.7    14
	glove    0.6    17
	coat     1.7    6
	armor    1.9    5
	belt     0.4    25
	boot     0.6    17
	mantle       0.6 17
	*/
]);
//////////////////////// armor functions ////////////////////////////
string armor_power(mapping p, string type) {
  int i;
  switch (type) {
    case "head": type = "cap"; break;
    case "hands": type = "glove"; break;
    case "boots": type = "boot"; break;
    case "surcoat": type = "mantle"; break;
    case "waist": type = "belt"; break;
    case "coat":
    case "armor": break;
    default: return "！！！错误的防具类型！！！";
  }
  if (type == "boot" || type == "mantle") i = p["dodge"] * 8 * armor_modify[type] / 10;
  else i = p["armor"] * 4 * armor_modify[type] / 10;

  if (i >= 600) return HIW "无敌天下" NOR;
  if (i >= 550) return HIW "天下无双" NOR;
  if (i >= 500) return HIY "绝世罕见" NOR;
  if (i >= 450) return HIY "举世无匹" NOR;
  if (i >= 400) return HIM "无与伦比" NOR;
  if (i >= 360) return HIM "牢不可破" NOR;
  if (i >= 330) return HIR "坚固异常" NOR;
  if (i >= 300) return HIC "极高" NOR;
  if (i >= 270) return HIG "很高" NOR;
  if (i >= 240) return HIB "较高" NOR;
  if (i >= 210) return WHT "很不错" NOR;
  if (i >= 180) return YEL "不错" NOR;
  if (i >= 150) return MAG "不小" NOR;
  if (i >= 120) return RED "还可以" NOR;
  if (i <= 25) return BLU "极差" NOR;
  if (i <= 75) return GRN "低劣" NOR;
  return CYN "一般" NOR;
}
///////////////////Status/////////////////////////////////////////
nosave mapping Status_list = ([
  "jingli": 5,
  "jing": 5,
  "neili": 8,
  "qi": 8,
  "parry": 150,
  "dodge": 150,
  "force": 180,
  "attack": 200,
  "defense": 200,
  "re_qi": 400,
  "re_neili": 400,
  "re_jing": 400,
  "re_jingli": 400,
  "damage": 400,
  "armor": 400,
  "strength": 1300,
  "constitution": 1300,
  "dexerity": 1300,
  "intelligence": 2000,
  "karma": 3000,
  "personality": 3000,
  "armor_vs_force": 1000,
]);

mixed StrToFloat(string s) {
  float i;

  if (sscanf(s, "%f", i) == 1)
    return i;
  return "FaileD";
}

string FloatToStr(float i) {
  return sprintf("%f", i);
}

string ask_imbue(string type) {
  object *obs;
  int i, pp = 0, sp = 0, gp = 0, bp = 0;
  string str = "我想想看啊…………………………………………………………\n";

  if (type == "weapon") type = USER_WEAPON;
  else if (type == "armor") type = USER_ARMOR;
  else return 0;

  obs = filter_array(children(type), (: clonep :));
  i = sizeof(obs);
  if (i && i > 0) {
    while (i--) {
      switch (obs[i]->query("imbued")) {
        case 5: pp++; break;
        case 4: sp++; break;
        case 3: gp++; break;
        case 2: bp++; break;
        case 1:
        default: break;
      }
    }
  }
  if (pp > 0) {
    str += "		     目前游戏里已经有了" + chinese_number(pp) + "把传说中的";
    str += type == USER_WEAPON ? "武器。\n" : "防具。\n";
  }
  if (sp > 0) {
    str += "		     目前游戏里已经有了" + chinese_number(sp) + "把最高等级的";
    str += type == USER_WEAPON ? "武器。\n" : "防具。\n";
  }
  if (gp > 0) {
    str += "		     目前游戏里已经有了" + chinese_number(gp) + "把高等级的";
    str += type == USER_WEAPON ? "武器。\n" : "防具。\n";
  }
  if (bp > 0) {
    str += "		     目前游戏里已经有了" + chinese_number(bp) + "把低等级的";
    str += type == USER_WEAPON ? "武器。\n" : "防具。\n";
  }
  return str;
}

nosave string spe_name = " ";
nosave string jade_show = " ";
nosave string item_show = " ";
nosave int is_prop = 0;
nosave int is_sure = 0;
nosave string add_type = " ";
nosave int add_use = 1;
nosave string add_numa = "";
nosave float add_numb = 0;
nosave string can_wield = " ";
nosave string just_for = " ";
nosave int if_next = 0;
nosave int status_type = 0;  //无任何冲突

int status_armor_lists(int i, int t) {
  if (i == 0) i = 1 + random(37);
  ///init
  spe_name = " ";
  jade_show = " ";
  item_show = " ";
  is_prop = 0;
  is_sure = 0;
  add_type = " ";
  add_use = 1;
  add_numa = "";
  add_numb = 0;
  can_wield = " ";
  just_for = " ";
  if_next = 0;
  status_type = 0;
  switch (i) {
    case 1:
      spe_name = HIC "优良";
      jade_show = "纯度增加";
      item_show = "加强防御";
      is_prop = 1;
      is_sure = 1;
      add_type = "armor";
      add_use = 3;
      add_numa = FloatToStr(1.1);
      status_type = 1;
      break;
    case 2:
      spe_name = HIC "上品";
      jade_show = "纯度叠加";
      item_show = "上品防御";
      is_prop = 1;
      is_sure = 1;
      add_type = "armor";
      add_use = 3;
      add_numa = FloatToStr(1.2);
      status_type = 1;
      break;
    case 3:
      spe_name = HIW "极品";
      jade_show = "极品纯度";
      item_show = "极品防御";
      is_prop = 1;
      is_sure = 1;
      add_type = "armor";
      add_use = 3;
      add_numa = FloatToStr(1.3);
      status_type = 1;
      break;
    case 4:
      spe_name = GRN "柔水";
      jade_show = "柔水质地";
      item_show = "最大内力要求减小半";
      is_sure = 1;
      add_type = "wear_maxneili";
      add_use = 3;
      add_numa = FloatToStr(0.75);
      status_type = 2;
      break;
    case 5:
      spe_name = GRN "柔晶";
      jade_show = "柔晶质地";
      item_show = "最大内力要求减半";
      is_sure = 1;
      add_type = "wear_maxneili";
      add_use = 3;
      add_numa = FloatToStr(0.5);
      status_type = 2;
      break;
    case 6:
      spe_name = GRN "丽水";
      jade_show = "丽水质地";
      item_show = "最大内力要求减大半";
      is_sure = 1;
      add_type = "wear_maxneili";
      add_use = 3;
      add_numa = FloatToStr(0.4);
      status_type = 2;
      break;
    case 7:
      spe_name = GRN "丽晶";
      jade_show = "丽晶质地";
      item_show = "无最大内力要求";
      is_sure = 1;
      add_type = "wear_maxneili";
      add_use = 5;
      add_numa = FloatToStr(0.0);
      status_type = 2;
      break;
    case 8:
      spe_name = HIW "凝水";
      jade_show = "凝水质地";
      item_show = "内力要求减小半";
      is_sure = 1;
      add_type = "wear_neili";
      add_use = 3;
      add_numa = FloatToStr(0.75);
      status_type = 3;
      break;
    case 9:
      spe_name = HIW "凝晶";
      jade_show = "凝晶质地";
      item_show = "内力要求减半";
      is_sure = 1;
      add_type = "wear_neili";
      add_use = 3;
      add_numa = FloatToStr(0.5);
      status_type = 3;
      break;
    case 10:
      spe_name = HIW "玉水";
      jade_show = "玉水质地";
      item_show = "内力要求减大半";
      is_sure = 1;
      add_type = "wear_neili";
      add_use = 3;
      add_numa = FloatToStr(0.4);
      status_type = 3;
      break;
    case 11:
      spe_name = GRN "玉晶";
      jade_show = "玉晶质地";
      item_show = "无内力要求";
      is_sure = 1;
      add_type = "wear_neili";
      add_use = 5;
      add_numa = FloatToStr(0.0);
      status_type = 3;
      break;
    case 12:
      spe_name = HIG "华彩";
      jade_show = "色泽华彩";
      item_show = "膂力要求减小半";
      is_sure = 1;
      add_type = "wear_str";
      add_use = 3;
      add_numa = FloatToStr(0.75);
      status_type = 4;
      break;
    case 13:
      spe_name = HIG "光彩";
      jade_show = "色泽光彩";
      item_show = "膂力要求减半";
      is_sure = 1;
      add_type = "wear_str";
      add_use = 3;
      add_numa = FloatToStr(0.5);
      status_type = 4;
      break;
    case 14:
      spe_name = HIG "彩华";
      jade_show = "色泽彩华";
      item_show = "膂力要求减大半";
      is_sure = 1;
      add_type = "wear_str";
      add_use = 3;
      add_numa = FloatToStr(0.4);
      status_type = 4;
      break;
    case 15:
      spe_name = HIG "光华";
      jade_show = "色泽光华";
      item_show = "无膂力要求";
      is_sure = 1;
      add_type = "wear_str";
      add_use = 5;
      add_numa = FloatToStr(0.0);
      status_type = 4;
      break;
    case 16:
      spe_name = HIG "柳絮";
      jade_show = "印有柳纹";
      item_show = "减少重量";
      is_sure = 1;
      add_type = "weight";
      add_use = 3;
      add_numa = FloatToStr(0.75);
      status_type = 5;
      break;
    case 17:
      spe_name = "飞絮";
      jade_show = "印有玄纹";
      item_show = "重量减半";
      is_sure = 1;
      add_type = "weight";
      add_use = 3;
      add_numa = FloatToStr(0.5);
      status_type = 5;
      break;
    case 18:
      spe_name = WHT "天灵";
      jade_show = "悟性+$x";
      item_show = "增加悟性";
      is_prop = 1;
      add_numa = FloatToStr(1.0);
      add_numb = 7;
      add_type = "intelligence";
      add_use = 1;
      break;
    case 19:
      spe_name = BLU "天玄";
      jade_show = "根骨+$x";
      item_show = "增加根骨";
      is_prop = 1;
      add_numa = FloatToStr(1.0);
      add_numb = 7;
      add_type = "constitution";
      add_use = 1;
      break;
    case 20:
      spe_name = HIM "天宇";
      jade_show = "臂力+$x";
      item_show = "增加臂力";
      is_prop = 1;
      add_numa = FloatToStr(1.0);
      add_numb = 7;
      add_type = "strength";
      add_use = 1;
      break;
    case 21:
      spe_name = MAG "天渊";
      jade_show = "身法+$x";
      item_show = "增加身法";
      is_prop = 1;
      add_numa = FloatToStr(1.0);
      add_numb = 7;
      add_type = "dexerity";
      add_use = 1;
      break;
    case 22:
      spe_name = WHT "三才";
      jade_show = "增加所有属性";
      item_show = "增加所有属性";
      is_prop = 1;
      add_numa = FloatToStr(1.0);
      add_numb = 7;
      add_use = 1;
      switch (t) {
        case 0:
          add_type = "intelligence";
          if_next = 1;
          break;
        case 1:
          add_type = "constitution";
          if_next = 1;
          break;
        case 2:
          add_type = "dexerity";
          if_next = 1;
          break;
        case 3:
          add_type = "sharpness";
          break;
      }
      break;
    case 23:
      spe_name = HIG "长生";
      jade_show = "增加气血+$x";
      item_show = "增加气血";
      is_prop = 1;
      add_numa = FloatToStr(200.0);
      add_numb = 1000;
      add_type = "qi";
      add_use = 1;
      break;
    case 24:
      spe_name = HIG "不老";
      jade_show = "增加精血+$x";
      item_show = "增加精血";
      is_prop = 1;
      add_numa = FloatToStr(200.0);
      add_numb = 1000;
      add_type = "jing";
      add_use = 1;
      break;
    case 25:
      spe_name = HIG "小周天";
      jade_show = "增加精力+$x";
      item_show = "增加精力";
      is_prop = 1;
      add_numa = FloatToStr(200.0);
      add_numb = 1000;
      add_type = "jingli";
      add_use = 1;
      break;
    case 26:
      spe_name = HIG "大周天";
      jade_show = "增加内力+$x";
      item_show = "增加内力";
      is_prop = 1;
      add_numa = FloatToStr(200.0);
      add_numb = 1000;
      add_type = "neili";
      add_use = 1;
      break;
    case 27:
      spe_name = HIW "闪电";
      jade_show = "增加命中+$x";
      item_show = "增加命中";
      is_prop = 1;
      add_numa = FloatToStr(20.0);
      add_numb = 100;
      add_type = "attack";
      add_use = 1;
      break;
    case 28:
      spe_name = HIG "体灵";
      jade_show = "气血恢复+$x%";
      item_show = "提高气血恢复";
      is_prop = 1;
      add_numa = FloatToStr(5.0);
      add_numb = 35;
      add_type = "re_qi";
      add_use = 1;
      break;
    case 29:
      spe_name = HIG "智灵";
      jade_show = "精血恢复+$x%";
      item_show = "提高精血恢复";
      is_prop = 1;
      add_numa = FloatToStr(5.0);
      add_numb = 35;
      add_type = "re_jing";
      add_use = 1;
      break;
    case 30:
      spe_name = HIG "心灵";
      jade_show = "精力恢复+$x%";
      item_show = "提高精力恢复";
      is_prop = 1;
      add_numa = FloatToStr(5.0);
      add_numb = 35;
      add_type = "re_jingli";
      add_use = 1;
      break;
    case 31:
      spe_name = HIG "合灵";
      jade_show = "内力恢复+$x%";
      item_show = "提高内力恢复";
      is_prop = 1;
      add_numa = FloatToStr(5.0);
      add_numb = 35;
      add_type = "re_neili";
      add_use = 1;
      break;
    case 32:
      spe_name = HIC "龙灵";
      jade_show = "提高体质恢复";
      item_show = "提高体质恢复";
      is_prop = 1;
      add_numa = FloatToStr(5.0);
      add_numb = 35;
      add_use = 1;
      switch (t) {
        case 0:
          add_type = "re_qi";
          if_next = 1;
          break;
        case 1:
          add_type = "re_jing";
          if_next = 1;
          break;
        case 2:
          add_type = "re_jingli";
          if_next = 1;
          break;
        case 3:
          add_type = "re_neili";
          break;
      }
      break;
    case 33:
      spe_name = HIC "御邪";
      jade_show = "抗毒+$x%";
      item_show = "抵御毒性";
      is_prop = 1;
      add_numa = FloatToStr(10.0);
      add_numb = 10;
      add_type = "antipoison";
      add_use = 1;
      status_type = 87;
      break;
    case 34:
      spe_name = HIC "避邪";
      jade_show = "抗毒+$x";
      item_show = "消弱毒性";
      is_prop = 1;
      add_numa = FloatToStr(6.0);
      add_numb = 6;
      add_type = "antipoison";
      add_use = 1;
      status_type = 87;
      break;

    case 35:
      spe_name = HIM "紫石";
      jade_show = "防御+$x";
      item_show = "提高防御";
      is_prop = 1;
      add_numa = FloatToStr(15.0);
      add_numb = 15;
      add_type = "parry";
      add_use = 1;
      status_type = 88;
      break;
    case 36:
      spe_name = HIW "白石";
      jade_show = "躲避+$x";
      item_show = "提高躲避";
      is_prop = 1;
      add_numa = FloatToStr(15.0);
      add_numb = 15;
      add_type = "dodge";
      add_use = 1;
      status_type = 89;
      break;
    case 37:
      spe_name = RED "红石";
      jade_show = "内功+$x";
      item_show = "提高内功";
      is_prop = 1;
      add_numa = FloatToStr(15.0);
      add_numb = 15;
      add_type = "force";
      add_use = 1;
      status_type = 90;
      break;
      /*
		case 25:
			spe_name = HIB"夜叉";
			jade_show = "夜叉特性";
			item_show = "增加所有属性";
			is_prop=1;
			add_numa=FloatToStr(1.0);
			add_numb=7;
			add_use = 1;
			switch(t){
				case 0:
					add_type ="intelligence";
					if_next=1;
					break;
				case 1:
					add_type ="constitution";
					if_next=1;
					break;
				case 2:
					add_type ="dexerity";
					if_next=1;
					break;
				case 3:
					add_type ="sharpness";					
					break;								
			}
			break;
			*/

  }
  return i;
}

int status_weapon_lists(int i, int t) {
  if (i == 0) i = 1 + random(37);
  ///init
  spe_name = " ";
  jade_show = " ";
  item_show = " ";
  is_prop = 0;
  is_sure = 0;
  add_type = " ";
  add_use = 1;
  add_numa = "";
  add_numb = 0;
  can_wield = " ";
  just_for = " ";
  if_next = 0;
  status_type = 0;
  switch (i) {
    case 1:
      spe_name = HIC "优良";
      jade_show = "纯度增加";
      item_show = "加强威力";
      is_prop = 1;
      is_sure = 1;
      add_type = "damage";
      add_use = 3;
      add_numa = FloatToStr(1.1);
      status_type = 1;
      break;
    case 2:
      spe_name = HIC "上品";
      jade_show = "纯度叠加";
      item_show = "上品威力";
      is_prop = 1;
      is_sure = 1;
      add_type = "damage";
      add_use = 3;
      add_numa = FloatToStr(1.2);
      status_type = 1;
      break;
    case 3:
      spe_name = HIW "极品";
      jade_show = "极品纯度";
      item_show = "极品威力";
      is_prop = 1;
      is_sure = 1;
      add_type = "damage";
      add_use = 3;
      add_numa = FloatToStr(1.3);
      status_type = 1;
      break;
    case 4:
      spe_name = GRN "柔水";
      jade_show = "柔水质地";
      item_show = "最大内力要求减小半";
      is_sure = 1;
      add_type = "wield_maxneili";
      add_use = 3;
      add_numa = FloatToStr(0.75);
      status_type = 2;
      break;
    case 5:
      spe_name = GRN "柔晶";
      jade_show = "柔晶质地";
      item_show = "最大内力要求减半";
      is_sure = 1;
      add_type = "wield_maxneili";
      add_use = 3;
      add_numa = FloatToStr(0.5);
      status_type = 2;
      break;
    case 6:
      spe_name = GRN "丽水";
      jade_show = "丽水质地";
      item_show = "最大内力要求减大半";
      is_sure = 1;
      add_type = "wield_maxneili";
      add_use = 3;
      add_numa = FloatToStr(0.4);
      status_type = 2;
      break;
    case 7:
      spe_name = GRN "丽晶";
      jade_show = "丽晶质地";
      item_show = "无最大内力要求";
      is_sure = 1;
      add_type = "wield_maxneili";
      add_use = 5;
      add_numa = FloatToStr(0.0);
      status_type = 2;
      break;
    case 8:
      spe_name = HIW "凝水";
      jade_show = "凝水质地";
      item_show = "内力要求减小半";
      is_sure = 1;
      add_type = "wield_neili";
      add_use = 3;
      add_numa = FloatToStr(0.75);
      status_type = 3;
      break;
    case 9:
      spe_name = HIW "凝晶";
      jade_show = "凝晶质地";
      item_show = "内力要求减半";
      is_sure = 1;
      add_type = "wield_neili";
      add_use = 3;
      add_numa = FloatToStr(0.5);
      status_type = 3;
      break;
    case 10:
      spe_name = HIW "玉水";
      jade_show = "玉水质地";
      item_show = "内力要求减大半";
      is_sure = 1;
      add_type = "wield_neili";
      add_use = 3;
      add_numa = FloatToStr(0.4);
      status_type = 3;
      break;
    case 11:
      spe_name = GRN "玉晶";
      jade_show = "玉晶质地";
      item_show = "无内力要求";
      is_sure = 1;
      add_type = "wield_neili";
      add_use = 5;
      add_numa = FloatToStr(0.0);
      status_type = 3;
      break;
    case 12:
      spe_name = HIG "华彩";
      jade_show = "色泽华彩";
      item_show = "膂力要求减小半";
      is_sure = 1;
      add_type = "wield_str";
      add_use = 3;
      add_numa = FloatToStr(0.75);
      status_type = 4;
      break;
    case 13:
      spe_name = HIG "光彩";
      jade_show = "色泽光彩";
      item_show = "膂力要求减半";
      is_sure = 1;
      add_type = "wield_str";
      add_use = 3;
      add_numa = FloatToStr(0.5);
      status_type = 4;
      break;
    case 14:
      spe_name = HIG "彩华";
      jade_show = "色泽彩华";
      item_show = "膂力要求减大半";
      is_sure = 1;
      add_type = "wield_str";
      add_use = 3;
      add_numa = FloatToStr(0.4);
      status_type = 4;
      break;
    case 15:
      spe_name = HIG "光华";
      jade_show = "色泽光华";
      item_show = "无膂力要求";
      is_sure = 1;
      add_type = "wield_str";
      add_use = 5;
      add_numa = FloatToStr(0.0);
      status_type = 4;
      break;
    case 16:
      spe_name = HIG "柳絮";
      jade_show = "印有柳纹";
      item_show = "减少重量";
      is_sure = 1;
      add_type = "weight";
      add_use = 3;
      add_numa = FloatToStr(0.75);
      status_type = 5;
      break;
    case 17:
      spe_name = "飞絮";
      jade_show = "印有玄纹";
      item_show = "重量减半";
      is_sure = 1;
      add_type = "weight";
      add_use = 3;
      add_numa = FloatToStr(0.5);
      status_type = 5;
      break;
    case 18:
      spe_name = GRN "斑竹";
      jade_show = "印有竹纹";
      item_show = "无重量";
      is_sure = 1;
      add_type = "weight";
      add_use = 5;
      add_numa = FloatToStr(0.0);
      status_type = 5;
      break;
    case 19:
      spe_name = HIW "淬制";
      jade_show = "锋利度+$x";
      item_show = "增加锋利度";
      add_numa = FloatToStr(1.0);
      add_numb = 4;
      add_type = "sharpness";
      add_use = 1;
      break;
    case 20:
      spe_name = HIY "巧制";
      jade_show = "硬度+$x";
      item_show = "增加硬度";
      add_numa = FloatToStr(1.0);
      add_numb = 4;
      add_type = "rigidity";
      add_use = 1;
      break;
    case 21:
      spe_name = WHT "天灵";
      jade_show = "悟性+$x";
      item_show = "增加悟性";
      is_prop = 1;
      add_numa = FloatToStr(1.0);
      add_numb = 7;
      add_type = "intelligence";
      add_use = 1;
      break;
    case 22:
      spe_name = BLU "天玄";
      jade_show = "根骨+$x";
      item_show = "增加根骨";
      is_prop = 1;
      add_numa = FloatToStr(1.0);
      add_numb = 7;
      add_type = "constitution";
      add_use = 1;
      break;
    case 23:
      spe_name = HIM "天宇";
      jade_show = "臂力+$x";
      item_show = "增加臂力";
      is_prop = 1;
      add_numa = FloatToStr(1.0);
      add_numb = 7;
      add_type = "strength";
      add_use = 1;
      break;
    case 24:
      spe_name = MAG "天渊";
      jade_show = "身法+$x";
      item_show = "增加身法";
      is_prop = 1;
      add_numa = FloatToStr(1.0);
      add_numb = 7;
      add_type = "dexerity";
      add_use = 1;
      break;
    case 25:
      spe_name = WHT "三才";
      jade_show = "增加所有属性";
      item_show = "增加所有属性";
      is_prop = 1;
      add_numa = FloatToStr(1.0);
      add_numb = 7;
      add_use = 1;
      switch (t) {
        case 0:
          add_type = "intelligence";
          if_next = 1;
          break;
        case 1:
          add_type = "constitution";
          if_next = 1;
          break;
        case 2:
          add_type = "dexerity";
          if_next = 1;
          break;
        case 3:
          add_type = "sharpness";
          break;
      }
      break;
    case 26:
      spe_name = HIG "长生";
      jade_show = "增加气血+$x";
      item_show = "增加气血";
      is_prop = 1;
      add_numa = FloatToStr(200.0);
      add_numb = 1000;
      add_type = "qi";
      add_use = 1;
      break;
    case 27:
      spe_name = HIG "不老";
      jade_show = "增加精血+$x";
      item_show = "增加精血";
      is_prop = 1;
      add_numa = FloatToStr(200.0);
      add_numb = 1000;
      add_type = "jing";
      add_use = 1;
      break;
    case 28:
      spe_name = HIG "小周天";
      jade_show = "增加精力+$x";
      item_show = "增加精力";
      is_prop = 1;
      add_numa = FloatToStr(200.0);
      add_numb = 1000;
      add_type = "jingli";
      add_use = 1;
      break;
    case 29:
      spe_name = HIG "大周天";
      jade_show = "增加内力+$x";
      item_show = "增加内力";
      is_prop = 1;
      add_numa = FloatToStr(200.0);
      add_numb = 1000;
      add_type = "neili";
      add_use = 1;
      break;
    case 31:
      spe_name = HIW "闪电";
      jade_show = "增加命中+$x";
      item_show = "增加命中";
      is_prop = 1;
      add_numa = FloatToStr(20.0);
      add_numb = 100;
      add_type = "attack";
      add_use = 1;
      break;
    case 32:
      spe_name = HIG "体灵";
      jade_show = "气血恢复+$x%";
      item_show = "提高气血恢复";
      is_prop = 1;
      add_numa = FloatToStr(5.0);
      add_numb = 35;
      add_type = "re_qi";
      add_use = 1;
      break;
    case 33:
      spe_name = HIG "智灵";
      jade_show = "精血恢复+$x%";
      item_show = "提高精血恢复";
      is_prop = 1;
      add_numa = FloatToStr(5.0);
      add_numb = 35;
      add_type = "re_jing";
      add_use = 1;
      break;
    case 34:
      spe_name = HIG "心灵";
      jade_show = "精力恢复+$x%";
      item_show = "提高精力恢复";
      is_prop = 1;
      add_numa = FloatToStr(5.0);
      add_numb = 35;
      add_type = "re_jingli";
      add_use = 1;
      break;
    case 35:
      spe_name = HIG "合灵";
      jade_show = "内力恢复+$x%";
      item_show = "提高内力恢复";
      is_prop = 1;
      add_numa = FloatToStr(5.0);
      add_numb = 35;
      add_type = "re_neili";
      add_use = 1;
      break;
    case 36:
      spe_name = HIC "龙灵";
      jade_show = "提高体质恢复";
      item_show = "提高体质恢复";
      is_prop = 1;
      add_numa = FloatToStr(5.0);
      add_numb = 35;
      add_use = 1;
      switch (t) {
        case 0:
          add_type = "re_qi";
          if_next = 1;
          break;
        case 1:
          add_type = "re_jing";
          if_next = 1;
          break;
        case 2:
          add_type = "re_jingli";
          if_next = 1;
          break;
        case 3:
          add_type = "re_neili";
          break;
      }
      break;
      /*
		case 37:
			spe_name = HIB"千蛛";
			jade_show = "千蛛毒";
			item_show = "千蛛毒";			
			status_type=6;
			switch(t){
				case 0:
					add_numa=FloatToStr(300.0);
					add_numb=300;
					add_use = 1;
					add_type ="poison_number";
					if_next=1;
					break;
				case 1:
					add_numa="qzhu_poison";
					add_use = 5;
					add_type ="poisoned";
					break;
			}
			break;
		case 38:
			spe_name = BLU"天蝎";
			jade_show = "天蝎毒";
			item_show = "天蝎毒";			
			status_type=6;
			switch(t){
				case 0:
					add_numa=FloatToStr(300.0);
					add_numb=300;
					add_use = 1;
					add_type ="poison_number";
					if_next=1;
					break;
				case 1:
					add_numa="scorpion_poison";
					add_use = 5;
					add_type ="poisoned";
					break;
			}
			break;
		case 39:
			spe_name = CYN"寒冰";
			jade_show = "寒冰毒";
			item_show = "寒冰毒";			
			status_type=6;
			switch(t){
				case 0:
					add_numa=FloatToStr(300.0);
					add_numb=300;
					add_use = 1;
					add_type ="poison_number";
					if_next=1;
					break;
				case 1:
					add_numa="hb_poison";
					add_use = 5;
					add_type ="poisoned";
					break;
			}
			break;
		case 40:
			spe_name = HIB"一品毒";
			jade_show = "怪蛇毒";
			item_show = "怪蛇毒";			
			status_type=6;
			switch(t){
				case 0:
					add_numa=FloatToStr(300.0);
					add_numb=300;
					add_use = 1;
					add_type ="poison_number";
					if_next=1;
					break;
				case 1:
					add_numa="bt_poison";
					add_use = 5;
					add_type ="poisoned";
					break;
			}
			break;
		case 41:
			spe_name = HIB"剧毒";
			jade_show = "剧毒";
			item_show = "剧毒";		
			status_type=6;	
			switch(t){
				case 0:
					add_numa=FloatToStr(300.0);
					add_numb=300;
					add_use = 1;
					add_type ="poison_number";
					if_next=1;
					break;
				case 1:
					add_numa="xx_poison";
					add_use = 5;
					add_type ="poisoned";
					break;
			}
			break;
		case 42:
			spe_name = HIR"火焰";
			jade_show = "火焰毒";
			item_show = "火焰毒";			
			status_type=6;
			switch(t){
				case 0:
					add_numa=FloatToStr(300.0);
					add_numb=300;
					add_use = 1;
					add_type ="poison_number";
					if_next=1;
					break;
				case 1:
					add_numa="hot_poison";
					add_use = 5;
					add_type ="poisoned";
					break;
			}
			break;
		case 43:
			spe_name = BLU"腐尸";
			jade_show = "腐尸毒";
			item_show = "腐尸毒";			
			status_type=6;
			switch(t){
				case 0:
					add_numa=FloatToStr(300.0);
					add_numb=300;
					add_use = 1;
					add_type ="poison_number";
					if_next=1;
					break;
				case 1:
					add_numa="fs_poison";
					add_use = 5;
					add_type ="poisoned";
					break;
			}
			break;
		case 44:
			spe_name = HIG"绿波";
			jade_show = "绿波毒";
			item_show = "绿波毒";			
			status_type=6;
			switch(t){
				case 0:
					add_numa=FloatToStr(300.0);
					add_numb=300;
					add_use = 1;
					add_type ="poison_number";
					if_next=1;
					break;
				case 1:
					add_numa="lvbo_poison";
					add_use = 5;
					add_type ="poisoned";
					break;
			}
			break;
		case 45:
			spe_name = CYN"寒毒";
			jade_show = "寒毒";
			item_show = "寒毒";			
			status_type=6;
			switch(t){
				case 0:
					add_numa=FloatToStr(300.0);
					add_numb=300;
					add_use = 1;
					add_type ="poison_number";
					if_next=1;
					break;
				case 1:
					add_numa="cold_poison";
					add_use = 5;
					add_type ="poisoned";
					break;
			}
			break;
		case 46:
			spe_name = HIR"蔓陀萝";
			jade_show = "蔓陀萝毒";
			item_show = "蔓陀萝毒";			
			status_type=6;
			switch(t){
				case 0:
					add_numa=FloatToStr(300.0);
					add_numb=300;
					add_use = 1;
					add_type ="poison_number";
					if_next=1;
					break;
				case 1:
					add_numa="man_poison";
					add_use = 5;
					add_type ="poisoned";
					break;
			}
			break;
		case 47:
			spe_name = CYN"青蛇";
			jade_show = "青蛇毒";
			item_show = "青蛇毒";			
			status_type=6;
			switch(t){
				case 0:
					add_numa=FloatToStr(300.0);
					add_numb=300;
					add_use = 1;
					add_type ="poison_number";
					if_next=1;
					break;
				case 1:
					add_numa="snake_poison";
					add_use = 5;
					add_type ="poisoned";
					break;
			}
			break;
		*/
  }
  return i;
}
