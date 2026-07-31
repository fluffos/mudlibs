 //  design.c
inherit ITEM; 
void create()
{
        set_name("¿×È¸Í¼", ({ "design"}) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "¿×È¸ôáµÄÉè¼ÆÍ¼Ö½\n");
                set("unit", "ÕÅ");
                set("value", 0);
                set("real",1);
                set("material", "paper");
              }
        
}       
