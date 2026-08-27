#include <standard.h>
#include <cmd.h>

inherit CMD_BASE;

string query_short_help()
{
   return "Uso: pk\n\n"
      "Informa sobre las muertes que tienes a tus espaldas.\n\n";
}

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

string query_living_contents()
{
  object *wpn, *held, *worn, *carry, money;
  string s, ret, *strs, loc;
  int i, col, j, cont;

  s = "";
  strs  = ({ });
  carry = ({ });
  loc=""; 
  j=0;

  wpn  = TP->query_weapons_wielded();  // Armas
  held = TP->query_held_ob();          // Objetos empunyado NO arma
  worn = TP->query_worn_ob();          // Objetos vestidos
  if (!pointerp(wpn))  wpn  = ({ }); else wpn  -= ({ 0 });
  if (!pointerp(held)) held = ({ }); else held -= ({ 0 });
  if (!pointerp(worn)) worn = ({ }); else worn -= ({ 0 });
  held -= wpn;
  worn = sort_array(worn,"sort");
  money = present("Some Money For Me", TP);        // Dinero
  carry = all_inventory(TP) - wpn - held 
          - worn - ({ money });                    // Resto de objetos
  carry = filter_array(carry,"filtro"); // Elimino objetos "ocultos"
 

      if(!sizeof(wpn))
        loc="\nEmpunyando  :    %^REVERSE%^BOLD%^RED%^B_GREEN%^Modo de lucha %^MAGENTA%^DESARMADO.%^RESET%^\n";
      else
      {
        if(sizeof(wpn)==1)
          loc="\nEmpunyando  :   "+wpn[0]->query_short()+"\n";
        else
          loc="\nEmpunyando  :   "+wpn[0]->query_short()+" y "+
                       wpn[1]->query_short()+"\n";
      }

      if(!sizeof(held))
        loc="Sosteniendo :\n";
      else
      {
        if(sizeof(held)==1)
          loc+="Sosteniendo :   "+held[0]->query_short()+"\n";
        else
          loc+="Sosteniendo :  "+held[0]->query_short()+" y "+
                       held[1]->query_short()+"\n";
      }

 
      if(sizeof(worn))
         {
          loc+="Vistiendo   :\n";
          cont=0;
          for(i=0;i<17;i++)
           {
            if(j<sizeof(worn))
            { if(worn[j]->query_armour_type()==(i+1))
              {
                if(i==4||i==6||i==12||i==16)
                { loc+=" * "+dame_tipo(i)+" : ";
                  if((j+1)<sizeof(worn))
                   while(worn[j]->query_armour_type()==worn[j+1]->query_armour_type())
                    {  loc+=worn[j]->query_short();
                       j+=1;
                       cont+=1;
                       if(cont==2&&(worn[j-1]->query_armour_type()==worn[j]->query_armour_type()))
                          loc+="\n";
                       if(j>=sizeof(worn)-1)
                         break;
                    }
                  loc+=worn[j]->query_short();
                  j+=1;
                  loc+="\n";
                }
                else
		{
                   loc+=" * "+dame_tipo(i)+" : ";
                    loc+=worn[j]->query_short()+"\n";
                       j+=1;
                  }
              }
            }
           }
         }
         else
	{	
           loc+="Vistiendo:   %^BOLD%^Nada%^RESET%^\n";
	}

      loc+="\nOtros:\n";
      if(j<sizeof(worn))
        { loc+="\n   ";
         for(i=j;i<sizeof(worn);i++)
            loc+="   "+worn[i]->query_short()+" ("+worn[i]->cond_string_short()+").\n";

        }
      loc+="\n";

//      return loc;
   

  // Fin comando localizacion

  if(sizeof(wpn))  strs+=({"Empunyando",  query_multiple_short(wpn) +".\n"});
  if(sizeof(held)) strs+=({"Sosteniendo", query_multiple_short(held)+".\n"});



 if(sizeof(carry)) 
    strs  += ({ "Cargando", query_multiple_short(carry)+"." });

  col = TP?TP->query_cols()-13:80;
  for(i=0; i<sizeof(strs); i++)
    s += sprintf("%11-s: %-=*s\n", strs[i], col, capitalize(strs[++i]));

    if(!sizeof(strs)) s = "Estas con las manos vacias.\n";
    ret = (money?money->short(0):0);
    if(money) 
    {
      loc += capitalize("La bolsa esta ");
      switch(money->query_number_coins())
      {
        case 0..10:    loc += "llena de telaranyas!"; break;
        case 11..40:   loc += "casi vacia.";          break;
        case 41..100:  loc += "medio llena.";          break;
        case 101..300: loc += "llena de monedas.";    break;
        case 301..400: loc += "a rebosar de monedas.";    break;
        default:       loc += "a punto de reventar!";
      }
      }
  loc +="\n";
  return loc;
}

int sort(object s1, object s2)
{
  if (s1->query_armour_type()>s2->query_armour_type()) return 1;
  if (s1->query_armour_type()<s2->query_armour_type()) return -1;
  return 0;
}

int filtro(object ob)
{
  string str = ob->query_short();
  return (str && str!="");
}



int cmd(string str, object ob)
{
        write(query_living_contents());
        return 1;
}

