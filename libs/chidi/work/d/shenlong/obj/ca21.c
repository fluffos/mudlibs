inherit ITEM;
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
        set_name("无名花", ({"hua", "wuming"}));
        set("unit", "朵");
        set("long", "这是一朵无名小花,花蕊虽小,却十分美丽。\n");
        setup();
}
int do_eat(string arg)
{
    if (!id(arg))  return notify_fail("你要吃什么？\n");
    message_vision(BOLD "$N吃下一朵"+this_object()->name()+"顿然间只觉一股异香直沁心肺...\n" NOR, this_player());
    this_player()->add("max_neili",4);
    this_player()->add("kar",11);
    this_player()->unconcious();
       this_object()->move(VOID_OB);
    destruct(this_object());
    return 1;
}
