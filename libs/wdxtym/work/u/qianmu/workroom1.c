inherit ROOM;

void create()
{
	set("short", "¹¤×÷ÊÒ");
	set("long", "¹¤×÷ÊÒ\n");

	set("action_list", ([
		"²âÊÔ" : "test",
		]));
	
	setup();
}

void init()
{
	add_action("do_test", "test");
	add_action("do_test2", "test2");
	add_action("do_dest_item", "dest_item");
}

int do_test2()
{
	tell_room(this_object(), "²â²âÊÔÊÔÊÔ\n"NOR);
	return 1;
}

int do_test(string arg)
{
	object who = this_player();
    object room;

mapping id = ([

"1ÕËºÅ" : "chilly27",
"2ÕËºÅ" : "egg579aa1",
"3ÕËºÅ" : "cdm106",
"4ÕËºÅ" : "a101100",
"5ÕËºÅ" : "g2585729683",
"6ÕËºÅ" : "yjn19158217",
"7ÕËºÅ" : "w111111111",
"8ÕËºÅ" : "g3584721",
"9ÕËºÅ" : "meloding",
"10ÕËºÅ" : "wzwzwz1103",
"11ÕËºÅ" : "z948653949",
"12ÕËºÅ" : "chufengliu",
"13ÕËºÅ" : "rubina",
"14ÕËºÅ" : "zhuao",
"15ÕËºÅ" : "yygysss",
"16ÕËºÅ" : "a2273099224",
"17ÕËºÅ" : "h847681409",
"18ÕËºÅ" : "jn01",
]);
    string temp;

    foreach(temp in values(id))
    {
        log_file("id_buchang", "\"" + temp + "\",\n");
    }


    
	// who->start_busy((: call_other, __FILE__, "start" :),
	// 				(: call_other, __FILE__, "end" :));
    //room = new("/d/jingjichang/room");
    //who->move(room);
	//"/d/fuben_huanjing/huanjing"->start_fuben(who);
	return 1;
}

int start()
{
	return 1;
}

int end()
{
	write("ÄãÍ£Ö¹ÁË¡£\n");
	return 1;
}

int do_dest_item(string arg)
{
    object * obs;
    object temp;
    
    obs = children(arg);
    foreach(temp in obs)
    {
        log_file("xxxxxxxxx", "ÄãÇå³ıÁË" + sprintf("%O\n",all_inventory(temp)) + "¡£\n");
        
        //temp->end_fuben_moku();
        //destruct(temp);
    }
}