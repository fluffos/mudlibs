string password, email;
nosave string tmp_password;
string real_name, birth_day, desc, where;
string titulo = "s";

void finger_commands() {
  add_action("chfn", "chfn");
  add_action("set_email","email");
  add_action("describe","describir");
  add_action("change_password","password");
  add_action("change_password","passwd");
} /* finger_commands() */


int finger(string str) {
  string ret, mud;

  if (!str) {
    object *obs;
    string type;
    int i;

    obs = users();

    write(sprintf("%-12.12s    %-20.20s %-20.20s %-20.20s\n",
                  "Nombre", "Real name", "Domicilio", "Cumpleanyos"));
    for (i=0;i<sizeof(obs);i++)
    {
      string euid;

      if (obs[i]->query_invis() && !this_object()->query_creator())
        continue;
      if ((int)obs[i]->query_invis() > 1 && !this_object()->query_god())
        continue;
      type = (obs[i]->query_earmuffs() ? "e" : " ");
      euid = geteuid(obs[i]);
      /* To get the G we had to use the line with query_god, but it gives an
      error if it's a player.. I just change the whole to query object
      type, Baldrick sept '93 */
      /*
      if(!environment(obs[i])) type += "X";
      else if (find_player(euid)->query_god()) type += "G";
      else if ("/secure/master"->high_programmer(euid)) type += "H";
      else if ("/secure/master"->query_lord(euid)) type += "D";
      else if (obs[i]->query_creator()) type += "P";
      else if (obs[i]->query_app_creator()) type += "A";
      else type += " ";
      */
      type = (obs[i]->query_object_type());
      printf("%-12.12s %2.2s %-20.20s %-20.20s %-20.20s\n",
      (obs[i]->query_invis()?"("+obs[i]->query_name()+")":(string)obs[i]->query_name()),
                    type,
                    ((ret = (string)obs[i]->query_real_name())?ret:"-"),
                    ((ret = (string)obs[i]->query_where())?ret:"-"),
                    ((ret = (string)obs[i]->query_birthday())?ret:"-"));
    }
    return 1;
  }

  str = (string)this_object()->expand_nickname(str);
  if(ret = (string)"/secure/finger"->finger_info(str)) {
    write(ret);
    return 1;
  } else if (this_object()->query_creator() &&
             sscanf(str, "%s@%s", mud, mud) == 2) {
    "/net/daemon/out_finger"->do_finger(str);
    write("Intermud finger on its way.\n");
    return 1;
  } else {
    notify_fail("Nadie con el nombre " + str + " ha visitado " +
      mud_name() + ".\n");
    return 0;
  }
} /* finger() */

nomask int set_email(string str) {
    if(str == ":") {
      if(email && (email[0..0] != ":"))
        email = ":"+email;
      write("Only immortals will be able to see your email address.\n");
       return 1;
    }
    if(this_object()->query_registrated()) {
      write("You are registered.  Have an immortal help you change "
            "your email address.\nIf you wish to change your email "
            "to be visible only to immorts, do: 'email :'\n");
      return 1;
    }
    if (!str) {
      write("You current email address is "+email+"\n");
      write("To clear use \"email CLEAR\"\n");
      write("For the email address to be only visible by lords prepend a :\n");
      write("eg email :name@server.school.unit\n");
      return 1;
    }
    if (str == "CLEAR")
      email = "";
    else
      email = str;
    if (email != "")
      write("Email address set to "+str+".\n");
    else
      write("Email address is null.\n");
    return 1;
} /* set_email() */

void set_desc(string str) { desc = str; }
string query_desc() { return desc; }

int describe(string arg) {
  if (!arg) {
    if(desc)
      notify_fail("Uso: describir <texto>\n"+
                  "     describir clear\n"+
                  "Tu descripcion : "+this_object()->query_cap_name()+" "+desc+"\n");
    else
      notify_fail("Uso: describir <texto>\n"+
                  "     describir clear\n"+
                 "No has puesto tu descripcion.\n");
    return 0;
  }
  if(arg == "clear") {
    desc = 0;
    write("Descripcion borrada.\n");
    return 1;
  }
  set_desc(arg);
  write("Ok.\n");
  return 1;
} /* describe() */

void set_password(string pass) {
  int i;
  if (sscanf(file_name(previous_object()), "/secure/login#%d", i))
    password = pass;
} /* set_password() */

int change_password2(mixed pass);

protected int change_password() {
  if (password) {
    write("Pon tu password antiguo: ");
    input_to("change_password2",1);
    return 1;
  }
  change_password2(0);
  return 1;
} /* change_password() */

protected int change_password2(mixed pass) {
  string str;
  if (password) {
    str = crypt(pass,password);
    if (str != password) {
      write("\nIncorrecto.\n");
      return 1;
    }
  }
  write("\nPon tu nuevo password : ");
  input_to("change_password3",1);
  return 1;
} /* change_password2() */

private string tmppassword;

protected int change_password3(string pass) {
  tmppassword = pass;
  write("\nOtra vez por favor : ");
  input_to("change_password4",1);
  return 1;
} /* change_password3() */

protected int change_password4(string pass) {
  if (tmppassword != pass) {
    write("\nIncorrecto.\n");
    return 1;
  }
  password = crypt(pass,password);
  write("\nOk.\n");
  return 1;
} /* change_password4() */
string query_birthday();

int chfn() {
  write("Cambiar informacion personal.\n");
  write("Si presionas enter en las preguntas se tomara la opcion por "+
	"defecto. La opcion por defecto esta encerrada en []'s.\n");
  
  if(this_object()->query_registrated()) {
    write("Domicilio (p.e. A Corunya, Valencia, ...) ["+where+"]\n"+
          "(ninguno para ninguno) : ");
    input_to("get_where");
    return 1;
  }

  write("Introduce tu nombre real ["+real_name+"] ? ");
  input_to("real_name");
  return 1;
} /* chfn() */

void mostrar_titulo(string str) {
  if(str == "n") {
	titulo = "n";
    write("Ocultando tu titulo.\n");
  }
  else if(str == "s") {
	titulo = "s";
    write("Mostrando tu titulo.\n");
  }
  else
    write("Estado de tu titulo no modificado.\n");
  return;
}

int real_name(string str) {
  if (str && str != "")
    if (str == "none" || str == "ninguno")
      real_name = 0;
    else
      real_name = str;
  if (real_name && real_name != "")
    write("Ok, tu nombre real es "+real_name+".\n");
  else
    write("Nombre real borrado.\n");
  write(
"Domicilio (p.e. A Corunya, Valencia, ...) ["+where+"]\n"+
"(ninguno para ninguno) : ");
  input_to("get_where");
  return 1;
} /* real_name() */

int get_where(string str) {
  if (str && str != "")
    if (str == "none" || str == "ninguno")
      where = 0;
    else
      where = str;
  if (where && where != "")
    write("Ok, tu domicilio es "+where+".\n");
  else
    write("Domicilio borrado.\n");
  write("Cumpleanyos (ddmm) ["+query_birthday()+
        "] (ninguno para ninguno) : ");
  input_to("birthday");
  return 1;
} /* get_where() */

string convert_birthday(string str) {
  /* we assume it is 4 characters long */

  int day, month, tot;
  string retval;

  sscanf(str, "%d", tot);
  day = tot / 100;
  month = tot % 100;
/*
  switch(day) {
    case 11:
      retval = "11th"; break;
    case 12:
      retval = "12th"; break;
    case 13:
      retval = "13th"; break;
    default:
      switch(day%10) {
        case 1:
          retval = day+"st"; break;
        case 2:
          retval = day+"nd"; break;
        case 3:
          retval = day+"rd"; break;
        default:
          retval = day+"th";
      }
  }*/
	retval = day + " de ";
  //retval += " of ";
  switch(month) {
    case 1:
      return retval + "Enero";
    case 2:
      return retval + "Febrero";
    case 3:
      return retval + "Marzo";
    case 4:
      return retval + "Abril";
    case 5:
      return retval + "Mayo";
    case 6:
      return retval + "Junio";
    case 7:
      return retval + "Julio";
    case 8:
      return retval + "Agosto";
    case 9:
      return retval + "Septiembre";
    case 10:
      return retval + "Octubre";
    case 11:
      return retval + "Noviembre";
    case 12:
      return retval + "Diciembre";
  }
  return retval;
} /* convert_birthday() */

int valid_birthday(string str) {
#define LENGTHS ({ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 })

  int tot, month, day;

  if(strlen(str) != 4) {
    return 0;
  }
  if(!sscanf(str, "%d", tot)) {
    return 0;
  }
  month = tot % 100;
  day = tot / 100;
  if(month > 12 || month < 1) {
    return 0;
  }
  if(day < 1) {
    return 0;
  }
  return day <= LENGTHS[month];
} /* valid_birthday() */

string query_birthday() {
  if(birth_day) {
    return birth_day;
  }
  return "Desconocido";
} /* query_birthday() */

int set_birthday(string str)
{ /* added so wizzes can set player's birthdays if they foul up */
  if(valid_birthday(str)) {
     birth_day = convert_birthday(str);
     this_object()->save_me();
     return 1;
  }
  return 0;
} /* set_birthday() */

void birthday(string str) {
  if (str == "") {
    if (birth_day)
      write("Cumpleanyos no modificado: "+query_birthday()+".\n");
    else
      write("Cumpleanyos dejado en blanco.\n");
  } else {
    if(query_birthday() != "Unknown") {
      write("No puedes cambiar donde naciste! Pregunta a un dios " +
        "para cambiarlo si te equivocaste.\n");
    } else if(!valid_birthday(str)) {
        write("Cumpleanyos invalido. Borrado.\n");
        birth_day = 0;
    } else {
      birth_day = convert_birthday(str);
      write("Cumpleanyos en " + query_birthday() + ".\n");
      this_object()->birthday_gifts();
    }
  }
  this_object()->save_me();
  if(!this_object()->query_registrated()) {
    write("Introduce tu direccion de correo electronico. 'ninguna' para "+
	"borrarla.\n");
    write("Poniendo ':' delante solo la podran ver los inmortales"+
          ".\n");
    write("["+email+"] : ");
    input_to("get_email");
  }
  else {
    write("Deseas que los demas jugadores vean tu direccion de email? "
          "(s o n) [s] : ");
    input_to("mod_email");
  }
} /* birthday() */

void get_email(string str) {
  if (str == "")
    if (!email || email == "")
      write("Direccion email en blanco.\n");
    else
      write("Direccion email dejada como "+email+".\n");
  else if (str == "ninguno" || str == "none" || str == "ninguna") {
    email = 0;
    write("Direccion de correo electronico borrada.\n");
  } else {
    email = str;
    write("Direccion email: "+email+".\n");
  }
	// mostrar titulo y tal
	write("Deseas mostrar tu titulo a los demas? (s o n)["+titulo+"] ");
	input_to("mostrar_titulo");

  this_object()->save_me();
} /* get_email() */

void mod_email(string str) {
  if(str == "")
    str = "s";
  if(str == "n") {
    if(email && (email[0..0] != ":"))
      email = ":" + email;
    write("Solo los inmortales podran ver tu email.\n");
  }
  else if(str == "s") {
    if(email && (email[0..0] == ":"))
      email = email[1..sizeof(email)-1];
    write("Los jugadores podran ver tu email.\n");
  }
  else
    write("Estado de tu direccion email no modificado.\n");
  if(this_object()->query_registrated()) {
        write("Deseas que otros jugadores vean tu nombre real? "
          "(s o n) [s] : ");
     input_to("mod_real_name");
  }
	else {
	// vaya paranoias
	// mostrar titulo y tal
	write("Deseas mostrar tu titulo a los demas? (s o n)["+titulo+"] ");
	input_to("mostrar_titulo");
	}

  return;
}

void mod_real_name(string str) {
  if(str == "")
    str = "s";
  if(str == "n") {
    if(real_name && (real_name[0..0] != ":"))
      real_name = ":" + real_name;
    write("Solo los inmortales podran ver tu nombre real.\n");
    return;
  }
  if(str == "s") {
    if(real_name && (real_name[0..0] == ":"))
      real_name = real_name[1..sizeof(email)-1];
    write("Los jugadores podran ver tu nombre real.\n");
    return;
  }

  write("Estado de tu nombre real no modificado.\n");
	// mostrar titulo y tal
	write("Deseas mostrar tu titulo a los demas? (s o n)["+titulo+"] ");
	input_to("mostrar_titulo");
  return;
}

int query_is_birthday_today() {
    string cmonth, dummy, bmonth;
    int cdate, bdate;

    if(sscanf(ctime(time()), "%s %s %d %s", dummy, cmonth, cdate, dummy)!=4)
        return 0; /* error in date */
    //if(sscanf(query_birthday(), "%d%s de %s", bdate, dummy, bmonth) !=3)
    if(sscanf(query_birthday(), "%d de %s", bdate, bmonth) !=2)
        return 0; /* no bday set */
    if(cmonth == bmonth[0..2] && cdate == bdate)
        return 1;
} /* query_is_birthday_today() */

string query_real_name() { return real_name; }
string query_where() { return where; }
int query_show_title() { return (titulo == "s") ? 1:0; }
