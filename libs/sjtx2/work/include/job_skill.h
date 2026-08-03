void set_basic()
{       set_skill("literate",500);
        set_skill("strike", 500);
        set_skill("cuff", 500);
        set_skill("hand", 500);
        set_skill("dodge", 500);
        set_skill("sword", 500);
        set_skill("finger", 500);
        set_skill("force", 500);
        set_skill("parry", 500);
        set_skill("blade", 500);
        set_skill("hammer", 500);
        set_skill("stick", 500);
        set_skill("club", 500);
        set_skill("staff", 500);
        set_skill("whip", 500);
        set_skill("dagger", 500);
        set_skill("hook", 500);
        set_skill("leg", 500);
        set_skill("claw", 500);
        set_skill("unarmed", 500);
}
void set_martial()
{
        string weapon = "null";
        switch(random(33))
        {
                case 0:  // wd 太极拳
                        set_skill("yinyun-ziqi", 500);
                        set_skill("tiyunzong", 500);
                        set_skill("taiji-quan", 500);
                        map_skill("force", "yinyun-ziqi");
                        map_skill("dodge", "tiyunzong");
                        map_skill("parry", "taiji-quan");
                        map_skill("cuff", "taiji-quan");
                        prepare_skill("cuff", "taiji-quan");
                        set("family/family_name","武当派");
                        set("chat_chance_combat", 20);
                        set("chat_msg_combat", ({
                                (: exert_function, "taiji" :),
                                (: perform_action, "dodge.zong" :),
                                (: perform_action, "cuff.luanhuan" :),
                                (: perform_action, "cuff.zhannian" :),
                                (: perform_action, "cuff.yinyang" :),
                                (: perform_action, "cuff.gangrou" :),
                        }));
                        break;
                case 1:  // wd 太极剑
                        set_skill("yinyun-ziqi", 500);
                        set_skill("tiyunzong", 500);
                        set_skill("taiji-jian", 500);
                        set_skill("taiji-quan", 500);
                        map_skill("force", "yinyun-ziqi");
                        map_skill("dodge", "tiyunzong");
                        map_skill("sword", "taiji-jian");
                        map_skill("parry", "taiji-jian");
                        map_skill("cuff", "taiji-quan");
                        prepare_skill("cuff", "taiji-quan");
                        set("family/family_name","武当派");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "taiji" :),
                                (: perform_action, "dodge.zong" :),
                                (: perform_action, "sword.chan" :),
                                (: perform_action, "sword.sanhuan" :),
                                (: perform_action, "sword.raozhi" :),
                        }));
                        weapon = "sword";
                        break;
                case 2:  // sl 日月鞭法
                        set_skill("yijin-jing", 500);
                        set_skill("shaolin-shenfa", 500);
                        set_skill("riyue-bian", 500);
                        set_skill("yizhi-chan", 500);
                        map_skill("force", "yijin-jing");
                        map_skill("dodge", "shaolin-shenfa");
                        map_skill("whip", "riyue-bian");
                        map_skill("parry", "riyue-bian");
                        map_skill("finger", "yizhi-chan");
                        prepare_skill("finger", "yizhi-chan");
                        set("family/family_name","少林派");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "jingang" :),
                                (: perform_action, "whip.riyue" :),
                                (: perform_action, "whip.chanrao" :),
                        }));
                        weapon = "whip";
                        break;
                case 3:  // sl 燃木刀法
                        set_skill("yijin-jing", 500);
                        set_skill("shaolin-shenfa", 500);
                        set_skill("ranmu-daofa", 500);
                        set_skill("yizhi-chan", 500);
                        map_skill("force", "yijin-jing");
                        map_skill("dodge", "shaolin-shenfa");
                        map_skill("blade", "ranmu-daofa");
                        map_skill("parry", "ranmu-daofa");
                        map_skill("finger", "yizhi-chan");
                        prepare_skill("finger", "yizhi-chan");
                        set("family/family_name","少林派");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "jingang" :),
                                (: perform_action, "blade.fenwo" :),
                                (: perform_action, "blade.fenxin" :),
                                (: perform_action, "blade.fentian" :),
                        }));
                        weapon = "blade";
                        break;
                case 4:  // sl 韦陀杵
                        set_skill("yijin-jing", 500);
                        set_skill("shaolin-shenfa", 500);
                        set_skill("yizhi-chan", 500);
                        set_skill("weituo-chu", 500);
                        map_skill("force", "yijin-jing");
                        map_skill("dodge", "shaolin-shenfa");
                        map_skill("parry", "weituo-chu");
                        map_skill("finger", "yizhi-chan");
                        map_skill("club", "weituo-chu");
                        prepare_skill("finger", "yizhi-chan");
                        set("family/family_name","少林派");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "jingang" :),
                                (: perform_action, "club.leidong" :),
                                (: perform_action, "club.chaodu" :),
                        }));
                        weapon = "club";
                        break;
                case 5:  // sl 一指禅 龙抓功
                        set_skill("yijin-jing", 500);
                        set_skill("shaolin-shenfa", 500);
                        set_skill("yizhi-chan", 500);
                        set_skill("longzhua-gong", 500);
                        map_skill("force", "yijin-jing");
                        map_skill("dodge", "shaolin-shenfa");
                        map_skill("parry", "yizhi-chan");
                        map_skill("finger", "yizhi-chan");
                        map_skill("claw", "longzhua-gong");
                        prepare_skill("finger", "yizhi-chan");
                        prepare_skill("claw", "longzhua-gong");
                        set("family/family_name","少林派");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "jingang" :),
                                (: perform_action, "finger.wofo" :),
                                (: perform_action, "claw.lianhuan" :),
                        }));
                        break;
                case 6:  // sl 金刚拳 般若掌
                        set_skill("yijin-jing", 500);
                        set_skill("shaolin-shenfa", 500);
                        set_skill("banruo-zhang", 500);
                        set_skill("jingang-quan", 500);
                        map_skill("force", "yijin-jing");
                        map_skill("dodge", "shaolin-shenfa");
                        map_skill("parry", "banruo-zhang");
                        map_skill("cuff", "jingang-quan");
                        map_skill("strike", "banruo-zhang");
                        prepare_skill("cuff", "jingang-quan");
                        prepare_skill("strike", "banruo-zhang");
                        set("family/family_name","少林派");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "jingang" :),
                                (: perform_action, "strike.yipai" :),
                                (: perform_action, "cuff.fumo" :),
                        }));
                        break;
                case 7:  // sl 如影腿 千叶手
                        set_skill("yijin-jing", 500);
                        set_skill("shaolin-shenfa", 500);
                        set_skill("ruying-suixingtui", 500);
                        set_skill("qianye-shou", 500);
                        map_skill("force", "yijin-jing");
                        map_skill("dodge", "shaolin-shenfa");
                        map_skill("parry", "ruying-suixingtui");
                        map_skill("leg", "ruying-suixingtui");
                        map_skill("hand", "qianye-shou");
                        prepare_skill("hand", "qianye-shou");
                        prepare_skill("leg", "ruying-suixingtui");
                        set("family/family_name","少林派");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "jingang" :),
                                (: perform_action, "leg.ruying" :),
                                (: perform_action, "hand.qianshou" :),
                        }));
                        break;
                case 8:  // hs 混元掌
                        set_skill("zixia-gong", 500);
                        set_skill("huashan-shenfa", 500);
                        set_skill("hunyuan-zhang", 500);
                        map_skill("force", "zixia-gong");
                        map_skill("dodge", "huashan-shenfa");
                        map_skill("parry", "hunyuan-zhang");
                        map_skill("strike", "hunyuan-zhang");
                        prepare_skill("strike", "hunyuan-zhang");
                        set("family/family_name","华山派");
                        set("chat_chance_combat", 30);
                        set("family/sect", "气宗");
                        set("chat_msg_combat", ({
                                (: exert_function, "zixia" :),
                                (: perform_action, "strike.hunyuan" :),
                                (: perform_action, "strike.wuji" :),
                        }));
                        break;
                case 9:  // hs 华山剑法
                        set_skill("zixia-gong", 500);
                        set_skill("huashan-shenfa", 500);
                        set_skill("huashan-jianfa", 500);
                        set_skill("hunyuan-zhang", 500);
                        map_skill("force", "zixia-gong");
                        map_skill("dodge", "huashan-shenfa");
                        map_skill("sword", "huashan-jianfa");
                        map_skill("parry", "huashan-jianfa");
                        map_skill("strike", "hunyuan-zhang");
                        prepare_skill("strike", "hunyuan-zhang");
                        set("family/family_name","华山派");
                        set("chat_chance_combat", 30);
                        if (random(2))
                        {
                                set("family/sect", "剑宗");
                                set("chat_msg_combat", ({
                                        (: exert_function, "zixia" :),
                                        (: exert_function, "jianqi" :),
                                        (: perform_action, "sword.lianhuan" :),
                                        (: perform_action, "sword.fengyi" :),
                                        (: perform_action, "sword.kuaijian" :),
                                        (: perform_action, "sword.shijiushi" :),
                                }));
                        }
                        else
                        {
                                set("family/sect", "气宗");
                                set("chat_msg_combat", ({
                                        (: exert_function, "zixia" :),
                                        (: exert_function, "jianqi" :),
                                        (: perform_action, "sword.lianhuan" :),
                                        (: perform_action, "sword.luomu" :),
                                        (: perform_action, "sword.shijiushi" :),
                                        (: perform_action, "sword.jianzhang" :),
                                }));
                        }
                        weapon = "sword";
                        break;
                case 10: // sld 化骨绵掌
                        set_skill("poison", 500);
                        set_skill("dulong-dafa", 500);
                        set_skill("huagu-mianzhang", 500);
                        set_skill("shenlong-yaoli", 500);
                        set_skill("youlong-shenfa", 500);
                        map_skill("force", "dulong-dafa");
                        map_skill("dodge", "youlong-shenfa");
                        map_skill("parry", "huagu-mianzhang");
                        map_skill("strike", "huagu-mianzhang");
                        prepare_skill("strike", "huagu-mianzhang");
                        set("family/family_name","神龙岛");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "wudi" :),
                                (: exert_function, "shexin" :),
                                (: perform_action, "strike.bujue" :),
                        }));
                        break;
                case 11: // sld 腾龙匕法
                        set_skill("poison", 500);
                        set_skill("dulong-dafa", 500);
                        set_skill("huagu-mianzhang", 500);
                        set_skill("shenlong-yaoli", 500);
                        set_skill("tenglong-bifa", 500);
                        set_skill("youlong-shenfa", 500);
                        map_skill("force", "dulong-dafa");
                        map_skill("dodge", "youlong-shenfa");
                        map_skill("parry", "tenglong-bifa");
                        map_skill("strike", "huagu-mianzhang");
                        map_skill("dagger", "tenglong-bifa");
                        prepare_skill("strike", "huagu-mianzhang");
                        set("family/family_name","神龙岛");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "wudi" :),
                                (: exert_function, "shexin" :),
                                (: perform_action, "dagger.diqing" :),
                                (: perform_action, "dagger.zixu" :),
                                (: perform_action, "dagger.luda" :),
                                (: perform_action, "dagger.xiaolian" :),
                                (: perform_action, "dagger.feiyan" :),
                                (: perform_action, "dagger.guifei" :),
                        }));
                        weapon = "dagger";
                        break;
                case 12:  // gb 打狗棒法
                        set_skill("huntian-qigong", 500);
                        set_skill("bangjue", 500);
                        set_skill("xiaoyaoyou", 500);
                        set_skill("dagou-bang", 500);
                        set_skill("xianglong-zhang", 500);
                        map_skill("force", "huntian-qigong");
                        map_skill("dodge", "xiaoyaoyou");
                        map_skill("stick", "dagou-bang");
                        map_skill("parry", "dagou-bang");
                        map_skill("strike", "xianglong-zhang");
                        prepare_skill("strike", "xianglong-zhang");
                        set("family/family_name","丐帮");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "huntian" :),
                                (: perform_action, "stick.tiao" :),
                                (: perform_action, "stick.pi" :),
                                (: perform_action, "stick.yin" :),
                                (: perform_action, "stick.chan" :),
                                (: perform_action, "stick.ban" :),
                                (: perform_action, "stick.chuo" :),
                        }));
                        weapon = "stick";
                        break;
                case 13:  // gb 降龙十八掌
                        set_skill("huntian-qigong", 500);
                        set_skill("xiaoyaoyou", 500);
                        set_skill("xianglong-zhang", 500);
                        map_skill("force", "huntian-qigong");
                        map_skill("dodge", "xiaoyaoyou");
                        map_skill("parry", "xianglong-zhang");
                        map_skill("strike", "xianglong-zhang");
                        prepare_skill("strike", "xianglong-zhang");
                        set("family/family_name","丐帮");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "huntian" :),
                                (: perform_action, "strike.kanglong" :),
                                (: perform_action, "strike.paiyun" :),
                        }));
                        break;
                case 14:  // thd 组合
                        set_skill("qimen-bagua", 500);
                        set_skill("suibo-zhuliu", 500);
                        set_skill("xuanfeng-tui", 500);
                        set_skill("luoying-zhang", 500);
                        set_skill("lanhua-shou", 500);
                        set_skill("yuxiao-jian", 500);
                        set_skill("bihai-chaosheng", 500);
                        set_skill("tanzhi-shentong", 500);
                        map_skill("hand",  "lanhua-shou");
                        map_skill("force", "bihai-chaosheng");
                        map_skill("leg",   "xuanfeng-tui");
                        map_skill("strike", "luoying-zhang");
                        map_skill("dodge", "suibo-zhuliu");
                        map_skill("sword", "yuxiao-jian");
                        map_skill("parry", "yuxiao-jian");
                        map_skill("finger", "tanzhi-shentong");
                        prepare_skill("finger", "tanzhi-shentong");
                        set("family/family_name","桃花岛");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "maze" :),
                                (: exert_function, "qimen" :),
                                (: perform_action, "dodge.wuzhuan" :),
                                (: perform_action, "sword.feiying" :),
                        }));
                        weapon = "xiao";
                        break;
                case 15: // mr 慕容剑法
                        set_skill("shenyuan-gong", 500);
                        set_skill("douzhuan-xingyi", 500);
                        set_skill("yanling-shenfa", 500);
                        set_skill("murong-jianfa", 500);
                        set_skill("canhe-zhi", 500);
                        map_skill("force", "shenyuan-gong");
                        map_skill("dodge", "yanling-shenfa");
                        map_skill("sword", "murong-jianfa");
                        map_skill("parry", "murong-jianfa");
                        map_skill("finger", "canhe-zhi");
                        prepare_skill("finger", "canhe-zhi");
                        set("family/family_name","姑苏慕容");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "shenyuan" :),
                                (: perform_action, "sword.sanhua" :),
                                (: perform_action, "sword.lianhuan" :),
                        }));
                        weapon = "sword";
                        break;
                case 16: // mr 参合指
                        set_skill("shenyuan-gong", 500);
                        set_skill("douzhuan-xingyi", 500);
                        set_skill("yanling-shenfa", 500);
                        set_skill("murong-jianfa", 500);
                        set_skill("canhe-zhi", 500);
                        map_skill("force", "shenyuan-gong");
                        map_skill("dodge", "yanling-shenfa");
                        map_skill("sword", "murong-jianfa");
                        map_skill("parry", "canhe-zhi");
                        map_skill("finger", "canhe-zhi");
                        prepare_skill("finger", "canhe-zhi");
                        set("family/family_name","姑苏慕容");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "shenyuan" :),
                                (: perform_action, "finger.ci" :),
                        }));
                        break;
                case 17: // gumu 玄铁剑法
                        set_skill("yunu-xinjing", 500);
                        set_skill("yunu-shenfa", 500);
                        set_skill("xuantie-jianfa", 500);
                        set_skill("anran-zhang", 500);
                        map_skill("force", "yunu-xinjing");
                        map_skill("dodge", "yunu-shenfa");
                        map_skill("sword", "xuantie-jianfa");
                        map_skill("parry", "xuantie-jianfa");
                        map_skill("strike", "anran-zhang");
                        prepare_skill("strike", "anran-zhang");
                        set("family/family_name","古墓派");
                        set("gender", "男性");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "xinjing" :),
                                (: perform_action, "sword.haichao" :),
                                (: perform_action, "sword.wujian" :),
                        }));
                        weapon = "sword";
                        break;
                case 18: // gumu 黯然销魂掌
                        set_skill("yunu-xinjing", 500);
                        set_skill("yunu-shenfa", 500);
                        set_skill("xuantie-jianfa", 500);
                        set_skill("anran-zhang", 500);
                        map_skill("force", "yunu-xinjing");
                        map_skill("dodge", "yunu-shenfa");
                        map_skill("sword", "xuantie-jianfa");
                        map_skill("parry", "anran-zhang");
                        map_skill("strike", "anran-zhang");
                        prepare_skill("strike", "anran-zhang");
                        set("family/family_name","古墓派");
                        set("gender", "男性");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "xinjing" :),
                                (: perform_action, "strike.anran" :),
                                (: perform_action, "strike.xiaohun" :),
                        }));
                        break;
                case 19: // gumu 银索金铃
                        set("gmsanwu",1);
                        set_skill("yunu-xinjing", 500);
                        set_skill("yunu-shenfa", 500);
                        set_skill("yinsuo-jinling", 500);
                        set_skill("meinu-quanfa", 500);
                        map_skill("force", "yunu-xinjing");
                        map_skill("dodge", "yunu-shenfa");
                        map_skill("whip", "yinsuo-jinling");
                        map_skill("parry", "yinsuo-jinling");
                        map_skill("cuff", "meinu-quanfa");
                        prepare_skill("cuff", "meinu-quanfa");
                        set("family/family_name","古墓派");
                        set("gender", "女性");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "xinjing" :),
                                (: perform_action, "whip.sanwu" :),
                                (: perform_action, "whip.yueyin" :),
                        }));
                        weapon = "whip";
                        break;
                case 20: // emei 回风拂柳剑
                        set_skill("linji-zhuang", 500);
                        set_skill("anying-fuxiang", 500);
                        set_skill("huifeng-jian", 500);
                        set_skill("sixiang-zhang", 500);
                        map_skill("force", "linji-zhuang");
                        map_skill("dodge", "anying-fuxiang");
                        map_skill("sword", "huifeng-jian");
                        map_skill("parry", "huifeng-jian");
                        map_skill("strike", "sixiang-zhang");
                        prepare_skill("strike", "sixiang-zhang");
                        set("family/family_name","峨嵋派");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "riyue" :),
                                (: exert_function, "fengyun" :),
                                (: perform_action, "sword.miejue" :),
                                (: perform_action, "sword.liaoyuan" :),
                        }));
                        weapon = "sword";
                        break;
                case 21: // emei 截手九式
                        set_skill("linji-zhuang", 500);
                        set_skill("anying-fuxiang", 500);
                        set_skill("jieshou-jiushi", 500);
                        map_skill("force", "linji-zhuang");
                        map_skill("dodge", "anying-fuxiang");
                        map_skill("parry", "jieshou-jiushi");
                        map_skill("hand", "jieshou-jiushi");
                        prepare_skill("hand", "jieshou-jiushi");
                        set("family/family_name","峨嵋派");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "fengyun" :),
                                (: exert_function, "riyue" :),
                                (: perform_action, "strike.foguang" :),
                        }));
                        break;
                case 22: // mj 圣火令法
                        set_skill("qiankun-danuoyi", 500);
                        set_skill("piaoyi-shenfa", 500);
                        set_skill("shenghuo-lingfa", 500);
                        set_skill("shenghuo-shengong", 500);
                        set_skill("qishang-quan", 500);
                        map_skill("force", "shenghuo-shengong");
                        map_skill("dodge", "piaoyi-shenfa");
                        map_skill("dagger", "shenghuo-lingfa");
                        map_skill("parry", "shenghuo-lingfa");
                        map_skill("cuff", "qishang-quan");
                        prepare_skill("cuff", "qishang-quan");
                        set("family/family_name","明教");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "yinfeng" :),
                                (: perform_action, "dagger.tisha" :),
                                (: perform_action, "dagger.duo" :),
                        }));
                        weapon = "tieling";
                        break;
                case 23: // mj 七伤拳
                        set_skill("shenghuo-shengong", 500);
                        set_skill("qiankun-danuoyi", 500);
                        set_skill("piaoyi-shenfa", 500);
                        set_skill("qishang-quan", 500);
                        map_skill("force", "jiuyang-shengong");
                        map_skill("dodge", "piaoyi-shenfa");
                        map_skill("parry", "qishang-quan");
                        map_skill("cuff", "qishang-quan");
                        prepare_skill("cuff", "qishang-quan");
                        set("family/family_name","明教");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "yinfeng" :),
                                (: perform_action, "cuff.qishang" :),
                                (: perform_action, "cuff.duanhun" :),

                        }));
                        break;
                case 24: // tls 一阳指
                        set_skill("kurong-changong", 500);
                        set_skill("tianlong-xiang", 500);
                        set_skill("yiyang-zhi", 500);
                        map_skill("force", "kurong-changong");
                        map_skill("dodge", "tianlong-xiang");
                        map_skill("parry", "yiyang-zhi");
                        map_skill("finger", "yiyang-zhi");
                        prepare_skill("finger", "yiyang-zhi");
                        set("family/family_name","天龙寺");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "kurong" :),
                                (: perform_action, "finger.sanmai" :),
                                (: perform_action, "finger.sandie" :),
                        }));
                        break;
                case 25: // tz 铁掌掌法
                        set_skill("tiezhang-zhangfa", 500);
                        set_skill("shuishangpiao", 500);
                        set_skill("guiyuan-tunafa", 500);
                        set_skill("tiezhang-xinfa", 200);
                        map_skill("force", "guiyuan-tunafa");
                        map_skill("dodge", "shuishangpiao");
                        map_skill("parry", "tiezhang-zhangfa");
                        map_skill("strike", "tiezhang-zhangfa");
                        prepare_skill("strike", "tiezhang-zhangfa");
                        set("family/family_name","铁掌帮");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "guiyuan" :),
                                (: perform_action, "strike.tianlei" :),
                                (: perform_action, "strike.heyi" :),
                                (: perform_action, "strike.tiezhang" :),
                                (: perform_action, "dodge.piao" :),
                        }));
                        break;
                case 26: // xx 抽髓掌
                        set_skill("huagong-dafa", 500);
                        set_skill("chousui-zhang", 500);
                        set_skill("zhaixingshu", 500);
                        set_skill("poison", 200);
                        map_skill("force", "huagong-dafa");
                        map_skill("dodge", "zhaixingshu");
                        map_skill("parry", "chousui-zhang");
                        map_skill("strike", "chousui-zhang");
                        prepare_skill("strike", "chousui-zhang");
                        set("family/family_name","星宿派");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "huadu" :),
                                (: perform_action, "strike.chousui" :),
                        }));
                        break;
                case 27: // xx 天山杖法
                        set_skill("huagong-dafa", 500);
                        set_skill("tianshan-zhang", 500);
                        set_skill("chousui-zhang", 500);
                        set_skill("zhaixingshu", 500);
                        set_skill("poison", 200);
                        map_skill("force", "huagong-dafa");
                        map_skill("dodge", "zhaixing-shu");
                        map_skill("parry", "tianshan-zhang");
                        map_skill("strike", "chousui-zhang");
                        map_skill("staff", "tianshan-zhang");
                        prepare_skill("strike", "chousui-zhang");
                        set("family/family_name","星宿派");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "huadu" :),
                                (: perform_action, "staff.feizhi" :),
                        }));
                        weapon = "staff";
                        break;
                case 28: // ss 嵩山剑法
                        set_skill("hanbing-zhenqi", 500);
                        set_skill("zhongyuefeng", 500);
                        set_skill("songshan-jian", 500);
                        set_skill("hanbing-shenzhang", 500);
                        set_skill("poison", 200);
                        map_skill("force", "hanbing-zhenqi");
                        map_skill("dodge", "zhongyuefeng");
                        map_skill("parry", "songshan-jian");
                        map_skill("sword", "songshan-jian");
                        map_skill("strike", "hanbing-shenzhang");
                        prepare_skill("strike", "hanbing-shenzhang");
                        set("family/family_name","嵩山派");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "hanbing" :),
                                (: exert_function, "huti" :),
                                (: perform_action, "sword.feiwu" :),
                                (: perform_action, "sword.leiting" :),
                                (: perform_action, "sword.longfeng" :),
                        }));
                        weapon = "sword";
                        break;
                case 29: // ss 寒冰神掌
                        set_skill("hanbing-zhenqi", 500);
                        set_skill("zhongyuefeng", 500);
                        set_skill("songshan-jian", 500);
                        set_skill("hanbing-shenzhang", 500);
                        set_skill("poison", 200);
                        map_skill("force", "hanbing-zhenqi");
                        map_skill("dodge", "zhongyuefeng");
                        map_skill("parry", "hanbing-shenzhang");
                        map_skill("strike", "hanbing-shenzhang");
                        prepare_skill("strike", "hanbing-shenzhang");
                        set("family/family_name","嵩山派");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "hanbing" :),
                                (: exert_function, "hanjian" :),
                                (: perform_action, "strike.hanbing" :),
                        }));
                        break;
                case 30: // dls 火焰刀
                        set_skill("longxiang-boruo", 500);
                        set_skill("yuxue-dunxing", 500);
                        set_skill("huoyan-dao", 500);
                        map_skill("force", "longxiang-boruo");
                        map_skill("dodge", "yuxue-dunxing");
                        map_skill("parry", "huoyan-dao");
                        map_skill("strike", "huoyan-dao");
                        prepare_skill("strike", "huoyan-dao");
                        set("family/family_name", "大轮寺");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "longxiang" :),
                                (: perform_action, "strike.daoqi" :),
                                (: perform_action, "strike.ran" :),
                                (: perform_action, "strike.fen" :),
                        }));
                        break;
                case 31: // dls 血刀经
                        set_skill("longxiang-boruo", 500);
                        set_skill("yuxue-dunxing", 500);
                        set_skill("huoyan-dao", 500);
                        set_skill("xuedao-jing", 500);
                        map_skill("force", "longxiang-boruo");
                        map_skill("dodge", "yuxue-dunxing");
                        map_skill("parry", "xuedao-jing");
                        map_skill("strike", "huoyan-dao");
                        map_skill("blade", "xuedao-jing");
                        prepare_skill("strike", "huoyan-dao");
                        set("family/family_name","大轮寺");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "longxiang" :),
                                (: perform_action, "blade.jixue" :),
                                (: perform_action, "blade.shendao" :),
                        }));
                        weapon = "blade";
                        break;
                case 32: // dls 降服轮
                        set_skill("longxiang-boruo", 500);
                        set_skill("yuxue-dunxing", 500);
                        set_skill("huoyan-dao", 500);
                        set_skill("xiangfu-lun", 500);
                        map_skill("force", "longxiang-boruo");
                        map_skill("dodge", "yuxue-dunxing");
                        map_skill("parry", "xiangfu-lun");
                        map_skill("strike", "huoyan-dao");
                        map_skill("hammer", "xiangfu-lun");
                        prepare_skill("strike", "huoyan-dao");
                        set("family/family_name","大轮寺");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "longxiang" :),
                                (: perform_action, "hammer.wushuai" :),
                        }));
                        weapon = "chui";
                        break;
                default: // others      BUG!!!
                        set("long","武功设置错误，BUG！！！");
        }
        set("weapon", weapon);
        if (weapon != "null")
        carry_object(BINGQI_D(weapon))->wield();
        carry_object(ARMOR_D("cloth"))->wear();
}

void check_fight()
{
        object ob = this_object();
        string weapon;

        weapon = ob->query("weapon");
        if (stringp(weapon) && weapon != "null" && !ob->query_temp("weapon"))
        {
                message_vision("$N又拿出一把兵器握在手中。\n", ob);
                carry_object(BINGQI_D(weapon))->wield();
        }
        call_out("check_fight", 1);
}

void do_clone(object me, int lvl)
{
        set_martial();
        set("jiali", lvl * 50);
        TASK_D->do_copy_player(me, this_object(), lvl);
        set_temp("do_clone", 1);
}
