/*
    Detect hidden exit skill
    - Verkho, Feb '96
*/

int detect_it(string str, object ob) {
  int i, COST;
  string last, *dirs, *exit_hid;

	if (!ob) ob = TP;
  COST = 4;
  exit_hid = ({ });
  dirs = environment(ob)->query_direc();

  if(str == "salidas") {
    if(ob->query_gp() < COST) {
      notify_fail("Prueba a descansar un poco antes.\n");
      return 0;
    }
    for(i = 0; i < sizeof(dirs); i++) {
      if(environment(ob)->query_ex_type(dirs[i]) == "hidden" ||
         environment(ob)->query_ex_type(dirs[i]) == "secret")
        exit_hid += ({ dirs[i] });
    }
    if(!sizeof(exit_hid)) {
      tell_object(ob, "No detectas ninguna salida oculta.\n");
      ob->adjust_gp(-COST);
      return 1;
    }
    if(sizeof(exit_hid) == 1) {
      tell_object(ob, "Encuentras una salida oculta en direccion "+ implode(exit_hid, " ") +
                  ".\n");
      ob->adjust_gp(-COST);
      return 1;
    }
    else {
      last = " y "+ exit_hid[sizeof(exit_hid) - 1]+ ".";
      exit_hid = delete(exit_hid, sizeof(exit_hid) - 1, 1);
      tell_object(ob, "Encuentras "+ query_num(sizeof(exit_hid) + 1, 0) +
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
         "Coste PGs: 4\n"
         "The detect skill utilizes the thief's abilities to detect any "
         "hidden exits, trails or otherwise disguised paths. Effectiveness "
         "is dependant upon the thief's wisdom and dexterity."
         "\n\nSintaxis: detectar salidas\n\n";
}
