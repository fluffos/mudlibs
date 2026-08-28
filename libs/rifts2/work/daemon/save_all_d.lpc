//--==** /wizards/thrace/save_all_d2.c **==--
// 
// /daemon/save_all_d.c
// Daemon which allows players to save items on thier bodies over
// crashes, quits and reboots.
// Written by: Thrace (April 11 '1999)
// Special thanks to Helios.
// Updated by Thrace May 30, 1999 to add support for new file sys.
// Updated by Thrace May 31, 1999 to fix duped item bug.

#include <std.h>
#include <security.h>
#include <move.h>
#include <daemons.h>

inherit DAEMON;


int do_save_filter(object ob){
    if(!ob->query_auto_load() && !ob->query_property("no save"))
        return 1;
    else
        return 0;
}

void add_crash_items(object player, int flag){
    object *inv;
    object a;
    int i;
    string tmp, file, *inv2;
    string letter, save_dir, name;

    name=player->query_true_name();
    letter = explode(name, "")[0];
   
    save_dir = DIR_OBJECTS+"/saveall/"+letter;
    mkdir(save_dir);

    save_dir = DIR_OBJECTS+"/saveall/"+letter+"/"+name;
    mkdir(save_dir);
   
    save_dir += "/";
    inv2 = get_dir(save_dir+name+"_*"); 
    for (i=0;i<sizeof(inv2);i++){
//        file = save_dir+name+"_*"+inv2[i];
       file = save_dir+name+"_"+i+".o";
        rm(file);
    }
    inv = all_inventory(player);
    inv = filter_array(inv, "do_save_filter");
    for(i=0;i<sizeof(inv);i++){
        a=inv[i];
        a->save_me("saveall/"+letter+"/"+name+"/"+name+"_"+i);
        if(virtualp(a)){
            tmp = DIR_OBJECTS+"/saveall/"+letter+"/"+name+"/"+name+"_"+i;
            rename(tmp + ".o", tmp + ".tmp");
            write_file(tmp+".o", "#"+base_name(a)+"\n", 1);
            file = read_file(tmp+".tmp");
            write_file(tmp+".o", file, 0);
            rm(tmp+".tmp");
        }
        if (flag) {
            a->remove();
        }
    }
    message("info", "%^BOLD%^%^YELLOW%^-%^CYAN%^*%^MAGENTA%^>%^RESET%^%^RED%^ Items Saved:%^RESET%^ "+sizeof(inv)+".", player);
    return;
}

void restore_crash_items(object player){
    string file;
    string obj;
    object ob;
    int x, i;
    string *inv, name, letter, save_dir;

    
    name=player->query_true_name();
    letter = explode(name, "")[0];
    save_dir = DIR_OBJECTS+"/saveall/"+letter+"/"+name;

    inv = get_dir(save_dir+"/"+name+"_*");
    for (i=0;i<sizeof(inv);i++){
        file = save_dir+"/"+inv[i];
        obj = replace_string(read_file(file, 1, 1), "#", "");
        obj = replace_string(obj, "\n", "");
        ob = new(obj);
       
ob->restore_me("saveall/"+letter+"/"+name+"/"+inv[i][0..(sizeof(inv[i])-3)]
);
        x = ob->move(player);
        message("info", "%^BOLD%^%^YELLOW%^-%^CYAN%^*%^MAGENTA%^>%^RESET%^%^RED%^ Item restored:%^RESET%^"+(string)ob->query_short()+".", player);
        if(x != MOVE_OK){
            message("info", "%^CYAN%^"+ob->query_short()+" was too heavy to hold, you drop it.%^RESET%^", player);
            ob->move(environment(player));
       }
        rm(file);
    }
    return;
}
