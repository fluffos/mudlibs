if ( djj > 1 ) {
if ( djj == 2 ) vic_exp=(int)victim->query("combat_exp")/500+20000; 
if ( djj == 3 ) vic_exp=(int)victim->query("combat_exp")/500+60000; 
if ( djj == 4 ) vic_exp=(int)victim->query("combat_exp")/500+120000; 
if ( djj == 5 ) vic_exp=(int)victim->query("combat_exp")/500+200000; 
if ( djj == 6 ) vic_exp=(int)victim->query("combat_exp")/500+300000; 
if ( djj == 7 ) vic_exp=(int)victim->query("combat_exp")/500+420000; 
if ( djj == 8 ) vic_exp=(int)victim->query("combat_exp")/500+560000;
if ( djj == 9 ) vic_exp=(int)victim->query("combat_exp")/500+720000;
if ( djj ==10 ) vic_exp=(int)victim->query("combat_exp")/500+900000;
if ( djj > 10 && victim->query("combat_exp")>500) 
vic_exp=((int)victim->query("combat_exp")/500)+(900000+((djj-10)*200000));
}
else {
if ( victim->query("combat_exp")>500 )
     vic_exp=(int)victim->query("combat_exp")/500;
else
vic_exp=(int)victim->query("combat_exp");
}


