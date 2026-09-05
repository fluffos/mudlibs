void init()
{
    add_action("do_xi","xi");
}

int do_xi()
{
    object me=this_player();
    if (me->is_busy()||me->is_fighting())
    {
        return notify_fail("你这么忙，还有空吸取花蜜吗？\n");
    }
    if (!this_object()->query("flower"))
    {
        return notify_fail("这朵花的花蜜已经被人吸干了。\n");
    }
    if (time()-(int)me->query("星宿派吃花蜜")<60)
    {
        return notify_fail("你又不是梅花鹿，怎么吃草上瘾了？\n");
    }
    if (me->query("water")<me->max_water_capacity())
    {
        me->add("water",20);
    }
    if (me->query("food")<me->max_food_capacity())
    {
        me->add("food",20);
    }
    if (me->query("neili")<me->query("max_neili"))
    {
        me->add("neili",20);
    }
    message_vision("$N把"+this_object()->query("name")+"的花蜜吸取出来，畅快无比。\n",me);
    me->set("星宿派吃花蜜",time());
    destruct(this_object());
    return 1;
}