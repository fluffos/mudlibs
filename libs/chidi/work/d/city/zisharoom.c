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
    set("item_desc",([
        "out"       :   (: look_out :),
    ]));
    setup();
}
void init()
{
    add_action("do_out", "out");
}
int do_out(string arg)
{
    object me;
    me = this_player();
    if (me->is_busy()) return 1;
    message_vision("$N大喊一声，一个纵身跳了下去。\n", me);
    if (wizardp(me)) {
    me->command("chat 天意难违，唉！" + me->query("name") + "愿一死谢天下！");
    me->delete("env");
    me->delete("skills");
    me->delete_temp("last_damage_from");
    me->set_temp("die_for","跳下万丈深崖摔");
    me->die();
   } else {
    message_vision("只听见“轰隆”一声巨响，把你吓得跳了起来。\n", environment(me));
    me->move("/d/city/guangchang");
   } 
    return 1;
}
string look_out()
{
    return  "这里是世界的最高处，从这里可以遥望整个世界。\n"
"浮世烟尘，尽在眼底。据说此地是巫师自杀的地方。\n";
}


