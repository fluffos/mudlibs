int query_guild_level(string guild);

int jedi_alignment = 0;

//:FUNCTION query_jedi_alignment
//Returns numeric jedi alignment
int query_jedi_alignment()
{
   if (!query_guild_level("jedi"))
   {
      return 0;
   }

   return jedi_alignment;
}

//:FUNCTION query_max_jedi_alignment
//Returns numeric maximum jedi alignment
int query_max_jedi_alignment()
{
   int jedi_level = query_guild_level("jedi");
   int max_alignment;

   if (!jedi_level) { return 0; }

   max_alignment = 25 + floor(jedi_level / 2);

   if (jedi_alignment < 0) { max_alignment *= -1; }

   return max_alignment;
}

//:FUNCTION set_jedi_alignment
//Value is from -50 to 50
void set_jedi_alignment(int value)
{
   int jedi_level = query_guild_level("jedi");
   int max_alignment;

   if (this_object()->is_body()) { this_object()->check_wizard_set("set " + this_object()->short() + "'s jedi alignment from " + jedi_alignment + " to " + value, previous_object(-1)); }

   if (!jedi_level) { return; }

   max_alignment = 25 + floor(jedi_level / 2);

   if ((value >= (max_alignment * -1)) && (value <= max_alignment))
   {
      jedi_alignment = value;
   }
   else
   {
      if (value < 0)
      {
         jedi_alignment = max_alignment * -1;
      }
      else if (value > 0)
      {
         jedi_alignment = max_alignment;
      }
   }
}

//:FUNCTION adjust_jedi_alignment
//Value is positive or negative integer
void adjust_jedi_alignment(int value)
{
   int jedi_level = query_guild_level("jedi");
   int max_alignment;

   if (this_object()->is_body()) { this_object()->check_wizard_set("adjust " + this_object()->short() + "'s jedi alignment from " + jedi_alignment + " to " + value, previous_object(-1)); }

   if (!jedi_level) { return; }

   max_alignment = 25 + floor(jedi_level / 2);

   if ((jedi_alignment < 0) && ((jedi_alignment + value) > -1))
   {
      jedi_alignment = max_alignment;
   }
   else if ((jedi_alignment > 0) && ((jedi_alignment + value) < 1))
   {
      jedi_alignment = max_alignment * -1;
   }

   jedi_alignment += value;

   if ((jedi_alignment < 0) && (jedi_alignment < (max_alignment * -1)))
   {
      jedi_alignment = max_alignment * -1;
   }
   else if ((jedi_alignment > 0) && (jedi_alignment > max_alignment))
   {
      jedi_alignment = max_alignment;
   }
}