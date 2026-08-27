inherit "/std/room";
#include "/d/abarrach/path.h"

void setup()
{
   set_short("%^BOLD%^BLACK%^Abarrach:%^YELLOW%^ Oficina de correos%^RESET%^");
   set_long("Esta es la oficina de correos de Abarrach. Es conocida por su "+
   "velocidad en la entrega de mensajes, esto es debido al uso de hadas "+
   "como carteros. Escribe \"mail\" para entrar al lector de cartas. Hay " +
   "unos cuantos burocratas detras del mostrador. No puedes arrimarte a "+
   "ellos, debido a algun tipo de campo de fuerza.\n");
   
   set_light(85);
   add_exit("fuera", CIUDAD+"an0710", "door");
   add_item("mostrador", "Un impresionante mostrador que va de un lado a "+
   "otro de la habitacion. Parece que la oficina de correos esta preparada "+
   "para mas gente de la que la usa.\n"); 
}

void init()
{
   ::init();
   add_action("mail", "leer");
   add_action("mail", "mail");
}

int mail(string str)
{
object ob;

ob = clone_object("/obj/handlers/post");
ob->move(this_player());
ob->start_mail(str);
   return 1;
}

void send_message(string to)
{
   write("Uno de los encargados le da las instrucciones a un hada y se va "+
      "volando con tu carta.\n");
  say("Uno de los encargados le da unas instrucciones para entregar una "+
      "carta de "+this_player()->query_cap_name()+" y sale volando por la "+
      "puerta.\n");

   if (find_living(to))
      call_out("after_call",5,to);
}

void after_call(string to)
{
   object ob;
   
   ob = find_living(to);
   if (!ob)
      return ;
   if (environment(ob) == this_object())
      say("El hada vuelve por la puerta y le da una nota a "+to+
      ".\n", this_player());
   else {
      tell_room(environment(ob), "Un hada vuela hacia "+to+", dice algo, "+
         "y se va volando por donde vino.\n", ({ ob }));
      call_out("come_back",5);
   }
   tell_object(ob, "Un hada vuela hacia ti y te informa de que "+
      "tienes correo.\n");
}

void come_back()
{
   tell_room(this_object(),"Un hada vuelve de su reparto de correo.\n");
}
