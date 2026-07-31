// 由于彩票身上带得太多的话会遗失，故特意写了个盒子来装它们。 caipiao_hezi.c
// by naihe 4:30 02-10-20

inherit ITEM;

void create()
{
        set_name("彩票盒", ({ "caipiao he", "he", "box" }));
        set_weight(200);
        set_max_encumbrance(3000);  // 可放300张。
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是一个小巧的盒子，是专门用来装彩票的。\n");
                set("value", 1);
		set("no_steal",1);
		set("no_drop",1);
        }
}

int is_container() { return 1; }

int reject(object ob)
{
        if (ob && ob->query("id")=="cai piao" ) return 0;
        notify_fail("这个盒子是专门用来装彩票的。\n");
        return 1;
}
