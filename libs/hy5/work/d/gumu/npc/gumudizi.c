// longnv.c 小龙女

// 1998.9 by Lgg

#include <ansi.h>

inherit NPC;
string* nm1 = ({
"赵","钱","孙","李","周","吴","郑","王","冯","陈","褚","卫",
"蒋","沈","韩","杨","朱","秦","尤","许","何","吕","施","张",
"孔","曹","严","华","金","魏","陶","姜","戚","谢","邹","喻",
"柏","水","窦","章","云","苏","潘","葛","奚","范","彭","郎",
"鲁","韦","昌","马","苗","凤","花","方","傻","任","袁","柳",
"邓","鲍","史","唐","费","廉","岑","薛","雷","贺","倪","汤",
"藤","殷","罗","华","郝","邬","安","常","乐","呆","时","付",
"皮","卞","齐","康","伍","余","元","卜","顾","盈","平","黄",
"和","穆","肖","尹","姚","邵","湛","汪","祁","毛","禹","狄",
"米","贝","明","藏","计","伏","成","戴","谈","宋","茅","庞",
"熊","纪","舒","屈","项","祝","董","梁","樊","胡","凌","霍",
"虞","万","支","柯","昝","管","卢","英","仇","候","岳","帅",
"司马","上官","欧阳","夏候","诸葛","闻人","东方","赫连","皇甫",
"尉迟","公羊","澹台","公治","宗政","濮阳","淳于","单于","太叔",
"申屠","公孙","仲孙","辕轩","令狐","钟离","宇文","长孙","幕容",
"司徒","师空","颛孔","端木","巫马","公西","漆雕","乐正","壤驷",
"公良","拓趾","夹谷","宰父","谷梁","楚晋","阎法","汝鄢","涂钦",
"段千","百里","东郭","南郭","呼延","归海","羊舌","微生","梁丘",
"左丘","东门","西门","佰赏","南官",
"缑","亢","况","后","有","琴","商","牟","佘","耳","墨","哈",
"谯","年","爱","阳","佟","第","五","言","福","蒯","钟","宗",
"林","石",
});

string* id = ({
"zhao","qian","sun","li","zhou","wu","zhen","wang","feng","chen","zhu","wei",
"jiang","shen","han","yang","zhu","qing","you","xu","he","lu","shi","zhang",
"kong","cao","yan","hua","jin","wei","tao","jiang","qie","xie","zhou","yu",
"bo","shui","dou","zhang","yun","su","pan","ge","xi","fan","peng","lang",
"lu","wei","chang","ma","miao","feng","hua","fang","sha","ren","yuan","liu",
"deng","bao","shi","tang","fei","lian","chen","xue","lei","he","ni","tang",
"teng","yin","luo","hua","hao","wu","an","chang","le","dai","shi","fu",
"pi","bian","qi","kang","wu","yu","yuan","po","gu","ying","ping","huang",
"he","mu","xiao","yin","yao","shao","zhan","wang","qi","mao","yu","di",
"mi","bei","ming","zang","ji","fu","cheng","dai","tan","song","mao","pang",
"xiong","ji","su","qu","xiang","zhu","dong","liang","fan","hu","ling","ho",
"yu","wan","zhi","ke","jiu","guan","lu","ying","qiu","hou","yue","suai",
"sima","shangguan","ouyang","xiahou","zhuge","wenren","dongfang","helian","huangpu",
"weichi","gongyang","zhantai","gongye","zongzheng","puyang","chunyu","shanyu","taishu",
"shentu","gongshun","zhongshun","xuanyuan","linghu","zhongli","yuwen","changshun","murong",
"situ","shikong","zhuankong","duanmu","wuma","gongxi","qidiao","lezheng","xiangsi",
"gongliang","tuozhi","jiagu","zaifu","guliang","chujing","yanfa","ruye","tuqin",
"duanqian","baili","dongguo","nanguo","huyan","guihai","yangshe","weisheng","liangqiu",
"zuoqiu","dongmen","ximen","baishang","nangong",
"gou","kang","kuang","hou","you","qing","shang","mo","she","er","mo","ha",
"qiao","nian","ai","yang","dong","di","wu","yan","fu","kai","zong","zong",
"lin","shi",
});

string* nm2 = ({
"忠","孝","礼","义","智","勇","仁","匡","宪","令","福","禄","大","小","晓",
"高","可","阿","金","世","克","叔","之","公","夫","时","若","庆","文","武",
"多","才","长","子","永","友","自","人","为","铁","","","","","","","","",
"","","","","","","","","","","","","","",
});

string* nm4 = ({      //女性专用
"爱","春","丹","芳","芬","凤","姑","红","虹","娇","娟",
"菊","兰","岚","丽","莉","莲","玲","琳","娜","琴","芹",
"倩","萍","婷","霞","香","艳","燕","英","瑛","玉","珍",
"珠",
});


void create()
{
      string weapon;
   int i = random(sizeof(nm1));

   set_name(nm1[i]+nm2[random(sizeof(nm2))]+nm4[random(sizeof(nm4))], ({ "gm dizi", "dizi" }));
        set("gender", "女性");
        set("age", 18);
        set("long",
                "披著一袭轻纱般的白衣。\n"+
                "是古墓派新一辈的女弟子。\n");
        set("attitude", "friendly");

        set("per", 30);
        set("str", 30);
        set("int", 37);
        set("con", 36);
        set("dex", 38);

        set("chat_chance", 1);
        set("chat_msg", ({
                (: command, "say 古墓派清尘脱俗，想加入的话，可以看"BRED"(help gumu)"NOR"。" :),
                (: command, "say 听说师哥，师姐们已经成为了神雕侠侣的传人， 什麽时候能带我去看看呢？" :),
        }) );

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.hubo" :),
                (: perform_action, "sword.suxing" :),
                (: perform_action, "unarmed.youju" :),
                (: perform_action, "unarmed.wuqing" :),
        }) );

        set("qi", 2500);
        set("eff_qi", 2500);
        set("max_qi", 2500);
        set("jing", 2600);
        set("eff_jing", 2600);
        set("max_jing", 2600);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 200);

        set("combat_exp", 700000);
        set("score", 0);

        set_skill("force", 150);
        set_skill("throwing", 100);
        set_skill("whip", 160);
        set_skill("yinsuo-jinling", 160);
        set_skill("yangyanshu", 100);
        set_skill("yunv-xinfa", 150);    //玉女心法
        set_skill("sword", 150);
        set_skill("yunv-jian", 150);     //玉女剑
        set_skill("quanzhen-jian",130);  //全真剑
        set_skill("dodge", 160);
        set_skill("yunv-shenfa", 160);   //玉女身法
        set_skill("parry", 150);
        set_skill("hubo", 120);          //双手互搏
        set_skill("unarmed",150);
        set_skill("meinv-quan", 160);    //美女拳法
        set_skill("literate",120);
        set_skill("qufeng",150);         //驱蜂之术
        set_skill("wuzhan-mei",150);
        set_skill("strike",100);
        set_skill("tianluo-diwang",200);         //驱蜂之术

        map_skill("force", "yunv-xinfa");
        map_skill("sword", "yunv-jian");
        map_skill("dodge", "yunv-shenfa");
        map_skill("parry", "meinv-quan");
        map_skill("unarmed", "meinv-quan");

        create_family("古墓派", 4, "弟子");


        set("book_count", 1);
        set("count",3);
        set("yfzhen",3);


        set("env/wimpy", 40);
        setup();

        carry_object("clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/baipao")->wear();

}

