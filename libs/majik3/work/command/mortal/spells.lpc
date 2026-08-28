int
main ()
{
  mapping spells;
  string buf = "";
  string *k, *spell_type = ({ "abjuration",
                              "alteration",
                              "conjuration",
                              "divination",
                              "enchantment",
                              "illusion",
                              "invocation",
                              "necromancy" });

  spells = THIS->query_spells();

  if (!spells || sizeof(spells) == 0)
    {
      write ("You have no spells.\n");
      return 1;
    }
  else
    {
      k = keys(spells);
      for (int i=0;i<sizeof(spell_type);i++)
        {
          for (int j=0;j<sizeof(k);j++)
            {
              if (THIS->find_spell(k[j]) == spell_type[i])
                buf += " - "+sprintf("^c1%-30s^c0 ^cY%3d^c0%%\n",
                  replace_string(k[j], "_", " "), spells[k[j]][0]);
            }

          if (buf != "")
            write ("You have following spells from ^cc"+spell_type[i]+
              "^c0 school:\n"+buf+"\n");
 
          buf = "";
        }
    }

  return 1;
}
query_author()
{
  return"namhas";
}

query_help()
{
  return "Shows you the spells you currently master and how good you are at that.";
}

query_see_also()
{
  return "skills(1)";
}
query_position()
{
  return POS_RESTING;
}

