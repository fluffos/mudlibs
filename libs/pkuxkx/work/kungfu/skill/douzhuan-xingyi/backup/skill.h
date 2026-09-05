// skill.h for /kungfu/skill/douzhuan-xingyi/douzhuanxingyi.c

mapping *perform = ({

// ALL MemPai got 2 symbolically skill ( weapon & unarmed ) here. should modify later
// hs,xx,sl,wd,gb,mj,gm,dl,em,tz,tls,xs,th

// HuaShan

([      "name"        :  "huashan-sanshengfeng",
        "describe"    :  "仰天一声清啸，运足内力使出「华岳三神峰」，雷霆般地击出两拳一刀！",
        "menpai"      :  "华山派",
        "skill_type"  :  "weapon", // weapon||unarmed
        "weapon_type" :  "sword", // sword,blade,whip...etc
        "unarmed_type":  "none",  // strike,hand,finger,etc
        "perform_type":  "1",
]),

([      "name"        :  "huashan-sanshengfeng",
        "describe"    :  "使出劈石破玉拳的绝学雷动九天，顿时天空电闪雷鸣！",
        "menpai"      :  "华山派",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "cuff",
        "perform_type":  "3",
]),

// XingXiu

([      "name"        :  "pixie-jian",
        "describe"    :  "一声阴笑，忽若一团红云般欺身而近，手中细针疾指双目！",
        "menpai"      :  "星宿派",
        "skill_type"  :  "weapon",
        "weapon_type" :  "sword",
        "unarmed_type":  "none",
        "perform_type":  "2",
]),

([      "name"        :  "chousui-zhang",
        "describe"    :  "面露凝重之色，双手色呈青紫，原本尖锐的掌风竟变得悄无声息。",
        "menpai"      :  "星宿派",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "strike",
        "perform_type":  "5",
]),

// ShaoLin

([      "name"        :  "jinggang-quan",
        "describe"    :  "使出日月鞭法「缠绕」诀，连挥数鞭，散下满天鞭网，企图把的全身缠绕起来。",
        "menpai"      :  "少林派",
        "skill_type"  :  "weapon",
        "weapon_type" :  "whip",
        "unarmed_type":  "none",
        "perform_type":  "4",
]),

([      "name"        :  "jinggang-quan",
        "describe"    :  "突然全身骨骼作响，真气具于指尖弹出，真是少林不传之技「无相劫指」！",
        "menpai"      :  "少林派",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "unarmed",
        "perform_type":  "3",
]),

// WuDang

([      "name"        :  "taiji-jian",
        "describe"    :  "使出太极剑法「缠」字诀，连递数个虚招企图扰乱对方的攻势。",
        "menpai"      :  "武当派",
        "skill_type"  :  "weapon",
        "weapon_type" :  "none",
        "unarmed_type":  "none",
        "perform_type":  "4",
]),

([      "name"        :  "taiji-quan",
        "describe"    :  "一招一式节节贯串，如长江大河，「粘」字绝一经使出，一个圆圈跟着一个圆圈，大圈、小圈、平圈、立圈、正圈、斜圈，一个个太极圆圈发出，连绵不断，滔滔不绝",
        "menpai"      :  "武当派",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "cuff",
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
        "describe"    :  "一声断喝，双掌齐出，挟起满天飞沙！使的正是萧峰的得意功夫「排云双掌」！",
        "menpai"      :  "丐帮",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "strike",
        "perform_type":  "5",
]),

// MinJiao

([      "name"        :  "yinfeng-dao",
        "describe"    :  "悄悄使出阴风刀，运起一股无形无质的阴寒之气，直插要穴而去！",
        "menpai"      :  "明教",
        "skill_type"  :  "weapon",
        "weapon_type" :  "blade",
        "unarmed_type":  "none",
        "perform_type":  "5",
]),

([      "name"        :  "hanbing-mianzhang",
        "describe"    :  "突然如同一只吸血青蝠，欺身而去，张嘴便向咽喉咬去。",
        "menpai"      :  "明教",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "bite",
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

([      "name"        :  "anran-zhang",
        "describe"    :  "面呈凄苦之色，心下万念俱灰，没精打采的挥袖卷出，倒拍出一掌",
        "menpai"      :  "古墓派",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "strike",
        "perform_type":  "5",
]),

// DaLi

([      "name"        :  "duanjia-jianfa",
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
        "unarmed_type":  "hand",
        "perform_type":  "1",
]),

([      "name"        :  "liuyang-zhang",
        "describe"    :  "凝气于掌，化气为水，化水为冰，一式「阳春白雪」缓缓点出。",
        "menpai"      :  "逍遥派",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "strike",
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

([      "name"        :  "jieshou-jiushi",
        "describe"    :  "面显庄严，运转体内临济十二庄，提一口真气，飘身而上，半空中手掌交错，一刹那之间，一股内劲狭带着热浪，如风如火，似雷似电般击出",
        "menpai"      :  "峨嵋派",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "hand",
        "perform_type":  "5",
]),

// TianLongSi

([      "name"        :  "duanjia-jianfa",
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
        "unarmed_type":  "finger",
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
        "weapon_type" :  "xiao",
        "unarmed_type":  "none",
        "perform_type":  "5",
]),

([      "name"        :  "luoying-zhang",
        "describe"    :  "双掌竖起，掌缘便似剑锋，竟然发出丝丝的剑气，从左右两边分斫合击",
        "menpai"      :  "桃花岛",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "strike",
        "perform_type":  "5",
]),
// Shen long dao
([      "name"        :  "canglang-goufa",
        "describe"    :  "乘你稍稍走神之机，拼尽全力使出洪教主不传之绝技－－「英雄三招」",
        "menpai"      :  "神龙教",
        "skill_type"  :  "weapon",
        "weapon_type" :  "hook",
        "unarmed_type":  "leg",
        "perform_type":  "1",
]),
([      "name"        :  "huagu-mianzhang",
        "describe"    :  "忽然猛一吸气，双掌一立，向你轻轻地拍出！",
        "menpai"      :  "神龙教",
        "skill_type"  :  "unarmed",
        "weapon_type" :  "none",
        "unarmed_type":  "strike",
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
