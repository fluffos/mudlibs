/* Do not remove the headers from this file! see /USAGE for more info. */

/* Random ART_OBJECT by Tsath 2020, May */

inherit OBJ;
inherit M_GETTABLE;

string *hard_materials = ({"marble", "silver", "tin", "copper", "wooden", "lead", "carved bone", "gold"});
string *soft_materials = ({"cloth", "silk", "hemp"});
string *colours =
    ({"bright chrimson", "blood rod", "orange", "bright yellow", "yellow ochre", "lime green", "forest green", "teal",
      "sky blue", "cerulean", "phtalo blue", "violet", "lavender", "pink", "brown", "gray", "white", "clear", "black"});
int rolled;
float art_value = 25.0;
string item_code;

void set_value(float value);

float query_value()
{
   return query_value();
}

// If sold to merchant, just remove the item, don't sell it again.
int destroyable()
{
   return 1;
}

string item_name()
{
   string id, tmp, item;
   item = item_code;
   sscanf(item, "%s +%s+ %s", tmp, id, tmp);
   if (!id)
      sscanf(item, "%s +%s+", tmp, id);
   if (!id)
      sscanf(item, "+%s+ %s", id, tmp);
   if (!id)
   {
      TBUG("Bad format art object: '" + item + "'");
      return;
   }
   set_id(id);

   item = replace_string(item, "+", "");
   item = replace_string(item, "[hmat]", choice(hard_materials));
   item = replace_string(item, "[smat]", choice(soft_materials));
   item = replace_string(item, "[col]", choice(colours));
   set_long(item);
   set_long("This art object is " + item + ", and it can be sold to a vendor buying these.");

   return item;
}

void generate_item()
{
   string *options;
   string item;

   if (!rolled)
   {
      rolled = 1;

      switch (to_int(query_value()))
      {
      case 25..249:
         options = ({"[hmat] +ewer+", "[hmat] +statuette+", "small [hmat] +bracelet+", "[col] [smat] +mask+",
                     "[hmat] +chalice+ with [hmat] filigree", "[col] embroidered [smat] +cloth+",
                     "delicate [hmat] +figurine+", "pair of [hmat] +dice+",
                     "small [hmat] +mirror+ with [col] wooden framing", "[hmat] +bowl+", "[hmat] +plate+",
                     "embroidered [smat] +handkerchief+", "[hmat] +locket+ with a portrait inside"});

         item = choice(options);
         item_code = item;
         item = item_name();
         set_value(5 + random(to_int(query_value())));
         set_weight(random(5) + 1 * 0.1);
         break;
      case 250..749:
         options = ({"[hmat] +ring set+ with [col] gems", "large [hmat] +statuette+", "large [hmat] +bracelet+",
                     "[hmat] +necklace+ with a [col] gemstone pendant", "[hmat] +crown+",
                     "[smat] +robe+ with [hmat] embroidery", "large [smat] +tapestry+", "[hmat] +mug+ with jade inlay",
                     "box of [col] animal +figurines+", "[hmat] bird +cage+ with [smat] padding"});

         item = choice(options);
         item_code = item;
         set_value(50 + random(to_int(query_value())));
         set_weight(random(5) + 3 * 0.1);
         break;
      }
   }
   item = item_name();
}

void mudlib_setup(int value)
{
   if (value > art_value)
      art_value = value;
   set_id("art", "art object");
   set_value(art_value);
   call_out("generate_item", 0);
}

void internal_setup()
{
   this_object()->add_save(({"rolled", "art_value", "item_code"}));
}