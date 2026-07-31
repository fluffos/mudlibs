//npc名字
#ifndef _NPC_SETUP_H_
#define _NPC_SETUP_H_

nosave mixed lastnamelist=({
({"赵", "zhao"}), ({"钱", "qian"}),  ({"孙", "sun"}),   ({"李", "li"}),
({"周", "zhou"}), ({"吴", "wu"}),    ({"诸", "chu"}), ({"卫", "wei"}),
({"冯", "feng"}), ({"陈", "chen"}),  ({"卫", "wei"}),   ({"高", "gao"}),
({"蒋", "jiang"}),  ({"沈", "shen"}), ({"韩", "han"}),   ({"杨", "yang"}),
({"朱", "zhu"}),  ({"秦", "qin"}), ({"尤", "you"}),   ({"许", "xu"}),
({"何", "he"}),  ({"吕", "lv"}), ({"施", "shi"}),   ({"张", "zhang"}),
({"方", "fang"}),  ({"余", "yu"}), ({"陆", "lu"}),   ({"贺", "he"}),
({"孟", "meng"}),  ({"谢", "xie"}), ({"徐", "xu"}),   ({"杨", "yang"}),
({"韩", "han"}),  ({"彭", "peng"}), ({"仇", "qiu"}),   ({"杨", "yang"}),
({"游", "you"}),  ({"任", "ren"}), ({"熊", "xiong"}),   ({"司马", "sima"}),
({"桑", "sang"}),  ({"泉", "quan"}), ({"金", "jin"}),   ({"丁", "ding"}),
({"田", "tian"}),  ({"上官", "shangguan"}), ({"诸葛", "zhuge"}),   ({"秦", "qin"}),
});

nosave mixed firstnamelist=({
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

// void set_random_name();
void set_random_name()
{
    string l_c, l_e, f_c, f_e;
    int    i, j;
 
    i = random(sizeof(lastnamelist));
    j = random(sizeof(firstnamelist));
 
    l_c = lastnamelist[i][0];
    l_e = lastnamelist[i][1];
    f_c = firstnamelist[j][0];
    f_e = firstnamelist[j][1];
 
    set_name(l_c+f_c, ({ l_e+ " " + f_e, l_e, }));
    set("id_long", l_e + " " + f_e);
    set("id_short", l_e);
}



#endif

