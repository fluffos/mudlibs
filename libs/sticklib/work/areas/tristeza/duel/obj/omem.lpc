/*
** omem.c
**
** Keeps track of objects and allows clones
** after desired time.
**
** (C) Tron.
**
*/
 
 
#define FNAME 0
#define TIME  1
#define RESET 2
 
mapping mem_list;
 
int resets;
 
void
reset(status arg) {
 
 
    if(arg) { 
        resets++;
        return;
       }
 
    mem_list = ([]);
}
 
private object
can_clone(string id) {
 
mixed *vec;
 
   vec = mem_list[id];
 
   if(vec) {
      if((resets - vec[RESET]) >= vec[TIME])
        {
          mem_list = m_delete(mem_list, id);
          return clone_object(vec[FNAME]);
       }
    }
 
return 0;
}
 
object
clone(string id, string o_t) {
 
object ob;
string fname;
int time;
 
    if(!id) return 0;
 
    if(!o_t) {
       mem_list = m_delete(mem_list, id);
       return 0;
      }
 
    if(sscanf(o_t, "%s#%d", fname, time) !=2) 
       return 0;
 
    if(!mem_list[id]) {
       mem_list += ([ id: ({fname, time, resets}) ]);
       return clone_object(fname);
      }
 
return can_clone(id);
}
 
status
query_ob(string id) { 
 
 if(!id || !mem_list[id]) return 0;
 return 1;
}
