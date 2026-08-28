string *known = ({ });

string
query_description_beauty ()
{
  switch (THOB->query_cha())
    {
      case -1000..5:
        return "hideous";
      case 6..8:
        return "ugly";
      case 9..11:
        return "ordinary";
      case 12..13:
        if (THOB->query_gender() == 1)
          return "good-looking";
        else return "pretty";
      case 14:
        return "elegant";
      case 15..17:
        if (THOB->query_gender() == 1)
          return "handsome";
        else
          return "beautiful";
      case 18..19:
        return "attractive";
      case 20..21:
        return "charming";
      case 22..28:
        if (THOB->query_gender() == 1)
          return "adorable";
        else
          return "gorgeous";
      case 29..35:
        return "magnificent";
      default:
        return "exquisite";
    }
  return "bug";
}

string
query_description_age ()
{
  switch ((THOB->query("age")/100)*100/(THOB->query("max_age")/100))
    {
      case 0..11:
        return "very young";
      case 12..17:
        return "teenage";
      case 18..29:
        return "young";
      case 30..45:
        return "middle-aged";
      case 46..55:
        return "elderly";
      case 56..75:
        return "old";
      case 76..95:
        return "very old";
      default:
        return "ancient";
    }
  return "bug";
}

string
query_description_race ()
{
  switch (THOB->query("race"))
    {
      case "elf":
        return "elven";
      case "half-elf":
        return "half-elven";
      case "dwarf":
        return "dwarven";
    }

  return THOB->query("race");
}

string
query_description_gender()
{    
  switch ((THOB->query("age")/100)*100/(THOB->query("max_age")/100))
    {
      case 0..20:
        if (THOB->query_gender() == 1)
          return "boy"; 
        else
          return "girl";
      default:
        if (THOB->query_gender() == 1)
          return "man";
        else
          return "woman";   
    }
  return "bug";
}

query_stranger_short()
{
  return article(THOB->query_description_beauty() +
           " " + THOB->query_description_age() +
           " " + THOB->query_description_race() +
           " " + THOB->query_description_gender());
}

query_stranger_name()
{
  return article(THOB->query_description_race() +
           " " + THOB->query_description_gender());
}

string *
set_known (string *s)
{
  return known = s;
}

string *
query_known ()
{
  return known;
}

string *
add_known (string s)
{
  if (!known)
    known = ({ s });
  else
    known += ({ s });

  return known;
}

string *
remove_known (string s)
{
  if (known && member_array(s, known) > -1)
    known -= ({ s });

  return known;
}

int
test_known (object o)
{
  if (o)
    {
      if (known && member_array(o->query_name(), known) > -1)
        return 1;

      if (o == THOB)
        return 1;

      if (o->query_security())
        return 1;
    }

  return 0;
}
