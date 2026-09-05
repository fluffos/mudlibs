// human.c
// From ES2
// 1.由于年龄的计算规则变化，按年龄的精气减值修正为从60岁开始每年减少6+每十年增加1点 
// 2.level的气血精神规则略有变化，加入con和int的影响。100级以后提供额外气血和精神加成。
// by seagate@pkuxkx 2011/05/06
// 对气血和精神计算采用/feature/attribute.c里面的算法，需要注意的是npc气血算法简化计算。
// by seagate@pkuxkx 2012/03/22

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
        int jiu_skill,tai_skill,hun_skill,sep_force;
        string force;

        my = ob->query_entire_dbase();

        ob->set("default_actions", (: call_other, __FILE__, "query_action" :));
        
        if( undefinedp(my["age"]) ) my["age"] = 14;
        if (undefinedp(my["str"])) my["str"] = 10 + random(21);
        if (undefinedp(my["con"])) my["con"] = 10 + random(21);
        if (undefinedp(my["dex"])) my["dex"] = 10 + random(21);
        if (undefinedp(my["int"])) my["int"] = 10 + random(21);
        if (undefinedp(my["per"])) my["per"] = 10 + random(21);
        if (undefinedp(my["kar"])) my["kar"] = 10 + random(21);

        if(stringp(force = ob->query_skill_mapped("force")))
		    {
			      sep_force = (int)ob->query_skill(force, 1);
		    }
		    else{
			      sep_force = (int)ob->query_skill(force, 1);
				}

        if( undefinedp(my["level"]) ) 
            my["level"] = 0;
        
        if( userp(ob) || undefinedp(my["max_jing"]) ) 
            my["max_jing"] = ob->query_max_jing();

        if( userp(ob) || undefinedp(my["max_qi"]) )
            my["max_qi"] = ob->query_max_qi();
        
        if(my["eff_qi"] > my["max_qi"]) my["eff_qi"] = my["max_qi"];
        if(my["eff_jing"] > my["max_jing"]) my["eff_jing"] = my["max_jing"];

        ob->set_default_object(__FILE__);
        if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 2000);
}

mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}
