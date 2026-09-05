/* 05/15/06 Earwax:  moved this from player.c for security and 
 * efficiency reasons.  Also made it so it only checks the ips for
 * a given wiz, rather than shooting through each of them for every
 * wiz of over 999.
 */

status check(string myip, string name) {
  string ajunk, bjunk;

  /* Boltar's numbers */
  if (name == "boltar" || name == "zeotide") {
/*
    if(sscanf(myip, "%s92.41.245%s",ajunk,bjunk) !=2)
    if(sscanf(myip, "198.77.7%s",bjunk) !=1)
    if(sscanf(myip, "24.1.2.%s",bjunk) !=1)
    if(sscanf(myip, "206.245.158%s",bjunk) !=1)
    if(sscanf(myip, "24.12.247%s",bjunk) !=1)
    if(sscanf(myip, "216.47.143%s",bjunk) !=1)
    if(sscanf(myip, "24.1.3%s",bjunk) !=1)
    if(sscanf(myip, "12.213.3%s",bjunk) !=1)
*/
    if(sscanf(myip, "98.206.22%s",bjunk) !=1)
    if(sscanf(myip, "64.53.%s",bjunk) !=1)
    if(sscanf(myip, "206.71.152%s",bjunk) !=1)
    if(sscanf(myip, "127.0.0.%s",bjunk) !=1)
      return 0;
    return 1;
  }
    /* Sandman's numbers */
/*
  if (name == "sandman") {
    if(sscanf(myip, "68.69.%s",ajunk) !=1)
    if(sscanf(myip, "141.153.%s",ajunk) !=1)
    if(sscanf(myip, "151.205%s",ajunk) !=1)
    if(sscanf(myip, "66.118.%s",bjunk) !=1)
      return 0;
    return 1;
  }
*/
  if (name == "rumplemintz") {
    return 1;  /* My home ip seems random everyday, damn Qwest - Rump */
/*
    if(sscanf(myip,"174.30.%s.%s",bjunk) !=1)
     if(sscanf(myip, "74.112.%s.%s",ajunk) != 1)
     if (sscanf(myip, "71.32.%s.%s",ajunk,bjunk) != 2)
     if(sscanf(myip, "69.170.%s.%s",ajunk) != 1)
     if(sscanf(myip, "174.137.154.%s", ajunk) != 1)
     if (sscanf(myip, "127.0.0.%s", ajunk) != 1)
     if (sscanf(myip, "67.3.%s.%s", ajunk) != 1)
     if (sscanf(myip, "75.162.%s.%s", ajunk) != 1)
     if(sscanf(myip, "97.125.%s",bjunk) !=1)
       return 0;
     return 1;
*/
   }
/* Added Dragnar - Rumplemintz */
  if (name == "dragnar") {
    return 1;  /* Dynamic IP address - changes daily */
/*
    if (sscanf(myip, "66.67.%s.%s,bjunk) !=1)
      return 0;
    return 1;
*/
  }
  if (name == "forbin") {
   /* forbin's numbers */
    if(sscanf(myip, "24.74.%s.%s",ajunk,bjunk) != 2)
    if(sscanf(myip, "71.75.%s.%s",ajunk,bjunk) != 2)
    if(sscanf(myip, "75.176.%s.%s",ajunk,bjunk) != 2)
    if(sscanf(myip, "74.227.%s.%s",ajunk,bjunk) != 2)
    if(sscanf(myip, "68.221.%s", ajunk) != 1)
      return 0;
    return 1;
  }
  if (name == "vertebraker") {
    /* verte's numbers */
if(sscanf(myip, "74.99.175.%s",ajunk) !=1)
if(sscanf(myip, "174.59.%s.%s",ajunk,bjunk) !=2)
if(sscanf(myip, "71.207.%s",ajunk) !=1)
      return 0;
    return 1;
  }
  if (name == "sparrow") {
    if (sscanf(myip, "96.235.%s.%s",ajunk) !=1)
    if (sscanf(myip, "71.114.%s.%s",ajunk,bjunk) !=2)
    if (sscanf(myip, "71.162.%s.%s",ajunk,bjunk) != 2)
    if (sscanf(myip, "108.22.%s.%s",ajunk,bjunk) !=2)
    if (sscanf(myip, "74.98.%s.%s",ajunk,bjunk) != 2)
    if (sscanf(myip, "71.169.%s.%s",ajunk,bjunk) != 2)
    if (sscanf(myip, "96.233.%s.%s", ajunk,bjunk) !=2)
    if (sscanf(myip, "96.247.%s.%s",ajunk,bjunk) !=2)
      return 0;
  return 1;
}
  if (name == "earwax") {
    /*earwax numbers */
/*
    if(sscanf(myip, "24.12.57.%s",ajunk) != 1)
    if(sscanf(myip, "67.173.87.%s",ajunk) != 1)
*/
   if(sscanf(myip, "67.165.163.%s",ajunk) != 1)
    if(sscanf(myip, "71.194.149.%s",ajunk) != 1)
    if(sscanf(myip, "71.239.132.%s",ajunk) != 1)
    if(sscanf(myip, "67.186.118.%s",ajunk) != 1)
      return 0;
    return 1;
  }
  if (name == "fred") {
    /* Fred's numbers */
    if(sscanf(myip, "156.99.156.%s", ajunk) != 1)
    if(sscanf(myip, "173.19.%s.%s", ajunk, bjunk) != 2)
    if(sscanf(myip, "173.25.%s.%s", ajunk, bjunk) != 2)
    if(sscanf(myip, "173.18.%s.%s", ajunk, bjunk) != 2)
    if(sscanf(myip, "156.99.%s.%s", ajunk,ajunk) != 2)
    if(sscanf(myip, "69.24.%s.%s", ajunk,ajunk) != 2)
    if(sscanf(myip, "216.114.%s", ajunk) != 1)
    if(sscanf(myip, "64.254.%s.%s", ajunk,ajunk) != 2)
      return 0;
    return 1;
  }
  if (name == "illarion") {
    /* Illarion's numbers */
    if(sscanf(myip, "68.84.80.%s", ajunk) != 1)
    if(sscanf(myip, "50.147.%s.%s", ajunk, bjunk) != 2)
    if(sscanf(myip, "71.80.34.%s", ajunk) != 1)
    if(sscanf(myip, "67.187.%s.%s", ajunk, bjunk) != 2)
    if(sscanf(myip, "76.22.%s.%s", ajunk, bjunk) != 2)
    if(sscanf(myip, "76.123.%s.%s", ajunk, bjunk) != 2)
    if(myip != "54.225.119.99")
      return 0;
    return 1;
  }
  if(name == "mokri") {
    /* Mokri's numbers */
    if(sscanf(myip, "71.227.%s.%s", ajunk,ajunk) != 2)
    if(sscanf(myip,"66.135.%s.%s",ajunk,ajunk) != 2)
    if(sscanf(myip, "70.57.%s.%s", ajunk,ajunk) != 2)
    if(sscanf(myip,"216.160.%s.%s",ajunk,ajunk) != 2)
  return 0;
  return 1;
  }
  if(name == "vital") {
    if(sscanf(myip, "85.154.%s.%s", ajunk, ajunk) != 2)
    if(sscanf(myip, "12.5.%s.%s", ajunk, ajunk) != 2)
    if(sscanf(myip, "62.61.%s.%s", ajunk, ajunk) != 2)
      return 0;
    return 1;
  }
}
