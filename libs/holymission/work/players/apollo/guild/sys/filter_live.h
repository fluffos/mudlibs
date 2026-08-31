

/* filter live  (c) Whisky
   This kfun can use only the object ob, or the object ob combined with
   the string what. It can be used with only ob as: filter_live(this_object())
   for example and returns the amount of livings in the this_object(). Used as
   filter_live(this_object(),"wolf") for example, it returns the amount
   of wolves (name == wolf) in the this_object().

   EXAMPLES:
          if (filter_live(this_object()) < 3)
              move_object(clone_object(filename),this_object());
     or
          if (filter_live(this_object(),"wolf") < 3)
              move_object(clone_object(filename),this_object());
                                                                   */
       
    
varargs int filter_live(object ob, string what)
{
  int i, j, sz;
  object *inv;
  mixed co, lv;

  co = (: call_other :);
  lv = (: living :);
      
  if (!first_inventory(ob)) return 0;

     inv = all_inventory(ob);
     sz =0;
     
     for (j=sizeof(inv), i = 0; i < j; i++)
     {
       if (evaluate(lv,inv[i]))
       {
          if (!what)
              sz++;
          else if (evaluate(co,inv[i],"id",what))
              sz++;
        }
     }
     return sz;
}
