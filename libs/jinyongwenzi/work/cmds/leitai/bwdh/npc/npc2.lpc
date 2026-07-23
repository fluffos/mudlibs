// daerba.c 达尔巴
// by iceland
#include <ansi.h>

inherit NPC;

void create()
{        
        set_name("小达尔巴", ({ "daer ba", "daerba" ,"daer","ba"}));
        set("long",@LONG
他是金轮法王座下二弟子，看起来身材削瘦，神情木讷，脑筋不大灵便。
他双臂却骨节突出，双手巨大，天生神力。
LONG
        );
        set("title", HIY"大轮寺金轮法王座下弟子" NOR);
        set("gender", "男性");
        set("class", "huanxi");
        set("age", 45);
        set("attitude", "heroism");

        set("str", 50);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per", 8);

        set("max_qi", 1500);
        set("max_jing", 1000);
        set("neili", 1500);
        set("eff_jingli", 1000);
        set("max_neili", 1500);
        set("jiali", 30);
        set("combat_exp", 400000); 
        set("unique", 1);

        set_skill("huanxi-chan", 100);
        set_skill("literate", 100);
        set_skill("force", 100);
        set_skill("longxiang-boruo", 100);
        set_skill("dodge", 100);
        set_skill("yuxue-dunxing", 100);
        set_skill("staff", 100);
        set_skill("wushang-dali", 100);
        set_skill("hand", 100);
        set_skill("dashou-yin", 100);
        set_skill("parry", 100 );

        map_skill("force", "longxiang-boruo");
        map_skill("dodge", "yuxue-dunxing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "wushang-dali");
        map_skill("staff", "wushang-dali");
        prepare_skill("hand","dashou-yin");

        set("class", "huanxi");

        setup();
        carry_object("/d/xueshan/npc/obj/changsheng-jiasha")->wear();
        carry_object(__DIR__"obj/jgxmc")->wield();
        carry_object("/d/shaolin/obj/sengxie")->wear();
        carry_object("/clone/medicine/jinchuang");
        carry_object("/clone/medicine/jinchuang");
        carry_object("/clone/medicine/jinchuang");        
}
