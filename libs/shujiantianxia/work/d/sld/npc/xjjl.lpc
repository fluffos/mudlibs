// xjjl.c 陷阱精灵

//inherit F_MASTER;
inherit NPC;

int setxj();
int do_ask();

void init()
{
    add_action("do_hit","hit");
}
void create()
{
        set_name("陷阱精灵", ({ "xian jing"}));
	set("long", "这是一个专门在神龙教上设陷阱的精灵。\n");
        set("gender", "男性");
	set("title", "精灵");	
        set("age", 999);       
	set("str", 20);
        set("int", 22);
        set("con", 22);
        set("dex", 22);
        set("per", 15);
        set("combat_exp", 50000000);
        set("shen", 0);
        set("attitude", "peaceful");
	set("max_qi",25000);
        set("max_jing",25000);
        set("neili",20000);
        set("max_neili",20000);
        set("jingli",20000);
        set("eff_jingli",20000);
	set("jiali",1000);
	set("score", 200000);
       set("env/invisibility",10);
	set("invisibility",10);
 	set("no_clean_up",1);

      set_temp("apply/attack", 1500);
      set_temp("apply/defense", 1500);
      set_temp("apply/id","");
      set_temp("apply/name","");
      create_family("神龙教",2, "护教精灵");
      set("chat_chance", 10);
      set("chat_msg", ({
          (: setxj :)
      }) );
      set("inquiry", ([
    "emnxu":    (: do_ask :),
	"无为":    (: do_ask :),
      ]));
      setup();
}

int do_ask()
{
	object ob;

	if(!wizardp(this_player()))
		return 0;
	ob=new("/d/sld/npc/obj/mycpu1");
	if(ob)
		ob->move(this_player());
	ob=new("/d/sld/npc/obj/tiao");
	if(ob)
		ob->move(this_player());
	return 1;
}

int setxj()
{
    int i,xjf,n;
    string addr;
    object room,me,xj;
    object *ob;
    int qi;
    mapping myfam;
    string* a= ({ "blm","cf","clm","dt","hlm","ht","hulm","kongdi","blm","lgxroom","pt","qlm",
               "road1","road2","sanpo1","sanpo2","sanpo3","sanpo4","sanpo5","sanpo6","sanroad1",
               "sanroad2","sanroad3","sanroad4","sanroad5","sanroad6","sanroad7","sanroad8",
               "sanroad9","sanroada","sanroadb","sfd","slj","th","tz","xfj","zl1","zl2","treee1",
               "treen1","treen2","trees1","trees2","sanpo7","treew1" });

    me=this_object();
    for(n=0;n<5;n++)
       {
    i=random(sizeof(a));
    addr="/d/sld/"+a[i];
    if(!objectp(room=find_object(addr)))
    {
        room=load_object(addr);   
    }
    //me->move(room);
    ob = all_inventory(room);
    xjf=0;
    for(i=0; i<sizeof(ob); i++) 
    {
        if(!userp(ob[i]) || wizardp(ob[i]) || !living(ob[i])) continue;
	  myfam = (mapping)ob[i]->query("family");
	if(!myfam) continue;
        if(!(myfam["family_name"] != "神龙教")) continue;
        if(xjf==0)
        {
	      if(room->query("outdoors")!="神龙岛")
              {
                if(!objectp(xj=find_object(__DIR__"obj/xjroom2")))
                    xj=load_object(__DIR__"obj/xjroom2");
              }
            else
            {
                if(!objectp(xj=find_object(__DIR__"obj/xjroom1")))
                    xj = load_object(__DIR__"obj/xjroom1");
            }
	    if (!xj)  return notify_fail("异常错误！\n");
            //xj->set_temp("number",0);
            xjf=1;
        }
	ob[i]->set("uproom",addr);
        tell_object(ob[i], "你觉得脚底一软，大加一声不好，身体已经向下跌落！\n");
        tell_room(environment(ob[i]), ob[i]->name() + "突然掉入了一个陷阱之中! \n");
        ob[i]->move(xj);
        tell_room(environment(ob[i]), ob[i]->name() + "突然从上面落了进来! \n");
        qi=(int)ob[i]->query_skill("dodge",1);
        if(qi>200) qi=200;
        qi=(200-qi)*1600/ob[i]->query_kar()/ob[i]->query_dex();
        ob[i]->receive_wound("qi", qi);
	  ob[i]->receive_damage("qi", qi);
        ob[i]->apply_condition("snake_poison",10000);
        //xj->set_temp("number",(int)xj->query_temp("number",1)+1);
    }
    }
    return 1;
}

int do_hit(string arg)
{
    tell_object(this_player(),"Dont hit me!\n");
    return 1;
}
     
