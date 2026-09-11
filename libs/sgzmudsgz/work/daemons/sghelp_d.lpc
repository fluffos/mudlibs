/*
** File: sghelp_d.c by fire on Dec 1998
** Created 25-OCT-94 by Deathblade for the new help system.
** This daemons is used to handle the player help system for sg
*/
#include <mudlib.h>
#include <security.h>
#include <area.h>
#define SAVE_FILE "/data/daemons/sghelp"
#define ROOT "/help/player/sanguo/"
#define BAR "----------------------------------------------------------------\n"
#define MAXNEWTIME 1209600 // two weeks
inherit M_ACCESS;
private mapping topics;
private nosave mapping real_topics;
private nosave int  pending_count;
private nosave object   initiator;
private nosave int root_length;
nomask void rebuild_data();
int add_new_topic();
void save_data()
{  unguarded(1, (: save_object, SAVE_FILE :));
}
void create()
{  unguarded(1, (: restore_object, SAVE_FILE, 1 :));
   root_length=sizeof(ROOT);
   remove_call_out("rebuild_data");
   rebuild_data();
   return;
}
nomask void process_dir(string path);
private void process_file(string path, string file)
{   string pathname;
    if ( file == "." || file == ".." ) return;
    if(member_array('.',file)!=-1) return;
    pathname = path + file;
    if ( file_size(pathname) == 0 ) return;
    if ( file_size(pathname) == -2 )
    {   pathname += "/";
        call_out((: process_dir :), 0, pathname);
        ++pending_count;
    }
    else
    {  if(real_topics[file])
       {  write("Warning "+file+" has more than one location\n");
          return;
       }
       real_topics[file] =  pathname[root_length..<1];
    }
}
nomask void process_dir(string path)
{   map_array(get_dir(path + "*"), (: process_file, path :));
    if ( !--pending_count )
    { 
       add_new_topic();
    }
}
nomask void rebuild_data()
{   string * lines;
    string * dirs;
    if ( pending_count )
    {  write("SGHELP_D 正在重建三国志帮助系统！\n");
       return;
    }
    write("SGHELP_D 开始重建三国志帮助系统 ... \n");
    initiator = this_user();
    dirs = (get_dir(ROOT+"*"));
    real_topics=([]);
    pending_count = 0;
    map_array(dirs, (: process_file, ROOT :));
}
mapping query_topics()
{   return topics;
}
mapping query_real_topics()
{   return real_topics;
}
int add_new_topic()
{
   string *top,*rtop;
   int curtime=time();
   if(!topics) topics=([]);
   top=keys(topics);
   rtop=keys(real_topics);
   rtop-=top;
   if(sizeof(rtop))
   {  foreach(string r in rtop)
      {  if(!topics[r]) topics[r]=([]); 
         topics[r]["p"]=real_topics[r];
      } 
      if(initiator)
         tell(initiator,sprintf("新增%d条帮助信息。\n",sizeof(rtop)));
   } 
   rtop=keys(real_topics);
   top-=rtop;
   if(sizeof(top))
   {
     foreach(string r in top)
        map_delete(topics, r);
      if(initiator)
         tell(initiator,sprintf("删除%d条帮助信息。\n",sizeof(top)));
   }
   rtop=keys(topics);
   foreach(string r in rtop)
   {
     topics[r]["p"]=real_topics[r];
     if(!topics[r]["parent"])
        topics[r]["parent"]=({});
     topics[r]["parent"]-=({"topics"});
     topics[r]["parent"]+=({"topics"});
     topics[r]["parent"]-=({"classes"});
     if(topics[r]["is_parent"])
       topics[r]["parent"]+=({"classes"});
     topics[r]["parent"]-=({"new"});
     if((curtime-stat(ROOT+topics[r]["p"])[1])<MAXNEWTIME)
        topics[r]["parent"]+=({"new"});
   }
   if ( initiator )
   {
     tell(initiator,"三国志帮助系统重建完成。\n");
     initiator = 0;
   }
   real_topics=0;
   save_data();
   remove_call_out("rebuild_data");
   call_out("rebuild_data",86400);
   return sizeof(rtop);
}
mixed set_topic(string topic,string para,mixed value)
{
   if(!topics[topic]) return 0;
   topics[topic][para]=value;
   save_data();
   return value;
}
mixed get_topic(string topic, string para)
{
   if(!topics[topic]) return 0;
   if((!para)||(para==""))
      return topics[topic];
   return topics[topic][para];
}
string get_count(string arg)
{
   string pathname;
   string ret="";
   string *tmp;
   if(!topics[arg]) return "没有此帮助主题。\n";
   if(!topics[arg]["p"]) return "此帮助主题内容还没有完成。\n";
   pathname=ROOT+topics[arg]["p"];
   if(file_size(pathname)<=0)
      return "BUG BUG BUG。\n";
   if(topics[arg]["t"])
   {  ret=arg+" : " + topics[arg]["t"] +"\n";
      ret+=BAR;
   }
   ret+=read_file(pathname);
   if(topics[arg]["is_parent"])
   {
      string *list,*list1,*list2;
      list=filter_array(keys(topics),
         (: member_array($(arg),topics[$1]["parent"])!=-1 :));
      list=sort_array(list,1);
      list1=filter_array(list,(:SGHELP_D->get_topic($1,"is_parent") :));
      list2=list-list1;
      list=list1+list2;
      if(sizeof(list))
      {
        int kk=0;
        ret+="\n本主题是一个帮助类，其中包括以下主题：\n"+BAR;
        foreach( string b in list)
        {  ret+=sprintf("%-12s: %-20s",b,get_topic(b,"t"));
           if(kk==1) ret+="\n";         
           kk++;
           if(kk>1)kk=0;
        }
      }
   }   
   tmp=topics[arg]["parent"];
   if(!tmp) tmp=({});
   tmp-=({"topics","classes","new"});
   if(sizeof(tmp))
   {
      int kk=0;
      string* idx;
      ret+="\n本主题所属类：\n"+BAR;
      idx=sort_array(tmp,1);
      foreach( string b in idx)
      {  ret+=sprintf("%-12s: %-20s",b,get_topic(b,"t"));
         if(kk==1) ret+="\n";         
         kk++;
         if(kk>1)kk=0;
      }
   }
   if(sizeof(topics[arg]["related"]))
   {
     int kk=0;
     string *idx;
     ret+="\n相关帮助：\n"+BAR;
     idx=sort_array(topics[arg]["related"],1);
     foreach( string b in idx)
     {  ret+=sprintf("%-12s: %-20s",b,get_topic(b,"t"));
        if(kk==1) ret+="\n";         
        kk++;
        if(kk>1)kk=0;
     }
   }
   return ret;  
}
mixed add_parent(string me,string par)
{
   if(!topics[me]) return "没有"+me+"这个帮助主题\n";
   if(!topics[par]) return "没有"+par+"这个帮助类\n";
   if(!topics[par]["is_parent"]) return par+"不是帮助类\n";
   if(!topics[me]["parent"]) topics[me]["parent"]=({});
   topics[me]["parent"]-=({par});
   topics[me]["parent"]+=({par});
   save_data();
   return me +" 加入 " + par + " 类，成功!\n";      
}
mixed sub_parent(string me,string par)
{
   if(!topics[me]) return "没有"+me+"这个帮助主题\n";
   if(!topics[me]["parent"]) topics[me]["parent"]=({});
   topics[me]["parent"]-=({par});
   save_data();
   return me +" 从 " + par + " 类中删除，成功!\n";      
}

mixed add_related(string me,string rel)
{
   if(!topics[me]) return "没有"+me+"这个帮助主题\n";
   if(!topics[rel]) return "没有"+rel+"这个帮助类\n";
   if(!topics[me]["related"]) topics[me]["related"]=({});
   topics[me]["related"]-=({rel});
   topics[me]["related"]+=({rel});
   save_data();
   return rel +" 成为 " + me + " 的相关主题!\n";
}
void system_check()
{
   string *list;
   list=keys(topics);
   list-=({"main"});
   foreach(string top in list)
   {  if(!topics[top]["t"])
         write(top+" 没有题目。\n");
      if(sizeof(topics[top]["parent"]-({"topics","classes","new"}))<1 )
         write(top+" 没有所属类。\n");
      if(file_size(ROOT+topics[top]["p"])<=0)
         write("找不到 "+top+" 的帮助文件。\n");
   }
}
mixed find_wrong()
{
   string *list;
   list=keys(topics);
   list-=({"main"});
   foreach(string top in list)
   {  if(!topics[top]["t"])
         return top+" 没有题目。\n";
      if(sizeof(topics[top]["parent"]-({"topics","classes","new"}))<1 )
         return top+" 没有所属类。\n";
      if(file_size(ROOT+topics[top]["p"])<=0)
         return "找不到 "+top+" 的帮助文件。\n";
   }
   return "找不到不完整的帮助主题。\n";
}
