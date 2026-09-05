#include "/players/mizan/esc.h";

id(str)
{
   return str == "dye" || str =="paint" || str == "splotch"; 
}

short()
{
   return ESC + "[32m" + "A large green splotch on the ground" + ESC + "[0m"; 
}

long() 
{
   write("This a truly large splotch of powdered green dye that is all over\n"+
         "the ground in copious amounts. It appears to have come from a test\n"+
         "marking munition used by large guns and howitzers.\n");
}

reset()
{
    remove_call_out("erase_me");
    call_out("erase_me", 500);
}

erase_me()
{
    say("The green splotch fades away in the wind.\n");
    destruct(this_object());
    return 1;
}

get()
{
    return 0;
}