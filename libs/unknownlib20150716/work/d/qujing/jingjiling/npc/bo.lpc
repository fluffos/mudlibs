inherit NPC;

#include <allnpc.h>

void create()
{
        set_name("孤直公", ({"guzhi gong", "gong"}));
        set("age", 90);
	set("attitude", "peaceful");
        set("gender", "男性");
	set("class", "yaomo");
	set("title", "深山四操");
	set("nickname", "乌栖凤宿");
  	set_level(90);

        set("mana_factor",900);
        set_skill("unarmed",900);
        set_skill("force",900);
        set_skill("dodge",900);
	set_skill("parry",900);
	set_skill("spells",900);
	set_skill("stick",900);
        setup();

	carry_object("/d/qujing/jingjiling/obj/zhang")->wield();
	carry_object("/d/qujing/jingjiling/obj/cloth")->wear();
}

void die()
{
	message_vision("$N身子一瘫，化作一根枯枝。\n",this_object());
	destruct(this_object());
}