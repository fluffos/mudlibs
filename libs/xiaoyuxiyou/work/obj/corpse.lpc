// corpse.c
inherit ITEM;

int decayed;
int do_mai(string);

void create()
{
	set_name("无名尸体", ({ "corpse" }) );
	set("long", "这是一具无名尸体。\n");
	set("unit", "具" );
	decayed = 0;
	setup();
	if( clonep(this_object()) ) 
        {
        	remove_call_out("decay");       
        	call_out("decay", 120, 1);
        }
}

int is_corpse() { return decayed < 2; }
int is_character() { return decayed < 1; }
int is_container() { return 1; }

string short() { return name() + "(" + capitalize(query("id")) + ")"; }

void decay(int phase)
{
	decayed = phase;
	switch(phase) 
        {
        	case 1:
                	say( query("name") + "开始腐烂了，发出一股难闻的恶臭。\n" );
                	switch(query("gender")) 
                	{
                        	case "男性":
                                	set_name("腐烂的男尸", ({ "corpse", "尸体" }) );
                                	break;
                        	case "女性":
	                                set_name("腐烂的女尸", ({ "corpse", "尸体" }) );
        	                        break;
                	        default:
                        	        set_name("腐烂的尸体", ({ "corpse", "尸体" }) );
                        }
                	set("long", "这具尸体显然已经躺在这里有一段时间了，正散发着一股腐尸的味道。\n");
                	remove_call_out("decay");
                	call_out("decay", 120, phase + 1);
                	break;
        	case 2:
	                say( query("name") + "被风吹干了，变成一具骸骨。\n" );
        	        set_name("一具枯干的骸骨", ({ "skeleton", "骸骨" }) );
                	set("long", "这副骸骨已经躺在这里很久了。\n");
	                set("is_skeleton",1);
        	        remove_call_out("decay");
                	call_out("decay", 60, phase + 1);
                	break;
        	case 3:
                	say( "一阵风吹过，把" + query("name") + "化成骨灰吹散了。\n" );
                	if( environment() ) 
                        {
                        	object *inv;
                        	int i;
                        	inv = all_inventory(this_object());
                        	for(i=0; i<sizeof(inv); i++) 
                                	inv[i]->move(environment());
                        }
                	destruct(this_object());
                	break;
        }
}

object animate(object who, int time)
{
	object zombie;

	if( !environment() ) 
		return 0;
	seteuid(getuid());
	zombie = new("/obj/npc/zombie");
	zombie->set_name( (string)query("victim_name") + "的僵尸", ({ "zombie" }) );
	zombie->move(environment());
	zombie->set_level(this_object()->query("level")/2+1);
	zombie->animate(who,time);
	destruct(this_object());
	return zombie;
}

void init()
{                                             
	add_action("do_mai", "mai");
	add_action("do_mai", "bury");
	add_action("do_shou","shouhun");
}

//收元神
int do_shou(string arg)
{
	string *strs;
	object ball,me = this_player();
	object ob = this_object();
	if( !arg || !id(arg) )
		return notify_fail("你要收什么尸身的魂？\n");
	if( ob->query("level")<10 )
		return notify_fail("这是凡人的尸骸。\n");
	if( me->query_level()<ob->query("level") )
	{
		if( random(me->query_spi()/10)<3 )
			return notify_fail("对方生前修为高过你，你感觉有点力不从心。\n");
	}		
	if( me->is_busy() || me->is_fighting() )
		return notify_fail("你先把手里的事忙完再说。\n");
	if( me->query("mana")<100 )
		return notify_fail("你法力不足。\n");	
	ball = present("souhun qiu",me);
	if( !ball || !ball->is_fabao() )
		return notify_fail("没有搜魂球，你如何搜取残魂？\n");
	if( ball->query("max_num")>0 )
	{
		if( ball->query("num")>=ball->query("max_num") )
			return notify_fail("搜魂球中残影翻滚，阴气弥漫，不时传出残魂的嘶叫。\n");
	}
	message_vision("$N捧着搜魂球，对着$n喃喃念了一通咒语。\n\n",me,ob);
	me->start_busy(1);
	me->add("mana",-81);
	if( random(me->query_level())>=ob->query("level")/2 )
	{
		message_vision("\n只见一道黑气从搜魂球上冒出，笼罩住地上$N，须臾之间便见一道模糊不清的小人身影浑浑噩噩，随着黑气身不由己的吸到搜魂球中。\n",ob);
		ball->add("num",1);
		strs = ball->query("owner_hun");
		if( !strs || !arrayp(strs) || sizeof(strs)<1 )
			strs = ({ ob->query("victim_name") });
		else if( member_array(ob->query("victim_name"),strs)==-1 )
			strs+= ({ ob->query("victim_name") });
		ball->set("owner_hun",strs);
		destruct(ob);
		return 1;
	}
	else
	{
		write("结果什么反应也没有。\n");
		return 1;
	}
}

int do_mai(string arg)
{
	object me = this_player();
	if( !arg || !id(arg) )
        	return 0;
	if(!environment(me)->query("mai_corpse_able"))
        	return err_msg("你不能在这里埋尸体！\n");
	if( random(3)==1) 
		me->add("potential",5);
	else if( random(3)==1) 
		me->add("daoxing", random(50));
	if(me->query("bellicosity")>10) 
		me->add("bellicosity", -10);
	me->receive_damage("kee", 5);
	me->delete("bury_corpse");
	me->add("mark/bury_corpse", 1);
	message_vision("$N在地下刨了个坑，把$n放了进去，用土埋了起来。\n", me, this_object());
	message_vision("$N对坟头鞠了个躬，道：怪你前世命短，好好修来生去吧！\n", me);
	destruct(this_object());
	return 1;
}