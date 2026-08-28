// Ipush (Immortal push) -command, coded by Yorkaturr


int main (string str)
{
  object ob;
  int i, hitpongat;
  string *dirs;
  string exit_dir;

    if(!str)
    {
    write("Usage: ipush <player>.\n");
    return 0;
    }

    ob = present(lower_case(str),ENV(THIS));

    if(ob && living(ob))
    {

     dirs = keys( ENV(ob)->query_exits() );

        if( sizeof(keys(ENV(ob)->query_exits())) )
        {
         tell_object(ob, "You sense that "+THIS->query_cap_name()+" does not enjoy your company, but alas,\n"+
                  "your feet are slower than your wits. "+THIS->query_cap_name()+" suddenly grabs\n"+
                  "you by the throat and shoves you away!\n");
         message("standard",THIS->query_cap_name()+" yells '^c1GO AWAY!^c0' and brutally pushes "
                            +ob->query_cap_name()+"!\n",ENV(ob),ob);

         exit_dir = dirs[random(i)];
         ob->force_us(exit_dir);
         return 1;
        }                               // end if
        else if( !sizeof(keys(ENV(ob)->query_exits())) )
        {
         tell_object(THIS, "Due to the fact that there are no exits in this room to push "+ob->query_cap_name()+"\n"+
                     "out of, you are forced to ram "+ob->query_cap_name()+" against the nearest wall.\n");
         tell_object(ob, "Since there are no apparent exits in the room, "+THIS->query_cap_name()+" is forced\n"+
                   "to ram you against the nearest wall!\n");
         message("standard",THIS->query_cap_name()+" rams "+ob->query_cap_name()+" against the nearest wall with\n"+
                      "a loud '^c1BLAM^c0'!!!\n", ENV(ob));

	ob->add_hp(-random(100));
         return 1;
        }                               // end else if
      }                                 // end if(ob)
    else
    {
      write ("No such living thing.\n");
    }                                   // end else
 }                                      // end main


query_help()
{
  return "Ipush (immortal push) is an effective way to get rid of annoying mortals"+
          " or monsters temporarily. Ipush moves the target "+
         "through a random exit. If no exits are available, ipush blams "+
         "the target against the nearest wall and decreases "+
          "random(100) hitpoints from him/her/it.";
}

query_author() { return "yorkaturr"; }

