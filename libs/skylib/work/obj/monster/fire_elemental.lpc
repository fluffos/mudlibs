/* The fire elemental summoned by the fire elemental ritual
 * heavily influenced by Mithal's monster of the same name
 */

inherit "/obj/monster/controlled_monster";

int whichone( int str) {
   mixed ac_ave,ac_inv,ac_weak;
   string sizedesc;
   int Dam, Hit, Base, Def, Size;

   set_summoned( 1 );

   Size = str;

   if ( Size < 50 )       sizedesc = "really tiny";
   else if ( Size < 100 )  sizedesc = "tiny";
   else if ( Size < 150 )  sizedesc = "small";
   else if ( Size < 200 ) sizedesc = "average sized";
   else if ( Size < 300 ) sizedesc = "large";
   else if ( Size < 400 ) sizedesc = "huge";
   else if ( Size < 500 ) sizedesc = "gigantic";
   else if ( Size < 600 ) sizedesc = "colossal";
   else sizedesc = "unbelievably large";

   set_name( "elemental");
   add_adjective( "fire" );
   //   add_alias( ({ "fire", "", "dust bowl" }) );
   set_long("A swirl of red hot gasses burining with intense heat.  It seems "
      "to be in the shape of " + add_a(sizedesc) + " humanoid\n" );
   set_short( sizedesc +" fire elemental" );
   set_main_plural( sizedesc +" fire elementals" );
   set_leave_msg("$N disappears in a big puff of noxious fumes.\n");
   set_enter_msg("$N appears in a big puff of noxious fumes.\n");

   str /= 10;

   basic_setup("elemental", str, 0 );
   
   if ( ( Dam  = str / 20 ) < 1 ) Dam = 1;
   if ( ( Hit  = str / 40 ) < 1 ) Hit = 1;
   if ( ( Base = str / 40 ) < 1 ) Base = 1;
   if ( ( Def  = str / 10 ) < 1 ) Def = 1;
   
   ac_ave  = ({ Def, Dam });   /** Ac default                        **/ 
   ac_inv  = ({ str, Dam });   /** Ac used if partilally invulerable **/   
   ac_weak = (({ 0,0 }));      /** Ac used if it's a weakness        **/

   call_out( "remove_attack", 2, "standard" );
 
   Dam += Hit + Base;

   add_attack( "fire_elemental_burn", 70,
         ({ Dam, 10, Dam }), "fire", "unarmed", 0 );
   add_attack( "fire_elemental_bake", 20,
         ({ Dam, 20, Dam }), "fire", "unarmed", 0 );
   add_attack( "fire_elemental_flame", 10,
         ({ Dam, 30, Dam }), "fire", "unarmed", 0 );

   add_ac("bing", "blunt", ac_ave);
   add_ac("bing2","sharp", ac_ave);
   add_ac("bing3","pierce",ac_inv);
   add_ac("bing4","fire",  ac_inv);  
   add_ac("bing5","cold",  ac_weak);  
   add_ac("bing6","magic", ac_weak);   

   load_chat(20, ({1,":flickers wildly",
        1,":forms a trident of fire fire",
        1,":looks roasting hot",
        1,":burns the ground around it"}));

  add_attack_message("fire_elemental_burn", "fire",
        ({20, ({ "You attempt to burn $hcname$ with fire.\n",
                 "$mcname$ attempts to burn you.\n",
                 "$mcname$ attempts to burn $hcname$.\n",
              }),
          80, ({ "You lightly sautee $hcname$.\n",
                 "$mcname$ lightly sautees you.\n",
                 "$mcname$ lightly sautees $hcname$.\n",
               }),
          120, ({ "You burn $hcname$.\n",
                 "$mcname$ burns you.\n",
                 "$mcname$ burns $hcname$.\n",
              }),
          200, ({ "You scorch $hcname$.\n",
                 "$mcname$ scorches you.\n",
                 "$mcname$ scorches $hcname$.\n",
               }),
           0, ({ "You toast $hcname$ until $hpron$'s done.\n",
                 "$mcname$ toasts you til you're done.\n",
                 "$mcname$ toasts $hcname$ and sticks a fork in $hobj$.\n",
              }),
        }) );

  add_attack_message("fire_elemental_bake", "fire",
        ({20, ({ "You warm $hcname$ up a bit.\n",
                 "$mcname$ warms you up a bit.\n",
                 "$mcname$ warms $hcname$ up a bit.\n",
              }),
          80, ({ "You slow roast $hcname$.\n",
                 "$mcname$ slow roasts you.\n",
                 "$mcname$ slow roasts $hcname$.\n",
               }),
          160, ({ "You toast $hcname$.\n",
                 "$mcname$ toasts you.\n",
                 "$mcname$ toasts $hcname$.\n",
              }),
          320, ({ "You scorch $hcname$.\n",
                 "$mcname$ scorches you.\n",
                 "$mcname$ scorches $hcname$.\n",
               }),
           0, ({ "You char-broils $hcname$ over an open flame.\n",
                 "$mcname$ char-broils you over an open flame.\n",
                 "$mcname$ char-broils $hcname$ over an open flame.\n",
              }),
        }) );

   add_attack_message("fire_elemental_flame", "unarmed",
        ({20, ({ "You swipe at $hcname$.\n",
                 "$mcname$ swipes at you.\n",
                 "$mcname$ swipes at $hcname$.\n",
              }),
          80, ({ "You slap $hcname$ with a fiery hand .\n",
                 "$mcname$ slaps you with a fiery hand.\n",
                 "$mcname$ slaps $hcname$ with a fiery hand.\n",
               }),
          160, ({ "You throw fire badly scorching $hcname$.\n",
                 "$mcname$ throws fire badly scorching you.\n",
                 "$mcname$ hurls fire badly scorches $hcname$.\n",
               }),
          320, ({ "You cast a stream of fire at $hcname$.\n",
                 "$mcname$ casts a stream of fire at you.\n",
                 "$mcname$ casts a stream of fire at $hcname$.\n",
              }),
           0, ({ "You hurl fire at $hcname$ burning $hobj$ to a cinder.\n",
                 "$mcname$ hurls fire at you burning you to a cinder.\n",
                 "$mcname$ hurls fire at $hcname$ burning $hobj$ to a cinder.\n",
              }),
        }) );
} /* whichone() */
   
