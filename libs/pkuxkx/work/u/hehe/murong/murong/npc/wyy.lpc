//wyy.c
//by hehe
//2003.3.20
#include <ansi.h>
inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("王语嫣", ({ "wang yuyan", "wang" }));
	set("long", "她生得极为美貌,一双眼睛顾盼生辉.\n");
	set("title",HIM"曼陀罗山庄小姐"NOR);
	set("nickname", HIB"天下无不知"NOR);
	set("gender", "女性");
	set("age", 20);
	set("attitude","friendly");
	set("str", 10);
	set("dex", 40);
	set("con", 40);
	set("int", 40);
	set("per", 40);

	set("max_qi", 500);
	set("max_jing", 500);
	set("max_neili", 0);

    set("inquiry", ([
		"慕容复" : "他是我表哥，我有好久没有见到表哥了，不知何年何月....",
	]));           

    set("chat_chance",5);
    set("chat_msg",({
		"王语嫣自言自语到：“什么时候才能见到表哥哪！”\n",
        "王语嫣道：“谁又能帮我找到表哥哪？”\n", 
	}) );
//	carry_object(__DIR__"obj/skirt")->wear();
//	carry_object(__DIR__"obj/shoe")->wear();

	setup();

}
void init()
{
	add_action("do_look","look");
}

int do_look(string arg)
{
	object me=this_player();
	object obj=this_object();
	if(!arg)
	{
		return 0;
	}
	else if(((string)arg=="wang") || ((string)arg=="wang yuyan"))
	{
		message_vision(RED "\n$n实在是太美丽了，美丽的让人窒息.......\n\n" NOR, me, obj);
		message_vision(RED "\n$N气血上冲，$N晕了..................\n\n" NOR, me, obj);
		me->unconcious();
		return 1;
	}
	else
	{
		write("你要看哪位？\n");
		return 1;
	}
}

int accept_object(object me, object ob)
{
	object obb;
	me=this_player();

	if(ob->query("name")=="情书") 
	{
		if(me->query_temp("murong/qing"))
		{
    		command("wa");
			command("say 是表哥给我的信啊，多谢你了 !");
			command("say 既然你来到这里，就再麻烦你帮我把这个送给表哥吧!\n");
			obb=new("/d/murong/npc/obj/juan");
			obb->move(me);
			me->set_temp("murong/juan",1);
			me->delete_temp("murong/qing");
			return 1;
		}else
		{
			command("say 是表哥给我的信啊，多谢你了 !");
			command("say 既然你来到这里，就再麻烦你帮我把这个送给表哥吧!\n");
			return 1;
		}
	}
	else if(ob->query("name")=="扇子")
	{
		if(me->query_temp("murong/shan"))
		{
			command("kiss");
			command("say 表哥平安我就放心了。\n");
			command("say 你这么辛苦我就指点你一门刀法“五虎断门刀”吧。\n");
			me->improve_skill("wuhu-duanmendao",10);
			//加一点描述
			me->set_temp("murong/dzxy",1);
			return 1;
		}
		else
		{
			command("kiss");
			command("say 表哥平安我就放心了。\n");
			return 1;
		}
	}
	else
	{
		command("?");
		command("say 给我这个干嘛啊？\n");
		return 1;
	}
}
