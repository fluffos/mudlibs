/*
   Inherit base room for domain common rooms
   Orginal from who knows where...
   Fixed and cleaned up code by Radix@FR : Dec 17, 1996
   Domain security added by Radix@FR : Dec 18, 1996
   Version 1.0
*/

inherit "/std/room";

string dom_name;

int do_list(string);
int add_creator(string);
int delete_creator(string);
int add_project(string);

void init() 
{
   ::init();
   add_action("do_list", "list");
   add_action("add_creator", "add");
   add_action("delete_creator", "delete");
   add_action("set_project", "project");
   
}

string query_dom() { return dom_name; }
void set_dom(string str) { dom_name = str; }

int do_list(string arg) 
{
   string *members, *domains, mem_list;
   mixed mast;
   int i, j;

   if(arg == "all")
      domains = get_dir("/d/");
   else 
      if(!arg)
         domains = ({ dom_name });
      else 
      {
         notify_fail("Usage: list\n       list all\n");
         return 0;
      }
   if(sizeof(domains) > 1) 
      write("All domains:\n");
   else 
      write("This domain:\n");
   for(i=0; i<sizeof(domains); i++) 
   {
      mast = "/d/" + domains[i] + "/master";
      members = (string *)mast->query_members(arg);
      printf("%8s has %2d members and is owned by %s.\n", domains[i],
              sizeof((string *)mast->query_members()),
              capitalize((string)mast->query_dom_lord()));
      mem_list = "";
      for(j=0; j<sizeof(members); j++)
         mem_list+=capitalize(members[j])+
                   (j==sizeof(members)-1?".":",");
      write(mem_list + "\n\n");
   }
   return 1;
}

int add_creator(string arg) 
{
   mixed mast;
  
   if(!arg) 
   {
      notify_fail("Usage: add <creator>\n");
      return 0;
   }
   arg = (string)this_player()->expand_nickname(arg);
   mast = "/d/" + dom_name + "/master";
   if((string)mast->query__dom_lord() != geteuid(this_player())) 
   {
      notify_fail("You are not the Lord of this Domain.\n");
      return 0;
   }
   if(!mast->add_member(arg)) 
   {
      notify_fail("Failed to add "+capitalize(arg)+" to "
                   +dom_name + ".\n");
      return 0;
   }
   write("Creator "+capitalize(arg)+" now added to "+dom_name+".\n");
   return 1;
}

int delete_creator(string arg) 
{
   mixed mast;
  
   if(!arg) 
   {
      notify_fail("Usage: delete <creator>\n");
      return 0;
   }
   arg = (string)this_player()->expand_nickname(arg);
   mast = "d/"+dom_name+"/master";
   if((string)mast->query_dom_lord() != geteuid(this_player())) 
   {
      notify_fail("You are not the Lord of this Domain.\n");
      return 0;
   }
   if(!mast->remove_member(arg)) 
   {
      notify_fail("Failed to remove "+capitalize(arg)+" from "+
                   dom_name+".\n");
      return 0;
   }
   write("Member "+capitalize(arg)+" removed from "+dom_name+".\n");
   return 1;
}

int set_project(string arg) 
{
   mixed mast;
   string proj;
   if(!arg || sscanf(arg,"%s %s", arg, proj) != 2)
   {
      notify_fail("Usage: project <creator> <project>\n");
      return 0;
   }
   arg = (string)this_player()->expand_nickname(arg);
   mast = "d/"+dom_name+"/master";
   if((string)mast->query_dom_lord() != geteuid(this_player())) 
   {
      notify_fail("You are not the Lord of this Domain.\n");
      return 0;
   }
   if(!mast->set_project(arg, proj)) 
   {
      notify_fail("Failed to set the project \""+capitalize(arg)
                  +"\" for "+dom_name+".\n");
      return 0;
   }
   write("Member "+capitalize(arg)+" project set in "+dom_name+".\n");
   return 1;
}

