//mudiao By Zine 史可法三期

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(YEL"木牌"NOR, ({"mu pai", "pai"}));
	set_weight(80);
	set("long", "一个雕工精美的木牌，上面刻着一幅山川图，你可以仔细赏玩(wan)。\n");
	set("unit", "个");
	set("value", 1000);
    setup();
    
}

void init()
{
    add_action("do_wan","wan");
}

int do_wan()
{
    object me=this_player();
    if (me->query("yanke3/getbonus"))
    {
        tell_object(me,"细看之下，你才发现山川图下隐藏了一个数字“"+chinese_number(me->query("yanke3/getbonus"))+"”。\n");
        return 1;
    }
    else
    {
        tell_object(me,"你不禁赞叹如此巧夺天工之作，应该相当值钱。\n");
        return 1;
    }
}