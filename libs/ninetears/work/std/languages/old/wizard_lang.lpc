/*
 * used for wizard spells...
 * Spider writing (poke sean)
 */

string garble_text(mixed *text) {
  string bing;

/* Handle special effects...  Like blowing up :) */
  if ((bing = (string)text[0]->garble_text(text)))
    return bing;
  return "some spidery writing";
} /* garble_text() */

string magical_text(mixed *text) {
  string bing;

  if ((bing = (string)text[0]->magic_text(text)))
    return bing;
  return "The spell "+text[1]+" seems to be written here in spidery writing.\n";
} /* magical_text() */
