discord(str) {
  object all;
  int i,percentage,w,cost,count;
 
  all=all_inventory(environment(TP));
  cost=TPL*3;
 
  if(TP->query_spell_points()<cost) {
    write("You lack the mental energy to suggest anything.\n");
    return 1;
  }
 
  spell_cost(cost);
 
  count=0;
  all=all_inventory(environment(TP));
 
  for(i=0;i<sizeof(all);i++) {
    if(all[i]->short() && all[i]->query_attack()==TP) {
 
      w=random(sizeof(all));
      while ((all[w]==TP && !random(3)) || (w==i) || (!living(all[w])))
	w=random(sizeof(all));
 
      count++;
      all[i]->attack_object(all[w]);
    }
  }
  if(!count)
    write("Everybody here seems to do somethings else.\n");
  else
    write("You have sown the seeds of discord between your opponents.\n");
 
  return 1;
 
}
