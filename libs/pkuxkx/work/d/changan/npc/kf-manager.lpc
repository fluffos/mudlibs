#include "/quest/changan/quest.h"
inherit NPC;

void create()
{
	set_name("库房守卫", ({ "kufang shouwei", "shouwei" }));
	set("age", 22);
	set("gender", "男性");
	set("long", "金吾卫的卫士，负责户部库房重地的安全事宜。\n");
	set("attitude", "peaceful");
	set("changan_bing",1);

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 500000);
  set("shen_type",1);
 	set("max_qi", 3000);
 	set("max_jing", 3000);
 	set("neili", 3000);
 	set("max_neili", 3000);
 	set("jiali", 50);

	set_skill("unarmed", 150);
	set_skill("hand",150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("blade", 150);
	set_skill("force", 150);
	set_skill("halberd",150);
	set_skill("bixue-xinfa", 150);
	set_skill("kuangfeng-dao", 150);
	set_skill("longfeng-xiang", 150);
	set_skill("huzhua-shou", 150);
	set_skill("lujia-ji", 150);
	map_skill("force", "bixue-xinfa");
	map_skill("dodge", "longfeng-xiang");
	map_skill("parry", "huzhua-shou");
	map_skill("hand", "huzhua-shou");
	map_skill("blade", "kuangfeng-dao");
	map_skill("halberd", "lujia-ji");
	
	prepare_skill("hand", "huzhua-shou");
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 50);
	set_temp("apply/armor", 50);

  set("inquiry", ([
    "兑奖" : "给我凭条，我根据凭条给你对应物品。\n"
  ]) );

	setup();
	carry_object("/clone/weapon/fangtianji")->wield();
	carry_object(__DIR__"obj/mingguang-jia")->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("cakiller")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

int accept_fight(object me)
{
	command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
	me->apply_condition("cakiller", 60);
	kill_ob(me);
	return 1;
}

int accept_object(object me, object ob)
{
  object env=environment();
  mixed *flist, file;
  int lp;
  object *item;
  
	if( ob->query("id")=="duijiang pingzheng" &&
	    ob->query("type")==env->query("type") )
  {
    if ( arrayp(ob->query("file")) )
    {
      flist=ob->query("file");
      item=allocate(sizeof(flist));
      for ( lp=0; lp<sizeof(flist); lp++ )
      {
        if ( stringp(flist[lp]) )
        {
          item[lp]=new(flist[lp]);
          if ( ob->query("rent_time") )
          {
            item[lp]->set("rent_time", ob->query("rent_time") );
            item[lp]->auto_dest();
          }
          item[lp]->move(me);
        }
        else if ( arrayp(flist[lp]) )
        {
          item[lp]=new(flist[lp][0]);
        //目前仅支持fitem中字符串列表定义的物件元素为2或者3的情况，分别为仅带一个初始化函数或者一个初始化函数加一个参数
          if ( sizeof(flist[lp])==2 )
            call_other(item[lp], flist[lp][1]);
          else
            call_other(item[lp], flist[lp][1], flist[lp][2]);
        
          if ( ob->query("rent_time") )
          {
            item[lp]->set("rent_time", ob->query("rent_time") );
            item[lp]->auto_dest();
          }
          item[lp]->move(me);
        }
        if ( !item[lp]->query("owner") )
          item[lp]->set("owner", me->query("id") );
        tell_object(me, "库房守卫从库房中领出"+item[lp]->name()+"交给了你。\n");
      }
    }
    else
    {
      file=ob->query("file");
      item=allocate(10);
      item[0]=new(file);
      if ( ob->query("rent_time") )
      {
        item[0]->set("rent_time", ob->query("rent_time") );
        item[0]->auto_dest();
      }
      if ( !item[0]->query("owner") )
        item[0]->set("owner", me->query("id") );
      item[0]->move(me);
      tell_object(me, "库房守卫从库房中领出"+item[0]->name()+"交给了你。\n");
    }
    call_out("dest_ob", 1, ob);
    return 1;
  }
  else
    return notify_fail("库房守卫并没有接受你的礼物。\n");
}

void dest_ob(object ob)
{
  if ( objectp(ob) )
    destruct(ob);
}