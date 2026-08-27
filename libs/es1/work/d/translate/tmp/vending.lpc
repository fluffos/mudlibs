/*
07/26/94 07/27/94
1,2,1
*/
#include <mudlib.h>
#include <config.h>
 
inherit OBJECT;
 
// out_of_order: 1 if yes. 0 if no.
// chance: chance of out_of_order.
int out_of_order, chance;
 
void create()
{
    set_name("vending machine","---");
    set_long("vending machine\n","Chinese message\n");
    set_short("vending machine","Chinese name");
    set("prevent_get",1);
    chance=5;
}
 
void init()
{
    add_action("insert_coin","insert"); // ok. except deduct coins
    add_action("push_button","push");
    add_action("return_coin","return");
    add_action("kick_machine","kick"); // ok.
}
 
int push_button(string str)
{
return 1;
}
 
int insert_coin(string str)
{
    int a,b,tmp;
    string syntax;
    syntax="Syntax: insert <amount> coins. (Note: Silver coins ONLY.)\n";
    if (!str || str="" ) {
        write(syntax);
        return 1;
    }
    tmp=sscanf(str,"%d coins",a);
write(tmp);
    if (tmp!=1) {
        write(syntax);
        return 1;
    }

    // if so, deduct it.
    this_player()->debit("silver",a);
    tell_room(environment(),({
        (string)this_player()->query("cap_name")+" inserts "+str+" into the machine.\n",
        "chinese message here."
        }),({this_object(),this_player()}) );
    write(can_read_chinese()?
    "Chinese message here.":
    "You insert "+str+" into the machine.\n");
    // does the machine has $$$ originally? ps. should we set max?
    b=(int)this_object()->query("deposit");
    if (!b) {
        this_object()->set("deposit",a);
    }
    else {
        this_object()->set("deposit",a+b);
    }
    return 1;
}
 
/*
some wicked formula for calculating chances.. and a lot of randoms..
*/
int kick_machine(string str)
{
    int damage;
    int kick_chance;
    if (!str || str="" || str !="machine") {
        return 0;
    }
    damage=10;
    kick_chance=25;
        tell_room(environment(),({
            (string)this_player()->query("cap_name")+" kicks the machine.\n",
            "Chinese message here."
            }),({this_object(),this_player()}) );
    // if it's already out_of_order, do we have chance to fix it?
    if (out_of_order) { //let's see...
        // if the person who make it out_of_order kick again.. hehehehe
if ((string)this_object()->query("kickee")==(string)this_player()->query("cap_name")) {
            tell_room(environment(),({
                "The machine yells, DIE SCUM! Dare you kick me again!\n",
                "Chinese message here."
                }), this_object());
            write(can_read_chinese()?
            "Chinese message here":
            "You were zapped by something, OUCH, that HURT!\n");
            this_player()->receive_damage(random(damage));
            tell_room(environment(),({
                (string)this_player()->query("cap_name")+" was zapped by the machine.\n",
                "Chinese message here.\n"
                }),({this_object(),this_player()}) );
            return 1;
        }
        else { // let's see the chance...
            if (random(kick_chance)<chance) { // made it
                tell_room(environment(),({
                    "You see the lights went back on-line. A message displayed on the panel:\n"+
                    "Welcome to the CokeLand!\n",
                    "chinese message here"
                    }),this_object() );
                this_object()->delete("kickee");
                write(can_read_chinese()?
"Chinese message here":
                "Hey man, you fixed it! Amazing..\n");
                return 1;
            }
            write(can_read_chinese()?
            "Chinese message here":
            "You kicked the machine, but nothing happened. \n");
            return 1;
        }
    }
    // just some screwed formula to calculate out_of_order chance
    if (random(chance+kick_chance)>(chance+kick_chance)/2) { // oops!
        out_of_order=1;
        tell_room(environment(),({
        "The built in alarm sounded, and the machine yelled: "+
        (string)this_player()->query("cap_name")+" kicked me! Help! Help!\n"+
        "Then all lights went off, except a red light blinks:"+
        "OUT OF ORDER.\n",
        "Chinese message here.\n"
        }),this_object());
        this_object()->set("kickee",(string)this_player()->query("cap_name"));
        write(can_read_chinese()?
        "Chinese message here.\n":
        "Way to go buddy, you've just screwed a vending machine.\n");
        return 1;
    }
    // shouldn't get to here.
    write("You are not supposed to see this message, if you do, tell a wiz ASAP.\n");
    return 1;
}
 
 
