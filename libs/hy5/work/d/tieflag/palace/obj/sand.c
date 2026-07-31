 inherit ITEM;
void create()
{
        set_name("É³×Ó", ({ "sand" , "Á÷É³"}) );
        set_weight(500);
        set_max_encumbrance(8000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¶Ñ");
                set("long", "¾§Ó¨½à°×µÄÉ³×Ó¡£\n");
                set("value", 1);
        }
} 
int is_container() { return 1; }    
