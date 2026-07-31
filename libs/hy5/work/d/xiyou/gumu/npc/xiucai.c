//轩辕古墓三代师傅
inherit NPC;
inherit F_SAVE;  
#include <ansi.h>
inherit F_MASTER;
int rank_me();
#include <ansi.h>

void create()
{
       set_name("林秀才", ({"lin xiucai", "lin", "xiucai","master"}));
       set("long",
"一只修炼百年成精的小狐仙，变成人后醉心功名利禄，
可惜屡考不中，只弄个秀才的头名。\n");
       set("title", "小狐仙");
       set("gender", "男性");
       set("age", 28);
       set("class", "yaomo");
       set("attitude", "friendly");
       set("rank_info/respect", "先生");
       set("per", 40);
        set("int", 30);
       set("max_kee", 500);
       set("max_gin", 500);
       set("force", 500);
       set("max_force", 500); 
       set("force_factor", 20);
       set("max_mana", 300);
       set("mana", 300);
       set("mana_factor", 20);
       set("combat_exp", 200000);
  set("daoxing", 100000);


        set("eff_dx", 70000);
        set("nkgain", 260);

create_family("轩辕古墓", 3, "弟子");
setup();

        carry_object("/d/obj/cloth/baipao")->wear();
      //  carry_object("/d/moon/obj/guihuajian")->wield();
}

