inherit ROOM;

void init();

void create() {

    set("short", "藏器阁");
    set("long",
@TEXT    一间堆满了各式武器防具的屋子。虽然房间不小，但由于放的东西实
在太多，并不显得非常宽敞。
TEXT);

    set("no_fight", 1);

    set("objects", ([
        // 剑
        "/d/quanzhou/obj/xuantiejian" : 1,  // 玄铁剑
        "/d/mingjiao/obj/shenghuo-ling" : 1,  // 圣火令
        "/d/guiyunzhuang/obj/obj/qixing" : 1,  // 七星剑
        "/d/lingxiao/obj/baihongjian" : 2,  // 白虹剑
        "/d/riyuejiao/obj/riyuejian" : 2,  // 日月剑
        "/d/jinshe/obj/jinshe-jian" : 1,  // 金蛇剑
        "/clone/weapon/feizei/sword" : 1,  // 冰弦剑

        // 刀
        "/d/shaolin/obj/fumo-dao" : 2,  // 伏魔刀
        "/d/riyuejiao/obj/riyuedao" : 2,  // 日月刀
        "/clone/weapon/feizei/blade" : 1,  // 鸣鸿刀

        // 杖
        "/d/xingxiu/obj/bingpozhang" : 2,  // 冰魄杖
        "/kungfu/class/gaibang/yuzhu_zhang" : 2, // 玉竹杖
        "/clone/weapon/feizei/staff" : 2,  // 胡节

        // 甲
        "/d/yuewangmu/obj/jsbaojia" : 1,  // 紧身宝甲
        "/d/xiakedao/npc/obj/kylinpi" : 1,  // 火麒麟皮
        "/d/taohuadao/obj/ruanwei-jia" : 1,  // 软猬甲
        "/d/beijing/npc/obj/baojia" : 1, // 真丝宝甲
        "/clone/weapon/feizei/cloth" : 1,  // 龙鳞
        "/clone/weapon/feizei/hands" : 1, // 金丝手套

        // 暗器
        "/d/jinshe/obj/jinshe-zhui" : 4,  // 金蛇锥

        // 匕首
        "/clone/weapon/feizei/dagger" : 1,  // 鱼肠剑
        "/d/beijing/npc/obj/bishou" : 1, // 匕首
        
        // 鞭子
        "/clone/weapon/feizei/whip" : 1,  // 金蛇带

        // 枪
        "/clone/weapon/feizei/spear" : 1,  // 霸王枪
        "/d/yuewangmu/obj/dpqiang" : 1,  // 夺魄枪
    ]));

    set("exits", ([
        "south" : __DIR__"wuchang",
    ]));

    setup();
}
