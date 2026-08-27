inherit "/obj/monster";
           
void event_enter(object ob, string mess)
{
  string raza  = ob->query_race();
    
  if (((raza == "elfo" || raza == "enano" || raza == "halfling" || raza == "lizard-man" || raza == "Half-elf" ||
  raza  == "gnomo" || raza == "humano" || raza == "drow" || raza == "half-drow")))
   {
     do_command("say Por la gloria de Keroon!! moriras ser asqueroso!!!!!!");
     do_command("seguir ob");   
     this_object()->attack_ob(ob);       
   }
   else
   {
  if (((raza == "orco" || raza == "Half-orc" || raza == "goblin")))
  {
  do_command("say Saludos, espero que no busqueis lios!!!!!");
  }
  else
  {
    if (((raza == "duergar")))
    {
    do_command("say Encantado de verte por estos corredores hermano, da gusto estar tan cerca de casa verdad?");
    }
  }
   }
  ::event_enter(ob, mess);
}
