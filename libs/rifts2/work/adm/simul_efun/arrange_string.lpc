//     /adm/simul_efun/arrange_string.c
//     from the Nightmare mudlib
//     makes a string a certain length
//     created by Descartes of Borg 23 december 1992
//     modified to take into account ansi colour :) codes
//       by Blodgett 10 september 1993 (europosis!)
//    log- 2005 - this damn function keeps throwing trace errors. 2nd argument to < not numeric when 1st is. references bottom line
//    -----Not sure wtf is doing this... x is the primary second argument to < in most of the function and if x is not passed this beast returns ""
//    I'll keep working on it --- parnell 2005

// recoding this darn thing - parnell 05
// ok it looks like if x is bigger than the string, the part that is suppose to add spaces is not working. 12:02 mar 19:2005
// well i see why i was confused, this function only handles the first color code sent to it, the rest it ignores hah, what  ajoke




string arrange_string(string str, int x) {
  int i, num, oldnum, total;
  string borg, blod, boop, burp;
  string *tmp;

  if(!str || str == "") 
    return "";

  if(!x) 
    return "";

  if(intp(str)) 
    str = str+"";
  total = x;
  num = 0;
  i = sizeof((tmp = explode(str,"%^")));

  if(i) borg = tmp[0];

  if(i>1) blod = tmp[1];

  if(i>2) { i = 3; burp = implode(exclude_array(tmp,0,1),""); }

  num = strlen(borg);

  boop = borg;

  if(num>x)
    boop = borg[0..x-1];
  else {
    if(i==2) {
      oldnum = num;
      num = num + strlen(blod);
      boop = boop + "%^";
      if(num>x) {
        boop = boop + blod[0..x-oldnum-1];
        num = x;
      } else
        boop = boop + blod;
    }
    if(i==3)
      boop = boop + "%^" + blod + "%^";

    while((i==3)&&(num<x)) {
    i = sizeof((tmp = explode(burp, "%^")));

    if(i) borg = tmp[0];
    if(i>1) blod = tmp[1];
    if(i>2) { i=3; burp = implode(exclude_array(tmp,0,1),""); }
      oldnum = num;
      num = num + strlen(borg);
      if(num>x) {
        boop = boop + borg[0..x-oldnum-1];
        num = x;
      } else {
        boop = boop + borg;
        if(i==2) 
	{
        oldnum = num;
        num = num + strlen(blod);
        boop = boop + "%^";
          	if(num>x)
		{
            	boop = boop + blod[0..x-oldnum-1];
            	num = x;
          	} 
		else
            	boop = boop + blod;
        }
        if(i==3)
          boop = boop + "%^" + blod + "%^";
      }
    }    
  }
  if(num<total) 
	{
	i = num - 1;
	while(i <= total)
		{
		boop += " ";
		i++;
		}
	}
/*
    for(i = num;i < total;i++) 
      boop += " ";
Had to remove this bad boy, it's not working, need to figure out another way to add the extra spaces on the end
nice, it was going over it's range...
*/
return boop;
}


