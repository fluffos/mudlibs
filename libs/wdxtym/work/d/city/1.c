// Room: /city/wumiao.c
// YZC 1995/12/04 

#include <room.h>

inherit ROOM;

int is_chat_room() { return 1; }

void create()
{
	set("short", "岳王庙");
	set("long", @LONG
这里是岳王庙的正殿，内有岳飞像，像上方悬挂岳飞手书“还我河山”的
横匾。殿两侧壁上嵌着“尽忠报国”四个大字。武人到此，都放下武器，毕恭
毕敬地上香礼拜。旁边似乎有一道侧门。
LONG );
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_learn", "1");
	set("no_study", "1");
	set("no_learn", "1");
	set("no_dazuo", "1");
	set("no_sleep_room", "1");

	set("valid_startroom","1");
	set("objects", ([
		__DIR__"obj/box" : 1,
	]));

	set("action_list", ([
		"每日任务" : "day_sign",
	]));

	set("exits", ([
		"east" : __DIR__"beidajie2",
		"north"   : __DIR__"wumiao2",
		"upnorthwest": "/d/wizard/guest_room",
		"south": "/d/fuben/ciyuan",
	]));
	create_door("northwest", "竹门", "southeast", DOOR_CLOSED);
	setup();
}

void init()
{
	add_action("mrrw","day_sign");
}

int valid_leave(object me, string dir)
{
      if (dir=="northwest"&& me->query("id")=="xiguazi" )
		return notify_fail("你因为不看更新公告进不去此地。\n");		
		
	if (dir == "northwest" && ! userp(me) && ! me->is_chatter())
		return 0;
	return ::valid_leave(me, dir);
}

int mrrw(string arg)
{
	object me=this_player();
	string type;
	string msg="", line="";
if (!arg) {
		msg = ZJOBLONG+
		      "目前游戏中的日常任务如下[更新中]：\n";
		msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += "武馆训练["+me->query("fuben/wuguan/mun")+"/3]:day_sign wuguan";
		msg += ZJSEP"伏击金兵["+me->query("fuben/jinbing/mun")+"/3]:day_sign jinbing";		
	}
	else if(arg=="wuguan"){
	msg = ZJOBLONG+"扬州武馆[武馆训练]："ZJBR
	                  "————————————————"ZJBR
                      "新手专属副本"ZJBR
                      "初入江湖难免行走困难，武馆是新人学艺初始的好地方，江湖之路从武馆学艺开始。\n";
	msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += "立即前往:day_sign wuguan2";	
	}
	else if(arg=="wuguan2"){ 
	me->move("d/city/wuguan/qianting");	
	}
	else if(arg=="jinbing"){
	msg = ZJOBLONG+"关外宁远镇[伏击金兵]："ZJBR
	                  "————————————————"ZJBR
                      "金国一直对我中原贼心不死，经常派密探进入关内刺探军情，阻击密探可获得丰厚奖励。\n";
	msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += "立即前往:day_sign jinbing2";	
	}
	else if(arg=="jinbing2"){ 
	me->move("d/guanwai/ningyuan");	
	}	
	write(msg + "\n");			
	return 1;
}