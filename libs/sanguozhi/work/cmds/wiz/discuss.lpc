// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

inherit CMD;


private void main(mixed *arg)
{
    if(userp(arg[0]) || member_array(arg[0],bodies()) != -1)
    {
        out("你不能 discuss 一个用户，只能是一个物件。\n");
        return;
    }
    new(ANNO_MENU, arg[0])->start_menu();
}
