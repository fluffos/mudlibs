string* snames=({
        "野猫怪","yemao guai",
        "野鸡怪","yeji guai",
        "野狗怪","yegou guai",
        "野兔怪","yetu guai",
        "野象怪","yexiang guai",
        "野熊怪","yexiong guai",
        "野猪怪","yezhu guai",
        "蝎子怪","xiezi guai",
        "野猴怪","yehou guai",
 "椅妖","yizi yao",
"鬼婆","gui po",
"风妖","feng yao",
"雪精","xue jing",
"蛤蟆怪","hama guai",
"壁虎怪","bihu guai",
"水蛇精","shuishe jing",
"僵尸","jiang shi",
"树妖","shu yao",
"狐狸精","huli jing",
"槐树精","huaishu jing",
"吸血鬼","xixie gui",
"杨树精","yangshu jing",
"吊死鬼","diaosi gui",
"黑无常","heiwu chang",
"白无常","baiwu chang",
"蝴蝶精","hudie jing",
"刑天","xing tian",
"夔","kui",
"蚩尤","chi you",
"水魔兽","shui moshou",
"土魔兽","tu moshou",
"火魔兽","huo moshou",
"蛟怪","jiao guai",
"蛇妖","she yao",
"石矶娘娘","shiji niangniang",
"黑山老妖","heishan laoyao",
"蜈蚣精","wugong jing",
"白骨精","baigu jing",
"蜘蛛精","zhizhu jing",
"蜂妖","feng yao",
"灯笼怪","denglong guai",
"坛子精","tanzi guai",
"扫把精","saoba jing",
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
    set("type","yao");
    setup();
}
