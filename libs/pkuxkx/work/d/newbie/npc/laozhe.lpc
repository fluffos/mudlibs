//laozhe.c 菜园老者
//by zoom
//2003.4.2

inherit NPC;

void create()
{
        set_name("老者", ({ "lao zhe", "lao", "zhe" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long",
                "这就是经营这个菜园的老者，近些日子生意好了，菜园里的活有些忙不过来。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("shen_type",1);set("score",200);setup();
}

void init()
{
        add_action("do_work", "work");
}

int do_work()
{
        int times;
        object me=this_player();
	if((me->query("combat_exp"))>100)
		return notify_fail("这里只是新手练习的地方，不要在这浪费时间了。\n");
        if (!me->is_busy() )
        {
        times=random(10)+5;
	me->start_busy(times);
	message_vision("$N在菜地里干起活来...\n",me);
	me->set_temp("newbie_work",1); 
	call_out("end_work",5, me);
	return 1;
        }
	else 
	{
                tell_object( me, "你还忙着呢，等会再来吧。\n");
	}
        return 0;
}   
void end_work(object me)
{
        int a,b;
	int m;
    if (objectp(me)&&!living(me))
    {
        return;
    }
        if ( me->is_busy() )
	{
                tell_object( me, "你直起腰，歇了一会儿，继续干活......\n");
                call_out("end_work",5,me);
        }
        else
        {
                object qian;
               	a=5+random(5);
       	        b=a-5;
	        message_vision("老者朝$N挥挥手，$N急忙从菜地里出来。\n",me);
        	if(me->query("potential")<200)
        	{
         	        me->add("potential",b);
         	        me->receive_damage("jing", 10);
        	        tell_object(me,"你的潜能增加了" + chinese_number(b) + "点\n");
 
      		}
        	tell_object(me,"你的经验增加了" + chinese_number(a) + "点\n");
         	me->add("combat_exp",a);
	        command("say 这是你的报酬。");
	        message_vision("老者给了$N一些碎银子。\n",me);
	        qian=new("/clone/money/silver");
	        qian->move(me);
		
	}
return;
} 