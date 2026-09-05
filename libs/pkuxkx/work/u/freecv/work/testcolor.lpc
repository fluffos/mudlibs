#include <ansi.h>
inherit ITEM;

void setup() {}

void create()
{
        set_name(HIG"彩色说话机"NOR,({"color talker","talker"}));
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit","台");
                set("long",HIG"一台冰箱，放在墙的角落里，时不时的发出一阵嗡嗡声。\n"NOR);
        }
}
void init()
{
        add_action("do_say","say");
}

int do_say(string content)
{
    message_vision("你是不是说"+HBRED+content+NOR+"\n",this_player());
    return 1;
}
