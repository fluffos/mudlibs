// hunyuandan.c 混元丹 

inherit COMBINED_ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("幽冥丹", ({"youming dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "些");
                set("base_unit", "颗");
                set("long", "一颗冒着丝丝血腥味的丹药，据说吃了能增加杀气。\n");
                set("value", 3000);
				set("drug_type", "良药");
        }
     set_amount(1);
        setup();
}

int do_eat(string arg)
{
        if ( !arg || !id(arg) )
                return 0;
        if ((int)this_player()->query("bellicosity")>10000 )
        	return notify_fail("你杀气太高，再吃恐怕要变傻人了。\n");
        	
                this_player()->add("bellicosity",300);
                message_vision("$N吃下一颗幽冥丹，头顶隐约浮现出一个骷髅头....\n",this_player());
		if (query_amount()>1)
         		add_amount(-1);
		else destruct(this_object());
                return 1;
        
}
