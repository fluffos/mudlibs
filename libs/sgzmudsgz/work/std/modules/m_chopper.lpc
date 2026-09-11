// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

// You must inherit M_INPUT for this stuff to work.
void modal_push(function,mixed);
void modal_pop();
void modal_pass(string);
void do_chopping(object);

private void answer_question(string input)
{
  object o;

  if(!stringp(input))
    {
      modal_pop();
      return;
    }
  if(o = present(input, environment(this_body())))
    do_chopping(o);
  else
    modal_pass(input);
  modal_pop();
}

void do_chopping(object arg)
{
  object * o;


  if(!arg)
    {
      o = filter(all_inventory(environment(this_body())), 
                 (: $1->is_choppable() :));
      switch(sizeof(o))
        {
        case 0:
          //write("There is nothing in which to chop here.\n");
          write("这里没有什么东西好砍的。\n");      
          return;
        case 1:
          printf("[in %s]\n",o[0]->short());
          arg = o[0];
          break;
        default:
          modal_push((:answer_question:),
                                  //"What do you want to chop in? "
                                  "你要砍什么？");
          return;
        }
    }
  arg->chop();
}
      
      
int can_chop()
{
  return 1;
}

int can_chop_with_obj()
{
  return 1;
}

int direct_chop_with_obj()
{
  return 1;
}


int indirect_chop_obj_with_obj()
{
  return 1;
}

int indirect_chop_in_obj_with_obj()
{
  return 1;
}

int indirect_chop_up_obj_with_obj()
{
  return 1;
}

int indirect_chop_out_obj_with_obj()
{
  return 1;
}

int direct_chop_with_obj_in_obj()
{
  return 1;
}