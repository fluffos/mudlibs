// paper.c
inherit ITEM;

void create()
{
	set_name("书信",({"paper"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long",
"这是张普通的纸，上面是当年陆乘风写给朋友的家常信.\n");
                set("material", "paper");
        }
}

