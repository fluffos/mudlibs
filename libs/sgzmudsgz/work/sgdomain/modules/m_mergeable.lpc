// m_mergeable by fire on Nov 1998
// if on object is inherited from this it is 
// mergeable
#include <hooks.h>
void add_hook(string tag, function hook);
private int ori_size=VERY_SMALL;
private int count=1;
//:Function set_ori_size
//
// Set the original size of on mergeable object 
void set_ori_size(int s)
{
    ori_size=s;
}
int query_ori_size()
{
   return ori_size;
}

void adjust_size() {
  this_object()->set_size(count*ori_size);

}

int query_count()
{
   return count;
}
void set_look()
{
    string s;
    s=chinese_number(query_count());
    s+=this_object()->query_unit();
   if(sizeof(this_object()->query_adj()))
     s+=this_object()->query_adj()[0];
    s+=this_object()->query_chinese_id();
    s+="("+this_object()->query_id()[0]+")";
    this_object()->set_proper_name(s);
    this_object()->set_in_room_desc(s);
}
void set_count(int n)
{
    object env;
    count=n;
    adjust_size();
    set_look();
    env=environment(this_object());
    if(objectp(env)) env->update_capacity();

}
void merge()
{
   mixed objs;
   object env;
   string f_name,f_name2;
   int n,n2;
   n=query_count();
   f_name=file_name(this_object());
   f_name=explode(f_name,"#")[0];
   env=environment(this_object());
   objs=all_inventory(env);
   foreach(object o in objs)
   {
       if(o!=this_object())
       {
          f_name2=file_name(o);
          f_name2=explode(f_name2,"#")[0];
          if(f_name==f_name2)
          {
            n2=o->query_count();
             n+=n2;
             destruct(o);
          }        
       }
   }
   set_count(n);
}
void merge_setup()
{
   add_hook("move",(:merge:));
}
mixed is_mergeable()
{ return 1;
}
mixed split(int n)
{
   int count;
   string f_name;
   object o;
   count=query_count();
   if(n>count) return -1; // can't split
   if(n==count) return this_object();
   if(n<=0) return 0; // wrong input
  
   f_name=file_name(this_object());
   f_name=explode(f_name,"#")[0];
   o=new(f_name);
   o->set_count(n);
   this_object()->set_count(count-n);
   return o;  
}
