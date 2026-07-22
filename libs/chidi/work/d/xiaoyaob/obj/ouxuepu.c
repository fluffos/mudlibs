// lankepu.c 呕血谱
// keinxin 2003.3
inherit ITEM;
#include <ansi.h>;
void create()
{
        set_name(RED"呕血谱"NOR, ({ "ouxue pu", "shu", "pu"}));
        set_weight(300);
        if( clonep() )
            set_default_object(__FILE__);
        else {
            set("unit", "本");
            set("long","一本"RED"呕血谱"NOR"，记载的是精妙的围棋对局。
功能："HIC"琴棋书画(50--100)"NOR"\n");
            set("value", 400);
            set("material", "paper");
            set("skill", ([
            "name": "art",    // name of the skill
            "exp_required": 1000, // minimum combat experience required
            "jing_cost":    15,// jing cost every time study this
            "difficulty":  30,// the base int to learn this skill
            "max_skill":  100,// the maximum level you can learn to
            "min_skill":  50,// minimun level required
            ]) );
        }
}
