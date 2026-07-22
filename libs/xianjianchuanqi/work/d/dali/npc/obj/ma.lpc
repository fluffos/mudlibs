//  ma.c   

inherit ITEM;
void setup()
{}

void init()
{
        add_action("do_ride", "qi");
        add_action("do_ride", "ride");
}

void create()
{
        set_name("岭南马", ({"lingna ma", "ma", "horse" }));
        set_weight(35000);
        set_max_encumbrance(50000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "匹");
                set("long", "一匹健壮的岭南马，你不妨骑骑看。\n");
                set("value", 1000);
        }
}

int do_ride(string arg)
{
	object me = this_player();
        if (!id(arg))
                return notify_fail("你要骑什么？\n");
        if (this_player()->query_temp("marks/骑") ) {
                       write("你已经骑在马上了。\n");
                        return 1;
        }
        else {
               message("vision",this_player()->name() + "翻身上马。\n",
                        environment(me), ({me}) );
               write("你拍拍马的头，慢慢地爬上马背。\n");
                this_player()->set_temp("marks/骑", 1);
        return 1;
        }
}
