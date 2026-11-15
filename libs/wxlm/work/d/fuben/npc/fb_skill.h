
//#include "fb_copy.h"
#include "/d/fuben/npc/fb_copy.h"

// 设置基础技能等级
void set_basic()
{
        string *basic_skills = ({
                "literate", "strike", "cuff", "hand", "dodge", "sword",
                "finger", "force", "parry", "blade", "hammer", "club",
                "staff", "whip", "dagger", "claw", "unarmed"
        });
        
        foreach(string skill in basic_skills) {
                set_skill(skill, 500);
        }
}

void set_martial()
{
        mapping martial_styles, style;
        string *style_names, chosen_style, skill, skill_name, weapon;
        
        // 定义门派武功映射
        martial_styles = ([
                "武当": ([
                        "skills": ([
                                "force": "taiji-shengong",
                                "dodge": "tiyunzong",
                                "sword": "taiji-jian",
                                "hand": "paiyun-shou", 
                                "unarmed": "taiji-quan"
                        ]),
                        "prepare": ([ 
                                "hand": "paiyun-shou",
                                "unarmed": "taiji-quan"
                        ]),
                        "weapon": "changjian",
                        "combat_actions": ({
                                (: exert_function, "powerup" :),
                                (: perform_action, "sword.lian" :),
                                (: perform_action, "sword.chan" :),
                                (: perform_action, "sword.sui" :),
                                (: perform_action, "unarmed.zhen" :),
                                (: exert_function, "recover" :)
                        })
                ]),
                "少林": ([
                        "skills": ([
                                "force": "hunyuan-yiqi",
                                "dodge": "shaolin-shenfa",
                                "sword": "damo-jian",
                                "finger": "nianhua-zhi",
                                "strike": "sanhua-zhang"
                        ]),
                        "prepare": ([
                                "finger": "nianhua-zhi",
                                "strike": "sanhua-zhang"
                        ]),
                        "weapon": "changjian",
                        "combat_actions": ({
                                (: perform_action, "sword.sanjue" :),
                                (: perform_action, "strike.san" :),
                                (: exert_function, "powerup" :),
                                (: exert_function, "recover" :)
                        })
                ]),
                "华山": ([
                        "skills": ([
                                "force": "zixia-shengong",
                                "dodge": "feiyan-huixiang",
                                "sword": "huashan-sword",
                                "cuff": "poyu-quan",
                                "strike": "hunyuan-zhang"
                        ]),
                        "prepare": ([
                                "cuff": "poyu-quan",
                                "strike": "hunyuan-zhang"
                        ]),
                        "weapon": "changjian",
                        "combat_actions": ({
                                (: perform_action, "sword.jianzhang" :),
                                (: perform_action, "sword.jie" :),
                                (: perform_action, "cuff.leidong" :),
                                (: perform_action, "cuff.poshi" :),
                                (: exert_function, "powerup" :),
                                (: exert_function, "recover" :)
                        })
                ]),
                "神龙": ([
                        "skills": ([
                                "force": "shenlong-xinfa",
                                "dodge": "yixingbu",
                                "hand": "shenlong-bashi",
                                "strike": "huagu-mianzhang",
                                "staff": "shedao-qigong"
                        ]),
                        "prepare": ([
                                "strike": "huagu-mianzhang",
                                "hand": "shenlong-bashi"
                        ]),
                        "weapon": "null",
                        "combat_actions": ({
                                (: perform_action, "strike.hua" :),
                                (: perform_action, "hand.xian" :),
                                (: exert_function, "powerup" :),
                                (: exert_function, "recover" :)
                        })
                ]),
                "丐帮": ([
                        "skills": ([
                                "force": "huntian-qigong",
                                "dodge": "feiyan-zoubi",
                                "staff": "dagou-bang",
                                "strike": "dragon-strike"
                        ]),
                        "prepare": ([
                                "strike": "dragon-strike"
                        ]),
                        "weapon": "gangzhang",
                        "combat_actions": ({
                                (: exert_function, "powerup" :),
                                (: exert_function, "recover" :),
                                (: perform_action, "staff.chan" :),
                                (: perform_action, "staff.ban" :)
                        })
                ]),
                "桃花": ([
                        "skills": ([
                                "force": "bibo-shengong",
                                "dodge": "anying-fuxiang",
                                "sword": "yuxiao-jian",
                                "hand": "lanhua-shou",
                                "finger": "tanzhi-shentong"
                        ]),
                        "prepare": ([
                                "hand": "lanhua-shou",
                                "unarmed": "tanzhi-shentong"
                        ]),
                        "weapon": "changjian",
                        "combat_actions": ({
                                (: exert_function, "powerup" :),
                                (: perform_action, "sword.qing" :),
                                (: perform_action, "sword.tianwai" :),
                                (: perform_action, "hand.fuxue" :),
                                (: perform_action, "finger.jinglei" :),
                                (: exert_function, "recover" :)
                        })
                ]),
                "古墓": ([
                        "skills": ([
                                "force": "yunv-xinfa",
                                "dodge": "yunv-shenfa",
                                "sword": "yunv-jian",
                                "unarmed": "meinv-quan",
                                "strike": "tianluo-diwang",
                                "throwing": "yufeng-zhen"
                        ]),
                        "prepare": ([
                                "unarmed": "meinv-quan",
                                "strike": "tianluo-diwang"
                        ]),
                        "weapon": "changjian",
                        "combat_actions": ({
                                (: exert_function, "recover" :),
                                (: exert_function, "powerup" :),
                                (: perform_action, "strike.wang" :),
                                (: perform_action, "sword.he" :),
                                (: perform_action, "sword.lian" :),
                                (: perform_action, "unarmed.you" :),
                                (: perform_action, "throwing.wuying" :)
                        })
                ]),
                "雪山": ([
                        "skills": ([
                                "force": "longxiang",
                                "dodge": "shenkong-xing",
                                "cuff": "yujiamu-quan",
                                "hand": "dashou-yin",
                                "hammer": "riyue-lun"
                        ]),
                        "prepare": ([
                                "hand": "dashou-yin",
                                "cuff": "yujiamu-quan"
                        ]),
                        "weapon": "yinlun",
                        "combat_actions": ({
                                (: perform_action, "hammer.poli" :),
                                (: perform_action, "hammer.wulun" :),
                                (: perform_action, "hand.jingang" :),
                                (: perform_action, "cuff.chen" :),
                                (: exert_function, "powerup" :),
                                (: exert_function, "recover" :)
                        })
                ]),
                "星宿": ([
                        "skills": ([
                                "force": "huagong-dafa",
                                "dodge": "zhaixinggong",
                                "strike": "chousui-zhang",
                                "claw": "sanyin-wugongzhao",
                                "staff": "tianshan-zhang"
                        ]),
                        "prepare": ([
                                "strike": "chousui-zhang",
                                "claw": "sanyin-wugongzhao"
                        ]),
                        "weapon": "gangzhang",
                        "combat_actions": ({
                                (: perform_action, "staff.fugu" :),
                                (: perform_action, "staff.xue" :),
                                (: perform_action, "strike.biyan" :),
                                (: perform_action, "strike.huolang" :),
                                (: perform_action, "strike.huoqiu" :),
                                (: perform_action, "strike.huoyan" :),
                                (: perform_action, "claw.zhua" :),
                                (: exert_function, "recover" :),
                                (: exert_function, "powerup" :)
                        })
                ]),
                "欧阳世家": ([
                        "skills": ([
                                "force": "hamagong",
                                "dodge": "chanchu-bufa",
                                "staff": "lingshe-zhangfa",
                                "cuff": "lingshe-quan",
                                "finger": "shedu-qiqiao"
                        ]),
                        "prepare": ([
                                "cuff": "lingshe-quan",
                                "finger": "shedu-qiqiao"
                        ]),
                        "weapon": "gangzhang",
                        "combat_actions": ({
                                (: perform_action, "staff.chan" :),
                                (: perform_action, "staff.qianshe" :),
                                (: perform_action, "staff.wuji" :),
                                (: perform_action, "cuff.rou" :),
                                (: exert_function, "powerup" :),
                                (: exert_function, "recover" :)
                        })
                ]),
                "全真": ([
                        "skills": ([
                                "force": "quanzhen-xinfa",
                                "dodge": "jinyan-gong",
                                "strike": "haotian-zhang",
                                "finger": "zhongnan-zhi",
                                "sword": "quanzhen-jian"
                        ]),
                        "prepare": ([
                                "strike": "haotian-zhang",
                                "finger": "zhongnan-zhi"
                        ]),
                        "weapon": "changjian",
                        "combat_actions": ({
                                (: perform_action, "sword.ding" :),
                                (: perform_action, "sword.hua" :),
                                (: perform_action, "strike.ju" :),
                                (: exert_function, "recover" :),
                                (: exert_function, "powerup" :)
                        })
                ]),
                "逍遥": ([
                        "skills": ([
                                "force": "beiming-shengong",
                                "dodge": "lingbo-weibu",
                                "hand": "zhemei-shou",
                                "strike": "liuyang-zhang",
                                "blade": "ruyi-dao"
                        ]),
                        "prepare": ([
                                "hand": "zhemei-shou",
                                "strike": "liuyang-zhang"
                        ]),
                        "weapon": "gangdao",
                        "combat_actions": ({
                                (: perform_action, "blade.ruyi" :),
                                (: perform_action, "hand.jiubu" :),
                                (: perform_action, "strike.jiutian" :),
                                (: exert_function, "recover" :),
                                (: exert_function, "powerup" :)
                        })
                ]),
                "血刀": ([
                        "skills": ([
                                "force": "xuehai-mogong",
                                "dodge": "shenkong-xing",
                                "hand": "dashou-yin",
                                "cuff": "yujiamu-quan",
                                "blade": "xue-dao"
                        ]),
                        "prepare": ([
                                "cuff": "yujiamu-quan",
                                "hand": "dashou-yin"
                        ]),
                        "weapon": "gangdao",
                        "combat_actions": ({
                                (: perform_action, "blade.shendao" :),
                                (: perform_action, "blade.xueyu" :),
                                (: perform_action, "hand.jingang" :),
                                (: perform_action, "cuff.chen" :),
                                (: exert_function, "powerup" :),
                                (: exert_function, "recover" :)
                        })
                ])
        ]);

        // 随机选择门派
        style_names = keys(martial_styles);
        chosen_style = style_names[random(sizeof(style_names))];
        style = martial_styles[chosen_style];
        
        // 设置基础战斗属性
        set("chat_chance_combat", 80);
        
        // 设置技能
        foreach(skill, skill_name in style["skills"]) {
                set_skill(skill, 1);
                set_skill(skill_name, 1);
                map_skill(skill, skill_name);
        }
        
        // 设置准备技能
        if(style["prepare"]) {
                foreach(skill, skill_name in style["prepare"]) {
                        prepare_skill(skill, skill_name);
                }
        }
        
        // 设置战斗招式
        if(style["combat_actions"]) {
                set("chat_msg_combat", style["combat_actions"]);
        }
        
        // 设置武器
        weapon = style["weapon"] || "null";
        set("weapon", weapon);
        if (weapon != "null") {
                if (weapon == "yinlun")
                        carry_object("/d/xueshan/obj/yinlun")->wield();
                else
                        carry_object("/clone/weapon/" + weapon)->wield();
        }
        carry_object("/clone/cloth/cloth")->wear();
}

void check_fight()
{
        object ob;
        string weapon;
        
        ob = this_object();
        weapon = ob->query("weapon");
        
        if (stringp(weapon) && weapon != "null" && !ob->query_temp("weapon"))
        {
                message_vision("$N又拿出一把兵器握在手中。\n", ob);
                if (weapon == "yinlun")
                        carry_object("/d/xueshan/obj/yinlun")->wield();
                else
                        carry_object("/clone/weapon/" + weapon)->wield();
        }
        call_out("check_fight", 1);
}

void do_clone(object me, int lvl)
{
        set_martial();
        do_copy_player(me, this_object(), lvl);
        set_temp("do_clone", 1);
}
