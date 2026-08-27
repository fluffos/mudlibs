// Alea 1996
//     CODE by Taniwha and Alea
//          July 22,1996
// Traducida por Gareth 22.01.03

inherit "/std/object";
string * verbotten = ({ "thief","Grimbrand","bard","wiz-thief" });
int wet;

void setup()
{
   set_name("toalla");
   set_short("Toalla suave");
   set_long("     Tienes en tus manos una de las toallas mas "
      "suaves que has visto nunca. Es de un brillante "
      "color rosa va muy bien con todo lo que llevas, "
      "como con cualquier cosa que puedas vestir.\n\n");

   set_weight(20);
   add_plural("Toallas Suaves");
}
void dryer(object me)
{
   wet = me->query_wetness();
   if(wet > 50) wet = 50;
   me->adjust_wetness(-wet);
}

void init()
{
  ::init();
   add_action("do_dry","secar");
   add_action("do_wring","estrujar");
}

int do_dry(string targetname)
{
   object me,you;
if(!targetname)
{
 notify_fail("Que quieres secar?\n");
 //Would you like to dry an object, or are you just trying to stop boozing?
return 0;
}
   you = present(targetname,environment(this_player()));
   me  = this_player();
if(!targetname)
 {notify_fail ("Que quieres secar?\n");
 //Would you like to dry a person, or are you simply trying to stop boozing?
return 0;
}
   if(!you)
   {
      notify_fail("A quien quieres secar?\n");	
      return 0;
   }
   if(!you->query_alive())
   {
      notify_fail("Esta toalla esta lejos de ser tan buena como para secar eso!\n");
      return 0;
   }
   if(wet)
   {
      notify_fail("La toalla esta empapada.\n");
      return 0;
   }
   if( member_array(me->query_guild_name(),verbotten)>= 0 && !query_property("stolen") )
   {
      notify_fail("Te moririas de verguenza si has usado que no fue robada.\n");
      //You'd die of shame if you used a towel that HADN'T been stolen
      return 0;
   }
   if(!you->query_wetness())
   {
   	notify_fail(targetname+" no esta mojado.\n");
   	return 0;
   }	
   if( me == you )
   {
   	write(" Sientiendo un trozo humedo, decides agarrar tu "
      	"toalla rosa para hacer un buen trabajo, recuerdas "
      	"brevemente su suavidad contra tu piel. "
      	"Despues de ese breve momento, comienzas "
      	"a secarte.\n\n");

   	tell_room(environment(me),me->query_cap_name()+
      	" coje una toalla rosa y comienza a secarse "
   	"a si mismo. Un aspecto de placer cruza "
      	"su cara, mientras incrementa "
      	"tus celos.\n\n",({me}));
   	dryer(you);
   	return(1);
   }
   else
   {
   	write(" Viendo que "+you->query_cap_name()+
   	" esta algo mojado, tomas tu fiel toalla y "
   	"lo secas.\n"
   	);
   	tell_object(you,(string)me->query_cap_name()+
   	" te sonrie, agarra una toalla y te seca.\n"
   	);
   	tell_room(environment(me),(string)me->query_cap_name()+
   	" una gran toalla rosa y restriega a "
   	+you->query_cap_name()+" con ella.\n"
   	"Ambos parecen disfrutar con la experiencia.\n"
      ,({me,you}));
   	dryer(you);
   	return(1);
   	
   }	
return(0);
}

int do_wring(string str)
{
   object me=this_player();
   if(str != "toalla") 
   {
   	notify_fail("Secar que?\n");	
   	return 0;
   }	
   if(!wet)
   {
      notify_fail("La toalla ya esta seca.\n");
      return 0;
   }
   write("    Anhelando sentir la suavidad de la toalla "
      "otra vez, comienzas a retorcer la toalla lentamente, "
      "intentando secar todo el agua que tiene.\n\n"
      "Ahhhh..... mucho mejor ahora. Un aspecto de placer "
      "cruza tu cara mientras frotas la suave toalla "
      "contra tu cara.\n\n");


      tell_room(environment(me),me->query_cap_name()+
   	" sostiene la toalla goteando en sus manos, y "
      	"comienza a estrujarla lentamente para secarla.\n\n",({me}));
   	wet = 0;
      return(1);
}
