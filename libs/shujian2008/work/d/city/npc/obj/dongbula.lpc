
#include <weapon.h>
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("冬不拉",({"dongbula"}));
        set_weight(150);
        if (clonep())
                set_default_object(__FILE__);
        else{
                set("unit", "把");
                set("value", 600);
                set("material", "wood");
                set("long","这是一把维吾尔族的弦乐器冬不拉。你可以演奏(play)它。\n");
                        }
        setup();
}

void init()
{
	add_action("do_play", "play");
	add_action("do_play", "tan");
}

int do_play(string arg)
{
	object me;
	me = this_player();
	if (!arg) return 0;
	if (arg !="dongbula") return 0;
	if (arg=="dongbula")
	switch(random(3)) {
	case 0 :
		message_vision(HIW"\n$N弹起冬不拉，深情地唱道：" +
		"在那遥远的地方，有位好姑娘。每当人们走过她的毡房，总要把她" +
		"深情地凝望。。\n\n"NOR,me);
               break;
	case 1 :
		message_vision(GRN"\n$N弹起冬不拉，哀伤地唱道：" +
		"戈壁滩上的一朵清泉，冰山上的一朵雪莲，风暴不会永远不停，啊啊啊，什么时候啊，才能见到你的笑脸。。\n\n"NOR,me);
		break;
	case 2 :
		message_vision(MAG"\n$N弹起冬不拉，快乐地唱道：" +
		"大坂城的石头圆又硬喽西瓜大又甜喽，大坂城的姑娘辫子长喽两只眼睛真漂亮。\n\n"NOR,me);
		break;
	}
	return 1;
}