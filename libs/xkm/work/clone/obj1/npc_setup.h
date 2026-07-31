//Cracked by Roath
#ifndef _NPC_SETUP_H_
#define _NPC_SETUP_H_

static string *menpai_list = ({
    "huashan", "shaolin", "wudang", "emei", "gaibang", "murong",
    "baituo","xueshan", "xingxiu", "taohua", "gumu", "lingjiu" });

static mixed lastnamelist=({
    ({"赵", "zhao"}), ({"钱", "qian"}),  ({"孙", "sun"}),   ({"李", "li"}),    
    ({"周", "zhou"}), ({"吴", "wu"}),    ({"郑", "zheng"}), ({"王", "wang"}), 
    ({"冯", "feng"}), ({"陈", "chen"}),  ({"褚", "zhu"}),   ({"卫", "wei"}),   
    ({"蒋", "jiang"}),({"沈", "shen"}),  ({"韩", "han"}),   ({"杨", "yang"}),
    ({"朱", "zhu"}),  ({"秦", "qin"}),   ({"尤", "you"}),   ({"许", "xu"}),    
    ({"何", "he"}),   ({"吕", "lu"}),    ({"施", "shi"}),   ({"张", "zhang"}), 
    ({"孔", "kong"}), ({"曹", "cao"}),   ({"严", "yan"}),   ({"华", "hua"}),   
    ({"金", "jin"}),  ({"魏", "wei"}),   ({"陶", "tao"}),   ({"姜", "jiang"}),
    ({"戚", "qi"}),   ({"谢", "xie"}),   ({"邹", "zou"}),   ({"喻", "yu"}),   
    ({"柏", "bai"}),  ({"水", "shui"}),  ({"窦", "dou"}),   ({"章", "zhang"}), 
    ({"云", "yun"}),  ({"苏", "su"}),    ({"潘", "pan"}),   ({"葛", "ge"}),   
    ({"奚", "xi"}),   ({"范", "fan"}),   ({"彭", "peng"}),  ({"郎", "lang"}),
    ({"鲁", "lu"}),   ({"韦", "wei"}),   ({"昌", "chang"}), ({"马", "ma"}),
    ({"苗", "miao"}), ({"凤", "feng"}),  ({"花", "hua"}),   ({"方", "fang"}),
    ({"傻", "sha"}),  ({"任", "ren"}),   ({"袁", "yuan"}),  ({"柳", "liu"}),
    ({"邓", "deng"}), ({"鲍", "bao"}),   ({"史", "shi"}),   ({"唐", "tang"}),
    ({"费", "fei"}),  ({"康", "kang"}),  ({"岑", "cen"}),   ({"薛", "xue"}),    
    ({"雷", "zhou"}), ({"贺", "he"}),    ({"倪", "ni"}),    ({"汤", "tang"}), 
    ({"藤", "teng"}), ({"殷", "yin"}),   ({"罗", "luo"}),   ({"华", "hua"}),   
    ({"郝", "hao"}),  ({"安", "an"}),    ({"常", "chang"}), ({"乐", "yue"}),
    ({"付", "fu"}),   ({"皮", "pi"}),    ({"齐", "qi"}),    ({"伍", "wu"}),    
    ({"余", "yu"}),   ({"顾", "gu"}),    ({"黄", "huang"}), ({"肖", "xiao"}), 
    ({"尹", "yin"}),  ({"姚", "yao"}),   ({"邵", "shao"}),  ({"汪", "wang"}),   
    ({"祁", "qi"}),   ({"毛", "mao"}),   ({"狄", "di"}),    ({"米", "mi"}),
    ({"贝", "bei"}),  ({"计", "ji"}),    ({"成", "cheng"}), ({"戴", "dai"}),    
    ({"宋", "song"}), ({"茅", "mao"}),   ({"庞", "pang"}),  ({"熊", "xiong"}), 
    ({"纪", "ji"}),   ({"舒", "shu"}),   ({"项", "xiang"}), ({"祝", "zhu"}), 
    ({"董", "dong"}), ({"梁", "liang"}), ({"樊", "fan"}),   ({"胡", "hu"}), 
    ({"凌", "ling"}), ({"霍", "huo"}),   ({"虞", "yu"}),    ({"万", "wan"}), 
    ({"柯", "ke"}),   ({"管", "guan"}),  ({"卢", "lu"}),    ({"英", "ying"}), 
    ({"仇", "qiu"}),  ({"候", "hou"}),   ({"岳", "yue"}),   ({"林", "lin"}),   
    ({"石", "shi"}),  ({"年", "nian"}),  ({"墨", "mo"}),    ({"佟", "tong"}),
    ({"司马", "sima"}),    ({"上官", "shangguan"}),({"欧阳", "ouyang"}),   ({"夏候", "xiahou"}), 
    ({"诸葛", "zhuge"}),   ({"东方", "dongfang"}), ({"赫连", "helian"}),   ({"皇甫", "huangpu"}),   
    ({"尉迟", "yuchi"}),   ({"公治", "gongye"}),   ({"淳于", "chunyu"}),   ({"公孙", "gongsun"}),
    ({"司徒", "situ"}),    ({"端木", "duanmu"}),   ({"辕轩", "xuanyuan"}), ({"令狐", "linghu"}), 
    ({"长孙", "zhangsun"}),({"幕容", "murong"}),   ({"左丘", "zuoqiu"}),   ({"西门", "ximen"}),   
    ({"南宫", "nangong"}), ({"百里", "baili"}),    ({"东郭", "dongguo"}),  ({"呼延", "huyan"}),
});

static mixed firstnamelist=({
({"金鳌", "jinao"}),   ({"吼", "hou"}), ({"克", "ke"}),
({"国梁", "guoliang"}), ({"光杰", "guangjie"}), ({"领军", "lingjun"}),
({"玄", "xuan"}),    ({"望海", "wanghai"}),  ({"千灵", "qianling"}),
({"青", "qing"}),    ({"伯山", "boshan"}),  ({"广义", "guangyi"}),
({"大雄", "daxiong"}),    ({"鹤", "he"}),  ({"九佳", "jiujia"}),
({"天恒", "tianheng"}),    ({"文亮", "wenliang"}),  ({"金鹏", "jinpeng"}),
({"涛", "tao"}),    ({"则成", "zecheng"}),  ({"石坚", "shijian"}),
({"评", "ping"}),    ({"建男", "jiannan"}),  ({"正鸿", "zhenghong"}),
({"天彪", "tianbiao"}),    ({"一邙", "yimang"}),  ({"泰", "tai"}),
({"智远", "zhiyuan"}),    ({"松年", "songnian"}),  ({"迅", "xun"}),
({"三星", "sanxing"}),    ({"孤桐", "gutong"}),  ({"柏英", "boying"}),
({"百童", "baitong"}),    ({"莲亭", "lianting"}),  ({"勉", "mian"}),
({"伯光", "boguang"}),    ({"云", "yun"}),  ({"南扬", "nanyang"}),
});

void set_random_name();

// sets full status (qi, jing, neili, jingli) according to level
void set_hp(int level);

// random menpai if parameter "menpai" given is 0
// return the menpai this npc has been assigned to
// sets "default_weapon" attribute
string set_skills(string menpai, int exp, int skill_rate);
#endif
