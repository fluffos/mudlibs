string *weapon_skill = ({ 
// 5 blade
        "ranmu-daofa",
        "lieyan-dao",
	"fanliangyi-dao",
        "xuedao-jing",
        "murong-daofa",
// 6 sword
        "huashan-jianfa",
        "taiji-jian",
        "damo-jian",
        "jinshe-jianfa",
        "duanjia-jianfa",
        "xuantie-jianfa",
// 3 whip
        "riyue-bian",
        "songyang-bian",
        "yinsuo-jinling",
// 1 stick
        "dagou-bang",
// 1 club
        "weituo-chu",
});

string *weapon_p = ({
// blade
        "fentian",
        "shenghuo",
        "sanshenfeng",
        "shendao",
        "daoying",
//sword
        "jianmang",
        "lian",
        "sanjue",
        "kuangwu",
        "fenglei",
        "haichao",
// whip
        "riyue",
        "luan",
        "yueyin",
// stick
        "linglong",
// club
        "chaodu",
});

string *k_force =({ 
// blade
                        "yijin-jing",
                        "shenghuo-shengong",
                        "zixia-gong",
                        "longxiang-boruo",
                        "shenyuan-gong",
// sword
                        "zixia-gong",
                        "yinyun-ziqi",
                        "yijin-jing",
                        "bihai-chaosheng",
                        "kurong-changong",
                        "yunu-xinjing",
// whip
                        "yijin-jing",
                        "hanbing-zhenqi",
                        "yunu-xinjing",
// stick
                        "huntian-qigong",
// club
                        "yijin-jing",
});

string *k_dodge =({ 
                        "piaoyi-shenfa",
                        "suibo-zhuliu",
                        "tianlong-xiang",
                        "tiyunzong",
                        "shaolin-shenfa",
                        "yunu-shenfa",
                        "kunlun-shenfa",
                        "shuishangpiao",
                        "yanling-shenfa",
                        "zhaixingshu", 
                        "xiaoyaoyou",
                        "anying-fuxiang",});

mapping *skill2=({
/*cuff*/
       (["t_skill" :              "taiji-quan",
         "b_skill" :              "cuff",]),
        (["t_skill" :              "taizu-quan",
         "b_skill" :              "cuff",]),  
        (["t_skill" :              "jingang-quan",
         "b_skill" :              "cuff",]),  
        (["t_skill" :              "kongming-quan",
         "b_skill" :              "cuff",]), 
        (["t_skill" :              "poyu-quan",
         "b_skill" :              "cuff",]), 
        (["t_skill" :              "qishang-quan",
         "b_skill" :              "cuff",]), 
        (["t_skill" :              "meinu-quanfa",
         "b_skill" :              "cuff",]), 
        (["t_skill" :              "wenjia-quan",
         "b_skill" :              "cuff",]), 
/*strike*/
        (["t_skill" :              "qingyan-zhang",
         "b_skill" :              "strike",]),  
       (["t_skill" :              "hanbing-mianzhang",
         "b_skill" :              "strike",]),  
       (["t_skill" :              "hanbing-shenzhang",
         "b_skill" :              "strike",]),  
        (["t_skill" :              "xingyi-zhang",
         "b_skill" :              "strike",]),  
        (["t_skill" :              "sanhua-zhang",
         "b_skill" :              "strike",]),  
        (["t_skill" :              "banruo-zhang",
         "b_skill" :              "strike",]),  
        (["t_skill" :              "chousui-zhang",
         "b_skill" :              "strike",]),  
        (["t_skill" :              "hunyuan-zhang",
         "b_skill" :              "strike"]),
        (["t_skill" :              "jinding-mianzhang",
         "b_skill" :              "strike"]),
        (["t_skill" :              "jinshe-zhangfa",
         "b_skill" :              "strike"]),
        (["t_skill" :              "luoying-zhang",
         "b_skill" :              "strike",]),  
        (["t_skill" :              "kunlun-zhang",
         "b_skill" :              "strike",]), 
        (["t_skill" :              "tiangang-zhang",
         "b_skill" :              "strike",]),
        (["t_skill" :              "sixiang-zhang",
         "b_skill" :              "strike",]),
        (["t_skill" :              "tiezhang-zhangfa",
         "b_skill" :              "strike",]),
//      (["t_skill" :              "xianglong-zhang",
//       "b_skill" :              "strike",]),
/*hand*/
        (["t_skill" :              "yingzhua-shou",
         "b_skill" :              "hand",]),
        (["t_skill" :              "suohou-shou",
         "b_skill" :              "hand",]),
        (["t_skill" :              "songyang-shou",
         "b_skill" :              "hand",]),
        (["t_skill" :              "jieshou-jiushi",
         "b_skill" :              "hand",]),
        (["t_skill" :              "juehu-shou",
         "b_skill" :              "hand",]),
        (["t_skill" :              "lanhua-shou",
         "b_skill" :              "hand",]),
        (["t_skill" :              "qianye-shou",
         "b_skill" :              "hand",]),
//      (["t_skill" :              "qianzhu-wandushou",
//       "b_skill" :              "hand",]),
//      (["t_skill" :              "zhemei-shou",
//       "b_skill" :              "hand",]),
/*leg*/
        (["t_skill" :              "ruying-suixingtui",
         "b_skill" :              "leg",]),
        (["t_skill" :              "xuanfeng-tui",
         "b_skill" :              "leg",]),
/*finger*/
        (["t_skill" :              "yiyang-zhi",
         "b_skill" :              "finger",]),
        (["t_skill" :              "yizhi-chan",
         "b_skill" :              "finger",]),
        (["t_skill" :              "tanzhi-shentong",
         "b_skill" :              "finger",]),
        (["t_skill" :              "canhe-zhi",
         "b_skill" :              "finger",]),
        (["t_skill" :              "nianhua-zhi",
         "b_skill" :              "finger",]),
/*claw*/
        (["t_skill" :              "yingzhua-gong",
         "b_skill" :              "claw",]),
        (["t_skill" :              "jimie-zhua",
         "b_skill" :              "claw",]),
        (["t_skill" :              "longzhua-gong",
         "b_skill" :              "claw",]),

});

int do_clone(object me, object ob)
{
	object old_weapon;
        mapping killerskill1;
        int number,number_t,k_qi,k_neili,k_jing, j, k, which;
        string t_force,t_dodge,weapon,w_skill;

        number = (int)ob->query("max_pot");
        number = number - 100;
        k_qi = (int)ob->query("max_qi") + random((int)ob->query("max_qi") / 10 + 1000);
        k_jing = (int)ob->query("max_jing");
        k_neili = (int)ob->query("max_neili") + random((int)ob->query("max_qi") / 10 + 1000);
        j = (int)ob->query("dex");
        k = (int)ob->query("str");

        killerskill1 = skill2[random(sizeof(skill2))];

// skills LVL
        number = number - random(10);
        number_t = number + random(15);
//        if (number > 300) number_t = 300;

        if( ob->query("hmy_job") > 200 || number > 300) {
                me->set_temp("apply/parry",  number / 5 + random(number / 4));
                me->set_temp("apply/attack",  number / 5 + random(number / 4));
        }
//set killer's skill
        t_force = k_force[random(sizeof(k_force))];       
        t_dodge = k_dodge[random(sizeof(k_dodge))];       
        me->set_skill("force",number_t);
        me->set_skill("dodge",number_t);
        me->set_skill("jingang-quan",210);
        me->set_skill(t_force,number_t);
        me->set_skill(t_dodge,number_t);
        me->set_skill(killerskill1["t_skill"],number_t);
        me->set_skill(killerskill1["b_skill"],number_t);
// set killer's  skill maps
        me->map_skill("force",t_force);
        me->map_skill("dodge",t_dodge);
        me->map_skill("parry",killerskill1["t_skill"]);
        me->map_skill(killerskill1["b_skill"],killerskill1["t_skill"]);
// set killer's skill prepares
        me->prepare_skill(killerskill1["b_skill"],killerskill1["t_skill"]);
// copy entire dbase values
        me->set("max_qi",k_qi);
        me->set("eff_qi",k_qi);
        me->set("qi",k_qi);
        me->set("max_jing",k_jing);
        me->set("eff_jing",k_jing);
        me->set("jing",k_jing);
        me->set("max_neili",k_neili);
        me->set("neili",k_neili);
        me->set("jiali", k_neili / 40);
        me->set("combat_exp",ob->query("combat_exp")* 12/10);
        
// set weapon skill
        if (!random(3)) {
                switch(random(16) + 1) {
                        case 1 :
                        case 2 :
                        case 3 :
                        case 4 :
                        case 5 :
                                weapon = "blade";
                                which = random(5);
                                break;
                        case 6 :
                        case 7 :
                        case 8 :
                        case 9 :
                        case 10 :
                        case 11 :
                                weapon = "sword";
                                which = 5 + random(6);
                                break;
                        case 12 :
                        case 13 :
                        case 14 :
                                weapon = "whip";
                                which = 11 + random(3);
                                break;
                        case 15 :
                                weapon = "stick";
                                which = 14;
                                break;
                        case 16 :
                                weapon = "club";
                                which = 15;
                                break;
                        default :
				which = 6 + random(6);
                                which = 6 + random(6);
                                 break;
                }
                w_skill = weapon_skill[which];
                me->set_skill(k_force[which],number_t);
                me->set_skill(w_skill,number_t);
                me->set_skill(weapon,number_t);
                me->map_skill("force",k_force[which]);
                me->map_skill("parry",w_skill);
                me->map_skill(weapon,w_skill);
                me->set("chat_chance_combat", 40);
                me->set("chat_msg_combat", ({
                        (: perform_action, weapon + "." + weapon_p[which] :)
                }) );

                if (weapon != "blade") {
                        if (old_weapon = me->query_temp("weapon"))
                                old_weapon->unequip();
                        carry_object(__DIR__"obj/" + weapon)->wield();
                }
                if (!me->query_temp("weapon"))
                        carry_object("/clone/weapon/blade")->wield();
                me->set("weaponset",1);
        }

// add log here
        write_file("/log/job/HMY_KILL",sprintf("%s %s(%s) FIGHT TONG，TONG等级是 %d，%s，本人等级是 %d。\n",
        ctime(time()),ob->name(1),ob->query("id"),number_t,me->query("weaponset")?"有"+w_skill:"无weapon",(int)ob->query("max_pot")-100));

        if (!me->query("weaponset") && old_weapon = me->query_temp("weapon"))
                old_weapon->unequip();
        me->set_temp("skillset",1);
        command("say 来吧，让我试试你功夫如何！");
        return 1;
}
