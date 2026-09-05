// body guard 保镖
// by emnil@sj          2/9/2k

inherit NPC;
inherit F_SAVE;

#include <ansi.h>

int do_copy(object target,int mode);

string * name1 = ({ "马","何","东方","吴","王","张","李","薛","齐","任","黄","郭","欧阳","南宫"}); 
string * name2 = ({ "镖头","大虾","大侠","捕头","护院","保镖" }); 

void create()
{
        string weapon = "null" , menpai;
        string name = name1[random(sizeof(name1))] + name2[random(sizeof(name2))];

        set_name(name, ({ "body guard","guard" }));
        set("gender", "男性");
        set("age", 20 + random(40));
        set("long", "这是位威风凛凛的保镖，身体壮实，一看就是武功高手！\n");

        set("combat_exp", 800000);
        set("meitude", "peaceful");
        set("str", 32);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("shen",1000000);
        set("max_qi", 20000);
        set("max_jing", 20000);
        set("max_neili", 5000);
        set("neili", 5000);
        set_temp("apply/armor", 50);

        set_skill("strike", 500);
        set_skill("cuff", 500);
        set_skill("hand", 500);
        set_skill("dodge", 500);
        set_skill("sword", 500);
        set_skill("force", 500);
        set_skill("parry", 500);
        set_skill("blade", 500);
        set_skill("hammer", 500);
        set_skill("staff", 500);
        set_skill("club", 500);
        set_skill("staff", 500);
        set_skill("whip", 500);

        switch( random(19) ) {
                case 0:  // wd1
                        set_skill("taiji-shengong", 500);
                        set_skill("tiyunzong", 500);
                        set_skill("taiji-jian", 500);
                        set_skill("taiji-quan", 500);
                        map_skill("force", "taiji-shengong");
                        map_skill("dodge", "tiyunzong");
                        map_skill("sword", "taiji-jian");
                        map_skill("parry", "taiji-quan");
                        map_skill("cuff", "taiji-quan");
                        prepare_skill("cuff", "taiji-quan");         
                        set("chat_chance_combat", 30);
                        set("chat_msg_combat", ({
                                (: exert_function, "recover" :),
                                (: perform_action, "cuff.zhen" :), 
                                (: perform_action, "cuff.zhen" :), 
                        }));
                        menpai = "武当";
                        break;
                case 1:  // wd2
                        set_skill("taiji-shengong", 500);
                        set_skill("tiyunzong", 500);
                        set_skill("taiji-jian", 500);
                        set_skill("taiji-quan", 500);
                        map_skill("force", "taiji-shengong");
                        map_skill("dodge", "tiyunzong");
                        map_skill("sword", "taiji-jian");
                        map_skill("parry", "taiji-jian");
                        map_skill("cuff", "taiji-quan");
                        prepare_skill("cuff", "taiji-quan");         
                        set("chat_chance_combat", 20);
                        set("chat_msg_combat", ({
                                (: perform_action, "dodge.zong" :),
                                (: perform_action, "sword.chan" :), 
                                (: perform_action, "sword.chan" :), 
                                (: perform_action, "sword.chan" :), 
                        }));
                        weapon = "sword";
                        menpai = "武当";
                        break;
                case 2:  // sl1
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
                        set("chat_chance_combat", 15);
                        set("chat_msg_combat", ({
                                (: exert_function, "jingang" :),
                                (: perform_action, "whip.chan" :), 
                                (: perform_action, "whip.chan" :), 
                        }));
                        weapon = "whip";
                        menpai = "少林";
                        break;
                case 3:  // sl3
                        set_skill("yijin-jing", 500);
                        set_skill("shaolin-shenfa", 500);
                        set_skill("yizhi-chan", 500);
                        map_skill("force", "yijin-jing");
                        map_skill("dodge", "shaolin-shenfa");
                        map_skill("parry", "yizhi-chan");
                        map_skill("finger", "yizhi-chan");
                        prepare_skill("finger", "yizhi-chan");         
                        set("chat_chance_combat", 20);
                        set("chat_msg_combat", ({
                                (: exert_function, "jingang" :),
                                (: perform_action, "finger.jingmo" :), 
                                (: perform_action, "finger.jingmo" :), 
                        }));
                        menpai = "少林";
                        break;
                case 5:  // hs1
                        set_skill("zixia-shengong", 500);
                        set_skill("huashan-shenfa", 500);
                        set_skill("huashan-jianfa", 500);
                        set_skill("poyu-quan", 500);
                        map_skill("force", "zixia-shengong");
                        map_skill("dodge", "huashan-shenfa");
                        map_skill("sword", "huashan-jianfa");
                        map_skill("parry", "huashan-jianfa");
                        map_skill("cuff", "poyu-quan");
                        prepare_skill("cuff", "poyu-quan");         
                        set("chat_chance_combat", 15);
                        set("chat_msg_combat", ({
                                (: exert_function, "powerup" :),
                                (: perform_action, "sword.jianzhang" :), 
                                (: perform_action, "sword.jianzhang" :), 
                        }));
                        weapon = "sword";
                        menpai = "华山";
                        break;
                case 6:  // hs2
                        set_skill("zixia-gong", 500);
                        set_skill("huashan-shenfa", 500);
                        set_skill("fanliangyi-dao", 500);
                        set_skill("poyu-quan", 500);
                        map_skill("force", "zixia-gong");
                        map_skill("dodge", "huashan-shenfa");
                        map_skill("blade", "fanliangyi-dao");
                        map_skill("parry", "fanliangyi-dao");
                        map_skill("cuff", "poyu-quan");
                        prepare_skill("cuff", "poyu-quan");         
                        set("chat_chance_combat", 10);
                        set("chat_msg_combat", ({
                                (: exert_function, "powerup" :),
                                (: perform_action, "blade.sanshen" :), 
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
                        map_skill("staff", "dagou-bang");
                        map_skill("parry", "dagou-bang");
                        map_skill("strike", "xianglong-zhang");
                        prepare_skill("strike", "xianglong-zhang");         
                        set("chat_chance_combat", 20);
                        set("chat_msg_combat", ({
                                (: exert_function, "powerup" :),
                                (: perform_action, "staff.tiao" :), 
                                (: perform_action, "staff.zhuan" :), 
                                (: perform_action, "staff.chan" :), 
                        }));
                        weapon = "staff";
                        menpai = "丐帮";
                        break;
                case 9:  // thd1
                        set_skill("bihai-shengong", 500);
                        set_skill("yuxiao-jian", 500);
                        set_skill("luoying-shenfa",500);
                        set_skill("tanzhi-shengong", 500);
                        map_skill("force", "    bihai-shengong");
                        map_skill("dodge", "luoying-shenfa");
                        map_skill("sword", "yuxiao-jian");
                        map_skill("parry", "yuxiao-jian");
                        map_skill("finger", "tanzhi-shengong");
                        prepare_skill("finger", "tanzhi-shengong");         
                        set("chat_chance_combat", 20);
                        set("chat_msg_combat", ({
                                (: exert_function, "powerup" :),
                                (: perform_action, "sword.chan" :), 
                                (: perform_action, "sword.chan" :), 
                                (: perform_action, "sword.xiaohua" :), 
                        }));
                        set("thd/perform",999);
                        weapon = "sword";
                        menpai = "桃花岛";
                        break;
                case 11: // mr1
                        set_skill("shenyuan-gong", 500);
                        set_skill("douzhuan-xingyi", 500);
                        set_skill("yanling-shenfa", 500);
                        set_skill("murong-jianfa", 500);
                        set_skill("tanzhi-shengong", 500);
                        map_skill("force", "    shenyuan-gong");
                        map_skill("dodge", "yanling-shenfa");
                        map_skill("sword", "murong-jianfa");
                        map_skill("parry", "douzhuan-xingyi");
                        map_skill("finger", "canhe-zhi");
                        prepare_skill("finger", "canhe-zhi");         
                        set("chat_chance_combat", 20);
                        set("chat_msg_combat", ({
                                (: exert_function, "powerup" :),
                                (: perform_action, "parry.xingyi" :), 
                                (: perform_action, "parry.xingyi" :),                           
                        }));
                        weapon = "sword";
                        menpai = "姑苏慕容";
                        break;
                case 13: // emei1
                        set_skill("linji-zhuang", 500);
                        set_skill("zhutian", 500);
                        set_skill("fuliu-jian", 500);
                        set_skill("jinding-mianzhang", 500);
                        map_skill("force", "linji-zhuang");
                        map_skill("dodge", "zhutian");
                        map_skill("sword", "fuliu-jian");
                        map_skill("parry", "fuliu-jian");
                        map_skill("strike", "jinding-mianzhang");
                        prepare_skill("strike", "jinding-mianzhang");         
                        set("chat_chance_combat", 20);
                        set("chat_msg_combat", ({
                                (: exert_function, "powerup" :),
                                (: perform_action, "sword.mie" :), 
                                (: perform_action, "sword.fuliu" :), 
                        }));
                        weapon = "sword";
                        menpai = "娥眉";
                        break;
                case 15: // mj1
                        set_skill("shenghuo-lingfa", 500);
                        set_skill("qiankun-danuoyi", 500);
                        set_skill("datengnuo-bufa", 500);
                        set_skill("jiuyang-shengong", 500);
                        set_skill("hanbing-zhang", 500);
                        map_skill("force", "jiuyang-shengong");
                        map_skill("dodge", "datengnuo-bufa");
                        map_skill("sword", "shenghuo-lingfa");
                        map_skill("parry", "shenghuo-lingfa");       
                        set("chat_chance_combat", 20);
                        set("chat_msg_combat", ({
                                (: exert_function, "powerup" :),
                                (: perform_action, "sword.duo" :), 
                        }));
                        weapon = "tieling";
                        menpai = "明教";
                        break;
                default: // tls
                        set_skill("beiming-shengong", 500);
                        set_skill("lingbo-weibu", 500);
                        set_skill("liumai-shenjian", 500);
                        set_skill("yiyang-zhi", 500);
                        map_skill("force", "beiming-shengong");
                        map_skill("dodge", "lingbo-weibu");
                        map_skill("parry", "yiyang-zhi");
                        map_skill("finger", "liumai-shenjian");
                        prepare_skill("finger", "liumai-shenjian");         
                        set("chat_chance_combat", 20);
                        set("chat_msg_combat", ({
                                (: perform_action, "finger.qifa" :), 
                                (: perform_action, "finger.qifa2" :), 
                                (: perform_action, "finger.qifa2" :), 
                        }));
                        menpai = "大理天龙寺";
                        break;
        }
        set("long" , query("long") + sprintf("这位高手似乎来自%s。\n",menpai) );

        setup();
	if( weapon!="null" ) carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", random(10));

        this_object()->start_call_out( (: call_other, this_object(), "display", this_object() :), 60);
        this_object()->start_call_out( (: call_other, this_object(), "dest", this_object() :), 660);
}       

int do_copy(object target,int mode)
{
        mapping skills;
        string *sk;
        object me,ob; 
        int lv,exp,i,t;

        me = this_object();
        ob = target;
        if(mode) {
                t = 11+random(5); 
                set("long",query("long")+"最近治安不太好，这个保镖是特别从京城请来的，据说还曾经是大内高手呢！\n");
        }
        else 
                t = 10;

        lv = 0;
        if(lv < (int)ob->query_skill("dodge",1)) lv = (int)ob->query_skill("dodge",1);
        if(lv < (int)ob->query_skill("force",1)) lv = (int)ob->query_skill("force",1);
        if(lv < (int)ob->query_skill("parry",1)) lv = (int)ob->query_skill("parry",1);
        if(lv < (int)ob->query_skill("strike",1)) lv = (int)ob->query_skill("strike",1);
        if(lv < (int)ob->query_skill("cuff",1)) lv = (int)ob->query_skill("cuff",1);
        if(lv < (int)ob->query_skill("hammer",1)) lv = (int)ob->query_skill("hammer",1);
        if(lv < (int)ob->query_skill("whip",1)) lv = (int)ob->query_skill("whip",1);
        if(lv < (int)ob->query_skill("sword",1)) lv = (int)ob->query_skill("sword",1);
        if(lv < (int)ob->query_skill("blade",1)) lv = (int)ob->query_skill("blade",1);
        lv += 2 + random(3);
        lv = lv * t/10;
        exp = ob->query("combat_exp") *t/10;

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

        if( exp>200000 && exp<500000)
                me->set("combat_exp",exp+random(50000) );
        else if( exp>500000 && exp<1000000)
                me->set("combat_exp",exp+random(300000) );
        else if( exp>1000000 && exp <2000000)
                me->set("combat_exp",exp + random(400000) );
        else if( exp>2000000)
                me->set("combat_exp",exp + random(500000) );
        
        me->set("shen" , me->query("combat_exp")/20);

        skills = me->query_skills();
        if (mapp(skills)) {
                sk = keys(skills);
                for (i=0;i<sizeof(sk);i++)
                        skills[sk[i]] = lv;
        }      
        me->set("jiali",(int)me->query_skill("force")/6);       
}

void display()
{
        object me = this_object();

        if(!objectp(me->query("place"))) return;  // means BUG!!!       
        me->move(me->query("place"));
}

void dest()
{
        destruct(this_object());
}

void kill_ob(object ob)
{
        object me = this_object();

        command("!!!");
        if( ob->query("id") != me->query("target")) {
                command("say 快逃啊！");
                if( objectp(me->query("beauty")) )
                        (me->query("beauty"))->kill_ob(ob);
        }
        else 
                command("say 光天化日也敢抢劫！");

        ::kill_ob(ob);
}

int accept_fight(object ob)
{
        object me = this_object();

        if( ob->query("id") != me->query("target")) {
                command("haha");
                command("say 今日有公务在身，恕不奉陪");
                return 0;       
        }
        else
                return 1;                       
}

