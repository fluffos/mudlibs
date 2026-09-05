//  instrument: dongbula.c
// Edited by Zgbl 2010-08-24
#include <ansi.h>

inherit ITEM;
int do_play(string);

//void setup()
//{}

void init()
{
        add_action("do_play", "play");
}

void create()
{
        set_name("冬不拉", ({"dongbula"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把维吾尔族的弦乐器冬不拉。你可以演奏(play)它。\n");
                set("value", 100);
        }
//        setup();
}

int do_play(string arg)
{
	object me;
	me = this_player();

        if (!id(arg))
                return notify_fail("你要演奏什么？\n");
        switch( random(3) ) {
                case 0:
    message_vision(me->name()+"弹起冬不拉，深情地唱道：\n"
HIM "在那遥远的地方，有位好姑娘。每当人们走过她的毡房，总要把她深情地凝望。\n" NOR,me);
                        break;
                case 1:
    message_vision(me->name()+"弹起冬不拉，快乐地唱道：\n"
HIY "大坂城的石头圆又硬喽西瓜大又甜喽，大坂城的姑娘辫子长喽两只眼睛真漂亮。\n" NOR,me);
                        break;
                case 2:
    message_vision(me->name()+"弹起冬不拉，哀伤地唱道：\n"
HIB "戈壁滩上的一朵清泉，冰山上的一朵雪莲，风暴不会永远不停，啊啊啊，什么时候啊，"
"才能见到你的笑脸。\n" NOR,me);
                        break;
        }
        return 1;
}

