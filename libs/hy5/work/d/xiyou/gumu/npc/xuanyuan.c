//轩辕古墓终极师承 轩辕公
//by junhyun@SK
inherit NPC;
#include <ansi.h>
inherit F_MASTER;
string avenge();
void create()
{
        set_name("轩辕公", ({"xuanyuan gong", "xuanyuan", "gong","master","tianshen"}));
       set("long", "开天辟地之神，与女娲平起平坐，但因为
屡犯天规而得不到众仙的认同。
\n");
       set("title", HIW"开天辟地"NOR);
       set("color", HIR);
       set("gender", "男性");
       set("age", 20);
       set("class","xian");
       set("attitude", "friendly");
       set("rank_info/respect", "上尊");
       set("cor", 30);
       set("per", 40);
      set("looking", "仙风道骨，举止出尘。");
       set("max_kee", 6000);
       set("max_gin", 1000);
       set("max_sen", 6000);
       set("force", 4000);
       set("max_force", 2000);
       set("force_factor", 125);
       set("max_mana", 2000);
       set("mana", 4000);
       set("mana_factor", 100);
       set("combat_exp", 5000000);
      
create_family("轩辕古墓", 1, "红");
setup();


        
}

