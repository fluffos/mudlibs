/*

Last Update By Yanyan@dt 2003.9.9
*/
#define JOBSYS_D "/adm/daemons/jobsysd.lpc"
#define JOBNPC_D "/adm/daemons/jobnpcd.lpc"


//此函数为奖励帮会的储备。
void add_shili(object me,int exp,int money)
{
   object sboard;
   if(!me->query("shili/name")) return;
   sboard=load_object(BOARD_PATH+me->query("shili/name"));
   if(!sboard) return;
 if(!me->query_temp("bhjob"))
   sboard->add("exp",exp/10);
 else sboard->add("exp",exp);
 if(!me->query_temp("bhjob"))
   sboard->add("money",money/8);
 else sboard->add("money",money);
   sboard->save();
   tell_object(me,"你的帮会的贮备增加了！\n");
   return;
}

nosave int sort_keys(string one, string two) 
{
   return strcmp(one, two);  

}


//复制武功。source 为源物件，target 为目标物件。武功复制 source-->target
void copy_all_skill(object source,object target)
{
     mapping skills;mixed *skl;
     int i;
     
     skills=source->query_skills(); //得到 技能的 mapping 变量形式。
     if(!skills) return;//如果没有技能，则返回。
     skl=keys(skills);//使用 keys() 函数。使用方法可以看 mudosfun.hlp
     
     for(i=0;i<sizeof(skl);i++){
       if(!SKILL_D(skl[i])->query_no_copy())//判断此技能是否可以被复制                                            
          target->set_skill(skl[i],skills[skl[i]]);
     }
     
     target->reset_action(target->query_temp("weapon"));
     //确定target使用的技能，这句也可以不加。
    //但最好是加上。
     return;
}

//给每一个技能设定 level 级。
void set_all_skill(object ob,int level)
{
  mapping skills;mixed *skl;
  int i;
  skills=ob->query_skills();
  if(!skills) return;
  skl=keys(skills);
  for(i=0;i<sizeof(skl);i++)
  ob->set_skill(skl[i],level);
  return;
}


//复制 精、气、神。
//最后一个参数为倍数。
//如果不想加倍，则可以使用 copy_hp_item(source,target,arg);
//如果想让 target 的某项是 source 的倍数，如 2 倍，
//则可以使用 copy_hp_item(source,target,arg,2);
//如果想让 target 的某项是 source 的倍数，如 1.5 倍，
//则可以使用 copy_hp_item(source,target,arg,3,2);
varargs void copy_hp_item(object source,object target,string arg,int i,int j)
{
	if(!source||!target) return;
	if(!i)  i= 1;
	if(!j||j<=0) j = 1;
 	target->set("eff_"+arg,source->query("max_"+arg)*i/j);
 	target->set("max_"+arg,source->query("max_"+arg)*i/j);
 	target->set(arg,source->query("max_"+arg)*i/j);
}
//复制内力
//最后一个参数为倍数。
//如果不想加倍，则可以使用 copy_force(source,target);
//如果想让 target 是 source 的倍数，如 2 倍，
//则可以使用 copy_force(source,target,2);
//如果想让 target 的某项是 source 的倍数，如 1.5 倍，
//则可以使用 copy_hp_item(source,target,arg,3,2);
varargs void copy_force(object source,object target,int i,int j)
{
   if(!source||!target) return;
   if(!i) i=1;
   if(!j||j<=0) j = 1;
   target->set("max_force",source->query("max_force")*i/j);
   target->set("force",source->query("max_force")*i/j);
   
}

//将 物件 me 随机移动到 *dirs 中任意一个。
int random_place(object me, string *dirs)
{
        int  i, j, k;
        object  newob;
        mixed *file, exit;
                

        if( !sizeof(dirs) )  return 1;

        i = random(sizeof(dirs));    // pick up one directory

        file = get_dir( dirs[i]+"/*.lpc", -1 );
        
        if(!sizeof(file))
         return 1;
                                 
	for(k=0;k<30;k++) { // try 20 times
		
           j = random(sizeof(file));
           if( file[j][1] > 0 ) {
             newob=load_object(dirs[i]+"/"+file[j][0]);
             if (newob) {  
               if(newob->query("no_fight") ||
                  newob->query("sleep_room")||
                  newob->query("no_death")||
                  newob->query("no_select")||
		       !(exit=newob->query("exits")) ||
		       sizeof(exit)<1)
		   continue;

               if(me->move(newob)) {
               
		   message_vision("$N走了过来。\n",me);
		   break;
	       }
	     }
	   }
	}

        return 1;
}

//得到 *dirs 中随机任意一个地点。
//如 *dirs=({"/d/yangzhou","/d/xiangyang"});
//则随机得到 扬州(/d/yangzhou) 或 襄阳(/d/xiangyang) 目录中的任何一个地点。
string get_random_place(string *dirs)
{
        int  i, j, k;
        object  newob;
        mixed *file, exit;
                

        if( !sizeof(dirs) )  return "error";

        i = random(sizeof(dirs));    // pick up one directory

        file = get_dir( dirs[i]+"/*.lpc", -1 );
        
        if(!sizeof(file))
         return "error";
                                 
	for(k=0;k<30;k++) { // try 20 times
		
           j = random(sizeof(file));
           if( file[j][1] > 0 ) {
             newob=load_object(dirs[i]+"/"+file[j][0]);
             if (newob)  
               if(newob->query("no_fight") ||
                  newob->query("sleep_room")||
                  newob->query("no_death")||
                  newob->query("no_select")||
		       !(exit=newob->query("exits")) ||
		       sizeof(exit)<1)
		   continue;
	    break;
	}
	}

              
        return dirs[i]+"/"+file[j][0];
}

int valid_do_job(object ob,string jobname)
{
	return 1;
}

//这个函数运算量太大，最好不用。
void copy_object(object newob,object ob)
{       
  mixed *klist;int i;mapping list;
	mapping skills;mixed *skl;
  
  list=(mapping)ob->query_entire_dbase();
	klist=keys(list);
        for(i=0;i<sizeof(klist);i++)
	newob->set(klist[i],list[klist[i]]);
        skills=ob->query_skills();
        if(!skills) return;
	skl=keys(skills);
	for(i=0;i<sizeof(skl);i++){
	if(skl[i]=="busi-yin") continue;
	newob->set_skill(skl[i],skills[skl[i]]);}
  newob->delete("env");
	newob->reset_action(newob->query_temp("weapon"));
        return;
}