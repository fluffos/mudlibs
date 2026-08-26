/* look.c

 Tacitus @ LPUniversity
 06-Oct-06 
 Look Command (Rewrite # ... 3?)
 
*/

object room;

int render_room();
int render_object(string target);
int render_container(string target);
string highlight_view(string str, string *keys);

int main(string arguments)
{
    string target;
    
    room = environment(this_player());
    
    if(!arguments) return render_room();        
    if(sscanf(arguments, "at %s", target)) 
        return render_object(lower_case(target));
    if(sscanf(arguments, "in %s", target)) 
        return render_container(lower_case(target));
    else return render_object(arguments);
}

string highlight_view(string str, string *keys)
{
    int i;
    
    /* Recode following with regexp? */
    
    if(sizeof(keys) <= 0) return str;
    
    for(i = 0; i < sizeof(keys); i++)
    {
        str = replace_string(str , " " + keys[i] + " ", " %^GREEN%^" + keys[i] 
            + "%^RESET%^ ");
        str = replace_string(str , " " + capitalize(keys[i]) + " ", " %^GREEN%^" 
            + capitalize(keys[i]) + "%^RESET%^ ");
        str = replace_string(str , " " + keys[i] + ",", " %^GREEN%^" + keys[i] 
            + "%^RESET%^,");
        str = replace_string(str , " " + keys[i] + ".", " %^GREEN%^" + keys[i] 
            + "%^RESET%^.");
        str = replace_string(str , " " + keys[i] + "!", " %^GREEN%^" + keys[i] 
            + "%^RESET%^!");
        str = replace_string(str , " " + keys[i] + ";", " %^GREEN%^" + keys[i] 
            + "%^RESET%^;");
        str = replace_string(str , " " + keys[i] + "'", " %^GREEN%^" + keys[i] 
            + "%^RESET%^'");
        str = replace_string(str , " " + keys[i] + ":", " %^GREEN%^" + keys[i] 
            + "%^RESET%^:");
    }

    return str;
}

int render_room()
{
    string *exits, *users, *objects;
    
    if(!objectp(room)) 
        return notify_fail("You see nothing because you have no environment!\n");
        
    write("\t%^BOLD%^" + room->query_short() + "%^RESET%^\n\n");
    write(highlight_view(room->query_long(), keys(room->query_items())) + "\n");

    exits = keys(room->query_exits());
    
    switch(sizeof(exits))
    {
        case 0 :
        {
            write("%^CYAN%^There are no obvious exits here.\n\n");
            break;
        }
        
        case 1 :
        {
            write("%^CYAN%^The only obvious exit is%^RESET%^BOLD%^YELLOW%^ "
                + exits[0] + "%^RESET%^CYAN%^.\n\n%^RESET%^"); 
            break;
        }
        
        default :
        {
            write("%^CYAN%^" + 
                sprintf("The only obvious exits are %s, and %s.\n\n", HIY 
                + implode (exits[0..<2], NOR + ", " + HIY), HIY + exits[<1] 
                + NOR));
        }
    }
    
    users = filter(all_inventory(room), (: living($1) && $1 != this_player() :));
    objects = filter(all_inventory(room), (: !living($1) :));
    
    if(sizeof(users) > 0) write(implode(users->query_short(), "\n") + "\n"); 
    if(sizeof(objects) > 0) write(implode(objects->query_short(), "\n") + "\n");
    
    write("\n"); 
    return 1;   
}

int render_object(string target)
{
    object ob, user;
    string subtarget;

    if(stringp(room->query_item(target)))
    {
        write(highlight_view(room->query_item(target), keys(room->query_items())) 
            + "\n");
        return 1;
    }
    
    if(sscanf(target, "%s in %s", target, subtarget) == 2 || 
        sscanf(target, "%s on %s", target, subtarget) == 2 && subtarget != "me")
    {
        user = present(subtarget, room);
        if(!objectp(user)) return notify_fail("You can not find '" + subtarget
            + "'.\n");
        ob = present(target, user);
    }

    else
    {
        ob = present(target, room);
        if(!objectp(ob)) ob = present(target, this_player());
    }
    
    if(!objectp(ob)) return notify_fail("You can't find '" + target + "'.\n");
    
    
    if(living(ob))
    {
        object *inv = all_inventory(ob);
        
        if(ob == this_player())
        {
            write("You look at yourself.\n");
            tell_room(room, this_player()->query_cap_name() 
                + " looks at themselfs.\n", ({ ob }));
            
            write("\t%^BOLD%^" + ob->query_cap_name() + "%^RESET%^\n\n");
            write(ob->query_long() + "\n");
            write(implode(filter(inv->query("extra_look"), (: $1 :)),
                "\n") + "\n\n");
            
            if(sizeof(inv) <= 0) write("You are carrying nothing.\n\n");
            else write("You are carrying:\n" + implode(inv->query_short(), 
                "\n") + "\n\n");
        }
        
        else
        {
            write("You look at " + ob->query_cap_name() + ".\n");
            tell_room(room, this_player()->query_cap_name() + " looks at " +
                ob->query_cap_name() + ".\n", ({ this_player(), ob }) );
            tell_object(ob, this_player()->query_cap_name() + " looks at you.\n");
            
            write("\t%^BOLD%^" + ob->query_cap_name() + "%^RESET%^\n\n");
            write(ob->query_long() + "\n");
            write(implode(filter(inv->query("extra_look"), (: $1 :)),
                "\n") + "\n\n");
            
            if(sizeof(inv) <= 0) write(ob->query_cap_name() 
                + " is carrying nothing.\n\n");
            else write(ob->query_cap_name() + " is carrying:\n" 
                + implode(inv->query_short(), "\n") + "\n\n");
        }
              
    }
    
    else
    {
        if(objectp(user))
        {
            write("You look at a " + ob->query_short() + " on "
                + user->query_cap_name() + "\n\n");
            tell_object(user, this_player()->query_cap_name() 
                + " looks you over.\n");
            tell_room(room, this_player()->query_cap_name() +
                " looks over " + ob->query_short() + "\n",
                ({ this_player(), user }));
        }
        
        else
        {        
            write("You look at a " + ob->query_short() + "\n\n");
            tell_room(room, this_player()->query_cap_name() + " looks at "
                + ob->query_short() + "\n", ({ this_player() }) );
        }
        
        write(ob->query_long() + "\n");        
    }  
    
    return 1;
}

int render_container(string target)
{
    return notify_fail("Error: Containers are not implemented yet.\n");
}

string help()
{
    return(HIW + " SYNTAX:" + NOR + " look [<in/at>] <object> [<on/in> <object>]\n\n" +
      "This command will allow you to look at objects in your environment.\n" +
      "If no command is supplied, it will show you the whole room. You can\n" +
      "also look at specific objects by typing 'look <object>' or 'look at object'.\n" +
      "You might also try looking into an object by type 'look in <object>'.\n");
}
