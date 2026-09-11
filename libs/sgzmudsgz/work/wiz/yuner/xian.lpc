// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Rust
#include <mudlib.h>
#include <setbit.h>
#include <daemons.h>

inherit CMD;


private void main() 
{
    string msg;
    if(!this_body()->query_userid() == "rou")
    {
        return;
    }
    if (this_body()->is_visible())
        printf("好妹妹，你现在没有隐形啊 @_@。\n");
    else
    {
        this_body()->set_visibility(1);
        FINGER_D->update_me();
        this_body()->do_player_message("vis");
        out("你决定不隐形了，*pout rou，为什么呢？ @_@\n");
    }
}
