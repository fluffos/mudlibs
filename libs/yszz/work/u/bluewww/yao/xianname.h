        
string* snames=({
        "仙人","xian ren",
        "仙官","xian guan",
        "仙女","xian nu",
        "仙卿","xian qing",
        "仙将","xian jiang",
        "仙妃","xian fei",
        "大仙","da xian",       
"白云大师","baiyun dashi",
"燕赤侠","yanchi xia",
"仙子","xian zi",
"灭妖专家","mieyao zhuanjia",
"菩萨","pu sa",
"共工","gong gong",
"祝融","zhu rong",
"姜子牙","jiang ziya",
"哪吒","ne zha",
"木吒","mu zha",
"金吒","jin zha",
"托塔天王","tuota tianwang",
"金刚","jin gang",
"尊者","zun zhe",
"赤脚大仙","chijiao daxian",
"黄飞虎","huangfei hu",
"广成子","guancheng zi",
"太乙真人","taiyi zhenren",
"陆压道人","luya daoren",
"傀儡生","kuilei sheng",
"钟馗","zhong kui",
"罗汉","luo han",
"剑仙","jian xian",
"灶王爷","zaowang ye",
"土地神","tudi shen",
"财神","cai shen",
"龙女","long nv",
"善财童子","shancai tongzi",
"进宝天尊","jinbao tianzun",
"天兵","tian bing",
"天将","tian jiang",
"巨灵神","juling zhen",
});

void create()
{
    int i;

    set_name(snames[i=random(sizeof(snames)/2)*2],({snames[i+1]}));
    set("attitude","heroism");
    set("age",20+random(80));
    set("cor",40);
    set("str",30);
    set("cps",20);
    set("per",21+random(10));
    set("type","xian");
    setup();
}
