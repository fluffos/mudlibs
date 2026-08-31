inherit INDOOR_ROOM;

int stage = 0;
int pause = 10;
object body;

void something_arrived();

void setup()
{
   TBUG(base_name(__FILE__));
   set_area("omega_terminal", "living quarters");
   set_brief("A small recovery room");
   set_long("Despite its worn and dirty appearance, the room still manages to exude a sense of faded "
            "functionality. It served its purpose in the past, but time and neglect have taken their toll, "
            "leaving behind a somber reminder of better days. It becomes clear that you have arrived in "
            "a space station that has seen better times, a place where the hustle and bustle "
            "of daily operations has been replaced by an atmosphere of decay and abandonment.\n"
            "A rusty cabinet stands along the wall, and a simple metal door to the south leads out of here.");
   add_hook("object_arrived", ( : something_arrived:));
}

void tr(string s)
{
   tell_from_inside(this_object(), "\n     " + s + "\n\n");
}

void setup_room(int virtual)
{
   if (virtual && !present("rusty_cabinet"))
   {
      set_light(0); // Dark when people arrive.
      set_objects((["^common/item/door":({"south", "^omega/room/floor1/n_hall"}), "^common/item/rusty_cabinet":1]));
      // Add cabinet that can be open with some stuff inside.
      present("door")->set_locked("metal_door");
   }
   else if (!virtual && !present("rusty_cabinet"))
   {
      set_light(1);
      set_objects((["^common/item/door":({"south", "^omega/room/floor1/n_hall"}),
           "^common/item/rusty_cabinet":1, "^omega/npc/floor1/doc_green":1]));
      present("door")->set_locked(0);
   }
}

void create_cabinet()
{
   object s;

   s = new (COINS, (random(5) + 5), "credit");
   s->move(present("cabinet"));
   s = new ("/domains/omega/armour/bomber_jacket");
   TBUG("creating jacket");
   s->move(present("cabinet"));
}

void play_script()
{
   object tmp;
   if (!body)
      return;
   switch (stage)
   {
   case 0:
      tr("As you regain consciousness, your eyes flutter open to reveal a worn and dirty recovery room within "
         "a space station. The room is dimly lit, with flickering fluorescent lights casting eerie shadows "
         "on the cracked and stained walls. The air carries a stale odor, a mix of metallic tang and an "
         "underlying scent of mildew.");
      create_cabinet();
      set_smell("The air carries a stale odor, a mix of metallic tang and an "
                "underlying scent of mildew.");
      add_item("lights",
               (["adjs":({"flickering", "flourescent"}),
                   "look":"There are only dim lights here, and it occurs to you that they might be turned down to "
                          "protect your eyesight."]));
      add_item("walls", (["adjs":({"stained"}), "look":"You feel sick."]));

      break;
   case 1:
      set_light(1);
      add_item("cabinets", (["adjs":({"rusty"}), "look":"There is only one cabinet here?"]));
      break;
   case 2:
      tr("The floor beneath you is covered in a worn, faded blue linoleum, marred with scuff marks and stains "
         "that bear witness to years of neglect. The corners of the room gather dust and cobwebs, suggesting "
         "a lack of regular maintenance. The metal cabinet lining the wall show signs of rust and wear, "
         "their once-shiny surfaces now dull and pockmarked.");
      add_item("floor", "linoleum", "marks", "stains",
               (["adjs":({"blue", "faded", "scuffed"}), "look":"The floor has seen better days."]));
      add_item("cobwebs", (["adjs":({"dusty"}), "look":"The are spiders in space, who would have thunk."]));
      break;
   case 3:
      tr("The recovery bed you lie on is old and creaks as you shift your weight. Its thin, tattered mattress provides "
         "little comfort, and the faded sheets bear remnants of past patients—stains that have resisted countless "
         "attempts at removal. The nearby medical equipment appears outdated and old.");
      add_item("bed", (["adjs":({"recovery", "old"}),
                          "look":"Wonder how long you've lied on this bed ... the sheets seems to indicate that it has "
                                 "been a while. If those are your stains."]));
      add_item("equipment", "syringes",
               (["adjs":({"medical"}),
                   "look":"The medical equipment seems forgotten here, buttons faded and labels peeling "
                          "off, yet still functioning with a faint hum of life."]));

      break;
   case 4:
      tr("Small cracks run along the transparent viewport that overlooks the vast expanse of space outside. The glass "
         "is smudged with grime, obscuring the view and further accentuating the neglect that pervades the room. A few "
         "flickering monitors display outdated data, their screens covered in a thin layer of dust, implying their "
         "infrequent use.");
      add_item("cracks",
               (["adjs":({"small"}), "look":"They seem to have been here for a while. No immediate danger it seems."]));
      add_item("glass", (["adjs":({"smudged"}), "look":"Wonder what that is?"]));
      add_item("monitors", "screens",
               (["adjs":({"flickering"}),
                   "look":"The green light from the monitors hurt your eyes, you quickly look away."]));

      break;
   case 5:
      tr("As you sit up, the chair beside the bed groans under the weight of accumulated dirt and wear. A table "
         "covered in discarded medical supplies sits nearby, a jumble of used syringes, crumpled papers, and "
         "half-empty bottles, hinting at a hurried and disorganized environment.");
      add_item("bottles", "supplies",
               (["adjs":({"medical"}),
                   "look":"Seems like disorganized old medicine bottles, all empty after injections (?)."]));
      add_item("chair", "dirt", "dust", "table", (["look":"Typical office furniture, but covered in dust."]));
      add_item(
          "papers",
          (["adjs":({"medical"}),
              "look":"If you can get your eyes to focus, you might be able to read them.",
              "read":"They seem to be notes on a patient described as 'Spacefarer " + (random(10000) + 100) +
                     "A', someone who arrived at this station unconsciously on a transport ship without papers. The "
                     "person seemed to be suffering from various infections and had bites as if from small creatures "
                     "all over the body.\nA list of several medications are listed including times of injection."]));

      break;
   case 6:
      tr("The door opens and a tall man enters, and sits down in the chair.");
      tmp = new ("/domains/omega/npc/floor1/virtual_doc_green");
      tmp->move(this_object());
      break;
   case 7:
      present("doc_green")->do_game_command("say Glad to see you're finally awake.");
      present("doc_green")->do_game_command("smile slightly");
      break;
   }
   if (stage < 8)
   {
      stage++;
      call_out("play_script", pause + random(3));
   }
}

// Useful for testing in the non-virtual version of this room.
void start_at(int s)
{
   set_light(1);       // Turn on the light.
   stage = s;          // Skip to stage
   body = this_body(); // Set body to whoever did this
   pause = 0;          // Skip pauses entirely.
   play_script();      // Play script
}

void something_arrived()
{
   setup_room(virtualp(this_object()));
   if (!virtualp(this_object()))
   {
      return;
   }
   body = filter(all_inventory(), ( : $1->is_body() :));
   if (!stage && body && find_call_out("play_script") == -1)
   {
      call_out("play_script", 3);
   }
}

object virtual_create(string args)
{
   object room = new (__FILE__);
   return room;
}

string *query_hint(int lvl)
{
   return virtualp(this_object()) ? ({
                                        "Hints appear as you move from room to room. They will change as you level up.",
                                        "Try 'inventory or 'i' and 'look at token' as a start.",
                                    })
                                  : 0;
}