

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("大力丸", ({"daliwan", "wan", "dali"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "包");
		set("long", "这是一包武林人士必备的好药,有伤治伤,没伤健身。\n");
		set("value", 50000);
	}
	setup();
}

int do_eat(string arg)
{

        if (!id(arg))
		return 0;
	if ((int)this_player()->query("eff_qi") == 
	    (int)this_player()->query("max_qi")&&
            (int)this_player()->query("qi") == 
	    (int)this_player()->query("eff_qi")            
           )
		return notify_fail("身强体壮的，吃什么药啊？\n");
	else {
		this_player()->receive_curing("qi", 50);
	                           
                if ((int)this_player()->query("qi")+200 > 
	        (int)this_player()->query("eff_qi"))     
                { this_player()->set("qi",(int)this_player()->query("eff_qi"));
		message_vision("$N吃下一包大力丸，觉得身体恢复了往日的活力.\n", this_player());
		destruct(this_object());
                return 1;
                }
                this_player()->set("qi",(int)this_player()->query("qi")+200);
		message_vision("$N吃下一包大力丸，气色看起来好多了。\n", this_player());
		destruct(this_object());
		return 1;
            }
}

