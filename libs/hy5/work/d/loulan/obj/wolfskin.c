 inherit ITEM;
inherit F_LIQUID;
#include <ansi.h> 
void create()
{
        set_name( RED"ÀÇ¾Æ´ü"NOR, ({ "wolf skin", "skin" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»Ì³´¼Ïã·¼Ùý£¬ÑÞºìËÆÑªµÄÃÀ¾Æ¡£\n");
                set("unit", "¸ö");
                set("value", 2000);
                set("max_liquid", 15);
        } 
        set("liquid", ([
                "type": "alcohol",
                "name": "ÀÇ¾Æ",
                "remaining": 15,
                "drunk_apply": 30,
        ]) );
        
} 
