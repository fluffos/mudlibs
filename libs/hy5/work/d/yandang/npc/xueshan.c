inherit NPC;
int give_qian();
void create()
{
		set_name("雪山上人", ({ "shangren", "xueshanshangren","heshang" }) );
		set("title", "慈悲为怀");
		set("long","雪山上人主持观音洞已经一甲子了,你可以向他打听关于求签(qiuqian)的事。\n");
		set("gender", "男性");
		set("age", 80);
		set("attitude", "peaceful");
        set("max_force", 2000);
        set("force", 2000);
        set("force_factor", 3);

        set_skill("unarmed", 90);
        set_skill("parry", 60);
        set_skill("dodge", 60);
        set_skill("sword", 60);
        set_skill("force", 60);
        set_skill("literate", 60);
	set("combat_exp",800000);
        set("shen_type",1);
        set("inquiry",(["qiuqian":(:give_qian():)]));	
        setup();
        carry_object("/d/yandang/npc/obj/jiasha")->wear();
		add_money("silver", 56);
}
void init()
{
	::init();
	add_action("do_get","get");
	add_action("do_steal","steal");
}
int do_get(string arg)
{
	object me,obj;
	string from,item;
	me=this_player();
	if(!arg)	return 0;
	if(sscanf(arg, "%s from %s", arg, from)==2)
     {  if (me->query("family/family_name")!="雁荡派")
	{
		if(from=="xiang"||from=="gongde xiang")	{
		command("say 这位施主请不要乱动！");
		return 1;
		}
      }
	return 0;
	}
	return 0;
}
int do_steal(string arg)
{
	object me;
	string from;
	me=this_player();
	if(!arg)	return 0;
	if(sscanf(arg,"%s from %s",arg,from)==2)	{
		if(from=="xiang"||from=="gongde xiang")	{
		command("say 佛门清静之地，施主所为未免太过份了吧！");
		return 1;
	}
	return 0;
	}
	return 0;
}


int give_qian()
{
  object me,ob,*inv;
  int count;

  me=this_player();
	inv=all_inventory(me);
	for(count=0;count<sizeof(inv);count++)
	    if(inv[count]->query("id")=="qiantong")
       return notify_fail("上人摇头道:施主心念已迷,回头是岸,回头是岸.\n");
  else
{
  if( me->over_encumbranced() ) return notify_fail("你已经负荷过重了！\n");
  clone_object("/d/yandang/obj/qiantong")->move(me);

    command("say 心诚则灵,心动则迷,因缘天定,念动劫生。");  
    message_vision("雪山上人递给$N一个发黄的签筒.\n",me);   
  return 1;}
}
