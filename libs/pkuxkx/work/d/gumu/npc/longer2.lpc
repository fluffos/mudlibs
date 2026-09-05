// longer.c 小龙女
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void heal();
void create()
{
        set_name("小龙女", ({ "xiao longnu","longnu" }));
        set("nickname", "");
          set("title",HIR "古墓派" NOR + GRN +"传人" NOR);
        set("long",
                "她就是古墓派第三代传人小龙女，她是神雕大侠扬过的妻子。\n"
                "她容颜极美，只是脸上稍带白色。\n");
        set("gender", "女性");
        set("age", 32);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 18);
        set("int", 28);
        set("con", 20);
        set("dex", 50);
        set("per", 50);
        set("max_qi", 3000);
        set("max_jing", 3000);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 100);
        set("combat_exp", 2000000);
        set("score", 100000);

       
        set_skill("force", 180);
        set_skill("yunu-xinfa", 180);
        set_skill("dodge", 200);
        set_skill("xianyun", 200);
        set_skill("cuff", 180);
        set_skill("meinu", 180);
        set_skill("parry", 180);
        set_skill("whip", 180);
        set_skill("chang", 180);
        set_skill("literate", 100);
	set_skill("sword",180);
	set_skill("mintian-jiushi",200);
        map_skill("force", "yunu-xinfa");
        map_skill("dodge", "xianyun");
        map_skill("cuff", "meinu");
	map_skill("sword","mintian-jiushi");
        map_skill("parry", "chang");
        map_skill("whip", "chang");
        prepare_skill("cuff", "meinu");
        create_family("古墓派", 3, "传人");
        setup();
        carry_object("/u/lianxing/gumu/obj/sword1")->wield();
        carry_object("/u/lianxing/gumu/obj/white")->wear();
}
void heal()


{
        object ob=this_object();
        
        if (ob->query("eff_qi") < ob->query("max_qi"))
        {
                command("exert heal");
                command("enforce 100");
                return;
        }

        if (ob->query("qi") < ob->query("eff_qi"))
 {
                command("exert recover");
                return;
        }

        if (ob->query("jing") < ob->query("eff_jing"))
{         command("exert regenerate");

        return;}
}



