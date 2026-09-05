#include <ansi.h>

#define DAEMON "/obj/user/rlinfo/rlinfo_daemon"

int ok_edit(string str);

int cmd_rlinfo(string str)
{
  int i;
  
  write("This command is disabled.\n");
  return 1;
  if((string)this_player()->query_real_name()=="guest") return 0;
  if(!str)
  {
    str = (string)this_player()->query_real_name();
    i = (int)"/obj/user/rlinfo/rlinfo_daemon"->query_index(str);
    if(i == -1)
    {
      write("You have not yet entered any real life information.\n"+
            "Would you like to do so now?\n"+
            "<y/n> ");
      input_to("ok_edit");
    }
    else
    {
      ok_edit("y");
    }
  }
  else
  {
    i = (int)"/obj/user/rlinfo/rlinfo_daemon"->query_index(str);
    if(i == -1)
    {
      write("There isn't any real life information entered for the\n"+
            "name \""+capitalize(str)+"\".\n");
    }
    else
    {
      string name, age, gender, location, email, www, favorite,
             quote, im, misc, occupation;
      
      name = (string)DAEMON->query_name(str);
      age = (string)DAEMON->query_age(str);
      gender = (string)DAEMON->query_gender(str);
      location = (string)DAEMON->query_location(str);
      email = (string)DAEMON->query_email(str);
      www = (string)DAEMON->query_www(str);
      favorite = (string)DAEMON->query_favorite(str);
      quote = (string)DAEMON->query_quote(str);
      im = (string)DAEMON->query_im(str);
      misc = (string)DAEMON->query_misc(str);
      occupation = (string)DAEMON->query_occupation(str);
      if(!name) name = " ";
      if(!age) age = " ";
      if(!gender) gender = " ";
      if(!location) location = " ";
      if(!email) email = " ";
      if(!www) www = " ";
      if(!favorite) favorite = " ";
      if(!quote) quote = " ";
      if(!im) im = " ";
      if(!misc) misc = " ";
      if(!occupation) occupation = " ";

      write("\n");
      write(BOLD+"Character Name:"+NORM+" "+capitalize(str)+"\n");
      write("\n");
      write(BOLD+"     Real Name:"+NORM+" "+name+"\n");
      write(BOLD+"           Age:"+NORM+" "+age+"\n");
      write(BOLD+"        Gender:"+NORM+" "+gender+"\n");
      write(BOLD+"      Location:"+NORM+" "+location+"\n");
      write(BOLD+"    Occupation:"+NORM+" "+occupation+"\n");
      write(BOLD+"E-mail Address:"+NORM+" "+email+"\n");
      write(BOLD+"       Website:"+NORM+" "+www+"\n");
      write(BOLD+"   Instant Msg:"+NORM+" "+im+"\n");
      write("\n");
      write("     "+BOLD+"Favorites:\n"+NORM);
      print(favorite+"\n", 70);
      write("\n");
      write("        "+BOLD+"Quotes:\n"+NORM);
      print(quote+"\n", 70);
      write("\n");
      write(" "+BOLD+"Miscellaneous:\n"+NORM);
      print(misc+"\n", 70);
      write("\n");
    }
  }
  return 1;
}

int ok_edit(string str)
{
  if(str=="y")
  {
    object obj;
    if((int)DAEMON->query_index((string)this_player()->query_real_name()) == -1)
      DAEMON->add_character((string)this_player()->query_real_name());
    obj = clone_object("/obj/user/rlinfo/rlinfo_editor");
    obj->start_edit();
  }
  return 1;
}

