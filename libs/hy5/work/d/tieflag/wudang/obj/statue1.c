 inherit ITEM;
void create()
{
        set_name("ĞşÎä", ({ "ĞşÎä", "xuanwu" }) );
        set_weight(500);
        set_max_encumbrance(8000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
            set_default_object(__FILE__);
        else {
            set("unit", "×ğ");
            set("long", "Ò»×ğĞşÎäµÄÍ­ÖıËÜÏñ£¬Åû·¢õĞ×ã£¬·á×ËÎ¡Î°¡£\n");
            set("value", 1);
        }
        setup();
} 
int is_container() { return 1; }       
