string dame_tipo(int i)
{
  switch(i)
   {
    case(0):
        return "Cuerpo  ";
    case(1):
        return "Escudo  ";
    case(2):
        return "Cabeza  ";
    case(3):
        return "Pies    ";
    case(4):
        return "Cuello  ";
    case(5):
        return "Torso   ";
    case(6):
        return "Dedos   ";
    case(7):
        return "Manos   ";
    case(8):
        return "Brazos  ";
    case(9):
        return "Cintura ";
    case(10):
        return "Piernas ";
    case(11):
        return "Espalda ";
    case(12):
        return "Orejas  ";
    case(13):
        return "Tobillos";
    case(14):
        return "Cara    ";
    case(15):
        return "Munyeca ";
    case(16):
        return "Frente  ";
    case(17):
        return "Hombros ";
    default:
        return "desconocido";
	}
}


string query_living_contents(int self)
{
  object *wpn, *held, *worn, *carry, money;
  string s, ret, *strs, loc, *worn2;
  int i, col, j, cont;


  s = "";
  strs  = ({ });
  carry = ({ });
  loc="";
  j=0;

  wpn  = TO->query_weapons_wielded();  // Armas
  held = TO->query_held_ob();          // Objetos empunyado NO arma
  worn = TO->query_worn_ob();          // Objetos vestidos
  if (!pointerp(wpn))  wpn  = ({ }); else wpn  -= ({ 0 });
  if (!pointerp(held)) held = ({ }); else held -= ({ 0 });
  if (!pointerp(worn)) worn = ({ }); else worn -= ({ 0 });
  held -= wpn;
  worn = sort_array(worn,"sort");
  money = present("Some Money For Me", TO);        // Dinero
  carry = all_inventory(TO) - wpn - held
          - worn - ({ money });                    // Resto de objetos
  carry = filter_array(carry,"filtro"); // Elimino objetos "ocultos"

  if(sizeof(wpn))  strs+=({"Empunyando",  query_multiple_short(wpn) +".\n"});
  if(sizeof(held)) strs+=({"Sosteniendo", query_multiple_short(held)+".\n"});

      if(sizeof(worn))
         {
          loc+="Vistiendo:\n\n";
          cont=0;
          for(i=0;i<17;i++)
           {
            if(j<sizeof(worn))
            { if(worn[j]->query_armour_type()==(i+1))
              {
                if(i==4||i==6||i==12||i==16)
                { loc+="   "+dame_tipo(i)+": ";
                  if((j+1)<sizeof(worn))
                   while(worn[j]->query_armour_type()==worn[j+1]->query_armour_type())
                    {  loc+=worn[j]->query_short()+" ("+
                           worn[j]->cond_string_short()+"). ";
                       j+=1;
                       cont+=1;
                       if(cont==2&&(worn[j-1]->query_armour_type()==worn[j]->query_armour_type()))
                          loc+="\n             ";
                       if(j>=sizeof(worn)-1)
                         break;
                    }
                  loc+=worn[j]->query_short()+" ("+
                       worn[j]->cond_string_short()+"). ";
                  j+=1;
                  loc+="\n";
                }
                   { loc+="   "+dame_tipo(i)+": ";
                    loc+=worn[j]->query_short()+" ("+
                           worn[j]->cond_string_short()+").\n";
                       j+=1;
                  }
              }
            }
           }
         }
         else
           loc+="Vistiendo:   %^BOLD%^Nada%^RESET%^\n";
write("blablabla\n");
return 1;
}

int filtro(object ob)
{
  string str = ob->query_short();
  return (str && str!="");
}

