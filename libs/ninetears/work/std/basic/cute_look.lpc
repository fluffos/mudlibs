string number_as_string(int num);
string number_as_place(int num);
/*
 * returns an array of the form:
 * ({
 *   ({
 *     "foo",
 *     "bing",
 *   }),
 *   ({
 *     ({ <list of living objects with short "foo"> }),
 *     ({ <ditto for short "bing"> }),
     }),
 *   ({
 *     "s1",
 *     "s2",
 *   }),
 *   ({
 *     ({ <list of pointers to objects that have a short of "s1"> }),
 *     ({ <ditto for objects with a short of "s2"> }),
 *   }),
 *   ({ <pointers to invisible objects> }),
 * })
 * The first two arrays contain living objects, the second two contain
 * the rest, the last contains the pointers to invisible objects.
 * NB: this_player() is _not_ included in the array if (s)he is present.
 */
mixed query_inventory(object *obs) {
  mixed inv;
  object ob;
  mixed desc;
  int i,j,z;

  inv = ({ ({ }), ({ }), ({ }), ({ }), ({ }), });
  if (!obs)
    obs = all_inventory(this_object());
  for (z = sizeof(obs)-1; z >= 0;z--) {
    ob = obs[z];
    if (!(desc = (string)ob->pretty_short()) || (desc == "")) {
      inv[4] += ({ ob });
      continue;
    }
   /* Remove comments when ready for hidden players - Radix
    if(interactive(ob) && (int)ob->query_hidden())
    {
       inv[4] += ({ ob });
       continue;
    }
   */
    if (pointerp(desc)) {
      if (living(ob)) {
        if (ob == this_player()) continue;
        for (j=0;j<sizeof(desc);j++)
          if ((i = member_array(desc[j], inv[0])) >=0)
            inv[1][i] += ({ ob });
          else {
            inv[0] += ({ desc[j] });
            inv[1] += ({ ({ ob }), });
          }
        continue;
      }
      for (j=0;j<sizeof(desc);j++)
        if ((i = member_array(desc[j], inv[2])) >= 0)
          inv[3][i] += ({ ob });
        else {
          inv[2] += ({ desc[j] });
          inv[3] += ({ ({ ob }) });
        }
      continue;
    }
    if (living(ob)) {
      if (ob == this_player()) continue;
      if ((i = member_array(desc, inv[0])) >= 0) {
        inv[1][i] += ({ ob });
        continue;
      }
      inv[0] += ({ desc });
      inv[1] += ({ ({ ob }), });
      continue;
    }
    if ((i = member_array(desc, inv[2])) >= 0) {
      inv[3][i] += ({ ob });
      continue;
    }
    inv[2] += ({ desc });
    inv[3] += ({ ({ ob }), });
  }
  return inv;
}

string number_as_string(int n) {
  string ret;

  if (!n) return "cero";
  if (n<20 && n>9) return ({ "diez", "once", "doce", "trece",
"catorce", "quince", "dieciseis", "diecisiete", "dieciocho", "diecinueve" })[n-10];
  ret = ({ "", "", "veinte", "treinta", "cuarenta", "cincuenta",
"sesenta", "setenta", "ochenta", "noventa"})[n/10];
  if ((n = n%10)&&(ret!="")) ret += " ";
  return ret + ({ "", "un", "dos", "tres", "cuatro", "cinco", "seis",
"siete", "ocho", "nueve"})[n];
}

string number_as_place(int n) {
  if (!n) return "cero";
  if (n>9 && n<20) return n+"ero";
  return n+((n%10 == 1)?"er":(n%10 == 2)?"nd":(n%10 == 3)?"rd":"ero");
}

/*
 * returns a string of the contents.
 * this is crying out to be fixed....
 */
// usar somos_plural() de la shadow de mirror para poner "estan"
// sin que falle algun dia...
varargs string query_contents(string str, object *obs) {
  	int i, j, drunk;
  	mixed inv;
  	string ret;
	string color;

  	ret = "";
  	inv = query_inventory(obs);
  	drunk = (int)this_player()->query_volume(0);
  	if (!sizeof(inv[0]) && !sizeof(inv[2])) return ret;
  	if (str) ret += str;
  	str = " esta";

  	if (sizeof(inv[0]) > 1) str = " estan";
  	for (i=sizeof(inv[0])-1; i >= 0; i--) {
    		if (inv[0][i][0] < '0' && inv[0][i][0] > '9') j = sizeof(inv[1][i])*((random(drunk)/1000)+1);
    		else j = sizeof(inv[1][i]);
		
                switch(TP->query_relacion(inv[1][i][0])) {
		    case -2:color="%^RED%^BOLD%^";break;
		    case -1:color="%^BLACK%^BOLD%^";break;
                    case 0:color="%^BOLD%^";break;
		    case 1:color="%^CYAN%^";break;
		    case 2:color="%^CYAN%^BOLD%^";break;
		    }
		if(!inv[1][i][0]->query_player()) color="%^RESET%^";
		
		if (j > 1) {
      			ret += capitalize(query_num(j, 0)) + " "+color+inv[1][i][0]->pretty_plural(inv[0][i])+"%^RESET%^";
      			str = " estan";
    			}
		else ret += color+capitalize(inv[0][i])+"%^RESET%^";
    		if (!i) {
      			ret += str + " aqui.\n";
      			break;
    			}
    		if (i == 1) {
      			ret += " y ";
      			continue;
    			}
    		ret += ", ";
  		}
  	for (i=sizeof(inv[2])-1; i>=0; i--) {
    		j = sizeof(inv[3][i])*((random(drunk)/1000)+1);
    		if (j > 1) {
      			ret += capitalize(query_num(j,20)) + " " +(string)inv[3][i][0]->pretty_plural(inv[2][i]) + ".\n";
      			continue;
    			}
    		ret += capitalize(inv[2][i]) + ".\n";
  		}
  	return ret;
	}

void list_contents(string str) {
  write(query_contents(str));
}
