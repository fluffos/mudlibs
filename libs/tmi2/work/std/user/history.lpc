/*
// file: /std/player/history.c
// author: Portals (wayfarer and huthar)
// last modified: 1992/03/08 - Truilkan@TMI
// Changed so objects with euid Root can query_history()
//   (eg /cmds/std/_history.c when a non-admin user is
//    using the history command on themselves.)
// Pallando (93-02-06)
// Added a query_last_command() lfun. Mobydick, 5-26-93.
// Added support for porting history across su's Descartes 940811
//
// changed enqueue to hist_enqueue to prevent conflicting inheritance, Leto

*/

#include <commands.h>
#include <uid.h>

private nosave string *history_queue;
private nosave int cmd_num, ptr;
private nosave int max;

int query_cmd_num() { return cmd_num; }
int query_ptr() { return ptr; }
int query_max() { return max; }
 
string *query_history() {

   if(!adminp(geteuid(previous_object()))&&
      (geteuid(previous_object()) != ROOT_UID) &&
      (base_name(previous_object()) != CMD_SU))
     {
        log_file( "hist_err", wrap(ctime(time())+" "+geteuid(previous_object())+
                  identify(previous_object())) );
        return 0;
     }
 
// As soon as someone installs a driver with previous_object(n) I'm going
// to give the whole call stack so you can't get around this
if( this_player(1) != this_object() && adminp(getuid(this_object())) )
  receive( sprintf("%s just read your history!\n",
	capitalize( this_player(1)->query("name") ) ) );
return history_queue; }

void set_history(string *arr, int num, int p, int m) {
    if(base_name(previous_object()) != CMD_SU) return;
    history_queue = arr;
    cmd_num = num;
    ptr = p;
    max = m;
}
void hist_alloc(int size)
{
    if (pointerp(history_queue) && sizeof(history_queue))  return;
    if (size <= 1)  size = 2;
    history_queue = allocate(max = size);
    cmd_num = 0;
}

void hist_enqueue(string str)
{
   string tmp;

   if(!max)
      return;
   if (str == "" && cmd_num)
      if (ptr)
         str = history_queue[ptr-1];
      else
         str = history_queue[max-1];
   history_queue[ptr++] = str;
   cmd_num++;
   if(ptr == max)
      ptr = 0;
}

string handle_history(string str)
{
   int tmp, tmp2;
   string *tmpq;
   string *lines;
   string cmd;

   if(str[0] != '!' || str == "!")
   {
      hist_enqueue(str);
      return str;
   }

   if(!history_queue || sizeof(history_queue) == 0)
   {
      write(str[1 .. strlen(str) - 1]+": Event not found.\n");
      return "";
   }
   if(str[0 .. 1] == "!!")
   {
      if((tmp = ptr - 1) < 0)
         tmp = max - 1;
      cmd = history_queue[tmp];
      if(str != "!!")
         cmd = cmd + str[2 .. strlen(str) - 1];
   }
   else
   if(sscanf(str,"!%d",tmp2))
   {
      tmp = tmp2;
      if(tmp > 0)
         tmp = tmp - cmd_num - 1;
      if(tmp >= 0 || (-tmp) > max)
      {
         write(tmp2+": Event not found.\n");
         return "";
      }
      if((tmp = ptr + tmp) < 0)
         tmp = max + tmp;
      cmd = history_queue[tmp];
   }
   else
   {
      str = str[1..strlen(str)];
      if(!ptr)
         tmpq = history_queue;
      else
         tmpq = history_queue[ptr .. (max - 1)] +
            history_queue[0 .. ptr - 1];

      lines = regexp(tmpq,"^"+str);
      if(!sizeof(lines))
      {
         write(str+": Event not found.\n");
         return "";
      }
      cmd = lines[sizeof(lines) - 1];
   }

   write(cmd+"\n");
   hist_enqueue(cmd);
   return cmd;
}

string query_last_command() {
   if (previous_object() && !adminp(geteuid(previous_object())) &&
     (geteuid(previous_object()) != ROOT_UID))
     {
        log_file( "hist_err", wrap(ctime(time())+" "+geteuid(previous_object())+
                  identify(previous_object())) );
        return 0;
     }
	if (cmd_num<1) return "" ;
#if 0
	if (adminp(this_object()->query("name"))>-1){
	    if (geteuid(previous_object())!=ROOT_UID &&
		previous_object()!=this_object()) return "" ;
	}
#endif
	if (ptr == 0)
		return history_queue[max-1];
	return history_queue[ptr-1];
}
