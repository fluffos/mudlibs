// Room: /d/taohuadao/boat.c
// Date: llx 27/10/97

inherit ROOM;




void create()
{
	set("short", "小木船");
	set("long", @LONG
一艘小木船，最少也能载五、六个人。船虽小，至少
也能经受得住一般的风浪。一名四十多岁的船夫手持
长木桨，正在船尾吃力地撑着船。
LONG
	);


	set("outdoors", "taohuadao");
        set("no_task",1);
	setup();
	
}



void init()
{       
        object ob=this_player();
        if(!userp(ob)){
        ob->move("/d/taohuadao/haigang1");
        return;
        }
}
