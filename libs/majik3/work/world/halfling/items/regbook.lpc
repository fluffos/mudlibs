inherit ITEM;

#include "../path.h"

#define room(x) message("standard", x, ENV(THIS), THIS)

string *my_array = ({});

create_item()
{
     restore_object("/world/halfling/items/pook_book.o");

     set_name(({"book","registry book"}));
     set_short("Shire Registry Book");
     set_long(wrap("The book is a leather bound text and is fairly"
  + " large. It sits on a wooded pedastal and there is a writing u"
  + "tensil next to it. Perhaps you should 'read book'.\n"));

    set_no_get(1);

    set_dimensions(40, 60, 20);
    set_weight(75);
    set_hp(40);
    set_max_hp(40);
    set_material("glass");
    
}

init()
{
  add_action("do_list","list");
  add_action("do_read","read");
  add_action("do_register","register");
}

do_register(string what)
{
  int i;
  for(i = 0;i<sizeof(my_array);i++)
  {
     if(my_array[i] ==  THIS->query_cap_name())
      {
       write("You have already registered.\n");
       return 1;
      }
  }
  if(THIS->query_money() < 50)
   {
    write(wrap("You need 50 gold coins to register.\n"));
    return 1;
   }
  if(present("clerk", ENV(THIS), THIS))
   { 
    if(!what)
     {
      write(wrap("You pay the clerk 50 gold coins. You then pick up the pencil next "
       + "to the book and sign your name in it.\n"));
      add_member(THIS->query_cap_name());
      save_object("/home/pook/halfling/items/pook_book.o");
      THIS->add_money(-50);
      return 1;
     }
    else
     {
      write(wrap("You need only type 'register' to do so.\n"));
      return 1;
     }
    }
   else
   {
    write(wrap("The clerk is not here to take your payment.\n"));
    return 1;
   }
}

string *query_members() {return my_array;}
add_member(string member) 
{ 
 if(!my_array) 
   {my_array = ({member});}
 else 
   {my_array += ({member});}
}    

do_list()
{
  int i;
  write(wrap("You read the current list of citizens from the book.\n"));
  for(i = 0;i<sizeof(my_array);i++)
   {
    write((i+1)+"- "+my_array[i]+"\n");
   }
  return 1;
}


do_read(string what)
{
  if(what == "book")
   {
    write(wrap("You open the Shire Registry Book and begin to read it:\n"
     + "This is the offical document of the citizens registered in the Shire. "
     + "Once you register you have a lifetime membership and gain full benefits "
     + "of living here, if you pay your taxes. To view the current citizens just "
     + "type 'list'.\n"));
    room(wrap(THIS->query_cap_name() + " opens the Shire Registry Book "
     + "and begins to read from it.\n"));
    return 1;
   }
  else
   {
    write(wrap("Read what?\n"));
    return 1;
   }
}

   



