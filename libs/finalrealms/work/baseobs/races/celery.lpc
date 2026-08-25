inherit "/std/races/standard";
string *descs = ({"%^GREEN%^A stalk of celery","%^GREEN%^A large green thing with legs."});

void setup() {
   set_long("%^GREEN%^A rather large stalk of celery, with legs.\n");

   set_name("celery");
   /* throw away human bits and replace totally */
   bits = ({ 
"crown", 0, ({ 0, 2, 0, "left eye", "right eye", "left frond", "right frond" }),
"left eye", "eye", ({ "crown", 1, 0 }),
"right eye", "eye", ({ "crown", 1, 0 }),
"left frond", "frond", ({ "crown", 1, 0 }),
"right frond", "frond", ({ "crown", 1, 0 }),
"main stalk", "seed pods", ({ 0, 400, 0, "central stalk", "left central stalk", "left green bits",
    "right green bits", "fibrous nodules" }),
"central stalk", "", ({ "seed pods", 10, 0 }),
"left central stalk", "", ({ "seed pods", 5, 0 }),
"left green bits", "green curly bits", ({ "seed pods", 5, 0 }),
"right green bits", "green curly bits", ({ "seed pods", 5, 0 }),
"fibrous nodules", "", ({ "seed pods", 5, 0 }),
"flowers", "", ({ 0, 5, 0 }),  /* sex ????  ohhh yes*/
"left front stalk", "stalk", ({ 0, 5, 0, }),
"right front stalk", "stalk", ({ 0, 5, 0, }),
"rear petral stalk", "stalk", ({ 0, 5, 0 }),
"roots", 0, ({ 0, 5, 0 }),
});
}

string query_desc(object ob) {
   return( "%^GREEN%^A large ambulatory stalk of celery.\n");
}
string *valid_atatcks()
{
   return ({
   "$att_name$ swats $def_name$ with a leafy appendage",
   
"You swat $def_name$ with a leafy appendage",
  "$att_name$ swats you with a leafy appendage",

   });
}
