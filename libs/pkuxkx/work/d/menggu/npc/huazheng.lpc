// huazheng
// create by zine Aug 30 2010
#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIW+"华筝公主"+NOR, ({"huazheng gongzhu","huazheng","hua","gongzhu"}));
	set("long", "她是铁木真宠爱的女儿——华筝公主。\n"NOR);
	set("gender", "女性");
	set("age", 15);
    set("no_get", "铁木真的公主你也敢抢？还想活着离开草原吗？\n");
    set("is_huazheng",1);
    set("is_for_shediao_quest",1);
    set("combat_exp", 10000);
    set_skill("unarmed", 25);
    set_skill("force", 25);
    set_skill("dodge", 40);
	set("per",40);
    set_temp("apply/attack", 5);
    set_temp("apply/defense", 5);
	set("shen_type", 1);
	set("uni_target","zine");
    setup();
	carry_object(__DIR__"items/pixue")->wear();
	carry_object(__DIR__"items/cloth10")->wear();
	
}
	
void die()
{
    fullme();
    return;
}

void unconcious()
{
    die();
}

void init()
{
    object me=this_player();
    add_action("do_follow","follow");
    if (me->query_temp("shediaoquest/shediao_step2a"))
    {
        me->delete_temp("shediaoquest/shediao_step2a");
        message_vision("$N道：“$n，你舍得来了？快跟我过去吧。”\n",this_object(),me);
        message_vision("$N道：“东面那些大雕打得真厉害呢，快去瞧。”\n",this_object());
        command("lead "+me->query("id"));
        me->set_temp("shediaoquest/shediao_step1",1);
        me->set_temp("shediaoquest/shediao_refuse_hua",1);
    }
}

int look_diao(object ob,object me)
{
    command("xixi");
    command("say 我们快过去吧！");
    command("northwest");
    command("northwest");
    command("northwest");
    command("southwest");
	command("southwest");
    if (environment(me)==environment(this_object()))
    {
		me->delete_temp("shediaoquest/shediao_step2");
		me->set_temp("shediaoquest/shediao_step3",1);
		me->move("/d/menggu/shanqian");
		me->move("/d/menggu/xuanyaqian");
		message_vision("$N按照$n的吩咐，到周围看看大雕的踪迹。\n",me,this_object());
    }
	return 1;
}

int do_follow(string arg)
{
    object me=this_player();
    if (!me->query_temp("shediaoquest/shediao_step1")||(arg!="huazheng gongzhu"&&arg!="huazheng"&&arg!="hua"&&arg!="gongzhu"))
    {
        return 0;
    }
    me->delete_temp("shediaoquest/shediao_step1");
    me->set_temp("shediaoquest/shediao_step2",1);
    call_out("look_diao",5,this_object(),me);
    return 0;
}

int hua_2(string arg,object ob,object me)
{
    me->delete_temp("shediaoquest/shediao_step1");
    if (arg=="Yes"||arg=="Y"||arg=="yes")
    {
        write("决定了，就快点过去吧！别拖拖拉拉的。\n");
        me->set_temp("shediaoquest/shediao_step2a",1);
    }
    else
    {
        write("你决定不去理睬华筝！还是继续练习射箭吧。\n");
        me->set_temp("shediaoquest/shediao_step2b",1);
        call_out("greeting2",3,me);
    }
    return 1;
}

int hua_1(string arg,object ob,object me)
{
    if (arg=="Yes"||arg=="Y"||arg=="yes")
    {
        message_vision("$N回过头来，见$n骑在匹青骢马上，一脸焦虑与兴奋的神色。\n",me,ob);
        message_vision("$N道：“怎么？”\n",me);
        message_vision("$N道：“快来看啊，好多大雕打架。”$n道：“我在练箭呢。”\n",ob,me);
        message_vision("$N道：“那些大雕打得真厉害呢，快去瞧。”\n",ob);
        command("lead "+me->query("id"));
    }
    else
    {
        command("angry");
        command("northwest");
        write(ob->name()+"似乎被你气跑了，你要不要追上去？(Yes or No)\n");
        input_to((:hua_2:),ob,me);
    }
    return 1;
}

int greeting(object me)
{
    object ob=this_object();
    ob->set("quest_owner",me);
    message_vision("$N正自怔怔出神，突然听到$n的声音在后叫道：“"+me->query("name")+"，快来，快来！”\n",me,ob);
    me->set_temp("shediaoquest/shediao_step1",1);
    write("你现在想搭理华筝吗？(Yes or No)\n");
    input_to( (: hua_1 :),ob,me);
    return 1;
}

int greeting2(object me)
{
    object ob=this_object();
    object arrow=new("/d/menggu/obj/arrow-hua");
    if (!me)
    {
        destruct(ob);
        return 1;
    }
    message_vision("$N不知从哪里又走了回来，幽幽对$n道：“"+me->query("name")+"，难道你一直都那么讨厌我？”\n",ob,me);
    me->set("shediaoquest/shediao",1);//结局1
    arrow->move(me);
    command("say 罢了，我也无法强求，这个送给你留作纪念。");
    write(ob->name()+"送给你一把"+arrow->query("name")+"。\n");
    command("kiss "+me->query("id"));
    return 1;
}

int lean(object me)
{
	command("lean "+me->query("id"));
}

int lean2()
{
	CHANNEL_D->do_channel(this_object(), "jh", "blush", 1);
}
