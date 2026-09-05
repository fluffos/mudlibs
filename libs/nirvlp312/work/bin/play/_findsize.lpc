int cmd_findsize() {
   int hf,pr,hi,we,sizew,sizeh,sizea;
   string ge;
   object plob;
   plob = this_player();
   hf=(int)plob->query_phys_at(1);
   hi=(int)plob->query_phys_at(2);
   we=(int)plob->query_phys_at(3);
   ge=(string)plob->query_gender();
   if((int)plob->query_pregnancy())
   pr=(int)plob->query_age()-(int)plob->query_pregnancy();
   if(ge == "male" || ge == "creature") {
     if(hf == 7) sizeh = 50;
     if(!sizeh && hf == 6 && hi > 6) sizeh = 45;
     if(!sizeh && hf == 6 && hi < 7) sizeh = 40;
     if(!sizeh && hf == 5 && hi > 6) sizeh = 30;
     if(!sizeh && hf == 5 && hi > 0) sizeh = 20;
     if(!sizeh) sizeh = 10;

     if(we > 300) sizew = 60;
     if(!sizew && we > 250) sizew = 55;
     if(!sizew && we > 230) sizew = 50;
     if(!sizew && we > 190) sizew = 40;
     if(!sizew && we > 150) sizew = 30;
     if(!sizew && we > 110) sizew = 20;
     if(!sizew) sizew = 10;
   }
   if(ge == "female") {
     if(hf > 6) sizeh = 50;
     if(!sizeh && hf == 5 && hi > 9) sizeh = 40;
     if(!sizeh && hf == 5 && hi > 2) sizeh = 30;
     if(!sizeh && hf == 5 && hi < 3) sizeh = 20;
     if(!sizeh) sizeh = 10;

     if(we > 300) sizew = 70;
     if(!sizew && we > 275) sizew = 60;
     if(!sizew && we > 250) sizew = 55;
     if(!sizew && we > 220) sizew = 52;
     if(!sizew && we > 200) sizew = 50;
     if(!sizew && we > 160) sizew = 40;
     if(!sizew && we > 130) sizew = 30;
     if(!sizew && we > 100) sizew = 20;
     if(!sizew) sizew = 10;
  }
   if(pr) {
    if(pr > 3000) sizew +=10;
    if(pr > 8100) sizew +=10;
    if(pr > 13000) sizew +=10;
   }
    sizea = (sizeh + 2*sizew)/3;
    if(sizea > 59) sizea = 6;
    if(sizea > 49) sizea = 5;
    if(sizea > 39) sizea = 4;
    if(sizea > 29) sizea = 3;
    if(sizea > 19) sizea = 2;
    if(sizea > 9) sizea = 1;
    if(sizea > 6) sizea = 1;

    write("You are size:");
    if(sizea == 1) write(" (XS)");
    if(sizea == 2) write(" (S)");
    if(sizea == 3) write(" (M)");
    if(sizea == 4) write(" (L)");
    if(sizea == 5) write(" (XL)");
    if(sizea > 5) write(" (XXL)");
    write("\n");
    return 1;
}
