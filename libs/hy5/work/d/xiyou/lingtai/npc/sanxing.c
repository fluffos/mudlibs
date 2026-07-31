//三星圣母
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
       set_name(HIW"三星圣母"NOR, ({"sanxing shengmu","sanxing", "master"}));
       set("long", "乾坤倒转。万妙无方\n");
       set("title", HIC"万妙无方"NOR);
       set("gender", "女性");
       set("age", 20);
        set("class", "taoist");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "圣母");
       set("per", 40);
        set("int", 30);
       set("max_kee", 5000);
       set("max_gin", 1000);
       set("max_sen", 5000);
       set("force", 5000);
       set("max_force", 2500);
    
create_family("方寸山三星洞", 1, "蓝");
setup();

        carry_object("/d/xiyou/lingtai/obj/pao")->wear();
        carry_object("/d/xiyou/lingtai/obj/shoe")->wear();
        carry_object("/d/xiyou/lingtai/obj/longxingjian")->wield();
}

