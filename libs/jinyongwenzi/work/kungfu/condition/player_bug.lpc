// mj_tasting.c

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
        if (duration < 1) {
		tell_object(me, HIY "忽然你觉得轻飘飘,你似乎被人提到了一个神秘的地方。\n" NOR); 
                me->move("/u/dubei/sg");
                return 0;
	}
        if (!duration) return 0;
        me->apply_condition("player_bug", duration - 1);
        return 1;
}
