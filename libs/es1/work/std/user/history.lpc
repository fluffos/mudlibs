//#pragma save_binary

/*
// file: /std/player/history.c
// author: Portals (wayfarer and huthar)
// last modified: 1992/03/08 - Truilkan@TMI
// Changed so objects with euid Root can query_history()
//   (eg /cmds/std/_history.c when a non-admin user is
//    using the history command on themselves.)
// Pallando (93-02-06)
// Added a query_last_command() lfun. Mobydick, 5-26-93.
*/

#include <uid.h>

 nosave string *history_queue;
 nosave int cmd_num, ptr;
 nosave int max;

int query_cmd_num() { return cmd_num; }
int query_ptr() { return ptr; }
int query_max() { return max; }

string *query_history() {

   if(!member_group(geteuid(previous_object()), "admin")&&
     (geteuid(previous_object()) != ROOT_UID))
     {
        log_file( "hist_err", wrap(ctime(time())+" "+geteuid(previous_object())+
                  identify(previous_object())) );
        return 0;
     }

return history_queue; }

void alloc(int size)
{
    max = size;
    if (max)
       history_queue = allocate(max);
    cmd_num = 0;
}

void enqueue(string str)
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
      enqueue(str);
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
   enqueue(cmd);
   return cmd;
}

string query_last_command() {
   if (previous_object() && !member_group(geteuid(previous_object()),"admin") &&
     (geteuid(previous_object()) != ROOT_UID))
     {
        log_file( "hist_err", wrap(ctime(time())+" "+geteuid(previous_object())+
                  identify(previous_object())) );
        return 0;
     }
	if (cmd_num<1) return "" ;
	if (ptr == 0)
		return history_queue[max-1];
	return history_queue[ptr-1];
}
