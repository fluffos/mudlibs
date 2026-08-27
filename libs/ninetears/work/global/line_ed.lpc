#include "ed.h"
/*
 * Expansion of the editor.  We will now allow the player to use any
 * or three different editors.  One of them is the default (the old
 * one) one of them is ed and the other I am going to write in a
 * few secs....
 *
 * cute line editor thing.  Which even a player could use!
 */

nosave string *lines, end_func;
nosave object end_object;
nosave int insertion_point;
string editor; /* The editor to use... */

void main_bit(string str);
void editor_do_quit(string str);

void create() {
  editor = "menu";
} /* create() */

void editor_commands() {
  add_action("set_editor", "editor");
} /* edito_commands() */

int do_edit(string str, string end_f, object end_o) {

  if (!end_f) {
    write("Someone has stuffed up.\n");
    return 0;
  }
  end_func = end_f;
  if (!end_o)
    end_object = previous_object();
  else
    end_object = end_o;
  if (!str)
    str = "";
    if (!stringp(editor)) editor="menu";
  switch (editor) {
    case "menu" :
      lines = explode(str, "\n") - ({ 0 });
      write("Ok, puedes escribir. Escribe unicamente ** en una linea para terminar.\n");
      insertion_point = sizeof(lines);
      printf("%-2d] ", insertion_point+1);
      input_to("editor_loop");
      return 1;
    case "ed" :
      if (stringp(str) && str != "")
        write_file(TMP_FILE, str);
      ed(TMP_FILE, "editor_finish_ed");
      return 1;
    case "command" :
      lines = explode(str, "\n") - ({ 0 });
      write("Ok, puedes escribir. Escribe unicamente ** en una linea para terminar. Ayuda: ~h .\n");
      insertion_point = sizeof(lines);
      printf("%-2d] ", insertion_point+1);
      input_to("editor_loop");
      return 1;
  }
} /* do_edit() */

void main_bit(string str) {
  int i;
  string s;

  if (str != "") {
    while (str[0] == ' ')
      str = str[1..100];
    switch (str[0]) {
      case 'i' :
      case 'I' :
                write("Inserta linea anterior : ");
                input_to("editor_insert");
                return ;
      case 'd' :
      case 'D' :
                write("Inserta linea a borrar (puedes usar un numero o un rango n..m) : ");
                input_to("editor_delete");
                return ;
      case 'l' :
      case 'L' :
                s = "";
                for (i=0;i<sizeof(lines);i++)
                  s += sprintf("%3d: %s\n", i+1, lines[i]);
                this_player()->set_finish_func("end_of_edit_more");
                this_player()->more_string(s);
                return ;
      case 'm' :
      case 'M' :
                write("Inserta linea a modificar (puedes usar un numero o un rango n..m) : ");
                input_to("editor_modify");
                return ;
      case 'c' :
      case 'C' :
                write(sprintf("Ok, continuando, ** para terminar.\n%-2d] ", insertion_point+1));
                insertion_point = sizeof(lines);
                input_to("editor_loop");
                return ;
      case 'e' :
      case 'E' :
                write("Cambiando a modo ed...  Usa 'q' para salir, 'x' para grabar y salir, "+
                      "'Q' para salir sin grabar y 'h' "+
                      "para ver la ayuda.\n");
                write_file(TMP_FILE, implode(lines,"\n"));
                ed(TMP_FILE, "editor_exit_ed");
                return ;
      case 's' :
      case 'S' :
                write("Grabando y saliendo.\n");
                editor_do_quit(implode(lines, "\n"));
                return ;
      case 'q' :
      case 'Q' :
                write("Seguro que quieres abortar (Y/N)? ");
                input_to("editor_check_quit");
                return ;
      case 'h' :
      case 'H' :
                s = read_file(ED_HELP_FILE);
                this_player()->set_finish_func("end_of_edit_more");
                this_player()->more_string(s);
                return ;
       default :
                write("Comando desconocido.  Usa "+(editor == "command"?
                      "~h":"h")+" para ver la ayuda.\n");
                main_bit("");
                return ;
    }
  }
  if (editor == "menu") {
    write(sizeof(lines)+" lineas - Elige una opcion: IDLMCESQ H para ver la ayuda. ");
    input_to("main_bit");
  } else {
    printf("%-2d] ", insertion_point+1);
    input_to("editor_loop");
  }
  return ;
} /* editor_loop() */

void end_of_edit_more() {
  this_player()->set_finish_func(0);
  main_bit("");
} /* end_of_edit_more() */

void editor_delete(string str) {
  int num1, num2, tmp;

  if (sscanf(str, "%d..%d", num1, num2) == 2) {
    if (num1 > num2) {
      tmp = num1;
      num1 = num2;
      num2 = tmp;
    }
    if (num1 < 1 || num2 > sizeof(lines)+1) {
      write("Rango incorrecto.\n");
      main_bit("");
    }
    write("Borrando desde la linea "+num1+" hasta la linea "+num2+".\n");
    lines = delete(lines, num1-1, num2-num1+1);
    write("Ok.\n");
    main_bit("");
    return ;
  }
  if (sscanf(str, "%d", num1) == 1) {
    if (num1 < 1 || num1 > sizeof(lines)) {
      write("Numero de linea fuera de rango.\n");
      main_bit("");
      return ;
    }
    write("Borrando la linea "+num1+".\n");
    lines = delete(lines, num1-1, 1);
    write("Ok.\n");
    main_bit("");
    return ;
  }
  write("Error.\n");
  main_bit("");
  return ;
} /* editor_delete() */

void editor_insert(string str) {
  int num;

  if (sscanf(str, "%d", num) != 1) {
    write("ERROR! Debe ser un numero.\n");
    main_bit("");
    return ;
  }
  if (num < 1 || num > sizeof(lines)+1) {
    write("Numero fuera de rango.\n");
    main_bit("");
    return ;
  }
  insertion_point = num -1;
  write("Insertando despues de la linea "+num+".  Usa ** para terminar.\n] ");
  input_to("editor_loop");
  return ;
} /* editor_insert() */

void editor_loop(string str) {
  if (strlen(str) > 1 && str[0] == '~' && editor == "command") {
    main_bit(str[1..1000]);
    return ;
  }
  if (str == "**") {
    if (editor == "menu")
      main_bit("");
    else if (sizeof(lines))
      editor_do_quit(implode(lines, "\n"));
    else
      editor_do_quit(0);
    return ;
  }
  lines = lines[0..insertion_point-1]+({ str })+lines[insertion_point..1000];
  insertion_point++;
  printf("%-2d] ", insertion_point+1);
  input_to("editor_loop");
  return ;
} /* editor_loop() */

nosave int range1, range2;
nosave string modify_string;

void editor_modify(string str) {
  int num1, num2, tmp;

  if (sscanf(str, "%d..%d", num1, num2) == 2) {
    if (num1 > num2) {
      tmp = num1;
      num1 = num2;
      num2 = tmp;
    }
    if (num1 < 1 || num2 > sizeof(lines)+1) {
      write("Out of bounds.\n");
      main_bit("");
    }
    write("Modificando de la linea "+num1+" a la "+num2+".\n");
    write("Texto a cambiar: ");
    range1 = num1;
    range2 = num2;
    input_to("editor_modify2");
    return ;
  }
  if (sscanf(str, "%d", num1) == 1) {
    if (num1 < 1 || num1 > sizeof(lines)) {
      write("Numero de linea fuera de rango.\n");
      main_bit("");
      return ;
    }
    write("Modificando linea "+num1+".\n");
    write("Texto a cambiar: ");
    input_to("editor_modify2");
    range1 = range2 = num1;
    return ;
  }
  write("Error.\n");
  main_bit("");
  return ;
} /* editor_modify() */

void editor_modify2(string str) {
  if (!str || str == "") {
    write("Abortando.\n");
    main_bit("");
    return ;
  }
  write("Cambiar a: ");
  input_to("editor_modify3");
  modify_string = str;
  return ;
} /* editor_modify2() */

void editor_modify3(string str) {
  int i;
  string s1, s2, s3;

  write("Cambiando todas las apariciones de '"+modify_string+"' por '"+str+"' "+
        "en el intervalo ["+range1+"-"+range2+"]\n");
  for (i=range1-1; i<range2;i++)
    if (sscanf(lines[i], "%s"+modify_string+"%s", s1, s2) == 2) {
      s1 += str;
      while (sscanf(s2, "%s"+modify_string+"%s", s3, s2) == 2)
        s1 += s3+str;
      lines[i] = s1 + s2;
      write(sprintf("%3d: %s\n", i+1, lines[i]));
    }
  write("Hecho.\n");
  main_bit("");
  return ;
} /* editor_modify3() */

void editor_exit_ed() {
  string str;

  str = read_file(TMP_FILE);
  if (!rm(TMP_FILE))
    log_file(LOG_FILE, "ed: couldn't rm "+TMP_FILE+"\n");
  lines = explode("#"+str+"#", "\n");
  lines[0] = lines[0][1..1000];
  lines[sizeof(lines)-1] = lines[sizeof(lines)-1][0..
                                 strlen(lines[sizeof(lines)-1])-2];
  main_bit("");
  return ;
} /* editor_exit_ed() */

void editor_finish_ed() {
  string str;

  str = read_file(TMP_FILE);
  if (!rm(TMP_FILE))
    log_file(LOG_FILE, "ed: couldn't rm "+TMP_FILE+"\n");
  if (!str) {
    write("Abortado.\n");
    editor_do_quit(0);
    return ;
  }
  lines = explode(str, "\n");
  if (sizeof(lines))
    editor_do_quit(str);
  else
    editor_do_quit(0);
  return ;
} /* editor_finish_ed() */

void editor_do_quit(string str) {
  lines = ({ });
  call_other(end_object, end_func, str);
  TP->fini_editor(); // Tyrael - Jun'02 - Evitar (Editando)
  end_object = 0;
} /* editor_do_quit() */

void editor_check_quit(string str) {
  if (str != "" && str[0] != 'y' && str[0] != 'Y') {
    write("Volviendo al editor.\n");
    main_bit("");
    return ;
  }
  write("Saliendo.\n");
  editor_do_quit(0);
  end_object = 0;
  return ;
} /* editor_check_quit() */

int set_editor(string str) {
  if (member_array(str, ({ "menu", "command", "ed" }) ) == -1) {
    notify_fail("Puedes elegir como editor de texto uno de los siguientes:\n   'menu'  'ed'  'command'\nNo pongas tu editor en ed a menos que sepas lo que haces.\n"+
                "El editor por defecto es 'menu'.\n");
    return 0;
  }
  editor = str;
  write("Editor set to "+str+".\n");
  return 1;
} /* set_editor() */

string append_signature() {
  mapping sig;

  sig = (mapping)this_player()->query_aliases();
  if (sig[".signature"]) {
    return "\n--\n"+replace((string)"/secure/finger"->make_string(sig[".signature"]), ";", "\n")+"\n";
  }
  return "";
} /* append_signature() */

void editor_check_do_quit() {
  if (end_object) {
/* Force them to sve the thingy they are editing. */
    write("Grabando lo que estabas haciendo.\n");
    if (editor != "ed")
      editor_do_quit(implode(lines, "\n"));
    else
      editor_finish_ed();
  }
} /* editor_check_do_quit() */
