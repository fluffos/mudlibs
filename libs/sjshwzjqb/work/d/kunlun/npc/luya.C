
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("陆压", ({"luya","lu","ya"}));
        set("gender", "男性" );
        create_family("昆仑山玉虚洞", 3, "弟子");
        set("title",HIG"昆仑山玉虚洞管家"NOR);
        set("age", 41);
       set("class", "xian");
        set("long", "昆仑山玉虚洞散仙陆压，在洞中兼任管家之职。\n");
        set("combat_exp", 30);
        set("attitude", "peaceful");
        setup();
  carry_object("/d/obj/cloth/linen")->wear();;
}

