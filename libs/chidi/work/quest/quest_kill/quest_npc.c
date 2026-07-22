//火云录杀手任务NPC数据库 writed by xingyun 22/5/2001; 

inherit BHNPC;
#include <ansi.h>
#include <room.h>    
int get_level(int exp);
void  consider();
void go_back(object me)
{
       object env;
       string *dirs,dir;
       mapping exits;
       int door,i;

       door=0;
       env=environment(me);

       if( mapp(exits = env->query("exits")) )
       {
         dirs = keys(exits);
         for(i=0; i<sizeof(dirs); i++)
         if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
         { 
           door=1;
           dirs[i] = 0;
         }
         dirs -= ({ 0 });

         dir=dirs[random(sizeof(dirs))];
         if(door) command("open door");
         command("tnnd");
         command("go "+dir);
       }
       return;
}

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
([      "title1":                "红花会败类",
        "title2":                "红花会大侠",
        "class":                 "sworder",
        "gender":                "男性",
        "dodge":                 "youlong-shenfa",
        "parry":                 "baihuacuo-quan",     
        "unarmed":               "baihuacuo-quan",
        "sword":                 "luohua-jian",
        "force":                 "honghua-shengong",
        "exert1":                "powerup",
        "perform1":              "sword.qixing",
        "perform2":              "sword.beng",
        "weapon":                __DIR__"obj/changjian",
]),
([      "title1":                "浣花剑派败类",
        "title2":                "浣花剑派剑客",
        "class":                 "sworder",
        "gender":                "男性",
        "dodge":                 "feihua-wuping",
        "parry":                 "tiexian-quan",
        "unarmed":               "tiexian-quan",
        "sword":                 "huanhua-jian",
        "force":                 "guiyuan-dafa",
        "exert1":                "powerup",
        "perform1":              "sword.snow",
        "perform2":              "sword.zhenjian",
        "weapon":                __DIR__"obj/changjian",
]),
([      "title1":                "灵宵城弟子",
        "title2":                "灵宵城弟子",
        "class":                 "sworder",
        "gender":                "男性",
        "dodge":                 "snowstep",
        "parry":                 "xueshan-sword",
        "unarmed":               "snow-zhang",
        "sword":                 "xueshan-sword",
        "force":                 "bingxue-xinfa",
        "exert1":                "powerup",
        "perform1":              "sword.feixue",
        "perform2":              "sword.wanmei",
        "perform3":              "sword.xuehua",
        "perform4":              "unarmed.yanxue",
        "weapon":                __DIR__"obj/changjian",
]),
([      "title1":                "灵宵城弟子",
        "title2":                "灵宵城弟子",
        "class":                 "sworder",
        "gender":                "男性",
        "dodge":                 "snowstep",
        "parry":                 "xueshan-sword",
        "unarmed":               "snow-zhang",
        "blade":                 "jinwu-blade",
        "force":                 "bingxue-xinfa",
        "exert1":                "powerup",
        "perform1":              "blade.jinwu",
        "perform2":              "unarmed.yanxue",
        "weapon":                __DIR__"obj/blade",
]),
([      "title1":                "灵宵城弟子",
        "title2":                "灵宵城弟子",
        "class":                 "sworder",
        "gender":                "男性",
        "dodge":                 "snowstep",
        "parry":                 "xueshan-sword",
        "unarmed":               "snow-zhang",
        "blade":                 "jinwu-blade",
        "sword":                 "xueshan-sword",
        "force":                 "bingxue-xinfa",
        "prepare1":              "sword",  
        "prepare2":              "blade",  
        "exert1":                "powerup",
        "perform1":              "sword.xuehua",       
        "perform2":              "blade.jinwu",
        "perform3":              "unarmed.yanxue",
        "perform4":              "sword.feixue",    
        "weapon":                __DIR__"obj/changjian",
        "weapon_s":              __DIR__"obj/blade",
]),
([      "title1":                "狂风剑派剑客",
        "title2":                "狂风剑派剑客",
        "class":                 "sworder",
        "gender":                "男性",
        "dodge":                 "zfwy-bu",
        "parry":                 "kuangfeng-jianfa",
        "strike":                "fyfy-zhang",
        "sword":                 "kuangfeng-jianfa",
        "force":                 "zhenfeng-xinfa",
        "prepare1":              "strike",
        "exert1":                "han",
        "perform1":              "sword.kuang",
        "perform2":              "sword.hu",
        "perform3":              "strike.yunyu",
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
        "parry":                "duanjia-jian",
        "sword":                "duanjia-jian",
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
        "dodge":                "pixie-jian",
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
([      "title1":                "血刀淫僧",
        "title2":                "血刀门喇嘛",
        "gender":                "男性",
        "dodge":                 "shenkong-xing",
        "parry":                 "xue-dao",
        "hand":                  "dashou-yin",
        "blade":                 "xue-dao",
        "force":                 "longxiang",
        "prepare1":              "hand",
        "perform1":              "blade.shendao",
        "perform2":              "hand.yin",  
        "exert1":                "fanchang",   
        "weapon":                __DIR__"obj/blade",
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
([      "title1":                "神秘杀手",
        "title2":                "神秘高手",
        "class":                 "taoist",
        "dodge":                 "bugui-bufa",
        "parry":                 "qishen-dao",
        "strike":                "fanyun-zhang",
        "blade":                 "qishen-dao",
        "force":                 "wuji-shengong",
        "prepare1":              "strike", 
        "perform1":              "blade.shaqi",
        "perform2":              "blade.wudao",
        "exert1":                "powerup",
        "weapon":                __DIR__"obj/blade",
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

mapping *first_name=({
([      "name":"孙",      "id":"sun"    ]),
([      "name":"吴",      "id":"wu"     ]),
([      "name":"独孤",    "id":"dugu"   ]),
([      "name":"赖",      "id":"lai"    ]),
([      "name":"林",      "id":"lin"    ]),
([      "name":"赵",      "id":"zhao"   ]),
([      "name":"任",      "id":"ren"    ]),
([      "name":"钱",      "id":"qian"   ]),
([      "name":"李",      "id":"li"     ]),
([      "name":"张",      "id":"zhang"  ]),
([      "name":"臧",      "id":"zang"   ]),
([      "name":"徐",      "id":"xu"     ]),
([      "name":"杨",      "id":"yang"   ]),
([      "name":"邱",      "id":"qiu"    ]),
([      "name":"舒",      "id":"shu"    ]),
([      "name":"叶",      "id":"ye"     ]),
([      "name":"刘",      "id":"liu"    ]),
([      "name":"周",      "id":"zhou"   ]),
([      "name":"杨",      "id":"yang"   ]),
([      "name":"王",      "id":"wang"   ]),
([      "name":"梁",      "id":"liang"  ]),
([      "name":"于",      "id":"yu"     ]),
([      "name":"黄",      "id":"huang"  ]),
([      "name":"林",      "id":"lin"    ]),
([      "name":"陈",      "id":"chen"   ]),
([      "name":"谢",      "id":"xie"    ]),
([      "name":"鲁",      "id":"lu"     ]),
([      "name":"何",      "id":"he"     ]),
([      "name":"曾",      "id":"zeng"   ]),
([      "name":"郭",      "id":"guo"    ]),
([      "name":"成",      "id":"cheng"  ]),
([      "name":"南宫",    "id":"nangong"  ]),
([      "name":"欧阳",    "id":"ouyang"   ]),
([      "name":"长孙",    "id":"zhangsun" ]),
([      "name":"慕容",    "id":"murong"   ]),
([      "name":"西门",    "id":"ximen"    ]),
([      "name":"公孙",    "id":"gongsun"  ]),
});

mapping *second_name1=({
([      "name":"",      "id":""      ]),
([      "name":"风",    "id":"feng"  ]),
([      "name":"德",    "id":"de"    ]),
([      "name":"晓",    "id":"xiao"  ]),
([      "name":"润",    "id":"run"   ]),
([      "name":"富",    "id":"fu"    ]),
([      "name":"达",    "id":"da"    ]),
([      "name":"默",    "id":"mo"    ]),
([      "name":"玄",    "id":"xuan"  ]),
([      "name":"海",    "id":"hai"   ]),
([      "name":"自",    "id":"zi"    ]),
([      "name":"泰",    "id":"tai"   ]),
([      "name":"昭",    "id":"zhao"  ]),
([      "name":"",      "id":""      ]),
([      "name":"通",    "id":"tong"  ]),
([      "name":"耘",    "id":"yun"   ]),
([      "name":"奋",    "id":"fen"   ]),
([      "name":"宏",    "id":"hong"  ]),
([      "name":"荣",    "id":"rong"  ]),
([      "name":"鹏",    "id":"peng"  ]),
([      "name":"冲",    "id":"chong" ]),
([      "name":"灏",    "id":"hao"   ]),
([      "name":"思",    "id":"si"    ]),
([      "name":"理",    "id":"li"    ]),
([      "name":"刚",    "id":"gang"  ]),
([      "name":"武",    "id":"wu"    ]),
([      "name":"逸",    "id":"yi"    ]),
});

mapping *second_name2=({
([      "name":"凤",    "id":"feng"  ]),
([      "name":"玉",    "id":"yu"    ]),
([      "name":"",      "id":""      ]),
([      "name":"子",    "id":"zi"    ]),
([      "name":"金",    "id":"jin"   ]),
([      "name":"忆",    "id":"yi"    ]),
([      "name":"淑",    "id":"shu"   ]),
([      "name":"碧",    "id":"bi"    ]),
([      "name":"兰",    "id":"lan"   ]),
([      "name":"英",    "id":"ying"  ]),
([      "name":"语",    "id":"yu"    ]),
([      "name":"嫣",    "id":"yan"   ]),
([      "name":"珠",    "id":"zhu"   ]),
([      "name":"紫",    "id":"zi"    ]),
([      "name":"霞",    "id":"xia"   ]),
([      "name":"彩",    "id":"cai"   ]),
([      "name":"丽",    "id":"li"    ]),
([      "name":"莉",    "id":"li"    ]),
([      "name":"君",    "id":"jun"   ]),
([      "name":"婉",    "id":"wan"   ]),
});

mapping *third_name1=({
([      "name":"峰",    "id":"feng"  ]),
([      "name":"华",    "id":"hua"   ]),
([      "name":"奇",    "id":"qi"    ]),
([      "name":"歌",    "id":"ge"    ]),
([      "name":"旭",    "id":"xu"    ]),
([      "name":"发",    "id":"fa"    ]),
([      "name":"威",    "id":"wei"   ]),
([      "name":"晖",    "id":"hui"   ]),
([      "name":"城",    "id":"cheng" ]),
([      "name":"轩",    "id":"xuan"  ]),
([      "name":"勇",    "id":"yong"  ]),
([      "name":"泰",    "id":"tai"   ]),
([      "name":"在",    "id":"zai"   ]),
([      "name":"君",    "id":"jun"   ]),
([      "name":"军",    "id":"jun"   ]),
([      "name":"凡",    "id":"fan"   ]),
([      "name":"伟",    "id":"wei"   ]),
([      "name":"帆",    "id":"fan"   ]),
([      "name":"雄",    "id":"xiong" ]),
([      "name":"涛",    "id":"tao"   ]),     
([      "name":"波",    "id":"bo"    ]),
([      "name":"杰",    "id":"jie"   ]),
([      "name":"郎",    "id":"lang"  ]),     
});

mapping *third_name2=({
([      "name":"兰",    "id":"lan"   ]),
([      "name":"婷",    "id":"ting"  ]),
([      "name":"霞",    "id":"xia"   ]),
([      "name":"莲",    "id":"lian"  ]),
([      "name":"卿",    "id":"qing"  ]),
([      "name":"楣",    "id":"mei"   ]),
([      "name":"妹",    "id":"mei"   ]),
([      "name":"敏",    "id":"min"   ]),
([      "name":"菲",    "id":"fei"   ]),
([      "name":"贞",    "id":"zhen"  ]),
([      "name":"君",    "id":"jun"   ]),
([      "name":"嫣",    "id":"yan"   ]),
([      "name":"凤",    "id":"feng"  ]),
([      "name":"燕",    "id":"yan"   ]),
([      "name":"珍",    "id":"zhen"  ]),
([      "name":"真",    "id":"zhen"  ]),
([      "name":"香",    "id":"xiang" ]),
([      "name":"玉",    "id":"yu"    ]),
([      "name":"娘",    "id":"niang" ]),
});

void create()
{
        string id1,id2,id3,idf1,idf2;
        string name1,name2;
        int i,skill,skill_lvl,basic_radio,basic_skill,index,index1,index2,nl;
        object me=this_player(),weapon,weapon_s;
        mapping        mp,skills;
        string *basic=({"dodge","unarmed","force","parry","finger","hand",
                        "strike","taoism","club","staff","fork","hammer",
                        "blade","cuff","axe","sword","whip","dagger",
                        "throwing","claw" ,"poison"});
        int ratio=50;
        string *chat_chance_combat_here=({});

        index1=random(sizeof(first_name));
        index2=random(sizeof(first_name));        
        name1=first_name[index1]["name"];
        name2=first_name[index2]["name"];
        id1=first_name[index1]["id"];
        id2=first_name[index2]["id"];
        idf1=id1;
        idf2=id2;
        if(query("title1")=="姑苏慕容弟子")
        {
                id1="慕容";
                id2="慕容";
        }
        index1=random(sizeof(second_name1));
        index2=random(sizeof(second_name2));
        name1+=second_name1[index1]["name"];
        name2+=second_name2[index2]["name"];
        id1+=" "+second_name1[index1]["id"];
        id2+=" "+second_name2[index2]["id"];


        index1=random(sizeof(third_name1));
        index2=random(sizeof(third_name2));
        name1+=third_name1[index1]["name"];
        name2+=third_name2[index2]["name"];
        id1+=third_name1[index1]["id"];
        id2+=third_name2[index2]["id"];

        set_name(name1,({id1,idf1}) );
        index=random(sizeof(menpai));
        mp=menpai[index];
        if (mp["gender"]) set("gender",mp["gender"]);
        if (query("gender")=="女性") set_name(name2,({id2,idf2}));
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
        //if (sizeof(skills))
       // {
        //for (i=0;i<sizeof(keys(skills));i++)
         //       if (skills[keys(skills)[i]]>=skill) 
       //                 skill=skills[keys(skills)[i]];
        //}
        if(skill>get_level(me->query("combat_exp")))
        skill=get_level(me->query("combat_exp"));
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
        set("no_suck",1);
        set("chat_chance", 5);
        set("chat_msg", ({
            // (: random_move :),
             (: consider :)   
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

        basic_radio = me->query("max_qi") /10 +1; 
        set("max_qi",(me->query("max_qi")/2));
        set("qi",query("max_qi"));
        set("eff_qi",query("max_qi"));
        set("max_jing",(me->query("max_jing")/2));
        set("eff_jing",query("max_jing"));
        set("jing",query("max_jing"));
        set("jh_dj/dj",me->query(("jh_dj/dj")+("jh_dj/zhuan")));
        set("fight_till_die",1);
        set("eff_jing",query("max_jing"));
        if(me->query("max_neili")<80)
                nl=50;
                else nl=me->query("max_neili");
        set("max_neili",nl*ratio/20);
        set("neili",me->query("max_neili")/2);
        set("max_jingli",nl*ratio/50);
        set("jingli",me->query("max_jingli")/2);
        basic_radio = me->query("max_neili") / 50 ;
        set("jiali",me->query("max_neili")/(20+5*basic_radio));
        set("killer","xingyun");
        set("food",500);
        set("water",500);
        set("no_suck",1);
        set("no_suck2",1);
        set("combat_exp",me->query("combat_exp")-random(100000000));
        if( query("combat_exp") > 10000000 )
        chat_chance_combat_here+=({(: consider :)}); 
        set("chat_msg_combat",chat_chance_combat_here);
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

        carry_object(__DIR__"obj/tiejia")->wear();
}

void  consider()
{
        object me=this_object();

        if(me->is_fighting() && ( query("qi")*2 < query("max_qi")
           || query("eff_qi")*3/2 < query("max_qi") ) )
         command("surrender");   
        if( !me->query_temp("weapon") )
        { 
          command("grin");
          if( query("weapon") ) command("wield "+query("weapon"));
          if( query("weapon_s") ) command("wield "+query("weapon_s"));
        }
        return;
}

void check_room(object me)
{
    object env=environment(me);
    
    if(!living(me) || !env ) return;
    if(env && (env->query("no_quest") ||
                env->query("no_fight") ))
           go_back(me);

    return;
}

void init()
{
        object ob,env;
        object killer=this_object();        
        string area;
        if(!killer->query("area") && !killer->query("found") )
        {
                env=environment(killer);
                if(objectp(env) && sscanf(file_name(env),"/d/%s/",area)==1)
                        killer->set("area",area);
        }
        command("yun powerup");
        ob=this_player();
        if(!this_object()->query("killer"))
                return;
        if(ob->query("id")==query("killer"))
        {
                delete("area");
                set("found",1);
        }

        if(ob->query("combat_exp") >= 10000000)
        {
            if(query("title")!="神秘杀手"&&query("title")!="神秘高手")
            if(ob->query("id")==query("killer"))
            if( !is_fighting() && random(10)==0)
            {
              message_vision(HIR"$N喝道：“你又想偷袭我。”\n"NOR,killer); 
              killer->set("auto_kill",1);
              killer->kill_ob(ob);
              ob->kill_ob(killer); 
            }

            if (query("title")=="神秘杀手" || query("title")=="神秘高手")
            if (ob->query("id")==query("killer") )
            if(  !is_fighting() && !query_leader()) 
            {
             message_vision(HIR"$n一看到$N，冷笑了一声: 又一个活得不耐烦的家伙，自寻死路!\n"NOR,ob,killer);
             this_object()->kill_ob(ob);
             ob->kill_ob(this_object()); 
            }
        }

        if(this_object()->query("jiali")==0)
        set("jiali", (int)this_object()->query_skill("force")/4);

        if(this_object()->query("killer")!=ob->query("id"))
        {
                add_action("do_kill","team kill");
                add_action("do_kill","kill");
                add_action("do_kill","hit");
                add_action("do_kill","fight");
                add_action("do_kill","steal");
                add_action("do_kill","beg");
                add_action("do_kill","touxi");   
                add_action("do_kill","persuade");
        }
        remove_call_out("check_room");
        call_out("check_room",2,killer);

}

void start_escape(object ob,object me)
{
        call_out("escape_me",9,ob,me);
}

int do_kill(string arg)
{
        string what,who;
        if(!arg) return 0;
        if(this_object()->id(arg))
        {
                write("江湖人士，还是少惹为妙。\n");
                return 1;
        }
        else
        if(sscanf(arg,"%s from %s",what,who)==2 && this_object()->id(who))
        {
                write("还是到别处去施展你的本事吧。\n");
                return 1;
        }
        return 0;
}


void escape_me(object ob,object me)
{
        if( !ob ) return;
        if (objectp(me) ) 
        {
                me->set_temp("kill_quest/have_task",0);
                me->add("score",-random(3));
                me->set_temp("kill_quest/killed",ob->query("id"));

                if( environment(ob) )
                if(ob->query("shen_type")==-1)
                message_vision(
"$N狞笑了几声：“今天心情好，"+RANK_D->query_self_rude(ob)+
"就放过你，不陪你玩了。”说罢，一个筋斗跳出战圈，不知去向。\n",ob);
        else
                message_vision(
"$N跳出战圈，朗声道：“"+RANK_D->query_self(ob)+"尚
有要事在身，下回再来讨教。”只见身形几晃，已无踪无影。\n",ob);
        }
        destruct(ob);
        return;
}

void die()
{
        int reward_exp,reward_pot,gg,level=0;
        string fam;
        object killer,me;
        string *dir,file;
        object equip;
object reward_gold;
reward_gold=new("/clone/money/gold");

        me=this_object();
        killer=me->query_temp("last_damage_from");

        message_vision(HIC"$N惨嚎一声，口喷鲜血，到在地上死了。\n"NOR,me);
/*
        if( killer && random(50) < 1 )
        { 
           dir = get_dir("/quest/quest_kill/obj/");
           file = "/quest/quest_kill/obj/"+dir[random(sizeof(dir))];
           if( file_size(file) != -1 )
           {
               equip = new(file);
               if( objectp(equip) )
               {
                 equip->change_ob(me,killer);
                 equip->move(environment(me));
                 tell_object(all_inventory(environment(me)),
                             BLINK+HIB"只听“哐铛”一声，好象一样东西从"
                             +me->name()+"的尸体中掉了出来···\n"NOR);
               }
            }
         }
        */
        if(killer && killer->query("id")==me->query("killer"))
        {
                   reward_exp=5000+random(2500)+level+
                           (int)killer->query_temp("kill_quest/count")*80;
                   if(killer->query("combat_exp") < 100000 )
                            reward_exp -=reward_exp/5;
                   if(killer->query("combat_exp") > 1000000)
                            reward_exp +=reward_exp/3;

                   fam=killer->query("title");
           if(  fam=="神秘杀手" || fam=="神秘高手"
                || fam=="古墓逆徒" || fam=="古墓大侠" 
                || fam=="五毒魔女" || fam=="五毒护法") 
                   reward_exp += reward_exp/2;

           reward_pot=2500+random(2500);

           reward_gold->set_amount(reward_pot/160);
        gg=reward_gold->query_amount();
           if (killer->query("combat_exp") > 10000000 && 
              (query("title")=="神秘杀手" || query("title")=="神秘高手") )   
           {
                   reward_exp +=5000+random(2500); 
                   reward_pot +=2500+random(2500);
                 gg +=20+random(10);
           }
           if (reward_pot<0) reward_pot=0;

                   tell_object(killer,HIW"在实战中，你获得了"+
CHINESE_D->chinese_number(reward_exp) +"点的『实战经验』"+
CHINESE_D->chinese_number(reward_pot)+"点的『潜能』"+
CHINESE_D->chinese_number(gg)+ "两的『黄金』！\n"NOR); 
                   killer->add("kill_quest/reward_exp",reward_exp);            
                   killer->add("kill_quest/reward_potential",reward_pot);
                   killer->add("combat_exp",reward_exp*2);
                   killer->add("potential",reward_pot*2);
                   killer->add("score",random(5));
                   killer->add_temp("kill_quest/count",1);
                   killer->set_temp("kill_quest/killed",me->query("id"));
                   killer->set_temp("kill_quest/killed_name",
                                      me->query("name"));
                   killer->set_temp("kill_quest/killed_place_name",
                                      me->query("place_name"));
                   killer->delete_temp("player_quit");
                   killer->set_temp("kill_quest/wait_start",time());
                   killer->set_temp("kill_quest/have_task",0);
                   reward_gold->move(killer);
        } else
        if( objectp( killer = find_living(me->query("killer")) ) ) 
        {
                killer->set_temp("kill_quest/have_task",0);
                killer->add("score",-random(10));
                killer->set_temp("kill_quest/killed",me->query("id"));
        }
        remove_call_out("escape_me");
        destruct(me);
        return;
}

int get_level(int exp)
{
  int level=0;
  do {
      level++;
     } while(level*level*level<(exp));

  return level;    
}               

