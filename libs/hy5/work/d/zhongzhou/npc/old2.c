//keeper.c
//updated by rama

inherit NPC;
#include <ansi.h>

int ask_hbd(object me, object ob);

void create()
{
        set_name("ÀÏºº", ({ "old man", "old", "man" }) );
        set("gender", "ÄĞĞÔ" );
        set("age", 63);
        set("shen_type", 1);
        set("combat_exp", 10000);
        set("str", 20);
        set("dex", 20);
        set("con", 20);
        set("int", 20);
        set("attitude", "peaceful");
        set("inquiry",([  
                "ºÚ°×µÀ" : (: ask_hbd :),  
                               ]) );  
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

