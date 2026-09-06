/*--------------------------------------------------------------------------
 * /p/daemons/country.c  --  Convert IP numbers into meaningful names.
 *
 * Copyright (C) 1992-1997 by Nightfall.
 * Copyright (C) 1997-1998 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *
 * The domain information stems from the Internic, RIPE and APNIC databases.
 * Commercial use of this information is prohibited by these organizations.
 *--------------------------------------------------------------------------
 * The daemon keeps a list of ip-address/name relations in
 * country/country.list (LIST_FILE). To speed up lookups, it uses a hash
 * file country/country.hash. On every load or every reset(), the dates
 * of the two files are checked, and if necessary, the hash file is
 * recreated.
 * The LIST_FILE is evaluated line by line, each line describing one entry.
 * The format of a line is: <ip-number> : <city>, <country>.
 * Empty lines and lines starting with # are ignored.
 * The <ip-address> may be of these formats:
 *   aaa.bbb.ccc.ddd
 *   aaa.bbb.ccc.ddd/ee   with ee the number of msbits to match.
 *   aaa.bbb.ccc.ddd-eee  yielding a range of addresses.
 * The trailing octets may be omitted to cover whole classes.
 *
 * Though usually the namelookup is done using the ip-address, the daemon
 * is able to recognize certain name patterns, as defined in
 * country/*_country.h and country/*_domains.h.
 *--------------------------------------------------------------------------
 * The initial entries of the data file were contributed by Helenette, a lot
 * of people looked up the others.
 * Hyp wrote the original object, Deepthought added many extensions.
 *--------------------------------------------------------------------------
 */

#include <daemons.h>

#include "country/country_german.h"
#include "country/country_domains.h"

#define HASH_FILE DAEMONPATH "country/country.hash"
#define LIST_FILE DAEMONPATH "country/country.list"
#define HASH_SIZE 499

private void CreateHashFile();                      // forward
public varargs string country(mixed ip, int flag);  // forward

private mapping cache = ([]);

/*-------------------------------------------------------------------------*/
public void create()

/* Create a new hash_file if necessary. */

{
  seteuid(getuid());
  if (file_date(HASH_FILE) < file_date(LIST_FILE))
    CreateHashFile();
}

public void reset()

/* Create a new hash_file if necessary. */

{
  if (file_date(HASH_FILE) < file_date(LIST_FILE))
    CreateHashFile();
}

public int clean_up (int ref)
{
  return destruct(this_object()) && 0;
}

/*-------------------------------------------------------------------------*/
public int hash(int x) {
  return (x & 0x7fffffff) % HASH_SIZE;
}

/*-------------------------------------------------------------------------*/
public int inet_addr(string ipnum) {
  int a, b, c, d;

  sscanf(ipnum, "%d.%d.%d.%d", a, b, c, d);
  return (a << 24) | (b << 16) | (c << 8) | d;
}

/*-------------------------------------------------------------------------*/
private mixed *checkrange(int a, int b, int bits)
{
  int d;
  int na;
  int nb;
  mixed *range;

  range = ({});
  d = (1 << (8-bits));
  na = ((a+d-1) / d) * d;
  nb = (b+1) / d * d - 1;

  if (a > b)
    return range;

  if (na <= nb) {
    //log_file("COUNTRY", sprintf("subnet %d..%d/%d\n", na, nb, bits));
    range = ({ ({ na, bits }) });
    if (a < na)
      range += checkrange(a, na-1, bits);
    if (nb < b)
      range += checkrange(nb+1, b, bits);
  }
  else {
    if (na <= b) {
      range += checkrange(a, na-1, bits+1);
      range += checkrange(na, b, bits+1);
    }
    else {
      range += checkrange(a, b, bits+1);
    }
  }
  return range;
}

/*-------------------------------------------------------------------------*/
private void CreateHashFile()
{
  string lfile, *hfile, ipnum, city, country;
  int s, h, addr;
  int netbits;
  string *parts;

  //log_file("COUNTRY", "Creating hash\n");
  hfile = map(allocate(HASH_SIZE), lambda(0, ""));
  s = 1;
  while (lfile = read_file(LIST_FILE, s, 1)) {
    if (catch(lfile = explode(lfile, "\n")[0])) {
      log_file("UNRESOLVED",sprintf("error in explode |%s|\n", lfile));
    }
    ++s;
    if (lfile == "" || lfile[0] == '#')
      continue;
    if (3 != sscanf(lfile, "%s: %s, %s", ipnum, city, country)) {
      log_file("UNRESOLVED", sprintf("Error in country.list, line %d\n", s-1));
      continue;
    }
    parts = explode(ipnum, "/");
    if (sizeof(parts) == 2) {
      ipnum = parts[0];
      netbits = to_int(parts[1]);
      h = hash(addr = inet_addr(ipnum));
      hfile[h] = sprintf("%s%08x/%d:%s, %s#", hfile[h], addr, netbits, city, country);
    }
    else {
      parts = explode(ipnum, "-");
      if (sizeof(parts) == 2) {
        int ip1;
        int ip2;
        mixed *ranges;
        int i;

        ip2 = to_int(parts[1]);
        parts = explode(parts[0], ".");
        ip1 = to_int(parts[<1]);
        ipnum = implode(parts[0..<2], ".");
        netbits = 8 * (sizeof(parts) - 1);
        ranges = checkrange(ip1, ip2, 0);

        for (i = sizeof(ranges); i--; ) {
          h = hash(addr = inet_addr(sprintf("%s.%d", ipnum, ranges[i][0])));
          hfile[h] = sprintf("%s%08x/%d:%s, %s#", hfile[h],
              addr, netbits+ranges[i][1], city, country);
        }
      }
      else {
        netbits = 8 * sizeof(explode(ipnum, "."));
        h = hash(addr = inet_addr(ipnum));
        hfile[h] = sprintf("%s%08x/%d:%s, %s#", hfile[h], addr, netbits, city, country);
      }
    }
    h = hash(addr = inet_addr(ipnum));
    hfile[h] = sprintf("%s%08x/%d:%s, %s#", hfile[h], addr, netbits, city, country);
  }
  rm(HASH_FILE);
  write_file(HASH_FILE, implode(hfile, "\n"));
}

/*-------------------------------------------------------------------------*/
// FUNCTION: ModifyCity()
// DESCRIPTION:
//   Maps names like "uni-tuebingen", which are combined from a
//   prefix and a city name to the city name and handles special
//   cases.
private string ModifyCity(string pre, string name)
{
  if(!name)
    return 0;
  if(name[0..sizeof(pre)-1] == pre)
    name = name[sizeof(pre)..];
  else return 0;
  switch(name) {
    // Special kind of spelling
  case "frankfurt":
    name = "Frankfurt/Main";
    break;
  case "frankfurt-o":
    name = "Frankfurt/Oder";
    break;
  case "muenchen":
    name = "Munich (Muenchen)";
    break;
  case "koeln":
    name = "Cologne (Koeln)";
  }
  return capitalize(name);
}


/*-------------------------------------------------------------------------*/
/*
 * LookupCityFromNumber()
 *
 * internal function which gets City and Country from the country file.
 */
public string LookupCityFromNumber(string ip_number)
{
  int numeric_ip_address;
  int mask, pos;
  string str, key;
  int netbits;

  if (find_call_out("CreateHashFile") < 0
   && file_date(HASH_FILE) < file_date(LIST_FILE))
    call_out("CreateHashFile", 2);

  numeric_ip_address = inet_addr(ip_number);
  if (!numeric_ip_address)
    return 0;

  if (str = cache[numeric_ip_address])
    return str == "---" ? 0 : str;

  netbits = 32;
  mask = -1;
  do {
    str = read_file(HASH_FILE, hash(numeric_ip_address & mask) + 1, 1);
    key = sprintf("%08x/%d:", numeric_ip_address & mask, netbits);
    if ((pos = strstr(str, key)) >= 0) {
      pos += sizeof(key);
      str = str[pos..member(str[pos..], '#') - 1 + pos];
      return cache[numeric_ip_address] = str;
    }
  } while ((--netbits >= 8) && (mask <<= 1));

  log_file("UNRESOLVED", ctime(time()) + " ipnumber= "
           + ip_number + "\n");

  cache[numeric_ip_address] = "---";
  return 0;
}

/*-------------------------------------------------------------------------*/
/*
 * Lookup from a complete domainname.
 *
 * returns "City, Country" if useful, 0 otherwise.
 */
public string LookupCityFromName(string ip_name)
{
  string *parts;
  string str;
  string *country;
  string *parts2;

  if (find_call_out("CreateHashFile") < 0
   && file_date(HASH_FILE) < file_date(LIST_FILE))
    call_out("CreateHashFile", 2);

  ip_name = lower_case(ip_name);
  parts = explode(ip_name, ".");
  switch (parts[<1]) {
    case "com":
    case "net":
      if (sizeof(parts) > 6 && parts[<2] == "uu" && parts[<3] == "ms")
        return capitalize(parts[<5]) + " " + upper_case(parts[<4]) + ", USA";
      if (sizeof(parts) > 5 && parts[<2] == "att" && parts[<3] == "dial-access") {
        parts2 = explode(parts[<5], "-");
        if (sizeof(parts2) > 1) {
          parts2 = map(parts2[0..<2], #'capitalize /*'*/);
          return implode(parts2, "-") + " " + upper_case(parts[<4]) + ", USA";
        }
      }
      return 0;
    case "org":
    case "gov":
    case "mil":
    case "edu":
      return 0;
    case "de":
      if (str = KNOWN_NAMES_DE[parts[<2]])
        return str;
      if (sizeof(parts) > 2 && parts[<2] == "netsurf")
        return capitalize(parts[<3]) + ", Germany";
      if(sizeof(parts) > 2 && parts[<2] == "fh-rpl")
        return capitalize(parts[<3]) + ", Germany";
      country = map(PREFIXES_DE, #'ModifyCity /*'*/, parts[<2]) - ({0});
      if (sizeof(country))
        return country[0] + ", Germany";
      return 0;
    default:
      return 0;
  }
  return 0;
}

/*-------------------------------------------------------------------------*/
public string LookupCountryFromName(string ip_name)
{
  string str;
  string *parts;

  ip_name = lower_case(ip_name);
  parts = explode(ip_name, ".");
  switch (parts[<1]) {
    case "com":
    case "net":
    case "org":
      return 0;
    case "mil":
    case "gov":
    case "edu":
      return "USA";
    default:
      str = GetCountryMapping()[parts[<1]];
      return str ? str : 0;
  }
  return 0;
}


/*-------------------------------------------------------------------------*/
/*
 * GetCountry()
 *
 * return "City, Country" from object or numeric ip address
 * if flag == 1, return "Country" if flag == 0.
 * ip can be a object, array or string.
 * if ip is a array, the first element gives the ipnumber, the second
 * the ipname.
 */
public varargs string GetCountry(mixed ip, int flag)
{
  string str;
  string ipnumber;
  string ipname;
  string country;
  int isdemon;

  if(!ip)
    return "Unknown";

  isdemon = 0;

  if (objectp(ip)) {
    ipnumber = query_ip_number(ip);
    ipname = query_ip_name(ip);
    // we don't want failed logins or www-requests to clutter the country.list
    if (({int})ip->IsServiceDemon())
      isdemon = 1;
  }
  else if (pointerp(ip)) {
    ipnumber = ip[0];
    ipname = ip[1];
  }
  else {
    ipnumber = ipname = ip;
  }
  if (!ipnumber)
    return "Unknown";

  if (flag) {
    // Lookup from name is preferred
    if (str = LookupCityFromName(ipname))
      return str;

    if (!isdemon) {
      if (str = LookupCityFromNumber(ipnumber))
        return str;
    }

    str = LookupCountryFromName(ipname);
      return str ? str : "Unknown";
  }
  else {
    if (str = LookupCountryFromName(ipname))
      return str;

    if (!(str = LookupCityFromName(ipname))) {
      if (isdemon || !(str = LookupCityFromNumber(ipnumber))) {
        return "Unknown";
      }
    }
    sscanf(str, "%~s, %s", country);
    return country ? country : "Unknown";
  }
}

/***************************************************************************/
