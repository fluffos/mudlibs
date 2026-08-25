// Updated by stefan on 10 Jan 1997
//updated by row on Dec. 1999
/* Do not remove the headers from this file! see /USAGE for more info. */

// Define a function called dig(obj)  for when obj tries to dig you.
// This module requires that M_atPUT also be inherited.
void modal_wave(function,mixed);
void modal_pop();
void modal_pass(string);

int is_waveable()
{
  return 1;
}

int direct_wave_at_obj()
{
  return 1;
}

int direct_wave_out_obj()
{
  return 1;
}

int direct_wave_up_obj()
{
  return 1;
}

int direct_wave_obj()
{
  return 1;
}

int direct_wave_obj_with_obj()
{
  return 1;
}

int can_wave_at_obj()
{
  return 1;
}

int can_wave_out_obj()
{
  return 1;
}

int can_wave_up_obj()
{
  return 1;
}

int direct_wave_at_obj_with_obj()
{
  return 1;
}

int direct_wave_out_obj_with_obj()
{
  return 1;
}

int direct_wave_up_obj_with_obj()
{
  return 1;
}

int indirect_wave_with_obj_at_obj()
{
  return 1;
}

private void answer_question(string input)
{
  object o;
  
  if(!stringp(input))
    {
      modal_pop();
      return;
    }
  if(o = present(input, environment(this_body())) || 
     o = present(input, this_body()))
    o->do_waveing(this_object());
  else
    modal_pass(input);
  modal_pop();
}

void complete_wave()
{
  object * obs;

  obs = filter(all_inventory(this_body())+all_inventory(environment(this_body())),
               (: $1->can_wave() :));
  
  switch(sizeof(obs))
    {
    case 0:
      //write("You have nothing with which to wave.\n");   
      write("你没有扇的工具。\n");
      return;
    case 1:
          printf(//"[with %s]\n"
                 "[带着 %s]",obs[0]->short());
          obs[0]->do_waveing(this_object());
          return;
    default:
          modal_wave((:answer_question:),
                                  //"What do you want to wave with? "
                                  "你要拿什么来扇呀？");
          return;
    }
}