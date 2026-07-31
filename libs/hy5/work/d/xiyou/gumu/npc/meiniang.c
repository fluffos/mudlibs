//轩辕古墓三代师傅
inherit NPC;
inherit F_SAVE; 
#include <ansi.h>
inherit F_MASTER;
int rank_me();
#include <ansi.h>

void create()
{
       set_name("胡媚娘", ({"hu meiniang", "hu", "meiniang","master"}));
       set("long",
"原本是一只小狐狸，修炼百年后，终于化成人形\n");
       set("title", "小狐狸精");
       set("gender", "女性");
       set("age", 18);
       set("class", "yaomo");
       set("attitude", "friendly");
       set("rank_info/respect", "姐姐");
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

        
      //  carry_object("/d/moon/obj/guihuajian")->wield();
}

