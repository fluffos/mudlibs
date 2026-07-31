inherit ROOM;
string look_out();
void create()
{
    set("short", "世界之巅");
    set("long", @LONG
这里就是之巅。尽管山风吹人欲倒，可是在云海里漫步，还是让人有飘飘欲仙的感觉。
不知道跳(out)到云头上，会是怎样的感觉？
LONG
    );
    set("exits", ([
    ]));
    set("item_desc", ([
        "out"       :   (: look_out :),
    ]));
    setup();
}
void init()
{
    add_action(do_out, out);
}
int do_out(string arg)
{
    object me;
    message_vision($N大喊一声，一个纵身跳了下去。\n, me);
    me->move(__DIR__guangchang);
    message_vision(只听『砰』地一声巨响，一团物体从天上掉了下来。\n, me);
    if (wizardp(me)) {
    me->command(unset immortal);
    me->command(unset invisibility);
    me->command(chat 啊～～～);
    me->delete_temp(last_damage_from);
    me->set_temp(die_for,跳下万丈深崖摔);
    me->die();
    return 1;
   }
}
string look_out()
{
    return  这里是世界的最高处，从这里可以遥望整个世界。\n
"浮世烟尘，尽在眼底。据说此地是巫师自杀的地方。\n";
}

