/*
 * player interfaces for mysql goes here. makes things easier
 * mokri
*/


/*
 * pass a name, and a column you want to return that result
 * as a string.
 * example:
 * get_player("mokri","level") would return the value of the 'level'
 * column in the 'players' table where the name was 'mokri'.
 * note that all results are returned as a string.
*/

string get_player_info(string name, string what)
{
  string my_result, *rs;
  mixed *all;
  if(!name || !what)
    return my_result;

  all = db_get_rs("select " + what + " from players where name='" + name + "'");
  if(sizeof(all))
    rs = all[0];
  if(sizeof(rs))
    my_result = rs[0];
  return my_result;
}
