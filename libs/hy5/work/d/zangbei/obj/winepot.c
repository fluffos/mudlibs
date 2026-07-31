 inherit ITEM;
inherit F_LIQUID; 
void create()
{
        set_name("ÆÆ¾Æºø", ({ "winepot" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»¸öÆÆ¾Æºø£¬´ó¸Å×°µÃ°Ë¡¢¾ÅÉýµÄ¾Æ¡£\n");
                set("unit", "¸ö");
                set("value", 20);
                set("max_liquid", 15);
        } 
        set("liquid", ([
                "type": "alcohol",
                "name": "ÉÕµ¶×Ó¾Æ",
                "remaining": 15,
                "drunk_apply": 6,
        ]) );
        
}    
