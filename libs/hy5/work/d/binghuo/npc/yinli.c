//NPC:/d/lingshedao/npc/yinli.c
//Creat by Yjss on Sep.1999
#include "ansi.h"
inherit NPC;
inherit F_UNIQUE;
string ask_me();
int ask_popo();
void create()
{
        set_name(HIC"殷离"NOR, ({"yin li", "yin",}));
        set("nickname",HIW"千蛛万毒手"NOR);
        set("long",
"她脸上肌肤浮肿，凹凹凸凸，生得极是丑陋，\n"
"只是一对眸子颇有神采,身材也苗窕纤秀.\n"
        );
        set("gender", "女性");
	set("attitude", "friendly");
        set("age", 16);
        set("shen_type", 1);
        set("per", 18);
        set("str", 120);
        set("int", 120);
        set("con", 125);
        set("dex", 120);

        set("max_qi", 5700);
        set("max_jing", 5500);
        set("neili", 50000);
        set("max_neili", 50000);
        set("jiali", 50);
        set_temp("no_kill", 1);
        set("combat_exp", 800000);
        set("score", 50000);
	set("book_count", 1);
        set_skill("force", 280);
        set_skill("dodge", 260);
        set_skill("parry", 260);
        set_skill("unarmed",290);
        set_skill("hand",290);
        set_skill("xiaoyao-bu",350);
        set_skill("qianzhu-wandushou",350);
        map_skill("unarmed","qianzhu-wandushou");
        map_skill("parry", "qianzhu-wandushou");
        map_skill("dodge","xiaoyao-bu");
        map_skill("force","shenghuo-shengong");
        
        set("inquiry",([
               "张无忌" : "他生得很英俊，可是骄傲得很。我要他跟着我去,
一辈子跟我在一起，他不肯，那也罢了，哪知还骂我,
打我,将我咬得身上鲜血淋漓。可我就是忘不了他!\n",
               "父母": "我亲生爹爹不要我，见到我就会杀我。我妈妈是我害死的.\n",
               "蛛儿": "你怎么知道的?快走开,不然叫你尝尝我的千蛛万毒手的厉害!\n",
		"锦盒":(:ask_me:),
           ]) );

          setup();
          carry_object("/clone/cloth/female1-cloth")->wear();
          carry_object("/d/yanziwu/npc/obj/flower_shoe")->wear();
          carry_object("/d/yanziwu/npc/obj/necklace")->wear();
}             
void init()
{
  add_action("do_quit","exert");
}






string ask_me()
{
	object me,ob;
	ob=this_player(); 

	if (query("book_count") < 1)
		return "你来晚了，锦盒我已经赠送给别入了。";   
	add("book_count", -1);                  

	message_vision(HIY"殷离从怀里拿出一个锦盒，交了给$N \n\n"NOR,ob);
	me=new("/clone/book/jinhe");
	me->move(ob);

	return "这个锦盒你要好好保管。\n";
}

int do_quit(string arg)
{
	if(arg=="roar") {
        write(this_player()->query("name")+"，这里不能用roar吧！\n");
        return 1;
	}
}