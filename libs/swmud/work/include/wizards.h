mapping wizard_titles = ([
   1 : "apprentice",
   2 : "journeyman",
   3 : "master",
   4 : "teacher",
]);

mapping wizard_titles_plural = ([
   1 : "apprentices",
   2 : "journeymen",
   3 : "masters",
   4 : "teachers",
]);

string get_wizard_title(int wizard_rank)
{
   if (wizard_titles[wizard_rank])
   {
      return wizard_titles[wizard_rank];
   }

   return "unknown";
}

string get_wizard_title_plural(int wizard_rank)
{
   if (wizard_titles_plural[wizard_rank])
   {
      return wizard_titles_plural[wizard_rank];
   }

   return "unknown";
}

mapping query_wizard_titles()
{
   return wizard_titles;
}