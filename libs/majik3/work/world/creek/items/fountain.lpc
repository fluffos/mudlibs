inherit LIQUID;

create_item ()
{
  set_name (({ "a white marble fountain", "fountain","marble fountain"  }));
  set_short ("a white marble fountain gurgles here happily");
  set_long ("A fountain made from white marble, its sparking water is "
          + "crystal clear and ice cold. At the center of the fountain "
          + "is figurine of an angel holding a sword in other hand and "
          + "a shield in other. Water gushes towards the heavens from "
          + "its base.\n");

  set_dimensions (200, 200, 200, 75);
  set_material ("marble");
  set_liquid ("water");
  set_no_empty();
  set_liters (THOB->query_max_liters());
  set_no_get (1);
}
