#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name(GRN "蛇杖" NOR, ({"she zhang", "zhang","staff"}));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "一根曲折盘旋的" + GRN "蛇杖" NOR + "\n");
                set("value", 10000);
                set("material", "bamboo");
                set("wield_msg", "$N抽出一根曲折盘旋的" + GRN "蛇杖" NOR + "抓在手中。\n");
                set("unwield_msg", "$N把手中的" + GRN "蛇杖" NOR + "插回腰中。\n");
        }
   init_staff(80);
        setup();
}       
void init()
{
        add_action("convert","convert");
}

int convert(string arg)
{
        object me = this_player();
        object ob;

        if (arg!="shezhang" && arg!="staff" && arg!="zhang") return 0;
        if (me->query("family/family_name") != "白驼山") 
                return notify_fail("你不能化杖为蛇。\n");
        if ((int)me->query("jing") < 100)
                return notify_fail("你的精力不够。\n");
	if (!present("she zhang", me)) 
		return notify_fail("你身上没有蛇杖。\n");

        if (random(me->query_skill("training",1)) <20) {
        message_vision("$N手握蛇杖手舞足蹈，好像发疯一般。\n"
                ,me);
		me->receive_damage("jing", 95);
                return 1;
        }
        message_vision("$N手握蛇杖手舞足蹈，猛地往地上一摔，将蛇杖化为一条毒蛇。\n",
                me,);
                ob = new("/d/xingxiu/npc/snake");
                 me->receive_damage("jing", 95);
        ob->move(environment(me));
        destruct(this_object());
        return 1;
}
