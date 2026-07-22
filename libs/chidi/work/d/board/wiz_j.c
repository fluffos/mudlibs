// /clone/board/wiz_b.c
inherit BULLETIN_BOARD;
void create()
{
    set_name("工作里程碑", ({ "bei" }) );
	set("location", "/d/wizard/wizard_job");
	set("board_id", "wiz_j");
    set("long", "这是一本专供巫师记录工作的大理石碑。\n");
	setup();
	set("capacity", 60);
	replace_program(BULLETIN_BOARD);
}
