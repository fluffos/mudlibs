//fix by yhzzyahoo
inherit NPC;
#include <ansi.h>
int find_npc(string arg);
int check_legal_id(string id)
{
	int i;

	i = strwidth(id);
	while(i--)
		if( id[i]>'a' && id[i]<'z' ) {
			return 1;
		}

	return 0;
}
void create()
{
        set_name("无际", ({ "vast npc", "vast" }));
        set("title", HIR"千里眼"NOR);
        set("str", 30);
        set("per", 40);
        set("gender", "男性");
        set("age", 25);
        set("long","他就是无际，无所不知！\n");
        set("combat_exp",  5000000);
        set_skill("unarmed",3000);
        set("attitude", "friendly");
        set("inquiry", ([
                "找人":"找人不要钱啊，给我8 gold我就给你找！输入findnpc！新手大优惠，一两银子就够了。\n",
                "findnpc":"找人不要钱啊，给我8 gold我就给你找！输入findnpc！新手大优惠，一两银子就够了。\n",
                "findtask":"找task物品输入findtask明了即可，银行转账给我，优惠期一次10两黄金。\n",	
        ]));
        
        setup();
}
void init()
{
add_action("find_npc","find"); 
add_action("find_npc","findnpc"); 
add_action("do_findtask","findtask"); 
}


int find_npc(string arg)
{
        object *chn,env;
        object ob_wiz;
        int i,j,count=0,num=0;
		int cd_time;
        string enstr;

        mapping mm;
        mapping mtemp;
        
        mm =  ([]);
        
        if ((int)this_player()->query_temp("findnpc")<1)
                      return notify_fail("无际说道：“不给钱怎么干活？找人至少需要黄金8两，新手优惠，1两白银！”\n"); 
        
        if (!arg)
                return notify_fail("无际说道：“请输入想查找的人物名，中文才行!”\n");

		if(check_legal_id(arg))
		{
			return notify_fail("无际说道：“对不起，我这里只能查中文姓名的。\n");
		}

        if (objectp(ob_wiz=find_player(arg)) && wizardp(ob_wiz))
                return notify_fail("无际在你耳边偷偷的说道：“这个人惹不起，你还是不要查的好！”\n");
        if (arg=="静电清水"||arg=="溢出")
                return notify_fail("无际瞪了你一眼说道：“北侠老大你也敢查，不想活了你！”\n");
		/*if (environment(this_player())->query("short")=="发呆室"&& environment(this_player())->query("repair_room")==1)
		{
			cd_time=15+random(5);
		}
		else
		{
			cd_time=15+random(5);
		}*/
		cd_time=15+random(5);
        if (time()-query_temp("scan_time") < cd_time )
                return notify_fail("不要频繁的查询，谢谢！\n");

        set_temp("scan_time",time());
        chn = livings();

        for(i=0;i<sizeof(chn);i++)
        {
                if(clonep(chn[i]) && (member_array(arg,chn[i]->parse_command_id_list())!=-1 || 
                                strsrch(chn[i]->query("name"),arg)!=-1))
                {
                        if (chn[i]->query("dontseekme")||chn[i]->query("hide"))//部分任务，难度重点就是找的过程，类似捉迷藏，有vast就不好玩了。
                        {
                            continue;
                        }
						if(this_player()->query_temp("findnpc_cheap"))
						{
							//新手优惠，只能找自己的任务npc
							if(chn[i]->query("killer") != this_player()->query("id") && chn[i]->query("uni_target") != this_player() )
							{
								continue;
							}
						}
                
                        
                        count++;
                        if ( objectp(env=environment(chn[i])) )
//                                enstr = sprintf("%s(%s)\n",env->query("short"),base_name(env));
                                enstr = sprintf("%s",env->query("short"));
                        else    
                                enstr = sprintf("不详！");            
                                                        
                        for(j=0;j<sizeof(mm);j++)
                        {                       
                                mtemp = mm [j] ;
                                if (mapp(mtemp)) 
                                {
                                        if (mtemp["file_name"] == base_name(chn[i]) && mtemp["env"] == enstr )
                                        {
                                                mtemp["count"]++;
                                                break;
                                        }       
                                }
                        }
                        
                        if (j>=sizeof(mm))
                        {
                                mtemp = ([]);
                                mtemp["file_name"] = base_name(chn[i]);                         
                                mtemp["name"] = chn[i]->query("name")+"("+
                                                chn[i]->query("id")+")";
                                mtemp["count"]=1;
                                mtemp["env"] = enstr ;
                                mm[j] = mtemp;
                        }                               
                }                       
        
        }               
        
        if (count==0)
                return notify_fail("无际摇头道：“没找到！”\n");                    
                
        i=random(sizeof(mm));
        mtemp = mm[i];
        printf("无际说道：“似乎有个叫做%s的家伙在%s，不知道是不是你要找的那个家伙？”\n",mtemp["name"],mtemp["env"]);
        this_player()->delete_temp("findnpc");
		this_player()->delete_temp("findnpc_cheap");
        return 1;
}                       
int accept_object(object who, object ob)
{       
        if (ob->query("money_id") )       
        {
            if(ob->value() >= 80000)
            {
                message_vision("无际说道：“既然你出手这么阔绰，那么我就帮你找一次人吧！\n请输入findnpc <要找的人>，中文名才可。”\n", this_player());
				this_player()->delete_temp("findnpc_cheap");
            }
            else if(who->query("mud_age") < 86400*5 && ob->value() >= 100 ) 
            {
                message_vision("无际说道：“看你是个新手，就便宜点吧。！\n请输入findnpc <要找的人>，中文名才可。”\n", this_player());
				this_player()->set_temp("findnpc_cheap",1);
            }
            else
            {
                message_vision("无际说道：现在什么都涨，我这生意不好做啊。\n", this_player());                
				return 0;
            }            
            this_player()->set_temp("findnpc",1);

            return 1;
        }
        message_vision("无际说道：“什么破东西，不要不要！”\n", this_player());
        return 0;
}
int do_findtask(string arg)
{
	object me=this_player();
	string output;//查询的结果
  string ow,na;	
  
  if(!arg||arg=="")
         return notify_fail("无际告诉你：你要寻找什么的方位？\n");	
	
	if(me->query("balance")<100000)
                     return notify_fail("无际告诉你：优惠期找task服务一次需要10两黄金，可是你的存款不够。\n");
	
  if(sscanf(arg,"%s的%s",ow,na)!=2) 
          return notify_fail("无际告诉你：没有这样task。\n");
  
  output=TASK_D->query_location_where(arg);  
  
  if(stringp(output))
    {
    	tell_object(me,"无际告诉你："+output);
    	tell_object(me,"你不禁在心里骂了一句：“奸商”，但还是老老实实地从银行转账10两黄金到了无际的户头！\n");
    	me->add("balance",-100000);//扣款
		me->start_busy(random(2));
    	return 1;
    }
    else
	{
      tell_object(me,"无际告诉你：无法确定"+arg+"的方位。\n");
	  me->start_busy(random(2));
	}
   return 0;	 
}
