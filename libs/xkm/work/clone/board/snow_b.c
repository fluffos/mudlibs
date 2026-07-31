inherit BULLETIN_BOARD;
#include <ansi.h>;
void create()
{
        set_name(HIB"留言簿"NOR, ({ "board" }) );
        set("location", "/u/snow/workroom");
        set("board_id", "snow_b");
        set("unit", "块");
        set("no_get", 1);
        set("long", "这是一个专供巫师留言(post)使用的留言板。\n" );
        setup();
        set("capacity", 300);
        replace_program(BULLETIN_BOARD);
}
string short()
{
    if ((this_player())&&this_player()->query("id")!="snow") return "一张"+HIY+"废纸"+NOR+"(paper)";
    return ::short();
}

string long()
{
    if ((this_player())&&this_player()->query("id")!="snow") return "一张废纸。\n";
    return ::long();
}
int do_post(string arg)
{
    if ((this_player())&&this_player()->query("id")!="snow") return 0;
    return ::do_post(arg);
}
int do_read(string arg)
{
    if ((this_player())&&this_player()->query("id")!="snow") return 0;
    return ::do_read(arg);
}
int do_discard(string arg)
{
    if ((this_player())&&this_player()->query("id")!="snow") return 0;
    return ::do_discard(arg);
}
