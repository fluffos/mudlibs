inherit ROOM; 
void create() 
{ 
        set("short", "大雁塔下"); 
        set("long", @LONG 
大雁塔为一座七层方形塔，塔身十分雄伟，底座宽大，造型简洁庄严神秘。方塔底
座有门，门楣上有石刻画。
    却不想塔下另有玄机，只见四面纵横十余丈，其中错牙交错的甬道
连接四方，两名的石壁上画满佛符，闪烁着微弱的金光。

LONG
); 
        set("virtual_room", 1); 
        set("no_magic",1);
        set("exits", ([
                "south" : __DIR__"maze/entry", 
                "up": "/d/eastway/ciensi",
        ])); 
        set("objects",([
        	"/d/maze/dayan-ta/npc/monk" : 1,
        ]));	
        setup();
} 

void init_key(object who)
{
	mapping jg;
	string str,*msg,*ks;
	int i;
	if( !who || !living(who) || !present(who,this_object()) )
		return;
	jg = ([
		"黄铜" : "ht_key",
		"青铜" : "qt_key",
		"钨铜" : "wt_key",
		"黑铁" : "htie_key",
		"钨钢" : "wg_key",
	]);
	ks = values(jg);
	reset_eval_cost();
	for(i=0;i<sizeof(ks);i++)
	{
		msg = ({
			"甲","乙","丙","丁","戊","己","庚","辛","壬","癸",
			"子","丑","寅","卯","辰","巳","午","未","申","酉","戌","亥",
		});
		str = msg[random(sizeof(msg))];
		who->set_temp("maze/"+ks[i]+"1",str);
		msg-= ({str});
		str = msg[random(sizeof(msg))];
		who->set_temp("maze/"+ks[i]+"2",str);
		msg-= ({str});
		str = msg[random(sizeof(msg))];
		who->set_temp("maze/"+ks[i]+"3",str);
		msg-= ({str});
		str = msg[random(sizeof(msg))];
		who->set_temp("maze/"+ks[i]+"4",str);
		msg-= ({str});
	}
	who->set_temp("maze/daya_key_create",1);
	if( wizardp(who) )
		tell_object(who,"密语生成完毕。\n");	
}

int valid_leave(object who,string dir)
{
	if( !who->query_temp("maze/dayan") )
        	return notify_fail("你是怎么混进来的？！\n");
	if( !who->query_temp("maze/daya_key_create") )
		init_key(who);        	
        return ::valid_leave(who,dir);
}			  		 
