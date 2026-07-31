// 此程序采自xkx老版本makelove.c 现已完全修改成鹿鼎记版本，呵呵
// makelove.c Modify By linux 1999-2000
// makelove.c add baby By 心有些乱(linux) 2000

#include <ansi.h>
void over(object,object);
void over1(object,object);
void over2(object,object);
void over3(object,object);
void over4(object,object);

int main(object me, string arg)
{
        object obj;
        object *ob;

        int i;

        if(!arg || !objectp(obj = present(arg, environment(me))))
                return notify_fail("你想和谁做爱？\n");

        if( !obj->is_character()||me->query("gender")==obj->query("gender") )
                return notify_fail("这样...？！恐怕不行吧？\n");

        if(!living(obj))
                return notify_fail("人家都这样了，你还...\n");

	if( me->is_busy() )
	return notify_fail("( 你上一个动作还没有完成。)\n");
	if( me->is_busy() )
	return notify_fail("( 你上一个动作还没有完成。)\n");

        if( me->query("gender") =="无性" )
                return notify_fail("你一个太监，也想干那事啊？？那不是搞笑吗？\n");

        if( obj->query_condition("huaiyun") > 0)
                return notify_fail("搞笑啊？孕妇要注意宝宝安全，怎么能这样？忍一忍拉！\n");

        if( me->query_condition("huaiyun") > 0)
                return notify_fail("搞笑啊？孕妇要注意宝宝安全，怎么能这样？忍一忍拉！\n");

        if( !environment(me)->query("sleep_room")||
                environment(me)->query("no_sleep_room"))
                return notify_fail("总得找个温馨点儿的地方吧。\n");

	if( me->is_busy() )
	return notify_fail("( 你上一个动作还没有完成。)\n");
	if( me->is_busy() )
	return notify_fail("( 你上一个动作还没有完成。)\n");
	if( me->is_busy() )
	return notify_fail("( 你上一个动作还没有完成。)\n");
	if( me->is_busy() )
	return notify_fail("( 你上一个动作还没有完成。)\n");

        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++)
                if( ob[i]->is_character()&&ob[i]!=me
                        &&ob[i]!=obj&&!wizardp(ob[i]) )
                        return notify_fail("这儿还有别人呢，多不好意思呀！\n");
        if(!me->query_temp("makelove/quest")) {
                if((me->query("gender")=="男性")) {
                        message_vision(YEL "$N轻轻的注视着$n，双手搂在$n的小蛮腰，\n轻柔的吻着$n的小耳垂....\n"NOR,me,obj);
                        tell_object(obj, HIR "看起来他想和你共度良宵，\n如果你愿意，请你也对" + me->name() + "("+(string)me->query("id")+")"+ "下一次 makelove 指令。\n" NOR);
                }
                else {
                        message_vision(YEL "$N的小脸儿红扑扑的，缠上来勾住$n的脖子，胸前紧紧的贴着$n的\n胸膛，小嘴嘟嘟的凑上来轻轻的吻着$n的嘴唇....\n"NOR,me,obj);
                        tell_object(obj, HIR "傻子也能看出来她想和你共渡良宵，\n如果你愿意，请你也对" + me->name() + "("+(string)me->query("id")+")"+ "下一次 makelove 指令。\n" NOR);
                }
                obj->set_temp("makelove/quest",1);

        }
        else {
                if((me->query("gender")=="男性")) {
                        message_vision(YEL "$N过了好半响，实在受不了$n的挑逗\n突然一把将$n紧紧抱住压在床上....\n"NOR,me,obj);
                        call_out("over", 1, me,obj);
                }
                else {
                        message_vision(YEL "$N极力的忍受着$n火热的挑逗，心头小鹿撞击不停，\n终于瘫软在$n的怀里，被$n一把横抱了起来，轻柔的放在床上....\n"NOR,me,obj);
                        call_out("over", 3, obj,me);
                }
                me->delete_temp("makelove/quest");
        }


        return 1;
}


void over(object me,object obj)
{
        message_vision(HIB"...屋里的"+HIR"红烛"+HIB"被吹灭了...\n"NOR,me);
        if(me->query("qi")<30||me->query("jing")<30||obj->query("qi")<30||obj->query("jing")<30)
        {
                if(me->query("qi")<30||me->query("jing")<30) {
                        message_vision(HIR "$N突然口吐鲜血，晕倒在地。看来是纵欲过度了。\n"NOR,me);
                        me->unconcious();
                          me->add("makeloved",1);
                          obj->add("makeloved",1);
                }
                else {
                        message_vision(HIR "$N突然口吐鲜血，晕倒在地。看来是纵欲过度了。\n"NOR,obj);
                        obj->unconcious();
                          obj->add("makeloved",1);
                          me->add("makeloved",1);
                }
        }
        else
        switch(random(10)) {
                case 0:
                        message_vision(HIR "$N突然大叫一声，显然是极度兴奋，紧接着竟晕死过去！\n"NOR,me);
                        me->unconcious();
                        obj->add("qi",obj->query_str()-55+random(10));
                        obj->add("jing",obj->query_con()-55+random(10));
                          obj->add("makeloved",1);
                          me->add("makeloved",1);
                        break;
                case 1:
                        message_vision(HIR "$N突然大叫一声，显然是极度兴奋，紧接着竟晕死过去！\n"NOR,obj);
                        obj->unconcious();
                        me->add("qi",obj->query_str()-55+random(10));
                        me->add("jing",obj->query_con()-55+random(10));
                          obj->add("makeloved",1);
                          me->add("makeloved",1);
                        break;
                default:
                        if(random(10) > 7) {
                                message_vision(YEL "$N坐在一旁闷头不语，望了一眼仍在微微娇喘的$n，\n喃喃说到：要不然...再让我试一次...\n"NOR,me,obj);
                          obj->add("makeloved",1);
                          me->add("makeloved",1);
                        }
                        else {
                                message_vision(HIM "$n闭上眼睛静静地躺在床上，感到自己身上的衣服\n一件一件的被脱掉，突然$n感到$N火烫的身体压上了自己...\n"NOR,me,obj);
                                call_out("over1", 3, me,obj);
                        }
                obj->add("qi",obj->query_str()-55+random(10));
                obj->add("jing",obj->query_con()-55+random(10));
                obj->add("makeloved",1);
                me->add("qi",obj->query_str()-55+random(10));
                me->add("jing",obj->query_con()-55+random(10));
                me->add("makeloved",1);                
        }
}
void over1(object me,object obj)
{
                message_vision(HIR "$N轻柔的吻者$n的唇，手掌开始不安分的抚摸$n光\n滑如缎子般的肌肤，$n娇喘吁吁，双手主动的抱住$N...\n"NOR,me,obj);
                call_out("over2", 3, me,obj);
}

void over2(object me,object obj)
{
                message_vision(WHT "$N也越来越兴奋，终于和$n结为一体，只听$n\n如蚊子般的“恩。。”了一声，似是痛苦，似是舒服...\n"NOR,me,obj);
                call_out("over3", 3, me,obj);
}

void over3(object me,object obj)
{
                message_vision(HIW "$N的动作越来越快，越来越猛，$n则配合着$N的节奏\n释放出对$N的爱，阵阵呻吟,春光熠熠，春潮绵绵...\n"NOR,me,obj);
                call_out("over4", 3, me,obj);
}

void over4(object me,object obj)
{
                message_vision(HIM "汹涌澎湃的高潮过后，$n温顺的躺在$N的怀里，听着\n$N的心跳声，$N轻轻的抚弄着$n光滑的皮肤，无限温柔...\n"NOR,me,obj);
                obj->add("qi",obj->query_str()-55+random(10));
                obj->add("jing",obj->query_con()-55+random(10));
                obj->add("makeloved",1);
                me->add("qi",obj->query_str()-55+random(10));
                me->add("jing",obj->query_con()-55+random(10));
                me->add("makeloved",1);
if(obj->query("gender")=="女性")
{
        if ((random(obj->query("makeloved")) > 30) && (random(me->query("makeloved")) > 30) && (!(obj->query_condition("huaiyun"))) 
         && random(2)==1)
        {
                obj->set("fuqi/father",me->query("id"));
        message("shout", HIR "【家有喜事】："HIM"恭喜 "HIY""+ me->query("name") +"(" + me->query("id") +")"HIM"与"HIY""+ obj->query("name") +"(" + obj->query("id") +")"HIM"做了准父母。\n" NOR,users());
                message_vision(HIY "\n$N突然觉得一阵做呕，旋即羞红着脸，咬咬牙想起了那个该死的。\n"NOR, obj);
                message_vision(HIM "\n$N怀孕了。赶快通知孩子的爸爸"+ obj->query("fuqi/father") +"啊？．．．\n"NOR, obj);
                obj->apply_condition("huaiyun",1200);           
                obj->set("long", HIY "\n"+ obj->query("name") +""NOR"挺着个大肚子，一看就知道是怀孕了，混身散发出一股慈祥的母爱。\n"NOR);
                me->set("makeloved",1);
                obj->set("makeloved",1);

        }
}
}

int help(object me)
{
        write(@HELP
指令格式 : makelove <人物>
做爱！
相关知识参看初中《生理卫生》课本

HELP);
        return 1;
}



