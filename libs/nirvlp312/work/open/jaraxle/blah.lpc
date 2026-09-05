jealous_check(ob){
  if(masterob){ 
    if( ob && ( (ob->query_master() == masterob) || (ob->query_owner() ==
masterob) ) ){
      if(random(3)==1){
        say(BOLD+cap_name+" flies into a jealous rage.\n"+OFF);
        this_object()->attack_object(ob);

