// Fantasma.
// Gestur'98 (En mita de los examenes)
#include "path.h"

inherit "/obj/monster";

void setup()
{
   set_name("fantasma");
   set_short("%^GREEN%^BOLD%^Fantasma%^RESET%^");
   set_main_plural("%^GREEN%^BOLD%^Fantasmas%^RESET%^");
   add_plural("fantasmas");
   set_race_ob("fantasma");
   set_long("Estas delante de lo que parece un fantasma. Su imagen es "
   "eterea casi como el mismo aire, pero el resplandor que desprende "
   "facilita su vision. El resplandor es de color verde fosforescente "
   "igual que los restos que hay en el suelo. De esto deduces que son "
   "suyos. A pesar de que pueda parecer terrorifico su cara expresa una "
   "agradable sonrisa.\n");
   add_property("undead", 1);
   set_random_stats(6,18);
   set_str(16+random(6));
   set_level(15+random(10));
   set_thac0(600);  // No te pega
   set_al(-1000);
   load_chat(30, 
   ({ 1, ":cambia su intensidad de brillo.",
      1, ":se va por el este.",
      1, ":llega del este.",
      1, ":comienza a formular un hechizo.",
      1, ":te propina el golpe mortal.",
      1, "'Q u i e r e s  a p r e n d e r  m i s  h a b i l i d a d e s ?",
   }));
   load_a_chat(150,
   ({ 1, ":pronuncia el cantico 'magios aereos pyros'.",
      2, ":te golpea con su espada bastarda, produciendote 666 HPs de danyo.",
   }));
}

void adjust_hp(int i)
{
   if (i && i!=1 && i!=-1)
   {
      tell_object(TP, TO->query_short()+" no parece quejarse mucho.\n");
      tell_room(ETO, TP->query_cap_name()+" golpea al "+TO->query_short()+
      " pero no parece quejarse mucho.\n", TP);
   }   
   return 0;
}

/** Aokromes & XeoN 2000/07/24 Modificacion para aceptar conversaciones con filtro (Shadow) Antis y Palatas**/


void event_person_say(object ob, string start, string mess, string lang, int speaker)
{
    string frase;    
    frase = lower_case(mess);
    frase = extract(frase,strlen(frase)-3,strlen(frase)-1);
    if (frase == "si" || frase == " si" || frase == " si " || frase == "si " )
    {
    	call_out("show_emote", 2, ob);
        return 0;
    }
    else
    {
    	TO->do_say("N o  t e  e n t i e n d o .");
        TO->do_say("Q u i e r e s  a p r e n d e r  m i s  "
            "h a b i l i d a d e s ?");
        return 0;
    }
}

void show_emote(object ob)
{
    if (ob->query_zombie()) return 0;
    else
    {
        if (ob->query_property("emote"))
        {
            TO->do_say("Y a  c o n o c e s  m i s  h a b i l i d a d e s !");
            return 0;
        }
        else
        {
            ob->add_property("emote", 1);
            TO->do_say("D e s d e  a h o r a  p o d r a s  h a c e r  l o  "
                "q u e  y o  h a g o .");
            tell_object(ob, TO->query_short()+" te ha ensenyado la "
                "habilidad \"emocion\". Pon \"ayuda emocion\" para saber "
                "mas sobre este comando.\n");
            log_file(LOGS+"emote_log", ob->query_cap_name()+" completo la "
            "quest en "+ctime(time())+".\n", 0);
        }
    }
   return 1;
}
