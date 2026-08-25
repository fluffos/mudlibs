#include <mudlib.h>
inherit LIVING;
void ppp(object me,object who,string item)
{
        me->targetted_action("$N对着$T哈哈大笑",who);
}
void setup()
{
    set_name("papasmurf", "蓝爸爸");
    set_gender(1);
    set_proper_name("雪白胡须的蓝爸爸");
    set_in_room_desc("%^H_BLUE%^蓝爸爸%^RESET%^(papasmurf)正在调毒药... fear");
    set_long("蓝爸爸瞪了你一眼：“别烦我，忙着呢!”");
    set_answer("net", (: ppp :)) ;
}
