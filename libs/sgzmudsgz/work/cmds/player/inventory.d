// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// Rust/Belboz@ZorkMUD wrote it
// Megaboz added header and help 5-5-94
// Beek decided to edit this one when he noticed we had two
// inventory commands.  *boggle*

#include <mudlib.h>
inherit CMD;


private void main()
{
    string ex;

    if (ex = inv_list(all_inventory(this_body()))) {
        out("你身上带着：\n" + ex);
    } else {
        out("你身上什么也没有。\n");
    }
    return;
}
