#include <ansi.h>
inherit ITEM;

void create()
{
        set_name( "任我行的尸体", ({ "corpse" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "具");
                set("long","这是一代枭雄任我行的尸体。他曾经叱咤风云，令江湖人物闻风丧胆，
但是他终归还是要化作尘土。（cuthead corpse）\n"NOR);
		set("material","wood");
		set("mingjiao",1);
		set("no_get",1);
                 }
        setup();
}

void init()
{
	add_action("do_cut","cut");
        add_action("do_cut","cuthead");
}

void destroying(object obj)
{
	destruct(obj);
	return;
}

int do_cut(string arg)
{
	object me,obj;
	me = this_player();
	if (!arg || arg != "corpse")
	{
          return 0;
	}
	
	message_vision("$N顺手拿起任我行身边的钢刀，一刀切下了任我行的脑袋。\n",me);
	message_vision("一名庄仆走了进来，略带惋惜地拖走了任我行的尸体。\n",me);
	obj = new("/d/riyuejiao/obj/shouji");
	obj->move(me);
	destroying(this_object());
      return 1;
}


