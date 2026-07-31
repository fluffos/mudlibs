string set_npc(object ob, string menpai, int exp, int skill_rate);

string set_npc(object ob, string menpai, int exp, int skill_rate)
{
	string *menpai_list = ({
    "huashan", "shaolin", "wudang", "emei", "gaibang",
    "baituo", "xueshan", "xingxiu", "taohua"  });

    int level, i;
	string c_menpai;

    //if (exp < 0 || skill_rate < 0) return;
    level = pow(10*exp, 0.333334);
	level = level * skill_rate / 100;
    if (level < 20) level = 20;
    if (!stringp(menpai)) 
	menpai = menpai_list[random(sizeof(menpai_list))];
	c_menpai = CHINESE_D->chinese_menpai(menpai);

	generate_cn_name(ob);
	ob->set("long", "此人好像是个"+c_menpai+"的高手。\n");
	ob->create_family(c_menpai, 0, "高手");

    ob->set("max_neili", level*12);
    ob->set("neili", level*12);
    ob->set("eff_jingli", level*10);
    ob->set("max_jingli", level*10);
    ob->set("jingli", level*10);
    ob->set("max_qi", level*12);
    ob->set("eff_qi", level*12);
    ob->set("qi", level*12);
    ob->set("max_jing", level*10);
    ob->set("eff_jing", level*10);
    ob->set("jing", level*10);
    ob->set("jiali", level/2);

    ob->set("combat_exp", exp);
    ob->set_skill("force", level);
    ob->set_skill("dodge", level);
    ob->set_skill("parry", level);
    ob->set_skill("sword", level);
    ob->set_skill("blade", level);
    ob->set_skill("strike", level);
    ob->set_skill("cuff", level);
    ob->set_skill("finger", level);
    ob->set_skill("claw", level);
    ob->set_skill("club", level);
    ob->set_skill("kick", level);
    ob->set_skill("staff", level);
    ob->set_skill("whip", level);

    switch (menpai){
    case "huashan":
        ob->set_skill("huashan-jianfa", level);
        ob->set_skill("liangyi-dao", level);
        ob->set_skill("huashan-shenfa", level);
        ob->set_skill("zixia-gong", level);
	ob->set_skill("pishi-poyu", level);
	ob->set_skill("hunyuan-zhang", level);
 
        ob->map_skill("force", "zixia-gong");
        ob->map_skill("dodge", "huashan-shenfa");
        ob->map_skill("parry", "huashan-jianfa");
        ob->map_skill("strike", "hunyuan-zhang");
	ob->map_skill("cuff", "pishi-poyu");
        ob->map_skill("sword", "huashan-jianfa");
        ob->map_skill("blade", "liangyi-dao");
        
        ob->prepare_skill("cuff", "pishi-poyu");
        ob->prepare_skill("strike", "hunyuan-zhang");
	
	ob->set("default_weapon", "/clone/weapon/gangjian");

	break;
    case "emei":
	ob->set_skill("huifeng-jian", level);
	ob->set_skill("yanxing-dao", level);
	ob->set_skill("jinding-zhang", level);
	ob->set_skill("tiangang-zhi", level);
	ob->set_skill("linji-zhuang", level);
	ob->set_skill("zhutian-bu", level);

	ob->map_skill("force", "linji-zhuang");
	ob->map_skill("sword", "huifeng-jian");
	ob->map_skill("blade", "yanxing-dao");
	ob->map_skill("strike", "jinding-zhang");
	ob->map_skill("finger", "tiangang-zhi");
	ob->map_skill("dodge", "zhutian-bu");
	ob->map_skill("parry", "huifeng-jian");

        ob->prepare_skill("finger", "tiangang-zhi");
        ob->prepare_skill("strike", "jinding-zhang");
	ob->set("default_weapon", "/clone/weapon/gangdao");
	break;
    case "wudang":
        ob->set_skill("taiji-shengong", level);
        ob->set_skill("taiji-jian", level);
        ob->set_skill("tiyunzong", level);
	ob->set_skill("taiji-quan", level);
 
        ob->map_skill("force", "taiji-shengong");
        ob->map_skill("parry", "taiji-jian");
	ob->map_skill("cuff", "taiji-quan");
        ob->map_skill("dodge", "tiyunzong");
        ob->map_skill("sword", "taiji-jian");
        
        ob->prepare_skill("cuff", "taiji-quan");
	ob->set("default_weapon", "/clone/weapon/gangjian");
	break;
    case "shaolin":
        ob->set_skill("damo-jian", level);
        ob->set_skill("xiuluo-dao", level);
        ob->set_skill("wuchang-zhang", level);
        ob->set_skill("zui-gun", level);
        ob->set_skill("shaolin-shenfa", level);
        ob->set_skill("hunyuan-yiqi", level);
	ob->set_skill("yizhi-chan", level);
	ob->set_skill("banruo-zhang", level);
 
        ob->map_skill("force", "hunyuan-yiqi");
        ob->map_skill("dodge", "shaolin-shenfa");
        ob->map_skill("parry", "damo-jian");
        ob->map_skill("sword", "damo-jian");
        ob->map_skill("blade", "xiuluo-dao");
        ob->map_skill("club", "zui-gun");
        ob->map_skill("staff", "wuchang-zhang");
        ob->map_skill("finger", "yizhi-chan");
        ob->map_skill("strike", "banruo-zhang");
        
        ob->prepare_skill("finger", "yizhi-chan");
        ob->prepare_skill("strike", "banruo-zhang");
	ob->set("default_weapon", "/clone/weapon/gangjian");
	break;

    case "gaibang":
        ob->set_skill("liuhe-dao", level);
        ob->set_skill("xiaoyaoyou", level);
        ob->set_skill("huntian-qigong", level);
	ob->set_skill("shexing-diaoshou", level);
 
        ob->map_skill("force", "huntian-qigong");
        ob->map_skill("dodge", "xiaoyaoyou");
        ob->map_skill("parry", "liuhe-dao");
        ob->map_skill("blade", "liuhe-dao");
        ob->map_skill("hand", "shexing-diaoshou");
        
        ob->prepare_skill("hand", "shexing-diaoshou");
	ob->set("default_weapon", "/clone/weapon/gangdao");
	break;
    case "baituo":
        ob->set_skill("hamagong", level);
        ob->set_skill("lingshe-zhang", level);
	ob->set_skill("chanchubu", level);
	ob->set_skill("poison", level);
 
        ob->map_skill("force", "hamagong");
        ob->map_skill("dodge", "chanchubu");
        ob->map_skill("parry", "lingshe-zhang");
        ob->map_skill("strike", "hamagong");
        ob->map_skill("staff", "lingshe-zhang");
        
        ob->prepare_skill("strike", "hamagong");
	ob->set("default_weapon", "/clone/weapon/shezhang");
	break;

    case "taohua":
        ob->set_skill("bitao-xuangong", level);
        ob->set_skill("canglang-bian", level);
        ob->set_skill("luoying-shenfa", level);
	ob->set_skill("luoying-shenjian", level);
	ob->set_skill("xuanfeng-saoye", level);
	ob->set_skill("qimen-dunjia", level);
 
        ob->map_skill("force", "bitao-xuangong");
        ob->map_skill("dodge", "luoying-shenfa");
        ob->map_skill("parry", "canglang-bian");
        ob->map_skill("strike", "luoying-shenjian");
        ob->map_skill("kick", "xuanfeng-saoye");
        ob->map_skill("whip", "canglang-bian");
        
        ob->prepare_skill("strike", "luoying-shenjian");
        ob->prepare_skill("kick", "xuanfeng-saoye");
	ob->set("default_weapon", "/clone/weapon/changbian");
	break;

    case "xueshan":
        ob->set_skill("longxiang-banruo", level);
        ob->set_skill("xue-dao", level);
        ob->set_skill("jingang-chu", level);
	ob->set_skill("huoyan-dao", level);
	ob->set_skill("xueshitiao", level);
	ob->set_skill("mingwang-jian", level);
 
        ob->map_skill("force", "longxiang-banruo");
        ob->map_skill("dodge", "xueshitiao");
        ob->map_skill("parry", "xue-dao");
        ob->map_skill("blade", "xue-dao");
        ob->map_skill("sword", "mingwang-jian");
        ob->map_skill("strike", "huoyan-dao");
        ob->map_skill("staff", "jingang-chu");
        
        ob->prepare_skill("strike", "huoyan-dao");
	ob->set("default_weapon", "/clone/weapon/gangdao");
	break;

    case "xingxiu":
    default:
        ob->set_skill("huagong-dafa", level);
        ob->set_skill("zhaixinggong", level);
        ob->set_skill("chousui-zhang", level);
        ob->set_skill("sanyin-zhua", level);
        ob->set_skill("tianshan-zhang", level);
        ob->set_skill("poison", level);

	ob->map_skill("force", "huagong-dafa");
	ob->map_skill("strike", "chousui-zhang");
	ob->map_skill("claw", "sanyin-zhua");
	ob->map_skill("dodge", "zhaixinggong");
	ob->map_skill("parry", "sanyin-zhua");
	ob->map_skill("staff", "tianshan-zhang");

	ob->prepare_skill("strike", "chousui-zhang");
	ob->prepare_skill("claw", "sanyin-zhua");
	ob->set("default_weapon", "/clone/weapon/gangzhang");
	break;
    }
    return menpai;
}
