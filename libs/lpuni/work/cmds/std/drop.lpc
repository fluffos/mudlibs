/* drop.c

 Ico2 @ LPUniversity
 27-OCTOBER-05
 Standard command

QC Review: Tacitus on October 28th, 2005

Last edited on June 27th, 2006 by Tacitus

*/

int main(string arg)
{
     if(!arg) return(notify_fail("SYNTAX: drop <object>\n"));

     if(arg == "all")
     {
         object *inv = all_inventory(this_player());
         foreach(object item in inv)
         {
             if(!item->move(environment(this_player())))
                 write("Error [drop]: " + capitalize(item->query_short()) +
                     " can not be droped here.\n");
            else
            {
                write("Success [drop]: You drop a '" + item->query_short() + "'.\n");
                say(capitalize(this_player()->query_name()) + " drops a '"
                    + item->query_short() + "'.\n");
            }
         }

         return 1;
     }

     if(sscanf(arg, "all %s", arg))
     {
         object item, *failedObjects = ({});

         item = present(arg, this_player());

         while(objectp(item) && member_array(item, failedObjects) == -1)
         {
             if(!item->move(environment(this_player())))
             {
                 write("Error [drop]: " + capitalize(item->query_short()) +
                     " can not be droped here.\n");
                 failedObjects += ({ item });
             }
            else
            {
                write("Success [drop]: You drop a '" + item->query_short() + "'.\n");
                say(capitalize(this_player()->query_name()) + " drops a '"
                    + item->query_short() + "'.\n");
            }

            item = present(arg, this_player());
         }

         return 1;
     }

     else
     {
         object ob;

        ob = present(arg, this_player());

        if(!ob) return(notify_fail("Error [drop]: You don't have a '" + arg + "' in your inventory.\n"));
        if(ob->query("prevent_drop") || ob->prevent_drop()) return(notify_fail("Error [drop]: That object can not be dropped.\n"));
        if(!ob->move(environment(this_player()))) return(notify_fail("Error [drop]: That object can not be droped here.\n"));

        write("Success [drop]: You drop a '" + ob->query("short") + "'.\n");
        say(capitalize(this_player()->query_name()) + " drops a '" + ob->query("short") + "'.\n");

        return 1;
    }
}

string help()
{
     return(HIW + " SYNTAX: " + NOR + "drop <item>\n\n"
     "This command will allow you to drop an object you are currently\n"
     "holding onto the ground. The argument you provide, will be the\n"
     "name of the object you wish to drop.\n\n" +
     HIW + "See also: " + NOR + "get\n");
}