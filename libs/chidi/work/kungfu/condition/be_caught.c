// be_caught.c
// by QingP

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 1) {
		me->move("/d/xingxiu/riyuedong");
		message("vision",
			HIY "只听乒地一声，你吓了一跳，定睛一看，\n"
			"原来是一个昏昏沉沉的家伙被星宿弟子架了进来！\n" NOR, environment(me), me);
		tell_object(me, HIY "星宿弟子说道：今日老仙开恩，广收门徒，还不快快拜入星宿门下，更待何时。\n" NOR);
		me->set("startroom", "/d/city/kedian");
		return 0;
	}

	me->apply_condition("be_caught", duration - 1);
	
	return 1;
}