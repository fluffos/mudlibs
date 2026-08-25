//**********************************************
// write by fire 10/12/97 xiaoer.c 店小二
#include <mudlib.h>
inherit LIVING;
void setup() 
{
    add_id("xiao","er")
    set_name("xiaoer", "白梨云灵魂")
    set_gender(1)
    set_proper_name("精灵古怪的白梨云灵魂")
    set_in_room_desc("充满魅力的白梨云灵魂")
    set_long("白梨云灵魂痴痴地望着你，\n"+"你可别乱闯哦？\n\n")
    set_sg_zi("大愚")
        add_question("zhanpu","zhanpu" )
        add_question("money","money")
}
void special_answer(object who, string matt)
{
        switch(matt)
        {
                case "zhanpu" :
                        this_object()->targetted_action("$N对$T大声地说：“不可对我的主人不敬！不然我劈死你！”\n",who)
                        return
                case "money" :
                        this_object()->simple_action("白梨云灵魂鄙视地看着你：“你没手没脚啊，要当叫花子！”\n")
 return
        }
}
