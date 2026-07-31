// skill.h for /kungfu/skill/douzhuan-xingyi/douzhuanxingyi.c

mapping *perform = ({

// ALL MemPai got 2 symbolically skill ( weapon & unarmed ) here. should modify later
// hs,xx,sl,wd,gb,mj,gm,dl,em,tz,tls,xs,th

// HuaShan

([      "name"        :  "dugu-jiujian",
        "describe"    :  "将手中宝剑一收，紧接着将「破剑」「破刀」「破掌」三式同时使出！",
        "menpai"      :  "华山派",
        "skill_type"  :  "weapon", // weapon||unarmed
        "weapon_type" :  "sword", // sword,blade,whip...etc
        "unarmed_type":  "none",  // strike,hand,finger,etc
        "perform_type":  "1",
]),

([      "name"        :  "poyu-quan",
        "describe"    :  "深深吸了一口气，脸上顿时紫气大盛，出手越来越重！",
        "menpai"      :  "华山派",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "unarmed",
        "perform_type":  "3",
]),

// XingXiu

([      "name"        :  "tianshan-zhang",
        "describe"    :  "将手中巨杖舞做一团，大开大阖的施展出「天崩地裂」向敌人没头没脸的狂击！！！",
        "menpai"      :  "星宿派",
        "skill_type"  :  "weapon",
        "weapon_type" :  "staff",
        "unarmed_type":  "none",
        "perform_type":  "2",
]),

([      "name"        :  "xingxiu-duzhang",
        "describe"    :  "口念邪咒，手捏青红涅磐印，施展出星宿独门幻术，企图迷惑对手。",
        "menpai"      :  "星宿派",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "unarmed",
        "perform_type":  "5",
]),

// ShaoLin

([      "name"        :  "riyue-bian",
        "describe"    :  "使出日月鞭法「缠绕」诀，连挥数鞭，散下满天鞭网，企图把你的全身缠绕起来。",
        "menpai"      :  "少林派",
        "skill_type"  :  "weapon",
        "weapon_type" :  "whip",
        "unarmed_type":  "none",
        "perform_type":  "4",
]),

([      "name"        :  "jinggang-quan",
        "describe"    :  "使出大金刚拳的绝技「大金刚神通」，臂力陡然增加！",
        "menpai"      :  "少林派",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "unarmed",
        "perform_type":  "3",
]),

// WuDang

([      "name"        :  "taiji-jian",
        "describe"    :  "手中长剑连连化出数个太级如意，一片太极圆圈向前涌去！！",
        "menpai"      :  "武当派",
        "skill_type"  :  "weapon",
        "weapon_type" :  "none",
        "unarmed_type":  "none",
        "perform_type":  "4",
]),

([      "name"        :  "taiji-quan",
        "describe"    :  "使出太极拳法「缠」字诀，连递数个虚招企图扰乱你的攻势。。",
        "menpai"      :  "武当派",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "unarmed",
        "perform_type":  "4",
]),

// GaiBang

([      "name"        :  "dagou-bang",
        "describe"    :  "使出打狗棒法「缠字」诀，只见一团青影铺天盖地罩了过去 ",
        "menpai"      :  "丐帮",
        "skill_type"  :  "weapon",
        "weapon_type" :  "stick",
        "unarmed_type":  "none",
        "perform_type":  "4",
]),

([      "name"        :  "xianglong-zhang",
        "describe"    :  "施展出降龙十八掌的绝学"HIY+"「惊天一击」"+HIC"，全身急速转动起来，越来越快！",
        "menpai"      :  "丐帮",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "unarmed",
        "perform_type":  "5",
]),

// MinJiao

([      "name"        :  "shenghuo-lingfa",
        "describe"    :  "脚踏乾坤五行，手中剑器一卷，突然放出数道红色剑芒分刺向前！！",
        "menpai"      :  "明教",
        "skill_type"  :  "weapon",
        "weapon_type" :  "blade",
        "unarmed_type":  "none",
        "perform_type":  "5",
]),

([      "name"        :  "qishang-quan",
        "describe"    :  "大喝一声，使出七伤拳的绝技「魂魄飞扬」，双拳势如雷霆，向你击去。",
        "menpai"      :  "明教",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "unarmed",
        "perform_type":  "5",
]),

// GuMu

([      "name"        :  "xuantie-jianfa",
        "describe"    :  "大吼一声，手持玄铁剑挟巨浪潮涌之势,从轻而响，从响而轻，忽寂然无声，忽轰轰之声，反复七次，席卷而去。",
        "menpai"      :  "古墓派",
        "skill_type"  :  "weapon",
        "weapon_type" :  "sword",
        "unarmed_type":  "none",
        "perform_type":  "1",
]),

([      "name"        :  "anran-xiaohunzhang",
        "describe"    :  "面呈凄苦之色，心下万念俱灰，没精打采的挥袖卷出，倒拍出一掌",
        "menpai"      :  "古墓派",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "unarmed",
        "perform_type":  "5",
]),

// DaLi

([      "name"        :  "duanjia-jian",
        "describe"    :  "长笑一声，剑交左手，蹂身而上，施展「风雷四击」绝技，试图快速击伤对手。",
        "menpai"      :  "大理国",
        "skill_type"  :  "weapon",
        "weapon_type" :  "sword",
        "unarmed_type":  "none",
        "perform_type":  "1",
]),

([      "name"        :  "yiyang-zhi",
        "describe"    :  "凝气于指，一式「阳关三叠」反手缓缓点出，纯阳指力聚如凝束。",
        "menpai"      :  "大理国",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "finger",
        "perform_type":  "5",
]),

// Xiaoyao

([      "name"        :  "zhemei-shou",
        "describe"    :  "长笑一声，蹂身而上，施展「迎风折梅」绝技。",
        "menpai"      :  "逍遥派",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "unarmed",
        "perform_type":  "1",
]),

([      "name"        :  "liuyang-zhang",
        "describe"    :  "凝气于掌，化气为水，化水为冰，一式「阳春白雪」缓缓点出。",
        "menpai"      :  "逍遥派",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "unarmed",
        "perform_type":  "5",
]),

// Emei

([      "name"        :  "huifeng-jian",
        "describe"    :  "清啸一声，身形腾空丈许，将峨嵋绝技「灭剑」心法融入回风拂柳剑招之中，手中软剑挽起无数剑花",
        "menpai"      :  "峨嵋派",
        "skill_type"  :  "weapon",
        "weapon_type" :  "sword",
        "unarmed_type":  "none",
        "perform_type":  "3",
]),

([      "name"        :  "tiangang-zhi",
        "describe"    :  "使出天罡指穴法绝技「凌空指穴」，回过身来，一连七指，全是对向对手的头脸与前胸重穴!",
        "menpai"      :  "峨嵋派",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "unarmed",
        "perform_type":  "5",
]),

// TianLongSi

([      "name"        :  "duanjia-jian",
        "describe"    :  "长笑一声，剑交左手，蹂身而上，施展「风雷四击」绝技，试图快速击伤对手。",
        "menpai"      :  "天龙寺",
        "skill_type"  :  "weapon",
        "weapon_type" :  "sword",
        "unarmed_type":  "none",
        "perform_type":  "1",
]),

([      "name"        :  "yiyang-zhi",
        "describe"    :  "凝气于指，一式「阳关三叠」反手缓缓点出，纯阳指力聚如凝束。",
        "menpai"      :  "天龙寺",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "unarmed",
        "perform_type":  "5",
]),

// XueShan
/*
([      "name"        :  "",
        "describe"    :  "",
        "menpai"      :  "大轮寺",
        "skill_type"  :  "weapon",
        "weapon_type" :  "",
        "unarmed_type":  "none",
        "perform_type":  "",
]),

([      "name"        :  "",
        "describe"    :  "",
        "menpai"      :  "大轮寺",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "",
        "perform_type":  "",
]),

// TieZhang

([      "name"        :  "",
        "describe"    :  "",
        "menpai"      :  "",
        "skill_type"  :  "weapon",
        "weapon_type" :  "",
        "unarmed_type":  "none",
        "perform_type":  "",
]),

([      "name"        :  "",
        "describe"    :  "",
        "menpai"      :  "",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "",
        "perform_type":  "",
]),
*/
// TaoHua

([      "name"        :  "yuxiao-jian",
        "describe"    :  "将箫凑到嘴边，吹得两下，从箫筒里突然射出一道青光，疾飞而去。",
        "menpai"      :  "桃花岛",
        "skill_type"  :  "weapon",
        "weapon_type" :  "swword",
        "unarmed_type":  "none",
        "perform_type":  "5",
]),

([      "name"        :  "luoying-zhang",
        "describe"    :  "双掌竖起，掌缘便似剑锋，竟然发出丝丝的剑气，从左右两边分斫合击",
        "menpai"      :  "桃花岛",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "unarmed",
        "perform_type":  "5",
]),
// Shen long dao
([      "name"        :  "shenlong-bashi",
        "describe"    :  "乘你稍稍走神之机，拼尽全力使出洪教主不传之绝技－－「神龙八式」",
        "menpai"      :  "神龙教",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "unarmed",
        "perform_type":  "1",
]),
([      "name"        :  "huagu-mianzhang",
        "describe"    :  "忽然猛一吸气，双掌一立，向你轻轻地拍出！",
        "menpai"      :  "神龙教",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "unarmed",
        "perform_type":  "1",
]),

// Other        

([      "name"        :  "",
        "describe"    :  "",
        "menpai"      :  "",
        "skill_type"  :  "",
        "weapon_type" :  "",
        "unarmed_type":  "",
        "perform_type":  "",
]),

});
