inherit ROOM;
void create()
{
        set("short", "大海");
        set("long",@LONG
你正处在茫茫大海之中。你极目远望，只见海天一线，周围连个黑点都没有。
耳边只有海浪的拍打声。
LONG);   
        setup();
}
void init()
{
    object me;
    me = this_player();
    message_vision("你只觉海水从头顶哗哗地冲下来，啊，不是，是你在急速地往下沉。\n", me);
    me->delete_temp("last_damage_from");
    me->set_temp("die_for","跳海");
    me->die();
}
