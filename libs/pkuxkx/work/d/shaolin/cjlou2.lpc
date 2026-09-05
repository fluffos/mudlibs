// Room: /d/shaolin/cjlou1.c
// Date: YZC 96/01/19
// modify by chui

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "藏经阁小屋");
        set("long", @LONG
千余年来少林寺之所以成为武林泰斗，自达摩老祖以下，历代
人材辈出。其中有不少高僧遗著留存，汇集至今，终成名震天下
的少林七十二绝艺。少林也收藏了一些其他门派的武技、秘籍，
尽集于此，对此少林弟子也从未提起。许多少林的绝技也是于此
领悟、变化而出(lingwu、digest)。书架(shelf)上堆满了各
种少林经书武籍。
LONG
        );

        set("exits", ([
               // "down" : __DIR__"cjlou",
                "north" : __DIR__"cjlou1",
        ]));

        set("bo",1);
        set("objects",([
                "d/shaolin/obj/wuji1" : 1,
                "d/shaolin/obj/wuji2" : 1,
                "d/shaolin/obj/wuji3" : 1,
        ]));
        set("item_desc",([
                "shelf" : "架子上堆满了少林的经书武籍。\n",
        ]));
        create_door("north", "壁门", "south", DOOR_CLOSED);
        set("no_perform",1);
        set("no_exert",1);
        set("no_fight",1);

        setup();
}

void init()
{
	object me = this_player();
	if (random(me->query("kar") + 100) > 109
	    && me->query("combat_exp") > 1000000
	    && me->query("family/master_id") != "murong bo")
          {
        tell_object(me,HIB"你眼前一花，觉得书架背后仿佛有个人影晃过。\n"NOR);
           me->set_temp("murong/bo",1);
        }
        add_action("do_linwu", "lingwu");
        add_action("do_linwu", "digest");
        add_action("do_move", "move");
        add_action("do_move", "push");
}


int do_linwu(string arg)
{
        object me;
        me=this_player();   
        
        if(arg) return 1;
        if(me->query("combat_exp")<2000000) 
        {
          write(HIY"你现在经验太低无法冥想佛家的真理!\n"NOR);
          return 1;
        }
        
        if(me->is_busy()||me->is_fighting())
        {
          write(HIY"你现在无法静下心领悟佛家的真理!\n"NOR);
          return 1;
        }
        
        if((int)me->query("max_neili")>(int)me->query("neili"))
        {
          write(HIY"你现在内息紊乱，无法静下心领悟佛家的真理!\n"NOR);
          return 1;
        }
        
        if(me->query("jingli")<500)
        {
          write(HIY"很明显,你现在太累了,无法冥想佛家的真理!\n"NOR);
          return 1;
        }
        
        me->start_busy(600);
        call_out("lingwu_loop",3, me,100);
        return 1;
}

void lingwu_loop(object me, int times)
{
        int mykar;
        if ( !objectp(me) )
        	return;
        mykar = me->query("kar")+me->query_temp("wuming")/60;      //重新调整了算法，zine修正bug以后领悟命中率降低太多了。 by seagate
        
        if((random(600)==0) && me->query("family/family_name")== "少林派")
        {
          write(HIY"你领悟了少林寺上乘的武功秘籍，觉得颇有所获!\n"NOR);
          if((random(random(mykar)+1000))>999)
          {
            me->add("wuming",1);
            write(HIY"你突然觉得窗外的扫地老僧对你笑了笑,回头却发现他只是在专心打扫.\n"NOR);
            write(HIY"你感觉这种事情已经发生"+me->query("wuming")+"次了。\n"NOR);
          }
          
          me->add("jingli",-100);
          me->add("potential",2);
          me->add("combat_exp",random(5)+1);  
        }
        else
        {
          write(HIY"你领悟了佛家的真理,觉得颇有所获!\n"NOR);
          if (!me->query("antirobot/deactivity"))
          {
            me->add("potential",2);
            me->add("combat_exp",random(6)+3);
          }
        }
        
        me->add_temp("wuming",1);
        
        if ( !times )
        {
        	write(HIY"你结束了对佛法的冥思，觉得颇有所获!\n"NOR);
        	me->start_busy(0);
        }
        else
          call_out("lingwu_loop",3, me,times-1);
}

int valid_leave(object me, string dir)
{
        object ob;

        if ( present("huizhen zunzhe", environment(me)) )
        if ( present("shaolin wuji", me)
        ||   objectp(ob = present("corpse", me)) && present("shaolin wuji", ob) )
        {
                if (dir == "south" )
                {
                        return notify_fail("慧真说道: 武功秘籍只许在藏经阁内研习，不得携带外出 !\n");
                }
        }
        return ::valid_leave(me, dir);
}
int do_move(string arg)
{
	object me = this_player();
	object bo,*inv;
	int i;

	if (!arg || arg != "shelf")
	return notify_fail("你要移动什么？\n");

	inv = all_inventory(this_object());
	for(i=0; i<sizeof(inv); i++)
	{
		if (userp(inv[i]) && inv[i] != me)
		return notify_fail("现在有人正在翻阅书架上的书，你怎么好移动书架呢？\n");
	}

         if (this_object()->query("bo") < 1)
         {
         message_vision(HIY"$N暗运内功双掌将书架向一旁推开,结果什么都没有发现。\n"NOR,me);
         return 1;
         }
	if (me->query("family/family_name") == "姑苏慕容" && me->query("family/master_id") == "murong bo")
	{
	message_vision(HIC"\n慕容博从书架后一跃而出，向你道：“徒儿，有何事禀告为师？”\n"NOR,me);
	bo = new(CLASS_D("murong/murongbo"));
	bo->move(this_object());
         this_object()->add("bo", -1);
	me->start_busy(3);
	return 1;
	}

	if (!me->query_temp("murong/bo"))
	return notify_fail("你没事乱动别人书架干什么？\n");
	me->delete_temp("murong/bo");
	message_vision(HIY"$N暗运内功双掌将书架向一旁推开。\n"NOR,me);
	message_vision(HIR"\n突然书架后面跃出一人，二话不说指尖向$N当胸点来。\n"NOR,me);
	bo = new(CLASS_D("murong/murongbo"));
         bo->set("player",me->query("id"));
	bo->move(this_object());
	me->start_busy(3);
	if (me->query("family/family_name") == "姑苏慕容")
	{
	message_vision(HIY"$N仓促间立刻使出本门手法出拳相迎。\n"NOR,me);
	message_vision(HIY"来人见$N出招，十分惊诧，突地大喝一声：“住手！本门弟子找我有何要事？\n"NOR,me);
	message_vision(HIY"$N不禁大惊，双方都停下手来... ...\n"NOR,me);
	}
	else
	{
	message_vision(HIR"来人对$N大喝道：“既然你已发现我的栖身之地，就去见阎王爷吧。\n"NOR,me);
	bo->kill_ob(me);
	}
	return 1;
}
