

inherit NPC;
#include <ansi.h>
int ask_done();
void create()
{
	set_name(WHT"大长老"NOR, ({ "da zhanglao", "zhanglao",}));
	set("str", 20);
	set("gender", "男性");
	set("age", 60+random(18));
	set("long", "他是壮族山寨的长老，可以过问壮族山寨几乎所有事务。\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set("inquiry", ([
            "老虎" : "小路东面的山林里有老虎，已经害了很多人的性命了。",
            "山林" : "山林进去之后需要细心寻找，才能找到老虎。",
            
			"杀虎" : (: ask_done :),
            "shahu" : (: ask_done :),
			
			
            
       	]) );
	set("QUEST_DROP_GEM",1);
	set("shen_type",1);set("score",200);setup();
    setup();
    carry_object("/clone/misc/cloth")->wear();

}

int ask_done()
{
    object me=this_player();
    object ob=this_object();
    object baoshi;
    int i;
	string gem;
    if (ob->is_busy() || ob->is_fighting())
		{
			return notify_fail("大长老正忙着呢！\n");
        }
    if (!me->query_temp("zhuangquest"))
    {
        if (me->query("zhuangquest"))
        {
            tell_object(me,"大长老道：我们这没有老虎啦：）\n");
            return 1;
        }
        else
        {
            tell_object(me,"大长老道：加油啊，杀死老虎我们重重有赏！\n");
            return 1;
        }
    }
    else
    {
        baoshi= new("/obj/gem/gem");
         i = random(20);
			if (i < 3) gem = "yan";
			else if (i < 6) gem = "mu";
			else if (i < 9) gem = "sui";
			else if (i < 12) gem = "jin";
			else if (i < 15) gem = "bing";
			else if (i < 16) gem = "gu";
			else if (i < 17) gem = "yu";
			else if (i < 18) gem = "jiao";
			else gem = "jia";
        baoshi->set_level(9400,9999,gem);    //3级及以上
        me->delete_temp("zhuangquest");
        tell_object(me,"哇，你太厉害了！\n");
        if (baoshi)
        {
            baoshi->move(me);
            tell_object(me,"大长老道：我这有块石头，不知道有什么用，就给你吧。\n");
            tell_object(me,"大长老给你一枚"+baoshi->name()+"。\n");
            ob->add_busy(2);
            me->add_busy(1);
            remove_call_out("giveout");
            call_out("giveout",1,me);
            
        }
        return 1;
    }
}
string gem_drop_msg(object me,object item)
{
	return query("name")+"拿出了一"+item->query("unit")+item->name()+"交给"+me->name()+"。\n";
}
int giveout(object me)
{
 
    int i=0;
    int n=4+random(5);
    tell_object(me,"大长老道：我还有些东西，也全给你了吧。\n");
    message_vision("$N抖了抖身上的衣服，仿佛在努力找到点什么……\n",this_object(),me);
    while (i<n)
    {
        GEM_D->drop(this_object(),me);
        i=i+1;
    }
    return 1;
}