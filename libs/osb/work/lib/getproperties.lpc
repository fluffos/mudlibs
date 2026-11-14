/* This file returns an array of all aviable properties defined in
 * /sys/properties.h */

mixed *get_properties()
{
  string *properties;
  string *dummy;
  mixed  *proplist;
  int    i;

  proplist = ({({}),({})});
  properties = explode(read_file("/sys/properties.h"),"\n");
  properties = regexp(properties,"^#define.*P_");
  for(i = 0; i < sizeof(properties); i++) {
    dummy = explode(properties[i]," ") - ({""});
    proplist = insert_alist(dummy[1],implode(dummy[2..]," ")[1..<2],proplist);
  }
  return proplist;
}
