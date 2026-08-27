/* Hamlet August 1995.  Room where sacrifices occur. */
/* Generic.  shouldn't be cloned directly. */
inherit "/std/room";
#define GOD_HAND "/obj/handlers/god_handler"
#define OBJS "/baseobs/misc/"
#define ART_PATH "/baseobs/misc/gods/"

string mydeity = "nobody";               
object altar;
object bust;
int artifact_dispatched = 0;

int set_god_here(string which) { 
  mydeity = lower_case(which); 
  if(GOD_HAND->is_deity(which)) {
    altar = clone_object(OBJS+"altar");
    altar->set_long(GOD_HAND->altar_long(which));
    altar->move(this_object());
    if(GOD_HAND->query_high_priest(which)) {
      bust = clone_object(OBJS+"bust");
      bust->subject(GOD_HAND->query_high_priest(which)[0],
                    GOD_HAND->query_high_priest(which)[3],mydeity);
      bust->move(this_object());
    }
  }
}

void setup()
{
  set_short("Sala de Sacrificios de "+mydeity);
  set_long("Me gustaria que me cambiaran, plis.\n");
  set_light(60);
  add_property("no_clean_up",1);
}

void init() {
  add_action("worship","worship");
  add_action("worship","adorar");
  add_action("sacrifice","sacrifice");
  add_action("sacrifice","sacrificar");
  add_action("bless_me","bless");
  add_action("bless_me","bendecir");
	add_action("renegar", "renegar");
  ::init();
}

void dest_me() {
  if(altar)
    altar->dest_me();
  if(bust)
    bust->dest_me();
}

int begin_worship(string rabbit);

int worship(string who) {
  string himher;

	if (!TP->query_alive()) {
		notify_fail("Tal vez parezca extranyo, pero los fantasmas no adoran a nadie.\n");
		return 0;
	}
  
  if(GOD_HAND->deity_gender(mydeity) == 1)
    himher = "him";
  else if(GOD_HAND->deity_gender(mydeity) == 2)
    himher = "her";
  else
    himher = "it";

  if( !who || (lower_case(who) != mydeity) ) {
	/* by Unleashed - a falta de poner variables tipo himher para sexo */
	if (GOD_HAND->deity_gender(mydeity) == 1)
    		tell_object(this_player(),capitalize(mydeity)+" estaria considerablemente "
                	"mas impresionado si fuera el unico adorado aqui.\n");
	else
    		tell_object(this_player(),capitalize(mydeity)+" estaria considerablemente "
                	"mas impresionada si fuera la unica adorada aqui.\n");
    return 1;
  }
  
  if( this_player()->query_deity() == mydeity ) {
    tell_object(this_player(),"Te lanzas al suelo y dedicas tu vida a "
                "servir a "+capitalize(mydeity)+".\n");
    tell_room(environment(this_player()),this_player()->query_cap_name()+
              " se arrodilla ante el altar.\n",
              ({this_player()}));
    //TIMION
      this_player()->add_known_command("rezar");
    return 1;
  }
  
  if( this_player()->query_deity() && 
      (capitalize(this_player()->query_deity()) != "Ninguna") ) {
    tell_object(this_player(),capitalize(this_player()->query_deity())+
                " no parece estar impresionado contigo.\n");
  }
  
  if(!(GOD_HAND->race_can_worship(mydeity,this_player()->query_race()))) {
    tell_object(this_player(),capitalize(mydeity)+" no acepta a los tuyos "
                "como seguidores.\n");
    return 1;
  }
  
  tell_object(this_player(),"Estas seguro de que deseas adorar a "+
              capitalize(mydeity)+"?  ");
  input_to("begin_worship",0);
  return 1;
}

int begin_worship(string rabbit) {
  if(!rabbit || rabbit == "") {
    tell_object(this_player(),"Si o no?:  ");
    input_to("begin_worship",0);
    return 1;
  }  
  
  if( (lower_case(rabbit) == "si") || (lower_case(rabbit) == "s") ) {
    if( this_player()->query_deity() && 
        (capitalize(this_player()->query_deity()) != "Ninguna") ) {
      tell_object(this_player(),"Un trueno te sobrecoge mientras una luz "
                                "cegadora desciende desde el cielo, dejandote inconsciente. "
                                "Cuando tu mente vuelve de su viaje, "
                                "un fuerte dolor de cabeza te atormenta "
                                "haciendote sentir extremamente culpable.\n");
      tell_room(environment(this_player()), "Una luz divina cubre a "
		+this_player()->query_cap_name()+" por completo.\n",
                ({this_player()}));
      this_player()->add_property("SWITCHED_DEITIES",time());
	this_player()->remove_property(TP->query_deity()+"_sagrado");
      GOD_HAND->remove_sacrifices(this_player());
      this_player()->set_xp(0);
      this_player()->clear_deity();
    }
    tell_object(this_player(),"Tu adoracion a "+capitalize(mydeity)+
                " ha comenzado.\n");
    tell_room(environment(this_player()),this_player()->query_cap_name()+
              " se arrodilla ante el altar.\n",
              ({this_player()}));
    this_player()->set_deity(mydeity);
   //TIMION
    this_player()->add_known_command("rezar");
  }
  else {
    tell_object(this_player(),"Ok. Tal vez a "+capitalize(mydeity)+" no "
                "le importes mucho en realidad.\n");
    tell_room(environment(this_player()),this_player()->query_cap_name()+
              " parece tener dudas existenciales.\n",
              ({this_player()}));
  }

  return 1;
}

nomask int not_in_use(object ob) { return ob && !ob->query_in_use() &&
                                          !ob->query_property("cursed"); }

int renegar(string que) {
	if (!TP->query_alive()) {
		notify_fail("Tal vez parezca extranyo, pero los fantasmas no adoran a nadie.\n");
		return 0;
	}
	if(TP->query_deity() != mydeity) {
		notify_fail("Renegar de un dios que no adoras?\n");
		return 0;
	}
    if( this_player()->query_deity() && 
        (capitalize(this_player()->query_deity()) != "Ninguna") ) {
      tell_object(this_player(),"Un trueno te sobrecoge mientras una luz "
                                "cegadora desciende desde el cielo, dejandote inconsciente. "
                                "Cuando tu mente vuelve de su viaje, "
                                "un fuerte dolor de cabeza te atormenta "
                                "haciendote sentir extremamente culpable.\n");
      tell_room(environment(this_player()), "Una luz divina cubre a "
		+this_player()->query_cap_name()+" por completo.\n",
                ({this_player()}));
      this_player()->add_property("SWITCHED_DEITIES",time());
	this_player()->remove_property(TP->query_deity()+"_sagrado");
      GOD_HAND->remove_sacrifices(this_player());
      this_player()->set_xp(0);
      this_player()->clear_deity();
    }
    tell_object(this_player(),"Tu adoracion a "+capitalize(mydeity)+
                " ha finalizado.\n");
    tell_room(environment(this_player()),this_player()->query_cap_name()+
              " se retira de la adoracion a "+capitalize(mydeity)+".\n",
              ({this_player()}));
    this_player()->set_deity("ninguna");
   //TIMION
    this_player()->remove_known_command("rezar");
	return 1;
}

int sacrifice(string what) {
	object estatua;
  string *stuff;
  int i;
  int XP = 0;
  int amt;
  int credits;
  string pr;
  
  if( !what || (what == "items") ) {
    if(!sizeof(all_inventory(altar))) {
      tell_object(this_player(),"Sacrificar que?\n");
      return 1;
    }
    /* else */
    what = "trees";
  }
  
  stuff = explode(what," ");
   
  for(i=0;i<sizeof(stuff);i++)
    if( (lower_case(stuff[i]) == "experiencia") || 
        (lower_case(stuff[i]) == "xp") || (lower_case(stuff[i]) == "exp") ) {
      XP = 1;
      break;
    }
    
  if(XP) {
    if(i>0) {
      sscanf(stuff[i-1],"%d",amt);
      if(amt < 0)  amt = -amt;
      if(amt > this_player()->query_xp())
        amt = this_player()->query_xp();
      if(amt < 0)
        amt = 0;
      tell_object(this_player(),"Estas sacrificando "+amt+" puntos de experiencia a tu dios.\n");
      
      credits = GOD_HAND->sacrifice_xp(this_player(),amt,mydeity);
    }
    else {
      tell_object(this_player(),"Cuanta experiencia?\n");
      return 1;
    }
  }
  else {
    if(what != "trees")
    {
      object at = present("altar",this_object());
      if(at)
        filter(find_match(what,this_player()),"not_in_use",this_object())->
          move(at);
    }
    credits = GOD_HAND->sacrifice_all_items(this_player(),altar,mydeity);
  }
    
    if(!credits) 
      tell_object(this_player(),"Sientes la indiferencia de "+capitalize(mydeity)+
                                " por tu sacrificio.\n");
    else
      tell_object(this_player(),"Notas el agradecimiento de "+capitalize(mydeity)+
                                " por tu sacrificio.\n");
  
  if(GOD_HAND->query_high_priest(mydeity) &&
     (GOD_HAND->query_high_priest(mydeity)[0] == this_player()->query_name()))
  {
    if(GOD_HAND->query_high_priest(mydeity)[3] == 2)
      pr = "Alta Sacerdotisa";
    else
      pr = "Alto Sacerdote";
      
    tell_object(this_player(), capitalize(mydeity) + " te dice: Saludos, mi "+pr+
                              "! Puedes pedirme un objeto especial con "
                              "'bendecir'.\n");
	// CHECK para ver si estamos CAMBIANDO de SUMO
	// y de paso cambiar la estatua :P
	if (!(estatua = find_match("estatua sagrada", TO)) ||
	estatua->query_who() != TP->query_name()) {
		if (estatua)
			estatua->dest_me();
		estatua = clone_object("/baseobs/misc/bust");
		estatua->subject(TP->query_name(), TP->query_gender());
		estatua->move(TO);
		tell_room(TO, "De pronto "+capitalize(mydeity)+" aparece "
		"en el plano terrenal para labrar una nueva estatua en "
		"el templo, desapareciendo con celeridad.\n");
	}
  }
  return 1;
}

int bless_me(string arg) {
  
	if (!TP->query_alive()) {
		notify_fail("Tal vez parezca extranyo, pero los fantasmas no adoran a nadie.\n");
		return 0;
	}

  notify_fail("El Alto Sacerdote puede pedir un objeto especial con 'bendecir'.\n");
  /*if(!arg || (arg != "me")) - No sirve pa na en espaniol
    return 0;*/
    
  if(this_player()->query_deity() != mydeity) {
    tell_object(this_player(),"Tu no adoras a "+capitalize(mydeity)+"!\n");
    return 1;
  }
  
  if(!GOD_HAND->query_high_priest(mydeity)) {
    tell_object(this_player(),capitalize(mydeity)+" no te considera "
                "suficientemente valioso.\n");
    return 1;
  }

  if(GOD_HAND->query_high_priest(mydeity) &&
    (GOD_HAND->query_high_priest(mydeity)[0] != this_player()->query_name())) {
    tell_object(this_player(),capitalize(mydeity)+" no te considera "
                "suficientemente valioso.\n");
    return 1;
  }
  
//  if(artifact_dispatched) {
  if(TP->query_property(mydeity+"_sagrado")) {
    tell_object(this_player(),"Ya existe un objeto sagrado de " + capitalize(mydeity) +
                              "!\n");
    return 1;
  }
/* una vez destruido el objeto sigue entrando aki!
	if (find_object(ART_PATH+mydeity)) {
		tell_object(this_player(), capitalize(mydeity) + " te dice: "
		"Mi objeto sagrado esta en manos de mi anterior devoto supremo, "
		"hasta que la llama de su vida no se apague el objeto no "
		"podra ser tuyo.\n");
		return 1;
	}
*/
  clone_object(ART_PATH+mydeity)->move(this_player());
  
  /*if(GOD_HAND->query_high_priest(mydeity)[3] == 2)
    pr = "Alta Sacerdotisa";
  else
    pr = "Alto Sacerdote";*/
    
  tell_object(this_player(),capitalize(mydeity)+" te honra con un regalo especial!\n");
  tell_room(environment(this_player()),"De repente el aire parece cargado. "
            "Sientes la presencia divina de "+capitalize(mydeity)+" en todo el templo.\n",
            ({this_player()}));
  //artifact_dispatched = 1;
	TP->add_property(mydeity+"_sagrado", 1);
  return 1;
}
