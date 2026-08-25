// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Rust -- An example for the guys on Red Dragon...
// This can't get much easier because call_out's interface isn't too good.
// I'll try to explain what is going on...
// If you don't understand any part of this, post to lima.help on Lima Bean.

#include <mudlib.h>
inherit ROOM;
inherit CLASS_COMBAT_RESULT;

private void do_burning(object player)
{
    // First check to see if the player is here.  If he isn't, stop burning
    // him by returning
    if ( !player )
        return;  // object has been destroyed.

    if ( environment(player) != this_object() )
    {
        return;
    }

    //reduce hit points here
    player->do_damage(new(class combat_result,
                          kind : "fire",
                          damage : 5,
                          message : "$T发出痛苦的尖叫！\n"));  
    this_body()->simple_action("$N被熔岩灼伤了！");

    // Now we call_out again...
    call_out((: do_burning($(player)) :), 5);
}

private void when_person_enters(object o)
{
    // If the object passed to us isn't living, then it was a regular old
    // object (probably someone dropped it)
    // So let's have it burn up in the lava.
    if ( !o->is_living() )
    {
        receive_inside_msg(o->short() +
                  "沉在熔岩里消失了...\n");
        destruct(o);
    }

    // This is the initial call to the burn_player function...  The call keeps
    // getting renewed from inside do_burning () until the person leaves.
    call_out( (: do_burning($(o)):), 5);
}

void setup() 
{
    set_brief("熔岩山洞");
    set_area("none");
    set_long("这里地面全是滚烫的热熔岩浆(lava)！");
    set_exits( ([ "southeast" : "wizroom" ]) );
    add_item("lava", "floor",
             (["adjs" : ({ "燃烧的", "热的" }),
              "look" : "看上去热气灼人。",
              "touch" : "别笨了！会烫伤的！",
              "get" : "你疯了吗？", ]));
    add_item("exit", "exits", "唯一的出口在西南方。");

    // Set it up so our functions get called when something enters.
    add_hook("object_arrived", (: when_person_enters :));
}
