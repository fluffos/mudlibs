#include <login.h>
#include <ansi.h>
int update_condition(object me, int duration)
{
 int  drunkduration;
object ob;
drunkduration=(me->query("con") + (int)me->query("max_neili") / 50) * 2-1;
if(random(6)>4&&!me->query_skill("zui-quan")&&me->is_fighting()&&me->query_skill("cuff",1)>=100&&me->query_int()>=45)
me->set_skill("zui-quan",1);
if(random(3)>0) me->start_busy(1);
if(me->query_skill("zui-quan",1)&&random(6)>3&&me->is_fighting()&&me->query_skill("cuff",1)>=100&&me->query_int()>=45&&me->query_skill("cuff",1)>me->query_skill("zui-quan",1))
 {
 write(HIR"你在冥冥之中突然领悟到一些醉拳中形醉意不醉的道理！\n"+BNK"你觉得自己在醉拳方面的造诣有所进步！\n"NOR);
me->improve_skill("zui-quan",random(me->query("int"))+me->query("dex"));
}
        if (duration < 1)
             {
me->add("wannianzui",1);
write(HIY"你体内万年醉的酒力渐渐散去，你觉得身体无比舒畅！\n"NOR);
if(me->query("wannianzui")>19)
{
 write(HIR"你回味醉中步法，突然感到身轻如燕，冥冥之中感觉到你的身法有所提高！\n"NOR);
me->set("wannianzui",0);
me->add_temp("dex",1);
log_file("wiz/edit", "万年醉加点:"+me->query("id"));
me->add("xiantian/dex/wannianzui", 1);
}
              return 0;
             }
        me->apply_condition("wannianzui", duration - 1);
        me->apply_condition("drunk",drunkduration);
        return 1;
}
