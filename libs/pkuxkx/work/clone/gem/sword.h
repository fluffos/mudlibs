// by Vast@PKUXKX
// all comments added by Vast
// 剑

string *sword_name = ({

        YEL"铸铁剑"NOR,
        HIY"青铜剑"NOR,
        HIB"精钢剑"NOR,
        WHT"薄刃剑"NOR,
        GRN"萧"NOR,
        HIW"宽刃剑"NOR,
        HIC"双手剑"NOR,
        HIG"玄铁剑"NOR,

        });

string *sword_id = ({

        ({ "zhutie jian", "sword", "jian" }),
        ({ "qingtong sword", "sword", "jian" }),
        ({ "jinggang sword", "sword", "jian" }),
        ({ "baoren sword", "sword", "jian" }),
        ({ "yu xiao", "sword", "jian", "xiao" }),
        ({ "kuanren sword", "sword", "jian" }),
        ({ "two-handed sword", "sword", "jian" }),
        ({ "xuantie sword", "sword", "jian" }),

        });

int *sword_weight = ({

        1000, 1500,
        2500, 1500,
        1500, 2000,
        500,  1500,
        500,  1000,
        1200, 1800,
        2000, 4000,
        5000, 5000,

        });

string *sword_long = ({

        "这是一柄普通的铸铁剑，一般的剑客都配带此剑。\n",
        "这是一柄古旧的青铜剑，很受用剑高手的欢迎。\n",
        "这是一把精钢铸就的利刃，官兵们经常随身携带此剑。\n",
        "这把剑剑刃极薄，看上去十分锋利。\n",
        "表面上看来这是一把华丽的碧玉长箫，实际上它也是杀敌的利器。\n",
        "这把剑剑刃很宽，是一把攻防兼备的好剑。\n",
        "这剑剑身极沉，剑柄很长，需要双手并用才能有效的使用它。\n",
        "这是一把黑幽幽的长剑，不知道是什么材料制成。\n",

        });

string *sword_material = ({

        "iron",
        "copper",
        "steel",
        "steel",
        "jade",
        "steel",
        "steel",
        "heavysteel",

        });

int *sword_rigidity = ({

        50,   100,
        80,   100,
        150,  50,
        20,   50,
        50,   200,
        250,  100,
        200,  300,
        500,  500,

        });

int *sword_value = ({

        30000,
        45000,
        50000,
        80000,
        70000,
        80000,
        150000,
        120000,

        });

string *sword_wieldmsg = ({

        "",  "",
        "",  "",
        "",  "",
        "",  "",
        "",  "",
        "",  "",
        "",  "",
        "$N从陈旧的剑鞘中拔出一把$n握在手中。\n",  "$N将手中的$n插入腰间的剑鞘。\n",

        });

int *sword_damage = ({

        30,    75,
        45,    65,
        50,    85,
        40,    120,
        70,    110,
        80,    130,
        150,   280,
        100,   150,

        });



