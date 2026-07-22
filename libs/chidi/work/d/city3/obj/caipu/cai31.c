// cai by -wyz
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name( "ÇåÕô¶¬¹ÏÖÑ" , ({"china cai", "wintry"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",  "ÕâÊÇÒ»µúÏãÅçÅçµÄËØ²Ë¡£\n" );
                set("unit", "µú");
                set("value", 150);
                set("food_remaining", 3);
                set("food_supply", 60);
        }
}

