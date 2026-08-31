

#include "/players/whisky/genesis/kfun/unique_string.lpc"

void my_look()
{
    string ret;
    object *inv;

    ret = environment()->long();
    inv = all_inventory(environment());

    if (sizeof(inv) > 0)
        ret = ret + implode(unique_string(inv,"short"),", ");
    tell_object(this_object(),ret+"\n");
}
    

    
