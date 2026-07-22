// Write By Yanyang@SJ 2001.9.27
// NPC: /d/changan/child.c

inherit NPC;

string* f_name = ({
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
"缑","亢","况","后","有","琴","商","牟","佘","耳","墨","哈",
"谯","年","爱","阳","佟","第","五","言","福","蒯","钟","宗",
"林","石",
});

string* f_id = ({
"zhao","qian","sun","li","zhou","wu","zhen","wang","feng","chen","zhu","wei",
"jiang","shen","han","yang","zhu","qin","you","xu","he","lu","shi","zhang",
"kong","cao","yan","hua","jin","wei","tao","jiang","qi","xie","zhou","yu",
"bo","shui","dou","zhang","yun","su","pan","ge","xi","fan","peng","lang",
"lu","wei","chang","ma","miao","feng","hua","fang","sha","ren","yuan","liu",
"deng","bao","shi","tang","fei","lian","chen","xue","lei","he","ni","tang",
"teng","yin","luo","hua","hao","wu","an","chang","le","dai","shi","fu",
"pi","bian","qi","kang","wu","yu","yuan","bo","gu","ying","ping","huang",
"he","mu","xiao","yin","yao","shao","zhan","wang","qi","mao","yu","di",
"mi","bei","ming","zang","ji","fu","cheng","dai","tan","song","mao","pang",
"xiong","ji","su","qu","xiang","zhu","dong","liang","fan","hu","ling","huo",
"yu","wan","zhi","ke","jiu","guan","lu","ying","qiu","hou","yue","suai",
"gou","kang","kuang","hou","you","qin","shang","mu","she","er","mo","ha",
"qiao","nian","ai","yang","dong","di","wu","yan","fu","kuai","zhong","zong",
"lin","shi",
});

string* name_m = ({
"小二","小三","小四","小五","小六","小七","小八",
});

string* id_m = ({
"xiaoer","xiaosan","xiaosi","xiaowu","xiaoliu","xiaoqi","xiaoba",
});

void create()
{
        string f_n, f_i, name_1, id_1;
        int i;
    
        i = random(sizeof(f_name));
        f_n = f_name[i];
        f_i = f_id[i];
        i = random(sizeof(name_m));
        name_1 = name_m[i];
        id_1 = id_m[i];

        set_name(f_n+name_1,({ f_i+" "+id_1, f_i, id_1 }));
        //set_name(name);
        set("gender", "男性" );
        set("age", 12);
        set("long", "这是个非常调皮捣蛋的半大孩子。\n");

        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set("combat_exp", 2000);
        set("str", 25);
        set("dex", 20);
        set("con", 15);
        set("int", 15);
        set("attitude","heroism");
        setup();

        carry_object(ARMOR_D("cloth"))->wear();
        add_money("coin", 10);
}