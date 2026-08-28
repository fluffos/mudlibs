object animal,tamer, tamer_ob;
int time,follow,st;
void reset() {
        enable_commands();
}
start(object ani, object tam) {
  animal = ani;
  tamer = tam;
  follow = 0;
  time = (tamer->query_skills("control animal") * 18 + 120);
  tamer_ob = clone_object("/guilds/skill_obj/tamer_ob");
  move_object(tamer_ob, this_player());
  shadow(animal, 1);
  call_out("move_check",4);
}

query_animal_shadow() { return this_object(); }
query_animal_ob() { return this_object(); }

add_exp(arg) {
  tamer->add_exp(arg);
  return 1;
}
death(arg) {
        destruct(this_object());
        if(tamer_ob) {
                destruct(tamer_ob);
        }
}
query_follow() { return follow; }
query_tamer() { return tamer; }

catch_tell(str) {
        string order,target,master,dir,tmp;
        if(sscanf(str, "%s says 'follow'", master) == 1) {
                if(!master == tamer->query_name()) { return 1; }
                        follow = 1;
                        write(animal->short()+" looks deeply in your eyes and starts walking circles around you.\n");
                return 1;
                }
        if(sscanf(str, "%s says 'stay'", master) == 1) {
                if(!master == tamer->query_name()) { return 1; }
                        write(animal->short()+" looks at you with confused manner and lays down.\n");
                        follow = 0;
                return 1;
        }
        if(sscanf(str, "%s says 'attack %s'", master, target) == 2) {
          if(!master == tamer->query_name()) { return 1; }
          target = present(lower_case(target),environment(animal));
          //Animal can't attack players -- Rag 2.11.04
          if(!target || !living(target) || !target->query_npc() ) { return; }
          if(environment(animal)->query_property("no_kill")) { return 1; }
          animal->attack_object(target);
          return 1;
        }
}
move_check() {
               if(tamer->query_ghost()) {
               move_object(animal, "/world/special/dump");
               tell_object(tamer, (animal->short()+" leaves back into the wilderness.\n"));
                say(animal->short()+" leaves back into the wilderness.\n");
               destruct(animal);

                if(tamer_ob) {
                destruct(tamer_ob);
 }
                 return;
                }
        if(!present(tamer,environment(animal)) && follow ==1) {
                tell_room(environment(animal), animal->short()+" follows its tamer.\n");
                move_object(animal,environment(tamer));
                tell_room(environment(animal), animal->short()+" arrives.\n");
}
call_out("move_check",5);
}
