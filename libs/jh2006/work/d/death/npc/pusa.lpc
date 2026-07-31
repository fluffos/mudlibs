#include <ansi.h>
#include <command.h>
#include <login.h>

inherit NPC;

string *death_msg = ({
        HIY "地藏王菩萨念道：阿弥陀佛！\n\n" NOR,
        HIY "地藏王菩萨伸出一只手，发出无限光芒，按在$n的顶门之上。\n\n" NOR,
        HIY "地藏王菩萨轻叹一声：汝虽为佛门弟子，却要遭受如此苦难，只因因果如此，善哉！善哉！\n\n" NOR,
        HIY "地藏王菩萨道：汝当一心向佛，历十纪灾难，才能超脱苦海，终成正果！\n\n" NOR,
	HIY "地藏王菩萨叹道：佛曰“我不入地狱，谁入地狱？”，你走吧，去偿还那前世的孽债。\n\n"
                HIW"$n觉得自己的意识越来越弱，渐渐不省人事了。。。\n\n" NOR,
});

void create()
{
        set_name("地藏王菩萨", ({ "dizangwang pusa", "pusa", "budda" }) );
        set("title",  HIY"阴间轮回王"NOR );
        set("long", "你低头埋首，无法看清他的宝象。\n");
        set("attitude", "peaceful");
        set("chat_chance", 5);
        set("chat_msg", ({ 
"大殿中响起一阵：“阿弥陀佛”的声音。\n",
"又走进来几名厉鬼，都双手合十，跪在地上。\n",
        }) );
        set("age", 300000);
        set("combat_exp", 200000);
        set("max_jing", 1000);
        set("max_qi", 1000);
        setup();
}

#include "death.h";
