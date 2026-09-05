
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "碑林");
        set("long", @LONG
这是长安皇城东南角的碑林，存放着历朝名家的碑文(stone)、经书、墓志
以及石刻，各地文人墨客都慕名前来临摹(copy)。
LONG        );
        
        set("exits", ([
                "west" : __DIR__"taimiao",
                "northwest" : __DIR__"shangshusheng"
        ]));
        
        set("item_desc", ([
          "stone" : "这里有着开成石经、颜家庙碑、草书千字文等二千余件碑文，你可以尝试临摹碑文。\n"]));
        
        set("locate_level",1);
        set("no_perform",1);
        set("no_exert",1);
        set("no_fight",1);

        set("outdoors", "changan");
        set("changan", 2); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}

void init()
{
	add_action("do_copy", "copy");
}

int do_copy(string arg)
{
	object me=this_player(),bi,mo,zhi,yan;
	mapping *beiwen=
	  ({(["skill":"literate",
	  	  "beiwen":"千字文",
	  	  "min":50,
	  	  "max":100]),
	  	(["skill":"literate",
	  	  "beiwen":"颜家庙碑",
	  	  "min":50,
	  	  "max":150]),
	  	(["skill":"literate",
	  	  "beiwen":"开成石经",
	  	  "min":100,
	  	  "max":200]),
	  	(["skill":"force",
	  	  "beiwen":"抱朴子",
	  	  "min":100,
	  	  "max":200]),
      (["skill":"taoism",
	  	  "beiwen":"抱朴子",
	  	  "min":100,
	  	  "max":200]),
      (["skill":"buddhism",
	  	  "beiwen":"大般若经",
	  	  "min":100,
	  	  "max":200]),
      (["skill":"medical-skill",
	  	  "beiwen":"千金方",
	  	  "min":0,
	  	  "max":100])}), curbw;
	
	if ( arg!="shibei" )
	{
		tell_object(me, "临摹碑文的命令格式是copy shibei。\n");
		return 1;
	}
	
	if ( me->query_combatgrade()>=120&&
		   !wizardp(me) )
	{
		tell_object(me, "你现在的阅历足够丰富了，这里的碑文对你已经没有任何帮助了。\n");
		return 1;
	}
	
	if ( me->query_skill("literate", 1)<50 )
	{
		tell_object(me, "你还是再多学一点文化，再过来临摹碑文吧。\n");
		return 1;
	}
	
	if ( me->is_busy() )
	{
		tell_object(me ,"你正忙着呢！\n");
		return 1;
	}
	
	if ( !objectp(bi=present("hu bi", me))||
		   !objectp(mo=present("hui mo", me))||
		   !objectp(zhi=present("xuan zhi", me))||
		   !objectp(yan=present("duan yan", me)) )
  {
  	tell_object(me, "你没有带文房四宝怎么临摹碑文？\n");
		return 1;
	}
	
	if ( time()-me->query("changan/copy_beiwen")<=600 )
	{
		tell_object(me, "你刚临摹了碑文，稍等再过来临摹吧？\n");
		return 1;
	}
	
	curbw=beiwen[random(sizeof(beiwen))];
	destruct(bi);
	destruct(mo);
	destruct(zhi);
	destruct(yan);
	me->set("changan/copy_beiwen",time());
	if ( me->query_skill(curbw["skill"],1)<curbw["min"] )
	{
		tell_object(me, "你临摹了关于『"+curbw["beiwen"]+"』的碑文，但是似乎过于艰深，不能理解碑文的深意。\n");
		return 1;
	}

	if ( me->query_skill(curbw["skill"],1)>curbw["max"] )
	{
		tell_object(me, "你临摹了关于『"+curbw["beiwen"]+"』的碑文，但是似乎过于浅显，对你没有任何帮助。\n");
		return 1;
	}
	
  message_vision("$N开始临摹碑文『"+curbw["beiwen"]+"』。\n", me);
  me->start_busy(600);
  call_out("copy_beiwen", 6, me, curbw, 1);
	return 1;
}

void copy_beiwen(object me, mapping beiwen, int times)
{
    if (objectp(me)&&!living(me))
    {
        return;
    }
    printf("%s,%d\n", beiwen["skill"], times);
	if ( times>10 )
	{
		tell_object(me,"你完成了对碑文『"+beiwen["beiwen"]+"』的临摹。\n");
		me->start_busy(0);
		return;
	}
	
	if ( me->query("jing")<50 )
	{
		tell_object(me,"你由于精神不足结束了对碑文『"+beiwen["beiwen"]+"』的临摹。\n");
		me->start_busy(0);
		return;
	}
	
	me->receive_damage("jing",20);
	me->improve_skill(beiwen["skill"],500);
	tell_object(me , "你在临摹碑文『"+beiwen["beiwen"]+"』的过程中，不断揣摩碑文，对"+to_chinese(beiwen["skill"])+"的理解又加深了一步。\n");
	call_out("copy_beiwen", 6, me, beiwen, times+1);
}