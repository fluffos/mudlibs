// halaoban.c 哈老板
// Zine Oct 16 2010

inherit NPC;


#include <ansi.h>


void create()
{
	set_name("哈老板", ({ "ha laoban", "ha", "laoban"}));
	set("long", "哈老板来自西域，徐娘半老，风韵犹存。\n");
	set("gender", "女性");
    set("title", HIY"落难的"NOR);
	set("age", 35);
    set("start_room","/d/luoyang/sishu");
	set_skill("literate", 150);
    set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 400000);
	set("shen_type", 1);
 
	set("inquiry", ([
		"name" : "小女子是那个谁来着，我也记不清了。",
        "家乡" : "我从西边来的。",
        "西域" : "我从西边来的。",
	       ]) );
	setup();

	set("chat_chance", 3);
	set("chat_msg", ({
		"哈老板说道：为什么我那么命苦啊。\n",
		"哈老板说道：那个无良的小伙计，鸠占鹊巢，把我赶出来了。\n",
		"哈老板说道：难道没人帮我主持公道吗？ \n",
	}) );
		
}




int recognize_apprentice(object ob)
{
     return 1;
}

int dest(object niren)
{
	if(niren)
	destruct(niren);
	return 1;
}

int accept_object(object me, object niren)
{
    object chater;
	if( niren->query("id") != "ni ren")
	return notify_fail(this_object()->query("name")+"说道，你的好意我心领了，我人穷志不穷，还不需要这些身外物。\n");
	else
	{
        chater=new("/d/luoyang/obj/chater");
        if (chater)
        {
		message_vision("哈老板接过$N的泥人，爱不释手，喃喃自语。\n",me);
        message_vision("哈老板给了$N一把小剑。\n",me);
        chater->move(me);
		call_out("dest",2,niren);
		return 1;
        }
    }
}