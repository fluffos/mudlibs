
inherit ITEM;
inherit F_FOOD;

string *names= ({
  "´à¿¾»ğ¼¦",
  "ÏãÑ¬»ğ¼¦",
  "ÌîÔæ»ğ¼¦",
});

string *parts= ({
  "»ğ¼¦Èâ",
  "»ğ¼¦Ğ¡ÍÈÈâ",
  "»ğ¼¦´óÍÈÈâ",
  "»ğ¼¦³á°òÈâ",
  "»ğ¼¦±³°åÈâ",
  "»ğ¼¦¸¬×ÓÈâ",
  "»ğ¼¦¾±×ÓÈâ",
  "»ğ¼¦Æ¨¹ÉÈâ",
  "»ğ¼¦Í·",
  "»ğ¼¦ëÓ",
  "»ğ¼¦¸Î",
  "»ğ¼¦³¦",
  "»ğ¼¦Öå³¦",
  "»ğ¼¦ÕëÏß°üÑü×Ó",
  "»ğ¼¦ÕíÍ··Î",
  "»ğ¼¦Àß¹Ç",
  "»ğ¼¦¾±¹Ç",
  "»ğ¼¦³á¹Ç",
  "»ğ¼¦ÍÈ¹Ç",
});

void create()
{
  string name = "»ğ¼¦";
  set_name(name, ({"turkey"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "Ò»Ö»Ë¶´óµÄ¸Ğ¶÷½Ú»ğ¼¦¡£\n");
    set("unit", "Ö»");
    set("value", 950);
    set("food_remaining", 30);
    set("food_supply", 10);
  }
  setup();
}

