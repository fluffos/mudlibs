
#include <std.h>
#include <bboard.h>
#include <daemons.h>
inherit OBJECT;
mapping title;
string tm;
void create()
{
 set_name("box");
 set_short("a board in a box");
 set_long("The following commands you can use to read posts:\n"
          "<list> - lists all the boards\n"
          "<read> - checks all your unread posts on all boards.\n"
          "<post on [board]> - posts on a certain board.\n");
 set_mass(1);
set_prevent_get("You can't take that.");
 set_id( ({ "box", "board in a box" }) );
 
}
void init()
{
 ::init();
 
 add_action("__list", "list");
 add_action("__read", "read");
 add_action("__post", "post");
}
int __post(string str)
{
 string *st, b;
 if (!str || str=="")
  return notify_fail("Post on which board?\n");
 if (sscanf(str, "on %s", b) != 1)
   return notify_fail("Post on which board?\n");
 st = get_dir(BBOARD_DIR);
 if (!st)
   return notify_fail("That board doesnt exist.\n");
 if (member_array(b+".o", st)==-1)
   return notify_fail("That board doesnt exist.\n");
  
 if (!title) title = ([]);
/*
    if((int)BBOARD_D->get_num_posts(b) >= max_posts) {
        notify_fail("You will first have to remove a note!\n");
        return 0;
    }
*/
    if(strlen(str) > 30) {
        notify_fail("Title cannot contain more than 30 characters.\n");
        return 0;
    }
    if(title[this_player()]) write("Warning! You are already marked as
posting!");
    title[this_player()] = str;
    tm = b;
    write("Edit post.\n");
   
this_player()->edit(BBOARD_EDIT+(string)this_player()->query_name(),"postit",
this_object());
    return 1;
}
varargs int postit() {
    int x;
    x = (int)BBOARD_D->post_message(tm, title[this_player()]);
    if(x == BBOARD_OK) write("Posted.\n");
    else if(x == EDIT_ABORT) write("Edit aborted.\n");
    else if(x == BAD_DATA) write("Error in posting call.\n");
    map_delete(title, this_player());
    return 1;
}
int __read()
{
 string *str, tmp;
 int i, read;
 int number;
 mapping msg;
 string *lines;
 if (!i = sizeof(str = get_dir(BBOARD_DIR)))
   return notify_fail("Board error!\n");
     while(i--)
      {
       sscanf(str[i], "%s.o", tmp);
       read =(int)BBOARD_D->get_num_read(tmp,
(string)this_player()->query_name());
       if ((int)BBOARD_D->get_num_posts(tmp)-read > 0)
         {
         number = 1 + (int)BBOARD_D->get_new_post(tmp,
(string)this_player()->query_name());
             msg = (mapping)BBOARD_D->get_message(tmp, number-1);
    if(!msg) {
        notify_fail("Invalid message number.\n");
        return 0;
    }
    lines = ({ ""+tmp +" board post #"+number+" by "+capitalize(msg["owner"])+",
subject: "+msg["title"] });
    
    lines += explode(msg["message"], "\n");
    this_player()->more(lines);
    BBOARD_D->set_read(tmp, (string)this_player()->query_name(), number-1);
     return 1;
         }
         
      }
   }
int __list(string tt)
{
 string *str, out, tmp;
 int read, unread, i;
if (tt) return 0;
write("Here are your current unread posts:"); 
 if (!i = sizeof(str = get_dir(BBOARD_DIR)))
 return notify_fail("Problem get_dir for "+BBOARD_DIR+" failed.\n");
 while(i--)
  {
   sscanf(str[i], "%s.o", tmp);
   read =(int)BBOARD_D->get_num_read(tmp, (string)this_player()->query_name());
   if (read==-1)
     {
      write(tmp+": 0");
      continue;
     }
   unread = (int)BBOARD_D->get_num_posts(tmp)-read;
   out = arrange_string(arrange_string(tmp, 17)+": ["+""+unread+"]", 25); 
 
   if ((i-1) > 0)
    {
   sscanf(str[i-1], "%s.o", tmp);
read =(int)BBOARD_D->get_num_read(tmp,(string)this_player()->query_name());
   if (read==-1)
     {
      write(tmp+": 0");
      continue;
     }
   out +=
arrange_string(arrange_string(tmp,17)+":
["+(BBOARD_D->get_num_posts(tmp)-read)+"]",25);
    i--;
    }
    if ((i-2) > 0)
    {
   sscanf(str[i-2], "%s.o", tmp);
read =(int)BBOARD_D->get_num_read(tmp,(string)this_player()->query_name());
   if (read==-1)
     {
      write(tmp+": 0");
      continue;
     }
   out +=
arrange_string(tmp,17)+": ["+(BBOARD_D->get_num_posts(tmp)-read)+"]";
    i--;
    }
 write(out);
}
 return 1;
}
int query_auto_load()
{
 return 1;
}
