#include <ansi.h>
inherit NPC;
void create()
{
        set_name("小夏雪宜", ({ "xia xueyi", "xia","xueyi" }));
        set("long","他静静地站在那里，仿佛有很多心事。\n");        
        set("title",HIY"金蛇郎君"NOR);
        set("gender", "男性");        
        set("age", 35);
        set("attitude", "friendly");
        
        set("str", 35);
        set("int", 30);
        set("con", 35);
        set("dex", 35);

        set("max_qi", 1500);
        set("max_jing", 1000);
        set("neili", 1500);
        set("eff_jingli", 1000);
        set("max_neili", 1500);
        set("jiali", 30);
        set("combat_exp", 400000);    
        set("unique", 1);
        
        set_skill("literate", 100);
        set_skill("force", 100);
        set_skill("zixia-gong", 100);
        set_skill("dodge", 100);
        set_skill("huashan-shenfa", 100);
        set_skill("strike", 100);
        set_skill("jinshe-zhangfa", 100);
        set_skill("throwing", 100);
//        set_skill("jinshe-zhuifa", 100);
        set_skill("sword",100);
        set_skill("jinshe-jianfa",100);
        set_skill("parry", 100 );

        map_skill("force", "zixia-gong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("throwing", "jinshe-zhuifa");
        map_skill("parry", "jinshe-jianfa");
        map_skill("strike", "jinshe-zhangfa");
        map_skill("sword","jinshe-jianfa");        
        prepare_skill("strike", "jinshe-zhangfa");              

        setup();
        carry_object(__DIR__"obj/jsj")->wield();
        carry_object(__DIR__"obj/jsz");
        carry_object(__DIR__"obj/jsz");
        carry_object("/d/gumu/obj/pao1")->wear();
        carry_object("/clone/medicine/badan");
        carry_object("/clone/medicine/jinchuang");
}
