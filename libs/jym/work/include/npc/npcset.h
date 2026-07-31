string set_npc(object ob, string menpai, int exp, int skill_rate);
int ob_menpai_newname(object ob, string menpai);

string set_npc(object ob, string menpai, int exp, int skill_rate)
{
	string *menpai_list = ({
    "huashan", "shaolin", "wudang", "emei", "gaibang", "lingjiu", "quanzhen",
    "baituo", "xueshan", "xingxiu", "taohua", "gumu", "shenlong", "dali"  });

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
		ob->set_skill("xianglong-zhang", level);
 
        ob->map_skill("force", "huntian-qigong");
        ob->map_skill("dodge", "xiaoyaoyou");
        ob->map_skill("parry", "liuhe-dao");
        ob->map_skill("blade", "liuhe-dao");
        ob->map_skill("hand", "shexing-diaoshou");
		ob->map_skill("strike", "xianglong-zhang");
        
        ob->prepare_skill("strike", "xianglong-zhang");
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
		ob->set("th_jianyi", 6);
 
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

    case "lingjiu":
		ob->set_skill("music",level);

		ob->set_skill("zhemei-shou",level);
		ob->set_skill("liuyang-zhang",level);
		ob->set_skill("tianyu-qijian",level);
		ob->set_skill("yueying-wubu",level);
		ob->set_skill("bahuang-gong", level);
		ob->set_skill("ruyi-dao", level);

		ob->map_skill("force", "bahuang-gong");
		ob->map_skill("strike","liuyang-zhang");
		ob->map_skill("dodge", "yueying-wubu");
		ob->map_skill("hand", "zhemei-shou");
		ob->map_skill("parry", "liuyang-zhang");
		ob->map_skill("sword", "tianyu-qijian");
		ob->map_skill("blade", "ruyi-dao");

		ob->prepare_skill("strike","liuyang-zhang");
		ob->prepare_skill("hand","zhemei-shou");
		ob->set("default_weapon", "/clone/weapon/gangdao");
	break;

    case "gumu":
        ob->set_skill("yunu-xinjing", level);
        ob->set_skill("meinu-quan", level);
        ob->set_skill("yunu-jianfa", level);
        ob->set_skill("suhan-zhi", level);
        ob->set_skill("feiyan-gong", level);
		ob->set_skill("bee-training",level);
		ob->set_skill("lovingness",level);
		ob->set_skill("suxin-jue",level);
		ob->set_skill("zuoyou-hubo",level);
		ob->set_skill("jueqing-bian",level);
		ob->set_skill("suhan-zhi",level);

        ob->map_skill("force", "yunu-xinjing");
        ob->map_skill("dodge", "feiyan-gong");
        ob->map_skill("cuff", "meinu-quan");
        ob->map_skill("parry", "yunu-jianfa");
        ob->map_skill("sword", "yunu-jianfa");

        ob->prepare_skill("cuff", "meinu-quan");
		ob->set("default_weapon", "/clone/weapon/gangjian");
	break;

    case "quanzhen":
		ob->set_skill("xiantian-gong", level);
		ob->set_skill("jinyangong", level);
		ob->set_skill("chunyang-quan", level);
		ob->set_skill("sanhua-juding", level);
		ob->set_skill("quanzhen-jian", level);
		ob->set_skill("taoism", level);

		ob->map_skill("force", "xiantian-gong");
		ob->map_skill("dodge", "jinyangong");
		ob->map_skill("cuff", "chunyang-quan");
		ob->map_skill("strike", "sanhua-juding");
		ob->map_skill("parry", "quanzhen-jian");
		ob->map_skill("sword", "quanzhen-jian");

		ob->prepare_skill("cuff", "chunyang-quan");
		ob->prepare_skill("strike", "sanhua-juding");
		ob->set("default_weapon", "/clone/weapon/gangjian");
		if ( level > 200 ) ob->set("shentong",65);
	break;

    case "shenlong":
 		ob->set_skill("dulong-dafa", level);
		ob->set_skill("lingshe-shenfa", level);
		ob->set_skill("huagu-mianzhang", level);
		ob->set_skill("medicine", level);
//		ob->set_skill("yingxiong-sanzhao", level);
		ob->set_skill("digging", level);
		ob->set_skill("jueming-tui", level);
		ob->set_skill("ruyi-gou", level);
		ob->set_skill("hook", level);

		ob->map_skill("force", "dulong-dafa");
		ob->map_skill("dodge", "lingshe-shenfa");
		ob->map_skill("strike", "huagu-mianzhang");
		ob->map_skill("parry", "ruyi-gou");
//		ob->map_skill("finger", "yingxiong-sanzhao");
		ob->map_skill("hook", "ruyi-gou");

		ob->prepare_skill("strike", "huagu-mianzhang");
		ob->prepare_skill("kick", "jueming-tui");
		ob->set("default_weapon", "/clone/weapon/hook");
	break;

    case "dali":
		ob->set_skill("buddhism", level);
		ob->set_skill("yiyang-zhi", level);
		ob->set_skill("duanjia-jian",level);
		ob->set_skill("duanshi-shenfa",level);
		ob->set_skill("kurong-changong",level);
		ob->set_skill("qingyan-zhang", level);
		ob->set_skill("jinyu-quan", level);

		ob->map_skill("cuff","jinyu-quan");
		ob->map_skill("sword","duanjia-jian");
		ob->map_skill("dodge","duanshi-shenfa");
		ob->map_skill("parry", "duanjia-jian");
		ob->map_skill("force","kurong-changong");
		ob->map_skill("strike","qingyan-zhang");
		ob->map_skill("finger","yiyang-zhi");

		ob->prepare_skill("finger","yiyang-zhi");
		ob->set("default_weapon", "/clone/weapon/gangjian");
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
	ob->set("menpai", menpai);
    return menpai;
}

int ob_menpai_newname(object ob, string menpai)
{
	string name, new_name, str;
	int me_force, x;
	string *em_names = ({ "文", "妙", "灵", "如" });
	string *sl_names = ({ "虚", "空", "明", "净" });
	string* th_m_names = ({
		"浩", "烈", "战", "神", "天", "英", "玉", "剑", "星", "蛟",
		"海", "寒", "流", "鹤", "朝", "空", "洛", "朗", "阳", "清",
		"梦", "闲", "苍", "朔", "幽", "灭", "若", "翔", "幻", "冥",
		"潜", "劫", "旭", "秋", "凯", "乐", "廷", "道", "阴", "御",
		"望", "狂", "穹", "定", "晴", "淳", "旋", "腾", "凰", "寻",
		"云",}); 

	string* th_f_names = ({
		"兰", "月", "采", "泠", "碧", "星", "虹", "雪", "海", "寒",
		"柔", "霜", "流", "鹤", "雁", "朝", "如", "清", "梦", "闲",
		"慧", "幽", "若", "幻", "冥", "馨", "沐", "秋", "乐", "岚",
		"御", "凝", "盼", "望", "湘", "盈", "慕", "琼", "纯", "扬",
		"舞", "凰", "诗", "飘", "韵", "琳", "涵", "云", "迎", "画",
		"遥",}); 
    
	switch (menpai){
		case "dali":
			name = ob->query("name");
		    new_name = "段" + name[2..3];
			if ( new_name ) ob->set("name", new_name);
			break;
		case "emei":
			name = ob->query("name");
		    if ((int)ob->query_skill("linji-zhuang", 1) < 90 ) 
				new_name = em_names[random(sizeof(em_names))] + name[0..1];
			else new_name = "静" + name[0..1];
			if ( new_name ) ob->set("name", new_name);
			ob->set("class", "bonze");
			break;
		case "taohua":
			name = ob->query("name");
			if( ob->query("gender") == "男性") str = th_m_names[random(sizeof(th_m_names))];
			else str = th_f_names[random(sizeof(th_f_names))];
			new_name = name[0..01] + str + "风";
			if ( new_name ) ob->set("name", new_name);
			break;
		case "quanzhen":
			name = ob->query("name");
			me_force = (int)ob->query_skill("xiantian-gong", 1);
			if ( me_force < 60 ) new_name = name[0..01]+ "净" + name[4..5];
			if ( me_force > 60 && me_force < 100 ) new_name = name[0..01]+ "清" + name[4..5];
			if ( me_force > 100 ) new_name = name[0..01]+ "志" + name[4..5];
			if ( new_name ) ob->set("name",new_name);
			ob->set("class", "taoist");
			break;
		case "xingxiu":
			if ((int)ob->query_skill("poison", 1) > 50)
			{
			name = ob->query("name");
			x=random(3);
            if (x==3)             	
                new_name =  name[0..01] + name[2..3] + "子";
            else if (x==2) 
				new_name =  name[2..3] + name[0..01] +  "子";
			else if (x==1)
				new_name =  name[0..01]+ "玄" + "子";
			else 
				new_name =  name[0..01]+ "凡" + "子";
	        if ( new_name ) ob->set("name", new_name);
			}
			break;
		case "shaolin":
			name = ob->query("name");
		    me_force = (int)ob->query_skill("hunyuan-yiqi", 1);
			if ( me_force < 60 ) new_name = sl_names[random(sizeof(sl_names))] + name[0..1];
			if ( me_force > 60 && me_force < 100 ) new_name = "清" + name[2..3];
			if ( me_force > 100 && me_force < 150 ) new_name = "慧" + name[2..3];
			if ( me_force > 150 && me_force < 190 ) new_name = "澄" + name[2..3];
			if ( me_force > 190 && me_force < 250 ) new_name = "玄" + name[2..3];
			if ( me_force > 250 ) new_name = "渡" + name[2..3];
			if ( new_name ) ob->set("name", new_name);
			break;
	}

	return 1;
}
