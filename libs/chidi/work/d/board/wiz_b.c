// /clone/board/wiz_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("巫师留言簿", ({ "board" }) );
        set("location", "/d/wizard/wizard_room");
        set("board_id", "wiz_b");
        set("long", "这是一个专供巫师使用的留言板。\n" );
        setup();
        set("capacity", 300);
//      replace_program(BULLETIN_BOARD);
}
string short()
{
        if (!wizardp(this_player()))
                return "一万张"+YEL+"一千两金票"+NOR+"(Thousand-gold)";
        return ::short();
}
string long()
{
        if (!wizardp(this_player()))
                return "一张面额值一千两金子的金票。\n";
        return ::long();
}
/*
int do_post(string arg)
{
        if (!wizardp(this_player())) return 0;
        return ::do_post(arg);
}
int do_read(string arg)
{
        if (!wizardp(this_player())) return 0;
        return ::do_read(arg);
}
int do_discard(string arg)
{
        if (!wizardp(this_player())) return 0;
        return ::do_discard(arg);
}
*/

