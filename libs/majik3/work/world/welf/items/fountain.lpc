inherit LIQUID;

create_item ()
{
  set_name (({ "a grey fountain", "fountain" }));
  set_short ("a grey fountain spouts water in the air here");

  set_long ("The fountain is made of smooth grey granite which catches the"
          + " light in the most sparkling way. At the center of the fountain"
          + " stands a statue sculpted to resemble a majestetic grey swan spr"
          + "eading its wings. It spouts water from its beak and makes a happy"
          + " gurgling sound. You enjoy greatly watching the waters play. \n");

  set_material ("granite");
  set_dimensions (200, 200, 200, 50);
  set_liquid ("water");
  set_liters (THOB->query_max_liters());

  set_no_get (1);
  set_no_empty (1);
  set_no_clean_up(1);
}
