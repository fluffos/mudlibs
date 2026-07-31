// human.c
// From ES2
// Modified by Xiang@XKX

// A normal human is at least 40 kg weight
#define BASE_WEIGHT 40000

inherit F_DBASE;
inherit F_SKILL;

mapping *combat_action = ({
        ([      "action":               "$N挥拳攻击$n的$l",
                "damage_type":  "瘀伤",
        ]),
        ([      "action":               "$N往$n的$l一抓",
                "damage_type":  "抓伤",
        ]),
        ([      "action":               "$N往$n的$l狠狠地踢了一脚",
                "damage_type":  "瘀伤",
        ]),
        ([      "action":               "$N提起拳头往$n的$l捶去",
                "damage_type":  "瘀伤",
        ]),
        ([      "action":               "$N对准$n的$l用力挥出一拳",
                "damage_type":  "瘀伤",
        ]),
});

void create()
{
        seteuid(getuid());
        set("unit", "位");
        set("gender", "男性");
        set("can_speak", 1);
        set("attitude", "peaceful");
        set("limbs", ({
                "头部", "颈部", "胸口", "后心", "左肩", "右肩", "左臂",
                "右臂", "左手", "右手", "腰间", "小腹", "左腿", "右腿",
                "左脚", "右脚"
        }) );
}

void setup_human(object ob)
{
        mapping my;
        int xism_age;

        my = ob->query_entire_dbase();

        ob->set("default_actions", (: call_other, __FILE__, "query_action" :));

        ob->set_default_action(__FILE__, "query_action");
        if (! stringp(my["unit"])) my["unit"] = "位";
        if (! stringp(my["gender"])) my["gender"] = "男性";
        if (undefinedp(my["can_speak"])) my["can_speak"] = 1;
        if (! stringp(my["attitude"])) my["attitude"] = "peaceful";
        if (! pointerp(my["limbs"])) my["limbs"] = ({
                "头部", "颈部", "胸口", "后心", "左肩", "右肩", "左臂",
                "右臂", "左手", "右手", "腰间", "小腹", "左腿", "右腿",
                "左脚", "右脚"
        });

        if( undefinedp(my["age"]) ) my["age"] = 14;
        if (undefinedp(my["str"])) my["str"] = 10 + random(21);
        if (undefinedp(my["con"])) my["con"] = 10 + random(21);
        if (undefinedp(my["dex"])) my["dex"] = 10 + random(21);
        if (undefinedp(my["int"])) my["int"] = 10 + random(21);
        if (undefinedp(my["per"])) my["per"] = 10 + random(21);
        if (undefinedp(my["kar"])) my["kar"] = 10 + random(21);

        if( userp(ob) || undefinedp(my["max_jing"]) )
        {
                if( my["age"] <= 14 ) my["max_jing"] = 100;
                else if( my["age"] <= 30 ) my["max_jing"] = 100 + (my["age"] - 14) * my["int"];
                else my["max_jing"] = my["int"] * 16 + 100;

                if( my["age"] > 60 ) my["max_jing"] -= (my["age"] - 60) * 5 ;

                // 道家保精：
//                if(my["age"] > 20 && ob->query("ob->query("breakup"))
//                {
//                        my["max_jing"] += 1000;
//                }
                if(my["age"] > 20 && (int)ob->query_skill("biguan", 1) >= 100)
                {
                        my["max_jing"] += 1000;
                }

                if(my["age"] > 60 && (int)ob->query_skill("taoism", 1) >= 120)
                {
                        my["max_jing"] += (my["age"] - 60) * 5;
                }

                // 佛家养精：３０岁前补精，３０岁后长精
                if((xism_age=(int)ob->query_skill("buddhism", 1)) > 39)
                {
                        xism_age = xism_age/2;
                        if (my["age"] <= 30) xism_age -= my["age"];
                        else xism_age -= 30;

                        if (xism_age > 0) my["max_jing"] += xism_age *((int)ob->query_skill("hunyuan-yiqi", 1)/10);
                }

                if( my["max_jingli"] > 0 ) my["max_jing"] += my["max_jingli"] / 2;
                if(my["age"] > 20 && (int)ob->query_skill("biguan", 1) >= 100)
                {
                        my["max_jingli"] += 100;
                }

        }
        if( userp(ob) || undefinedp(my["max_qi"]) )
        {
                if( my["age"] <= 14 ) my["max_qi"] = 100;
                else if( my["age"] <= 30 ) my["max_qi"] = 100 + (my["age"] - 14) * my["con"];
                else my["max_qi"] = my["con"] * 16 + 100;

                if( my["age"] > 60 ) my["max_qi"] -= (my["age"] - 60) * 5;

                // 佛家保气：
                if(my["age"] > 60 && (int)ob->query_skill("buddhism", 1) >= 120)
                {
                        my["max_qi"] += (my["age"] - 60) * 5;
                }

                // 道家练气：３０岁前补气，３０岁后长气
                if((xism_age=(int)ob->query_skill("taoism", 1)) > 39)
                {
                        xism_age = xism_age/2;
                        if (my["age"] <= 30) xism_age -= my["age"];
                        else xism_age -= 30;

                        if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("taiji-shengong", 1)/10);
                }

                // 毒技练气：３０岁前补气，３０岁后长气
                if((xism_age=(int)ob->query_skill("poison", 1)) > 39)
                {
                        xism_age = xism_age/2;
                        if (my["age"] <= 30) xism_age -= my["age"];
                        else xism_age -= 30;

                        if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("huagong-dafa", 1)/15);
                }
//baituo
                if((xism_age=(int)ob->query_skill("training", 1)) > 139
                && (int)ob->query_skill("hamagong", 1)> 1 )
                {
                        xism_age = xism_age/2;
                        if (my["age"] <= 30) xism_age -= my["age"];
                        else xism_age -= 30;

                        if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("hamagong", 1)/18);
                }
//dali
else            if((xism_age=(int)ob->query_skill("buddhism", 1)) > 139
                && (int)ob->query_skill("kurong-changong", 1) > 1)
                {
                        xism_age = xism_age/2;
                        if (my["age"] <= 30) xism_age -= my["age"];
                        else xism_age -= 30;

                        if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("kurong-changong", 1)/18);
                }
//emei
else            if((xism_age=(int)ob->query_skill("mahayana", 1)) > 139
                && (int)ob->query_skill("linji-zhuang", 1)>1)
                {
                        xism_age = xism_age/2;
                        if (my["age"] <= 30) xism_age -= my["age"];
                        else xism_age -= 30;

                        if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("linji-zhuang", 1)/15);
                }
//gaibang
else            if((xism_age=(int)ob->query_skill("begging", 1)) > 139
                && (int)ob->query_skill("huntian-qigong", 1)>1)
                {
                        xism_age = xism_age/2;
                        if (my["age"] <= 30) xism_age -= my["age"];
                        else xism_age -= 30;

                        if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("huntian-qigong", 1)/20);
                }
//mr
else            if((xism_age=(int)ob->query_skill("douzhuan-xingyi", 1)) > 139
                && (int)ob->query_skill("shenyuan-gong", 1)>1 )
                {
                        xism_age = xism_age/2;
                        if (my["age"] <= 30) xism_age -= my["age"];
                        else xism_age -= 30;

                        if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("shenyuan-gong", 1)/18);
                }
//gumu
else            if((xism_age=(int)ob->query_skill("qufeng", 1)) > 139
                && (int)ob->query_skill("yunv-xinfa", 1) > 1)
                {
                        xism_age = xism_age/2;
                        if (my["age"] <= 30) xism_age -= my["age"];
                        else xism_age -= 30;

                        if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("yunv-xinfa", 1)/15);
                }
//huashan
else            if((xism_age=(int)ob->query_skill("zhengqijue", 1)) > 139
                &&(int)ob->query_skill("zixia-shengong", 1)>1)
                {
                        xism_age = xism_age/2;
                        if (my["age"] <= 30) xism_age -= my["age"];
                        else xism_age -= 30;

                        if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("zixia-shengong", 1)/20);
if ((int)ob->query_skill("huashan-neigong", 1)>(int)ob->query_skill("zixia-shengong", 1))
{
                        if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("huashan-neigong", 1)/20);
}
                }
//kl
else            if((xism_age=(int)ob->query_skill("art", 1)) > 139
                && (int)ob->query_skill("xuantian-wuji", 1)>1)
                {
                        xism_age = xism_age/2;
                        if (my["age"] <= 30) xism_age -= my["age"];
                        else xism_age -= 30;

                        if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("xuantian-wuji", 1)/16);
                }
//lj
else            if((xism_age=(int)ob->query_skill("yangyanshu", 1)) > 139
&& (int)ob->query_skill("bahuang-gong", 1)>1)
                {
                        xism_age = xism_age/2;
                        if (my["age"] <= 30) xism_age -= my["age"];
                        else xism_age -= 30;

                        if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("bahuang-gong", 1)/15);
                }
//mz
else            if((xism_age=(int)ob->query_skill("lamaism", 1)) > 139
&& (int)ob->query_skill("longxiang", 1)>1)
                {
                        xism_age = xism_age/2;
                        if (my["age"] <= 30) xism_age -= my["age"];
                        else xism_age -= 30;

                        if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("longxiang", 1)/20);
                }
//mj
else            if((xism_age=(int)ob->query_skill("shenghuo-shengong", 1)) > 139
&& (int)ob->query_skill("jiuyang-shengong", 1)>1)
                {
                        xism_age = xism_age/2;
                        if (my["age"] <= 30) xism_age -= my["age"];
                        else xism_age -= 30;

                        if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("jiuyang-shengong", 1)/18);
                }
//qz
else            if((xism_age=(int)ob->query_skill("taoism", 1)) > 139
&& (int)ob->query_skill("xiantian-qigong", 1)>1)
                {
                        xism_age = xism_age/2;
                        if (my["age"] <= 30) xism_age -= my["age"];
                        else xism_age -= 30;

                        if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("xiantian-qigong", 1)/18);
                }
//ry
else            if((xism_age=(int)ob->query_skill("kuihua-xinfa", 1)) > 139
&& (int)ob->query_skill("tmdafa", 1)>1)
                {
                        xism_age = xism_age/2;
                        if (my["age"] <= 30) xism_age -= my["age"];
                        else xism_age -= 30;

                        if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("tmdafa", 1)/18);
                }
//sl
else            if((xism_age=(int)ob->query_skill("yijinjing", 1)) > 139
&& (int)ob->query_skill("hunyuan-yiqi", 1)>1)
                {
                        xism_age = xism_age/2;
                        if (my["age"] <= 30) xism_age -= my["age"];
                        else xism_age -= 30;

                        if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("hunyuan-yiqi", 1)/20);
                }
//shenlong
else            if((xism_age=(int)ob->query_skill("yangsheshu", 1)) > 139
&& (int)ob->query_skill("shenlong-xinfa", 1)>1)
                {
                        xism_age = xism_age/2;
                        if (my["age"] <= 30) xism_age -= my["age"];
                        else xism_age -= 30;

                        if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("shenlong-xinfa", 1)/15);
                }
//taohua
else            if((xism_age=(int)ob->query_skill("count", 1)) > 139
&& (int)ob->query_skill("bibo-shengong", 1)>1)
                {
                        xism_age = xism_age/2;
                        if (my["age"] <= 30) xism_age -= my["age"];
                        else xism_age -= 30;

                        if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("bibo-shengong", 1)/15);
                }
//tiandi
else            if((xism_age=(int)ob->query_skill("yunlong-shenfa", 1)) > 139
                && (int)ob->query_skill("yunlong-shengong", 1)>1)
                {
                        xism_age = xism_age/2;
                        if (my["age"] <= 30) xism_age -= my["age"];
                        else xism_age -= 30;

                        if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("yunlong-shengong", 1)/15);
                }
//tz
else            if((xism_age=(int)ob->query_skill("shuishangpiao", 1)) > 139
                && (int)ob->query_skill("guiyuan-tunafa", 1)>1)
                {
                        xism_age = xism_age/2;
                        if (my["age"] <= 30) xism_age -= my["age"];
                        else xism_age -= 30;

                        if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("guiyuan-tunafa", 1)/15);
                }
//xiaoyao
else            if((xism_age=(int)ob->query_skill("yangyanshu", 1)) > 139
                && (int)ob->query_skill("beiming-shengong", 1)>1)
                {
                        xism_age = xism_age/2;
                        if (my["age"] <= 30) xism_age -= my["age"];
                        else xism_age -= 30;

                        if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("beiming-shengong", 1)/15);
                }
//lingxiao
else            if((xism_age=(int)ob->query_skill("snowstep", 1)) > 139
                && (int)ob->query_skill("bingxue-xinfa", 1)>1)
                {
                        xism_age = xism_age/2;
                        if (my["age"] <= 30) xism_age -= my["age"];
                        else xism_age -= 30;

                        if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("bingxue-xinfa", 1)/18);
                }
//wudu
else            if((xism_age=(int)ob->query_skill("duji", 1)) > 139
                && (int)ob->query_skill("wudu-shengong", 1)>1)
                {
                        xism_age = xism_age/2;
                        if (my["age"] <= 30) xism_age -= my["age"];
                        else xism_age -= 30;

                        if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("wudu-shengong", 1)/18);
                }
 
//
                if( my["max_neili"] > 0 ) my["max_qi"] += my["max_neili"] / 2;
        }

        ob->set_default_object(__FILE__);
        if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)*2000);
}

mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}
