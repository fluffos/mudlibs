// /d/guiyunzhuang/npc/danren.c
inherit NPC;
#include <ansi.h>
void create()
{
	set_name("炼丹人",({"liandan ren","ren"}));
	set("nickname","药师");
	set("long",@LONG
他是一位五十来岁的中年人,是归云庄的炼丹人.
他有一手好手艺,是陆庄主专门从江湖上炼丹匠中挑选出来的精匠.
LONG);
	set("str",20);
	set("age",58);
	set("max_qi",300);
	set("combat_exp",10000);
	set_skill("unarmed",20);
	set("shen_type",1);set("score",200);setup();
	carry_object("/d/city/obj/cloth")->wear();
}
int accept_object(object who, object ob)
{
	int flag;
        object obn;
        if( !who || environment(who) != environment() ) return 0;
        if ( !objectp(ob) ) return 0;
        if ( !present(ob, who) ) return notify_fail("你没有这件东西。\n");

	flag = query_temp("dan");
        if (  (string)ob->query("id") == "song guo" && ob->name() == "千年松果")
        if( flag & 1 )
        {
        	command("shake "+(string)who->query("id"));
        	message_vision("$N对$n说道: 我已经有千年松果了。\n", this_object(), who);
        	return 0;
	}
        else
        {
        	command("nod "+(string)who->query("id"));
        	set_temp("dan", query_temp("dan") | 1);
        	call_out("des", 1, ob);
        }

        else if (  (string)ob->query("id") == "xue lian" && ob->name() == "天山雪莲")
        if( flag & 2 )
        {
        	command("shake "+(string)who->query("id"));
        	message_vision("$N对$n说道: 我已经有天山雪莲了。\n", this_object(), who);
        	return 0;
	}
        else
        {
        	command("nod "+(string)who->query("id"));
        	set_temp("dan", query_temp("dan") | 2);
        	call_out("des", 1, ob);
        }

        else if (  (string)ob->query("id") == "jumang dan" && ob->name() == "巨蟒胆")
        if( flag & 4 )
        {
        	command("shake "+(string)who->query("id"));
        	message_vision("$N对$n说道: 我已经有巨蟒胆了。\n", this_object(), who);
        	return 0;
	}
        else
        {
        	command("nod "+(string)who->query("id"));
        	set_temp("dan", query_temp("dan") | 4);
        	call_out("des", 1, ob);
        }

        else if (  (string)ob->query("id") == "laoshan shen" && ob->name() == "老山参")
        if( flag & 8 )
        {
        	command("shake "+(string)who->query("id"));
        	message_vision("$N对$n说道: 我已经有老山参了。\n", this_object(), who);
        	return 0;
	}
        else
        {
        	command("nod "+(string)who->query("id"));
        	set_temp("dan", query_temp("dan") | 8);
        	call_out("des", 1, ob);
        }

        else
        {
        	write("药师不需要这件东西。\n");
        	return 0;
        }

        if(query_temp("dan") == 15)
	{
		command("gongxi "+(string)who->query("id"));
		who->start_busy(3);
		write( HIY "只见药师将四种药材投入炼丹炉中，又加入一些\n"
          		   "不知是什么的药粉，然后不停地用药匙搅拌！经\n"
          		   "过一段时间『"NOR + YEL"女娲石"HIY"』终于做成了。\n" NOR );
		message_vision("药师将"YEL"女娲石"NOR"递给$N。\n", who);
   		obn = new("/d/guiyunzhuang/obj/nvwashi");
   		obn->move(who);
   		set_temp("dan",0);
	}
	return 1;
}

void des(object ob)
{
	destruct(ob);
}

