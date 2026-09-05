#include <ansi.h>
inherit NPC;
void create()
{
	set_name("孟温礼", ({ "jingzhao yin", "yin" }));
	set("title",HIY"京兆尹"NOR);
  set("gender", "男性");
	set("age", 50);
	set("long", "他是一个京兆府的长官，分管地产买卖。\n");
	
	set("combat_exp", 100000);
	set("shen_type", -1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

        set("inquiry", ([  
                "name" : "我就是大名鼎鼎的京兆尹啊！",
        ]) );

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}
