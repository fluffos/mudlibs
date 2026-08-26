string *jedi_titles = ({
   "Jedi Padawan",
   "Jedi Knight",
   "Jedi Master",
   "Jedi Grand Master",
});

string *sith_titles = ({
   "Sith Apprentice",
   "Sith Master",
   "Sith Lord",
   "Dark Lord of the Sith",
});

string get_jedi_rank_title(int rank, int alignment)
{
   if (rank < 1) { rank = 1; }
   else if (rank > 4) { rank = 4; }

   if (alignment < 0)
   {
      return sith_titles[rank - 1];
   }

   return jedi_titles[rank - 1];
}