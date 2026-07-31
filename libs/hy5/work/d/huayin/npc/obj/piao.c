// piao.c

inherit ITEM;

protected int full;

int is_shui_piao() { return 1; }
string q_long() { return sprintf("这是一个用来盛水的水瓢%s",full?"，\n里面盛满了清水。\n":"。\n"); }

void create()
{
	set_name("水瓢", ({ "shui piao" }) );
	set_weight(500);

	set("unit", "个");
	set("long", (: q_long :));
}

int is_full() { return full; }
void do_fill() { full = 1; }
void do_pour() { full = 0; }
