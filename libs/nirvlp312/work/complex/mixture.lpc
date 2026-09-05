/*
 * complex/mixture.c by Alfe for Tubmud 2002-Apr-22
 *
 * mixtures consisting of ingredients.
 * can be powders or liquids.
 */

#include <is_wizard.h>
#include <libs.h>

inherit "basic/math";
inherit "complex/item";

private mapping ingredients;

mapping query_ingredients() {
  return ingredients || ([]);
}

void optimize_ingredients_mapping(mapping m) {
  int gcd, i, j;
  if (sizeof(m) > 1) {
    gcd = gcd_n(m_values(m));
    m = map(m, lambda(({ 'ingredient, 'amount }),
                      ({ (#'/), 'amount, gcd })));
  }
  // lower all values to avoid overflows
  i = max(m_values(m));
  if (i > 0x1000)  // maybe 0x1000 (4096) is too low?
    for (j=1; ; j++)
      if (i >> j <= 0x1000) {
        m = map(m, lambda(({ 'ingredient, 'amount }),
                          ({ (#'>>), 'amount, j })));
        // we will leave all the 0 entries in the mapping to keep the
        // information that there are traces of this ingredient in there.
        return;
      }
}

void set_ingredients(mapping ing) {
  ingredients = ing;
  optimize_ingredients_mapping(&ingredients);
}

void add_ingredient(object new_ingredient) {
  mapping new_ingredients, old_ingredients;
  int old_sum, new_sum;  // the sums are also the dividers of the fractions
  int old_mass, new_mass;
  int a, b;
  new_ingredients = new_ingredient->query_ingredients();
  if (!new_ingredients)
    raise_error("Bad ingredient to be added\n");
  old_ingredients = ingredients;
  old_sum = fold_left(#'+, m_values(old_ingredients), 0);
  new_sum = fold_left(#'+, m_values(new_ingredients), 0);
  old_mass = get_mass(this_object());
  new_mass = get_mass(new_ingredient);
  ingredients = ([]);
  a = new_sum * old_mass;
  b = old_sum * new_mass;
  // the following will help to keep the numbers as small as possible
  reduce_fraction(&a, &b);
  // the following will also add a little error, but i fear to reach maxint
  while (a > 0x100 && b > 0x100)
    a >>= 1, b >>= 1;
  foreach (string ingredient, int amount : old_ingredients)
    ingredients[ingredient] += amount * a;
  foreach (string ingredient, int amount : new_ingredients)
    ingredients[ingredient] += amount * b;
  optimize_ingredients_mapping(&ingredients);
  set_encumbrance(new_mass + old_mass);
  destruct(new_ingredient);
}

private string mixture_long;

void set_mixture_long(string s) { mixture_long = s; }
string query_mixture_long() { return funcall(mixture_long); }

private string get_mixture_long() {
  string result;
  result = query_mixture_long();
  if (is_wizard(this_player(), IW_TOOLUSER))
    result += sprintf("%O\n", query_ingredients());
  return result;
}

void configure() {
  item::configure();
  set_id("mixture");
  set_short("a mixture");
  set_mixture_long("This is a mixture.\n");
  set_long(#'get_mixture_long);
}

string query_smell() { return LIB_INGREDIENT->compute_smell(this_object()); }
string query_taste() { return LIB_INGREDIENT->compute_taste(this_object()); }
