//this is a room where stuff ends up after something errors out
//it also cleans itself so some things go here to be removed.
#include <config.h>
#include <std.h>
#include <security.h>

#define PRISON_D ("/adm/daemon/prison_d")
#define JAIL ("/d/shadowgate/jail")
void check_my_inventory();
void clean_inventory();
inherit "/std/room";

void create()
{
    ::create();
    set("short", "The void");
    set("long",
        "You're in the void, stuck here for reasons unknown.\n"
        "To get out, simply %^WHITE%^<break free>%^WHITE%^.");
    set_property("light", 1);
    call_out("check_my_inventory", 10);
    set_property("no teleport", 1);
    set_property("indoors", 1);
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    seteuid(UID_ROOT);
    set_no_clean(1);
    return;
}

init()
{
    ::init();
    
    if(!userp(this_player()))
        return;
    
    add_action("break_free", "break");
}

int break_free(string str)
{
    if (!str) {
        return 0;
    }
    if (str != "free") {
        return 0;
    }
    TP->move_player("/d/shadow/room/forest/road30");
    return 1;
}

void handle_player_object(object ob)
{
    string start;
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ob) || !userp(ob)) {
        return;
    }
    if (PRISON_D->is_imprisoned(ob->query_true_name())) {
        ob->move_player(JAIL);
        return;
    }
    ob->set_property("voided", 1);
    if (stringp(start == ob->getenv("start"))) {
        ob->move_player(start);
        return;
    }else {
        ob->move_player("/d/shadow/room/forest/road30");
        return;
    }
    return;
}

void clean_inventory()
{
    object * players, *targets;
    object ob;
    object trash;

    if (!objectp(TO)) {
        return;
    }
    
    players = filter_array(all_inventory(TO), (:userp($1):));
    if (sizeof(players))
    {
        foreach(ob in players)
            handle_player_object(ob);
    }
    
    trash = load_object("/d/shadowgate/trash");
    targets = deep_inventory(this_object());
    
    if(sizeof(targets) > 100)
        targets = targets[0..99];
    
    foreach(ob in targets)
    {
        if(eval_cost() < 25000)
            continue;
                
        if (!objectp(ob)) {
            continue;
        }
        
        if (userp(ob)) {
            handle_player_object(ob);
            continue;
        }
        
        if(objectp(trash))
        {
            ob->move(trash);
        }
        else
        {
            if(catch(ob->remove()))
                destruct(ob);
        }   
    }
    
    sizeof(targets) && objectp(trash) && destruct(trash);
    
    return;
}

void check_my_inventory()
{
    mixed error;
    
    if (!objectp(TO)) {
        return;
    }
    if (clonep(TO)) {
        clean_inventory();
        reclaim_objects();
        TO->remove();
        return;
    }
    error = catch(clean_inventory());
    reclaim_objects();
    call_out("check_my_inventory", 10);
    return;
}
