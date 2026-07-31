#include <ansi.h>
inherit NPC;
void create()
{
        set_name("小狄云", ({ "di yun", "di","yun" }));
        set("long","一个看上去老实巴交的男子。\n");
        set("title", HIW"连城诀"NOR);
        set("nickname","空心菜");
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
        set_skill("shenzhao-jing", 100);
        set_skill("dodge", 100);
        set_skill("yuxue-dunxing", 100);
        set_skill("claw", 100);
        set_skill("tianwang-zhua", 100);
        set_skill("hand", 100);
        set_skill("dashou-yin", 100);
        set_skill("blade",100);
        set_skill("xuedao-jing",100);
        set_skill("parry", 100 );

        map_skill("force", "shenzhao-jing");
        map_skill("dodge", "yuxue-dunxing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "xuedao-jing");
        map_skill("claw", "tianwang-zhua");
        map_skill("blade","xuedao-jing");
        prepare_skill("hand","dashou-yin");
        prepare_skill("claw","tianwang-zhua");              

        setup();
        carry_object(__DIR__"obj/xd")->wield();
        carry_object(__DIR__"obj/wcy")->wear();
        carry_object("/clone/medicine/badan");
        carry_object("/clone/medicine/jinchuang");
}
