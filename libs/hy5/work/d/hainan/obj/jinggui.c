inherit ITEM;
void create()
{
	object shu;
	set_name("白云庵藏经柜",({"cangjin gui","guizi","gui"}));
	set_weight(3000);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
	set("long","一个古檀木作的经柜,散发出檀香味。\n");
		set("material", "wood");
		set("no_get",1);
		set("no_drop",1);
	}
	setup();
	shu=new("/d/hainan/obj/forcebook");
	shu->move(this_object());
	shu=new("/d/hainan/obj/dodgebook.c");
	shu->move(this_object());
	shu=new("/d/hainan/obj/swordbook.c");
	shu->move(this_object());
}

int is_container() { return 1; }

