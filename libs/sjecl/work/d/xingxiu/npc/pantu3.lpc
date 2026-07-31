// body guard 保镖
// by emnil@sj          2/9/2k
// 大理，明教，娥眉，古墓，少林，华山，桃花岛，武当，丐帮，华山
// 铁掌，星宿，大轮寺，神龙岛
// 渡狂(Rockman)：★※ 金刚拳+班若掌,如影腿+千手,龙爪功加一指蝉 ※★
// caiji@SJ修改自 emnil@sj的body guard 保镖
// 8/8/2000

inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;

#include <ansi.h>

void checkfight();
void check_position(int count);
void display();
void dest();
string ask_target();
int do_copy(object target,int mode);

string *first_name = ({ "赵","钱","孙","李","周","吴","郑","王","张","陈", "刘","林",
"冯","卫","蒋","沈","韩","杨","朱","秦","尤","许","何","吕","施","上官","司马","司徒"});
string *first_name_id = ({ "zhao","qian","sun","li","zhou","wu","zheng","wang","zhang","chen", "liu","lin",
"feng","wei","jiang","shen","han","yang","zhu","qin","you","xu","he","lu","shi","shangguan","sima","situ" });
string *name_words = ({ "顺","昌","振","发","财","俊","良","志","忠", "孝","雄","益","添","金",
"辉","长","盛","胜","进","安","福","同","满", "富","万","龙","隆","祥","栋","国","亿","寿","杨",
"藤","殷","罗","华","安","常", "岩","云","鹏","一","鸣","子","生","百","童","过","伟","学","友",
"晨","海","东","剑","峰","米","克","风", });
string *name_words_id = ({ "shun","chang","zhen","fa","cai","jun","liang","zhi","zhong", "xiao","xiong","yi","tian","jin",
"hui","chang","sheng","sheng","jin","an","fu","tong","man", "fu","wan","long","long","xiang","dong","guo","yi","shou","yang",
"teng","yin","luo","hua","an","chang","yan","yun","peng","yi","ming","zi","sheng","bai","tong","guo","wei","xue","you","chen",
"hai","dong","jian","feng","mi","ke","feng" });

void create()
{

       int i, j, k;
       string name , name_word,weapon = "null" , menpai;
       i = random(sizeof(first_name));
       name = first_name[i];

       j = random(sizeof(name_words));
       name += name_words[j];
       name_word = name_words_id[j];

       if( random(10) > 5 ){
               k = random(sizeof(name_words));
               name += name_words[k];
               name_word = name_word + name_words_id[k];
       }

        set_name(name, ({ first_name_id[i]+" "+name_word, first_name_id[i], name_word,"pan tu" }) );

        set("gender", random(2)?"男性":"女性");
        set("age", 20 + random(30));
        set("long", "星宿派叛徒。\n");
        set("title", HIB+"星宿派叛徒"+NOR);

        set("combat_exp", 800000);
        set("meitude", "peaceful");
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 20000);
        set("max_neili", 5000);
        set("neili", 5000);
        set_temp("apply/armor", 50);
        set("eff_jing", 20000);
        set("eff_jingli", 20000);
        set("jingli", 20000);
        set("max_jingli", 20000);
        set("no_quest",1);
        set("no_ansuan",1);
        set_skill("strike", 500);
        set_skill("cuff", 500);
        set_skill("hand", 500);
        set_skill("dodge", 500);
        set_skill("medicine", 500);
        set_skill("sword", 500);
        set_skill("force", 500);
        set_skill("parry", 500);
        set_skill("blade", 500);
        set_skill("hammer", 500);
        set_skill("literate", 200);
        set_skill("stick", 500);
        set_skill("club", 500);
        set_skill("hook", 500);
        set_skill("claw", 500);
        set_skill("axe", 500);
        set_skill("brush", 500);
        set_skill("staff", 500);
        set_skill("whip", 500);

        switch( random(24) ) {
                case 0:  // wd1
                        set_skill("yinyun-ziqi", 500);
                        set_skill("tiyunzong", 500);
                        set_skill("taoism", 500);
                        set_skill("taiji-jian", 500);
                        set_skill("taiji-quan", 500);

                        map_skill("force", "yinyun-ziqi");
                        map_skill("dodge", "tiyunzong");
                        map_skill("sword", "taiji-jian");
                        map_skill("parry", "taiji-jian");
                        map_skill("cuff", "taiji-quan");
                        prepare_skill("cuff", "taiji-quan");
                        set("chat_chance_combat", 20);
                        set("chat_msg_combat", ({
                                (: exert_function, "taiji" :),
                                (: exert_function, "yinyun" :),
                                (: perform_action, "cuff.zhen" :),
                                (: perform_action, "cuff.ji" :),
                                (: perform_action, "cuff.dongjing" :),
                                (: perform_action, "cuff.luanhuan" :),
                                (: perform_action, "cuff.yinyang" :),
                                (: perform_action, "cuff.zhannian" :),
                                (: perform_action, "sword.raozhi" :),
                                (: perform_action, "sword.lian" :),
                                (: perform_action, "sword.chan" :),
                                (: perform_action, "sword.sanhuan" :),
                        }));
                        weapon = "sword";
                        menpai = "武当";
                        break;
                case 1:  // wd2
                        set_skill("yinyun-ziqi", 500);
                        set_skill("tiyunzong", 500);
                        set_skill("taoism", 500);
                        set_skill("xuanxu-daofa", 500);
                        set_skill("taiji-quan", 500);

                        map_skill("force", "yinyun-ziqi");
                        map_skill("dodge", "tiyunzong");
                        map_skill("blade", "xuanxu-daofa");
                        map_skill("parry", "taiji-quan");
                        map_skill("cuff", "taiji-quan");
                        prepare_skill("cuff", "taiji-quan");
                        set("chat_chance_combat", 15);
                        set("chat_msg_combat", ({
                                (: exert_function, "taiji" :),
                                (: exert_function, "yinyun" :),
                                (: perform_action, "cuff.zhen" :),
                                (: perform_action, "cuff.ji" :),
                                (: perform_action, "cuff.dongjing" :),
                                (: perform_action, "cuff.luanhuan" :),
                                (: perform_action, "cuff.yinyang" :),
                                (: perform_action, "cuff.zhannian" :),
                        }));
                        menpai = "武当";
                        break;
                case 2:  // sl1
                        set_skill("yijin-jing", 500);
                        set_skill("shaolin-shenfa", 500);
                        set_skill("riyue-bian", 500);
                        set_skill("longzhua-gong", 500);
                        set_skill("yizhi-chan", 500);
                        set_skill("buddhism", 500);

                        map_skill("force", "yijin-jing");
                        map_skill("dodge", "shaolin-shenfa");
                        map_skill("whip", "riyue-bian");
                        map_skill("parry", "riyue-bian");
                        map_skill("finger", "yizhi-chan");
                        map_skill("claw", "longzhua-gong");
                        prepare_skill("finger", "yizhi-chan");
                        prepare_skill("claw", "longzhua-gong");
                        set("chat_chance_combat", 18);
                        set("chat_msg_combat", ({
                                (: exert_function, "jingang" :),
                                (: perform_action, "whip.chanrao" :),
                                (: perform_action, "whip.fumoquan" :),
                                (: perform_action, "whip.riyue" :),
                                (: perform_action, "claw.ranyun" :),
                                (: perform_action, "finger.qiankun" :),
                                (: perform_action, "finger.wofo" :),
                        }));
                        weapon = "whip";
                        menpai = "少林";
                        break;
                case 3:  // sl2
                        set_skill("yijin-jing", 500);
                        set_skill("shaolin-shenfa", 500);
                        set_skill("ruying-suixingtui", 500);
                        set_skill("qianye-shou", 500);
                        set_skill("weituo-chu", 500);
                        set_skill("buddhism", 500);

                        map_skill("force", "yijin-jing");
                        map_skill("dodge", "shaolin-shenfa");
                        map_skill("leg", "ruying-suixingtui");
                        map_skill("parry", "weituo-chu");
                        map_skill("hand", "qianye-shou");
                        map_skill("club", "weituo-chu");

                        prepare_skill("leg", "ruying-suixingtui");
                        prepare_skill("hand", "qianye-shou");

                        set("chat_chance_combat", 25);
                        set("chat_msg_combat", ({
                                (: exert_function, "jingang" :),
                                (: perform_action, "leg.ruying" :),
                                (: perform_action, "hand.qianshou" :),
                                (: perform_action, "club.chaodu" :),
                                (: perform_action, "club.leidong" :),
                        }));
                        weapon = "club";
                        menpai = "少林";
                        break;
                case 4:  // sl3
                        set_skill("yijin-jing", 500);
                        set_skill("buddhism", 500);
                        set_skill("shaolin-shenfa", 500);
                        set_skill("banruo-zhang", 500);
                        set_skill("jingang-quan", 500);
                        set_skill("ranmu-daofa", 500);
                        set_skill("buddhism", 500);

                        map_skill("force", "yijin-jing");
                        map_skill("dodge", "shaolin-shenfa");
                        map_skill("parry", "ranmu-daofa");
                        map_skill("blade", "ranmu-daofa");
                        map_skill("cuff", "jingang-quan");
                        map_skill("strike", "banruo-zhang");

                        prepare_skill("cuff", "jingang-quan");
                        prepare_skill("strike", "banruo-zhang");
                        set("chat_chance_combat", 22);
                        set("chat_msg_combat", ({
                                (: exert_function, "jingang" :),
                                (: perform_action, "cuff.fumo" :),
                                (: perform_action, "cuff.qixing" :),
                                (: perform_action, "strike.qiankun" :),

                        }));

                        menpai = "少林";
                        break;
                case 5:  // hs1
                        set_skill("zixia-gong", 500);
                        set_skill("huashan-shenfa", 500);
                        set_skill("huashan-jianfa", 500);
                        set_skill("hunyuan-zhang", 500);
                        set_skill("zhengqi-jue", 500);

                        map_skill("force", "zixia-gong");
                        map_skill("dodge", "huashan-shenfa");
                        map_skill("sword", "huashan-jianfa");
                        map_skill("parry", "huashan-jianfa");
                        map_skill("strike", "hunyuan-zhang");
                        prepare_skill("strike", "hunyuan-zhang");
                        set("chat_chance_combat", 17);
                        set("chat_msg_combat", ({
                                (: exert_function, "zixia" :),
                                (: perform_action, "sword.jianzhang" :),
                                (: perform_action, "sword.jianmang" :),
                                (: perform_action, "sword.lianhuan" :),
                                (: perform_action, "sword.wudui" :),
                                (: perform_action, "strike.wuji" :),
                        }));
                        weapon = "sword";
                        menpai = "华山";
                        break;
                case 6:  // hs2
                        set_skill("zixia-gong", 500);
                        set_skill("huashan-shenfa", 500);
                        set_skill("fanliangyi-dao", 500);
                        set_skill("poyu-quan", 500);
                        set_skill("zhengqi-jue", 500);

                        map_skill("force", "zixia-gong");
                        map_skill("dodge", "huashan-shenfa");
                        map_skill("blade", "fanliangyi-dao");
                        map_skill("parry", "fanliangyi-dao");
                        map_skill("cuff", "poyu-quan");

                        prepare_skill("cuff", "poyu-quan");
                        set("chat_chance_combat", 17);
                        set("chat_msg_combat", ({
                                (: exert_function, "zixia" :),
                                (: perform_action, "blade.sanshenfeng" :),
                                (: perform_action, "cuff.leidong" :),
                        }));
                        weapon = "blade";
                        menpai = "华山";
                        break;
                case 7:  // gb1
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
                        set("chat_chance_combat", 15);
                        set("chat_msg_combat", ({
                                (: exert_function, "huntian" :),
                                (: perform_action, "stick.chuo" :),
                                (: perform_action, "stick.chan" :),
                        }));
                        set("dgb/wugou",6);
                        weapon = "stick";
                        menpai = "丐帮";
                        break;
                case 8:  // gb2
                        set_skill("huntian-qigong", 500);
                        set_skill("xiaoyaoyou", 500);
                        set_skill("xianglong-zhang", 500);

                        map_skill("force", "huntian-qigong");
                        map_skill("dodge", "xiaoyaoyou");
                        map_skill("stick", "dagou-bang");
                        map_skill("parry", "xianglong-zhang");
                        map_skill("strike", "xianglong-zhang");

                        prepare_skill("strike", "xianglong-zhang");
                        set("chat_chance_combat", 15);
                        set("chat_msg_combat", ({
                                (: exert_function, "huntian" :),
                                (: perform_action, "strike.kanglong" :),
                                (: perform_action, "strike.paiyun" :),
                                (: perform_action, "strike.xiao" :),
                        }));
                        set("xlz/hang",1);
                        menpai = "丐帮";
                        break;
                case 9:  // thd1
                        set_skill("bihai-chaosheng", 500);
                        set_skill("qimen-bagua", 500);
                        set_skill("suibo-zhuliu", 500);
                        set_skill("yuxiao-jian", 500);
                        set_skill("tanzhi-shentong", 500);
                        set_skill("lanhua-shou", 500);
                        set_skill("luoying-zhang", 500);
                        set_skill("throwing", 500);
                        set_skill("xuanfeng-tui", 500);

                        map_skill("force", "bihai-chaosheng");
                        map_skill("dodge", "suibo-zhuliu");
                        map_skill("sword", "yuxiao-jian");
                        map_skill("parry", "yuxiao-jian");
                        map_skill("finger", "tanzhi-shentong");

                        prepare_skill("finger", "tanzhi-shentong");
                        set("chat_chance_combat", 14);
                        set("chat_msg_combat", ({
                                (: exert_function, "maze" :),
                                (: perform_action, "sword.yuxiao" :),
                                (: perform_action, "sword.feiying" :),
                                (: perform_action, "sword.qimen" :),
                        }));
                        set("thd/perform",999);
                        weapon = "xiao";
                        menpai = "桃花岛";
                        break;
                case 10: // thd2
                        set_skill("bihai-chaosheng", 500);
                        set_skill("qimen-bagua", 500);
                        set_skill("suibo-zhuliu", 500);
                        set_skill("yuxiao-jian", 500);
                        set_skill("tanzhi-shentong", 500);
                        set_skill("throwing", 500);

                        map_skill("force", "bihai-chaosheng");
                        map_skill("dodge", "suibo-zhuliu");
                        map_skill("sword", "yuxiao-jian");
                        map_skill("parry", "tanzhi-shentong");
                        map_skill("finger", "tanzhi-shentong");
                        prepare_skill("finger", "tanzhi-shentong");
                        set("chat_chance_combat", 20);
                        set("chat_msg_combat", ({
                                (: exert_function, "maze" :),
                                (: perform_action, "finger.huayu" :),
                                (: perform_action, "finger.lingxi" :),
                                (: perform_action, "finger.shentong" :),
                        }));
                        set("thd/perform",999);
                        menpai = "桃花岛";
                        break;
                case 11: // mr1
                        set_skill("shenyuan-gong", 500);
                        set_skill("douzhuan-xingyi", 500);
                        set_skill("yanling-shenfa", 500);
                        set_skill("murong-jianfa", 500);
                        set_skill("canhe-zhi", 500);

                        map_skill("force", "shenyuan-gong");
                        map_skill("dodge", "yanling-shenfa");
                        map_skill("sword", "murong-jianfa");
                        map_skill("parry", "douzhuan-xingyi");
                        map_skill("finger", "canhe-zhi");

                        prepare_skill("finger", "canhe-zhi");
                        set("chat_chance_combat", 16);
                        set("chat_msg_combat", ({
                                (: exert_function, "shenyuan" :),
                                (: perform_action, "parry.bishen" :),
                                (: perform_action, "parry.xingyi" :),
                        }));
                        weapon = "sword";
                        menpai = "姑苏慕容";
                        break;
                case 12: // gumu1
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
                        set("chat_chance_combat", 40);
                        set("chat_msg_combat", ({
                                (: exert_function, "xinjing" :),
                                (: perform_action, "sword.haichao" :),
                                (: perform_action, "sword.wujian" :),
                        }));
                        weapon = "sword";
                        menpai = "古墓";
                        break;
                case 13: // emei1
                        set_skill("linji-zhuang", 500);
                        set_skill("anying-fuxiang", 500);
                        set_skill("huifeng-jian", 500);
                        set_skill("sixiang-zhang", 500);
                        set_skill("jieshou-jiushi", 500);


                        map_skill("force", "linji-zhuang");
                        map_skill("dodge", "anying-fuxiang");
                        map_skill("sword", "huifeng-jian");
                        map_skill("parry", "huifeng-jian");
                        map_skill("strike", "sixiang-zhang");
                        map_skill("hand", "jieshou-jiushi");

                        prepare_skill("hand", "jieshou-jiushi");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                        	(: exert_function, "wuwo" :),
                                (: perform_action, "sword.mie" :),
                                (: perform_action, "sword.jue" :),
                                (: perform_action, "sword.liaoyuan" :),
                        }));
                        weapon = "sword";
                        menpai = "峨嵋";
                        break;
                case 14: // emei2
                        set_skill("linji-zhuang", 500);
                        set_skill("anying-fuxiang", 500);
                        set_skill("yanxing-daofa", 500);
                        set_skill("sixiang-zhang", 500);
                        set_skill("jieshou-jiushi", 500);


                        map_skill("force", "linji-zhuang");
                        map_skill("dodge", "anying-fuxiang");
                        map_skill("blade", "yanxing-daofa");
                        map_skill("parry", "yanxing-daofa");
                        map_skill("strike", "sixiang-zhang");
                        map_skill("hand", "jieshou-jiushi");

                        prepare_skill("strike", "sixiang-zhang");
                        set("chat_chance_combat", 25);
                        set("chat_msg_combat", ({
                                (: exert_function, "wuwo" :),
                                (: perform_action, "blade.huanying" :),
                                (: perform_action, "blade.feiyan" :),
                                (: perform_action, "hand.foguang" :),
                        }));
                        weapon = "blade";
                        menpai = "峨嵋";
                        break;
                case 15: // mj1
                        set_skill("shenghuo-shengong", 500);
                        set_skill("qiankun-danuoyi", 500);
                        set_skill("piaoyi-shenfa", 500);
                        set_skill("shenghuo-lingfa", 500);
                        set_skill("hanbing-mianzhang", 500);

                        map_skill("force", "shenghuo-shengong");
                        map_skill("dodge", "piaoyi-shenfa");
                        map_skill("blade", "shenghuo-lingfa");
                        map_skill("parry", "qiankun-danuoyi");
                        map_skill("cuff", "shenghuo-lingfa");
                        map_skill("strike", "hanbing-mianzhang");

                        prepare_skill("cuff", "shenghuo-lingfa");
                        set("chat_chance_combat", 20);
                        set("chat_msg_combat", ({
                                (: exert_function, "yinfeng" :),
                                (: exert_function, "tougu" :),
                                (: perform_action, "blade.duo" :),
                                (: perform_action, "blade.ji" :),
                                (: perform_action, "blade.tisha" :),
                                (: perform_action, "blade.xinmo" :),
                        }));
                        weapon = "tieling";
                        menpai = "明教";
                        break;
                case 16: // mj2
                        set_skill("shenghuo-shengong", 500);
                        set_skill("qiankun-danuoyi", 500);
                        set_skill("piaoyi-shenfa", 500);
                        set_skill("shenghuo-lingfa", 500);
                        set_skill("qishang-quan", 500);

                        map_skill("force", "shenghuo-shengong");
                        map_skill("dodge", "piaoyi-shenfa");
                        map_skill("blade", "shenghuo-lingfa");
                        map_skill("parry", "hanbing-mianzhang");
                        map_skill("cuff", "qishang-quan");

                        prepare_skill("cuff", "qishang-quan");
                        set("chat_chance_combat", 12);
                        set("chat_msg_combat", ({
                                (: exert_function, "yinfeng" :),
                                (: perform_action, "cuff.qishang" :),
                        }));
                        menpai = "明教";
                case 17: // dali1
                        set_skill("qiantian-yiyang", 500);
                        set_skill("tianlong-xiang", 500);
                        set_skill("duanjia-jianfa", 500);
                        set_skill("qingyan-zhang", 500);

                        map_skill("force", "qiantian-yiyang");
                        map_skill("dodge", "tianlong-xiang");
                        map_skill("sword", "duanjia-jianfa");
                        map_skill("parry", "qingyan-zhang");
                        map_skill("strike", "qingyan-zhang");

                        prepare_skill("strike", "qingyan-zhang");
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: perform_action, "sword.fenglei" :),
                        }));
                        weapon = "sword";
                        menpai = "天南大理";
                        break;
                case 18: // tls
                        set_skill("kurong-changong", 500);
                        set_skill("tianlong-xiang", 500);
                        set_skill("liumai-shenjian", 500);
                        set_skill("yiyang-zhi", 500);

                        map_skill("force", "kurong-changong");
                        map_skill("dodge", "tianlong-xiang");
                        map_skill("parry", "yiyang-zhi");
                        map_skill("finger", "yiyang-zhi");
                        prepare_skill("finger", "yiyang-zhi");
                        set("chat_chance_combat", 26);
                        set("chat_msg_combat", ({
                                (: perform_action, "finger.ciqu" :),
                                (: perform_action, "finger.liumai" :),
                                (: perform_action, "finger.sandie" :),
                                (: perform_action, "finger.yizhisanmai" :),
                        }));
                        menpai = "大理天龙寺";
                        break;
                case 19: // tz1
                        set_skill("tiezhang-xinfa", 500);
                        set_skill("guiyuan-tunafa", 500);
                        set_skill("lietian-fu", 500);
                        set_skill("shuishangpiao", 500);
                        set_skill("tiezhang-zhangfa", 500);
                        set_skill("yingou-bifa", 500);

                        map_skill("force", "guiyuan-tunafa");
                        map_skill("dodge", "shuishangpiao");
                        map_skill("parry", "tiezhang-zhangfa");
                        map_skill("strike", "tiezhang-zhangfa");

                        prepare_skill("strike", "tiezhang-zhangfa");
                        set("chat_chance_combat", 26);
                        set("chat_msg_combat", ({
                                (: perform_action, "strike.tianlei" :),
                                (: perform_action, "strike.zhangdao" :),
                        }));
                        menpai = "铁掌帮";
                        break;
               case 20: // sld1
                        set_skill("poison", 500);
                        set_skill("throwing", 500);
                        set_skill("dulong-dafa", 500);
                        set_skill("hansha-sheying", 500);
                        set_skill("huagu-mianzhang", 500);
                        set_skill("lingshe-bianfa", 500);
                        set_skill("shenlong-yaoli", 500);
                        set_skill("youlong-shenfa", 500);

                        map_skill("force", "dulong-dafa");
                        map_skill("dodge", "youlong-shenfa");
                        map_skill("parry", "huagu-mianzhang");
                        map_skill("strike", "huagu-mianzhang");
                        map_skill("whip", "lingshe-bianfa");
                        map_skill("throwing", "hansha-sheying");

                        prepare_skill("strike", "huagu-mianzhang");
                        set("chat_chance_combat", 26);
                        set("chat_msg_combat", ({
                        	(: exert_function, "wudi" :),
                                (: perform_action, "strike.bujue" :),
                                (: perform_action, "dodge.baibian" :),

                        }));
                        menpai = "神龙岛";
                        break;
               case 21: // sld2
                        set_skill("poison", 500);
                        set_skill("throwing", 500);
                        set_skill("dulong-dafa", 500);
                        set_skill("hansha-sheying", 500);
                        set_skill("huagu-mianzhang", 500);
                        set_skill("lingshe-bianfa", 500);
                        set_skill("shenlong-yaoli", 500);
                        set_skill("youlong-shenfa", 500);

                        map_skill("force", "dulong-dafa");
                        map_skill("dodge", "youlong-shenfa");
                        map_skill("parry", "huagu-mianzhang");
                        map_skill("strike", "huagu-mianzhang");
                        map_skill("whip", "lingshe-bianfa");
                        map_skill("throwing", "hansha-sheying");

                        prepare_skill("strike", "huagu-mianzhang");
                        set("chat_chance_combat", 26);
                        set("chat_msg_combat", ({
                        	(: exert_function, "wudi" :),
                                (: perform_action, "strike.bujue" :),
                                (: perform_action, "dodge.baibian" :),
                                (: perform_action, "whip.chan" :),
                                (: perform_action, "whip.sandou" :),

                        }));
                        weapon = "whip";
                        menpai = "神龙岛";
                        break;
               case 22: // xs1
                        set_skill("huanxi-chan", 500);
                        set_skill("huoyan-dao", 500);
                        set_skill("longxiang-boruo", 500);
                        set_skill("wushang-dali", 500);
                        set_skill("yuxue-dunxing", 500);

                        map_skill("force", "longxiang-boruo");
                        map_skill("dodge", "yuxue-dunxing");
                        map_skill("parry", "huoyan-dao");
                        map_skill("strike", "huoyan-dao");
                        map_skill("staff", "wushang-dali");

                        prepare_skill("strike", "huoyan-dao");
                        set("chat_chance_combat", 26);
                        set("chat_msg_combat", ({
                        	(: exert_function, "longxiang" :),
                                (: perform_action, "strike.daoqi" :),
                                (: perform_action, "strike.fen" :),
                         }));
                        weapon = "staff";
                        menpai = "雪山大轮寺";
                        break;
               case 23: // xs2
                        set_skill("huanxi-chan", 500);
                        set_skill("tianwang-zhua", 500);
                        set_skill("longxiang-boruo", 500);
                        set_skill("xuedao-jing", 500);
                        set_skill("yuxue-dunxing", 500);

                        map_skill("force", "longxiang-boruo");
                        map_skill("dodge", "yuxue-dunxing");
                        map_skill("parry", "xuedao-jing");
                        map_skill("blade", "xuedao-jing");
                        map_skill("claw", "tianwang-zhua");

                        prepare_skill("claw", "tianwang-zhua");
                        set("chat_chance_combat", 26);
                        set("chat_msg_combat", ({
                        	(: exert_function, "longxiang" :),
                                (: perform_action, "blade.shendao" :),
                                (: perform_action, "blade.jixue" :),
                         }));
                        weapon = "blade";
                        menpai = "雪山血刀门";
                        break;
               case 23: // xs3
                        set_skill("huanxi-chan", 500);
                        set_skill("dashou-yin", 500);
                        set_skill("longxiang-boruo", 500);
                        set_skill("xiangfu-lun", 500);
                        set_skill("yuxue-dunxing", 500);
                        set_skill("poison", 500);

                        map_skill("force", "longxiang-boruo");
                        map_skill("dodge", "yuxue-dunxing");
                        map_skill("parry", "xiangfu-lun");
                        map_skill("hammer", "xiangfu-lun");
                        map_skill("hand", "dashou-yin");

                        prepare_skill("hand", "dashou-yin");
                        set("chat_chance_combat", 26);
                        set("chat_msg_combat", ({
                        	(: exert_function, "longxiang" :),
                                (: perform_action, "hammer.wushuai" :),
                                (: perform_action, "hand.tianyin" :),
                         }));
                        weapon = "leaden-falun";
                        menpai = "雪山派";
                        break;
                default: // others      BUG!!!
                        set("long","武功设置错误，BUG！！！");
        }
        set("long" , query("long") + sprintf("据说现在已经是%s的弟子了，学过一些武功。\n",menpai) );

        set("weapon" , weapon);
                set("inquiry", ([
                "xingxiu":        (: ask_target :),
                "星宿派":         (: ask_target :),
                "老仙"  :         (: ask_target :),
                "彩集"  :         (: ask_target :),
                "caiji" :         (: ask_target :),
       ]));

        set_temp("no_return",1);
        setup();
        if( weapon!="null" ) carry_object(BINGQI_D(weapon))->wield();
        carry_object(ARMOR_D("cloth"))->wear();
        add_money("silver", random(99));

        call_out("check_position", 10, 200);
        call_out("dest", 2000);
}

int do_copy(object target,int mode)
{
        mapping skills;
        string *sk;
        object me,ob;
        int lv,exp,i,t;

        me = this_object();
        ob = target;
        me->set("xx_target", target);
        me->set("xx_partner",target->query("xx/partner"));
        if(mode) {
                t = 10+random(4);
                set("long",query("long")+"据说他曾经得到了其他门派高人的真传！\n");
                add_money("gold", random(2));
        }
        else
                t = 10;

        lv = ob->query("max_pot")- 100;
        lv = lv * t/10;
        exp = ob->query("combat_exp") *t/10;
        exp = exp * (100+random(10))/100;

        me->set("max_qi", (int)ob->query("max_qi")*10/10*t/10 );
        me->set("eff_qi", (int)ob->query("max_qi")*10/10*t/10 );
        me->set("qi", (int)ob->query("max_qi")*10/10*t/10 );
        me->set("max_jing",(int)ob->query("max_jing"));
        me->set("eff_jing",(int)ob->query("max_jing"));
        me->set("jing",(int)ob->query("max_jing"));
        me->set("max_neili",(int)ob->query("max_neili") );
        me->set("neili",(int)ob->query("neili")*t/10 );
        if( me->query("neili") < me->query("max_neili") )
                me->set("neili",(int)me->query("max_neili") );
        me->set("max_jingli",(int)ob->query("max_jingli"));
        me->set("eff_jingli",(int)ob->query("eff_jingli"));
        me->set("jingli",(int)ob->query("jingli"));
        if( me->query("jingli") < me->query("eff_jingli") )
                me->set("jingli",(int)me->query("eff_jingli") );
        me->set("combat_exp",exp );

        skills = me->query_skills();
        if (mapp(skills)) {
                sk = keys(skills);
                for (i=0;i<sizeof(sk);i++)
                        skills[sk[i]] = lv;
        }
        me->set("jiali",(int)me->query_skill("force")/10);
}


void kill_ob(object ob)
{
        object me = this_object();

        command("!!!");
            if( ob->query("xx/pantu_obj") != me &&
            me->query("xx_partner") != ob) {
                command("say 我跟你无冤无仇，你干吗这么拼命！");
        this_player()->remove_killer(me);
        return;
        }
        else
                command("say 让你知道我的厉害！");

        ::kill_ob(ob);

        if( query("addqi")==0 && ob->query_temp("apply/damage")>100 ) {
                int qi;
                qi = query("max_qi") * 3/2;
                if(qi<3000) qi = qi*3/2;
                set("max_qi" , qi);
                set("eff_qi" , qi);
                set("qi" , qi);
                set("addqi" , 1);
        }

        call_out("checkfight",2);
}

int accept_fight(object ob)
{
        object me = this_object();

        if( ob->query("xx/pantu_obj")!=me && me->query("xx_partner")!=ob) {
                command("kick");
                command("say 你太差劲，别自取其辱了。");
                return 0;
        }
        else {
       if( (me->query("eff_qi")<(me->query("max_qi")*2/3)) || (me->query("neili")<me->query("max_neili")/2))
                        return 0;
                call_out("checkfight",2);

                if( query("addqi")==0 && ob->query_temp("apply/damage")>100 ) {
                        int qi;
                        qi = query("max_qi") *3/2;
                        if(qi<3000) qi = qi*3/2;
                        set("max_qi" , qi);
                        set("eff_qi" , qi);
                        set("qi" , qi);
                        set("addqi" , 1);
                }

                return 1;
        }
}

void checkfight()
{
        object me = this_object() , w;
        string weapon;

        if( !objectp(me) || !living(me) || !me->is_fighting() )
                return;

        weapon = me->query("weapon");
        if( stringp(weapon) && weapon!="" && weapon!="null" && !me->query_temp("weapon") ) {
                command("emote 又拿出把兵器。");
                w = new(BINGQI_D(weapon));
                w->move(me);
                w->wield(me);
        }

        call_out("checkfight",4);
}
void check_position(int count)
{
        object me,ob,partner,where;
        me=this_object();
        if(!ob=me->query("xx_target")) return;
        partner=me->query("xx_partner");
        where=me->query("xx_place");

	if (objectp(me) && environment(me)!=where) {
                if (count-- > 0 && ob && partner && (ob->query("xx/pantu_obj")==me) &&
                ( environment(ob)!=where || environment(partner)!=where )) {
                	if(count%10==0)tell_object(partner,HIY+ob->name()+"现在在"+environment(ob)->query("short")+"等你一起去"+where->query("short")+"杀星宿派的叛徒。\n");
                        if(count==10)tell_object(partner,HIY+ob->name()+"最后一次警告你，再不来可就要PK了。\n");
//                        tell_object(ob,""+partner->name()+"现在在"+environment(partner)->query("short")+"。\n");
                        call_out("check_position", 5, count);
                        return;
                }else if(count <=0 || (ob->query("xx/pantu_obj")!=me))  dest();
                else display();
        }
}

void display()
{
        object me = this_object();

        if(!objectp(me->query("xx_place"))) return;  // means BUG!!!
        me->move(me->query("xx_place"));
        command("emote 慌张的走了过来。");
}

void dest()
{
	command("emote 慢慢离开了。");
        destruct(this_object());
}

string ask_target()
{
        if( this_object()->query("xx_target")==this_player())
                return "我就是讨厌丁春秋这个老贼！不过那个风仙彩集还不错！";
        else
                return "你是谁呀？我凭什么告诉你我的想法？";
}

void die()
{
	object me=this_object(),target=me->query("xx_target");
	if(objectp(target) && living(target))target->set("xx_job5_finished",1);
	 ::die();
}
	