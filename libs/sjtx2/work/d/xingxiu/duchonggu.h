//caiji@SJ 8/24/2000

inherit ROOM;
#include <room.h>
#include <ansi.h>

void create ()
{
  	int north=(POS/10+4)%5*10+POS%10,south=(POS/10+1)%5*10+POS%10,
      	east=POS/10*10+(POS%10+1)%5,west=POS/10*10+(POS%10+4)%5;
  	set ("short", "毒虫谷");
  	set ("long", @LONG
一片平坦谷地，四周是大山环绕。四周阴沉沉的，气氛十分恐怖。谷内
瘴气四起，各种毒物，不计其数，地下都是陈年腐草败叶烂成的软泥。寒风
从山谷通道中刮进来，吹得你肌肤隐隐生疼。
LONG);

  	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"duchonggu"+north,
		"south" : __DIR__"duchonggu"+south,
		"east" : __DIR__"duchonggu"+east,
		"west" : __DIR__"duchonggu"+west,
	]));
	set("outdoors","星宿海");

	if(POS%5==0) set("exits/southeast", __DIR__"duchonggu-out");

	if(POS%3)
	set("objects",([
		FOOD_D("hulu") : 2,
		FOOD_D("xzhang") : 1,
	]));

	setup();

  	setup();
}

void init() 
{
        mapping fam=this_player()->query("family");
        add_action("do_action", ({"exert"}));

	if (present("du chong")) return;
	if( this_player()->query_temp("xx_job4")
	 && mapp(fam)
	 && fam["family_name"] =="星宿派"
	 && this_player()->query_condition("job_busy")){
		add_action("do_burn", "burn");
		add_action("do_catch", "dai");
		remove_call_out("greeting");
		if(!random(4)){
			call_out("greeting",1,this_player(),this_object());
			this_player()->start_busy(2+random(2));
		}
	}
}

void greeting(object me,object env)
{
	object staff;
	if (!me || environment(me)!=env) return;
	tell_object(me,BLU"忽听得草丛中瑟瑟声响，绿草中一物晃动，你不禁停了下来，想看个究竟。\n"NOR);
	me->set_temp("xx_burned",1);
	if(POS==(random(5)*10+random(5)) && (string)me->query("family/family_name")=="星宿派" &&
	(int)me->query_skill("huagong-dafa", 1) > 100){
		staff=unew(BINGQI_D("sword/qm-jian"));
		if(staff) {
			destruct(staff);
			staff=unew(BINGQI_D("staff/gangzhang-sp"));
		}
		if(staff){ 
			staff->move(environment(me));
			message_vision("在草丛中，$N还发现另一个奇怪的事物，仔细一看，原来是一根普通的钢杖。\n",me);
		}
		return;
	}
}

int do_burn(string arg)
{
	int costj;
	object me;
	me = this_player();
	if( arg != "liuhuang" && arg!="liu huang")return notify_fail("你想点燃什么来引虫子？\n");
	if (me->is_busy()) return notify_fail("你现在正忙着呢！没法静下心来烧东西引虫子！\n");
	if (me->is_fighting()) return notify_fail("你正在战斗中，无法腾出空来引虫子！\n");
	if (!present("fire", me)) return notify_fail("你没有火折，如何引火？\n");
	if (!present("liu huang", me)) return notify_fail("你没有引火之物，如何引火？\n");

	costj = random((int)me->query("int")/2)+2;

	me->add("jingli", -costj);
  
	message_vision("$N从硫磺上捏了一小块，放在地上，用火折点燃，烧了起来。\n",me);
	me->start_busy(1+random(2));
	if(!random(2))call_out("greeting",1,this_player(),this_object());
	else message_vision("这里的虫子似乎已经被其他人抓光了，你只好去其他地方试一试了。\n",me);
	return 1;
}

int do_catch(string arg)
{
	int costj;
	object me;
	me = this_player();
	if(!me->query_temp("xx_burned")) return notify_fail("你还没有把虫子引出来。\n");
	if( arg != "chongzi" && arg!="chong zi")return notify_fail("你想逮什么东东\n");
	if (me->is_busy()) return notify_fail("你现在正忙着呢！没法静下心来抓虫子！\n");
	if (me->is_fighting()) return notify_fail("你正在战斗中，无法腾出空来抓虫子！\n");
	if (!me->query_condition("xx_catch")) return notify_fail("你现在不能抓虫子，好象老仙没允许你进来吧！\n");

	costj = random((int)me->query("int")/2)+2;

	me->add("jingli", -costj);

	message_vision("$N向前一扑，想进一步接近这只虫子。\n",me);
	me->start_busy(1+random(3));
	if(!random(3)) call_out("greeting1",2,me,this_object());
	else message_vision("虫子被$N一吓，钻入草丛不见了。\n",me);
	return 1;
}

void greeting1(object me,object env)
{
	object chongzi;

	if (!me || !env || environment(me)!=env) return;
	chongzi=new(__DIR__"obj/duchong");
	chongzi->move(env);
	chongzi->set("target",me);
	chongzi->do_copy(me);
	tell_object(me,MAG"你的眼前一亮，原来是一只"+chongzi->name()+MAG+"全身闪光，头上凸起，与寻常毒虫大大不同。\n\n"NOR);
}

int valid_leave(object me, string dir)
{
	me->delete_temp("xx_burned");
	return ::valid_leave(me, dir);
}

int do_action(string arg)
{
	if(!arg){
		write("噶哈？你想噶哈？\n");
		return 1;
	}
	if(arg == "roar"){
		write("谷里这么寂静，你瞎嚷嚷什么！\n");
		return 1;
	}
}
