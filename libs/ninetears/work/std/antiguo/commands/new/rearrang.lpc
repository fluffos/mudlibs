/* Hamlet Sept 1995 */
/* New stat ROLLING method.  Basically best 3 of 4d6.  Capability of
     subtraction from some of the stats.  Let's *hope* there's no need.
     Warns immortals if there seems to be a script in action.
*/

/* These will be the amount subtracted from stats.  I suggest these amounts
   if it actually proves necessary:  SUB2 = 0, SUB3 = 1, SUB4 = 1, SUB5 = 2,
   SUB6 = 2.  
*/
#define SUB2 0
#define SUB3 0
#define SUB4 0
#define SUB5 0
#define SUB6 0

string *thestats = ({ "str", "dex", "con", "int", "wis", "cha" });
int *statorder = ({ -1, -1, -1, -1, -1, -1 });
int *scores = ({ 0, 0, 0, 0, 0, 0 });
mixed deds = ({ ({ 0 }), ({ 1, 1 }), ({ 1, 1, 1 }), ({ 2, 1, 1 }),
                ({ 2, 2, 1 }), ({ 1, 1, 1, 1 }), ({ 2, 1, 1, 1 }),
                ({ 2, 2, 1, 1 }), ({ 2, 2, 2, 1 }), ({ 2, 2, 2, 2 }),
                ({ 2, 2, 2, 2, 1 }) });

int times;
int roll_status;
object myplayer;
int wecareat;
int beginroll;
string pname;

/* Prototypes :) */
void ordering(string order);
void confirm_order(string answer);
void do_the_roll();
void finish_rolling(string answer);
void confirm_exit(string answer);
void store_values();
void wipe_stuff();
void dest_me();
varargs void house_keeping(int log);
void warn_immorts(string person, int times, int began);
int *ssort(int *arry, int max);

/* The welcome message has played.  They've picked a race.  Whatever else
   should be told.  Now we introduce the stat rolling...
*/



int intro() {
  string racial_bonus;

  racial_bonus = sprintf("str: %2d  dex: %2d  con: %2d  int: %2d  "
                         "wis: %2d  cha: %2d",
                         this_player()->query_bonus_str(),
                         this_player()->query_bonus_dex(),
                         this_player()->query_bonus_con(),
                         this_player()->query_bonus_int(),
                         this_player()->query_bonus_wis(),
                         this_player()->query_bonus_cha());

  tell_object(this_player(),"Calandria Mud usa un metodo de rol "
              "para generar los atributos del player.\nEstos atributos "
              "son: STRengthi (fuerza), DEXterity (dextreza), CONstitution (constitucion) "
              ", INTelligence (Inteligencia), "
              "WISdom (sabiduria),\nand CHArisma (carisma).  La relevancia de "
              "cada atributo depende de que clase de player quieras.  "
              "Intentaremos ayudarte para que sepas lo que necesita tu jugador en "
              "un futuro,\nDebemos conocer como valoras tus atributos."
              "\n\nTus bonus raciales son:  "+racial_bonus+"\n\nPorfavor "
              "escribe el orden en el que tu valoras tus atributos(desde "
              "mas valor\na menos valor) ahora.\nEjemplo: str dex con "
              "int wis cha\nlos Scripts y otra forma de automatizacion estan "
              "estan estrictamente PROHIBIDOS en este proceso.\n"
              "Usa 'quit' para salir.\n\nOrden>  ");

  myplayer = this_player();
  pname = myplayer->query_cap_name();
  
  input_to("ordering",0);
  return 1;
}

/* We elicit their order of preference for the attributes. */
void ordering(string order) {
  string *stuff;
  int i;
  int *slots = ({ 0, 0, 0, 0, 0, 0 });
  string spew;

  if(!order || (order == "") || (order == 0)) {
    tell_object(this_player(),"Este orden no es valido.  Intenta algo "
                "como: str dex con int wis cha\n\nOrden>  ");

    input_to("ordering",0);
    return; 
  }

  if(lower_case(order) == "quit"[0..strlen(order)-1]) {
    tell_object(this_player(),"Ajustar cancelado.\n");
    wipe_stuff();
    return;
  }

  stuff = explode(order," ");

  if(sizeof(stuff) < 6) {
    tell_object(this_player(),"Debes poner los 6 atributos.\n");
    tell_object(this_player(),"Este orden no es valido.  Intenta algo "
                "como: str dex con int wis cha\n\nOrden>  ");

    input_to("ordering",0);
    return;
  }

  for(i=0;i<6;i++) {
    statorder[i] = member_array(lower_case(stuff[i]),thestats);
    if(statorder[i] == -1) {
      tell_object(this_player(),"Este orden no es valido.  Intenta algo "
                  "como: str dex con int wis cha\n\nOrden>  ");

      input_to("ordering",0);
      return;
    }
    slots[statorder[i]] = 1;
  }

  for(i=0;i<6;i++)
    if(!slots[i]) {
      tell_object(this_player(),"Debes incluir los 6 atributos.\n");
      tell_object(this_player(),"Este orden no es valido.  Intenta algo "
                  "como: str dex con int wis cha\n\nOrden>  ");

      input_to("ordering",0);
      return;
    }

  /* We now have their desired order stored in statorder. */

  spew = implode(({ thestats[statorder[0]], thestats[statorder[1]],
                    thestats[statorder[2]], thestats[statorder[3]],
                    thestats[statorder[4]], thestats[statorder[5]] }), " ");

  tell_object(this_player(),"Has seleccionado:  "+spew+"\n\nEs correcto? "
                            "(s / n (o q para salir))  ");

  this_player()->add_property("statorder",statorder);
  beginroll = (time() - this_player()->query_property("rolltime"));
  this_player()->add_property("beginroll", beginroll);
  input_to("confirm_order",0);
  return;
}

void confirm_order(string answer) {
  if(!answer || (answer == "")) {
    tell_object(this_player(),"Debes contestar s / n :  ");
    input_to("confirm_order",0);
    return;
  }

 if(lower_case(answer) == "quit"[0..strlen(answer)-1]) {
   tell_object(this_player(),"Ajustar cancelado.\n");
   wipe_stuff();
   return;
 }

 if(member_array(answer,({"s","S","si","n","N","no"})) == -1) {
   tell_object(this_player(),"Debes contestar s / n :  ");
   input_to("confirm_order",0);
   return;
 }

 if(member_array(answer,({"s","S","si"})) != -1) {
   tell_object(this_player(),"A continuacion saldran tiradas para tus "
               "atributos.  Puedes guardar las tiradas\no volver "
               "a tirarlas.  Puedes hacer tantas tiradas como quieras. Guardalas "
               "en la mente\nEste proceso sirve para que los jugadores "
               "que se encuentran mas nivelados\nen el MUD en cuanto a level "
               "se diferencien de otra forma.  Ya sabes los bonus raciales que te dan\n"
               "Estos bonus se anyaden al final, no estan incluidos en las tiradas.\n\n");

    roll_status = (int) this_player()->query_property("roll_status");
    do_the_roll();
    return;
  }
  else {
    tell_object(this_player(),"Intenta otra vez ...\n\nEscribe tu orden :  ");
    input_to("ordering",0);
    return;
  }
}

void do_the_roll() {
  int i,j;
  int *dice = ({ 0, 0, 0, 0 });
  int *tmpscores = ({ 0, 0, 0, 0, 0, 0 });

  tell_object(this_player(),"Lanzando dados ...\n\n");
  
  for(i=0;i<6;i++) {
    for(j=0;j<4;j++)
      dice[j] = random(6) + 1;
    dice = ssort(dice,4);
    tmpscores[i] = dice[0] + dice[1] + dice[2];
  }
  tmpscores = ssort(tmpscores,6);

  tmpscores[1] -= SUB2;  tmpscores[2] -= SUB3;
  tmpscores[3] -= SUB4;  tmpscores[4] -= SUB5;
  tmpscores[5] -= SUB6;

  if(roll_status)
    for(i=0;i<sizeof(deds[roll_status]);i++)
      tmpscores[5-i] -= deds[roll_status][i];

  if(this_player()->query_property("statorder"))
    statorder = this_player()->query_property("statorder");

  for(i=0;i<6;i++)
    scores[statorder[i]] = tmpscores[i];

  this_player()->add_property("scores",scores);

  tell_object(this_player(),"Your scores are:\n\t"+thestats[statorder[0]]+
              ": "+tmpscores[0]+"\t\t"+thestats[statorder[1]]+": "+
              tmpscores[1]+"\t\t"+thestats[statorder[2]]+": "+
              tmpscores[2]+"\n\t"+thestats[statorder[3]]+": "+
              tmpscores[3]+"\t\t"+thestats[statorder[4]]+": "+
              tmpscores[4]+"\t\t"+thestats[statorder[5]]+": "+
              tmpscores[5]+"\n\n");

  tell_object(this_player(),"Quieres guardar estas tiradas? (s o n "
              "(o q para salir)):  ");
  input_to("finish_rolling",0);
  return;
}

/* See if they want to keep it or reroll */
void finish_rolling(string answer) {

  if(!answer || (answer == "")) {
    tell_object(this_player(),"Contesta s o n :  ");
    input_to("finish_rolling",0);
    return;
  }

  times = this_player()->query_property("timesrolled");
  times++;

  if(lower_case(answer) == "quit"[0..strlen(answer)-1]) {
    tell_object(this_player(),"Ajustar cancelado.\n");
    this_player()->add_property("timesrolled",times);
    wipe_stuff();
    return;
  }

  if(member_array(answer,({"s","S","n","N","si","no"})) == -1) {
    tell_object(this_player(),"Contesta s o n :  ");
    input_to("finish_rolling",0);
    return;
  }

  this_player()->add_property("timesrolled",times);
  if(this_player()->query_property("beginroll"))
    this_player()->add_property("rolltime",(time() -
                        this_player()->query_property("beginroll")));

  if(times && ((times%100) == 0))
    house_keeping();

  if(member_array(answer,({"s","S","si"})) != -1) {
    tell_object(this_player(),"Estas seguro?  (s o n):   ");
    input_to("confirm_exit",0);
    return;
  }

  tell_object(this_player(),"Tiradas borradas.\n");
  do_the_roll();
  return;
}

void confirm_exit(string answer) {
  if(!answer || (answer == "")) {
    tell_object(this_player(),"Contesta s o n:  ");
    input_to("confirm_exit",0);
    return;
  }

  if((answer == "quit") || (answer == "q")) {
    tell_object(this_player(),"Ajustar cancelado.\n");
    wipe_stuff();
    return;
  }

  if(member_array(answer,({"s","S","si","n","N", "no"})) == -1) {
    tell_object(this_player(),"Contesta s o n :  ");
    input_to("confirm_exit",0);
    return;
  }

  if(member_array(answer,({"s","S","si"})) != -1) {
    tell_object(this_player(),"ENHORABUENA!  La generacion de atributos "
                "ha sido completada.\n");
    store_values();
    return;
  }
  /* Else */

  tell_object(this_player(),"Tiradas borradas.\n");
  do_the_roll();
  return;

}

/* Set the attributes and clean out some junk. */
void store_values() {
  mapping stats_prop;

  scores = this_player()->query_property("scores");

  log_file("stat.rolls",ctime(time())+": "+this_player()->query_cap_name()+
           " rolled "+times+" times, got: "+scores[0]+" "+scores[1]+" "+
           scores[2]+" "+scores[3]+" "+scores[4]+" "+scores[5]+".\n");

  this_player()->adjust_str(scores[0]-this_player()->query_real_str());
  this_player()->adjust_dex(scores[1]-this_player()->query_real_dex());
  this_player()->adjust_con(scores[2]-this_player()->query_real_con());
  this_player()->adjust_int(scores[3]-this_player()->query_real_int());
  this_player()->adjust_wis(scores[4]-this_player()->query_real_wis());
  this_player()->adjust_cha(scores[5]-this_player()->query_real_cha());

  this_player()->add_property("stats_rearranged",1);

  /* added by Raskolnikov to save original stats */
  stats_prop = ([
    "str": scores[0],
    "dex": scores[1],
    "con": scores[2],
    "int": scores[3],
    "wis": scores[4],
    "cha": scores[5],
  ]);
  this_player()->add_property("original_stats", stats_prop);

  wipe_stuff();
  house_keeping(1);

  this_player()->remove_property("rolltime");
  /* Changed the roller to a command, need to remove it for one time
   * rearrange. Baldrick, sept '95
   */
  this_player()->remove_known_command("ajustar");
  this_player()->save();
  return;
}

void wipe_stuff() {
  this_player()->remove_property("statorder");
  this_player()->remove_property("scores");
  if(this_player()->query_property("beginroll"))
    this_player()->add_property("rolltime",(time() -
                         this_player()->query_property("beginroll")));
  this_player()->remove_property("beginroll");
  house_keeping(1);
  call_out("dest_me",0);
  return;
}

void dest_me() {
  destruct(this_object());
  return;
}

void init_wecareat() {
  wecareat = 100;
  while(wecareat < times) 
    wecareat *= 2;
}

varargs void house_keeping(int logme) {
  int rollspersec;
  int duration;

  if(!wecareat) {
    if(times == 100)
      wecareat = 100;
    else
      init_wecareat();
  }
    
  duration = time() - beginroll;
  rollspersec = (times * 100) / duration;

  if(rollspersec > 90) {
    if( (times == wecareat) || (logme && (times >= 100)) ) {
      log_file("stat.rolls",pname+" rolled "+times+
               "x from "+ctime(beginroll)+
               "-"+ctime(time())+"\n");
      wecareat *= 2;
    }
    warn_immorts(pname,times,beginroll);
    if(roll_status < 10) {
      roll_status++;
      if(this_player())
        this_player()->add_property("roll_status",roll_status);
    }
  }
}

/* If it seems to be a script */
void warn_immorts(string person, int times, int began) {
  object *ppl = users();
  int i;
  int howlong = (time() - began) / 60;

  for(i=0;i<sizeof(ppl);i++)
    if(ppl[i]->query_lord() && ppl[i]->query_property("roller_inform"))
      tell_object(ppl[i],"Ghost [Info] WARNING!  "+person+" ha tirado "
                  "unas "+times+" veces en al menos "+howlong+
                  " minutos.\n");
  return;
}

void reset() {
  if(clonep(this_object()) && !myplayer) {
    house_keeping(1);
    dest_me();
  }
}

/* Selection sort, of course */
int *ssort(int *arry, int max) {   /* This is actually greatest first */
  int j,k;
  int least;
  int tmp;

  for(j=0;j<(max-1);j++) {
    least = j;
    for(k=j+1;k<max;k++)
    if( arry[k] > arry[least] )
      least = k;
    tmp = arry[j];
    arry[j] = arry[least];
    arry[least] = tmp;
  }

  return arry;
}
