/*
 * heatable.c - a first attempt at a transient object that reacts to heat
 */

inherit "/obj/reagents/transient";

// phase is a two-element array. Each element is of the form:
//     ({ (int) temp, (string) final, (string) result,
//        (string) result_alias, (float) result_amt, (mixed) progress_msg })
// where tempi is the temp at which the change occurs; the other parameters
// are the same as for a normal transient.
// The first element is for the lower temp, and the second is for the
// higher temp.
//
// Currently, progress messages aren't supported.

mixed phase;
float tau = 100.0;
int last_T, last_time = 0, last_idx = -1;
int tot_heat;

void set_phase(mixed p) { phase = p; }
mixed query_phase() { return phase; }
void set_tau(float t) { tau = t; }
float query_tau() { return tau; }
int query_tot_heat() { return tot_heat; }

void start_reaction() {
    // This does nothing if called from outside
    return;
}

void init_heat(int h) {
    last_T = h;
    last_time = time();
    tell_object(find_player("jeremy"), file_name(this_object()) + 
                ": in init_heat("+h+","+last_time+")...\n");
}

object morph() {
    object ob;
    int idx;

    idx = last_idx;
    ob = ::morph();
    ob->init_heat(phase[idx][0]);
    ob->apply_heat(0);
    return ob;
}

void apply_heat(int heat) {
    int T0, T1, dt, idx;

    // This is the best way I could think of to initialize it...
    // It implies that the phase-change temp of the "parent" object
    // should be between the extremes of this one.
    tell_object(find_player("jeremy"), file_name(this_object()) + 
                ": last_time = " + last_time + "\n");
//    if (!last_time) {
//        tell_object(find_player("jeremy"), file_name(this_object()) + 
//                    ": initializing to "+heat+"...\n");
//        tot_heat = heat;
//        last_T = heat;
//        last_time = time();
//        return;
//    }
    //if (!heat) return;
    tot_heat += heat;
    if (phase[0] && (tot_heat <= phase[0][0]))
      idx = 0;
    else if (phase[1] && (tot_heat >= phase[1][0]))
      idx = 1;
    else
      idx = -1;
    stop_reaction();
    printf("lt-t()=%d,nth=%d,lT=%d\n", last_time-time(), tot_heat,
           last_T);
    T0 = to_int((1.0 - exp((last_time-time())/tau))
                * (tot_heat - heat - last_T) + last_T);
    if (idx >= 0 ) {
        T1 = phase[idx][0];
        dt = to_int(tau * log((to_float(tot_heat) - T0)
                              / (to_float(tot_heat) - T1)) + 0.5);
        if (idx != last_idx) {
            set_final(phase[idx][1]);
            set_result(phase[idx][2]);
            set_result_alias(phase[idx][3]);
            set_result_amt(phase[idx][4]);
            set_progress_msg(phase[idx][5]);
        }
        set_duration(dt);
        restart_reaction();
    }
    printf("dt = %d, T0 = %d, T1 = %d, tau = %f, phase_idx = %O\n",
           dt, T0, T1, tau, idx);
    last_T = T0;
    last_time = time();
    last_idx = idx;
}

mapping int_query_static_auto_load() {
   return ([
      "::": ::int_query_static_auto_load(),
   ]);
} /* int_query_static_auto_load() */

mapping query_static_auto_load() {
   if ( file_name( this_object() )[ 0 .. 21 ] == "/obj/reagents/heatable" )
      return int_query_static_auto_load();
   return 0;
} /* query_static_auto_load() */

void init_static_arg( mapping map ) {
   if ( map[ "::" ] )
      ::init_static_arg( map[ "::" ] );
} /* init_static_arg() */
