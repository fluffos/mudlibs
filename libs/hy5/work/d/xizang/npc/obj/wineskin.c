 // waterskin.c
inherit ITEM;
inherit F_LIQUID; 
void create()
{
        set_name("ÑòÆ¤¾Æ´ü", ({ "wineskin", "skin" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»¸öÑòÆ¤·ìµÄ´ó¾Æ´ü£¬´ó¸Å×°µÃ°Ë¡¢¾ÅÉýµÄ¾Æ¡£\n");
                set("unit", "¸ö");
                set("value", 20);
                set("max_liquid", 450);
        } 
        // The liquid contained in the container is independent, we set a copy
        // in each cloned copy.
        set("liquid", ([
                "type": "alcohol",
                "name": "ÑòÄÌ¾Æ",
                "remaining": 450,
                "drunk_apply": 7,
        ]) );
        
}
