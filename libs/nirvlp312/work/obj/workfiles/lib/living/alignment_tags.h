string translate_alignment_tag(int a)
{
  if(a > 10 * 64)
  {
    return "white lord";
  }
  if(a > 10 * 32)
  {
    return "paladin";
  }
  if(a > 10 * 16)
  {
    return "crusader";
  }
  if(a > 10 * 8)
  {
    return "good";
  }
  if(a > 10 * 4)
  {
    return "honorable";    
  }
  if(a > - 10 * 4)
  {
    return "neutral";   
  }
  if(a > - 10 * 8)
  {
    return "malicious";
  }
  if(a > - 10 * 16)
  {
    return "evil";
  }
  if(a > - 10 * 32)
  {
    return "infamous";
  }
  if(a > - 10 * 64)
  {
    return "black knight";
  }
  /* else */
  return "lord of evil";
}

