//大理三公的公共部分，实际上和四大卫护的差不多

void init()
{
	object ob=this_object();
	object me=this_player();
    
    if ( me->query_condition("kill_dali") 
        && ob->can_act() )
    {
        remove_call_out("kill_him");
        call_out("kill_him", 1, me);
    }
}

void kill_him( object me)
{
    message_vision( "$N对着$n大喝一声：“杀人放火的强盗，快快受死吧！！！” \n", this_object(), me );
    kill_ob(me);
}

int accept_object( object me, object obj)
{
	if ( obj->query("id")!="ling pai" )
	{
		command("say “多谢美意，不过这东西对我好象没有什么用。”");
		return 0;
	}
	if ( obj->query("id")=="ling pai" )
	{
		message_vision("$N看了看$n，说：“原来是侯爷引荐来的。”\n",
				this_object(), obj);
		remove_call_out("do_recruit2");
		call_out("do_recruit2", 1, me, obj);
		return 1;
	}
}

int do_recruit2( object me, object obj )
{
	object ob=this_object();
	destruct( obj );
	if ( !me->query_temp("marks/段/拿到令牌2") )
	{
		message_vision("$N奇怪地看着$n：“这令牌上怎么没有你的名字啊？奇怪……”\n",
				ob, me);
	}
	else
	{	
   		command("nod "+ me->query("id") );
    	command("say 好吧，既然侯爷有令，你以后就跟我学功夫罢。");
    	message_vision( @LONG
$N想要收$n为弟子。

$n决定拜$N为师。

$n跪了下来向$N恭恭敬敬地磕了四个响头，叫道：「师父！」

LONG, ob, me);
        tell_object( me, "恭喜您成为镇南王府"+ob->query("name")+"的弟子。\n");	    	
	    me->set("family/master_id", ob->query("id"));
	    me->set("family/master_name", ob->query("name"));
    	me->save();
	    LOG_D->do_log(me, "你得到鄯阐侯高升泰的赏识，获准向" + ob->query("name")
		    	+ "学习进一步的武功。");	
	}
	return 1;
}

int refuse_killing()
{
    int i;
    object *inv, who;

	who=this_player();
    who->apply_condition("kill_dali", 350);
    if( this_object()->query("id")=="fan hua" ) command( "wield blade" );
    inv = all_inventory( environment(this_object()) );
    for(i = 1; i < sizeof(inv); i++)
    {
        if ( userp(inv[i])
            && inv[i]->can_act()
            && inv[i]->query("class")=="duanshi"
            && inv[i] != who )
            inv[i]->kill_ob(who);
        if( inv[i]->query("id")=="fan hua" ) inv[i]->command( "wield blade" );
    }
    return 0;
}

#include "greeting.h"