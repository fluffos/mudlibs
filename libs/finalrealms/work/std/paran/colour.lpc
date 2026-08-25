/* the great colour creation object */

string colours;

create() {
  colours = ({
    "infrared", "IR",
    "grey", "GR",
    "smoke", "SM",
    "silver", "AG",
    "chrome", "CM",
    "white", "W",
    "cream", "CR",
    "salmon", "S",
    "flesh", "FL",
    "pink", "PI",
    "chartreuse", "CH",
    "puce", "PU",
    "rose", "RO",
    "russet", "RS",
    "red", "R",
    "ruby", "RU",
    "magenta", "M",
    "ginger", "GI",
    "burgundy", "BU",
    "scarlet", "SC",
    "carmine", "CA",
    "tangerine", "TA",
    "orange", "O",
    "copper", "CU",
    "brass", "BA",
    "gold", "AU",
    "umber", "UM",
    "amber", "AM",
    "lemon", "LE",
    "yellow", "Y",
    "vanilla", "VA",
    "lime", "LI",
    "olive", "OL",
    "verdegris", "VR",
    "green", "G",
    "jade", "J",
    "emerald", "E",
    "vermillion", "VE",
    "cyan", "C",
    "azure", "AZ",
    "aquamarine", "A",
    "ultramarine", "UL",
    "blue", "B",
    "cadmium", "CD",
    "cobalt", "CO",
    "gunmetal", "GM",
    "indigo", "I",
    "mauve", "MU",
    "purple", "P",
    "turquoise", "T",
    "violet", "V",
    "chocolate", "CH",
    "brown", "BR",
    "ochre", "OC",
    "khaki", "KA",
    "dun", "DU",
    "tan", "TN",
    "mahogany", "MA",
    "sienna", "SI",
    "manilla", "MN",
    "sepia", "SE",
    "obsidian", "OB",
    "ebony", "EB",
    "black", "BL",
    "ultraviolet", "UV",
  });
}

query_colour(level) {
  if (level*2>sizeof(colours))
    return colours[sizeof(colours)-2];
  return colours[level*2];
}

query_sizeof_colours() {
  return sizeof(colours)/2;
}

query_abbreviation(level) {
  if (level*2>sizeof(colours))
    return colours[sizeof(colours)-1];
  return colours[level*2+1];
}

query_sec_colour(str) {
  int i;
  if (!stringp(str))
    return ;
  i = member_array(str,colours);
  if (i<0)
    return -1;
  return i;
}
