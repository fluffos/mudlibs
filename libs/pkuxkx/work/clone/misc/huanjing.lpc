//太虚幻镜
//从xyj的照相机改过来的，允许玩家自己摆pose

#include <ansi.h>
inherit ITEM;
inherit F_SAVE;

#define MAX_LEN 256

string query_save_file()
{
	return "/data/huanjing";
}

void create()
{     
   set_name(HIC"太"HIY"虚"HIB"幻"HIW"镜"NOR, ({"huan jing"}));
   set("long",   @LONG  
这是一面上古流传下来的镜子，世间百态，天地万物，莫不在它的镜像之中。
人生岂不是正如这镜中景象，忽而一日，倏然一生？

所谓雁过留声，人过留名，你也许可以在这幻镜之中留下点什么(pose,memory)。   
你还可以试着从幻镜中找回从前的回忆(recall)。
LONG
    );
   set_weight(500);
   
   set("unit", "面");
   set("value", 100000);
   set("material", "stone");
   set("no_get",1);
   set("no_pawn",1);
   set("no_sell",1);     
   set("no_give",1); 
   
   setup();
   restore();       
     
   seteuid(getuid());
   
   
}

void init()
{
     add_action("do_memory","memory");
     add_action("do_pose","pose");
     add_action("do_kan","kan");
     add_action("do_recall","recall");
}

int do_pose(string arg)
{
    string str="";
    object me = this_player();
    if(!arg) return notify_fail("你要摆个什么姿势？\b");
    if(sizeof(arg) > MAX_LEN/2) return notify_fail("你摆的姿势未免也太复杂了。\n");    


    if(stringp(RANK_D->query_rank(me)))
    {
        str += RANK_D->query_rank(me);
    }
    str += " ";
    
    if(stringp(me->query("title"))) 
    {
        str += me->query("title");
    }    
    str += " ";    
    
    if(stringp(me->query("nickname"))) 
    {
        str += "「"+me->query("nickname")+"」";
    }
    str += " ";
    
    str += me->query("name") + "("+me->query("id")+")";
    str += "\n";
    
    if(me->query("gender") == "男性") 
    {
        str += "他";
    }
    else if(me->query("gender") == "女性") 
    {
        str += "她";
    }
    else
    {
        str += "祂";
    }
    
    //支持颜色
    arg = replace_string(arg,"HIY",HIY);
    arg = replace_string(arg,"RED",RED);
    arg = replace_string(arg,"GRN",GRN);
    arg = replace_string(arg,"YEL",YEL);
    arg = replace_string(arg,"BLU",BLU);
    arg = replace_string(arg,"MAG",MAG);
    arg = replace_string(arg,"CYN",CYN);
    arg = replace_string(arg,"WHT",WHT);
    arg = replace_string(arg,"HIR",HIR);
    arg = replace_string(arg,"HIG",HIG);
    arg = replace_string(arg,"HIY",HIY);
    arg = replace_string(arg,"HIB",HIB);
    arg = replace_string(arg,"HIM",HIM);
    arg = replace_string(arg,"HIC",HIC);
    arg = replace_string(arg,"HIW",HIW);    
    arg = replace_string(arg,"BNK",BNK);
       
    arg = replace_string(arg,"HBRED",HBRED);
    arg = replace_string(arg,"HBGRN",HBGRN);
    arg = replace_string(arg,"HBYEL",HBYEL);
    arg = replace_string(arg,"HBBLU",HBBLU);
    arg = replace_string(arg,"HBMAG",HBMAG);
    arg = replace_string(arg,"HBCYN",HBCYN);                          
    arg = replace_string(arg,"HBWHT",HBWHT);
    
    arg = replace_string(arg,"BBLK",BBLK);
    arg = replace_string(arg,"BRED",BRED);
    arg = replace_string(arg,"BGRN",BGRN);
    arg = replace_string(arg,"BYEL",BYEL);
    arg = replace_string(arg,"BBLU",BBLU);
    arg = replace_string(arg,"BMAG",BMAG);
    arg = replace_string(arg,"BCYN",BCYN);

    arg = replace_string(arg,"NOR",NOR);

    arg += NOR;
    
    arg = replace_string(arg,"\n","");
    arg = replace_string(arg,"\r","");
        
    set("pose/"+me->query("id"),str+arg);
    message_vision("一阵五彩的光芒闪过，太虚幻镜中清晰的映出$N"+arg+"的样子。\n",me);
    return 1;
}   
int do_kan(string arg)
{   
    object ob;
    object me = this_player();
    if(!arg) return notify_fail("从这面太虚幻镜里，你可以看到扬州，鬼门关，洛阳，侠客岛，襄阳,五指山。\n");
    if(arg == "扬州")
    {
        ob = find_object("/d/city/guangchang");
    }
    else if(arg == "鬼门关")
    {
        ob = find_object("/d/death/gate");
    }
    else if(arg == "洛阳")
    {
        ob = find_object("/d/luoyang/wangxinglou2");
    }    
    else if(arg == "侠客岛")
    {
        ob = find_object("/d/xiakedao/dadian");
    }    
    else if(arg == "襄阳")
    {
        ob = find_object("/d/xiangyang/sfdating");
    }    
    else if(arg == "五指山")
    {
        ob = find_object("/d/jiaofei/baoku");
    }    
                       
    if(objectp(ob))
    {
        "/cmds/std/look"->mudlook_room(me,ob);
    }
    else
    {
        return notify_fail("那里灰蒙蒙一片，什么也看不见。\n");
    }
    return 1;
}
int do_memory(string arg)
{
    object me, obj;
    object pic, env;
    int i;
    mixed *inv;
    mapping exits;
    string objname, objid, str, pro, *dirs;
    
    me = this_player();
    
    if(!wizardp(me)) 
    {
         return notify_fail("只有神才懂的如何运用这太虚幻镜。\n");
    }
    
    if(time() - query("last_work_time") < 60)
    {
        return notify_fail("即使你是神，也不能这样频繁的运用太虚幻镜。\n");
    }

    env = environment(me);
    str = objname = env->query("short");
    if( !env || !env->isroom())
    {
        return notify_fail("太虚幻镜必须在一个房间里才能使用。\n");
    }
    else
    {
        if(!arg)
        {
            str = "\n"HIC"太"HIY"虚"HIB"幻"HIW"镜"NOR + NATURE_D->game_time() + "印迹。\n";        
        }
        else
        {
            if(sizeof(arg) > MAX_LEN) 
            {
                return notify_fail("你留在太虚幻镜里的印迹太长了。\n");
            }
            str = arg + "\n";
        }
        str += sprintf( "%s\n\n    %s%s\n",env->query("short"), env->query("long"),
            env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) 
        {         
            if ( inv[i]->is_character() )
            {            
               if(stringp(query("pose/"+inv[i]->query("id"))))
               {               
                   str += query("pose/"+inv[i]->query("id")) + "\n";
               }
               else
               {
                   str += inv[i]->query("name") + "面无表情，恍若失魂。\n";
               }
            }         
        }
    }       
    message_vision(HIW"太虚幻镜突然一黯，五色光芒内敛，微微的颤动起来。过了一会，又渐渐恢复了光华，仔细一看：\n"NOR,me);
    message_vision(str,me);
  
    set(sprintf("memory/%d",time()),str);
    
    set("last_work_time",time());
    
    delete("pose");
    
    save();
    
    return 1;
}

//倒序
int sort_memorys(mixed item1,mixed item2)
{
    int time1,time2;
    if(stringp(item1) && stringp(item2))
    {
        if(sscanf(item1,"%d",time1) && sscanf(item2,"%d",time2))
        {
            if(time1 > time2) return -1;
            if(time1 < time2) return 1;
            return 0;
        }
    }
    return 0;
}

int do_recall(string arg)
{
    mixed* allkeys;
    string str;
    string* lines;
    int index=0;
    
    restore();
    
    if(mapp(dbase["memory"]))
    {
        allkeys = keys(dbase["memory"]);
    }
    if(!arrayp(allkeys)) 
    {
        write("太虚幻镜中空空如也。\n");
        return 1;
    }
        
   allkeys = sort_array(allkeys,(:sort_memorys:));
        
    if(!arg)
    {
        write("太虚幻镜中记录着久远的回忆。\n");
        for(int i=0;i<sizeof(allkeys);i++)
        {
            str = dbase["memory"][allkeys[i]];
            if(stringp(str))
            {
                lines = explode(str,"\n");
                if(sizeof(lines) > 0)
                {
                    write(sprintf("%d ",i+1));
                    write(lines[0]+"\n");
                }
            }
        }
        write("你可以选一个，试着回到从前。\n");
    }
    else
    {
        if(sscanf(arg,"%d",index) == 1 && index >= 1 && index <= sizeof(allkeys))
        {
            str = dbase["memory"][allkeys[index-1]];
            write(str);
        }
        else
        {
            return notify_fail("太虚幻镜里并没有留下那个时刻的世界印迹。\n");
        }       
    }
    return 1;
}

