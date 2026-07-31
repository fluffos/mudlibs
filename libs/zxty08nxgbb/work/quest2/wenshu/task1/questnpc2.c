//天涯杀手任务NPC数据库 writed by daniel

inherit NPC;
#include <ansi.h>
#include <room.h>    
int get_level(int exp);

mapping *menpai= ({
([      "title1":               "神龙教恶徒",
        "title2":               "神龙教尊使",
        "gender":               "男性",
        "dodge":                "yixingbu",
        "parry":                "shedao-qigong",
        "staff":                "shedao-qigong",
        "force":                "shenlong-xinfa",
        "unarmed":              "shenlong-bashi",
        "prepare1":             "unarmed",
        "exert1":               "powerup",
        "perform1":             "staff.chang",
        "perform2":             "staff.chang1",
        "perform3":             "staff.chang2",
        "perform4":             "staff.chang3",
        "weapon":                __DIR__"obj/shezhang",
]),                                
([      "title1":                "移花宫妖女",
        "title2":                "移花宫仙子",
        "gender":                "女性",
        "class":                 "sworder",
        "dodge":                 "yihua-jiemu",
        "sword":                 "yifeng-jian",
        "parry":                 "yifeng-jian",
        "force":                 "mingyu-shengong",
        "unarmed":               "jueqing-zhang",
        "prepare1":              "unarmed",
        "perform1":              "sword.yifeng",
        "perform2":              "unarmed.mihun",
        "weapon":                __DIR__"obj/changjian",
]),                                          
([      "title1":                "云龙门弃徒",
        "title2":                "云龙门侠士",
        "class":                 "sworder",
        "gender":                "男性",
        "dodge":                 "yunlong-shenfa",
        "parry":                 "houquan",
        "unarmed":               "houquan",
        "sword":                 "yunlong-jian",
        "force":                 "yunlong-shengong",
        "perform1":              "sword.xian",
        "perform2":              "parry.zhen",
        "exert1":                "powerup",
        "weapon":                __DIR__"obj/changjian",
]),
([      "title1":                "昆仑派弃徒",
        "title2":                "昆仑派大侠",
        "class":                 "sworder",
        "gender":                "男性",
        "dodge":                 "kunlun-shenfa",
        "parry":                 "liangyi-jian",
        "strike":                "kunlun-zhang",
        "sword":                 "liangyi-jian",
        "force":                 "xuantian-wuji",
        "prepare1":              "strike",
        "exert1":                "powerup",
        "perform1":              "sword.feixue",
        "perform2":              "sword.juedi",
        "perform3":              "strike.liuyun",
        "perform4":              "strike.yixing",
        "weapon":                __DIR__"obj/changjian",
]),
([      "title1":                "姑苏慕容弟子",
        "title2":                "姑苏慕容弟子",
        "gender":                "男性",
        "class":                 "sworder",
        "dodge":                 "yanling-shenfa",
        "sword":                 "murong-jianfa",
        "parry":                 "douzhuan-xingyi",
        "force":                 "shenyuan-gong",
        "finger":                "canhe-zhi",
        "prepare1":              "finger",
        "perform1":              "sword.qixing",
        "perform2":              "parry.xingyi",
        "perform3":              "finger.dian",
        "weapon":                __DIR__"obj/changjian",
]), 
([      "title1":                "姑苏慕容弟子",
        "title2":                "姑苏慕容弟子",
        "gender":                "男性",
        "class":                 "sworder",
        "dodge":                 "yanling-shenfa",
        "blade":                 "murong-daofa",
        "parry":                 "douzhuan-xingyi",
        "force":                 "shenyuan-gong",
        "finger":                "canhe-zhi",
        "prepare1":              "finger",
        "perform1":              "parry.xingyi",
        "perform2":              "finger.dian",
        "weapon":                __DIR__"obj/blade",
]),                       
([      "title1":                "姑苏慕容弟子",
        "title2":                "姑苏慕容弟子",
        "gender":                "男性",
        "class":                 "sworder",
        "dodge":                 "yanling-shenfa",
        "sword":                 "murong-jianfa",
        "blade":                 "murong-daofa",    
        "parry":                 "douzhuan-xingyi",
        "force":                 "shenyuan-gong",
        "finger":                "canhe-zhi",
        "prepare1":              "sword",
        "prepare2":              "blade",
        "perform1":              "sword.qixing",
        "perform2":              "parry.xingyi",
        "perform3":              "finger.dian",
        "weapon":                __DIR__"obj/changjian",
        "weapon_s":              __DIR__"obj/blade",
]),
([      "title1":                "少林恶僧",
        "title2":                "少林和尚",
        "gender":                "男性",
        "class":                 "bonze",
        "dodge":                 "shaolin-shenfa",
        "whip":                  "riyue-bian",
        "parry":                 "riyue-bian",
        "force":                 "hunyuan-yiqi",
        "finger":                "yizhi-chan",
        "prepare1":              "finger",
        "perform1":              "whip.chan",
        "perform2":              "finger.jingmo",
        "perform3":              "finger.dian",
        "exert1":                "jingang",
        "weapon":                __DIR__"obj/changbian",
]),
([      "title1":               "逍遥派恶徒",
        "title2":               "逍遥派弟子",
        "clasee":               "taoist",
        "gender":               "男性",
        "dodge":                "lingboweibu",
        "parry":                "zhemei-shou",
        "force":                "beiming-shengong",
        "hand":                 "zhemei-shou",
        "strike":               "liuyang-zhang",
        "blade":                "ruyi-dao",
        "prepare1":             "hand",
        "prepare2":             "strike",
        "exert1":               "shield",
        "perform1":             "blade.jiao",
        "perform2":             "dodge.lingbo",
        "perform3":             "blade.ruyi",
        "perform4":             "hand.duo",
        "weapon":                __DIR__"obj/blade",
]),
([      "title1":               "镇南王府弃仆",
        "title2":               "镇南王府侍将",
        "gender":               "男性",
        "dodge":                "tiannan-bufa",
        "force":                "kurong-changong",
        "finger":               "yiyang-zhi",
        "prepare1":             "finger",
        "exert1":               "powerup",
        "perform1":             "sword.ding",
        "perform2":             "sword.tun",
        "perform3":             "finger.yizhi",
        "weapon":                __DIR__"obj/changjian",
]),
([      "title1":               "天龙寺恶僧",
        "title2":               "天龙寺长老",
        "clasee":               "bonze",
        "gender":               "男性",
        "dodge":                "tiannan-bufa",
        "parry":                "liumai-shenjian",
        "force":                "kurong-changong",
        "finger":               "liumai-shenjian",
        "prepare1":             "finger",
        "exert1":               "powerup",
        "perform1":             "finger.feng",
        "perform2":             "fenger.tan",
        "perform3":             "finger.ci",
        "perform4":             "finger.liumai",
]),
([      "title1":               "日月神教阉贼",
        "title2":               "日月神教长老",
        "gender":               "无性",
        "dodge":                "kuihua-feiying",
        "parry":                "kuihua-dafa",
        "sword":                "pixie-jian",
        "force":                "kuihua-xinfa",
        "finger":               "pixie-jian",
        "unarmed":              "changquan",
        "prepare1":             "finger",
        "exert1":               "sneaky",
        "perform1":             "finger.cimu",
        "perform2":             "parry.tonggui",
        "perform3":             "dodge.feiying", 
        "weapon":                __DIR__"obj/xiuhua-zhen",
]),
([      "title1":               "明教恶徒",
        "title2":               "光明圣使",
        "gender":               "男性",
        "dodge":                "qiankundanuoyi",
        "parry":                "qiankundanuoyi",
        "sword":                "shenghuo-ling",
        "force":                "jiuyang-force",
        "unarmed":              "jiuyang-force",
        "cuff":                 "qishang-quan",
        "prepare1":             "unarmed",
        "exert1":               "powerup",
        "perform1":             "sword.xiyanling",
        "perform2":             "cuff.sanjiao", 
        "perform3":             "cuff.hunpofeiyang",
        "perform4":             "cuff.yihuanghu",  
        "weapon":                __DIR__"obj/shenghuoling",
]),                           
([      "title1":               "古墓妖女",
        "title2":               "古墓女侠",
        "gender":               "女性",
        "dodge":                "yunu-shenfa",
        "parry":                "yunu-jianfa",
        "sword":                "yunu-jianfa",
        "force":                "yunu-xinjing",
        "unarmed":              "meinu-quanfa",
        "prepare1":             "unarmed",
        "exert1":               "powerup",
        "perform1":             "sword.hebi",
        "perform2":             "unarmed.duo",
        "weapon":                __DIR__"obj/changjian",
]),                          
([      "title1":               "古墓妖女",
        "title2":               "古墓女侠",
        "gender":               "女性",
        "dodge":                "yunu-shenfa",
        "parry":                "yinsuo-jinling",
        "whip":                 "yinsuo-jinling",
        "force":                "yunu-xinjing",
        "unarmed":              "meinu-quanfa",
        "prepare1":             "unarmed",
        "exert1":                "powerup",
        "perform1":             "whip.dian",
        "perform2":             "whip.feng",
        "perform3":             "unarmed.duo",
        "weapon":                __DIR__"obj/changbian",
]),
([      "title1":               "古墓妖女",
        "title2":               "古墓女侠",
        "gender":               "女性",
        "dodge":                "yunu-shenfa",
        "parry":                "yunu-jianfa",
        "sword":                "yunu-jianfa",
        "whip":                 "yinsuo-jinling",   
        "force":                "yunu-xinjing",
        "unarmed":              "meinu-quanfa",
        "prepare1":             "sword",
        "prepare2":             "whip",
        "exert1":               "powerup",
        "perform1":             "whip.dian",
        "perform2":             "whip.feng",   
        "perform3":             "unarmed.duo",
        "weapon":                __DIR__"obj/changbian",    
        "weapon_s":              __DIR__"obj/changjian",
]), 
([      "title1":               "星宿老魔",
        "title2":               "星宿门徒",
        "gender":               "男性",
        "dodge":                "zhaixinggong",
        "parry":                "tianshan-zhang",
        "staff":                "tianshan-zhang",
        "force":                "huagong-dafa",
        "poison":               "huagong-dafa",
        "strike":               "chousui-zhang",
        "cuff":                 "wugong-zhao",
        "prepare1":             "strike",
        "prepare1":             "cuff",
        "exert1":               "powerup",
        "perform1":             "strike.sandu",
        "perform2":             "poison.du",
        "perform3":             "poison.hua",
        "perform4":             "poison.judu",
]),
([      "title1":               "白驼淫贼",
        "title2":               "白驼山弟子",
        "gender":               "男性",
        "dodge":                "chanchu-bufa",
        "parry":                "lingshe-zhangfa",
        "staff":                "lingshe-zhangfa",
        "force":                "hamagong",
        "hand":                 "shexing-diaoshou",
        "prepare1":             "hand",
        "exert1":               "nizhuan",
        "perform1":             "staff.shoot",
        "perform2":             "staff.lingshe",  
        "perform3":             "force.hama",  
        "weapon":                __DIR__"obj/shezhang",
]),
([      "title1":                "峨嵋贼尼",
        "title2":                "峨嵋女尼",
        "gender":                "女性",
        "class":                 "bonze",
        "dodge":                 "zhutian",
        "strike":                "jinding-mianzhang",
        "parry":                 "fuliu-jian",
        "sword":                 "fuliu-jian",
        "force":                 "linji-zhuang",
        "finger":                "tiangang-zhi",
        "prepare1":              "finger",
        "prepare2":              "strike",
        "perform1":              "sword.mie",
        "perform2":              "finger.lingkong",   
        "exert1":                "youming",
        "exert2":                "fengyun",
        "weapon":                __DIR__"obj/changjian",
]),
([      "title1":                "峨嵋贼尼",
        "title2":                "峨嵋女尼",
        "gender":                "女性",
        "class":                 "bonze",
        "dodge":                 "zhutian",
        "parry":                 "yanxing-dao",
        "blade":                 "yanxing-dao",
        "force":                 "linji-zhuang",
        "finger":                "tiangang-zhi",
        "strike":                "jinding-mianzhang",
        "prepare1":              "finger",
        "prepare2":              "strike",
        "perform1":              "blade.huanying",
        "perform2":              "finger.lingkong",   
        "exert1":                "youming",
        "exert2":                "fengyun",
        "weapon":                __DIR__"obj/blade",
]),
([      "title1":                "灵鹫妖姬",
        "title2":                "灵鹫圣使",
        "gender":                "女性",
        "class":                 "fighter",
        "dodge":                 "yueying-wubu",
        "parry":                 "tianyu-qijian",
        "sword":                 "tianyu-qijian",
        "force":                 "bahuang-gong",
        "hand":                  "zhemei-shou",
        "unarmed":               "liuyang-zhang",
        "prepare1":              "hand",
        "prepare2":              "unarmed",
        "perform1":              "sword.san",
        "perform2":              "unarmed.zhong",
        "perform3":              "hand.duo",
        "exert1":                "powerup",
        "weapon":                __DIR__"obj/changjian",
]),
([      "title1":                "五毒魔女",
        "title2":                "五毒护法",
        "gender":                "女性",
        "class":                 "fighter",
        "dodge":                 "wudu-yanluobu",
        "parry":                 "wudu-goufa",
        "sword":                 "wudu-goufa",
        "force":                 "wudu-shengong",
        "unarmed":               "qianzhu-wandushou",
        "prepare1":              "unarmed",
        "perform1":              "sword.suo",
        "perform2":              "unarmed.qzwd",
        "perform3":              "dodge.snake",  
        "exert1":                "powerup",
        "weapon":                __DIR__"obj/changjian",
]),
([      "title1":                "丐帮恶丐",
        "title2":                "丐帮长老",
        "gender":                "男性",
        "class":                 "fighter",
        "dodge":                 "xiaoyaoyou",
        "parry":                 "dagou-bang",
        "staff":                 "dagou-bang",
        "force":                 "huntian-qigong",
        "strike":                "xianglong-zhang",
        "prepare1":              "strike",
        "perform1":              "staff.chan",
        "perform2":              "staff.duo",
        "perform3":              "strike.leiting",
        "perform4":              "strike.xianglong",
        "exert1":                "powerup",
        "exert2":                "shengang",
        "weapon":                __DIR__"obj/zhubang",
]),
([      "title1":                "丐帮恶丐",
        "title2":                "丐帮长老",
        "gender":                "男性",
        "class":                 "fighter",
        "dodge":                 "xiaoyaoyou",
        "parry":                 "dagou-bang",
        "staff":                 "dagou-bang",
        "force":                 "huntian-qigong",
        "strike":                "xianglong-zhang",
        "prepare1":              "strike",
        "perform1":              "strike.leiting",
        "perform2":              "strike.xianglong",
        "exert1":                "powerup",
        "exert2":                "shengang",
]),            
([      "title1":                "神秘杀手",
        "title2":                "神秘高手",
        "gender":                "男性",
        "class":                 "fighter",
        "dodge":                 "huashan-shenfa",
        "parry":                 "dugu-jiujian",
        "sword":                 "dugu-jiujian",
        "force":                 "zixia-shengong",
        "strike":                "hunyuan-zhang",
        "cuff":                  "poyu-quan",
        "prepare1":              "strike",
        "prepare2":              "cuff",
        "perform1":              "sword.po",
        "perform2":              "sword.poqi",
        "perform3":              "sword.pozhang",
        "perform4":              "strike.wuji",  
        "exert1":                "powerup",
        "weapon":                __DIR__"obj/changjian",
]),
([      "title1":                "华山派剑客",
        "title2":                "华山派弃徒",
        "gender":                "男性",
        "class":                 "fighter",
        "dodge":                 "huashan-shenfa",
        "parry":                 "huashan-jianfa",
        "sword":                 "huashan-jianfa",
        "force":                 "zixia-shengong",
        "strike":                "hunyuan-zhang",
        "cuff":                  "poyu-quan",
        "prepare1":              "strike",
        "prepare2":              "cuff",
        "perform1":              "sword.feilong",
        "perform2":              "sword.jianzhang",
        "perform3":              "cuff.leidong",
        "perform4":              "strike.wuji",
        "exert1":                "powerup",
        "weapon":                __DIR__"obj/changjian",
]),
([      "title1":                "华山派女侠",
        "title2":                "华山派弃徒",
        "gender":                "女性",
        "class":                 "fighter",
        "dodge":                 "huashan-shenfa",
        "parry":                 "yunu-sword",
        "sword":                 "yunu-sword",
        "force":                 "zixia-shengong",
        "strike":                "hunyuan-zhang",
        "cuff":                  "poyu-quan",
        "prepare1":              "strike",
        "prepare2":              "cuff",
        "perform1":              "sword.wushuang",
        "perform2":              "cuff.leidong",
        "perform3":              "strike.wuji",
        "exert1":                "powerup",
        "weapon":                __DIR__"obj/changjian",
]), 
([      "title1":                "少林恶僧",
        "title2":                "少林和尚",
        "gender":                "男性",
        "class":                 "bonze",
        "dodge":                 "shaolin-shenfa",
        "cuff":                  "jingang-quan",
        "parry":                 "zui-gun",
        "club":                  "zui-gun",
        "force":                 "hunyuan-yiqi",
        "finger":                "nianhua-zhi",
        "strike":                "sanhua-zhang",
        "prepare1":              "finger",
        "prepare2":              "strike",
        "perform1":              "club.zuida",
        "perform2":              "cuff.jin",
        "exert1":                "jingang",
        "weapon":                __DIR__"obj/qimeigun",
]),
([      "title1":               "古墓逆徒",
        "title2":               "古墓大侠",
        "gender":               "男性",
        "dodge":                "yunu-shenfa",
        "parry":                "xuantie-jianfa",
        "strike":               "anran-xiaohunzhang",
        "sword":                "xuantie-jianfa",
        "force":                "yunu-xinjing",
        "exert1":               "powerup",
        "prepare1":              "strike",
        "perform1":             "sword.fen",
        "perform2":             "strike.anranxiaohun",     
        "perform3":             "sword.dang",
        "perform4":             "sword.haichao", 
        "weapon":                __DIR__"obj/changjian",
]),
([      "title1":                "全真败类",
        "title2":                "全真道长",
        "class":                 "taoist",
        "gender":                "男性",
        "dodge":                 "qixing-huanwei",
        "parry":                 "quanzhen-jianfa",
        "unarmed":               "kongming-quan",
        "sword":                 "quanzhen-jianfa",
        "force":                 "tiangang-zhengqi",
        "finger":                "yiyang-zhi",
        "prepare1":              "finger",    
        "perform1":              "sword.sanqing",
        "perform2":              "sword.qixing",
        "perform3":              "sword.tonggui", 
        "perform4":              "finger.yizhi",   
        "weapon":                __DIR__"obj/changjian",
]),   
([      "title1":                "雪山寺贼秃",
        "title2":                "雪山寺喇嘛",
        "gender":                "男性",
        "dodge":                 "shenkong-xing",
        "parry":                 "mingwang-jian",
        "strike":                "huoyan-dao",
        "sword":                 "mingwang-jian",
        "force":                 "xiaowuxiang",
        "prepare1":              "strike",
        "perform1":              "sword.ming",
        "perform2":              "strike.fen",
        "exert1":                "shield",
        "weapon":                __DIR__"obj/changjian",
]), 
([      "title1":                "武当败类",
        "title2":                "武当道长",
        "class":                 "taoist",
        "dodge":                 "tiyunzong",
        "parry":                 "taiji-quan", 
        "unarmed":               "taiji-quan",
        "sword":                 "taiji-jian",
        "force":                 "taiji-shengong",
        "perform1":              "sword.lian",
        "perform2":              "unarmed.zhen",
        "weapon":                __DIR__"obj/changjian",
]),
([      "title1":                "武当败类",
        "title2":                "武当道长",
        "class":                 "taoist",
        "dodge":                 "tiyunzong",
        "parry":                 "taiji-quan",
        "unarmed":               "taiji-quan",
        "sword":                 "taiji-jian",
        "blade":                 "taiji-dao",
        "force":                 "taiji-shengong",
        "prepare1":              "sword",
        "prepare2":              "blade",   
        "perform1":              "sword.lian",
        "perform2":              "blade.cuo",
        "perform3":              "unarmed.zhen",
        "weapon":                __DIR__"obj/changjian",
        "weapon_s":              __DIR__"obj/blade",
]), 
([      "title1":                "桃花岛逐徒",
        "title2":                "桃花岛门下",
        "dodge":                 "anying-fuxiang",
        "finger":                "tanzhi-shentong",
        "hand":                  "lanhua-shou",
        "parry":                 "yuxiao-jianfa",
        "sword":                 "yuxiao-jianfa",
        "force":                 "bibo-shengong",
        "exert1":                "powerup",
        "perform1":              "sword.ging",
        "perform2":              "sword.tianwai",     
        "perform3":              "hand.fuxue",
        "perform4":              "finger.jinglei",
        "prepare1":              "finger",
        "prepare2":              "hand",
        "weapon":                __DIR__"obj/yuxiao",
]),
([      "title1":                "桃花岛逐徒",
        "title2":                "桃花岛门下",
        "dodge":                 "anying-fuxiang",
        "unarmed":               "xuanfeng-tui",    
        "strike":                "luoying-zhang",     
        "parry":                 "luoying-shenjian",
        "sword":                 "luoying-shenjian",
        "force":                 "bibo-shengong",
        "exert1":                "powerup",
        "perform1":              "sword.lybf",    
        "perform2":              "unarmed.kuangfeng",
        "perform3":              "strike.xuan",
        "prepare1":              "unarmed",
        "prepare2":              "strike",
        "weapon":                __DIR__"obj/changjian",
]),
});
string *first_name = ({ "郑","王","张","陈","金","姑苏","钱","孙","李","周","吴",
        "刘","林","钱","木","元","破","喜" });
string *name_words = ({ "志","天","良","志","忠","大","老","良","勇","元","华","宏",
        "孝","雄","龙","明","文","武","斌","来","胜","进","铭","彬","东","伟" });

void create()
{
        string name,id;
         int i,skill,skill_lvl,basic_radio,basic_skill,index,index1,index2,nl,dengji;
        object me=this_player(),weapon,weapon_s;
        mapping        mp,skills;
        string *basic=({"dodge","unarmed","force","parry","finger","hand",
                        "strike","taoism","club","staff","fork","hammer",
                        "blade","cuff","axe","sword","whip","dagger",
                        "throwing","claw" ,"poison"});
        int ratio=100;
        string *chat_chance_combat_here=({});
        name = first_name[random(sizeof(first_name))];

            if( random(10) > 2 ) name += name_words[random(sizeof(name_words))];
     id = this_player()->query("id");

          set_name(name, ({ id+" qiangdao", "qiangdao" }) );

        index=random(sizeof(menpai));
        mp=menpai[index];
        if (mp["gender"]) set("gender",mp["gender"]);
        if (mp["class"]) set("class",mp["class"]);
        if (me->query("shen")>0) set("title",mp["title1"]);
        else if (me->query("shen")<0) set("title",mp["title2"]);
        else 
        {
                if (random(2))
                set("title",mp["title1"]);
                else
                set("title",mp["title2"]);
        }


        ratio=80+random(me->query_temp("kill_quest/count")*5+1);

//here begin to set_skill of this_object()
        skill=0;
        skills=me->query_skills();        
        if (sizeof(skills))
        {
        for (i=0;i<sizeof(keys(skills));i++)
                if (skills[keys(skills)[i]]>=skill) 
                        skill=skills[keys(skills)[i]];
        }
        if(skill>get_level(me->query("zjb_dj/dj")))
        skill=get_level(me->query("zjb_dj/dj"));
        skill_lvl = get_level((int)me->query("combat_exp")) - skill;
        if(skill_lvl < 0)
                skill_lvl = 0;
        basic_skill=skill*ratio/100;
        if(basic_skill-skill > 60)  
                basic_skill=skill + 60;
        skill=basic_skill + skill_lvl/4;
        if(skill<50)    skill=50;
        if(skill<10) skill=(50+skill)/3;

        for (i=0;i<sizeof(keys(mp));i++)
        {
                if (member_array(keys(mp)[i],basic)!=-1)
                        {
                                set_skill(keys(mp)[i],skill);
                                set_skill(mp[keys(mp)[i]],skill);
                                map_skill(keys(mp)[i],mp[keys(mp)[i]]);
                        }
        }
        if (mp["prepare1"])
           prepare_skill(mp["prepare1"],query_skill_mapped(mp["prepare1"]));
        if (mp["prepare2"])
           prepare_skill(mp["prepare2"],query_skill_mapped(mp["prepare2"]));
        set("chat_chance_combat",50);
        if (mp["perform1"])
        chat_chance_combat_here+=({(: perform_action, mp["perform1"] :)});
        if (mp["perform2"]) 
        chat_chance_combat_here+=({(: perform_action, mp["perform2"] :)}); 
        if (mp["perform3"]) 
        chat_chance_combat_here+=({(: perform_action, mp["perform3"] :)}); 
        if (mp["perform4"]) 
        chat_chance_combat_here+=({(: perform_action, mp["perform4"] :)}); 

        if (mp["exert1"])
        chat_chance_combat_here+=({(: exert_function, mp["exert1"] :)});
        if (mp["exert2"]) 
        chat_chance_combat_here+=({(: exert_function, mp["exert2"] :)});
        if (mp["exert3"]) 
        chat_chance_combat_here+=({(: exert_function, mp["exert3"] :)});
        if (mp["exert4"]) 
        chat_chance_combat_here+=({(: exert_function, mp["exert4"] :)});
        chat_chance_combat_here+=({(: exert_function, "powerup" :)});

        set("str",(25+random(6)));
        set("con",(25+random(6)));
        set("dex",(25+random(6)));

        set("chat_chance", 5);
        set("chat_msg", ({
             (: random_move :),
        }) );
        if(query("title")=="全真败类" || query("title")=="全真道长")
          set_skill("xiantian-gong",skill);    
        if(query("title")=="古墓妖女" || query("title")=="古墓女侠")
        {
          set("family/family_name","古墓派");
          set_skill("quanzhen-jianfa",skill);
          set_skill("hubo",skill);       
          set_skill("tianluo-diwang",skill);
        }
        if(query("title")=="桃花岛逐徒" || query("title")=="桃花岛门下")
        {
          set("family/family_name","桃花岛");
          set_skill("art",skill);
          set_skill("count",skill);
          set_skill("qimen-wuxing",skill);
        }           
        if( query("title")=="移花宫妖女" || query("title")=="移花宫仙子")
        set("family/family_name","移花宫");
        if(query("title")=="星宿老魔" || query("title")=="星宿门徒")
          set_skill("beiming-zhenqi",skill);
        if(query("class")=="taoist")
          set_skill("taoism",skill);
        if(query("title")=="峨嵋贼尼" || query("title")=="峨嵋女尼")
        {
          set("family/family_name","峨嵋派");
          set_skill("mahayana",skill);
        }
        if(query("title")=="少林恶僧" || query("title")=="少林和尚")
        {
          set("family/family_name","少林派");
          set_skill("buddhism",skill);
        }
        if(query("title")=="血刀淫僧" || query("title")=="血刀门喇嘛")
          set_skill("lamaism",skill);
        if(query("title")=="五毒魔女" || query("title")=="五毒护法")   
        {
          set("family/family_name","五毒教");
          set_skill("duji",skill);
         }
        if(query("title")=="逍遥派恶徒" || query("title")=="逍遥派弟子")
          set("family/family_name","逍遥派"); 
        if(query("title")=="武当道长" || query("title")=="武当败类")
          set("family/family_name","武当派");   
        if(query("title")=="明教恶徒" || query("title")=="光明圣使")
          set("family/family_name","明教");   
        if(query("title")=="姑苏慕容弟子")
        {
          set("family/family_name","姑苏慕容");
          set("nick",HIR"以彼之道 * * * 还施彼身"NOR); 
        } 

//以下开始添加任务NPC等级计算..
   dengji = me->query("zjb_dj/dj") / 2;
     if(dengji<0)    dengji=1;
     set("zjb_dj/dj",dengji);
        basic_radio = me->query("max_qi") /1000 +1; 
        set("max_qi",me->query("zjb_dj/dj")*50000);
        set("qi",query("max_qi"));
        set("eff_qi",query("max_qi"));
          set("max_jing",me->query("max_jing"));
        set("eff_jing",query("max_jing"));
        set("jing",query("max_jing"));
        set("fight_till_die",1);
        set("eff_jing",query("max_jing"));
        if(me->query("max_neili")<80)
                nl=100;
                else nl=me->query("max_neili");
        set("max_neili",me->query("zjb_dj/dj")*90000);
        set("neili",me->query("zjb_dj/dj")*90000);
        set("max_jingli",nl*ratio/200);
        set("jingli",query("max_jingli"));
        basic_radio = me->query("max_neili") / 500 ;
        set("jiali",me->query("max_neili")/(20+5*basic_radio));
        set("owner",id);
        set("food",500);
        set("water",500);
        set("combat_exp",me->query("combat_exp")/80*ratio);
        if( query("combat_exp") > 10000000 )
        set("is_quest",1);
        set("no_guard",1);
        set("no_clean_up",1);
        setup();

        if (mp["weapon"])
        {
         weapon=carry_object(mp["weapon"]);
         weapon->wield();
         if( query("combat_exp") > 10000000 )
         {
           set("weapon",weapon->query("id"));
           for(i=0;i<3;i++)
           carry_object(mp["weapon"]);
         }
        }

        if (mp["weapon_s"])
        {
         weapon_s=carry_object(mp["weapon_s"]);
         weapon_s->wield();
         if( query("combat_exp") > 10000000 )
         {
           set("weapon_s",weapon_s->query("id"));
           for(i=0;i<3;i++)
           carry_object(mp["weapon_s"]);
         }
        }

//        carry_object(__DIR__"obj/tiejia")->wear();
}
int get_level(int exp)
{
  object me;
  int level;
  me = this_player();
  level= me->query("zjb_dj/dj")*150;
  return level;    
}               

#include "npc.h"




              

