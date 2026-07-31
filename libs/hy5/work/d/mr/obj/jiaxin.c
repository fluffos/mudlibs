// 家书
inherit ITEM;

void create()
{
        set_name("家信", ({"jiaxin", "paper"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long",
"这是张慕容复写给慕容博的家书，信中主要是倾吐分离后的无限伤感，\n"
"和希望慕容博能收持信人为徒。\n");
                set("material", "paper");
        }
}

