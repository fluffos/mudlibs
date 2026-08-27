// Guardian de torreta, igual ke los de la puerta, pero sin atakar.
// Sinister 27 Julio 00.

inherit "/obj/monster";
object ob;

void setup()
{
   object objeto;
   set_name("guardian");
   set_short("Guardian de la Torreta");
   set_al(-150);
   set_gender(1);
   set_main_plural("guardianes");
   add_plural("guardianes");
   add_alias("guardian");
   add_alias("guardia");
   add_plural("guardias");
   add_alias("human");
   set_race_ob("Humano");
   set_race_ob("/std/races/human");
   set_guild_ob("/std/guilds/warriors/fighter");
   set_wimpy(0);
   set_random_stats(14, 18);
   set_cha(14+random(4)); 
   set_str(19+random(11)); 
   set_level(30+random(10));
set_thac0(0);
   set_long("Es uno de los guardianes apostados en las Torretas de "
   "vigilancia, su unica funcion es avisar a los otros guardias de "
   "si alguien o algo ataca la ciudad, no te extranya nada verles "
   "dormidos cada diez minutos, el sol pega fuerte en el techo de "
   "la torreta, y quieras que no, dan ganas de dormir. Aun asi "
   "parecen mucho mas apuestos y fuertes que los guardianes de las "
   "puertas.\n");
            
   set_aggressive(0);
   load_chat(30,
      ({
             1, ":dice: Uahhhh, porque me has despertado?!",
       1, ":dice: Te juro que vi antes un goblin pasar por aqui corriendo.",
            1, ":te mira con la cara roja, impregnado por los efluvios del suenyo",
            1, ":se cae al suelo roncando sonoramente.",
       }));
   add_clone("/baseobs/weapons/bastard_sword",1);
   add_clone("/baseobs/armours/large_shield",1);
   add_clone("/baseobs/armours/platemail",1);
   ::init_equip();
}
