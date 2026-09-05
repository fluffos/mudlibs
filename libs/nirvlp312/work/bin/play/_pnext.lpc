int
cmd_pnext()
{
    int     x,y,z;
    int     cost, need;

    x = 100000000 - (int)this_player()->query_exp();    
    y = (int)this_player()->query_prestige_level();
    z = (int)this_player()->query_bank_balance();

    if(y == 0) cost = 1000000;
    if(y > 0) cost = ((y * 100000) + 1000000);

    need = cost - z;
     
    if(x < 1 && need < 1)
     return (write("You have enough experience and gold for your next Prestige Level.\n"), 1);

    if(x < 1 && need > 0)
     return (write("You have enough experience but still need "+ comma_number ( need ) +" coins for your next Prestige Level.\n"), 1);
  
    if(x > -1 && need < 1)
     return (write("You have enough gold but still need "+ comma_number( x ) +" experience for your next Prestige Level.\n"), 1);

    write("You need "+ comma_number( x ) +" experience and "+ comma_number ( need ) +" gold for your next Prestige Level.\n");
    return 1;
}
