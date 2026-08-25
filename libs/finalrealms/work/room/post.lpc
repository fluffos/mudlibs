
inherit "/std/noncombat";
#include "mail.h";
 
object sign;
 
void init()
{
   ::init();
   add_action("do_mail", "mail");
   add_action("do_mail", "read");
}
 
void setup()
{
   set_short(mud_name() + " post office.");
   set_long("This is the FR:Illumitech Post Office.  If you are "+
            "applying to become a creator, please mail Benedick "+
            "and include: Your Real Name, Your EMail Address, the "+
            "IP Address and Name of the mud you're normally on (your "+
            "login name there might be helpful also!),  What you "+
            "hope to learn/accomplish here, and how you heard about "+
            "FR:Illumitech.\n\n");

   sign=add_sign("The commands are as follows:\n"
             "   mail <Person's name>    is used to send a message\n"
             "   read                    is used to read messages\n\n");
 
   set_light(80);
    
   add_exit("west", "/room/entryroom", "door");  
   
}
 
int do_mail(string TO_WHOM)
{
   object ob;
   ob=clone_object("/obj/handlers/post");
   ob->move(this_player());
   ob->start_mail(TO_WHOM);
   return 1;
}
 
void send_message(string TO_WHOM)
{
   write("You finish.\n\n");
   
   say(this_player()->query_cap_name()+" is finished mailing.\n\n");
   if(find_living(TO_WHOM))
      call_out("after_call", 5, TO_WHOM);
}
 
void after_call(string TO_WHOM)
{
   object TARGET;
   TARGET=find_living(TO_WHOM);
   if(!TARGET)
      return;
}
