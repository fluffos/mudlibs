 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
        set_name("ÐåÁú»¨¶Ð±»", ({ "huabei" , "ÐåÁú»¨¶Ð±»"}) );
        set_weight(500);
        set_max_encumbrance(8000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "´²");
                set("prep", "under");
                set("value", 1);
        }
        
}
int is_container() { return 1; }       
