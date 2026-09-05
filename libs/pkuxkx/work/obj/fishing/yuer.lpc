//by hehe
//2003.3.21
//MODIFIED BY ZINE 2010
inherit ITEM;

void create()
{
	set_name("鱼饵", ({"yuer","er"}));
    set_weight(100);
    if( clonep() )
		set_default_object(__FILE__);
    else
	{
		set("unit", "个");
        set("long","这是个最普通的鱼饵。需要先(gua)在钓杆上才能钓鱼。\n");
        set("value", 2);
        set("assist_fishing",5);//帮助钓鱼，越高越好，0-150
        set("is_yuer_for_fishing",1);//这个标记必须具备
        set("material", "steel");
    }
}
