
mapping arenas;
mapping watchers;

string *players;

void reset(int arg) {
  if(arg) return;
  arenas=([ ]);
  watchers=([ ]);
  players=({ });
}

void refresh() {
  object *k;
  int i,size;
  k=keys(arenas);
  for(i=0, size=sizeof(k); i < size; i++)
    destruct(k[i]);
  reset(0);
}  

void add_player(string str) {
  players+=({ str });
}

void remove_player(string str) {
  players-=({ str });
}

string *query_players() {
  return players;
}

int greater_fun(object ob1,object ob2) {
  int l1,l2;
  l1=(int)ob1->query_level();
  l2=(int)ob2->query_level();
  if(l1==l2)
    return (int)ob1->query_extra_level() < (int)ob2->query_extra_level();
  else
    return l1 < l2;
}

void shuffle_players(int arg) {
  string x;
  int i,r;
/* Sort by level/extra-level */
  if(arg==0)
    players=sort_array(players,"greater_fun",this_object());
  else if(arg==1) {
/* Take a card out at random and put it on the bottom of the deck. */
    for(i=sizeof(players); i > 0; i++) {
      r=random(sizeof(players));
      x=players[r];
      players-=({ players[r] });
      players+=({ x });
    }
  }
}

void add_fight(object arena,object kid) {
  if(member_array(arena,keys(arenas))==-1) {
    arenas+=([ arena : ({ kid }) ]);
    watchers[arena]=({ });
  }
  else
    arenas[arena]+=({ kid });
}

void remove_fight(object arena, object kid) {
  arenas[arena]-=({ kid });
}

object *list_arenas() {
  return keys(arenas);
}


/* Code for viewing */

void remove_watcher(object watcher) {
  object *ob;
  int i,size;
  for(i=0,ob=keys(watchers),size=sizeof(ob); i < size; i++)
    watchers[ob[i]]-=({ watcher });
}

void add_watcher(string str,object watcher) {
  object *ars;
  int x;
  if(sscanf(str,"%d",x)!=1) {
    write("Usage: watch #\n");
    return;
  }
  x--;   /* The who display adds 1, so we subtract 1 here. */
  ars=keys(arenas);
  if(x > sizeof(ars) || x < 0) {
    write("There are only "+sizeof(ars)+" arenas to watch.\n");
    return;
  }
  remove_watcher(watcher);
  watchers[ars[x]]+=({ watcher });
  write("You start watching the fight.\n");
}


/* 
   This is where input comes in from the arenas and is directed to the
   players in the stands who are watching it.
*/
void pipe_in(object arena,string msg) {
  object *peeps;
  int i,size;
  peeps=watchers[arena];
  for(i=0,size=sizeof(peeps); i < size; i++)
    tell_object(peeps[i],"#"+msg);
}

int cmd_who(string str) {
  object *ars;
  object *kids;
  object kid;
  int hp,sp;
  int i,j,size1,size2;
  if(str) {
    add_watcher(str,this_player());
    return 1;
  }
  ars=keys(arenas);
  if(sizeof(ars) <= 0) {
    write("There are currently no matches going on in the arena.\n");
    return 1;
  }
  for(i=0,size1=sizeof(arenas); i < size1; i++) {
    write("Arena #"+(i+1)+"\n");
    kids=arenas[ars[i]];
    for(j=0,size2=sizeof(kids); j < size2; j++) {
      /* Percent hps */
      hp=(int)kids[j]->query_hp();
      hp*=100;
      hp/=(int)kids[j]->query_mhp();

      /* Percent sps */
      sp=(int)kids[j]->query_sp();
      sp*=100;
      sp/=(int)kids[j]->query_msp();

      write("\t"+
            pad((string)kids[j]->query_name(),20)+
            pad(hp+"%",10)+
            pad(sp+"%",10)+
            "\n");
    }
  }
  return 1;
}
