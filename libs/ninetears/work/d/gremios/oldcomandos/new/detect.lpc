/*
    Detect hidden exit skill
    - Verkho, Feb '96
*/

int detect_it(string str, object ob) {
  int i, COST;
  string last, *dirs, *exit_hid;
  
  COST = 4;
  ob=TP; 
  exit_hid = ({ });
  dirs = environment(ob)->query_direc();
 
  if(!str)
    {  notify_fail("Detectar que?\n");
       return 0;
    }        

  if(str == "salidas") {
    if(ob->query_gp() < COST) {
      notify_fail("Estas demasiado cansado. Intenta descansar primero.\n");
      return 0;
    }
    for(i = 0; i < sizeof(dirs); i++) {
      if(environment(ob)->query_ex_type(dirs[i]) == "hidden" ||
         environment(ob)->query_ex_type(dirs[i]) == "secret")
        exit_hid += ({ dirs[i] });
    }
    if(!sizeof(exit_hid)) {
      tell_object(ob, "No detectas salidas ocultas aqui.\n");
      ob->adjust_gp(-COST);
      return 1;
    }
    if(sizeof(exit_hid) == 1) {
      tell_object(ob, "Detectas la salida oculta "+ implode(exit_hid, " ") +
                  ".\n");
      ob->adjust_gp(-COST);
      return 1;
    }
    else {
      last = " y "+ exit_hid[sizeof(exit_hid) - 1]+ ".";
      exit_hid = delete(exit_hid, sizeof(exit_hid) - 1, 1);
      tell_object(ob, "Detectas "+ query_num(sizeof(exit_hid) + 1, 0) +
                  " salidas ocultas: "+ implode(exit_hid,", ") + last +"\n");
      ob->adjust_gp(-COST);
      return 1;
    }
  }
  notify_fail("Uso: detectar salidas\n");
  return 0;
}

string help(string str) {
  return "Detectar:\n\n"
         "Coste en Pg: 4\n"
         "La habilidad de detectar utiliza las habilidades de un ladron para  "
         "detectar cualquier salida oculta, caminos escondidos y otras cosas. La "
         "efectividad depende de la sabiduria y la destreza del ladron."
         "\n\nSintaxis: detectar salidas\n\n";
}
