// medicine: zitanhua.c
// Jay 3/18/96
//write by lysh
inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("紫檀花", ({"zitan hua", "hua"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "朵");
                set("long", "这是一朵只有在华山之巅上才能生长的紫檀花。\n");
                set("value", 10);
        }
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("你要吃什么？\n");
             this_player()->add("food", 20);

// function of this medicine needed here

message_vision("$N吃下一棵紫檀花，只觉得一阵清凉 !\n", this_player());

       destruct(this_object());
       return 1;
}

