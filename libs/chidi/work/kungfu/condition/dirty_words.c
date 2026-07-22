// zhongkui_qiushi.c
#include <condition.h>
#include <ansi.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{


     if (duration < 1) {
         message("channel:rumor",sprintf(HIM"【谣言】某人：据说%s(%s)服刑欺满，被从流氓牢房里放出来了。\n"NOR,
         me->query("name"),me->query("id")),users());
         if (file_name(environment(me))=="/d/death/qiushi"){
         tell_object(me, HIY "你只觉一阵腾云驾雾般被扔出了地狱囚室！原来已经获得释放！恭喜！恭喜！\n\n" NOR);
         me->move("/d/city/wumiao");
         message("vision",HIY "突然一个家伙从天上掉了下来，原来是获得释放的"+me->query("name")+HIY"！\n" NOR, environment(me), me);
         }
         me->set("startroom", "/d/city/wumiao");
         me->save();
         return 0;
	 }

     if (!wizardp(me) && file_name(environment(me)) !="/d/death/qiushi") {
         tell_object(me,HIC"四扇门高手出现在你眼前：“你的牢还没坐完呢！快乖乖的给我滚回去！”\n\n\n"NOR);
         message_vision(HIC"四扇门高手突然出现，一甩索套，套住$N的脖子拉了就走。\n\n\n"NOR,me);
         me->move("/d/death/qiushi");
         }

     me->apply_condition("dirty_words", duration - 1);
     return 1;
}
