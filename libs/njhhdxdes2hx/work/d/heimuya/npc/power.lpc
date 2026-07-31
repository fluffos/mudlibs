//power.c
//write by dfbb@hero

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("老板", ({ "lord","laoban" }) );
	set("gender", "男性" );
	set("age", 42);
	set("long",
		"一个精明能干的中年人\n");
	set("combat_exp", 10000);
	set("attitude", "heroism");
	set("rank_info/respect", "大哥");
	create_family("日月神教", 16, "教众");
	set("title","顺升客栈");
        set_skill("unarmed", 60);
        set_skill("parry", 60);
        set_skill("dodge", 60);
	set_skill("mo-zhang-jue",60);
        map_skill("unarmed","mo-zhang-jue");
        set_skill("mo-shan-jue",60);
        map_skill("dodge","mo-shan-jue");
	setup();

}

void init()
{	
	add_action("do_join", "join");
	add_action("do_swear", "swear");
	::init();
}

int do_join(string arg)
{
 int i;	
 object ob,who,*inv;

 who=this_player();

  if(who->query("family/family_name")=="日月神教")
  {
    inv = all_inventory(who);
    for(i=0; i<sizeof(inv); i++)
     {   
        if(strsrch(inv[i]->query("name"),"腰牌")==-1)continue;
                
        write("你已经是日月神教的人.\n");
        return 1;
     }
    ob = new("/d/heimuya/obj/yaopai");
    ob->move(who);
    write("下次可要好好保管!!!\n");   
    return 1;
 }

 if(!arg) return notify_fail("你要干吗？\n");
if(arg=="日月神教"&&strsrch(who->query("title"),"普通百姓")!=-1)
 {
     if( who->query_temp("pending/rysj_swear") ) {
                command("say 多说无益，若不发誓忠于教主，便是说一千遍也没用。");
                return 1;
 } else {
                command("say 我日月神教中都是血性男儿，" + RANK_D->query_respect(who)
                        + "如果真的有心加入，且发个誓(swear)来。");
                who->set_temp("pending/rysj_swear", 1);
		return 1;
        }
  }
  else
   {	
  	write("你这个正派中的狗东西滚出去!!!\n");
	who->move("/d/heimuya/yidao5");
	message("vision","只听“乒”地一声，" +  who->query("name") +
                "被人从客栈里赶了出来 \n", environment(who), who);

	return 1;
    }	
  write("你要干什么\n");
  return 1;		
}

int do_swear(string arg)
{
	object ob,who;
	who=this_player();
        if( !who->query_temp("pending/rysj_swear") )
                return 0;
        if( !arg ) return notify_fail("你要发什麽誓？\n");
        this_player()->set_temp("pending/rysj_swear", 0);
        message_vision("$N发誓道：我向本教历代神魔发誓" + arg + "\n日后若违此誓,给三尸虫嚼食脑髓而亡!!!\n",this_player());
        if( strsrch(arg, "忠于教主") >=0 ) {
                command("smile");
	        ob = new("/d/heimuya/obj/yaopai");
                ob->move(who);
    		who->create_family("日月神教", 16, "教众");
		who->set("title",HIR "日"+HIB"月"+HIY "神教" NOR + "教众");
    		write("老板说: 恭喜你!今天起你就是我们日月神教的一员了!!!\n");
   		return 1;

        } else {
                command("say 你既然没有诚意,还是请回吧!\n");
		who->move("/d/heimuya/yidao5");
        message("vision","只听“乒”地一声，" +  who->query("name") +
                "被人从客栈里赶了出来 \n", environment(who), who);
                
        return 1;
		
        }
        return 1;
}

