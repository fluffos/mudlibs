// Included Lib: /d/plummanor/make_maze.c //制造单路径迷宫
// By Jpei

#include "plum_maze.h"

int exit_set, count, x, y, north_exit, south_exit;
mixed used, path;

void search_new()
{
	while (1) {
		if (x == MAZE_WIDTH - 1) {
			x = 0;
			if (y == MAZE_HEIGHT - 1) y = 0;
			else y++;
		}
		else x++;
		if (used[x][y]) break;
	}
}

void to_up()
{
	used[x][--y] = 1;
	count++;
	path[x][y] = LINK_DOWN;
}

void to_left()
{
	used[--x][y] = 1;
	count++;
	path[x][y] = LINK_RIGHT;
}

void to_right()
{
	used[x + 1][y] = 1;
	count++;
	path[x][y] |= LINK_RIGHT;
	x++;
}

void to_down()
{
	used[x][y + 1] = 1;
	count++;
	path[x][y] |= LINK_DOWN;
	y++;
}

void to_exit()
{
	exit_set = 1;
	south_exit = x;
	if (!path[x][y]) {
		x = 0;
		y = 0;
		if (!used[x][y]) search_new();
	}
	else search_new();
}

void handle_top()
{
	if ((x == MAZE_WIDTH - 1) || ((x < MAZE_WIDTH - 1) && (used[x + 1][y]))) {
		if (y == MAZE_HEIGHT - 1) {
			if (exit_set) to_left();
			else {
				if (random(2)) to_left();
				else to_exit();
			}
		}
		else {
			if (used[x][y + 1]) to_left();
			else {
				if (random(2)) to_left();
				else to_down();
			}
		}
	}
	else {
		if (y == MAZE_HEIGHT - 1) {
			if (exit_set) {
				if (random(2)) to_left();
				else to_right();
			}
			else {
				switch (random(3)) {
					case 0:
						to_left();
						break;
					case 1:
						to_right();
						break;
					case 2:
						to_exit();
						break;
				}
			}
		}
		else {
			if (used[x][y + 1]) {
				if (random(2)) to_left();
				else to_right();
			}
			else {
				switch (random(3)) {
					case 0:
						to_left();
						break;
					case 1:
						to_right();
						break;
					case 2:
						to_down();
						break;
				}
			}
		}
	}
}

void handle_right()
{
	if (y == MAZE_HEIGHT - 1) {
		if (exit_set) {
			if (random(2)) to_left();
			else to_up();
		}
		else {
			switch (random(3)) {
				case 0:
					to_left();
					break;
				case 1:
					to_up();
					break;
				case 2:
					to_exit();
					break;
			}
		}
	}
	else {
		if (used[x][y + 1]) {
			if (random(2)) to_left();
			else to_up();
		}
		else {
			switch (random(3)) {
				case 0:
					to_left();
					break;
				case 1:
					to_up();
					break;
				case 2:
					to_down();
					break;
			}
		}
	}
}

void handle_left()
{
	if ((y == 0) || ((y > 0) && (used[x][y - 1]))) {
		if ((x == MAZE_WIDTH - 1) || ((x < MAZE_WIDTH - 1) && (used[x + 1][y]))) {
			if ( y == MAZE_HEIGHT - 1) {
				if (exit_set) search_new();
				else to_exit();
			}
			else {
				if (used[x][y + 1]) search_new();
				else to_down();
			}
		}
		else {
			if (y == MAZE_HEIGHT - 1) {
				if (exit_set) to_right();
				else {
					if (random(2)) to_right();
					else to_exit();
				}
			}
			else {
				if (used[x][y + 1]) to_right();
				else {
					if (random(2)) to_right();
					else to_down();
				}
			}
		}
	}
	else {
		if ((x == MAZE_WIDTH - 1) || ((x < MAZE_WIDTH - 1) && (used[x + 1][y]))) {
			if (y == MAZE_HEIGHT - 1) {
				if (exit_set) to_up();
				else {
					if (random(2)) to_up();
					else to_exit();
				}
			}
			else {
				if (used[x][y + 1]) to_up();
				else {
					if (random(2)) to_up();
					else to_down();
				}
			}
		}
		else {
			if (y == MAZE_HEIGHT - 1) {
				if (exit_set) {
					if (random(2)) to_up();
					else to_right();
				}
				else {
					switch (random(3)) {
						case 0:
							to_up();
							break;
						case 1:
							to_right();
							break;
						case 2:
							to_exit();
							break;
					}
				}
			}
			else {
				if (used[x][y + 1]) {
					if (random(2)) to_up();
					else to_right();
				}
				else {
					switch (random(3)) {
						case 0:
							to_up();
							break;
						case 1:
							to_right();
							break;
						case 2:
							to_down();
							break;
					}
				}
			}
		}
	}
}

void make_maze(object me)
{
	count = 1;
	exit_set = 0;

	path = allocate(MAZE_WIDTH);
	used = allocate(MAZE_WIDTH);
	for (x = 0; x < MAZE_WIDTH; x++) {
		path[x] = allocate(MAZE_HEIGHT);
		used[x] = allocate(MAZE_HEIGHT);
	}

	north_exit = random(MAZE_WIDTH);
	used[north_exit][0] = 1;
	x = north_exit;
	y = 0;

	while (count < MAZE_HEIGHT * MAZE_WIDTH) {
		if (x == 0) handle_left();
		else 
			if (used[x - 1][y]) handle_left();
			else 
				if (y == 0) handle_top();
				else 
					if (used[x][y - 1]) handle_top();
					else
						if (x == MAZE_WIDTH - 1) handle_right();
						else
							if (used[x + 1][y]) handle_right();
							else {
								switch (random(3)) {
									case 0:
										to_left();
										break;
									case 1:
										to_up();
										break;
									case 2:
										to_right();
										break;
								}
							}
	}
	me->set_temp("plum_maze/north_exit", north_exit);
	me->set_temp("plum_maze/south_exit", south_exit);
	for (x = 0; x < MAZE_WIDTH; x++) {
		for (y = 0; y < MAZE_HEIGHT; y++) {
			if (x > 0 && path[x - 1][y] & LINK_RIGHT) path[x][y] |= LINK_LEFT;
			if (y > 0 && path[x][y - 1] & LINK_DOWN) path[x][y] |= LINK_UP;
			me->set_temp("plum_maze/" + x + "_" + y, path[x][y]);
		}
	}
}
