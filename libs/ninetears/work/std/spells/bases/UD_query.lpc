int where_me(object me)
{
  switch (explode(file_name(ENV(me)),"/")[1])
  {
    case "stonefall":
    case "oficios":
    case "clanes":
      return 1;
  }
  return ENV(me)->query_underground();
}
