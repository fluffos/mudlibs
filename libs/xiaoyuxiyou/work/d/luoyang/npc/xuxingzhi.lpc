//xuzingzhi.c
inherit NPC;
#include <ansi.h>

void create()
{
       set_name("虚行之", ({"xu xingzhi", "xu","master"}));
       set("long","原海沙帮军师,寇仲与海沙帮主一战之后与其帮众,跟随寇仲建立少帅军，忠心不二一心辅助寇仲争霸天下。\n");
       set("gender", "男性");
       set("age", 30);
       set("class", "fighter");
       set("attitude", "friendly");
       set("rank_info/respect", "先生");
       set_level(39);
       set("force_factor", 20);
       set("mana_factor", 40);
       set("eff_dx", 800000);
       set("nkgain", 350);
       set_skill("literate", 80);
       set_skill("unarmed", 80);
       set_skill("dodge", 80);
       set_skill("force", 80);
       set_skill("parry", 80);
       set_skill("sword", 80);
       set_skill("spells", 80);
       set_skill("pansi-dafa", 100);
       set_skill("lanhua-shou", 100);
       set_skill("jiuyin-xinjing", 100);
       set_skill("qingxia-jian", 100);
       set_skill("yueying-wubu", 100);
       set_skill("yinsuo-jinling", 150);
       map_skill("spells", "pansi-dafa");
       map_skill("unarmed", "lanhua-shou");
       map_skill("force", "jiuyin-xinjing");
       map_skill("sword", "qingxia-jian");
       map_skill("parry", "qingxia-jian");
       map_skill("dodge", "yueying-wubu");
   	
	create_family2("将军府","少帅军", 3,HIR"军师"NOR);
setup();

        carry_object("/d/obj/armor/tongjia")->wear();
          carry_object("/d/obj/weapon/sword/qinghong")->wield();
}
