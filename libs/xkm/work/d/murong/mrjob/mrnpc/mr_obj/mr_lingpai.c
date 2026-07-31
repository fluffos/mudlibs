/************************
File:   Lingpai.c
Create: Play
Time:   4/25/2002
************************/
#include <ansi.h>;
inherit ITEM;
#define JOB_G ("/d/murong/mrjob/mrnpc/mr_inherit/mr_jobs.c")
string *patrol_msg = ({
"你发现%s方向有些不正常，是否去察看察看呢？",
"你听到%s那边传来异样的声响，不知是否有什么不妥！",
"根据你的细心调查，%s需要查巡一下。",
"你反复推敲后越发觉得%s需要查巡了。",
});
string *patrol_str = ({
"你在%s附近没有发现什么不正常。",
"看来%s还算正常，没有什么特别的问题发生。",
"经过巡视你发现%s没有什么可疑的地方。",
});

void create()
{
	seteuid(ROOT_UID);
        set_name(HIY"令牌"NOR, ({"ling pai","ling", "pai"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("no_sell", 1);
                set("no_steal", 1);
                set("mrjob", 1);
                set("no_drop", 1);
                set("long", "一块金色的令牌，慕容世家专用。\n");
                set("value", 0);
                set_weight(100);
        }
        setup();
}
void init()
{
	object me;
	me = this_player();
        if(me->query_temp("Mrjob_patrol"))
	   {
                me->delete_temp("Mrjob_patrol");
                remove_call_out("go_patrol");
	        call_out("go_patrol",2,me,0);
	   }
        add_action("do_zhuo", "zhuo");
}

int go_patrol(object me,int k)
{
	object ob, room;
	string msg, str, path;

        msg = patrol_msg[random(sizeof(patrol_msg))];
        path = me->query_temp("Mrjob_path");

        if((me->query_temp("Mrjob/content")&&me->query_temp("Mrjob/content")=="patrol")&&
            me->query_temp("Mrjob_time")<time())
        {
        	write("巡视庄园工作时间已到，你可以去交差了。\n");
                me->set_temp("Mrjob_over",2);
        	return 1;
        }
        if(me->is_fighting()||!living(me))
        {
                remove_call_out("go_patrol");
        	call_out("go_patrol",10,me,k);
        	return 1;
        }
        if(me->query_temp("Mrjob_amu")>5+random(3))
        {
        	write("你完成了巡视庄园的工作，可以回去交差了。\n");
                me->delete_temp("Mrjob_path");
                me->set_temp("Mrjob_over",1);
                return 1;
        }
        if(path)
        {
        	if(k>5)
        	{
        		me->delete_temp("Mrjob_path");
        		me->add_temp("Mrjob_amu",-1);
        	}
        	if(me->query_temp("Mrjob_thief"))
        	{
        		ob= me->query_temp("Mrjob_thief");
        		if(ob&&!me->is_fighting() )
        		{
        		if(environment(ob)!=environment(me))
        		write(ob->name()+"在"+environment(ob)->query("short")+"附近，快去捉(zhuo)拿！\n");
                        else
        		if(environment(ob)==environment(me))
        		write("一个贼眉鼠眼的"+ob->name()+"在你身边，快捉(zhuo)住他！\n");
         	        }
         	        else
         	        me->delete_temp("Mrjob_thief");
        		call_out("go_patrol",25+random(10),me,k+1);
        		return 1;
        	}
        	if (environment(me)->query("short")==path->query("short"))
        	{
        		str = patrol_str[random(sizeof(patrol_str))];
        		str = sprintf(str,environment(me)->query("short"));
        		switch(random(10))
                        {
                	       	case 1:
                	        write("忽然一道可疑的身影在你看面闪过，你追上去后发现竟然是个小偷(thief)！\n");
                                ob=new(__DIR__"npc/thief");
                                ob->move(environment(me));
                                ob->set("Mrjob", "thief");
                                ob->set("combat_exp", me->query("combat_exp")*5/4);
                                ob->add_temp("apply/attack", me->query_skill("parry")*3/5);
                                ob->add_temp("apply/defense", me->query_skill("parry")*2/3);
                                ob->add_temp("apply/armor", me->query_skill("parry")/3);
                                ob->add("max_neili", me->query("max_neili")*5/4);
                                ob->add("max_qi", me->query("max_qi")*5/4);
                                ob->add("max_jingli", me->query("max_jingli")*5/4);
                                ob->add("neili", me->query("max_neili")*5/4);
                                ob->add("eff_qi", me->query("eff_qi")*5/4);
                                ob->add("qi", me->query("max_qi")*5/4);
                                ob->add("jingli", me->query("max_jingli")*5/4);
                                ob->add("jiali", me->query("jiali")*2/3);

                                me->set_temp("Mrjob_thief", ob);
                	        break;
                	        case 5:
                	        case 9:
                	        ob = new("/clone/money/coin.c");
                	        ob->set_amount(random(10)+10);
                	        ob->move(me);
                	        write("你发现了几枚铜钱，弯腰拾了起来。\n");
//                	        break;
       	                        default:
        		        write(str+"\n");
        		        me->delete_temp("Mrjob_path");
        		        me->add_temp("Mrjob_amu",1);
        		        break;
        		}
                        remove_call_out("go_patrol");
      		        call_out("go_patrol",5,me,k+1);
        		return 1;
                }

              	if(!me->query("env/mrjob")){
         		msg = sprintf(msg,path->query("short"));
        		write(msg+"\n");
        	}
                remove_call_out("go_patrol");
        	call_out("go_patrol",15+random(10),me,k+1);
        	return 1;
        }

        room=__FILE__->get_room();
        if(!room)
        {
        	write("慕容巡视系统出错，请告之巫师。\n");
        	return 1;
        }
       	msg = sprintf(msg,room->query("short"));
        write(msg+"\n");
        me->set_temp("Mrjob_path",room);
        if(wizardp(me)){
                write(HIY"Wizard patrol: "HIM);
       		write(room);
       		write("\n"NOR);
	}
	k=1;
        remove_call_out("go_patrol");
        call_out("go_patrol",10,me,k);
        
	return 1;
}
//发布下一步需要巡视的路径
string get_room()
{
	string dir,str,*path;
	mixed *file;
	int i, j, k;
	string room;
	dir = resolve_path("/d/murong/");
	file = get_dir(dir, -1);
	j = sizeof(file);
	str = file[random(j)][0];
	
	path = JOB_G->file_name();
        for(k=0;k<6;k++)
        {
        	for(i=0;i<sizeof(path);i++)
        	{
        	if(strsrch(str,path[i])<=-1&&strsrch(str,".c")>-1) continue;
        	str = file[random(j)][0];
        	}
                if( member_array(str, path)==-1) continue;
 	            str = file[random(j)][0];
        }
       	room = "/d/murong/"+str;
	return room;
}
