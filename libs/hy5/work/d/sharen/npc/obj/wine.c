#include <ansi.h>
inherit ITEM; 
void apply(string confirm, object me);
void create()
{
    set_name(HIW "逃情酒" NOR,({"taoqing-wine"}));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "壶");
                set("material", "wood");
                set("long", "古有情花，今有逃情酒。酒虽风雅，情却累人。\n");
                }
} 
void init()
{
        if(this_player()==environment())
        add_action("do_drink","drink");
} 
int do_drink(string arg)
{
        object me, obj;
        me = this_player();
        if (!arg)
                return notify_fail("你要喝什么？\n");
		if (arg != "taoqing-wine")
                return notify_fail("你要喝什么？\n");
        if (query("used")) 
                return notify_fail(this_object()->name()+"已经被喝光了。\n");     
		if (!me->query("marry"))
				return notify_fail("你并没有婚约，饮下此酒对你没有意义。\n");
        write(HIR"\n喝下此酒之人将与爱人形同陌路，你是否同意？(yes/no)\n"NOR);
        input_to( (: apply :), me);
        return 1;
}

void apply(string confirm, object me)
{
        if (! (confirm == "yes" || confirm == "YES")) 
                write("你出了一身冷汗，好险！\n");
        else    {
		message_vision(HIW"$N一仰脖，将整壶逃情酒一饮而尽......\n"NOR,me);
        write(WHT"\n你突然觉得旧情往事都如梦、如烟、如尘般消逝去了……\n\n"NOR);
        set("used",1);
        me->delete("marry");
        me->add("divorced",1);
        }
}

