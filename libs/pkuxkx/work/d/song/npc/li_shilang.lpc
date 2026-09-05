#include <ansi.h>
inherit __DIR__"song_officer";
#include "/d/song/config/mokan.h"
int ask_yin();
void create()
{
	call_out("npc_to_player",1,"吏部侍郎",50,-1);
	set("profession","武");
	set("mokan_high",4);
	set("mokan_low",6);
	set("inquiry", ([
	
		 "印信": (: ask_yin :),
		 "yin": (: ask_yin :),
		]));
	::create();
}

int dest(object ruyi)
{
	if(ruyi)
	destruct(ruyi);
	return 1;
}

int accept_object(object me, object ruyi)
{
    int n;
	if (ruyi->query("jade_ruyi")!=1)
	    return notify_fail(this_object()->query("name")+"不想要你的东西。\n");
    else
    {
        n=4+random(3);
        message_vision(this_object()->query("name")+"接过$N手里的嘉奖令，仔细阅读起来……\n",me);
        message_vision(this_object()->query("name")+"把嘉奖令封存起来，并仔细记下了$N的功绩。\n",me);
        me->add_busy(1);
        me->add("song/credit",n);
        tell_object(me,this_object()->query("name")+"在你名下功绩添上了"+chinese_number(n)+"点。\n");
		ruyi->move(VOID_OB);
        call_out("dest",1,ruyi);
        return 1;
    }
    
}

int ask_yin()
{
	object me=this_player(),*ob,gy;
	string theyin;
	if (!me->query("song/pro"))
	{
		command("say 你昏头了吧？到吏部来要东西？");
		return 1;
	}
	if (me->query("song/pro")=="文")
	{
		theyin="/d/song/obj/guanyin";
	}
	else if (me->query("song/pro")=="武")
	{
		theyin="/d/song/obj/peijian";
	}
	else if (me->query("song/pro")=="宦")
	{
		theyin="/d/song/obj/fuchen";
	}
	ob=all_inventory(me);
    for (int i=0;i<sizeof(ob);i++)
    {
		if (member_array(ob[i],children(theyin))!=-1)
		{
			command("say 你身上不是有一"+ob[i]->query("unit")+ob[i]->query("name")+"吗？");
			return 1;
		}
	}
	gy=new(theyin);
	gy->set("owner",me->query("id"));
	gy->move(me);
	message_vision("$N拿出新的"+gy->query("name")+"递给了$n。\n",this_object(),me);
	command("say 拿去吧，可要好好保管了。");
	return 1;
}