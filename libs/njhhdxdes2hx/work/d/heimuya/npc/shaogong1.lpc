// boater.c
// write by dfbb@hero
// Tue Dec 26 18:10:16 CST 1995
#include <ansi.h>

inherit NPC;

string	cross_river();

string *make_msg = ({
    HIG "猩猩滩水流湍急,不过梢公的技术很好\n\n" NOR,
    HIG "他用竹篙轻轻一点,竹筏便离开岸边\n\n" NOR,	
    HIG	"你们的竹筏已经快到江心了\n\n" NOR,
    HIG "你们的竹筏已经到了江心\n\n" NOR,
    HIG "你们的竹筏已经过了江心\n\n" NOR,
    HIG "你们的竹筏快靠岸了\n\n" NOR,
    HIG "终于到了!!!你轻轻一跃,就跳上岸去 \n\n" NOR,
});


void create()
{
        set_name("梢公", ({ "shaogong" }) );
        set("title", "渡口");
        set("gender", "男性" );
        set("age", 60);
        set("long", "船夫的皮肤晒得黝黑，脸上的沧桑是多年摆渡的痕迹。\n");
	set("str", 27);
        set("combat_exp", 1500);
        set("attitude", "heroism");
        set_skill("unarmed", 40);
        set_skill("parry", 50);
        set_skill("dodge", 30);
	set_skill("spear", 40);
	set_skill("mo-qiang-jue", 40);
	map_skill("spear", "mo-qiang-jue");
	map_skill("parry", "mo-qiang-jue");


        set("inquiry", ([
		"过江" : (: cross_river :),
		"摆渡" : (: cross_river :), 
        ]) );
	
	create_family("日月神教", 16, "教众");

	setup();
	add_money("coin", 200);
	carry_object("/obj/cloth")->wear();
	carry_object("/d/heimuya/obj/chuangao")->wield();

}

void init()
{
        add_action("do_chushi", "chushi");
        ::init();
}


int accept_object(object who, object ob)
{
		int val;

	        val = ob->value();
        	if( !val) return notify_fail("我不要物品\n");


                if( ob->value() >= 4000 ) {
			destruct(ob);
			command("nod");
			message("vision", "梢公说：客官可以过江啦！\n",who );
			this_player()->move("/d/heimuya/river1");
			call_out( "guohe", 2, who, 0 );
                        return 1;
                } else 
		   {
		    write("这么少？我还要养家呀！\n");
		    return 0;	
		   }	
}

string	cross_river()
{
	return  "日月神教的人不要钱,只需要出示(chushi)腰牌\n其他人每次交五十两银子";
}

int do_chushi()
{
	object who,*inv;
	int i;

	who=this_player();
	if(who->query("family/family_name")=="日月神教")
  	{
   	 inv = all_inventory(who);
   	 for(i=0; i<sizeof(inv); i++)
    	 {   
       	 if(strsrch(inv[i]->query("name"),"腰牌")==-1)continue;
      	 write("日月神教的兄弟过河当然免费!!.\n");
	 this_player()->move("/d/heimuya/river1");	 
	 call_out( "guohe", 2, who, 0 );

       	 return 1;
         }
	 write(HIR "你的腰牌上哪儿去了?\n快去补一块!!\n" NOR);   
    	 return 1;
	}	
	else
           write(HIY "老老实实交钱吧!!!\n" NOR);
	return 1;	
}

void guohe(object who, int stage)
{
     object obj;
     tell_object(who, make_msg[stage]);
     if( ++stage < sizeof(make_msg) ) {
         call_out( "guohe", 2, who, stage );
         return;
     } else
	who->move("/d/heimuya/xxt5");
        if(who->query("family/family_name")=="日月神教")
         {
	  tell_object(who,"兄弟,靠岸罗,一路顺风!\n");
	 }
	else
	 {
	  tell_object(who,"靠岸罗,快滚上去吧!\n");
	 }
    return;
}
