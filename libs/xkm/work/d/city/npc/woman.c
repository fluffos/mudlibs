//Cracked by Roath
// /d/emei/npc/woman.c
// Shan: 96/07/08
#include <ansi.h>
inherit NPC;
string ask_me();

void create()
{
        set_name("少妇", ({ "young woman", "woman" }) );
        set("gender", "女性" );
        set("age", 20+random(10));
        set("long", 
"一个少妇，正笑眯眯的向你迎来。\n");
	set("shen_type", 1);
	set("combat_exp", 500);
        set("str", 13);
        set("dex", 12);
        set("con", 14);
        set("int", 15);
        set("attitude", "friendly");

         set("inquiry", ([
            "媒婆" : (: ask_me :),
                ]) );
        setup();
	//carry_object(__DIR__"obj/cloth")->wear();
}



string ask_me()
{	object me,ob,npc;
	string who;
	me = this_player();
	
      if (me->query("gender")=="女性") 
	return  "女孩先开口，难到嫁不出去了？";	
	
      if ( !me->query_temp("marriage"))
         return "没有官府的允许，就想结婚啊？";
         who=me->query_temp("marriage/id");
      
      if(!who ||!objectp(ob = present(who, environment(me))))
	return "结婚可是要两个人一起来的呀！\n";
	
      if(file_size("/data/playerhomes/h_"+me->query("id")+".o") != -1)
      	{ 
      	 message_vision(HIY "哦，你们都准备好了，随我来吧！\n"NOR,me,ob);      
         npc=new("/d/ruzhou/npc/meipo");
       	 npc->move("/d/city/datang");
       	 me->move("/d/ruzhou/jiao1");
	 ob->move("/d/ruzhou/jiao2");
         call_out("go_lou",15,me,ob);
         return "哦，你们都准备好了，随我来吧！\n";
	}
	else
	return  "没买房子你们以后住哪里的呀？还是先把房子买好吧!!\n";
         	
}

int go_lou(object me,object ob)
{
	object npc;
	message_vision(HIY"\n 你们坐着轿子随着少妇穿过几条街，来到了中央广场。\n"NOR,me,ob);
     	call_out("go_lou2",5,me,ob);
         return 1;
}

int go_lou2(object me,object ob)
{
	object npc;
	message_vision(HIY"\n 只听轿夫们一声“到啦！”轿子整个儿一震，想是落到了地上，\n"
	"$N和$n从轿子中下来一看，来到了醉仙楼大堂。\n"
	"媒婆笑脸迎出来：“恭喜两位新人！恭喜恭喜！”\n"
	"你们赶紧下轿。\n"NOR,me,ob);
     	me->move("/d/city/datang");
        ob->move("/d/city/datang");
         return 1;
}