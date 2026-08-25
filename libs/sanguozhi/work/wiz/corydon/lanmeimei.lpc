#include <mudlib.h>
inherit LIVING;
void ppp(object me,object who,string item)
{
        me->targetted_action("$N对着$T哈哈大笑",who);
}
void setup()
{
    set_name("smuffette", "蓝妹妹");
    set_gender(2);
    set_proper_name("娇俏的蓝妹妹");
    set_in_room_desc("%^H_BLUE%^蓝妹妹%^RESET%^(smuffette)看着你张着小嘴半天不说话 :%^RED%^0%^RESET%^");
    set_long("%^H_BLUE%^蓝妹妹%^RESET%^跳过来搂着你的脖子说：亲爱的陌生人，带我去跳舞吧。。。");
    set_answer("net", (: ppp :)) ;
}
