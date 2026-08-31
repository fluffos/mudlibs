/* maze.c
 *
 * Unless I specify in file headers, all my stuff I release will be
 * Public Domain. Do as you want with it or not. The choice is yours.
 *
 * If I want to be paid for code, then I will pimp myself to a company.
 *
 * Tricky
 */

#include <std.h>

inherit DAEMON;

/* Colour defines for non-LPUni codebases */
#define YEL "%^YELLOW%^"
#define HIR "%^BOLD%^%^RED%^"
#define BRED "%^B_RED%^"
#define BBLU "%^B_BLUE%^"
#define NOR "%^RESET%^"

/* Maximum and minimum width and height */
#define MAXW 19
#define MAXH 19
#define MINW 5
#define MINH 5

/* Array manipulation defines */
#define POKE(pm, px, py, val) pm[py][px] = val
#define PEEK(pm, px, py) pm[py][px]

/* Global variables. Some of these could possibly be removed */
mixed *m;
int x, y, xm, ym, ok;

/* Functions */
void makeMaze(mixed ref *maze, int w, int h, float perc)
{
    mapping d = ([
      0: ({ 0, 1, 0, -1, }),
      1: ({ 1, 0, -1, 0, }),
    ]);
    int xx, yy;
    int i, j, n, rnd;
    int ok;

    x = 1;
    y = 1;
    xm = x + 1;
    ym = y + 1;

    maze = ({ });

    for (j = 0 ; j < h + 2 ; j++)
    {
        maze += ({ ({ }) });

        for (i = 0 ; i < w + 2 ; i++) maze[j] += ({ 0 });
    }

    POKE(maze, x, y, 1);

    for (n = 0 ; n < to_int((float)(w * h) * (perc / 100.0)) ; n++)
    {

        while (1)
        {
            ok = 1;

            while (1)
            {
                rnd = random(4);

                xx = x + d[0][rnd];
                yy = y + d[1][rnd];

                if (xx > 0 && xx < ((w + 3) >> 1)
                 && yy > 0 && (yy < (h + 3) >> 1)) break;
            }

            if (PEEK(maze, (xx * 2) - 1, (yy * 2) - 1) != 0)
            {
                ok = 0;

                while (1)
                {
                    x = random(xm) + 1;
                    y = random(ym) + 1;

                    if (PEEK(maze, (x * 2) - 1, (y * 2) - 1) != 0) break;
                }

            }

            if (ok) break;
        }

        POKE(maze, x * 2 + 0 * d[0][rnd] - 1, y * 2 + 0 * d[1][rnd] - 1, 1);
        POKE(maze, x * 2 + 1 * d[0][rnd] - 1, y * 2 + 1 * d[1][rnd] - 1, 1);

        x = xx;
        y = yy;

        if (x > xm) xm = x;
        if (y > ym) ym = y;
    }

}

int makeGates(mixed ref *maze, int w, int h)
{
    int gates = 0, count = 0;

    while (count < 50)
    {
        count++;
        x = random(w);

        if (PEEK(maze, x + 1, 1) != 0) count = 51;
    }

    if (count == 51)
    {
        POKE(maze, x + 1, 0, 2);
        gates++;
    }

    count = 0;

    while (count < 50)
    {
        count++;
        x = random(w);

        if (PEEK(maze, x + 1, h) != 0) count = 51;
    }

    if (count == 51)
    {
        POKE(maze, x + 1, h + 1, 3);
        gates++;
    }

    count = 0;

    while (count < 50)
    {
        count++;
        y = random(h);

        if (PEEK(maze, 1, y + 1) != 0) count = 51;
    }

    if (count == 51)
    {
        POKE(maze, 0, y + 1, 4);
        gates++;
    }

    count = 0;

    while (count < 50)
    {
        count++;
        y = random(h);

        if (PEEK(maze, w, y + 1) != 0) count = 51;
    }

    if (count == 51)
    {
        POKE(maze, w + 1, y + 1, 5);
        gates++;
    }

    return gates;
}

int cmd_mazegen(string args)
{
    string msg = "";
    float perc;
    int w, h, ok = 1;

    w = h = 5;
    perc = 40.0;

    if (!undefinedp(args) && args != "")
        if (sscanf(args, "%d %d %f", w, h, perc) != 3)
            sscanf(args, "%d %d", w, h);

    if (!(w & 1)) w++;
    if (!(h & 1)) h++;

    if (w < MINW) w = MINW;
    if (h < MINH) h = MINH;
    if (w > MAXW) w = MAXW;
    if (h > MAXH) h = MAXH;

    while (ok < 4)
    {
        makeMaze(ref m, w, h, perc);
        ok = makeGates(ref m, w, h);
    }

    for (int j = 0 ; j < h + 2 ; j++)
    {
        msg += " ";

        for (int i = 0 ; i < w + 2 ; i++)
            switch (PEEK(m, i, j))
            {
                case 0: msg += BRED + HIR + "#" + NOR; break;
                case 1: msg += "."; break;
                case 2: msg += BBLU + YEL + "N" + NOR; break;
                case 3: msg += BBLU + YEL + "S" + NOR; break;
                case 4: msg += BBLU + YEL + "W" + NOR; break;
                case 5: msg += BBLU + YEL + "E" + NOR; break;
                default: msg += "*"; break;
            }

        msg += NOR + "\n";
    }

    foreach (string line in explode(msg + "\n", "\n"))
        write(line + "\n");

    return 1;
}

void help() {
  message("help",
    "Syntax: <mazegen [width] [height] [fill]>\n\n"
    "Generates a random maze that is [width] x [height] rooms, "
    "with rooms in [fill]% of the space.",
    this_player() );
}
