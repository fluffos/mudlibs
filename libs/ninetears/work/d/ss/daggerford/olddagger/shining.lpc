inherit "std/pub";
#include "pub.h"
#include "path.h"
mixed top_list, top_deaths;
void add_to_list(object ob);

object board;
object kelson, filarion, delimbiyr;

void reset() {
   if(!kelson) {
      kelson = clone_object(CHAR+"kelson");
      kelson->move(this_object());
   }
   if(!filarion) {
      filarion = clone_object(CHAR+"filarion");
      filarion->move(this_object());
   }
   if(!delimbiyr) {
      delimbiyr = clone_object(CHAR+"delimbiyr");
      delimbiyr->move(this_object());
   }
   if (!board)
      {
      board = clone_object("/obj/misc/board");
      board->move(this_object());
      board->set_datafile("Council");
   }
/*   if (!list)
      {       
      list = clone_object("/obj/misc/list");
      list->move(this_object());
      list->set_datafile("Players");
   }*/
}

void setup()
{
   add_menu_item("Ale", ALCOHOL, 30, 15, 15, 15,
      "drink your beer", "drinks a pint of beer");
   add_menu_item("Mead", ALCOHOL, 100, 50, 50, 50,
      "drink a meal of dark mead", "drinks a meal of dark mead");
   add_menu_item("Malt whisky", ALCOHOL, 200, 100, 100, 100,
      "carefully sip the whisky", "slowly drinks a shot of whisky");
   add_menu_item("Otiluke Elixir", ALCOHOL, 500, 300, 300, 300,
      "you gulp the small glass of.... FIRE",
      "gulps down some kind of potion");
   add_menu_item("Egg roll", FOOD, 150, 17, 70, 0,
      "eat a dish of spring rolls", "eats a dish of spring rolls");
   add_menu_item("Chicken", FOOD, 200, 25, 90, 0,
      "eat a tasty chicken with rice", "eats chicken with rice");
   add_menu_item("Entrecote", FOOD, 400, 50, 180, 0,
      "eat a large hunk of tasty meat", "eats an entrecote");
   add_menu_item("Multi-dining", FOOD, 2000, 250, 700, 0,
      "eat several dishes from a large table", 
      "eats several dishes from a large table");
   add_menu_item("Tea", SOFTDRINK, 5, 0, 1, 0,
      "drink a cup of tea", "drinks a cup of tea");
   add_menu_item("Coffee", SOFTDRINK, 10, 1, 3, 0,
      "drink a cup of coffee", "drinks a cup of coffee");
   add_menu_alias("tea", "Tea");
   add_menu_alias("coffee", "Coffee");
   add_menu_alias("egg roll", "Egg roll");
   add_menu_alias("roll", "Egg roll");
   add_menu_alias("chicken", "Chicken");
   add_menu_alias("fried chicken", "Chicken");
   add_menu_alias("entrecote", "Entrecote");
   add_menu_alias("multi-dining", "Multi-dining");
   add_menu_alias("multi", "Multi-dining");
   add_menu_alias("beer", "Ale");
   add_menu_alias("ale", "Ale");
   add_menu_alias("ringnes beer", "Ale");
   add_menu_alias("stout", "Mead");
   add_menu_alias("mead", "Mead");
   add_menu_alias("whisky", "Malt whisky");
   add_menu_alias("malt", "Malt whisky");
   add_menu_alias("malt whisky", "Glenfiddich whisky");
   add_menu_alias("otiluke elixir", "Otiluke Elixir");
   add_menu_alias("Otiluke", "Otiluke Elixir");
   add_menu_alias("Elixir", "Otiluke Elixir");
   add_menu_alias("otiluke", "Otiluke Elixir");
   add_menu_alias("elixir", "Otiluke Elixir");
   set_short("The River Shining Tavern");
   set_long("You are in the stylish River Shining Tavern. The tavern is "+
      "decorated by all kinds of forest motifs. All very clean and stylish. "+
      "You notice a board here, inviting the patrons to write a note on how "+
      "they feel about the tavern and the Guilds in town. It is possible to "+
      "rent rooms upstairs, but unluckily for you this service is only given "+
      "to the most noble and influential patrons. There is a menu on the "+
      "nearest table. The doors to the east and north lead back outside.\n");
   
   add_exit("north", ROOM+"farmer4", "door");
   add_exit("east", ROOM+"duke2", "door");
   
   set_light(60);
   set_zone("pub");
   
   add_item(({"people", "patrons"}),
      "There are many of them, but since they're not really interested in "+
      "you might just as well let them be without your boisterous company.\n");
   add_item("bar",
      "The bar is made of wood, and is very stylish.\n");
   add_item("motifs",
      "The motifs seem to hint to the elfin heritage of the Delimbiyr!\n");
   add_item("menu",
      "Since there's writing on it they probably think you can read it.\n");
   add_item("table",
      "A cozy little table where you can enjoy your drinks.\n");
   
}

dest_me()
{
   if (board)
      board->dest_me();
/*   if (list)
      list->dest_me();*/
   if (kelson)
      kelson->dest_me();
   if (filarion)
      filarion->dest_me();
   if (delimbiyr)
      delimbiyr->dest_me();
   ::dest_me();
}

