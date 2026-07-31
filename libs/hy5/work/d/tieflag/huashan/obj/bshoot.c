 inherit ITEM;
void create()
{
        set_name("ÖñËñ", ({"bamboo shoot", "shoot"}) );
        set_weight(100);
        if( clonep() )
          set_default_object(__FILE__);
        else {
            set("unit", "¸ö");
            set("long", "Ò»¸öÄÛÖñËñ¡£\n");
            set("value", 50);
        }
        setup();
}   
