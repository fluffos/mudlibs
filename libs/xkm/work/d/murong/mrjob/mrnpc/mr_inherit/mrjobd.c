/************************
File:   Mrjobd.c
Create: Play
Time:   4/25/2002
*************************/
//void do_start_move();

void create(){
	seteuid(getuid());  
	__FILE__->start_move();
}
mixed snoop_path = ([
//"beijing":"changanjie_e.c",	
//"chengdu":"dongdajie1.c",	
"dali":"dalicheng4.c",	
"foshan":"qzroad2.c",	
"hangzhou":"tianzhu2.c",	
"jiaxing":"nanhu1.c",	
"quanzhou":"chxiang.c",	
"xixia":"luorilin.c",	
]);

mixed ask_path = ([
//"beijing":"tianqiao.c",
//"chengdu":"xidajie1.c",
"dali":"dalicheng16.c",
"foshan":"street0.c",
"hangzhou":"longjin0.c",
"jiaxing":"chating.c",
"quanzhou":"taoran.c",
"xixia":"beidajie.c",
]);

int start_move()
{
	string *a_path, *s_path;
	string room,room_2;
	int i, j;
	
	a_path = keys(ask_path);
	s_path = keys(snoop_path);

	for(i=0;i<sizeof(s_path);i++)
	{
		room = "/d/"+s_path[i]+"/"+snoop_path[s_path[i]];
                if(!room->query("exits/gate") ||
                    room->query("exits/gate")!="/d/murong/mrjob/mrmove/"+s_path[i]+"/zhumen.c")
                    room->set("exits/gate","/d/murong/mrjob/mrmove/"+s_path[i]+"/zhumen.c");
                if(!room->query("no_clean_up"))
                  room->set("no_clean_up", 1);
        }
	for(j=0;j<sizeof(a_path);j++)
	{
		room_2 = "/d/"+a_path[j]+"/"+ask_path[a_path[j]];
                if(!room_2->query("exits/enter") ||
                    room_2->query("exits/enter")!="/d/murong/mrjob/mrmove/"+a_path[j]+"/chaguan.c")
        	    room_2->set("exits/enter","/d/murong/mrjob/mrmove/"+a_path[j]+"/chaguan.c");
                if(!room_2->query("no_clean_up"))
                  room_2->set("no_clean_up", 1);
        }
        remove_call_out("start_move");
	call_out("start_move",30);

        return 1;
}