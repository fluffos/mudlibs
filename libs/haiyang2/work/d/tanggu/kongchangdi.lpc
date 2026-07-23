#include <ansi.h>
inherit ROOM;
string look_leitai();
string look_qi();
string look_board();

void create()
{
        set("short", HIY"广场空地"NOR);
        set("long", "此处内是塘沽繁华之所，只见红楼画阁，绣户朱门，雕车竞驻，骏马争驰。一
片开阔的场地上，但听得前面人声喧哗，喝彩之声不绝于耳，远远望去，围着好大
一堆人，只见中间老大一块空地，立着一方"NOR+HIR"擂台"NOR+"，地下插了一面锦旗（Qi），白底
红花，绣着『"NOR+HIY"比武 招亲"NOR+"』四个金字，旗下一块白板（Board）。旗下两人正自拳来
脚去的打得热闹，一个是红衣少女，一个是长大汉子。\n");

        set("no_fight", 1);
        set("no_sleep_room", 1);
        set("leitai", __DIR__"biwuleitai");
        set("exits", ([ 
			             "northwest" : "/d/tanggu/center",
        ])); 
        set("objects", ([    
             	//__DIR__"npc/mu-nianci" : 1,
				//__DIR__"npc/manghan" : 1,
        ]));
        set("item_desc",([            
            "qi" : (: look_qi :),
				"leitai" : (: look_leitai :),
				"board" : (: look_board :),
        ]));
        set("outdoors", "长安");  
        setup(); 
}


string look_qi()
{
    	object me,obj,who;
		string str;
		int i,p;
    	me = this_player();
    	if (me->is_busy()) 
          	return "你正忙着呢。\n";
    	me->start_busy(2);
		str  = "一面锦旗，白底红花，绣着『"+HIY"比武招亲"NOR+"』，底下几行小字：\n\n";
		str += "        『"+HIC"卧虎藏龙地，良辰美景天"NOR+"』\n\n";
		obj=present("mu nianci",this_object());
		if(obj && obj->query("station") && obj->query("bwzh/host_player"))
		{
			who=obj->query("bwzh/host_player/object");
			if(!who) return "";
			i=who->query("age")-obj->query("bwzh/age");
			if(i<18) i=18;
			p=who->query("age")+obj->query("bwzh/age");
			if(p>80) p=80;
			str += HIC"在锦旗的侧面一角，写着一个名字："+obj->query("bwzh/host_player/name")+"。\n"NOR;
			str += HIC"名字下面注明几个数字："+obj->query("bwzh/exp")+"|"+obj->query("bwzh/per")+"|"+i+"|"+p+"。\n"NOR;
		}
        tell_object(me,str);
    	return "";
}
string look_board()
{
    	object me,obj;
		string str;
    	me = this_player();
    	if (me->is_busy()) 
          	return "你正忙着呢。\n";

    	me->start_busy(2);
		obj=present("mu nianci",this_object());
		if(!obj || !obj->query("bwzh/winner_player"))
		{
			str  = "一块白板，正上方写着『"+HIY"比武招亲"NOR+"』标题，底下却什么也没写。\n";
		}
		else
		{
			if(obj->query("bwzh/challenge_player"))
				str  = "一块白板，正上方写着『"+HIY"比武招亲"NOR+"』标题，底下也写有两行字：\n";
			else 
				str  = "一块白板，正上方写着『"+HIY"比武招亲"NOR+"』标题，底下也写有一行字：\n";

			str += "\n             『"+HIC"擂  主"NOR+"』："+obj->query("bwzh/winner_player/name")+"\n";
			if(obj->query("bwzh/challenge_player"))
				str += "             『"+HIC"挑战者"NOR+"』："+obj->query("bwzh/challenge_player/name")+"\n";
		}
        tell_object(me,str);
    	return "";
}




