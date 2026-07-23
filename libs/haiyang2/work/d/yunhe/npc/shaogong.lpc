// /d/npc/chuangfu
// netkill /98/8/18


#include <ansi.h>


inherit NPC;
int  zuchuan();

void create()
{
        set_name("船家", ({ "chuan jia","jia",}));
        set("gender", "男性");
        set("age", 32);
        set("long",
        "这是一个年轻的船家，由于在运河上生意比较好，所以看上去并不\n"
        "象饱经风爽的人，你如果要租船，可以问问他。\n",
            );

        set("combat_exp", 1000000);
        set("shen_type", 1);

        set("eff_qi",2000);
        set("qi",2000);
        set("max_neili", 1000);
        set("neili", 500);
        set("jiali", 10);

        set_skill("force", 90);
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 60);
        set("inquiry", ([
                
                   "租船" :   (: zuchuan :),

        ]) );

        setup();
        carry_object("/clone/misc/cloth")->wear();
 }

void init()
{
        ::init();
        add_action("do_answer","answer");
	
}


int zuchuan()
{
  object ob ;
  ob = this_player ( ) ;
  message_vision( "船家满脸堆笑的对$N说：好说，好说。客官想租什么样的船呢？\n"
                 "快船一百两银子，小舟十两，出什么钱坐什么船，公平公道。\n" 
                 ,ob);
  ob->set_temp ("zu" , 1 );
  return 1;
}

int accept_object(object who, object ob)
{
    if (ob->query("money_id") && ob->value() >= 1000) 
	{ 
	if (!(int)who->query_temp("zu"))
         return notify_fail("船家笑的象个烂菜花一样，说道：客官真是大方，乐善好施，是个好人啊！\n");
        tell_object(who, "船家对你说道：好！好！小舟马上给您备好，您稍侯。\n"+
			    "不过不知客官想到哪里呢，小的好跟您准备。\n"+
			    "我可以送你去的地方有:京城、杭州、华山村，请客官明示(answer)\n");
        this_player()->delete_temp("zu" );this_player()->set_temp("ok",1);
	return 1;
         }
    else  
        if (ob->query("money_id") && ob->value() < 1000 && (int)who->query_temp("zu"))
         message_vision("船家不高兴的说，你该不是打赏叫花子吧。 \n");       
	 return 0;
	
 }

int do_answer( string arg )
{	
	object me;
	me=this_player();
	if (!(int)me->query_temp("ok"))
		
		  return notify_fail("船家对你说道：你在说什么鸟语花香，不租船的话就快走\n");
	
	else {	
	if (!arg || arg=="") 
	
		return notify_fail("船家瞪大眼看着你说:客官请大声点说。\n");
	
	switch (arg){
		case "京城" : me->set_temp("exit",10);break;
		case "杭州" : me->set_temp("exit",40);break;
		case "华山村" : me->set_temp("exit",20);break;
		default : return notify_fail("船家笑说道：客官说笑，我从小在这条江边长大，从没听说过这个地方!\n");
		}
	me->set_temp("ok1",1);
	message_vision( "船家笑嘻嘻的说到：好好，待我给你准备好船。\n"+
			"说完向江面挥了挥手，喊到：备～～～船～～～\n\n"+
			"只见一叶小舟缓缓靠了过来。\n"
			"船家说到：请准备上船(enter chuan)吧!\n", me);
	
	}
        return 1;
}

