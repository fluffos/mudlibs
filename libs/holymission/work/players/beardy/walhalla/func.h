/* return "no_player" if FILE is empty */

int check_player()
{ object *all, test;
  int i;

  test=clone_object("/obj/treasure");
  test->set_name("test_for_empty");
  transfer(test,this_object());
  all=all_inventory(environment(test));
  for(i=0;i<sizeof(all);i++)  
     if ( living(all[i]) && all[i]->query_npc()==0 ){
        destruct(test);
        return 1;
     }

  destruct(test);

  return  0;
}

/* transfer all players in a room to dest */

int trans_all_room(mixed dummy, object dummy2)
{ object *all, test;
  int i,flag;

  if(!dummy) return 0;
  if(!dummy2) return 0;

  flag=0;
  test=clone_object("/obj/treasure");
  test->set_name("test_for_empty");
  transfer(test,dummy);
  all=all_inventory(environment(test));
  for(i=0;i<sizeof(all);i++)  
     if ( living(all[i]) && all[i]->query_npc()==0 )
     { transfer(all[i],dummy2);
       flag=1;
     }

  destruct(test);

  if(flag==0) return 0;
  else return 1;
}
