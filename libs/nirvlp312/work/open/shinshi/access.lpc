/* Example file for granting other wizards access to your files */

status valid_write(string name, string path)
{
  string junk; 

 
 
  if (name == "shinshi")
    return 1;


  /* End of special cases, nobody else has special access */
  return 0;
}

status valid_read(string name, string path)
{
  /* If they can write to it, they can read it */
  if (valid_write(name, path)) return 1;

 
  /* No other special access */
  return 0;
}
