int set_gumu_npc (int level,object ob)
{  
       
        ob->set("gender","女性");
        ob->set_skill("force",level);
        ob->set_skill("yunu-xinfa",level);
        ob->set_skill("yunu-xinjing",level);
        ob->set_skill("literate",level);
        ob->set_skill("meinu-quanfa",level);
        ob->set_skill("tianluo-diwang",level);
        ob->set_skill("sword",level);
        ob->set_skill("yunu-jianfa",level);
        ob->set_skill("unarmed",level);
        ob->set_skill("dodge",level);
        ob->set_skill("yufeng-shu",level);
        ob->set_skill("whip",level);
        ob->set_skill("yinsuo-jinling",level);
        ob->set_skill("xianyun-bufa",level);
        ob->set_skill("throwing",level);
        ob->set_skill("parry",level);
        ob->map_skill("force","yunu-xinjing");
        ob->map_skill("unarmed","meinu-quanfa");
        ob->map_skill("sword","yunu-jianfa");
        ob->map_skill("dodge","xianyun-bufa");
        ob->map_skill("parry","yunu-jianfa");
        ob->map_skill("whip","yinsuo-jinling");
        ob->carry_object("/clone/weapon/changjian")->wield();
       
}


int set_emei_npc(int level,object ob)
{  
        ob->set("gender","女性");
        ob->set_skill("force", level);
        ob->set_skill("dodge", level);
        ob->set_skill("blade", level);
        ob->set_skill("unarmed",level);
        ob->set_skill("parry", level);
        ob->set_skill("sword", level);
        ob->set_skill("linji-zhuang",level);
        ob->set_skill("jinding-zhang",level);
        ob->set_skill("huifeng-jian",level);
        ob->set_skill("yanxing-dao", level);
        ob->set_skill("tiangang-zhi", level);
        ob->set_skill("zhutian-bu",level);
        ob->set_skill("yugalism", level);
        ob->set_skill("dushi-jiren",level);
        ob->set_skill("literate", level);
        ob->map_skill("dodge","zhutian-bu");
        ob->map_skill("parry", "huifeng-jian");
        ob->map_skill("sword", "huifeng-jian");
        ob->map_skill("force","linji-zhuang");
        ob->map_skill("unarmed","tiangang-zhi");
        ob->map_skill("blade","yanxing-dao");
        ob->prepare_skill("strike", "jinding-zhang");
        ob->prepare_skill("unarmed", "tiangang-zhi");
        ob->carry_object("/clone/weapon/changjian")->wield();
}



int set_yihua_npc(int level,object ob)
{
        ob->set("gender","女性");
        ob->set_skill("force", level);
        ob->set_skill("unarmed", level);
        ob->set_skill("dodge", level);
        ob->set_skill("parry", level);
        ob->set_skill("sword",level);
        ob->set_skill("literate", level);

        ob->set_skill("jueqing-zhang",level);
        ob->set_skill("mingyu-shengong",level);
        ob->set_skill("yifeng-jian",level);
        ob->set_skill("yihua-jiemu",level);

        ob->map_skill("force", "mingyu-shengong");
        ob->map_skill("unarmed", "jueqing-zhang");
                ob->map_skill("dodge", "yihua-jiemu");
        ob->map_skill("parry", "yihua-jiemu");
        ob->map_skill("sword","yifeng-jian");
        ob->carry_object("/clone/weapon/changjian")->wield();
}


int set_wudang_npc(int level,object ob)
{
        ob->set("gender","男性");
      ob->set_skill("force", level);
    ob->set_skill("taiji-shengong", level);
    ob->set_skill("dodge", level);
    ob->set_skill("tiyunzong", level);
    ob->set_skill("unarmed", level);
    ob->set_skill("taiji-quan", level);
    ob->set_skill("parry", level);
    ob->set_skill("sword", level);
    ob->set_skill("taiji-jian", level);
    ob->set_skill("blade", level);
    ob->set_skill("taiji-dao", level);
    ob->set_skill("taoism", level);
    ob->set_skill("literate", level);
    ob->map_skill("force", "taiji-shengong");
    ob->map_skill("dodge", "tiyunzong");
    ob->map_skill("unarmed", "taiji-quan");
    ob->map_skill("parry", "taiji-jian");
    ob->map_skill("sword", "taiji-jian");
    ob->map_skill("blade", "taiji-dao");
    ob->carry_object("/clone/weapon/changjian")->wield();
              
}


int set_shaolin_npc(int level,object ob)
{
        ob->set_skill("force", level);
    ob->set_skill("buddhism-force", level);
    ob->set_skill("dodge", level);
    ob->set_skill("shaolin-shenfa", level);
    ob->set_skill("unarmed", level);
    ob->set_skill("sword", level);
    ob->set_skill("parry", level);
    ob->set_skill("shaolin-shenfa", level);
    ob->set_skill("damo-jian", level);
    ob->set_skill("jingang-quan", level);
    ob->set_skill("buddhism", level);
    ob->set_skill("literate", level);
    ob->map_skill("force", "buddhism-force");
    ob->map_skill("dodge", "shaolin-shenfa");
    ob->map_skill("unarmed", "jingang-quan");
    ob->map_skill("parry", "jingang-quan");
    ob->map_skill("sword", "damo-jian");
    ob->carry_object("/clone/weapon/changjian")->wield();
   
}

int set_baituo_npc(int level,object ob)
{
        ob->set("gender","男性");
        ob->set_skill("force", level);
        ob->set_skill("unarmed", level);
        ob->set_skill("dodge", level);
        ob->set_skill("parry", level);        
        ob->set_skill("hand",level);
        ob->set_skill("staff", level);
        ob->set_skill("hamagong", level);
        ob->set_skill("shexing-diaoshou", level);
        ob->set_skill("lingshe-zhangfa", level);
        ob->map_skill("force", "hamagong");
        ob->map_skill("dodge", "chanchu-bufa");
        ob->map_skill("unarmed", "shexing-diaoshou");
        ob->map_skill("parry", "lingshe-zhangfa");
        ob->map_skill("staff", "lingshe-zhangfa");
        ob->carry_object("/clone/weapon/gangzhang")->wield();

       
}


int set_huashan_npc(int level,object ob)

{
        ob->set("gender","男性");

        ob->set_skill("force", level);
        ob->set_skill("dodge", level);
        ob->set_skill("parry", level);
        ob->set_skill("sword", level);
        ob->set_skill("unarmed", level);
        ob->set_skill("zixia-shengong", level);
        ob->set_skill("huashan-jianfa", level);
        ob->set_skill("huashan-shenfa", level);
        ob->set_skill("hunyuan-zhang", level);
        ob->map_skill("dodge", "huashan-shenfa");
        ob->map_skill("force", "zixia-shengong");
        ob->map_skill("parry", "huashan-jianfa");
        ob->map_skill("sword", "huashan-jianfa");
        ob->prepare_skill("unarmed", "hunyuan-zhang");
        ob->carry_object("/clone/weapon/changjian")->wield();

}

int set_xingxiu_npc(int level,object ob)
{
        ob->set("gender","男性");
        ob->set_skill("force", level);
        ob->set_skill("huagong-dafa", level);
        ob->set_skill("dodge", level);
        ob->set_skill("zhaixinggong", level);
        ob->set_skill("unarmed", level);
        ob->set_skill("xingxiu-duzhang", level);
        ob->set_skill("staff", level);
        ob->set_skill("tianshan-zhang", level);
        ob->set_skill("literate", level);

        ob->map_skill("force", "huagong-dafa");
        ob->map_skill("dodge", "zhaixinggong");
        ob->map_skill("unarmed", "xingxiu-duzhang");
        ob->map_skill("parry", "tianshan-zhang");
        ob->map_skill("staff", "tianshan-zhang");
        ob->carry_object("/clone/weapon/gangzhang")->wield();
}

int set_xueshan_npc(int level,object ob)
{
        ob->set("gender","男性");
        ob->set_skill("force", level);
        ob->set_skill("longxiang", level);
        ob->set_skill("dodge",level);
        ob->set_skill("shenkong-xing", level);
        ob->set_skill("unarmed", level);
        ob->set_skill("yujiamu-quan", level);
        ob->set_skill("parry",level);
        ob->set_skill("hammer",level);
        ob->set_skill("riyue-lun", level );

        ob->map_skill("force", "xiaowuxiang");
        ob->map_skill("dodge", "shenkong-xing");
        ob->map_skill("unarmed", "yujiamu-quan");
        ob->map_skill("parry", "riyue-lun");
        ob->map_skill("hammer", "riyue-lun");
        ob->carry_object("/clone/weapon/hammer")->wield();

       
}


