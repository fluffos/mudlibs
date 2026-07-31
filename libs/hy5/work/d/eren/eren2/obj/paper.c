 inherit ITEM;
void create()
{
        set_name("发黄的羊皮纸", ({"paper", "纸"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", "一张已经发黄了的羊皮纸，上面的字迹残缺不全，你隐约可辨四个字。
        藏宝                   
                       密室
\n");
                set("value", 1);
        }
}       
