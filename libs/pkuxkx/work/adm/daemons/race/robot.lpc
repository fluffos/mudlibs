// robot.c
// 机器人
// by lordstar 2017/09/19

// A normal robot is at least 40 kg weight
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
        set("attitude", "peaceful");
		set("can_speak", 1);
        set("limbs", ({
                "头部", "颈部", "胸口", "后背", "左肩", "右肩", "左臂",
                "右臂", "左手", "右手", "腰间", "小腹", "左腿", "右腿",
                "左脚", "右脚"
        }) );
}

void setup_robot(object ob)
{
        mapping my;
        int xism_age;
        int jiu_skill,tai_skill,hun_skill,sep_force;
        string force;

        my = ob->query_entire_dbase();

        ob->set("default_actions", (: call_other, __FILE__, "query_action" :));
        
        if( undefinedp(my["age"]) ) my["age"] = 50;
        if (undefinedp(my["str"])) my["str"] = 10 + random(40);
        if (undefinedp(my["con"])) my["con"] = 10 + random(40);
        if (undefinedp(my["dex"])) my["dex"] = 10 + random(40);
        if (undefinedp(my["int"])) my["int"] = 10 + random(40);
        if (undefinedp(my["per"])) my["per"] = 10 + random(40);
        if (undefinedp(my["kar"])) my["kar"] = 10 + random(40);

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
            my["max_jing"] = 1000;

        if( userp(ob) || undefinedp(my["max_qi"]) )
            my["max_qi"] = 1000;
        
        if(my["eff_qi"] > my["max_qi"]) my["eff_qi"] = my["max_qi"];
        if(my["eff_jing"] > my["max_jing"]) my["eff_jing"] = my["max_jing"];
		
		ob->set_default_object(__FILE__);
        if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["con"] - 10)* 2000);
}

mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}
