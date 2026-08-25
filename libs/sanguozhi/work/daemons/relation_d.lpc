// Npc Vs player relationship  daemon
// Suicide@sgz Aug 17, 2000
#include <mudlib.h>
#include <security.h>

#define RELATION_PATH(x)       sprintf("/data/relation/%c/%s",x[0],x)
#define CLEAN_TIME             240*40   //16min*10 = 2hours40min
#define KEEP_TIME              240*30   //4min*30  = 2hours
#define MAX_NUM_IN_CACHE       150
#define CUT_NUM_OF_CACHE        51

inherit M_ACCESS;

nosave protected  mapping cache;
nosave protected  int     num_in_cache=0;

private mapping npc;

int get_bazi_diff_level(string p_id,string t_id)
{int p_bazi,t_bazi;
 if (!CHAR_D->char_exist(p_id)) return 10;
 if (!CHAR_D->char_exist(t_id)) return 10;
 p_bazi = CHAR_D->get_char(p_id,"bazi");
 t_bazi = CHAR_D->get_char(t_id,"bazi");
 if (t_bazi==p_bazi) return 0;
 return (bmax(p_bazi,t_bazi)-bmin(p_bazi,t_bazi))/10 + 1;

}

void cut_part_of_cache()
{
 int i,old_num;
 string* keys;
 remove_call_out("cut_part_of_cache");
 old_num = num_in_cache;
 keys = keys(cache);
 for (i=0;i<sizeof(cache);i++)
    if (cache[keys[i]]["time"]<=time())
       {map_delete(cache,keys[i]);
        num_in_cache -- ;}
 //如果cache中数目仍然过多,强行删除cache中的多余数据
 //使cache中的数目为150-50 = 100
 if (num_in_cache>MAX_NUM_IN_CACHE) 
    for (i=0;i<CUT_NUM_OF_CACHE ;i++)
       {map_delete(cache,keys[i]);
        num_in_cache -- ;}
 SGSYS(sprintf("系统中原有NPC关系度条目%d，清除过期数据条目后还有%d",old_num,num_in_cache));
 call_out("cut_part_of_cache",CLEAN_TIME);
}


void add_num_in_cache()
{
num_in_cache++;
//当cache中数目为151时,cache溢出,清理cache
if (num_in_cache>MAX_NUM_IN_CACHE) 
   cut_part_of_cache();
}


mixed  cvt_id(string oldid)
{string *arg;
 string result;
 int i;
 if (!CHAR_D->char_exist(oldid)) return 0;
 arg = explode(oldid," ");
 result  = arg[0];
 for (i=1;i<sizeof(arg);i++)
     result = result + "_" +arg[i];
 return result;
}

void save_data(string npcid)
{
  unguarded(1, (: save_object, RELATION_PATH(npcid), 1 :));
}

int get_relation(string id,string userid)
{string npcid;
if (!npcid=cvt_id(id)) return -1;
if (!cache[npcid]) 
   {//printf("file name = %s\n",RELATION_PATH(npcid));
    if (file_size(RELATION_PATH(npcid)+".o")==-1) return 0;
    unguarded(1, (: restore_object, RELATION_PATH(npcid), 1 :));
    npc["time"]= time()+KEEP_TIME;
    cache[npcid] = npc;
    add_num_in_cache();
   }
cache[npcid]["time"] = time()+KEEP_TIME;   
if (!cache[npcid]["data"][userid]) return 0;
else  return cache[npcid]["data"][userid];
}

int add_relation(string id,string userid,int add)
{string npcid;
 mapping tmp=([]);
 if (add==0) return -1;
if (!npcid=cvt_id(id)) return -1;
//printf("npcid = %s userid = %s \n",npcid,userid);
if (!cache[npcid]) 
   {
    if (file_size(RELATION_PATH(npcid)+".o")==-1) //文件不存在
        {
        cache[npcid] = ([]);
        tmp["data"]=([]);
        tmp["data"][userid] = add;
        tmp["time"]= time()+KEEP_TIME ;
        cache[npcid] = tmp;
        npc = tmp;
        save_data(npcid);
        add_num_in_cache();
        return add;
        }
    else
    {
     unguarded(1, (: restore_object, RELATION_PATH(npcid), 1 :));
     npc["time"]= time()+KEEP_TIME ;
     cache[npcid] = npc;
     add_num_in_cache();
    } 
   }
npc = cache[npcid];
if (!npc["data"][userid]) npc["data"][userid]=add;
else  npc["data"][userid]+=add  ;
npc["time"] = time()+KEEP_TIME ;
if (npc["data"][userid]==0) map_delete(npc["data"],userid);
save_data(npcid);
cache[npcid] = npc;
return npc["data"][userid];
}

mixed stat_me(int flag)
{
if (!flag)
   return sprintf("现在共有%d个角色的关系度数据在缓存中!\n",num_in_cache);
if (flag==1)
   return npc;
if (flag==2)
   return cache;
}

void add_both_relation(string id1,string id2,int add)
{
add_relation(id1,id2,add);
add_relation(id2,id1,add);
}


void create()
{
cache = ([]);
num_in_cache = 0;
npc = ([]);
call_out("cut_part_of_cache",CLEAN_TIME);
}
