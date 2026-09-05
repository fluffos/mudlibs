inherit NPC;
#include <ansi.h>
int find_npc(string arg);
void create()
{
        set_name("千里眼", ({ "qianli yan", "eyes" }));
        set("str", 30);
        set("gender", "男性");
        set("age", 25);
        set("long",
                "他就是千里眼，无所不知！\n");
        set("combat_exp",  50000);
        set("attitude", "friendly");
        set("inquiry", ([
                "找人":"找人不要钱啊，给我5 gold我就给你找！\n",
                "find":"找人不要钱啊，给我5 gold我就给你找！\n",
        ]));
        
        setup();
}
void init()
{
add_action("find_npc","find"); 
add_action("find_npc","findnpc"); 
}


int find_npc(string arg)
{
        object *chn,env;
        object ob_wiz;
        int i,j,count=0,num=0;
        string enstr;

        mapping mm;
        mapping mtemp;
        
        mm =  ([]);
        
        if ((int)this_player()->query_temp("findnpc")<1)
                      return notify_fail("千里眼说道：不给钱怎么干活？找人至少需要黄金5两！\n"); 
        
        if (!arg)
                return notify_fail("千里眼说道：你必须输入想查找的人物名!\n");  
        
        if (objectp(ob_wiz=find_player(arg)) && wizardp(ob_wiz))
                return notify_fail("千里眼说道：你不能查巫师的位置！\n");
        chn = livings();

        for(i=0;i<sizeof(chn);i++)
        {
                if(clonep(chn[i]) && (member_array(arg,chn[i]->parse_command_id_list())!=-1 || 
                                strsrch(chn[i]->query("name"),arg)!=-1))
                {
                
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
                return notify_fail("千里眼说道：好像没有这个人吧？!\n");                    
                
        i=random(sizeof(mm));
        mtemp = mm[i];
        printf("千里眼说道：似乎有个叫做%s的家伙在%s，不知道是不是你要找的那个家伙？\n",mtemp["name"],mtemp["env"]);
        this_player()->delete_temp("findnpc");
        return 1;
}                       
int accept_object(object who, object ob)
{       
        if (ob->query("money_id") && ob->value() >= 50000) 
        {
                message_vision("千里眼说道：既然你出手这么阔绰，那么我就帮你找一次人吧！请输入findnpc <要找的人>。\n", this_player());
                this_player()->set_temp("findnpc",1);
                return 1;
        }
        message_vision("什么破东西，不要不要！\n", this_player());
        return 0;
}
