/* 
 .H file for user_weapond.c
 Created by snowman@SJ 21/04/2001
 Modified by kuku@sjsh 2003.2
*/

#define USER_WEAPON  "/d/quest/dazao/user_weapon"

#define DEFAULT_SETTINGS ([ \
         "wield_maxneili": 500,\
         "wield_neili":    50,\
         "wield_str":        17,\
         "long":             "",\
         "material":         "steel",\
         "wield_msg":        "$N将$n握在手中。\n",\
         "unwield_msg":    "$N将手中的$n放下。\n",\
         "no_sell":           1,\
         "imbued":            1,\
])
//木材材料列表 
nosave string* woods = ({  
        "红木", "杉木", "松木", "橡木", "楠木",  
        "樟木", "柚木", "柏木", "花梨木", "花榈木", 
        "胡桃木", "紫檀木", "黑檀木", "檀香木", 
}); 
       
//金属材料列表 
nosave string* metals = ({ 
        "黄金", "白金", "紫金", "白银", "青铜", 
        "紫铜", "黄铜", "赤铁", "黄铁", "铸铁", 
        "镍铁", "铸钢", "镍钢", 
}); 

nosave mapping SPECIAL_B = ([ 
         "imbued":             5,
         "material":           "xuantie",
         "wield_maxneili":   5000 + random(5000),
         "wield_neili": 1000 + random(1000),
         "wield_str":          30 + random(35),
         "wield_msg":          HIG"\n$N将手在风中一挥，无数的火星从四方飞来，渐渐聚在一起～～～一柄$n"HIG"已经出现在$P手中！\n"NOR,
         "unwield_msg": HIG"\n$N将$n"HIG"随手一扔，只见$n"HIG"突然变得火红，化做无数的火星四散飘走了！\n"NOR,
         ]);

nosave mapping SUPER_B = ([   
         "imbued":             4,
         "material":           "supersteel",
         "sharpness":          3,
         "rigidity":           3,
         "wield_maxneili":   4000 + random(4000),
         "wield_neili": 800 + random(800),
         "wield_str":          20 + random(30),
         "wield_msg":          HIW"\n$N将手一挥，一柄$n"HIW"从身后飞出，电光一闪，已经握在了$P手中。\n"NOR,
         "unwield_msg": HIW"\n$N将手中的$n"HIW"一弹，电光闪耀中，已不见了$n"HIW"的踪迹。\n"NOR,
         ]);

nosave mapping GREAT_B = ([   
         "imbued":             3,
         "material":           "greatsteel",
         "sharpness":          2,
         "rigidity":           2,
         "wield_maxneili":   2500 + random(2500),
         "wield_neili": 500 + random(500),
         "wield_str":          15 + random(25),
         "wield_msg":          "\n$N将一柄$n抽出握在了手中。\n",
         "unwield_msg": "\n$N将手中的$n放回了武器囊。\n",
         ]);

nosave mapping GOOD_B = ([   
         "imbued":             2,
         "material":           "steel",
         "sharpness":          1,
         "rigidity":           1,
         "wield_maxneili":   1000 + random(2000),
         "wield_neili": 100 + random(100),
         "wield_str":          10 + random(15),
         ]);        

nosave mapping WEAPON_MAP = ([    
         "sword" : ([   
                 "name":                        "剑",
                 "basic_name":          "长",
                 "b_id":                        "jian",
                 "skill_type":          "sword",
                 "verbs":               ({ "slash", "hack", "slice", "thrust" }),
                 "unit":                        "把",
                 "weight":              2000 + random(3000),
                 "flag":                        4,]),
         "xiao" : ([  
                 "name":                        "箫",
                 "basic_name":          "铁",
                 "b_id":                        "xiao",
                 "skill_type":          "sword",
                 "verbs":               ({ "slash", "hack", "slice", "thrust" }),
                 "unit":                        "只",
                 "weight":              1000 + random(2000),
                 "flag":                        8,]),
         "axe" : ([   
                 "name":                        "斧",
                 "basic_name":          "手",
                 "b_id":                        "fu",
                 "skill_type":          "axe",
                 "verbs":               ({ "chop", "slice", "hack" }),
                 "unit":                        "柄",
                 "weight":              4000 + random(10000),
                 "flag":                        4,]),
         "blade": ([  
                 "name":                        "刀",
                 "basic_name":          "单",
                 "b_id":                        "dao",
                 "skill_type":          "blade",
                 "verbs":               ({ "slash", "slice", "hack" }),
                 "unit":                        "把",
                 "weight":              2000 + random(3000),
                 "flag":                        4,]),
         "mace": ([  
                 "name":                        "锏",
                 "basic_name":          "铜",
                 "b_id":                        "jian",
                 "skill_type":          "mace",
                 "verbs":               ({ "pierce", "slice", "thrust","slam" }),
                 "unit":                        "根",
                 "weight":              2000 + random(2000),
                 "flag":                        8,]),
         "club": ([  
                 "name":                        "棍",
                 "basic_name":          "铁",
                 "b_id":                        "gun",
                 "skill_type":          "club",
                 "rigidity":            1,
                 "verbs":               ({ "bash", "crush", "slam" }),
                 "unit":                        "根",
                 "weight":              4000 + random(9000),
                 "flag":                        16,]),
        "dagger": ([ 
                 "name":                        "匕",
                 "basic_name":          "短",
                 "b_id":                        "bishou",
                 "skill_type":          "dagger",
                 "dagger_count":                5,
                 "verbs":               ({ "slice", "pierce", "thrust" }),
                 "unit":                        "把",
                 "weight":              500 + random(1000),
                 "flag":                        4,]),
         "fork": ([  
                 "name":                        "叉",
                 "basic_name":          "鱼",
                 "skill_type":          "fork",
                 "b_id":                        "cha",
                 "verbs":               ({ "thrust", "pierce", "impale" }),
                 "unit":                        "根",
                 "weight":              4000 + random(4000),
                 "flag":                        8,]),
         "hammer": ([  
                 "name":                        "锤",
                 "basic_name":          "钉头",
                 "b_id":                        "chui",
                 "skill_type":          "hammer",
                 "rigidity":            1,
                 "hammer_count":                5,
                 "verbs":               ({ "bash", "crush", "slam" }),
                 "unit":                        "柄",
                 "weight":              10000 + random(18000),
                 "flag":                        1,]),
         "hook": ([  
                 "name":                        "钩",
                 "basic_name":          "单手",
                 "skill_type":          "hook",
                 "b_id":                        "gou",
                 "verbs":               ({ "impale", "slash", "hack", }),
                 "unit":                        "把",
                 "weight":              3000 + random(4000),
                 "flag":                        4,]),
         "spear": ([  
                 "name":                        "枪",
                 "basic_name":          "长",
                 "b_id":                        "qiang",
                 "skill_type":          "spear",
                 "verbs":               ({ "thrust", "pierce", "impale" }),
                 "unit":                        "根",
                 "weight":              3000 + random(5000),
                 "flag":                        8,]),
         "staff": ([  
                 "name":                        "杖",
                 "basic_name":          "拐",
                 "b_id":                        "zhang",
                 "skill_type":          "staff",
                 "rigidity":            1,
                 "verbs":               ({ "bash", "crush", "slam" }),
                 "unit":                        "根",
                 "weight":              6000 + random(7000),
                 "flag":                        16,]),
         "stick": ([  
                 "name":                        "棒",
                 "basic_name":          "钢",
                 "b_id":                        "bang",
                 "skill_type":          "stick",
                 "rigidity":            1,
                 "verbs":               ({ "bash", "crush", "slam" }),
                 "unit":                        "根",
                 "weight":              4000 + random(6000),
                 "flag":                        16,]),
         "whip": ([  
                 "name":                        "鞭",
                 "basic_name":          "铁",
                 "b_id":                        "bian",
                 "skill_type":          "whip",
                 "verbs":               ({ "whip" }),
                 "unit":                        "根",
                 "weight":              1000 + random(3000),
                 "flag":                        0,]),
]);

nosave mapping Special_Class = ([   
RED"干将" : ([ "id": ({ "ganjiang jian","ganjiang", "sword", "jian" }),
                "long2" : RED"干将宝剑，威力无比，能开天辟地，荡妖除魔！\n"NOR,
                "weapon_prop/damage":  350,
                "sharpness":           10,
                "rigidity":            9,
                ]),
RED"莫邪" : ([ "id": ({ "moye jian","moye", "sword", "jian" }),
                "long2" : RED"莫邪宝剑，锋利无比，能开天辟地，荡妖除魔！\n"NOR,
                "weapon_prop/damage":  300,
                "sharpness":           15,
                "rigidity":            9,
                ]),
RED"鱼肠" : ([ "id": ({ "yuchang jian", "yuchang", "sword", "jian" }),
                "long2" : RED"鱼肠宝剑，轻巧无比，能开天辟地，荡妖除魔！\n"NOR,
                "weapon_prop/damage":  220,
                "weapon_prop/attack":  300,
                "weapon_prop/sword":   100,
                "sharpness":           8,
                "rigidity":            7,
                ]),
RED"太阿" : ([ "id": ({ "taie jian", "taie", "sword", "jian" }),
                "long2" : RED"太阿宝剑，帝王之兵，持之能号令天下，莫有不从！\n"NOR,
                "weapon_prop/damage":  150,
                "weapon_prop/kee":      4000,
                "weapon_prop/sen":    4000,
                "sharpness":           7,
                "rigidity":            9,
                ]),
RED"巨阙" : ([ "id": ({ "juque jian", "juque", "sword", "jian" }),
                "long2" : RED"巨阙宝剑，坚硬无比，能开天辟地，荡妖除魔！\n"NOR,
                "weapon_prop/damage":  270,
                "sharpness":           7,
                "rigidity":            20,
                ]),
RED"纯钧" : ([ "id": ({ "chunjun jian", "chunjun", "sword", "jian" }),
                "long2" : RED"纯钩宝剑，将帅之兵，持之能挥军百万，克敌制胜！\n"NOR,
                "weapon_prop/damage":  150,
                "weapon_prop/mana":  4000,
                "weapon_prop/force":   4000,
                "sharpness":           7,
                "rigidity":            8,
                ]),
RED"湛卢" : ([ "id": ({ "zhanlu jian", "zhanlu", "sword", "jian"        }),
                "long2" : RED"湛卢宝剑，威力、锋利、坚硬都冠绝当世，乃千古神兵！\n"NOR,
                "weapon_prop/damage":  290,
                "sharpness":           12,
                "rigidity":            12,
                ]),
RED"工布" : ([ "id": ({ "gongbu jian", "gongbu", "sword", "jian" }),
                "long2" : RED"工布宝剑，天生怪异，功能参商！\n"NOR,
                "weapon_prop/damage":  150,
                "weapon_prop/attack":  200,
                "weapon_prop/parry":   200,
                "weapon_prop/dodge":   200,
                "weapon_prop/sword":   200,
                "sharpness":           10,
                "rigidity":            9,
                ]),
RED"胜邪" : ([ "id": ({ "shengxie jian", "shengxie", "sword", "jian" }),
                "long2" : RED"胜邪宝剑，威力巨大而无任何要求！\n"NOR,
                "weapon_prop/damage":  220,
                "sharpness":           8,
                "rigidity":            9,
                "wield_maxneili":    0,
                "wield_neili":  0,
                "wield_str":           0,
                ]),
RED"龙泉" : ([ "id": ({ "longquan jian", "longquan", "sword", "jian" }),
                "long2" : RED"龙泉宝剑，人间极品，武林至宝！\n"NOR,
                "weapon_prop/damage":  190,
                "weapon_prop/spiritual":        40,
                "weapon_prop/strength": 40,
                "weapon_prop/constitution": 40,
                "weapon_prop/intelligence": 40,
                "sharpness":           9,
                "rigidity":            7,
             ]),
]);

nosave mapping Super_Class = ([   
        HIM"轩辕" : ([ "id":    "xuanyuan",     
                        "long2": HIM"昔日黄帝持此物立于指南车上，驱迷雾，扫阴霾，率应龙旱魃，御百兽而战蚩尤！\n"NOR,
                ]),
        HIR"神通" : ([ "id":    "shentong",
                        "long2":        HIR"天兵神通，走势要平善，气要随行，两眼顾尖，气沉两足稳，
身法需自然，身行如飞燕，身落如停风，收如花絮，刺如钢钉！\n"NOR,
                ]),
        HIG"无极" : ([ "id":    "wuji",         
                        "long2": HIG"此物已达出神入化，登峰造极，神乎其神之境界！俗说万物归宗，便是这“无极”！\n"NOR,
                ]),
        HIW"八卦" : ([ "id":    "bagua",        
                        "long2": HIW"八卦有“休”“生”“伤”“杜”“死”“景”“惊”“开”之别，创自诸葛武候，集天下万变于一身！\n"NOR,
                ]),
        HIB"乔依乌斯" : ([ "id": "joeywus",     
                        "long2": HIB"在西方查理曼统治的时代，最简朴的剑也能值三头母牛的价钱。而查理大帝自己的那把传奇式
的神兵“乔依乌斯”据说是半人半神的“韦兰铁匠”所造，乃当世界神兵！\n"NOR,
                ]),
        HIW"太白" : ([ "id":    "taibai",       
                        "long2": HIW"
                赵客缦胡缨  吴钩霜雪明          银鞍照白马  飒沓如流星
                十步杀一人  千里不留行          事了拂衣去  深藏身与名
                闲过信陵饮  脱剑膝前横          将炙□朱亥  持觞劝侯嬴
                三杯吐然诺  五狱倒为轻          眼花耳热後  意气素霓生
                救赵挥金槌  邯郸先震惊          千秋二壮士  喧赫大梁城
                纵死侠骨香  不惭世上英          谁能书阁下  白首太玄经\n"NOR,
                ]),
        HIY"乾坤" : ([ "id":    "qiankun",      
                        "long2": HIY"此物左右两边分别以黑白两种奇铁溶铸而成，一黑一白，切合乾坤，包含阴阳之气，好一柄宝物！\n"NOR,
                ]),
        HIY"太极" : ([ "id":    "taiji",        
                        "long2": HIY"太极者，无极而生，阴阳之母也。动之则分，静之则合。无过不及，随曲就伸。
人刚我柔谓之走，我顺人背谓之粘。动急则急应，动缓则缓随。虽变化万端，而
理为一贯！\n"NOR,
                ]),
        HIC"天地" : ([ "id":    "tiandi",       
                        "long2": HIC"天地之初，女娲补天所留下的天地间至尊之物之一经千秋万载所制，功能开天劈地！\n"NOR,
                ]),
        HIM"风云" : ([ "id":    "fengyun",      
                        "long2": HIM"所谓风云际会，天地变色！仗此行千里，老魔小丑，岂堪一击！\n"NOR,
                ]),
        HIG"浩气" : ([ "id":    "haoqi",        
                        "long2": HIG"天地浩气之神兵，扫魔除妖，为国为民，侠之大者！\n"NOR,
                ]),
        HIR"炼狱" : ([ "id":    "lianyu",       
                        "long2": HIR"三十三天下有地，地下有城，城名鬼城，大小妖魔，人神畜生都在此轮回往返，谓之“炼狱”！\n"NOR,
                ]),
        HIC"三清" : ([ "id":    "sanqing",      
                        "long2": HIC"大道无名，聚气成形，功参造化，一是三清！这便是“老子一罡化三清。”\n"NOR,
                ]),
        HIC"昆仑" : ([ "id":    "kunlun",       
                        "long2": HIC"   笑江湖浪迹十年游，空负少年头。
        对铜陀巷泊，吟情渺渺，心事悠悠！ 
        酒令诗残梦断，南国正清愁。 
        把剑凄然望，无处招归舟。 
 
        明月天涯路远，问谁留楚佩，弄影中洲？
        数英雄儿女，俯仰古今愁。
        难消受灯昏罗帐，伥昙花一现恨难休！
        飘零惯，金戈铁马，拼葬荒丘！ \n"NOR,
        ]),
]);

nosave mapping Great_Class = ([   
        CYN"帝王":      "diwang",       CYN"王者":      "wangzhe",
        CYN"天后":      "tianhou",      CYN"霸王":      "bawang",   
        CYN"天圣":      "tiansheng",    CYN"神王":      "shenwang",   
        CYN"妖后":      "yaohou",       BLU"公侯":      "gonghou", 
        BLU"魔王":      "mowang",       BLU"七星":      "qixing", 
        BLU"恶鬼":      "egui",         GRN"玉龙":      "yulong", 
        GRN"玉凤":      "yufeng",       GRN"松鹤":      "songhe",
        GRN"天龙":      "tianlong",     GRN"地龙":      "dilong",
        GRN"天凤":      "tianfeng",     GRN"地凤":      "difeng",
        GRN"龙翔":      "longxiang",    GRN"凤舞":      "fengwu",
        HIG"无影":      "wuying",       HIG"破甲":      "pojia",
        HIG"飞龙":      "feilong",      HIG"武翼":      "wuyi",
        HIG"鸟翔":      "niaoxiang",    HIG"婉盘":      "wanpan",
        HIG"青萍":      "qingping",     YEL"黄龙":      "huanglong",
        WHT"云梯":      "yunti",        WHT"太渊":      "taiyuan",
        WHT"太风":      "taifeng",      WHT"虚灵":      "xuling",
        WHT"霹雳":      "pili",         WHT"雷电":      "leidian",
        WHT"风雷":      "fenglei",      WHT"震电":      "zhendian",
        WHT"白玉":      "baiyu",        WHT"青玉":      "qingyu",
        WHT"紫玉":      "ziyu",         WHT"蓝玉":      "lanyu",
        WHT"绿玉":      "luyu",         WHT"黄玉":      "huangyu",
        WHT"赤玉":      "chiyu",        WHT"红玉":      "hongyu",
        CYN"青虹":      "qinghong",     CYN"白虹":      "baihong",
        CYN"紫虹":      "zihong",       CYN"蓝虹":      "lanhong",
        CYN"绿虹":      "luhong",       CYN"赤虹":      "chihong",
        CYN"幻影":      "huanying",     CYN"凝霜":      "ningshuang",
        CYN"青索":      "qingsuo",      MAG"天龙":      "tianlong",
        MAG"紫电":      "zidian",       MAG"凤凰":      "fenghuang",
        MAG"天枢":      "tianqu",       MAG"天璇":      "tianxuan",
        MAG"天玑":      "tianji",       MAG"天权":      "tianquan",
        MAG"玉衡":      "yuheng",       MAG"开阳":      "kaiyang",
        MAG"摇光":      "yaoguang",     MAG"北斗":      "beidou",
        HIR"天火":      "tianhuo",      HIR"麒麟":      "qilin",
        HIR"辟邪":      "pixie",        YEL"鸿钧":      "hongjun",
        YEL"广成":      "guangcheng",   YEL"金光":      "jinguang",
        YEL"修罗":      "xiuluo",       YEL"夜叉":      "yecha",
        YEL"瑶池":      "yaochi",       YEL"泪痕":      "leiheng",
        HIR"火龙":      "huolong",      HIC"冰龙":      "binglong",
        HIB"黑龙":      "heilong",      HIR"炎龙":      "yanlong",
        HIC"青龙":      "qinglong",     HIR"朱雀":      "zhuque",
        HIW"白虎":      "baihu",        HIB"玄武":      "xuanwu",       
        GRN"玄机":      "xuanji",       HIG"九天":      "jiutian",
        HIG"九幽":      "jiuyou",       MAG"九龙":      "jiulong",
        MAG"五龙":      "wulong",       MAG"三龙":      "sanlong",
        WHT"生死":      "shengsi",
]);

nosave string *G_3_class = ({
        "春雨", "夏雨", "秋雨", "冬雨", "春兰", "夏荷", "秋菊", "冬梅",
        "玉泉", "羽泉", "风泉", "虎泉", "怒涛", "江河", "漩流", "清水",
        "巨",   "大",   "小",   "怪",   "阖",   "阔",   "宾",   "叠",
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
        "娥眉", "明眸", "流盼", "朱唇", "皓齿", "玉指", "素臂", "登龙",
        "晓翠", "春江", "夜月", "啼莺", "慈云", "浮云", "青云", "朝云",
        "夜云", "飞云", "卷云", "白云", "蓝云", "紫云", "红云", "赤云",
        "鸿门", "蛟龙", "雷霆", "狮吼", "卧虎", "青羊", "老君", "斗母",
        "贺兰", "日月", "玉门", "阡陌", "纵横", "承天", "延永", "玉皇",
        "松柏", "须弥", "秀骨", "清相", "洛神", "圣母", "文昌", "聚泉",
        "武圣", "南天", "北天", "西天", "东天", "飞雪", "飘雪", "落雪",
        "白雪", "梦雪", "雪花", "烟雨", "霞蔚", "赤霞", "潇湘", "瀚海",
        "牡丹", "百合", "白荷", "龙菊", "幽兰", "翡翠", "青竹", "飞凤", 
        "相思", "云竹", "海棠", "芍药", "杜鹃", "玫瑰", "月季", "四季",
        "芙蓉", "蔷薇", "苍岩", "天师", "洗心", "常青", "翻天", "降魔",
        "風鈴", "風信", "紫陽", "丹陽", "紫薇", "木樨", "富貴", "太陽",
        "火鶴", "青鶴", "白鶴", "紫鶴", "白薇", "蓝薇", "青薇", "火薇",
        "冰薇", "青陽", "白陽", "火陽", "冰陽", "天秤", "巨蟹", "金牛",
        "扣骨", "渡心", "含翠", "蝙蝠", "月形", "黑云", "铁鲨", "撼山",
        "断玉", "摘星", "探星", "飞星", "黑魅", "绿影", "玉魔", "银铃",
        "金铃", "千仞", "晶电", "千芒", "阴霾", "魔袱", "戈壁", "起云", 
        "蚁峻", "矗页", "睚眦", "螭吻", "蒲牢", "饕餮", "蜍夏", "椒图",
        "血斩", "天威", "旋风", "紫芒", "削岩", "万丈", "星龙", "月龙",
        "巨威", "影残", "璨星", "裂心", "双星", "望霞", "翠屏", "朝云",
        "松峦", "集仙", "聚鹤", "净坛", "上升", 
});

string ask_imbue()
{
         object *obs,newob1,newob2;
         int i, j, k, pp = 0, sp = 0, gp = 0;
         mixed* file1,file2;
         string str = "你可以用 dazao xxx 来让我给你打造武器。\n";
         object me = this_player();      
        
         file1 = get_dir("/d/quest/dazao/material1"+"/*.lpc",-1);
         file2 = get_dir("/d/quest/dazao/material2"+"/*.lpc",-1);
         if( !sizeof(file1) )  return 0;
         if( !sizeof(file2) )  return 0;
         j = random(sizeof(file1));
         k = random(sizeof(file2));
         if( file1[j][1] > 0 ) { 
                 newob1=load_object("/d/quest/dazao/material1"+"/"+file1[j][0]);
         }
         if( file2[k][1] > 0 ) { 
                 newob2=load_object("/d/quest/dazao/material2"+"/"+file2[k][0]);
         }
         if(random(2)){
                 write("要打造兵器还需要给我些特殊物品，目前我这里需要"+newob1->query("name")+"，将这件东西\n"
                 "和你要打造的兵器一起给我，才能得到一件上好的武器。\n"); 
                 me->set_temp("dazao_ask/name", newob1->query("name"));
                 me->set_temp("dazao_ask/id", newob1->query("id"));
         }
         else{
                 write("要打造兵器还需要给我些特殊物品，目前我这里需要"+newob2->query("name")+"，将这件东西\n"
                 "和你要打造的兵器一起给我，才能得到一件上好的武器。\n");  
                 me->set_temp("dazao_ask/name", newob2->query("name"));
                 me->set_temp("dazao_ask/id", newob2->query("id")); 
         }
         
         obs = filter_array(children(USER_WEAPON), (: clonep :));
         i = sizeof(obs);
        if( i && i > 0 ){
                while(i--){
                        switch(obs[i]->query("imbued")){
                                case 5: pp++; break;
                                case 4: sp++; break;
                                case 3: gp++; break;
                                case 2: 
                                case 1: 
                                default: break;
                        }
                }
        }
         if( pp > 0 ) str += " 目前游戏里已经有了" + chinese_number(pp) + "把传说中的宝剑。\n";
         if( sp > 0 ) str += " 目前游戏里已经有了" + chinese_number(sp) + "把最高等级的武器。\n";
         if( gp > 0 ) str += " 目前游戏里已经有了" + chinese_number(gp) + "把高等级的武器。\n";  
         return str;
}

string s_good(int i)
{
         switch(i){
                 case 10..20:   return "无比";  
                  case 9:               return "无比";  
                  case 8:               return "极其";  
                  case 7:               return "绝对";  
                  case 6:               return "极为";  
                  case 5:               return "相当";  
                  case 4:               return "十分";  
                  case 3:               return "非常";  
                  case 2:               return "比较";  
                  case 1:               return "还算";  
                  case -1:             return "不怎么"; 
                  case -2:             return "很不";   
                  case -3:             return "极不";   
                  default:             return "一般";   
         }
}

string s_power(int i)
{
         if( i >= 300 ) return HIR"毁天灭地"NOR;
         if( i >= 280 ) return HIR"开元创世"NOR;        
         if( i >= 250 ) return HIR"天下无双"NOR;        
         if( i >= 220 ) return HIM"绝世罕见"NOR;        
         if( i >= 200 ) return HIY"举世无匹"NOR;
         if( i >= 180 ) return HIG"开天劈地"NOR;
         if( i >= 160 ) return HIB"倚天屠龙"NOR;
         if( i >= 140 ) return HIC"斩妖伏魔"NOR;
         if( i >= 120 ) return RED"无与伦比"NOR;
         if( i >= 100 ) return MAG"极其可怕"NOR;
         if( i >= 80 )  return YEL"很高"NOR;
         if( i >= 60 )  return GRN"水准以上"NOR;
         if( i >= 40 )  return BLU"不错"NOR;
         if( i > 20 )   return CYN"不小"NOR;
         if( i <= 0 )   return "极差";
         if( i <= -20 ) return "低劣";
         return "一般";
}

// Important mapping for user_weapon.
nosave mapping mp;
nosave string *special_st = ({});
nosave string *name_st = ({});

void special_weapon_status(int i)
{
         if( !i ) i = random(380);
         switch(i){
                 case 0: special_st += ({ HIG"长生" });
                          name_st += ({ "增加大量气血" });
                           mp["weapon_prop/kee"] = 1000 + random(2500);
                           break;
                  case 3: special_st += ({ HIG"长生" });
                           name_st += ({ "增加很多气血" });
                           mp["weapon_prop/kee"] = 700 + random(1800);
                           break;
                  case 6: special_st += ({ HIG"长生" });
                           name_st += ({ "增加气血" });
                           mp["weapon_prop/kee"] = 500 + random(1200);
                           break;
                  case 9: special_st += ({ HIG"长生" });
                           name_st += ({ "增加少量气血" });
                           mp["weapon_prop/kee"] = 200 + random(700);
                           break;
                  case 12: special_st += ({ HIG"不老" });
                           name_st += ({ "增加大量精神" });
                           mp["weapon_prop/sen"] = 1000 + random(2500);
                           break;
                  case 15: special_st += ({ HIG"不老" });
                           name_st += ({ "增加很多精神" });
                           mp["weapon_prop/sen"] = 700 + random(1800);
                           break;
                  case 18: special_st += ({ HIG"不老" });
                           name_st += ({ "增加精神" });
                           mp["weapon_prop/sen"] = 500 + random(1200);
                           break;
                  case 21: special_st += ({ HIG"不老" });
                           name_st += ({ "增加少量精神" });
                           mp["weapon_prop/sen"] = 200 + random(700);
                           break;
                  case 24: special_st += ({ HIG"小周天" });
                           name_st += ({ "增加大量法力" });
                           mp["weapon_prop/spells"] = 70 + random(35);
                           break;
                  case 27: special_st += ({ HIG"小周天" });
                           name_st += ({ "增加很多法力" });
                           mp["weapon_prop/spells"] = 40 + random(20);
                           break;
                  case 30: special_st += ({ HIG"小周天" });
                           name_st += ({ "增加法力" });
                           mp["weapon_prop/spells"] = 20 + random(10);
                           break;
                  case 33: special_st += ({ HIG"小周天" });
                           name_st += ({ "增加少量法力" });
                           mp["weapon_prop/spells"] = 10 + random(5);
                           break;
                  case 36: special_st += ({ HIG"大周天" });
                           name_st += ({ "增加大量内力" });
                           mp["weapon_prop/force"] = 70 + random(35);
                           break;
                  case 39: special_st += ({ HIG"大周天" });
                           name_st += ({ "增加很多内力" });
                           mp["weapon_prop/force"] = 40 + random(20);
                           break;
                  case 42: special_st += ({ HIG"大周天" });
                           name_st += ({ "增加内力" });
                           mp["weapon_prop/force"] = 20 + random(10);
                           break;
                  case 45: special_st += ({ HIG"大周天" });
                           name_st += ({ "增加少量内力" });
                           mp["weapon_prop/force"] = 10 + random(5);
                           break;
                  case 48: special_st += ({ HIR"绝世" });
                           name_st += ({ "绝世威力" });
                           mp["weapon_prop/damage"] += random(mp["weapon_prop/damage"]) * 3;
                           break;
                  case 51: special_st += ({ HIR"旷世" });
                           name_st += ({ "旷世威力" });
                           mp["weapon_prop/damage"] += random(mp["weapon_prop/damage"]) * 2;
                           break;
                  case 54: special_st += ({ HIW"灭世" });
                           name_st += ({ "提升威力" });
                           mp["weapon_prop/damage"] += random(mp["weapon_prop/damage"]);
                           break;
                  case 57: special_st += ({ HIW"极品" });
                           name_st += ({ "增加威力" });
                           mp["weapon_prop/damage"] += mp["weapon_prop/damage"]/2;
                           break;
                  case 60: special_st += ({ HIC"上品" });
                           name_st += ({ "提高威力" });
                           mp["weapon_prop/damage"] += random(mp["weapon_prop/damage"]/2);
                           break;
                  case 63: special_st += ({ HIC"优良" });
                           name_st += ({ "加强威力" });
                           mp["weapon_prop/damage"] += mp["weapon_prop/damage"]/4;
                           break;
                  case 66: special_st += ({ GRN"丽晶" });
                           name_st += ({ "无最大内力要求" });
                           mp["wield_maxneili"] = 0;
                           break;
                  case 69: special_st += ({ GRN"丽水" });
                           name_st += ({ "最大内力要求减大半" });
                           mp["wield_maxneili"] /= 3;
                           break;
                  case 72: special_st += ({ GRN"柔晶" });
                           name_st += ({ "最大内力要求减半" });
                           mp["wield_maxneili"] /= 2;
                           break;
                  case 75: special_st += ({ GRN"柔水" });
                           name_st += ({ "最大内力要求减小半" });
                           mp["wield_maxneili"] -= mp["wield_maxneili"]/3;
                           break;
                  case 78: special_st += ({ GRN"玉晶" });
                           name_st += ({ "无内力要求" });
                           mp["wield_neili"] = 0;
                           break;
                  case 81: special_st += ({ HIW"玉水" });
                           name_st += ({ "内力要求减大半" });
                           mp["wield_neili"] /= 3;
                           break;
                  case 84: special_st += ({ HIW"凝晶" });
                           name_st += ({ "内力要求减半" });
                           mp["wield_neili"] /= 2;
                           break;
                  case 87: special_st += ({ HIW"凝水" });
                           name_st += ({ "内力要求减小半" });
                           mp["wield_neili"] -= mp["wield_neili"]/3;
                           break;
                  case 90: special_st += ({ HIG"光华" });
                           name_st += ({ "最低膂力要求" });
                           mp["wield_str"] = 10;
                           break;
                  case 93: special_st += ({ HIG"彩华" });
                           name_st += ({ "膂力要求减大半" });
                           mp["wield_str"] /= 3;
                           break;
                  case 96: special_st += ({ HIG"光彩" });
                           name_st += ({ "膂力要求减半" });
                           mp["wield_str"] /= 2;
                           break;
                  case 99: special_st += ({ HIG"华彩" });
                           name_st += ({ "膂力要求减小半" });
                           mp["wield_str"] -= mp["wield_str"]/3;
                           break;
                  case 102: special_st += ({ HIW"神兵" });
                           name_st += ({ "极品锋利度" });
                           mp["sharpness"] += 3 + random(8);
                           break;
                  case 105: special_st += ({ HIW"炼制" });
                           name_st += ({ "叠加锋利度" });
                           mp["sharpness"] += 2 + random(6);
                           break;
                  case 108: special_st += ({ HIW"锻制" });
                           name_st += ({ "增加锋利度" });
                           mp["sharpness"] += 1 + random(3);
                           break;
                  case 112: special_st += ({ HIW"淬制" });
                           name_st += ({ "加强锋利度" });
                           mp["sharpness"] += random(3);
                           break;
                  case 115: special_st += ({ HIY"天兵" });
                           name_st += ({ "极品硬度" });
                           mp["rigidity"] += 3 + random(8);
                           break;
                  case 118: special_st += ({ HIY"御制" });
                           name_st += ({ "叠加硬度" });
                           mp["rigidity"] += 2 + random(6);
                           break;
                  case 121: special_st += ({ HIY"精制" });
                           name_st += ({ "增加硬度" });
                           mp["rigidity"] += 1 + random(3);
                           break;
                  case 124: special_st += ({ HIY"巧制" });
                           name_st += ({ "加强硬度" });
                           mp["rigidity"] += random(3);
                           break;
                  case 127: special_st += ({ HIW"闪电" });
                           name_st += ({ "极品命中" });
                           mp["weapon_prop/attack"] += (100 + random(100));
                           break;
                  case 130: special_st += ({ HIB"飓电" });
                           name_st += ({ "超高命中" });
                           mp["weapon_prop/attack"] += (70 + random(70));
                           break;
                  case 133: special_st += ({ HIM"紫电" });
                           name_st += ({ "提高命中" });
                           mp["weapon_prop/attack"] += (40 + random(40));
                           break;
                  case 136: special_st += ({ HIW"雷电" });
                           name_st += ({ "提升命中" });
                           mp["weapon_prop/attack"] += (20 + random(20));
                           break;
                  case 139: special_st += ({ WHT"天灵" });
                           name_st += ({ "极品思维" });
                           mp["weapon_prop/intelligence"] += (5 + random(5));
                           break;
                  case 142: special_st += ({ WHT"地灵" });
                           name_st += ({ "增加思维" });
                           mp["weapon_prop/intelligence"] += (3 + random(4));
                           break;
                  case 145: special_st += ({ WHT"人灵" });
                           name_st += ({ "提高悟性" });
                           mp["weapon_prop/intelligence"] += (2 + random(3));
                           break;
                  case 148: special_st += ({ WHT"合灵" });
                           name_st += ({ "增加悟性" });
                           mp["weapon_prop/intelligence"] += (1 + random(2));
                           break;
                  case 151: special_st += ({ BLU"天玄" });
                           name_st += ({ "极品根骨" });
                           mp["weapon_prop/constitution"] += (5 + random(5));
                           break;
                  case 154: special_st += ({ BLU"地玄" });
                           name_st += ({ "增加根骨" });
                           mp["weapon_prop/constitution"] += (3 + random(4));
                           break;
                  case 157: special_st += ({ BLU"人玄" });
                           name_st += ({ "提高体魄" });
                           mp["weapon_prop/constitution"] += (2 + random(3));
                           break;
                  case 160: special_st += ({ BLU"合玄" });
                           name_st += ({ "增加体魄" });
                           mp["weapon_prop/constitution"] += (1 + random(2));
                           break;
                  case 163: special_st += ({ HIM"天宇" });
                           name_st += ({ "极品力量" });
                           mp["weapon_prop/strength"] += (5 + random(5));
                           break;
                  case 166: special_st += ({ HIM"地宇" });
                           name_st += ({ "增加力量" });
                           mp["weapon_prop/strength"] += (3 + random(4));
                           break;
                  case 169: special_st += ({ HIM"人宇" });
                           name_st += ({ "提高膂力" });
                           mp["weapon_prop/strength"] += (2 + random(3));
                           break;
                  case 172: special_st += ({ HIM"合宇" });
                           name_st += ({ "增加膂力" });
                           mp["weapon_prop/strength"] += (1 + random(2));
                           break;
                  case 175: special_st += ({ MAG"天渊" });
                           name_st += ({ "极品灵性" });
                           mp["weapon_prop/spiritual"] += (5 + random(5));
                           break;
                  case 178: special_st += ({ MAG"地渊" });
                           name_st += ({ "增加灵性" });
                           mp["weapon_prop/spiritual"] += (3 + random(4));
                           break;
                  case 181: special_st += ({ MAG"人渊" });
                           name_st += ({ "增加灵性" });
                           mp["weapon_prop/spiritual"] += (2 + random(3));
                           break;
                  case 184: special_st += ({ MAG"合渊" });
                           name_st += ({ "增加灵性" });
                           mp["weapon_prop/spiritual"] += (1 + random(2));
                           break;
                  case 187: special_st += ({ YEL"檀木" });
                           name_st += ({ "木性，膂力要求减大半" });
                           mp["wield_str"] /= 3;
                           mp["material"] = "wood";
                           break;
                  case 190: special_st += ({ GRN"斑竹" });
                           name_st += ({ "竹性，无膂力要求" });
                           mp["wield_str"] = 0;
                           mp["material"] = "bamboo";
                           break;
                  case 193: special_st += ({ "飞絮" });
                           name_st += ({ "重量减半" });
                           mp["weight"] /= 2;
                           break;
                  case 196: special_st += ({ HIG"柳絮" });
                           name_st += ({ "柔性质材" });
                           mp["material"] = "softsteel";
                           break;
                  case 199: special_st += ({ HIB"剧毒" });
                           name_st += ({ "毒性攻击" });
                           mp["poisoned"] = "xx_poison";
                           mp["poison_number"] = 500;
                           break;
                  case 202: special_st += ({ HIB"一品毒" });
                           name_st += ({ "怪蛇毒" });
                           mp["poisoned"] = "bt_poison";
                           mp["poison_number"] = 500;
                           break;
                  case 205: special_st += ({ HIR"火焰" });
                           name_st += ({ "火毒攻击" });
                           mp["poisoned"] = "hot_poison";
                           mp["poison_number"] = 500;
                           break;
                  case 208: special_st += ({ HIG"绿波" });
                           name_st += ({ "绿波香露奇毒" });
                           mp["poisoned"] = "lvbo_poison";
                           mp["poison_number"] = 500;
                           break;
                  case 211: special_st += ({ HIR"蔓陀萝" });
                           name_st += ({ "蔓陀萝毒" });
                           mp["poisoned"] = "man_poison";
                           mp["poison_number"] = 500;
                           break;
                  case 214: special_st += ({ HIB"千蛛" });
                           name_st += ({ "千蛛毒" });
                           mp["poisoned"] = "qzhu_poison";
                           mp["poison_number"] = 500;
                           break;
                  case 217: special_st += ({ BLU"天蝎" });
                           name_st += ({ "天蝎毒" });
                           mp["poisoned"] = "scorpion_poison";
                           mp["poison_number"] = 500;
                           break;
                  case 220: special_st += ({ CYN"青蛇" });
                           name_st += ({ "青蛇毒" });
                           mp["poisoned"] = "snake_poison";
                           mp["poison_number"] = 500;
                           break;
                  case 223: special_st += ({ CYN"寒毒" });
                           name_st += ({ "寒毒攻击" });
                           mp["poisoned"] = "cold_poison";
                           mp["poison_number"] = 500;
                           break;
                  case 226: special_st += ({ CYN"寒冰" });
                           name_st += ({ "寒冰攻击" });
                           mp["poisoned"] = "hb_poison";
                           mp["poison_number"] = 500;
                           break;
                  case 229: special_st += ({ BLU"阴魔" });
                           name_st += ({ "内伤攻击" });
                           mp["poisoned"] = "yyz_hurt";
                           mp["poison_number"] = 500;
                           break;
                  case 232: special_st += ({ BLU"腐尸" });
                           name_st += ({ "腐尸攻击" });
                           mp["poisoned"] = "fs_poison";
                           mp["poison_number"] = 500;
                           break;
                  case 235: special_st += ({ HIG"周天" });
                           name_st += ({ "增加内力和法力" });
                           mp["weapon_prop/force"] = 40 + random(20);
                           mp["weapon_prop/spells"] = 40 + random(20);
                  case 238: special_st += ({ HIY"神圣" });
                           name_st += ({ "提高所有属性" });
                           mp["weapon_prop/spiritual"] += 8; 
                           mp["weapon_prop/strength"] += 8; 
                           mp["weapon_prop/constitution"] += 8; 
                           mp["weapon_prop/intelligence"] += 8; 
                           break;
                  case 241: special_st += ({ HIY"三才" });
                           name_st += ({ "增加所有属性" });
                           mp["weapon_prop/spiritual"] += 5; 
                           mp["weapon_prop/strength"] += 5; 
                           mp["weapon_prop/constitution"] += 5; 
                           mp["weapon_prop/intelligence"] += 5; 
                           break;
                  case 244: special_st += ({ HIW"白石" });
                           name_st += ({ "超高防御" });
                           mp["weapon_prop/parry"] += (70 + random(70));
                           break;
                  case 247: special_st += ({ HIM"紫石" });
                           name_st += ({ "提高防御" });
                           mp["weapon_prop/parry"] += (40 + random(40));
                           break;
                  case 250: special_st += ({ HIY"黄石" });
                           name_st += ({ "提升防御" });
                           mp["weapon_prop/parry"] += (20 + random(20));
                           break;
                  case 253: special_st += ({ BLU"黑石" });
                           name_st += ({ "超高躲避" });
                           mp["weapon_prop/dodge"] += (70 + random(70));
                           break;
                  case 256: special_st += ({ HIB"蓝石" });
                           name_st += ({ "提高躲避" });
                           mp["weapon_prop/dodge"] += (40 + random(40));
                           break;
                  case 259: special_st += ({ HIR"红石" });
                           name_st += ({ "提升躲避" });
                           mp["weapon_prop/dodge"] += (20 + random(20));
                           break;
                  case 262: special_st += ({ HIY"金木" });
                           name_st += ({ "提高防御和躲避" });
                           mp["weapon_prop/dodge"] += (40 + random(40));
                           mp["weapon_prop/parry"] += (40 + random(40));
                           break;
                  case 265: special_st += ({ HIW"水火" });
                           name_st += ({ "提高命中和威力" });
                           mp["weapon_prop/attack"] += (40 + random(40));
                           mp["weapon_prop/damage"] += (20 + random(40));
                           break;
                  case 268: special_st += ({ HIR"火土" });
                           name_st += ({ "提高威力和内功抗性" });
                           mp["weapon_prop/armor_vs_force"] += (40 + random(40));
                           mp["weapon_prop/damage"] += (20 + random(40));
                           break;
                  case 271: special_st += ({ YEL"土金" });
                           name_st += ({ "提高内功抗性和防御" });
                           mp["weapon_prop/parry"] += (40 + random(40));
                           mp["weapon_prop/armor_vs_force"] += (40 + random(40));
                           break;
                  case 274: special_st += ({ HIG"木水" });
                           name_st += ({ "提高躲避和命中" });
                           mp["weapon_prop/attack"] += (40 + random(40));
                           mp["weapon_prop/dodge"] += (20 + random(40));
                           break;
                  case 277: special_st += ({ HIG"长寿" });
                           name_st += ({ "增加气血和精神" });
                           mp["weapon_prop/kee"] = 300 + random(900);
                           mp["weapon_prop/sen"] = 300 + random(900);
                  default: break;
         }
         return;        
}
