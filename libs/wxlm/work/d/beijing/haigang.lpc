

inherit ROOM;

void create()
{
	set("short", "东海之滨");
	set("long", @LONG
这里就是大海之滨，浪花拍打着礁石，发出阵阵响声，海面上一群群海
鸥『欧欧..』地叫着，不时有鱼儿跃出海面，溅起层层的浪花。边上有艘大
船(chuan)， 船上坐着几个渔夫打扮的人，乘船可渡过大海到达海的另一端。
西面一直走就是燕京了，东面是一望无际的大海。极目眺望不禁让人心胸开
扩，神舒意畅，的确是一个好居处。
LONG );
	set("exits", ([
		"west" : __DIR__"road10",
		"north" : "/d/tulong/tulong/haian",
	]));
	set("item_desc", ([
		"【大船】" : "一艘大帆船，造得很结实，看来可以出远海的。\n",
	]));
	set("objects", ([
		"/d/shenlong/npc/chuanfu" :1,
	]));
	set("action_list", ([
		"上船" :"shangchuan",
	]));
	set("max_room", 3);
	set("outdoors", "beijing");
	setup();
}

void init()
{
	add_action("moveto","shangchuan");
}

int moveto()
{
	object me = this_player();

      if (me->query("combat_exp", 1)<1000000 )
		return notify_fail("你这么点低微的武功恐怕无法跟高手们争夺屠龙刀吧？\n");
	if (!this_object()->query("open"))
		return notify_fail("你错过了出发时间(20:30-20:35)，只好等下一趟了。\n");
	me->move("/d/tulong/tulong/boat");
	tell_object(me,"请耐心在此等候片刻，稍后出发。\n");
	return 1;
}

int start_tulong()
{
	object boat;

	shout(HIR "\n【倚天屠龙】" NOR+WHT "白龟寿仰天一声长笑。" NOR );
	shout(HIR "\n【倚天屠龙】" NOR+WHT "白龟寿：我天鹰教得到屠龙宝刀，今日在王盘山岛举行扬刀立威大会。"NOR"\n" );
	set("open",1);
	if(!(boat=find_object("/d/tulong/tulong/boat")))
		boat=load_object("/d/tulong/tulong/boat");
	call_out("arrive1",300,boat);
	call_out("clear_tulong",1800);
	return 1;
}

int clear_tulong()
{
	mixed *files;
	string file;
	object *inv,room;
	int i,j;

	files = list_dirs("/d/tulong/tulong/");
	for(i=0;i<sizeof(files);i++)
	{
		file = "/d/tulong/tulong/"+files[i];
		if(file_size(file))
		{
			room = find_object(file);
			if(room)
			{
				inv = all_inventory(room);
				if(sizeof(inv))
				{
					for(j=0;j<sizeof(inv);j++)
					{
						if(playerp(inv[j]))
						{
							tell_object(inv[j],"你被强行离开了扬刀立威会场！\n");
							inv[j]->move("/d/beijing/haigang");
						}
					}
				}
			}
		}
	}
	CHANNEL_D->do_channel(this_object(), "chat", "屠龙刀剧情已结束。");
	return 1;
}

int arrive1(object boat)
{
	tell_room(boat,HIC "\n天鹰教的大船上，只听到舵子手喊道：“开船了！”，大船慢慢的向大海驶进。"NOR"\n");
	tell_room(boat,HIB "\n大船在大海上慢慢的漂着......你不禁感到睡意朦胧。"NOR"\n");
	this_object()->delete("open");
	call_out("arrive2",300,boat);
	return 1;
}

int arrive2(object boat)
{
	object *inv;
 

	tell_room(boat,"\n你突然听到一声惊喝：“到了，下船吧”！顿时提起精神，跟着天鹰教教众下了船。"NOR"\n");
	inv = all_inventory(boat);
	inv->move("/d/tulong/tulong/daobian");
	inv->set_temp("bishi",1);
	return 1;
}

int valid_leave(object me, string dir)
{
	if (dir == "north" && ! playerp(me))
		return 0;

	return ::valid_leave(me, dir);
}