#include <ansi.h>
inherit NPC;


void create()
{
        set_name("老者", ({"old man","lao zhe","man"}));
        set("gender", "男性");
        set("age", 58);
        set("long","一个年迂古稀的老人，听说他就爱替别人写状纸，而打报不平。");
        set("attitude", "friendly");
        set("per", 30);
        set("str", 30);
        set("combat_exp",2000);
	set("combat_exp",2000);	
        set("max_qi",300);
        set("max_jing",300);

        setup();
}

