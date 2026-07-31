// cracked by vikee 2/09/2002   vikee@263.net
//renshenguo-yuan.c

inherit ROOM;

void create ()
{
	set ("short", "人参果园");
	set ("long", @LONG

好大的一遍人参果园！巨大的果树上吊着一枚枚令人垂涎欲滴的
人参果。只是不知道怎样才能弄将下来。据说这人参果娇贵无比，
要是乱摘一气什么都吃不上。
LONG);

	set("exits", 
	([ //sizeof() == 4
	]));
	
	set("objects", 
	([ //sizeof() == 1
	]));

	set("outdoors", "wuzhuang");

	setup();
}

void init()
{
	object me, zhenyuan;

	me = this_player();

	if( me->query_temp("used_huangtong_key") == 1 )
	{
		me->delete_temp("used_huangtong_key");
		
		message_vision("只听几声哈哈大笑，镇元大仙走了出来。\n", me);
		message_vision("镇元大仙说道：居然被你发现了。那我们就开个人参果大会吧！\n\n\n", me);

   add_action("do_clear","clear");
		if( !objectp(zhenyuan=present("zhenyuan daxian", environment(me))) )
		{//if zhenyuan already here, we do not need creat another one.
			zhenyuan = new(__DIR__"npc/zhenyuan");
			zhenyuan->move(environment(me));
		}
		zhenyuan->start_renshen();
	}
}

int do_clear() {
  object me=this_player();
  object *env=all_inventory(this_object());
  object zhenyuan=present("zhenyuan daxian",this_object());

  if (!zhenyuan) return notify_fail("镇元大仙不在。\n");
  if (!env) return 0;
  message_vision("$N冲着$n小声嘀咕：“这么多人，人参果园变菜市场了。。。”\n",me,zhenyuan);
  message_vision("$N皱了皱眉，突然朗声道：“我五庄观乃道家修身练道之清净所在，闲杂人等一律请回。”\n",zhenyuan);

  for (int i=0;i<sizeof(env);i++)
   if (env[i]!=me && userp(env[i]) && env[i]->query("daoxing")<10000) zhenyuan->send_back(zhenyuan,env[i]);
  return 1;
}
