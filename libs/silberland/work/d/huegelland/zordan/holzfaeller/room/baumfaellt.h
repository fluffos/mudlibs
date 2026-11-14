
/*
   Routinen fuer das Baumfaellen der Holzfaeller
*/

int anzbaeume;

init() {
  ::init();
  if ((anzbaeume > 0) && (interactive(TP))) {
    anzbaeume--;
    if(find_call_out("baum_faellt") == -1) {
      call_out("baum_faellt",60+random(60));
    }
  }
}

reset() {
  ::reset();
  anzbaeume=3;
}

baum_faellt() {
  object *env;
  object ob;
  int playerin;
  int i;
  playerin=0;
  if ((present("\nholzfaeller")) && (!present("\nbaum"))) {
    env=all_inventory(TO);
    for( i=0 ; i<sizeof(env) ; i++ ) {
      if ( living(env[i]) && interactive(env[i])) { playerin=1; } }
    domainshout("Ein Holzfaeller ruft: \"Achtung, Baum faellt.\"\n", ROOM "*", 1);
    if (playerin) {
      tell_room(TO,
            "Der Holzfaeller gibt dem Baum den letzten Schlag.\n"
            "Kurz darauf ruft der Holzfaeller: \"Achtung, Baum faellt.\"\n"
            "Der Holzfaeller geht sofort in Deckung.\n" );
      call_out("baumfaellt1",2);
    } else {
      ob=CLONEOB( OBJ "baum" );
      ob->move(TO, M_NOCHECK);
    }
  }
}

baumfaellt1() {
  tell_room(TO,"Der Baum beginnt zu kippen.\n");
  call_out("baumfaellt2",2);
}

baumfaellt2() {
  tell_room(TO,"Bedrohlich kommt der Baum auf Dich zugerast.\n");
  call_out("baumfaellt3",2);
}

baumfaellt3() {
  tell_room(TO,"Der Baum erschlaegt Dich gleich. Besser Du rennst schnell weg !\n");
  call_out("baumfaellt4",3);
}

baumfaellt4() {
  object *env;
  object ob;
  string player;
  int i;
  env=all_inventory(TO);
  for( i=0 ; i<sizeof(env) ; i++ ) {
   if ( living(env[i]) && interactive(env[i])) {
    player=env[i]->Name(WER,0);
    switch(random(4)) {
     case 0: 
      tell_object(env[i],"Der Baum schlaegt neben Dir auf den Boden.\n");
      tell_room(ME,"Der Baum schlaegt neben "+player+" ein.\n", ({ env[i] }));
      break;
     case 1:
      tell_object(env[i],"Ein paar Aeste des Baumes erwischen Dich.\n");
      tell_room(ME,"Ein paar Aeste treffen "+player+".\n", ({ env[i] }));
      env[i]->reduce_hit_point(10+random(5));
      break;
     case 2:
      tell_object(env[i],"Ein dicker Stamm trifft Dich hart.\n");
      tell_room(ME,"Ein dicker Stamm trifft "+player+" hart.\n",({ env[i] }));
      env[i]->reduce_hit_point(20+random(15));
      break;
     case 3:
      tell_object(env[i],"Der Baum faellt genau auf Deinen Kopf.\n");
      tell_room(ME,"Der Baum faellt genau auf "+player+".\n",({ env[i] }));
      env[i]->do_damage(30+random(25));
      ob=CLONEOB( OBJ "bewusstlos" );
      ob->move(env[i], M_NOCHECK);
      break;
    }
   }
  }
  ob=CLONEOB(OBJ "baum");
  ob->move(TO, M_NOCHECK);
}
