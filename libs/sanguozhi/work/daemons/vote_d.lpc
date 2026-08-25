//filename /daemons/vote_d.c
//Created by Suicide in 02/20/2000
#include <mudlib.h>
#include <security.h>
#include <daemons.h>

#define SAVE_FILE "/data/daemons/vote"
inherit M_ACCESS;
inherit CLASS_VOTE;


private mapping vote_info=([]);
private mapping special_vote=([]);
private mapping special_vote_memo=([]);
private int last_special_voteid=90000;

void save_data()
{
    unguarded(1, (: save_object, SAVE_FILE, 1 :));
    return;
}

/*int new_special_voteid()
{
last_special_voteid ++;
save_data();
return last_special_voteid;
}*/
void remove_vote(int vote_id)
{
 if (vote_info[vote_id])
    map_delete(vote_info,vote_id);
 save_data();
}

mixed add_special_vote(string nation,string index,string memo,int time_limit,string data)
{
if (!mapp(special_vote[nation]))
   special_vote[nation] = ([]);
if (special_vote[nation][index])
    return "这个投票建议已经存在，无法建立！\n";
special_vote[nation][index] = ({last_special_voteid,memo,time_limit,data});
last_special_voteid ++;
save_data();
return 1;
}

mixed modify_special_vote(string nation,string index,mixed *info)
{
if (!mapp(special_vote[nation]))
    return "这个投票建议不存在，无法修改！\n"; 
if (!arrayp(special_vote[nation][index]))
    return "这个投票建议不存在，无法修改！\n"; 
special_vote[nation][index] = info;
save_data();
return 1;
}


mixed * get_special_vote(string nation,string index)
{if (!special_vote[nation])
    return 0;
 if (!special_vote[nation][index])
    return 0;
 return special_vote[nation][index];
}

void del_special_vote(string nation,string index)
{int vote_id;
 if (!mapp(special_vote[nation]))
   return;
 if (!arrayp(special_vote[nation][index]))
    return ;
vote_id=special_vote[nation][index][0];
remove_vote(vote_id);
map_delete(special_vote[nation],index);
save_data();
}



void add_selectitem(int vote_id,string* items,int r_right,int w_right)
{class vote_info info;
 int item_id;
 string item_text;
 info = new(class vote_info,
            readright   :1,
            writeright  :1,
            selectitems : ([]),
            result      : ([])
            );
 for (int i=0;i<sizeof(items);i++)
     {sscanf(items[i],"(%d) %s", item_id,item_text);
      info->selectitems[item_id]=item_text;}
 info->readright =r_right;
 info->writeright=w_right;
 //info->selectitems=items;
 vote_info[vote_id] = info;
 save_data();
}

mapping get_selectitems(int vote_id)
{
 if ((vote_info[vote_id]))
     return vote_info[vote_id]->selectitems;
 else
   return 0;
}
mixed can_post(string userid)
{
if (wizardp(userid))
    return 1;
else 
    return "%^RED%^你没有这个权利%^RESET%^";
}
mixed can_read(int vote_id,string userid)
{
return 1;
}
mixed can_vote(int vote_id,string userid)
{class vote_info info;
 mixed* key;
 info = vote_info[vote_id];
 key = keys(info->result);
 for (int i=0;i<sizeof(key);i++)
     if (member_array(userid,info->result[key[i]])!=-1)
         return "%^RED%^你已经参加过这个表决,不能重复投票!%^RESET%^\n"; 
return 1;
}
 
void set_vote(int vote_id,int sel_id,string userid)
{int* keys;
 int i,have_voted=0;
if (!vote_info[vote_id])
   write("没有对应的投票信息!\n");
else
   { class vote_info info = vote_info[vote_id];
     if (!info->result[sel_id])
         info->result[sel_id]=({});
     keys = keys(info->result);
     for (i=0;i<sizeof(keys);i++)
        if (member_array(userid,info->result[keys[i]])!=-1)
            have_voted = 1;
     if (!have_voted)
         {info->result[sel_id] += ({userid});
          save_data();}
     else
         write("%^RED%^你已经参加过这个表决,不能重复投票!%^RESET%^\n"); 
   }   
   
}
void del_vote(int vote_id,int sel_id,string userid)
{
if (!vote_info[vote_id])
   write("没有对应的投票信息!\n");
else
   { class vote_info info = vote_info[vote_id];
     if (!info->result[sel_id])
         return;
     if (member_array(userid,info->result[sel_id])==-1)
            return;
     else
        {info->result[sel_id] -= ({userid});
          save_data();}
     write("删除投票信息成功!\n");
   }  
}


mapping get_vote_result(int vote_id)
{
if (!vote_info[vote_id])
  {printf("没有对应的投票信息!\n");
   return ([]);}
else
  {class vote_info info = vote_info[vote_id];
   return info->result;
  } 
}

void show_vote_result(int vote_id)
{
if (!vote_info[vote_id])
   printf("没有对应的投票信息!\n");
else
  {  class vote_info info = vote_info[vote_id];
   printf("\n");
   for (int i=1;i<=sizeof(info->selectitems);i++)
       printf("%%^CYAN%%^(%2d)    %-20s  %4d票%%^RESET%%^\n",i,
                 (info->selectitems)[i],
                 sizeof((info->result)[i]));
  }               
//printf("\nHere Will show vote Result!\n");
}
void create()
{      
    unguarded(1, (: restore_object, SAVE_FILE, 1 :));
}
