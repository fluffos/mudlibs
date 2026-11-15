

int do_dig(string arg)
{
    object me = this_player();
    object heap;
    string drop;
    object item;

    if (!arg)
    {
        return notify_fail("你要挖掘哪个矿堆?\n");
    }

    heap = present(arg, environment(me));
    if (!heap || !heap->is_mine_heap())
    {
        return notify_fail("这里没有这样的矿堆。\n");
    }

    drop = heap->get_drop();
    if (!drop)
    {
        return notify_fail("挖掘失败,没有获得任何物品。\n");
    }

    item = new(drop);
    if (!item)
    {
        return notify_fail("物品生成失败,请联系管理员。\n");
    }

    item->move(me);
    
    message_vision("$N用力挖掘" + heap->name() + "，成功地挖出了一个" + item->name() + "。\n", me);

    if (heap->query_amount() > 1)
    {
        heap->add_amount(-1);
    }
    else
    {
        destruct(heap);
    }

    return 1;
}