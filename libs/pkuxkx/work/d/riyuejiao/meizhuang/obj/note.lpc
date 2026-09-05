// note.c	李铁嘴的条子

inherit ITEM;

void create()
{
        set_name("条子", ({"tiao zi", "tiao", "note" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一张旧纸片，上面写着似通非通，文不文白不白的四句话：\n
	广陵古曲，圣姑收藏。
	率意草帖，朱熹身上。
	呕血棋谱，无量山中。
	溪山宝图，黑店墙上。\n");
                set("unit", "张");
        }
}

