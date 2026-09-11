#include <mudlib.h>
inherit LIVING;
inherit M_CHAR;
void receive_outside_msg(string msg, object * exclude, int message_type,
                         mixed other)
{
    responda("say "+msg);
    receive(msg);
}
void ppp(object me,object who,string item)
{
        me->targetted_action("$N对着$T哈哈大笑",who);
}
void setup()
{
    set_name("farmer", "农夫");
    set_gender(1);
    set_proper_name("劳累的农夫");
    set_in_room_desc("一个累得半死的农夫(farmer)");
    set_long("农夫瞪了你一眼：“好逸恶劳的家伙，还不过来帮忙翻翻地。”");
    set_answer("net", (: ppp :)) ;
}
