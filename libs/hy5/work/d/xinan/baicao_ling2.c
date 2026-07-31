#include <room.h>
inherit ROOM;


void create()
{
        set("short", "百草岭");
        set("long", @LONG
百草岭上气候温暖，终年云雾缭绕，高大的树木盘根错节地生长在岩壁，崖
缝之中，枝叶茂密，人在山谷中穿行，见不到一丝天空，阴森森的；脚下的；岩
石湿漉漉的，长满了小草和青苔，一些不知名的虫子在地上爬来爬去。头顶上是
陡峭的岩壁，据说山顶上可以采到各种仙草药材。
LONG
        );
        set("exits", ([
                "northdown"     : __DIR__"dukou1",
                "south"      : __DIR__"baicao_ling1",
        ]));

                    
        setup();
}
void init()
{
    add_action("do_up","climb");
    add_action("do_update","update");
}
int do_update()
{return 1;}

int do_up(object me,string arg)
{
    me = this_player();
    if ( me->query_temp_marks("lin/在百草岭山顶") )
        return notify_fail("你已经在山顶了！\n");
    message_vision("$N试着往山顶上爬去......\n",me);
    if ( me->query_xiuwei_by_type("dodge") < 1900 )
    {
        me->disable_command("verb","你正试着往山顶上爬......\n");
        call_out("fail_climbup",5,me);
    }
    else
    {
        me->disable_command("verb","你正试着往山顶上爬......\n");
        call_out("climbed_up",10,me);
    }
    return 1;
}
int fail_climbup(object me)
{
    me->receive_wound("qi",50);
    me->receive_wound("jing",70);
    me->receive_damage("qi",80);
    message_vision("$N刚刚爬到一半，突然一脚踩空，直摔了下来！！！\n",me);
    me->enable_path();
    me->unconcious();
    return 1;
}
int climbed_up(object me)
{
    me->receive_damage("jing",40);
    message_vision("$N成功地爬上了陡峭的山崖！\n",me);
    me->enable_path();
    me->set_temp_marks("lin/在百草岭山顶",1);
    return 1;
}
