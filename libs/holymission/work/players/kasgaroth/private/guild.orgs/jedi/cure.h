cure(str) {
  int i,cost,a; 
  string what,how;
  
  if(!str) return ;

  if(str=="wounds" || (sscanf(str,"%s %s",how,what)==2 && what=="wounds")) {
    switch(how) {
      case "light"   : a=3*TP->query_maxhp()/10; break;
      case "serious" : a=5*TP->query_maxhp()/10; break;
      case "critical": a=9*TP->query_maxhp()/10; break;
      default        : if(str=="wounds") 
                         a=TP->query_sp()-20;
                       else
                         return;
    }	
    
    if(TP->query_hp()+a>TP->query_maxhp()) { 
      if(str!="wounds") {
        write("You don't have "+how+" wounds.\n");
        return 1;
      }
      a=TP->query_maxhp()-TP->query_sp()-20;
    }

    if(a>TP->query_sp()) {
      write("You don't have the mental energy to do that.\n");
      return 1;
    }

    if(a<=0) {
      write("You think that this was useless.\n");
      return 1;
    }
    write("You feel better now.\n");
    /* 050993 Galadriel: Patch to prevent hp bigger than maxhp */
    if(TP->query_hp()+a>TP->query_maxhp())
      a=TP->query_maxhp()-TP->query_hp();
    /* end patch */
    TP->reduce_hit_point(-a);
    spell_cost(a);
    return 1;
  }
  if (str=="poison" || str=="poisonness") {
    cost = TP->query_poisoned()*2+TP->query_intoxination()*2/3;
    if(!TP->query_poisoned() && !TP->query_intoxination()) {
      write("You are not poisoned or intoxicated.\n");
      return 1;
    }  
    if(TP->query_sp()<cost) {
      write("You lack the power to do that.\n");
      return 1;
    }
    write("You concentrate your Force.\n"+
          "You think your blood is boiling.\n");
    if(TP->query_hp()>10)
      TP->reduce_hit_point(10);
    TP->add_poison(-TP->query_poisoned());
    for (i=0;i<TP->query_intoxination();i++)
      TP->add_intoxination(-1);
    spell_cost(cost);
    return 1;
  }   
}
