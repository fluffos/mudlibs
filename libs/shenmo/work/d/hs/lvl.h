int exp_to_lvl(int exp)
{

                 if  ( exp>= 100      )           return 1;
                 if  ( exp>= 440      )           return 2;
                 if  ( exp>= 1080     )           return 3;
                 if  ( exp>= 2080     )           return 4;
                 if  ( exp>= 3500     )           return 5;
                 if  ( exp>= 5400     )           return 6;
                 if  ( exp>= 7840     )           return 7;
                 if  ( exp>= 10880    )           return 8;
                 if  ( exp>= 14580    )           return 9;
                 if  ( exp>= 19000    )           return 10;
                 if  ( exp>= 24200    )           return 11;
                 if  ( exp>= 30240    )           return 12;
                 if  ( exp>= 37180    )           return 13;
                 if  ( exp>= 45080    )           return 14;
                 if  ( exp>= 54000    )           return 15;
                 if  ( exp>= 64000    )           return 16;
                 if  ( exp>= 75140    )           return 17;
                 if  ( exp>= 87480    )           return 18;
                 if  ( exp>= 101080   )           return 19;
                 if  ( exp>= 116000   )           return 20;
                 if  ( exp>= 132300   )           return 21;                             
                 if  ( exp>= 150040   )           return 22; 
                 if  ( exp>= 169280   )           return 23;
                 if  ( exp>= 190080   )           return 24;
                 if  ( exp>= 212500   )           return 25;
                 if  ( exp>= 236600   )           return 26;
                 if  ( exp>= 262440   )           return 27;
                 if  ( exp>= 290080   )           return 28;
                 if  ( exp>= 319580   )           return 29;
                 if  ( exp>= 351000   )           return 30;
                 if  ( exp>= 384400   )           return 31;
                 if  ( exp>= 419840   )           return 32;
                 if  ( exp>= 457380   )           return 33;
                 if  ( exp>= 497080   )           return 34;
                 if  ( exp>= 539000   )           return 35;
                 if  ( exp>= 583200   )           return 36;
                 if  ( exp>= 629740   )           return 37;
                 if  ( exp>= 678680   )           return 38;
                 if  ( exp>= 730080   )           return 39;
                 if  ( exp>= 784000   )           return 40;
                 if  ( exp>= 840500   )           return 41;
                 if  ( exp>= 899640   )           return 42;
                 if  ( exp>= 961480   )           return 43;
                 if  ( exp>= 1026080  )           return 44;
                 if  ( exp>= 1093500  )           return 45;
                 if  ( exp>= 1163800  )           return 46;
                 if  ( exp>= 1237040  )           return 47;
                 if  ( exp>= 1313280  )           return 48;
                 if  ( exp>= 1392580  )           return 49;
                 if  ( exp>= 1475000  )           return 50;
                 if  ( exp>= 1560600  )           return 51;
                 if  ( exp>= 1649440  )           return 52;
                 if  ( exp>= 1741580  )           return 53;
                 if  ( exp>= 1837080  )           return 54;
                 if  ( exp>= 1936000  )           return 55;
                 if  ( exp>= 2038400  )           return 56;
                 if  ( exp>= 2144340  )           return 57;
                 if  ( exp>= 2253880  )           return 58;
                 if  ( exp>= 2367080  )           return 59;
                 if  ( exp>= 2484000  )           return 60;
                 if  ( exp>= 2604700  )           return 61;
                 if  ( exp>= 2729240  )           return 62;
                 if  ( exp>= 2857680  )           return 63;
                 if  ( exp>= 2990080  )           return 64;
                 if  ( exp>= 3126500  )           return 65;
                 if  ( exp>= 3267000  )           return 66;
                 if  ( exp>= 3411640  )           return 67;
                 if  ( exp>= 3560480  )           return 68;
                 if  ( exp>= 3713580  )           return 69;
                 if  ( exp>= 3871000  )           return 70;
                 if  ( exp>= 4032800  )           return 71;
                 if  ( exp>= 4199040  )           return 72;
                 if  ( exp>= 4369780  )           return 73;
                 if  ( exp>= 4545080  )           return 74;
                 if  ( exp>= 4725000  )           return 75;
                 if  ( exp>= 4909600  )           return 76;
                 if  ( exp>= 5098940  )           return 77;
                 if  ( exp>= 5293080  )           return 78;
                 if  ( exp>= 5492080  )           return 79;
                 if  ( exp>= 5696000  )           return 80;
                 if  ( exp>= 5904900  )           return 81;
                 if  ( exp>= 6118840  )           return 82;
                 if  ( exp>= 6337880  )           return 83;
                 if  ( exp>= 6562080  )           return 84;
                 if  ( exp>= 6791500  )           return 85;
                 if  ( exp>= 7026200  )           return 86;
                 if  ( exp>= 7266240  )           return 87;
                 if  ( exp>= 7511680  )           return 88;
                 if  ( exp>= 7762580  )           return 89;
                 if  ( exp>= 8019000  )           return 90;
                 if  ( exp>= 8281000  )           return 91;
                 if  ( exp>= 8548640  )           return 92;
                 if  ( exp>= 8821980  )           return 93;
                 if  ( exp>= 9101080  )           return 94;
                 if  ( exp>= 9386000  )           return 95;
                 if  ( exp>= 9676800  )           return 96;
                 if  ( exp>= 9973540  )           return 97;
                 if  ( exp>= 10276280 )           return 98;
                 if  ( exp>= 10585080 )           return 99;
                 if  ( exp>= 10900000 )           return 100;

}

int lvl_to_exp(int lvl)
{

                 if (lvl==1) return 100      ;       
                 if (lvl==2) return 440      ;       
                 if (lvl==3) return 1080     ;             
                 if (lvl==4) return 2080     ;             
                 if (lvl==5) return 3500     ;             
                 if (lvl==6) return 5400     ;             
                 if (lvl==7) return 7840     ;             
                 if (lvl==8) return 10880    ;             
                 if (lvl==9) return 14580    ;             
                 if (lvl==10) return 19000    ;             
                 if (lvl==11) return 24200    ;             
                 if (lvl==12) return 30240    ;             
                 if (lvl==13) return 37180    ;             
                 if (lvl==14) return 45080    ;             
                 if (lvl==15) return 54000    ;             
                 if (lvl==16) return 64000    ;             
                 if (lvl==17) return 75140    ;             
                 if (lvl==18) return 87480    ;             
                 if (lvl==19) return 101080   ;             
                 if (lvl==20) return 116000   ;             
                 if (lvl==21) return 132300   ;                                          
                 if (lvl==22) return 150040   ;              
                 if (lvl==23) return 169280   ;              
                 if (lvl==24) return 190080   ;              
                 if (lvl==25) return 212500   ;              
                 if (lvl==26) return 236600   ;              
                 if (lvl==27) return 262440   ;              
                 if (lvl==28) return 290080   ;              
                 if (lvl==29) return 319580   ;              
                 if (lvl==30) return 351000   ;              
                 if (lvl==31) return 384400   ;              
                 if (lvl==32) return 419840   ;              
                 if (lvl==33) return 457380   ;              
                 if (lvl==34) return 497080   ;              
                 if (lvl==35) return 539000   ;              
                 if (lvl==36) return 583200   ;              
                 if (lvl==37) return 629740   ;              
                 if (lvl==38) return 678680   ;              
                 if (lvl==39) return 730080   ;              
                 if (lvl==40) return 784000   ;              
                 if (lvl==41) return 840500   ;              
                 if (lvl==42) return 899640   ;              
                 if (lvl==43) return 961480   ;              
                 if (lvl==44) return 1026080  ;              
                 if (lvl==45) return 1093500  ;              
                 if (lvl==46) return 1163800  ;              
                 if (lvl==47) return 1237040  ;              
                 if (lvl==48) return 1313280  ;              
                 if (lvl==49) return 1392580  ;              
                 if (lvl==50) return 1475000  ;              
                 if (lvl==51) return 1560600  ;              
                 if (lvl==52) return 1649440  ;              
                 if (lvl==53) return 1741580  ;              
                 if (lvl==54) return 1837080  ;              
                 if (lvl==55) return 1936000  ;              
                 if (lvl==56) return 2038400  ;              
                 if (lvl==57) return 2144340  ;              
                 if (lvl==58) return 2253880  ;              
                 if (lvl==59) return 2367080  ;              
                 if (lvl==60) return 2484000  ;              
                 if (lvl==61) return 2604700  ;              
                 if (lvl==62) return 2729240  ;              
                 if (lvl==63) return 2857680  ;              
                 if (lvl==64) return 2990080  ;              
                 if (lvl==65) return 3126500  ;              
                 if (lvl==66) return 3267000  ;              
                 if (lvl==67) return 3411640  ;              
                 if (lvl==68) return 3560480  ;              
                 if (lvl==69) return 3713580  ;              
                 if (lvl==70) return 3871000  ;              
                 if (lvl==71) return 4032800  ;              
                 if (lvl==72) return 4199040  ;              
                 if (lvl==73) return 4369780  ;              
                 if (lvl==74) return 4545080  ;              
                 if (lvl==75) return 4725000  ;              
                 if (lvl==76) return 4909600  ;              
                 if (lvl==77) return 5098940  ;              
                 if (lvl==78) return 5293080  ;              
                 if (lvl==79) return 5492080  ;              
                 if (lvl==80) return 5696000  ;              
                 if (lvl==81) return 5904900  ;              
                 if (lvl==82) return 6118840  ;              
                 if (lvl==83) return 6337880  ;              
                 if (lvl==84) return 6562080  ;              
                 if (lvl==85) return 6791500  ;              
                 if (lvl==86) return 7026200  ;              
                 if (lvl==87) return 7266240  ;              
                 if (lvl==88) return 7511680  ;              
                 if (lvl==89) return 7762580  ;              
                 if (lvl==90) return 8019000  ;              
                 if (lvl==91) return 8281000  ;              
                 if (lvl==92) return 8548640  ;              
                 if (lvl==93) return 8821980  ;              
                 if (lvl==94) return 9101080  ;              
                 if (lvl==95) return 9386000  ;              
                 if (lvl==96) return 9676800  ;              
                 if (lvl==97) return 9973540  ;              
                 if (lvl==98) return 10276280 ;              
                 if (lvl==99) return 10585080 ;              
                 if (lvl==100) return 10900000 ;              

}


void fullup(object obj) {
  if (!obj) return;
  obj->set("kee",(int)obj->query("max_kee"));
  obj->set("eff_kee",(int)obj->query("max_kee"));
  obj->set("sen",(int)obj->query("max_sen"));
  obj->set("eff_sen",(int)obj->query("max_sen"));
  obj->set("force",(int)obj->query("max_force")*2);
  obj->set("mana",(int)obj->query("max_mana")*2);
  obj->set("food",(int)obj->max_food_capacity()*2);
  obj->set("water",(int)obj->max_water_capacity()*2);
}

int lvl_up(object ob)
{
    int i,lvl,j;
    i= exp_to_lvl(ob->query("combat_exp"));
    lvl= ob->query("lvl");

    if ( !environment(ob)->query("hs_world") ) return 0;
    
    j=0;

    if (i>lvl) {
                lvl++;j++;
                message_vision(BLINK+HIY" Level Up ！！\n"NOR,ob);
                message_vision(HIG"$N的等级提升了。\n"NOR,ob);
                tell_object(ob,HIC"您当前等级为 "HIW+lvl+HIC"级 ！\n"NOR,ob);
                fullup(ob);
                call_out("lvl_up",2,ob);
                }
    return j;
}





















