// huazheng
// create by zine Aug 30 2010
#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIW+"华筝公主"+NOR, ({"huazheng gongzhu","huazheng","hua","gongzhu"}));
	set("long", "她是铁木真宠爱的女儿——华筝公主。\n"NOR);
	set("gender", "女性");
	set("age", 15);
    set("no_get", "铁木真的公主你也敢抢？还想活着离开草原吗？\n");
    set("is_huazheng",1);
    set("is_for_shediao_quest",1);
    set("combat_exp", 10000);
    set_skill("unarmed", 25);
    set_skill("force", 25);
    set_skill("dodge", 40);
	set("per",40);
    set_temp("apply/attack", 5);
    set_temp("apply/defense", 5);
	set("shen_type", 1);
	set("uni_target","zine");
    setup();
	carry_object(__DIR__"items/pixue")->wear();
	carry_object(__DIR__"items/cloth10")->wear();
	
}
	
int bye(object me)
{
	command("say 你早些回来。");
	command("hugfy "+me->query("id"));
	message_vision("$N说完也纵马离开。\n",this_object());
	destruct(this_object());
	return 1;
}