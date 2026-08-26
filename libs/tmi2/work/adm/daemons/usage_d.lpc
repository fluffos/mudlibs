#pragma save_binary
// usage_d.c
// Keeps a running track of how much the MUD has been used in the
// last 24 hours. Make fancy displays if asked to do so.
// Mobydick, 6-6-93
// Pallando, 94-04-25, changed mixed *data to float *data to fix indexing bug
// The idea is not mine, I saw something very similar to this on another
// MUD. But I can't remember where, or when... so I cannot track down
// the original author to give credit. Whoever it was, that author's
// work is gratefully acknowledged.
// This version of it was coded from scratch.

// Every CALL_TIME, the daemon collects the various information that
// it tracks and adds it to a running total.  For AVERAGING_NUM number of
// times, it computes the average usage and stores it in the history
// array. TRACK_NUM is the length of the history array. HEIGHT is the height
// of the resulting graph, in screen lines.

// Since samples are taken at the end of CALL_TIME intervals, a better sample
// uses midpoint averaging.  For TRACK_NUM = 12:
//
//  avg = [ (a0 + a1)/2 + (a1 + a2)/2 + ... + (a11 + a12)/2 ] / 12

#include <config.h>
#define CALL_TIME 600
#define AVERAGING_NUM 12
#define TRACK_NUM 20
#define HEIGHT 14.0

// Currently tracking number of users, memory and CPU use, and number
// of objects loaded.

int obs, users, memory, lastobs, lastusers, lastmem;
float cpu, lastcpu;
float times;
float *pastobs, *pastusers, *pastmem, *pastcpu;
int counter;

// At create time, start the call_out loop.

void create() {
    mapping r;

    return;

    memory = memory_info() / 1000;
    users = sizeof(users());
// rusage() not available everywhere. If you really
// really need it, figure it out.
#if 0
    r = rusage();
#endif
    cpu = (r["utime"] + r["stime"]) / ( uptime() + 1 ) / 10.0;
    obs = sizeof(objects());

    pastobs = allocate(TRACK_NUM);
    pastusers = allocate(TRACK_NUM);
    pastmem = allocate(TRACK_NUM);
    pastcpu = allocate(TRACK_NUM);

    pastmem[counter] = memory;
    pastusers[counter] = users;
    pastobs[counter] = obs;
    pastcpu[counter] = cpu;

    lastmem = 0;
    lastusers = 0;
    lastcpu = 0.0;
    lastobs = 0;

    counter = 0;
    times = 0.0;

    call_out("sample", CALL_TIME);
}

void sample() {
    mapping r;

    memory = lastmem + memory + (lastmem = memory_info() / 1000);
    users = lastusers + users + (lastusers = sizeof(users()));
    obs = lastobs + obs + (lastobs = sizeof(objects()));
#if 0
    r = rusage();
#endif
    cpu = lastcpu + cpu + (lastcpu = (r["utime"] + r["stime"]) / uptime() / 10.0);

    times = times + 1.0;

    pastmem[counter] = memory / times / 2;
    pastusers[counter] = users / times / 2;
    pastobs[counter] = obs / times / 2;
    pastcpu[counter] = cpu / times / 2;

    if (times == AVERAGING_NUM.0) {
        times = 0.0;

        counter = counter + 1;
        if (counter == TRACK_NUM)
            counter = 0;

        memory = lastmem;
        users = lastusers;
        cpu = lastcpu;
        obs = lastobs;

        pastmem[counter] = memory;
        pastusers[counter] = users;
        pastobs[counter] = obs;
        pastcpu[counter] = cpu;

        lastmem = 0;
        lastusers = 0;
        lastcpu = 0.0;
        lastobs = 0;
    }

    call_out ("sample", CALL_TIME);
}

void graph(string str) {
    float *data;
    int i, j, elem, max, time, limit;
    float scale, ylevel;
    string line;

    switch (str) {
        case "mem"   : { data = pastmem; break; }
        case "obs"   : { data = pastobs; break; }
        case "users" : { data = pastusers; break; }
        case "cpu"   : { data = pastcpu; break; }
    }

    // First, we need to find the maximum value, for scaling.
    max = 0;
    for (i = 0; i < TRACK_NUM; i++) {
        if (data[i] > max)
            max = data[i];
    }
    scale = max/(HEIGHT + 2.0);
    if (scale == 0.0)
        scale = 1.0;

    write ("Graphing "+str+" over time.\n");
    write ("Each vertical bar represents ");
    time = CALL_TIME*AVERAGING_NUM;
    if (time < 61) {
        write (time+" seconds.\n");
    } else {
        if (time < 3601) {
            write (time/60+" minutes.\n");
        } else {
            write (time/3600+" hours.\n");
        }
    }

    write ("Sampling every " + CALL_TIME + " seconds, " + AVERAGING_NUM +
          " samples per bar.\n");
    write ("Vertical scale is " + scale);
    switch (str) {
        case "mem"   : { write (" Kbytes per line.\n"); break; }
        case "obs"   : { write (" objects per line.\n"); break; }
        case "users" : { write (" users per line.\n"); break; }
        case "cpu"   : { write (" percent CPU per line.\n"); break; }
    }

    limit = max/scale+1;
    for (i = limit; i > 0; i--) {
        ylevel = scale*i;
        line = "|";
        for (j = 0, elem = counter + 1; j < TRACK_NUM; j++, elem++) {
            if (elem == TRACK_NUM)
                elem = 0;

            if (data[elem] >= ylevel) {
                line = line + " * ";
            } else {
                line = line + "   ";
            }
        }
        write (sprintf("%11f %s\n", ylevel, line));
    }
    write ("------------------------------------------------------------------------\n");
    write ("  T minus  | 19 18 17 16 15 14 13 12 11 10  9  8  7  6  5  4  3  2  1  0\n");
}

void print_data(string str) {
    mixed *data;
    int i, j;

    switch (str) {
        case "mem"   : { data = pastmem; break; }
        case "obs"   : { data = pastobs; break; }
        case "cpu"   : { data = pastcpu; break; }
        case "users" : { data = pastusers; break; }
    }

    for (i = 0, j = counter; i < TRACK_NUM && floatp(data[j]); i++, j--) {
        switch (i) {
            case 0:
                write(sprintf("Current:        %f\n", data[j]));
                break;
            case 1:
                write(sprintf("Last period:    %f\n", data[j]));
                break;
            default:
                write(sprintf("%2d periods ago: %f\n", i, data[j]));
                break;
        }
        if (j == 0)
            j = TRACK_NUM;
    }
}
