// Room: /d/luoyang/lvzuan.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "吕祖庵");
	set("long",  @LONG
吕祖庵又叫吕祖庙，背依邙岭坡，面临深壑，壑内为清清流水。庵
红垣绿槐琉璃房，小巧玲珑，从崖下仰望，如见天空仙境。吕祖庵初为
茶庵，是行人饮茶歇脚之所。后改为道教场所。因庵中道人属全真派，
故香火敬起全真派“五祖”之一的吕洞宾，因施茶性质未变，且庙宇规
模较小，故仍称“吕祖庵”，亦称“纯阳洞”。 
LONG);
	set("exits",  ([  
		"southwest" : "/d/luoyang/mangshan",
	]));
        set("objects", ([
                "/d/jinyong/book8/luoyang/npc/fei" : 1,
                "/d/jinyong/book8/luoyang/npc/yao" : 1,
                "/d/jinyong/book8/luoyang/npc/feng-buping" : 1,
                "/d/jinyong/book8/luoyang/npc/dizi" : 3,
        ]));
        
       	set("outdoors", "luoyang");

	setup();
	replace_program(ROOM);
}

void init()
{
	object who = this_player();
	if (who && interactive(who)) 
		call_out ("fengsay", 1, who);  
}

void fengsay(object who)
{
	object feng = present("feng buping", environment(who));
	if(feng)
	{
		message_vision("封不平恨恨的说：这次有嵩山派支持，必定要杀了岳不群，夺回掌门之位！＂\n");
		message_vision("然后去泉州杀了魔教使者向问天，我华山派从此名扬天下，哈哈！＂\n");
	}
}