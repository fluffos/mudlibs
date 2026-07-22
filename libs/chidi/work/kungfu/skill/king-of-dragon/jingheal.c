// jingheal.c
#include <ansi.h>
int exert(object me, object target) {
	if((int)me->query_skill("king-of-dragon", 1) < 500) {
		return notify_fail("你对君临天下神功的了解不够，还不能使用它为别人疗伤。\n");
	}
    if( !target )
        return notify_fail("你要用真气为谁疗伤？\n");
    message_vision(
        HIY "$N坐了下来运起内功，将手掌贴在$n背心，缓缓地将真气输入$n体内....\n\n"
        "过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。\n" NOR,
        me, target );
    target->set("eff_jing", target->query("max_jing"));
    target->set("jing",target->query("max_jing"));
    return 1;
}
