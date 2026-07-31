//轩辕古墓终极师承 女娲
//by junhyun@SK
inherit NPC;
#include <ansi.h>
inherit F_MASTER;
string avenge();
void create()
{
       set_name(HIW"女娲"NOR, ({"nu wa", "nuwa", "nu","wa","master","tianshen"}));
       set("long", "天地之母，以身躯化作五彩石补天，
其举动感动上苍，封为天地智圣大慈天尊，后收妲己等九
天玄女，专伺辅佐天神。
\n");
       set("title", HIM"天地之母"NOR);
       set("gender", "女性");
       set("age", 20);
       set("class","xian");
       set("attitude", "friendly");
       set("rank_info/respect", "上尊");
       set("cor", 30);
       set("per", 40);
      set("looking", "轻若飘渺,虚无实幻。");
       set("max_kee", 6000);
       set("max_gin", 1000);
       set("max_sen", 6000);
       set("force", 12000);
       set("max_force", 6000);
       set("force_factor", 300);
       set("max_mana", 6000);
       set("mana", 12000);
       set("mana_factor", 400);
       set("combat_exp", 30000000);
       set("daoxing", 50000000);
     
create_family("轩辕古墓", 1, "红");
setup();



}

