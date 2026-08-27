/* By Shimmer */


inherit "/obj/monster";

string ataque1,ataque2,ataque3;

void setup()
  {
  set_race("monster");
  switch(random(5))
  {
    case 0:
      set_name("lombriz de tierra");
      set_short("lombriz de tierra");
      set_long("Es una pequenya lombriz de tierra que se arastra por el suelo poco a poco.\n");
      add_alias("lombriz");
      set_main_plural("lombrices");
      add_plural("lombrices");
      set_gender(2);
      ataque1="babosea";
      ataque2="hace cosquillas al meterse en tu calzado";
      ataque3="te hace caer cuando intenta escapar";
      set_level(1);
      break;
    case 1:
      set_name("rata");
      set_short("rata");
      set_long("Es una rata gorda, grande y fea, propia de zonas oscuras y humedas como esta\n");
      add_alias("rata");
      set_main_plural("ratas");
      add_plural("ratas");
      set_gender(1);
      ataque1="rabunya la cara";
      ataque2="aranya una mano";
      ataque3="muerde la pierna";
      set_level(2+random(2));
      break;
    case 2:
      set_name("topo");
      set_short("topo");
      set_long("Es un topo tranquilo que ni se entera de que pasas por aqu\n");
      set_main_plural("topos");
	add_plural("topos");
      set_gender(1);
      ataque1="golpea una pierna";
      ataque2="muerde";
      ataque3="aranya";
      set_level(1+random(3));
      break;
    case 3:
      set_name("babosa");
      set_short("babosa");
      set_long("Es una pequenya babosa de color negro que busca algo de comida por los arrededores mientras se arrastra.\n");
      add_alias("babosa");
      set_main_plural("babosas");
      add_plural("babosas");
      set_gender(2);
      ataque1="lanza babas a la cara";
      ataque2="empapa de babas";
      ataque3="hace cosquillas en la pierna";
      set_level(1);
      break;
    case 4:
      set_name("aranya");
      set_short("aranya");
      set_long("Es una aranya que teje su tela en una esquina.\n");
      set_main_plural("aranyas");
      add_plural("aranyas");
      set_gender(2);
      set_level(2);
      ataque1="aranya la cara";
      ataque2="muerde un brazo";
      ataque3="muerde una pierna";
      break;
   }
  set_random_stats(6,17); 
  set_al(0);
  set_wimpy(20);
} 
#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()


int unarmed_attack(object target,object me) 
{
  object *att;
  att = (object*)me->query_attacker_list();
  monster::unarmed_attack(att[random(sizeof(att))],me);
} 


valid_attack() 
{
   return([
      "kick"  :({AN+" "+({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".\n",
                 ({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".",
                 AN+" te "+({ataque1,ataque2,ataque3})[random(3)]+".\n"}),
      "knee"  :({AN+" "+({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".\n",
                 ({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".",
                 AN+" te "+({ataque1,ataque2,ataque3})[random(3)]+".\n"}),
      "punch"  :({AN+" "+({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".\n",
                 ({ataque1,ataque2,ataque3})[random(3)]+" a "+DN+".",
                 AN+" te "+({ataque1,ataque2,ataque3})[random(3)]+".\n"})]);


}
