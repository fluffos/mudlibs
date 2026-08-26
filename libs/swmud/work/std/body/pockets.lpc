/*
** Rewrite of old money.c and other stuff by Tsath 2020. This file covers anything can the player carries that
** is converted from objects in the MUD into values in parameters into the player.
*/

#define PERCENT_TO_DROP_WHEN_ENCUMBERED 10
#define PERCENT_TO_TAKE_DMG_ENCUMBERED 10

int query_con();                               // From M_BODYSTATS
varargs float query_capacity(string relation); // From CONTAINER

private
mapping money = ([]);
private
mapping materials = ([]);

mapping query_materials()
{
   if (!mapp(materials))
      materials = ([]);
   return materials;
}

void empty_materials()
{
    materials = ([]);
}

private
int valid_currency(string currency)
{
   return member_array(currency, MONEY_D->query_currency_types()) != -1;
}

//: FUNCTION add_material
// int add_material(mixed m)
// Adds a material (object) to the pouch and detroys it from inventory.
// If m is a string, it's added directly under that ID.
// The function returns 1 on success or 0 on failure.
varargs int add_material(mixed m, int c)
{
   string m_id;
   if (!m)
      return 0;
   if (c <= 0 && stringp(m))
      c = 1;
   if (objectp(m))
   {
      m_id = m->short();
      c = 1;
   }
   else
      m_id = m;
   if (!CRAFTING_D->valid_material(m_id))
      return 0;

   if (materials[m_id])
      materials[m_id] += c;
   else
      materials[m_id] = c;
   if (objectp(m))
      destruct(m);
   return 1;
}

//: FUNCTION has_material
// int has_material(string m, int count)
// Checks for count material from the pouch if available (return 1),
// otherwise return 0. Material could also be in inventory, which is
// also checked.
int has_material(string m, int count)
{
   object ims;
   if (materials[m] >= count)
   {
      return 1;
   }

   ims = filter_array(all_inventory(), ( : $1->id($(m)) && ($1->is_material() || $1->is_junk()) :));
   if (sizeof(ims) >= count)
      return 1;
   return 0;
}

//: FUNCTION remove_material
// int remove_material(string m, int count)
// Removes count material from the pouch if available (return 1),
// otherwise it does nothing (return 0).
int remove_material(string m, int count)
{
   object *ims;

   ims = filter_array(all_inventory(), ( : $1->id($(m)) && ($1->is_material() || $1->is_junk()) :));

   if (sizeof(ims) >= count)
   {
      count--;
      ims = ims[0..count];
      ims->remove();
      return 1;
   }
   else if (sizeof(ims) < count && sizeof(ims))
   {
      return 0;
   }

   if (!CRAFTING_D->valid_material(m))
   {
      map_delete(materials, m);
      return 0;
   }

   if (materials[m] >= count)
   {
      materials[m] -= count;
      if (!materials[m])
         map_delete(materials, m);
      return 1;
   }
   return 0;
}

//: FUNCTION query_amt_money
// This is the functin to call to query the amount of a certain type
// of currency you have.
int query_amt_money(string type)
{
   string currency;
   float factor;
   type = MONEY_D->singular_name(type);
   currency = MONEY_D->query_currency(type);
   factor = MONEY_D->query_factor(type);
   return round(money[currency] / factor);
}

//: FUNCTION query_amt_currency
// This is the functin to call to query the sum of the types of a
// currency you have.
float query_amt_currency(string currency)
{
   float amount = 0.0;
   if (!valid_currency(currency))
      error("Unknown currency '" + currency + "'.");

   currency = MONEY_D->singular_name(currency);
   foreach (string type in MONEY_D->query_denominations(currency))
   {
      amount += to_float(money[type]) * MONEY_D->query_factor(type);
   }
   return amount;
}

//: FUNCTION add_money
// This is the function to call to add money to a person
void add_money(string type, float amount)
{
   string currency;
   float factor;
   type = MONEY_D->singular_name(type);
   currency = MONEY_D->query_currency(type);
   factor = MONEY_D->query_factor(type);
   amount = amount * factor;

   if (!valid_currency(currency))
      error("Unknown currency '" + currency + "'.");

   currency = MONEY_D->singular_name(currency);
   money[currency] = money[currency] + amount;

   if (money[currency] <= 0)
      map_delete(money, currency);
}

//: FUNCTION subtract_money
// This is the function to call to substract money from a person
void subtract_money(string type, int amount)
{
   string currency;
   float factor;
   type = MONEY_D->singular_name(type);
   currency = MONEY_D->query_currency(type);
   factor = MONEY_D->query_factor(type);
   amount = amount * factor;
   add_money(currency, -amount);
}

//: FUNCTION query_currencies
// This function will return the current "types" of money you have
string *query_currencies()
{
   if (!money)
      return ({});

   return keys(money);
}

//: FUNCTION query_money
// This function will return the complete money mapping
mapping query_money()
{
   if (!mapp(money))
      money = ([]);
   return money;
}

/* Override max_capacity from container to make it constitution based */
varargs int query_max_capacity(string relation)
{
   return to_int(query_con() * 4);
}

/* Override max_capacity from container to make it constitution based */

int query_heavy_capacity()
{
   return query_con() * 2;
}

int query_encumbered_capacity()
{
   return query_con();
}

varargs int query_no_move_capacity(string relation)
{
   return to_int(query_max_capacity() * 0.9);
}

void before_move()
{
   if (query_capacity() > query_encumbered_capacity())
   {
      int roll = random(100);
      object *obs = ({});
      foreach (object ob in all_inventory(this_body()))
      {
         if (!ob)
            continue;
         if (environment(ob) != this_body())
            continue;
         if (ob->is_armour() && ob->ob_state())
            continue;
         if (ob->is_weapon() && ob->query_wielded_by() == this_body())
            continue;
         obs += ({ob});
      }
      if (sizeof(obs) && roll < PERCENT_TO_DROP_WHEN_ENCUMBERED)
      {
         object drop_item = choice(obs);
         this_body()->simple_action(
             "$N $vare encumbered, so a $o $v1slip out of $p inventory and $v1drop to the floor.", drop_item);
         drop_item->move(environment(this_object()));
      }
   }

   if (query_capacity() > query_heavy_capacity())
   {
      int roll = random(100);
      if (roll < PERCENT_TO_TAKE_DMG_ENCUMBERED)
      {
         string limb = choice(this_body()->query_limbs() - this_body()->query_non_limbs());
         if (this_body()->is_vital_limb(limb) && this_body()->query_health(limb) > 5)
         {
            this_body()->hurt_us(random(3) + 1, limb);
            this_body()->simple_action("$N $vhurt $p $o transporting so much weight.", limb);
         }
         else
         {
            this_body()->hurt_us(random(3) + 1, limb);
            this_body()->simple_action("$N $vhurt $p $o transporting so much weight.", limb);
         }
      }
   }
}