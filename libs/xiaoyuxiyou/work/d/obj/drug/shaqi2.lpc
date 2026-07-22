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
        set_name("慈悲丹", ({"cibei dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "些");
                set("base_unit", "颗");
                set("long", "一颗透露出一丝祥和气息的丹药，据说吃了能增加杀气。\n");
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
        if ((int)this_player()->query("bellicosity")<50 )
        	return notify_fail("你够和谐的了，再吃也成不了佛。\n");
        	
                this_player()->add("bellicosity",-50);
                message_vision("$N吃下一颗慈悲丹，背后隐约浮现出一个菩萨光轮....\n",this_player());
		if (query_amount()>1)
         		add_amount(-1);
		else destruct(this_object());
                return 1;
        
}
