// yue_buqun.c 岳不群
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("小岳不群",({"yue buqun", "yue", "buqun" }));
        set("title","华山派第十三代掌门人");
        set("nickname","君子剑");
        set("long", "这就是在江湖中侠名远播，疾恶如仇，华山派掌门人。\n");
        set("age", 40);
        set("attitude", "peaceful");

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        
        set("max_qi", 1500);
        set("max_jing", 1000);
        set("neili", 1500);
        set("eff_jingli", 1000);
        set("max_neili", 1500);
        set("jiali", 30);
        set("combat_exp", 400000); 
        set("unique", 1);

        set_skill("strike", 100);
        set_skill("hunyuan-zhang", 100);
        set_skill("sword",  100);
        set_skill("dodge",  100);
        set_skill("force",  100);
        set_skill("parry",  100);
        set_skill("literate",100);
        set_skill("zixia-gong", 100);
        set_skill("huashan-jianfa",  100);
        set_skill("huashan-shenfa",  100);
        set_skill("ziyin-yin", 100);
        set_skill("zhengqi-jue", 100);

        map_skill("dodge", "huashan-shenfa");
        map_skill("force","zixia-gong");
        map_skill("sword","huashan-jianfa");
        map_skill("parry","huashan-jianfa");
        map_skill("strike","hunyuan-zhang");
        prepare_skill("strike","hunyuan-zhang");

        setup();
        carry_object(__DIR__"obj/bsj")->wield();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/medicine/badan");
}
