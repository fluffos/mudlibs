  if (pregnancy && myidletime < 2100) {
/* hard coded number because separating broke it. -Bp was:
   if (pregnancy && myidletime < idletime+300) {
*/
    int pregtmp;
    pregtmp = age - pregnancy;
    if(pregtmp == 2000) add_phys_at(3,5+random(kc()));
    if(pregtmp == 3000) add_phys_at(3,random(5)+random(kc()));
    if(pregtmp == 4000) add_phys_at(3,2+random(4)+random(kc()));
    if(pregtmp == 6000) add_phys_at(3,2 + random(4)+random(kc()));
    if(pregtmp == 8000) add_phys_at(3,2+random(4)+random(kc()));
    if(pregtmp == 10000) add_phys_at(3,1+random(10)+random(kc()));
    if(pregtmp == 12000) add_phys_at(3,3 +random(8)+random(kc()));
    if(pregtmp == 14000) add_phys_at(3,2+random(8)+random(kc()));
    if(pregtmp == 15500) add_phys_at(3,1+random(8)+random(kc()));
    if(pregtmp == 16500) add_phys_at(3,1+random(8)+random(kc()));
    if(pregtmp == 17500) add_phys_at(3,1+random(8)+random(kc()));
    if(pregtmp == 18500) add_phys_at(3,1+random(8)+random(kc()));
    if(pregtmp < 3000 && pregtmp > 500) {
      if(random(4000) < 3 || phys_at[4]==4001) { 
        write("You feel sick, like you are going to puke.\n");
        if(phys_at[4] > 4000) phys_at[4]=0;
        add_phys_at(3,-random(3));
        if(random(100) < 10) {
          write("You bend over and puke.\n");
          say(cap_name+" doubles over and pukes.\n");
        }
      }
      if(random(5000) < 3) {
        write("You feel a strange hunger for food.\n");
      }
    }
    if(pregtmp > 1000 && pregtmp < 18000) {
      object bbb;
       if(random(9000) < 3 || phys_at[4]==4004) {
       int rrx;
       rrx = random(3);
       if(phys_at[4] > 4000) phys_at[4]=0;
       if(rrx == 0)
         tell_object(this_object(),"You have a strange craving for peanut butter and hotdog sandwiches.\n");
       if(rrx == 1)
         tell_object(this_object(),"You have a strange craving for pickles and ice cream.\n");
       if(rrx == 2)
        tell_object(this_object(),"Your feet feel swollen.\n");
     }
      if(random(8200) < 2 || phys_at[4]==4002) {
        tell_object(this_object(),"Your breasts feel heavier and"+
          " larger.\n");
        if(phys_at[4] > 4000) phys_at[4]=0;
        say(cap_name+" wiggles uncomfortably as though her top is"+
          " too tight.\n");
        bbb=present("boobs",this_object()); 
        if(bbb) {
          bbb->add_cup(1);
          bbb->add_bust(1);
        }
      }
    }
    if(pregtmp > 12000) {
      if(random(25000) < 40 || phys_at[4]==4003) {
        if(phys_at[4] > 4000) phys_at[4]=0;
         tell_object(this_object(),"You feel the baby kick inside you.\n");
         say(cap_name+" jumps up as though something startled her.\n");
      }
    }
    if(pregtmp > 11000) {
      if(random(29000) < 40 || phys_at[4]==4004) {
        if(phys_at[4] > 4000) phys_at[4]=0;
        tell_object(this_object(),"You suddenly need to pee...really, really bad.\n");
      }
    }
    if(pregtmp > 15840) {
      if(random(1000) < 20)
        tell_object(this_object(),"You feel labor pains.\n");
    }
    if(pregtmp > 16200+random(500)) 
      if(random(900000) < pregtmp && phys_at[4]!=5001) 
      child_birth();
  }
