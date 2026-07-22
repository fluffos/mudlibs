// wizard_j.c
inherit BULLETIN_JBOARD;
void create()
{
        set_name("巫师工作进度报告", ({ "job board", "board","thousand-gold" }) );
	set("location", "/d/wizard/wizard_job");
	set("board_id", "wizard_j");
	set("long",	"这是一个特殊的留言板供巫师报告自己的工作进度。\n" );
	setup();
	set("unit","个");
//        replace_program(BULLETIN_JBOARD);
}
string short()
{
    if (!wizardp(this_player())) return "又是一张"+HIY+"一千两的金票"+NOR+"(Thousand-gold)";
    return ::short();
}

string long()
{
    if (!wizardp(this_player())) return "一张面额值一千两金子的金票。\n";
    return ::long();
}
int do_project(string arg)
{
    if (!wizardp(this_player())) return 0;
    return ::do_project(arg);
}

int do_report(string arg)
{
    if (!wizardp(this_player())) return 0;
    return ::do_report(arg);
}

int do_read(string arg)
{
    if (!wizardp(this_player())) return 0;
    return ::do_read(arg);
}
int do_terminate(string arg)
{
    if (!wizardp(this_player())) return 0;
    return ::do_terminate(arg);
}
