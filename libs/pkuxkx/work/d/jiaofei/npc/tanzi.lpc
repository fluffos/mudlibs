//Created by whuan@pkuxkx
//投名状任务：劫镖任务之探子
inherit NPC;
#include <ansi.h>

int leave();

void create()
{
		string name,*tmp,*pinying;
	  set("chat_chance",10);
		name=NAME_D->create_name();
		tmp=explode(name,"@");
		pinying=explode(tmp[1]," ");
		set_name(tmp[0],({tmp[1],"tan zi",pinying[0],pinying[1]}));	
		set("nickname",HIC"铁掌帮探子"NOR);
		set("gender",random(3)>0?"男性":"女性");
		set("no_get",1);
	  set("uni_target",1);
		set("age",20);
	  setup();
}

void init()
{
		object me;        
		::init();   
		if( interactive(me = this_player()) ) {
			remove_call_out("greeting");
			call_out("greeting", 1, me);
		}
}

void greeting(object me)
{
		object ob=this_object();
		if(me->query("id")==ob->query("master") && !ob->query_temp("met")) 
		{
			ob->add_temp("met",1);//加入一个标记记录已经会面
			command("hi");
			command("say 我已经打探到镖队马上就到，我们就在这里等着他们来吧。");
      remove_call_out("wait_target");
      call_out("wait_target", 30, ob, me);
		  return; 				
	  }
}

int wait_target(object ob, object me)
{
      object obj;
      if( !objectp(present(me, environment(ob))) ) {
              message_vision("$N说道：耶？那家伙怎么不见了？那我也走了！\n", ob);
              destruct(this_object());
              return 1;
      }
      if( !objectp(ob = present("tan zi", environment(me))) ) {
              tell_object(me,"你发现探子不见了，只好转身离开。\n");
              tell_room(environment(me), me->name()+"突然一脸茫然的表情，看来是想要离开了。\n", ({ me }));
              return 1;
      }

      obj = new(__DIR__"biaodui");
      obj->set("owner", ob->query("master"));
      obj->destme();            
      obj->move(environment(me));
      message_vision(HIY"\n只听一阵隆隆的车轮声传来，一支福威镖局的镖队出现在眼前！\n\n"NOR, ob);
      tell_object(me,"猎物终于出现了！\n");
      message_vision(HIY"$N对着$n大声道：你快抢(rob)镖队，我先闪了！\n"NOR, ob, me);
      message_vision("$N匆匆忙忙离开了！\n",ob,me);
      destruct(this_object());
}


void start_leave()
{
		call_out("leave", 300);
}
void die()
{
    object me,killer;
    me = this_object();
    if (objectp(killer = me->get_damage_origin_object()))
      CHANNEL_D->do_channel(this_object(), "bd", killer->name() + "！我们无冤无仇，你为何要杀我？！");
    else
    	CHANNEL_D->do_channel(this_object(), "bd", "xbc97", 1);
    ::die();
}

void unconcious()
{
	die();
}
int leave()
{
	if (!this_object()) return 1;
	CHANNEL_D->do_channel(this_object(), "bd", "push "+this_object()->query("master"), 1);
	CHANNEL_D->do_channel(this_object(), "bd", "靠！" + this_object()->query("master") + "你搞什么飞机啊，镖队已经走了，害我白等了你半天！");
	if (environment(this_object()))
		message_vision("$N转身走了。\n",this_object());
	destruct(this_object());
	return 1;
}
