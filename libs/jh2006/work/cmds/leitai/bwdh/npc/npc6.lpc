#include <ansi.h>
inherit NPC;

void create()
{
        string weapon;
        set_name("小张无忌",({"zhang wuji","zhang","wuji"}));
        set("title",HIY"明教第三十四代教主"NOR);
        set("long", "他就是明教的第三十四代教主。脸上带着英资勃发的笑容。\n");
        set("age", 25);         
        set("attitude", "friendly");
        set("str", 28);
        set("int", 28);
        set("con", 30);
        set("dex", 29);
        set("per", 28);

        set("max_qi", 1500);
        set("max_jing", 1000);
        set("neili", 1500);
        set("eff_jingli", 1000);
        set("max_neili", 1500);
        set("jiali", 30);
        set("combat_exp", 400000);    
        set("unique", 1);

        set_skill("sword",100);
        set_skill("dodge",100);
        set_skill("force", 100);
        set_skill("blade",100);
        set_skill("piaoyi-shenfa", 100);
        set_skill("tiyunzong", 100);
        set_skill("shenghuo-lingfa", 100);
        set_skill("shenghuo-lingfa", 100);
        set_skill("lieyan-dao", 100);
        set_skill("liehuo-jian", 100);
        set_skill("taiji-jian", 100);
        set_skill("taiji-quan", 100);
        set_skill("parry", 100);
        set_skill("cuff", 100);
        set_skill("qiankun-danuoyi",100);
        set_skill("qishang-quan",100);
        set_skill("literate", 100);
        set_skill("medicine", 100);
        set_skill("shenghuo-shengong",100);
        map_skill("force", "shenghuo-shengong");
        map_skill("cuff","qishang-quan");
        map_skill("blade","shenghuo-lingfa");
        map_skill("sword","taiji-jian");
        map_skill("dodge", "tiyunzong");
        map_skill("parry", "qiankun-danuoyi");        
        prepare_skill("cuff","qishang-quan");        
      
        setup();        
        carry_object(__DIR__"obj/shl")->wield();
        carry_object("/d/mingjiao/obj/white-cloth")->wear(); 
        carry_object("/clone/medicine/jinchuang");
        carry_object("/clone/medicine/jinchuang");
}
